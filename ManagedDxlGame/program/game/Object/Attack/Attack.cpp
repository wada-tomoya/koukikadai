#include "Attack.h"

Attack::Attack() {
	//�摜���[�h
	graph_hdl_ = LoadGraph("graphics/bullet.bmp", true);

}

void Attack::Draw(tnl::Vector3 draw_pos, int graph_hdl) {
	DrawGraph(draw_pos.x, draw_pos.y, graph_hdl, true);

}

void Attack::Shot(float speed, tnl::Vector3 first_pos, tnl::Vector3 target_pos) {
	//draw_pos_ = first_pos;
	
	//�e�\��
	Draw(draw_pos_, graph_hdl_);
	
	//�p�x�v�Z
	int x = target_pos.x - first_pos.x;
	int y = target_pos.y - first_pos.y;
	angle_ = atan2(x, y);

	//�e�ړ�
	draw_pos_.x += cos(angle_) * speed;
	draw_pos_.y += sin(angle_) * speed;

	DrawStringEx(30, 10, -1, "�e����", true);
}