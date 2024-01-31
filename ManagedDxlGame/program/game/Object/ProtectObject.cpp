#include "ProtectObject.h"

ProtectObject::ProtectObject() {
	anim_hdl_ = ResourceManager::GetInstance_ResourceManager()->LoadAnim_("PROTECT_OBJECT");
}

void ProtectObject::Draw(float delta_time, const Camera& camera) {
	// 描画位置の調整　　　　　　　　　　　　　　　　　
	tnl::Vector3 draw_pos = pos_ - camera.target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	//画像表示
	DrawGraph(draw_pos.x, draw_pos.y, (*anim_hdl_)[anim_frame_], true);
}

tnl::Vector3 ProtectObject::GetterPos() {
	return pos_;
}