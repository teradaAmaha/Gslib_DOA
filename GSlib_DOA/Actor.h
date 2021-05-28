#ifndef ACTOR_H_
#define ACTOR_H_

#include <gslib.h> // gslib�S�@�\�̃w�b�_�t�@�C���iGSvector2�̂��߂ɕK�v�j
#include <string>
#include "BoundingRectangle.h"

// ���[���h���ۃC���^�[�t�F�[�X�̑O���錾
class IWorld;

// �A�N�^�[�N���X
class Actor {
public:
    // �R���X�g���N�^
    Actor() = default;
    // ���z�f�X�g���N�^
    virtual ~Actor() = default;
    // �X�V
    virtual void update(float delta_time);
    // �`��
    virtual void draw() const;
    // GUI�`��
    virtual void draw_gui() const;
    // �Փˎ����A�N�V����
    virtual void react(Actor& other);
    // �Փ˔���
    void collide(Actor& other);
    // ���S����
    void die();
    // �Փ˔��肵�Ă��邩�H
    bool is_collide(const Actor& other) const;
    // ���S���Ă��邩�H
    bool is_dead() const;
    // ���O���擾
    const std::string& name() const;
    // �^�O�����擾
    const std::string& tag() const;
    // ���W���擾
    GSvector2 position() const;
    // ��]�p�x���擾
    float rotation() const;
    // �ړ��ʂ��擾
    GSvector2 velocity() const;
    // �Փ˔���f�[�^���擾
    BoundingRectangle collider() const;
    // �R�s�[�֎~
    Actor(const Actor& other) = delete;
    Actor& operator = (const Actor& other) = delete;
protected:
    // ���[���h
    IWorld* world_{ nullptr };
    // ���O
    std::string        name_;
    // �^�O��
    std::string        tag_;
    // ���W
    GSvector2          position_{ 0.0f, 0.0f };
    // ��]�p�x
    float              angle_{ 0.0f };
    // �ړ���
    GSvector2          velocity_{ 0.0f, 0.0f };
    // �Փ˔��肪�L�����H
    bool               enable_collider_{ true };
    // �Փ˔���
    BoundingRectangle  collider_{ 0.0f, 0.0f, 0.0f, 0.0f };
    // ���S�t���O
    bool               dead_{ false };
    // �e�N�X�`���h�c 
    GSuint             texture_{ 0 };
};

#endif
