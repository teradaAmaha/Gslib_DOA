#ifndef ACTOR_MANAGER_H_
#define ACTOR_MANAGER_H_

#include <list>
#include <string>


class Actor;  // �A�N�^�[�N���X�̑O���錾

// �A�N�^�[�}�l�[�W���[�N���X
class ActorManager {
public:
    // �R���X�g���N�^
    ActorManager() = default;
    // �f�X�g���N�^
    ~ActorManager();
    // �A�N�^�[�̒ǉ�
    void add(Actor* actor);
    // �A�N�^�[�̍X�V
    void update(float delta_time);
    // �A�N�^�[�̕`��
    void draw() const;
    // �A�N�^�[��GUI�`��
    void draw_gui() const;
    // �A�N�^�[�̏Փ˔���
    void collide();
    // ���S���Ă���A�N�^�[�̍폜
    void remove();
    // �A�N�^�[�̌���
    Actor* find(const std::string& name) const;
    // ����
    void clear();
    // �R�s�[�֎~
    ActorManager(const ActorManager& other) = delete;
    ActorManager& operator = (const ActorManager& other) = delete;
private:
    // �A�N�^�[���X�g
    std::list<Actor*> actors_;
};

#endif
