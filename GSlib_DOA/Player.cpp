#include "Player.h"
#include "IWorld.h"
#include"PlayerBeam.h"
#include "TextureID.h"  // �e�N�X�`��ID�̂��߂ɕK�v
#include <algorithm>

// �R���X�g���N�^
Player::Player(IWorld* world, const GSvector2& position) {
    world_ = world;
    tag_ = "PlayerTag";
    name_ = "Player";
    position_ = position;
    collider_ = BoundingRectangle{ 0.0f, 0.0f, 64.0f, 40.0f };
    texture_ = TexturePlayer;
}

const GSvector2& Player::minX() const {

    return min_x_;
}

const GSvector2& Player::maxX() const {

    return max_x_;
}

// �X�V
void Player::update(float delta_time) {
    world_->sub_timer(15);
    GSvector2 direction{ 0.0f, 0.0f }; // �ړ�����
    if (gsGetKeyState(GKEY_LEFT)) {
        direction.x = -1.0f;
    }
    if (gsGetKeyState(GKEY_RIGHT)) {
        direction.x = 1.0f;
    }
    /* if (gsGetKeyState(GKEY_UP)) {
         direction.y = -1.0f;
     }
     if (gsGetKeyState(GKEY_DOWN)) {
         direction.y = 1.0f;
     }*/
    float speed = 8.0f; // �ړ��X�s�[�h
    // �ړ��ʂ̌v�Z
    velocity_ = direction.normalized() * speed;
    // ���W�̍X�V
    position_ += velocity_ * delta_time;


    position_ = position_.clamp(minX(), maxX());


    // �X�y�[�X�L�[����������e�𔭎� �������Ă�
    if (gsGetKeyState(GKEY_SPACE)) {
        if (counter % 5 == 0) {
            world_->add_actor(new PlayerBeam{ world_,
                position_ + GSvector2{ 50.0f, 25.0f }, GSvector2{ 8.0f, 0.0f } });//playerBeam�̃R���X�g���N�^�Ă�ł�
        }
    }

    counter++;
}

/*�Փ˃��A�N�V����
void Player::react(Actor& other) {
     �G�̃^�O�����L�����N�^�ƏՓ˂������H
    if (other.tag() == "Enemy1Tag") {
         ���S��Ԃɂ���
        die();
    }*/
    //}