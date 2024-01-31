#include "Player.h"

Player::Player() {
	//�ړ����x
	speed_ = 5;
	//�摜�T�C�Y
	size_ = { 48,48,0 };
	//�������W
	pos_ = { 900,570,0 };
	//�A�j���[�V�����摜���[�h
	anim_hdl_ = ResourceManager::GetInstance_ResourceManager()->LoadAnim_("PLAYER_RIGHT");
}

void Player::Update(float delta_time) {
	Move(delta_time);
	Attack(delta_time);
}

void Player::Draw(float delta_time, const Camera& camera) {
	// �`��ʒu�̒����@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@
	tnl::Vector3 draw_pos = pos_ - camera.target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	//�v���C���[�\��
	DrawRotaGraph(draw_pos.x, draw_pos.y, 1.0f,0,(*anim_hdl_)[anim_frame_], true, isturn_);

	//�e�̕\��
	auto it = normal_attacks_.begin();
	while (it != normal_attacks_.end()) {
		(*it)->Draw(delta_time);
		it++;
	}
	DrawStringEx(10, 40, -1, "camera_pos.x %f, camera_pos.y %f", draw_pos.x, draw_pos.y);
	DrawStringEx(10, 10, -1, "player_pos.x %f, player_pos.y %f",pos_.x,pos_.y);
}

void Player::Move(float delta_time) {
	//�ړ��@��
	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
		//�ړ�
		pos_.y -= speed_;
		//�A�j���[�V�����Đ�
		Anim_Play(anim_hdl_, delta_time);
	}
	//�ړ��@��
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		//�ړ�
		pos_.y += speed_;
		//�A�j���[�V�����Đ�
		Anim_Play(anim_hdl_, delta_time);
	}
	//�ړ��@�E
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		//�ړ�
		pos_.x += speed_; 
		//�A�j���[�V�����Đ�
		Anim_Play(anim_hdl_, delta_time);
		//�������E
		isturn_ = DIRECTION::RIGHT;
	}
	//�ړ��@��
	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		//�ړ�
		pos_.x -= speed_;
		//�A�j���[�V�����Đ�
		Anim_Play(anim_hdl_, delta_time);
		//��������
		isturn_ = DIRECTION::LEFT;
	}
}

void Player::Attack(float delta_time) {
	//�}�E�X�̍��W
	int mouse_pos_x = 0;
	int mouse_pos_y = 0;

	//�N���b�N�ōU��
	if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
		//�}�E�X�̍��W���擾
		GetMousePoint(&mouse_pos_x, &mouse_pos_y);
		mposx = mouse_pos_x;
		mposy = mouse_pos_y;
		//�U������
		normal_attacks_.emplace_back(std::make_shared<NormalAttack>(pos_, mouse_pos_x,mouse_pos_y, attack_speed_));
	}

	//�e��Update���s�A
	auto it = normal_attacks_.begin();
	while (it != normal_attacks_.end()) {
		(*it)->Update(delta_time);
		it++;
	}

	//�e�����������������ĂȂ�
}

tnl::Vector3 Player::GetterPos() {
	return pos_;
}