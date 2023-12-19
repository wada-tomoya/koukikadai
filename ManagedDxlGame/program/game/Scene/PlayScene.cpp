#include "PlayScene.h"

PlayScene::PlayScene() {
	srand(time(0));

	//背景画像読み込み
	background_hdl_ = LoadGraph("graphics/playbackground.jpg");

	//オブジェクトインスタンス
	block_ = std::make_shared<Block>();
	camera_ = std::make_shared<Camera>();
}

void PlayScene::Update(float delta_time) {
	
}

void PlayScene::Draw(float delta_time) {
	//背景
	DrawExtendGraph(0,0,DXE_WINDOW_WIDTH+1,DXE_WINDOW_HEIGHT+1, background_hdl_, true);
	//足場ブロック
	//block_->Draw(*camera_);
}