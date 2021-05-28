#ifndef FIELD_H_
#define FIELD_H_

#include "BoundingRectangle.h"

// �t�B�[���h�N���X
class Field {
public:
    // �R���X�g���N�^
    Field() = default;
    // ������
    void initialize();
    // �X�V
    void update(float delta_time);
    // �`��
    void draw() const;
    // �g���G���A�̊O�����H
    bool is_outside(const BoundingRectangle& rect) const;
    // �G���A�̎擾
    const BoundingRectangle& area() const;

private:
    // �Q�[����ʃG���A
    BoundingRectangle area_{ 0.0f, 0.0f, 640.0f, 480.0f };
    // �g���G���A
    BoundingRectangle extend_area_{ -128, -128, 640.0f + 128.0f, 480.0f + 128.0f };
};

#endif
