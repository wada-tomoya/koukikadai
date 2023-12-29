#include "Attack.h"

Attack::Attack(tnl::Vector3 first_pos, tnl::Vector3 target_pos) {
	//�摜���[�h
	graph_hdl_ = LoadGraph("graphics/bullet.bmp", true);
	
}

void Attack::Shot_normal(float speed, tnl::Vector3 first_pos, tnl::Vector3 target_pos) {
	//�p�x�v�Z
	int x = target_pos.x - first_pos.x;
	int y = target_pos.y - first_pos.y;
	angle_ = atan2(x, y);

	//�e�ړ�
	draw_pos_.x += cos(angle_) * speed;
	draw_pos_.y += sin(angle_) * speed;

	//�e�\��
	Draw(draw_pos_, graph_hdl_);
}

void Attack::Draw(tnl::Vector3 draw_pos, int graph_hdl) {
	DrawGraph(draw_pos.x, draw_pos.y, graph_hdl, true);
}
