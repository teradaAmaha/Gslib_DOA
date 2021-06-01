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

	void alive(); //���C�t���O�ɂȂ�Ύ���

	
private:
	float life = 20.0f;
	int counter = 0;

	//���Ɋe�G�l�~�[�A�e�̃_���[�W��ǉ�
	float const e1_ = 3;
};

#endif

