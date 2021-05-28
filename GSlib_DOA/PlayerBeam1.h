#ifndef PLAYER_BEAM_H_
#define PLAYER_BEAM_H_

#include "Actor.h"

// �v���[���[�e
class PlayerBeam1 : public Actor {
public:
    // �R���X�g���N�^
    PlayerBeam1(IWorld* world, const GSvector2& position, const GSvector2& velocity);
    // �X�V
    virtual void update(float delta_time) override;
    // �Փ˃��A�N�V����
    virtual void react(Actor& other) override;
};

#endif
