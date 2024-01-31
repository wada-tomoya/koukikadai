#include "PlayScene.h"

PlayScene::PlayScene() {
	srand(time(0));

	//�w�i�摜�ǂݍ���
	background_hdl_ = ResourceManager::GetInstance_ResourceManager()->LoadGraph_("PlayScene_BackGround");


	//�I�u�W�F�N�g�C���X�^���X
	block_ = std::make_shared<Block>();
	camera_ = std::make_shared<Camera>();
	player_ = std::make_shared<Player>();
	protectobj_ = std::make_shared<ProtectObject>();
	enemy_ = std::make_shared<Enemy>(enemy_target_pos, enemy_spon_pos, 5.0f);
}

void PlayScene::Update(float delta_time) {
	//�v���C���[���s
	player_->Update(delta_time);
	//�J�����A�v���C���[�ǔ�
	camera_->Update(player_->GetterPos());
	//�G
	//enemy_->Update(delta_time);
}

void PlayScene::Draw(float delta_time) {
	// �`��ʒu�̒����@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@
	tnl::Vector3 draw_pos = bg_pos_ - camera_->target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	//�w�i
	DrawExtendGraph(draw_pos.x, draw_pos.y, draw_pos.x + map_endpos_.x, draw_pos.y + map_endpos_.y, background_hdl_, false);

	//����u���b�N
	block_->Draw(*camera_);
	//�G�̃^�[�Q�b�g�A�v���C���[�������
	protectobj_->Draw(delta_time, *camera_);
	//�G
	enemy_->Draw(delta_time, *camera_);
	//�v���C���[�\��
	player_->Draw(delta_time, *camera_);

}
