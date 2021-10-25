# Timer
タイマーを使っていろいろできます
  使用できる関数
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
