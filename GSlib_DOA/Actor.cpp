#include "Actor.h"

// �X�V
void Actor::update(float delta_time) {}

// �`��
void Actor::draw() const {
    // �X�v���C�g�̕\��

    gsDrawSprite2D(texture_, &position_, NULL, NULL, NULL, NULL, angle_);
}

// GUI�`��
void Actor::draw_gui() const {}

// �Փˎ����A�N�V����
void Actor::react(Actor& other) {}

// �Փ˔���
void Actor::collide(Actor& other) {
    // �ǂ���̃A�N�^�[���Փ˔��肪�L�����H
    if (enable_collider_ && other.enable_collider_) {
        // �Փ˔��������
        if (is_collide(other)) {
            // �Փ˂����ꍇ�́A���݂��ɏՓ˃��A�N�V����������
            react(other);
            other.react(*this);
        }
    }
}

// ���S����
void Actor::die() {
    dead_ = true;
}

// �Փ˔��肵�Ă��邩�H
bool Actor::is_collide(const Actor& other) const {
    return collider().intersects(other.collider());
}

// ���S���Ă��邩�H
bool Actor::is_dead() const {
    return dead_;
}

// ���O���擾
const std::string& Actor::name() const {
    return name_;
}

// �^�O�����擾
const std::string& Actor::tag() const {
    return tag_;
}

// ���W���擾
GSvector2 Actor::position() const {
    return position_;
}

// ��]�p�x���擾
float Actor::rotation() const {
    return angle_;
}

// �ړ��ʂ��擾
GSvector2 Actor::velocity() const {
    return velocity_;
}

// �Փ˔���f�[�^���擾
BoundingRectangle Actor::collider() const {
    return collider_.translate(position_);
}