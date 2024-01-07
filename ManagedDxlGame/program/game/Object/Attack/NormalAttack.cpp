#include "NormalAttack.h"

NormalAttack::NormalAttack(const tnl::Vector3& spawn_pos, const tnl::Vector3& target_pos, const float& speed) {
	//画像ロード
	//  = ResourceManager::GetInstance_ResourceManager()->LoadGraph_("NORMAL_SHOT");
	
	graph_hdl_ = LoadGraph("graphics/Attack/bullet.bmp");

	//引数で受け取った値を変数に入れる
	spawn_pos_ = spawn_pos;
	target_pos_ = target_pos;
	speed_ = speed;
}

void NormalAttack::Update(float delta_time) {
	////角度計算
	//int x = target_pos.x - first_pos.x;
	//int y = target_pos.y - first_pos.y;
	//angle_ = atan2(x, y);
	////弾移動
	//draw_pos_.x += cos(angle_) * speed;
	//draw_pos_.y += sin(angle_) * speed;
	////弾表示
	//Draw(draw_pos_, graph_hdl_);

	//角度計算
	int x = target_pos_.x - spawn_pos_.x;
	int y = target_pos_.y - spawn_pos_.y;
	angle_ = atan2(x,y);

	//弾移動
	spawn_pos_.x += speed_;
}

void NormalAttack::Delete() {
	is_alive_ = false;
}

void NormalAttack::Draw(float delta_time) {
	DrawGraph(spawn_pos_.x, spawn_pos_.y, graph_hdl_, true);
}
