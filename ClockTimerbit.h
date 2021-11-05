/*
        @file   ClockTimerbit.h
        @brief  疑似タイマー省メモリver
        @author CaseyNelson314
        @date   2021/10/31
*/

#pragma once
#include <Arduino.h>

class ClockTimer {

  private:

    unsigned long Time, Timesub;
    unsigned long ClockCycle;
    long COUNTUP;
    long CountLimit;
    unsigned int  SetPwm;
    byte flagdata;

  public:

    ClockTimer(unsigned long SetClockCycle): ClockCycle(SetClockCycle), SetPwm(255) {}
    ClockTimer(unsigned long SetClockCycle, unsigned int PwmWideSet): ClockCycle(SetClockCycle), SetPwm(PwmWideSet) {}

    bool ClickOut() {
      bitWrite(flagdata, 4, 0);
      Time = bitRead(flagdata, 2) ? micros() : millis();
      if (Time - Timesub > ClockCycle) {
        Timesub = Time; bitWrite(flagdata, 4, 1);
        if (bitRead(flagdata, 3)) COUNTUP >= CountLimit ? COUNTUP = 0 : COUNTUP++;
      }
      return bitRead(flagdata, 4);
    }

    bool ClockOut() {
      if (ClickOut())bitWrite(flagdata, 1, !bitRead(flagdata, 1));
      return bitRead(flagdata, 1);
    }

    void CountSet(long COUNTLIMIT) {
      bitWrite(flagdata, 3, 1); CountLimit = COUNTLIMIT;
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
      if (ClickOut() * !bitRead(flagdata, 0)) CALLFUNC();
    }

    void CallStop() {
      bitWrite(flagdata, 0, 1);
    }

    void CallStart() {
      bitWrite(flagdata, 0, 0);
    }

    void ClockCycleSet(unsigned long CLOCKCYCLE) {
      ClockCycle = CLOCKCYCLE;
    }

    void MicrosSet() {
      bitWrite(flagdata, 2, 1);
    }

    void ClockReset() {
      Timesub = Time;
      bitWrite(flagdata, 1, 0);
    }
};
