#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "Camera.h"
#include "../Manager/ResourceManager.h"

class Block {
private:
	//�u���b�N�̃T�C�Y
	const float size_ = 48.0f;

	//�u���b�N�摜�n���h��
	std::shared_ptr<std::vector<int>> mapchip_hdl_;
	//�u���b�N�\���ꏊ��csv�f�[�^
	std::vector<std::vector<int>> mapchip_csv_;

public:
	Block();
	//�}�b�v�`�b�v�\��
	void Draw(const Camera& camera);
};
