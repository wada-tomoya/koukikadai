#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Camera {
private:

public:
	//�J�����̃^�[�Q�b�g�̍��W
	tnl::Vector3 target_{0,0,0};
	//�J�����̃A�b�v�f�[�g�̏���
	void Update(tnl::Vector3 target_pos);
};