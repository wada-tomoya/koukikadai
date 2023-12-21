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
	//�v���C���[�`��
	DrawGraph(pos_.x, pos_.y, graphhdl_, true);

	//���̓I
	DrawGraph(mato_pos_.x, mato_pos_.y, graphhdl_, true);
}

void Player::Move(float delta_time_) {
	//�ړ��@��
	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
		pos_.y -= speed_;
	}
	//�ړ��@��
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		pos_.y += speed_;
	}
	//�ړ��@�E
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		pos_.x += speed_;
	}
	//�ړ��@��
	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		pos_.x -= speed_;
	}
}