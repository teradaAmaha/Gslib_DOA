#ifndef ENEMY_BEAM_H_
#define ENEMY_BEAM_H_

#include "Actor.h"

// �G�e�N���X
class EnemyBeam : public Actor {
public:
    // �R���X�g���N�^
    EnemyBeam(IWorld* world, const GSvector2& position, const GSvector2& velocity);
    // �X�V
    virtual void update(float delta_time) override;
    // �Փ˃��A�N�V����
    virtual void react(Actor& other) override;
};

#endif


