#include "PlayScene.h"

PlayScene::PlayScene() {
	srand(time(0));

	//�w�i�摜�ǂݍ���
	background_hdl_ = LoadGraph("graphics/playbackground.jpg");

	//�I�u�W�F�N�g�C���X�^���X
	block_ = std::make_shared<Block>();
	camera_ = std::make_shared<Camera>();
}

void PlayScene::Update(float delta_time) {
	
}

void PlayScene::Draw(float delta_time) {
	//�w�i
	DrawExtendGraph(0,0,DXE_WINDOW_WIDTH+1,DXE_WINDOW_HEIGHT+1, background_hdl_, true);
	//����u���b�N
	//block_->Draw(*camera_);
}