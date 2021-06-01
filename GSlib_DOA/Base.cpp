#include "Base.h"
#include "TextureId.h"
#include <iostream>
#include "IWorld.h"

Base::Base(IWorld* world, const GSvector2& position) {
	world_ = world;
	tag_ = "BaseTag";
	name_ = "Base";
	position_ = position;
	collider_ = BoundingRectangle{ 0.0f,0.0f,680.0f,20.0f };
	texture_ = TextureBase;
}
void Base::update(float delta_time)
{
	
	counter++;
}

void Base::draw() const {
	if (counter > 0 || counter % 2 == 0) {
		gsDrawSprite2D(TextureBase, &position_, NULL, NULL, NULL, NULL, angle_);
	}
}

void Base::alive() {//���C�t���O�ɂȂ�Ύ���
	world_->sub_hp(e1);
	--life;//�����C�t
	counter = -60;
	if (life <= 0)
	{
		die();
	}
}

void Base::react(Actor& other)
{
	if (other.tag() == "EnemyTag") {
		//�e�_���[�W�ʂ͂�����(life)
		alive();
	}
	if (other.tag() == "Enemy2Tag") {

		alive();
	}
	if (other.tag() == "Enemy3Tag") {

		alive();
	}
	if (other.tag() == "Enemy4Tag") {
		alive();
	}
	if (other.tag() == "EnemyBulletTag") {
		alive();
	}
}

