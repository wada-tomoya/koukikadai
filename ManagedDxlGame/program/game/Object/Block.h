#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "Camera.h"

class Block {
private:
	//ブロックのサイズ
	const float mapchip_size_ = 32.0f;

	//ブロックの画像
	int mapchip_hdl_[40] {};

	//ブロック表示場所のcsvデータ
	std::vector<std::vector<int>> mapchip_csv_;

public:
	Block();
	~Block();
	void Draw(const Camera& camera);
};
