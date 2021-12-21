/*
        @file   ClockTimer.h
        @brief  疑似タイマー
        @author CaseyNelson314
        @date   2021/10/26
*/
#pragma once
#include <Arduino.h>
class ClockTimer {

  private:

    unsigned long Time;
    unsigned long Timesub;
    unsigned long ClockCycle;
    long COUNTUP;
    long CountLimit;
    long SetPwm;
    bool Call;
    bool Output;
    bool TimerSerect;
    bool CountSerect;


  public:

    ClockTimer(unsigned long SetClockCycle): ClockCycle(SetClockCycle), SetPwm(255) {}
    ClockTimer(unsigned long SetClockCycle, unsigned int PwmWideSet): ClockCycle(SetClockCycle), SetPwm(PwmWideSet) {}

    bool ClickOut() {
      bool select = 0;
      Time = TimerSerect ? micros() : millis();
      if (Time - Timesub > ClockCycle) {
        Timesub = Time; select = 1;
        if (CountSerect) COUNTUP >= CountLimit ? COUNTUP = 0 : COUNTUP++;
      }
      return select;
    }

    bool ClockOut() {
      if (ClickOut())Output = !Output;
      return Output;
    }

    void CountSet(long COUNTLIMIT) {
      CountSerect = 1; CountLimit = COUNTLIMIT;
    }
    long CountOut() {
      ClickOut();
      return COUNTUP;
    }

    unsigned long PwmOut() {
      ClickOut();
      return (Time - Timesub) * SetPwm / ClockCycle;
    }

    unsigned long PwmUnprocessed() {
      ClickOut();
      return Time - Timesub;
    }

    unsigned long PwmIllumi() {
      ClickOut();
      long out = SetPwm - (Time - Timesub) * SetPwm * 2 / ClockCycle;
      return SetPwm - abs(out);
    }

    void CallFunc(void(*CALLFUNC)()) {
      if (ClickOut() * !Call) CALLFUNC();
    }

    void CallStop() {
      Call = 1;
    }

    void CallStart() {
      Call = 0;
    }

    void ClockCycleSet(unsigned long CLOCKCYCLE) {
      ClockCycle = CLOCKCYCLE;
    }

    void MicrosSet() {
      TimerSerect = 1;
    }

    void ClockReset() {
      Timesub = Time; Output  = 0;
    }
};
