#include "Enemy.h"

Enemy::Enemy(tnl::Vector3 target, tnl::Vector3 spon_pos, float speed) : target_pos_(target){
	//アニメーション画像ロード
	anim_hdl_ = ResourceManager::GetInstance_ResourceManager()->LoadAnim_("ENEMY_GHOST_RIGHT");
	//角度計算
	int x = target_pos_.x;
	int y = target_pos_.y;
	angle_ = atan2(y, x);
	//初期座標設定
	pos_ = spon_pos;
	//移動速度
	speed_ = speed;
}

void Enemy::Update(float delta_time) {
	Move(delta_time);
}

void Enemy::Draw(float delta_time, const Camera& camera) {
	// 描画位置の調整　　　　　　　　　　　　　　　　　
	tnl::Vector3 draw_pos = pos_ - camera.target_ + tnl::Vector3(DXE_WINDOW_WIDTH >> 1, DXE_WINDOW_HEIGHT >> 1, 0);
	//敵表示
	DrawRotaGraph(draw_pos.x, draw_pos.y, 1.0, 0, (*anim_hdl_)[anim_frame_], true, isturn_);

}

void Enemy::Move(float delta_time) {
	//移動
	pos_.x += cos(angle_) * speed_;
	pos_.y += sin(angle_) * speed_;
	
	//1f前の座標
	tnl::Vector3 prev_pos_{0,0,0};
	//左右向き変換
	prev_pos_ = pos_;
	float dir =  pos_.x - prev_pos_.x;
	if (dir > 0) isturn_ = DIRECTION::RIGHT;
	else if (dir < 0) isturn_ = DIRECTION::LEFT;

}