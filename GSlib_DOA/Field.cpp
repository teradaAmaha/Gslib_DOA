#include "Field.h"
#include "TextureID.h"


void Field::update(float delta_time) {
}

// �g���G���A�̊O�����H
bool Field::is_outside(const BoundingRectangle& rect) const {
    return !extend_area_.intersects(rect);
}

// �G���A�̎擾
const BoundingRectangle& Field::area() const {
    return area_;
}