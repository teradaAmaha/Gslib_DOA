#include "NumberTexture.h"
#include <sstream>
#include <iomanip>

// コンストラクタ
NumberTexture::NumberTexture(GSuint texture, int width, int height) :
    texture_{ texture }, width_{ width }, height_{ height } {
}

// 描画 (右詰め)
void NumberTexture::draw(const GSvector2& position, int num, int digit, char fill) const {
    std::stringstream ss;    //stringstreamは数値を抜き出す、文字列を空白で区切る、0埋めなど書式の変更などを行うために使います。
    //↓は文字を追加
    ss << std::setw(digit) << std::setfill(fill) << num;
    draw(position, ss.str());
}

// 描画 (左詰め)
void NumberTexture::draw(const GSvector2& position, int num) const {
    draw(position, std::to_string(num));
}

// 描画
void NumberTexture::draw(const GSvector2& position, const std::string& num) const {
    for (int i = 0; i < (int)num.size(); ++i) {
        if (num[i] == ' ') continue; // 空白文字はスキップ
        // 文字型をint型に変換
        int n = num[i] - '0';
        // 数字に対応する画像を切り出すための矩形を計算する
        GSrect rect(n * width_, 0.0f, (n * width_) + width_, height_);
        // 数字を表示する座標を計算
        GSvector2 pos{ position.x + i * width_, position.y };
        // 数字を１桁描画
        gsDrawSprite2D(texture_, &pos, &rect, NULL, NULL, NULL, 0);

    }

}