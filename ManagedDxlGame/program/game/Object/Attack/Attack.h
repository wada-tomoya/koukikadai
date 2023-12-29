#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "math.h"

class Attack {
protected:	
	struct NORMAL_SHOT {

	};
	//画像ハンドル
	int graph_hdl_ = 0;
	//表示座標
	tnl::Vector3 draw_pos_;
	//画像のサイズ
	tnl::Vector3 attack_size_;
	//弾を発射する角度
	int angle_ = 0;
	//弾の生死
	bool is_alive_ = true;

public:
	std::list<Attack> bullets;
	Attack(tnl::Vector3 first_pos, tnl::Vector3 target_pos);
	void Shot_normal(float speed, tnl::Vector3 first_pos, tnl::Vector3 target_pos );
	void Draw(tnl::Vector3 draw_pos, int graph_hdl);
};
