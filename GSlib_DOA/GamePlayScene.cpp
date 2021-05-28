#include "GamePlayScene.h"
#include "Player.h"
#include "Base.h"
#include "EnemyGenerator.h"
#include "Item.h"
#include "TextureID.h"



// �J�n
void GamePlayScene::start() {
    gsLoadTexture(TexturePlayer, "Assets/SHIP.png");
    gsLoadTexture(TextureEnemy, "Assets/ENEMY.png");
    gsLoadTexture(TexturePlayerBeam, "Assets/BEAM.png");
    gsLoadTexture(TextureEnemyBeam, "Assets/EBEAM.png");
    gsLoadTexture(TextureItem, "Assets/ITEM.png");
    gsLoadTexture(TextureBase, "Assets/base.png");
    /*gsLoadTexture(TextureBG1, "Assets/BG1.png");
    gsLoadTexture(TextureBG2, "Assets/BG2.png");
    gsLoadTexture(TextureBG3, "Assets/BG3.png");
    gsLoadTexture(TextureBomb, "Assets/BOMB.png");
    gsLoadTexture(TextureNumber, "Assets/NUM.png")*/;
    world_.add_actor(new Player{ &world_, GSvector2{ 0.0f, 200.0f } });
    world_.add_actor(new EnemyGenerator{ &world_ });
    world_.add_actor(new Item{ &world_,GSvector2{100.0f,100.0f} });
    world_.add_actor(new Base{ &world_,GSvector2{-40.0f,440.0f} });
}

// �X�V
void GamePlayScene::update(float delta_time) {
    world_.update(delta_time);
}
// �`��
void GamePlayScene::draw() const {
    world_.draw();
}

// �I�����Ă��邩�H
bool GamePlayScene::is_end() const {
    // �Q�[���I�[�o�[���܂��̓Q�[���N���A�Ȃ�V�[���I��
    return world_.is_game_over() || world_.is_game_clear();

}
// ���̃V�[����Ԃ�
std::string GamePlayScene::next() const {

    // �Q�[���N���A���H
    if (world_.is_game_clear()) {
        return "ResultScene";       // �Q�[���N���A�̏ꍇ�̓��U���g�V�[���ɑJ��
    }


    //�^�C�g���V�[���ɖ߂�
    return "TitleScene";

}

// �I��
void GamePlayScene::end() {
    // ���[���h������
    world_.clear();
    // �e�X�N�`���̍폜
    gsDeleteTexture(TexturePlayer);
    gsDeleteTexture(TextureEnemy);
    gsDeleteTexture(TexturePlayerBeam);
    gsDeleteTexture(TextureEnemyBeam);
    gsDeleteTexture(TextureBase);
    gsDeleteTexture(TextureItem);
    /* gsDeleteTexture(TextureBG1);
     gsDeleteTexture(TextureBG2);
     gsDeleteTexture(TextureBG3);
     gsDeleteTexture(TextureBomb);
     gsDeleteTexture(TextureNumber);*/
}
