#ifndef BOUNDING_RECTANGLE_H_
#define BOUNDING_RECTANGLE_H_

#include <gslib.h> // gslib�S�@�\�̃w�b�_�t�@�C���iGSvector2�̂��߂ɕK�v�j

// ��`�N���X
class BoundingRectangle {
public:
    // �R���X�g���N�^
    BoundingRectangle() = default;
    // �R���X�g���N�^
    BoundingRectangle(float left, float top, float right, float bottom);
    // �R���X�g���N�^
    BoundingRectangle(const GSvector2& min, const GSvector2& max);
    // ��`���d�Ȃ��Ă��邩�H
    bool intersects(const BoundingRectangle& other) const;
    // ���s�ړ�
    BoundingRectangle translate(const GSvector2& position) const;
    // ��
    float width() const;
    // ����
    float height() const;
    // ����̍��W
    const GSvector2& min() const;
    // �E���̍��W
    const GSvector2& max() const;

private:
    GSvector2 min_{ 0.0f, 0.0f };     // ��`�̍���̍��W
    GSvector2 max_{ 0.0f, 0.0f };     // ��`�̉E���̍��W
};

#endif
