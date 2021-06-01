#ifndef BASE_H_
#define BASE_H_
#include "Actor.h"

class Base : public Actor
{
public:
	Base(IWorld* world, const GSvector2& position);

	virtual void update(float delta_time) override;

	virtual void draw() const override;

	virtual void react(Actor& other) override;

	void alive(); //ライフが０になれば死ぬ

	
private:
	float life = 20.0f;
	int counter = 0;

	//下に各エネミー、弾のダメージを追加
	float const e1_ = 3;
};

#endif

