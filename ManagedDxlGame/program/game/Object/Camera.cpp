#include "Camera.h"

void Camera::Update(tnl::Vector3 target_pos) {
	//target_を追いかける
	target_ += (target_pos - target_) * 0.1f;

}