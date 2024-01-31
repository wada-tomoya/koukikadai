#include "Camera.h"

void Camera::Update(tnl::Vector3 target_pos, float up_edge, float down_edge, float right_edge, float left_edge) {
	//target_を追いかける
	target_ += (target_pos - target_) * 0.1f;

	//上端表示補正 画面の上端より上を表示しない
	if (target_.y < up_edge + (DXE_WINDOW_HEIGHT / 2 )) {
		target_.y = up_edge + (DXE_WINDOW_HEIGHT / 2);
	}
	//下端表示補正 画面の下端より下を表示しない
	if (target_.y > down_edge - (DXE_WINDOW_HEIGHT / 2)) {
		target_.y = down_edge - (DXE_WINDOW_HEIGHT / 2);
	}
	//右端表示補正 画面の右端より右を表示しない
	if (target_.x > right_edge - (DXE_WINDOW_WIDTH / 2)) {
		target_.x = right_edge - (DXE_WINDOW_WIDTH / 2);
	}
	//左端表示補正 画面の左端より左を表示しない
	if (target_.x < left_edge + (DXE_WINDOW_WIDTH / 2)) {
		target_.x = left_edge + (DXE_WINDOW_WIDTH / 2);
	}
}