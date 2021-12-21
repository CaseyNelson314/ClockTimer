/*
        @file   ClockTimer.h
        @brief  疑似タイマー
        @author CaseyNelson314
        @date   2021/10/26
*/
#pragma once

#define MICROS 0
#define MILLIS 1

class ClockTimer {
  private:
    long clockCycle;
    int pwmLimit;
    bool clickData;
    bool toggleData;
    bool isMillis = 1;
    unsigned long lastTime;
    unsigned long time;

    void Update() {
      time = isMillis ? millis() : micros();
      if (time - lastTime > clockCycle) {
        clickData = 1;
        toggleData ^= 1;
        lastTime = time;
      }
    }
  public:
    ClockTimer(long CLOCK_CYCLE, int PWM_LIMIT = 255): clockCycle(CLOCK_CYCLE), pwmLimit(PWM_LIMIT) {}


    bool GetClick() {
      Update();
      bool returnClick = clickData;
      clickData = 0;
      return returnClick;
    }
    
    bool GetToggle() {
      Update();
      return toggleData;
    }
    
    long GetPwm() {
      Update();
      return (time - lastTime) * pwmLimit / clockCycle;
    }
    
    long GetIllumination() {
      Update();
      long returnData = pwmLimit - (time - lastTime) * pwmLimit * 2 / clockCycle;
      return pwmLimit - abs(returnData);
    }

    void SetTimerType(bool type) {
      isMillis = type;
    }
    
    void ClockReset() {
      clickData = toggleData = 0;
      lastTime = time;
    }

};
