#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "Camera.h"

class Block {
private:
	//�u���b�N�̃T�C�Y
	const float mapchip_size_ = 32.0f;

	//�u���b�N�̉摜
	int mapchip_hdl_[40] {};

	//�u���b�N�\���ꏊ��csv�f�[�^
	std::vector<std::vector<int>> mapchip_csv_;

public:
	Block();
	~Block();
	void Draw(const Camera& camera);
};
