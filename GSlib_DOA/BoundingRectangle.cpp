#include "BoundingRectangle.h"

// �R���X�g���N�^
BoundingRectangle::BoundingRectangle(float left, float top, float right, float bottom)
    : BoundingRectangle{ GSvector2{ left, top }, GSvector2{ right, bottom } } {
}

// �R���X�g���N�^
BoundingRectangle::BoundingRectangle(const GSvector2& min, const GSvector2& max)
    : min_{ min }, max_{ max } {
}

// ��`���d�Ȃ��Ă��邩�H
bool BoundingRectangle::intersects(const BoundingRectangle& other) const {
    if (min_.x > other.max_.x) return false;
    if (max_.x < other.min_.x) return false;
    if (min_.y > other.max_.y) return false;
    if (max_.y < other.min_.y) return false;
    return true;
}

// ���s�ړ�
BoundingRectangle BoundingRectangle::translate(const GSvector2& position) const {
    return BoundingRectangle{ min_ + position, max_ + position };
}

// ��
float BoundingRectangle::width() const {
    return max_.x - min_.x;
}

// ����
float BoundingRectangle::height() const {
    return max_.y - min_.y;
}

// ����̍��W
const GSvector2& BoundingRectangle::min() const {
    return min_;
}

// �E���̍��W
const GSvector2& BoundingRectangle::max() const {
    return max_;
}