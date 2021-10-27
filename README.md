# Timer
#(h2)疑似的にタイマーを増やせます
#(h2)使用できる関数
#(h3) ClockOut        設定周期ごとに0,1が切り替わる
#(h3)ClickOut        設定周期になった時,瞬間的に1になる
#(h3)ClockCycleSet   設定周期を途中で変更
#(h3)ClockReset      クロックをリセットする
#(h3)CountOut        周期に達した数をカウントする
#(h3)CountSet        カウント上限を設定
#(h3)PwmOut          0からpwm上昇上限まで上昇する(設定周期間)
#(h3)PwmUnprocessed  0から設定周期まで上昇する(設定周期間)
#(h3)PwmIllumi       0からpwm上昇上限まで上昇したのち0まで降下する(設定周期間)
#(h3)CallFunc        設定周期になったら()内の関数を実行する
#(h3)CallStop        関数の呼び出しを停止する
#(h3)CallStart       関数の呼び出しを再開する
#(h3)MicrosSet       Timerをmillisからmicrosに変更する 周期(ms)→(μs)
