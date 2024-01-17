#include "Player.h"

Player::Player() {
	speed_ = 5;
	size_ = { 32,48,0 };
	pos_ = { 100,100,0 };
	
	graphhdl_ = LoadGraph("graphics/char_test.png");

}

void Player::Update(float delta_time) {
	Move(delta_time);
	Attack(delta_time);
}

void Player::Draw(float delta_time) {
	//�v���C���[�`��
	DrawGraph(pos_.x, pos_.y, graphhdl_, true);

	//�e�̕\��
	auto it = normal_attacks_.begin();
	while (it != normal_attacks_.end()) {
		(*it)->Draw(delta_time);
		it++;
	}
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

void Player::Attack(float delta_time) {
	//�}�E�X�̍��W
	int mouse_pos_x = 0;
	int mouse_pos_y = 0;

	//�N���b�N�ōU��
	if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
		GetMousePoint(&mouse_pos_x, &mouse_pos_y);
		mposx = mouse_pos_x;
		mposy = mouse_pos_y;
		normal_attacks_.emplace_back(std::make_shared<NormalAttack>(pos_, mouse_pos_x,mouse_pos_y, 10));
	}

	//�e��Update���s�A
	auto it = normal_attacks_.begin();
	while (it != normal_attacks_.end()) {
		(*it)->Update(delta_time);
		it++;
	}
}