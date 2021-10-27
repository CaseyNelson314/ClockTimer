# ClockTimer Library
```
疑似的にタイマーを増やせます
オブジェクトごとに周期を設定できるのでdelay等を使う必要がありません
millisまたはmicros関数を使うためTimer0の周波数変更には対応してません
```
# Data
```
version  Arduino 1.8.16
Author   CaseyNelson314
Date     2021/10/26
```
# Usage
オブジェクト生成
```
ClockTimer NAME(周期);
or
ClockTimer NAME(周期,上昇上限);
```
# Function
Function list
```
ClockOut          設定周期ごとに0,1が切り替わる
ClockCycleSet     設定周期を途中で変更
ClockReset        クロックをリセットする
ClickOut          設定周期になった時,瞬間的に1になる
CountOut          周期に達した数をカウントする
CountSet          カウント上限を設定
PwmOut            0からpwm上昇上限まで上昇する(設定周期間)
PwmUnprocessed    0から設定周期まで上昇する(設定周期間)
PwmIllumi         0からpwm上昇上限まで上昇したのち0まで降下する(設定周期間)
CallFunc          設定周期になったら()内の関数を実行する
CallStop          関数の呼び出しを停止する
CallStart         関数の呼び出しを再開する
MicrosSet         Timerをmillisからmicrosに変更する 周期(ms)→(μs)
```
Points to remember
```
CountOut関数を使うにはCountSet関数の引数でカウント上限を指定する必要があります
違なるオブジェクトで同じ周期を指定した場合しばらくするとそれぞれのクロックがずれる場合があります
```
