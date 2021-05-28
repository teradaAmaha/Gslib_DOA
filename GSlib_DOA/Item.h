#ifndef ITEM_H_
#define ITEM_H_

#include"Actor.h"

//�A�C�e���N���X
class Item :public Actor
{
public:
    // �R���X�g���N�^
    Item(IWorld* world, const GSvector2& position);
    // �X�V
    virtual void update(float delta_time) override;
    // �Փ˃��A�N�V����
    virtual void react(Actor& other) override;

private:
    //�����^�C�}�[
    float timer_{ 0.0f };


};

#endif