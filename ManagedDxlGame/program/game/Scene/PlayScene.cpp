#include "PlayScene.h"

PlayScene::PlayScene() {
	srand(time(0));

	//背景画像読み込み
	background_hdl_ = ResourceManager::GetInstance_ResourceManager()->LoadGraph_("PlayScene_BackGround");

	//オブジェクトインスタンス
	block_ = std::make_shared<Block>();
	camera_ = std::make_shared<Camera>();
	player_ = std::make_shared<Player>();

	//的
	graphhdl_ = LoadGraph("graphics/char_test.png");
}

void PlayScene::Update(float delta_time) {
	player_->Update(delta_time, mato_pos_);
}

void PlayScene::Draw(float delta_time) {
	//背景
	if (background_hdl_ == -1) {
		DrawStringEx(10, 10, -1, "画像が読み込めてない");
	}
	else {
		DrawExtendGraph(0, 0, DXE_WINDOW_WIDTH + 1, DXE_WINDOW_HEIGHT + 1, background_hdl_, true);
		DrawStringEx(10, 10, -1, "背景表示");
	} 

	//足場ブロック
	block_->Draw(*camera_);
	player_->Draw(delta_time);

	//的
	DrawGraph(mato_pos_.x, mato_pos_.y, graphhdl_, true);
}