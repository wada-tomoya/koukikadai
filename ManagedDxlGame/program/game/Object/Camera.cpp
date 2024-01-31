#include "Camera.h"

void Camera::Update(tnl::Vector3 target_pos, float up_edge, float down_edge, float right_edge, float left_edge) {
	//target_��ǂ�������
	target_ += (target_pos - target_) * 0.1f;

	//��[�\���␳ ��ʂ̏�[�����\�����Ȃ�
	if (target_.y < up_edge + (DXE_WINDOW_HEIGHT / 2 )) {
		target_.y = up_edge + (DXE_WINDOW_HEIGHT / 2);
	}
	//���[�\���␳ ��ʂ̉��[��艺��\�����Ȃ�
	if (target_.y > down_edge - (DXE_WINDOW_HEIGHT / 2)) {
		target_.y = down_edge - (DXE_WINDOW_HEIGHT / 2);
	}
	//�E�[�\���␳ ��ʂ̉E�[���E��\�����Ȃ�
	if (target_.x > right_edge - (DXE_WINDOW_WIDTH / 2)) {
		target_.x = right_edge - (DXE_WINDOW_WIDTH / 2);
	}
	//���[�\���␳ ��ʂ̍��[��荶��\�����Ȃ�
	if (target_.x < left_edge + (DXE_WINDOW_WIDTH / 2)) {
		target_.x = left_edge + (DXE_WINDOW_WIDTH / 2);
	}
}