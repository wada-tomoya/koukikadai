#include "Camera.h"

void Camera::Update(tnl::Vector3 target_pos) {
	//target_��ǂ�������
	target_ += (target_pos - target_) * 0.1f;

}