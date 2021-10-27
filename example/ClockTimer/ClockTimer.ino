/*
        @file   ClockTimer.ino
        @brief  example
        @author CaseyNelson314
        @date   2021/10/26

  使用可能関数
  ClockOut        設定周期ごとに0,1が切り替わる
  ClickOut        設定周期になった時,瞬間的に1になる
  ClockCycleSet   設定周期を途中で変更
  ClockReset      クロックをリセットする
  PwmOut          0からpwm上昇上限まで上昇する(設定周期間)
  PwmUnprocessed  0から設定周期まで上昇する(設定周期間)
  PwmIllumi       0からpwm上昇上限まで上昇したのち0まで降下する(設定周期間)
  CallFunc        設定周期になったら()内の関数を実行する
  CallStop        関数の呼び出しを停止する
  CallStart       関数の呼び出しを再開する
  MicrosSet       Timerをmillisからmicrosに変更する 周期(ms)→(μs)
*/

#include "ClockTimer.h"

//オブジェクトごとに周期設定(ms) AA(周期)またはAA(周期,Pwm上昇上限)
//Pwm上昇上限未設定の場合255が初期値として適用
ClockTimer T1(1000);
ClockTimer T2(2000);
ClockTimer T3(1000, 500);
ClockTimer T4(500);

void call() {
  Serial.print("call");                Serial.print("\t");
}

void setup() {
  Serial.begin(115200);
  T3.CountSet(10);
}

void loop() {
  Serial.print(T1.ClockOut());       Serial.print("\t");
  Serial.print(T1.PwmIllumi());      Serial.print("\t");
  Serial.print(T2.ClockOut());       Serial.print("\t");
  Serial.print(T2.PwmIllumi());      Serial.print("\t");
  Serial.print(T3.PwmOut());         Serial.print("\t");
  Serial.print(T3.CountOut());       Serial.print("\t");
  T4.CallFunc(call);  //関数呼び出し
  Serial.println();
  delay(10);
}
