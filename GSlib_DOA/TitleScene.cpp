#include "TitleScene.h"
#include "TextureID.h"

// �J�n
void TitleScene::start() {
    // �摜�̓ǂݍ���
    gsLoadTexture(TextureTitleLogo, "Assets/TITLE1.png");
    gsLoadTexture(TextureTitleStart, "Assets/TITLE2.png");
    /*gsLoadTexture(TextureBG1, "Assets/BG1.png");
    gsLoadTexture(TextureBG2, "Assets/BG2.png");
    gsLoadTexture(TextureBG3, "Assets/BG3.png");*/
    // �I���t���O�̏�����
    is_end_ = false;
}

// �X�V
void TitleScene::update(float delta_time) {
    // �G���^�[�L�[����������V�[���I��
    if (gsGetKeyTrigger(GKEY_RETURN)) {
        is_end_ = true;     // �V�[���I��
    }
    // �w�i�̃X�N���[���l���X�V
    scroll_ += delta_time;
}

// �`��
void TitleScene::draw() const {
    // �w�i�̕`��
   /* draw_background(TextureBG3, scroll_ * 0.5f);
    draw_background(TextureBG2, scroll_ * 2.0f);
    draw_background(TextureBG1, scroll_ * 3.0f);*/
    // �^�C�g�����S�̕`��
    const static GSvector2 position_logo{ 64.0f, 100.0f };
    gsDrawSprite2D(TextureTitleLogo, &position_logo, NULL, NULL, NULL, NULL, 0.0f);
    // ������@�̕`��
    const static GSvector2 position_start{ 170.0f, 260.0f };
    gsDrawSprite2D(TextureTitleStart, &position_start, NULL, NULL, NULL, NULL, 0.0f);
}

// �I�����Ă��邩�H
bool TitleScene::is_end() const {
    return is_end_;         // �I���t���O��Ԃ�
}

// ���̃V�[������Ԃ�
std::string TitleScene::next() const {
    return "GamePlayScene"; // ���̃V�[������Ԃ�
}

// �I��
void TitleScene::end() {
    // �摜�̍폜
    gsDeleteTexture(TextureTitleLogo);
    gsDeleteTexture(TextureTitleStart);
    /* gsDeleteTexture(TextureBG1);
     gsDeleteTexture(TextureBG2);
     gsDeleteTexture(TextureBG3);*/
     //�w�i
}

// �w�i�̕`��
void TitleScene::draw_background(GSuint id, float scroll) const {
    GSrect rect{ scroll, 0.0f, scroll + 640.0f, 480.0f };
    gsDrawSprite2D(id, NULL, &rect, NULL, NULL, NULL, 0.0f);
}

