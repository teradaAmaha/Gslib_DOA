#ifndef ENEMY_1_H_
#define ENEMY_1_H_

#include "Actor.h"

// �G�N���X
class Enemy1 : public Actor {
public:
    // �R���X�g���N�^
    Enemy1(IWorld* world, const GSvector2& position);
    // �X�V
    virtual void update(float delta_time) override;

    virtual void draw();
    // �Փ˃��A�N�V����
    virtual void react(Actor& other) override;

private:
    // �e���˃^�C�}
    float timer_{ 0.0f };
    int counter = 0;

};

#endif

