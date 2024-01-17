#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"
#include "../Object/Attack/NormalAttack.h"


class Player : public CharacterBase{
private:
	//画像ハンドル
	int graphhdl_;
	//攻撃方向の座標（マウス座標）
	int mposx = 0, mposy = 0;

public:
	Player();
	//実行関数
	void Update(float delta_time) override;
	//表示関数
	void Draw(float delta_time) override;
	//移動
	void Move(float delta_time);
	//攻撃
	void Attack(float delta_time);

	//生成した標準攻撃を入れるリスト
	std::list<std::shared_ptr<NormalAttack>> normal_attacks_;
};

