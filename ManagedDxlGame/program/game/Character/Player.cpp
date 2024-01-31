#include "Player.h"

Player::Player() {
	//移動速度
	speed_ = 5;
	//画像サイズ
	size_ = { 48,48,0 };
	//初期座標
	pos_ = { 900,570,0 };
	//アニメーション画像ロード
	anim_hdl_ = ResourceManager::GetInstance_ResourceManager()->LoadAnim_("PLAYER_RIGHT");
}

void Player::Update(float delta_time) {
	Move(delta_time);
	Attack(delta_time);
}

void Player::Draw(float delta_time, const Camera& camera) {
	// 描画位置の調整　　　　　　　　　　　　　　　　　
	tnl::Vector3 draw_pos = pos_ - camera.target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	//プレイヤー表示
	DrawRotaGraph(draw_pos.x, draw_pos.y, 1.0f,0,(*anim_hdl_)[anim_frame_], true, isturn_);

	//弾の表示
	auto it = normal_attacks_.begin();
	while (it != normal_attacks_.end()) {
		(*it)->Draw(delta_time);
		it++;
	}
	DrawStringEx(10, 40, -1, "camera_pos.x %f, camera_pos.y %f", draw_pos.x, draw_pos.y);
	DrawStringEx(10, 10, -1, "player_pos.x %f, player_pos.y %f",pos_.x,pos_.y);
}

void Player::Move(float delta_time) {
	//移動　上
	if (tnl::Input::IsKeyDown(eKeys::KB_W)) {
		//移動
		pos_.y -= speed_;
		//アニメーション再生
		Anim_Play(anim_hdl_, delta_time);
	}
	//移動　下
	if (tnl::Input::IsKeyDown(eKeys::KB_S)) {
		//移動
		pos_.y += speed_;
		//アニメーション再生
		Anim_Play(anim_hdl_, delta_time);
	}
	//移動　右
	if (tnl::Input::IsKeyDown(eKeys::KB_D)) {
		//移動
		pos_.x += speed_; 
		//アニメーション再生
		Anim_Play(anim_hdl_, delta_time);
		//向きを右
		isturn_ = DIRECTION::RIGHT;
	}
	//移動　左
	if (tnl::Input::IsKeyDown(eKeys::KB_A)) {
		//移動
		pos_.x -= speed_;
		//アニメーション再生
		Anim_Play(anim_hdl_, delta_time);
		//向きを左
		isturn_ = DIRECTION::LEFT;
	}
}

void Player::Attack(float delta_time) {
	//マウスの座標
	int mouse_pos_x = 0;
	int mouse_pos_y = 0;

	//クリックで攻撃
	if (tnl::Input::IsMouseTrigger(eMouseTrigger::IN_LEFT)) {
		//マウスの座標を取得
		GetMousePoint(&mouse_pos_x, &mouse_pos_y);
		mposx = mouse_pos_x;
		mposy = mouse_pos_y;
		//攻撃生成
		normal_attacks_.emplace_back(std::make_shared<NormalAttack>(pos_, mouse_pos_x,mouse_pos_y, attack_speed_));
	}

	//弾のUpdate実行、
	auto it = normal_attacks_.begin();
	while (it != normal_attacks_.end()) {
		(*it)->Update(delta_time);
		it++;
	}

	//弾を消す処理を書いてない
}

tnl::Vector3 Player::GetterPos() {
	return pos_;
}