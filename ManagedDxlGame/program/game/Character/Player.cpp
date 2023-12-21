#include "Player.h"

Player::Player() {
	speed_ = 5;
	size_ = { 32,48,0 };
	pos_ = { 100,100,0 };
	
	graphhdl_ = LoadGraph("graphics/char_test.png");

}

void Player::Update(float delta_time) {
	Move(delta_time);
}

void Player::Draw(float delta_time) {
	//プレイヤー描画
	DrawGraph(pos_.x, pos_.y, graphhdl_, true);

	//仮の的
	DrawGraph(mato_pos_.x, mato_pos_.y, graphhdl_, true);
}

void Player::Move(float delta_time_) {
	//移動　上
	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
		pos_.y -= speed_;
	}
	//移動　下
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		pos_.y += speed_;
	}
	//移動　右
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		pos_.x += speed_;
	}
	//移動　左
	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		pos_.x -= speed_;
	}
}