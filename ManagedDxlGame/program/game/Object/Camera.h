#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Camera {
private:

public:
	//�J�����̃^�[�Q�b�g�̍��W
	tnl::Vector3 target_{0,0,0};
	//�J�����̃A�b�v�f�[�g�̏���
	//�����i�Ǐ]����^�[�Q�b�g���W�A��ʂ̏�[�A��ʂ̉��[�A��ʂ̉E�[�A��ʂ̍��[�j
	void Update(tnl::Vector3 target_pos, float up_edge, float down_edge, float right_edge, float left_edge);
};