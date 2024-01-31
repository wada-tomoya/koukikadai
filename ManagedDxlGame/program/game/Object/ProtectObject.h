#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Manager/ResourceManager.h"
#include "Camera.h"

class ProtectObject {
private:
	//�\�����W
	tnl::Vector3 pos_{910,570,0};
	//�摜�n���h��
	std::shared_ptr<std::vector<int>> anim_hdl_;

	//�A�j���[�V�����Đ��̃J�E���g
	float anim_time_ = 0.0f;
	//�Đ�����t���[��
	int anim_frame_ = 0;
	//�A�j���[�V�����̍Đ����x
	float anim_speed_ = 0.1f;
public:
	ProtectObject();
	//�\���֐�
	void Draw(float delta_time, const Camera& camera);
};