#include "PlayScene.h"

PlayScene::PlayScene() {
	srand(time(0));

	//�w�i�摜�ǂݍ���
	background_hdl_ = ResourceManager::GetInstance_ResourceManager()->LoadGraph_("PlayScene_BackGround");

	//�I�u�W�F�N�g�C���X�^���X
	block_ = std::make_shared<Block>();
	camera_ = std::make_shared<Camera>();
	player_ = std::make_shared<Player>();

	//�I
	graphhdl_ = LoadGraph("graphics/char_test.png");
}

void PlayScene::Update(float delta_time) {
	player_->Update(delta_time, mato_pos_);
}

void PlayScene::Draw(float delta_time) {
	//�w�i
	if (background_hdl_ == -1) {
		DrawStringEx(10, 10, -1, "�摜���ǂݍ��߂ĂȂ�");
	}
	else {
		DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH + 1, DXE_WINDOW_HEIGHT + 1, background_hdl_, true);
		DrawStringEx(10, 10, -1, "�w�i�\��");
	} 

	//����u���b�N
	block_->Draw(*camera_);
	player_->Draw(delta_time);

	//�I
	DrawGraph(mato_pos_.x, mato_pos_.y, graphhdl_, true);
}