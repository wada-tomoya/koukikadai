#include "NormalAttack.h"

NormalAttack::NormalAttack(const tnl::Vector3& spawn_pos, const int& mouse_pos_x, const int& mouse_pos_y, const float& speed) {
	//�摜���[�h
	//  = ResourceManager::GetInstance_ResourceManager()->LoadGraph_("NORMAL_SHOT");
	
	graph_hdl_ = LoadGraph("graphics/Attack/bullet.bmp");

	//�����Ŏ󂯎�����l��ϐ��ɓ����
	spawn_pos_ = spawn_pos;
	target_pos_x_ = mouse_pos_x;
	target_pos_y_ = mouse_pos_y;
	speed_ = speed;

	//�p�x�v�Z
	int x = target_pos_x_ - spawn_pos_.x;
	int y = target_pos_y_ - spawn_pos_.y;
	angle_ = atan2(y,x);
}

void NormalAttack::Update(float delta_time) {
	//�e�ړ�
	spawn_pos_.x += cos(angle_) * speed_;
	spawn_pos_.y += sin(angle_) * speed_;
}

void NormalAttack::Delete() {
	is_alive_ = false;
}

void NormalAttack::Draw(float delta_time) {
	DrawGraph(spawn_pos_.x, spawn_pos_.y, graph_hdl_, true);
}
