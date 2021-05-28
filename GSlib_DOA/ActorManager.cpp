#include "ActorManager.h"
#include "Actor.h"

// �f�X�g���N�^
ActorManager::~ActorManager() {
    clear();
}

// �A�N�^�[�̒ǉ�
void ActorManager::add(Actor* actor) {
    actors_.push_back(actor);
}

// �A�N�^�[�̍X�V
void ActorManager::update(float delta_time) {
    for (auto actor : actors_) {
        actor->update(delta_time);
    }
}

// �A�N�^�[�̕`��
void ActorManager::draw() const {
    for (auto actor : actors_) {
        actor->draw();
    }
}

// �A�N�^�[��GUI�`��
void ActorManager::draw_gui() const {
    for (auto actor : actors_) {
        actor->draw_gui();
    }
}

// �A�N�^�[�̏Փ˔���
void ActorManager::collide() {
    for (auto i = actors_.begin(); i != actors_.end(); ++i) {
        for (auto j = std::next(i); j != actors_.end(); ++j) {
            (*i)->collide(**j);
        }
    }
}

// ���S���Ă���A�N�^�[�̍폜
void ActorManager::remove() {
    for (auto i = actors_.begin(); i != actors_.end(); ) {
        // ���S���Ă��邩�H
        if ((*i)->is_dead()) {
            delete* i;             // �A�N�^�[���폜
            i = actors_.erase(i);  // ���X�g�����菜��
        }
        else {
            ++i;
        }
    }
}

// �A�N�^�[�̌���
Actor* ActorManager::find(const std::string& name) const {
    for (auto actor : actors_) {
        // ���O����v���Ă��邩�H
        if (actor->name() == name) {
            return actor;  // ���O����v�����A�N�^�[��Ԃ�
        }
    }
    return nullptr; // ������Ȃ��ꍇ�́Anull�|�C���^��Ԃ�
}

// ����
void ActorManager::clear() {
    for (auto actor : actors_) {
        delete actor;  // �A�N�^�[���폜
    }
    actors_.clear();   // ���X�g����ɂ���
}