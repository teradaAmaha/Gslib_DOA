#ifndef GAME_PLAY_SCENE_H_
#define GAME_PLAY_SCENE_H_

#include"IScene.h"
#include "World.h"

// �Q�[���v���C�V�[��
class GamePlayScene : public IScene {
public:
    // �J�n
    virtual void start() override;
    // �X�V
    virtual void update(float delta_time) override;
    // �`��
    virtual void draw() const override;
    // �I�����Ă��邩�H
    virtual bool is_end() const override;
    // ���̃V�[����Ԃ�
    virtual std::string next() const override;
    // �I��
    virtual void end() override;
private:
    // ���[���h�N���X
    World   world_;
};

#endif

