#ifndef NUMBER_TEXTURE_H_
#define NUMBER_TEXTURE_H_

#include <gslib.h>
#include <string>

// �i���o�e�N�X�`��
class NumberTexture {
public:
    // �R���X�g���N�^
    NumberTexture(GSuint texture, int width, int height);
    // �`��(�E�l��)
    void draw(const GSvector2& position, int num, int digit, char fill = '0') const;
    // �`��(���l��)
    void draw(const GSvector2& position, int num) const;
    // �`��
    void draw(const GSvector2& position, const std::string& num) const;

private:
    // �t�H���g�p�̃e�N�X�`��
    GSuint	texture_;
    // �����̕�
    int	width_;
    // �����̍���
    int	height_;
};

#endif

