#include "NormalAttack.h"

NormalAttack::NormalAttack(const tnl::Vector3& spawn_pos, const tnl::Vector3& target_pos, const float& speed) {
	//‰æ‘œƒ[ƒh
	//  = ResourceManager::GetInstance_ResourceManager()->LoadGraph_("NORMAL_SHOT");
	
	graph_hdl_ = LoadGraph("graphics/Attack/bullet.bmp");

	//ˆø”‚Åó‚¯æ‚Á‚½’l‚ğ•Ï”‚É“ü‚ê‚é
	spawn_pos_ = spawn_pos;
	target_pos_ = target_pos;
	speed_ = speed;
}

void NormalAttack::Update(float delta_time) {
	////Šp“xŒvZ
	//int x = target_pos.x - first_pos.x;
	//int y = target_pos.y - first_pos.y;
	//angle_ = atan2(x, y);
	////’eˆÚ“®
	//draw_pos_.x += cos(angle_) * speed;
	//draw_pos_.y += sin(angle_) * speed;
	////’e•\¦
	//Draw(draw_pos_, graph_hdl_);

	//Šp“xŒvZ
	int x = target_pos_.x - spawn_pos_.x;
	int y = target_pos_.y - spawn_pos_.y;
	angle_ = atan2(x,y);

	//’eˆÚ“®
	spawn_pos_.x += speed_;
}

void NormalAttack::Delete() {
	is_alive_ = false;
}

void NormalAttack::Draw(float delta_time) {
	DrawGraph(spawn_pos_.x, spawn_pos_.y, graph_hdl_, true);
}
