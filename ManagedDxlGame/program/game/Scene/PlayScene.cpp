#include "PlayScene.h"

PlayScene::PlayScene() {
	srand(time(0));

	//背景画像読み込み
	background_hdl_ = ResourceManager::GetInstance_ResourceManager()->LoadGraph_("PlayScene_BackGround");


	//オブジェクトインスタンス
	block_ = std::make_shared<Block>();
	camera_ = std::make_shared<Camera>();
	player_ = std::make_shared<Player>();
	protectobj_ = std::make_shared<ProtectObject>();
	enemy_ = std::make_shared<Enemy>(enemy_target_pos, enemy_spon_pos, 5.0f);
}

void PlayScene::Update(float delta_time) {
	//プレイヤー実行
	player_->Update(delta_time);
	//カメラ、プレイヤー追尾
	camera_->Update(player_->GetterPos());
	//敵
	//enemy_->Update(delta_time);
}

void PlayScene::Draw(float delta_time) {
	// 描画位置の調整　　　　　　　　　　　　　　　　　
	tnl::Vector3 draw_pos = bg_pos_ - camera_->target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	//背景
	DrawExtendGraph(draw_pos.x, draw_pos.y, draw_pos.x + map_endpos_.x, draw_pos.y + map_endpos_.y, background_hdl_, false);

	//足場ブロック
	block_->Draw(*camera_);
	//敵のターゲット、プレイヤーが守るやつ
	protectobj_->Draw(delta_time, *camera_);
	//敵
	enemy_->Draw(delta_time, *camera_);
	//プレイヤー表示
	player_->Draw(delta_time, *camera_);

}
