# ClockTimer Library
```
疑似的にタイマーを増やし出力できます
オブジェクトごとに周期を設定し出力できるため、delayを使う必要がありません
millis,micros関数を使うためTimer0の周波数変更には非対応
```
# Data
```
version   Arduino 1.8.16
Author    CaseyNelson314
Date      2021/12/21
```
# Usage
```
ClockTimer ObjectName(周期);
ClockTimer ObjectName(周期,上昇上限);
```
# Function list
```
GetClick        周期に達したとき1loopHIGH出力
GetToggle       周期に達するごとに1,0切り替わる
GetPwm          0から上昇上限まで上昇する
GetIllumination 0から上昇し下降する
SetTimerType    millisかmicros
ClockReset      リセット
```
