#ifndef SCORE_H_
#define SCORE_H_

class Timer {
public:
	//コンストラクタ
	Timer(int timer = 6000);
	//タイマーの初期化
	void initialize(int timer = 0);
	//タイマーの減算
	void sub(int timer);
	//タイマーの描画
	void draw() const;
	//タイマーの取得
	int get() const;
	//タイマーのクリア
	void clear();

private:
	//タイマー
	int timer_ = 6000;


};

#endif