# ClockTimer Library
```
疑似的にタイマーを増やせます
オブジェクトごとに周期を設定し出力できるため、delay等を使う必要がありません
millisまたはmicros関数を使うためTimer0の周波数変更には対応してません
```
# Data
```
version   Arduino 1.8.16
Author    CaseyNelson314
Date      2021/10/26
```
# Usage
```
ClockTimer ObjectName(周期);
ClockTimer ObjectName(周期,上昇上限);
```
# Function list
```
ClockOut          設定周期ごとに0,1が切り替わる
ClockCycleSet     設定周期を途中で変更 : 引数(周期設定)
ClockReset        クロックをリセットする
ClickOut          設定周期になった時,瞬間的に1になる
CountOut          周期に達した数をカウントする
CountSet          カウント上限を設定 : 引数(カウント上限)
PwmOut            0からpwm上昇上限まで上昇する
PwmUnprocessed    0から設定周期まで上昇する
PwmIllumi         0からpwm上昇上限まで上昇したのち0まで降下する
CallFunc          設定周期になったら()内の関数を実行する : 引数(呼び出し関数)
CallStop          関数の呼び出しを停止する
CallStart         関数の呼び出しを再開する
MicrosSet         Timerをmillisからmicrosに変更する 周期(ms)→(μs)
```
# Important point
```
CountOut関数を使うにはCountSet関数の引数でカウント上限を指定する必要があります
指定した数になった後0にリセットされカウントがリスタートします
遅延によってオブジェクトごとのクロックが多少ずれるため周期をそろえて使用することは非推奨です
```
# example
```
//PwmIllumi関数の使用例
#include <ClockTimer.h>
ClockTimer Clock1(1120, 200);
ClockTimer Clock2(2320, 200);
ClockTimer Clock3(5260, 200);

byte LedPin[3] = {3, 5, 6};
byte LedPow[3];

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(LedPin[i], OUTPUT);
  }
}

void loop() {

  //PowerSet
  LedPow[0] = Clock1.PwmIllumi();
  LedPow[1] = Clock2.PwmIllumi();
  LedPow[2] = Clock3.PwmIllumi();

  //LedOutput
  for (int i = 0; i < 3; i++) {
    analogWrite(LedPin[i], LedPow[i]);
  }

  //SerialMonitorOutput
  for (int i = 0; i < 3; i++) {
    Serial.print(LedPow[i]); Serial.print("\t");
  }
  Serial.println();
}
```
