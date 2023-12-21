#include "Attack.h"

Attack::Attack(tnl::Vector3 first_pos, tnl::Vector3 target_pos) : first_pos_(first_pos), target_pos_(target_pos){
	//‰æ‘œƒ[ƒh
	graph_hdl_ = LoadGraph("graphics/bullet.bmp", true);

}

void Attack::Draw(float delta_time) {
	DrawGraph(draw_pos_.x, draw_pos_.y, graph_hdl_, true);
}

void Attack::Update(float delta_time) {

}