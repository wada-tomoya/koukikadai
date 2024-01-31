#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"
#include "../Object/Attack/NormalAttack.h"
#include "../Manager/ResourceManager.h"

class Player : public CharacterBase{
private:
	//アニメーション画像ハンドル
	std::shared_ptr<std::vector<int>> anim_hdl_;	
	//攻撃方向の座標（マウス座標）
	int mposx = 0, mposy = 0;
	//攻撃の移動速度
	float attack_speed_ = 10.0f;
	//画面の端
	float up_edge_, down_edge_, right_edge_, left_edge_;

public:
	Player(float up_edge, float down_edge, float right_edge, float left_edge);
	//実行関数
	void Update(float delta_time) override;
	//表示関数
	void Draw(float delta_time, const Camera& camera) override;
	//移動
	void Move(float delta_time, float up_edge, float down_edge, float right_edge, float left_edge);
	//攻撃
	void Attack(float delta_time);
	//プレイヤーの座標のゲッター
	tnl::Vector3 GetterPos();

	//生成した標準攻撃を入れるリスト
	std::list<std::shared_ptr<NormalAttack>> normal_attacks_;	
};

