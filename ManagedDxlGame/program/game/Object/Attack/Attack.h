#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Attack {
private:
	//画像ハンドル
	int graph_hdl_ = 0;
	//ターゲット（進行方向）の座標
	tnl::Vector3 target_pos_{ 0,0,0 };
	//最初の座標
	tnl::Vector3 first_pos_{ 0,0,0 };
	//表示座標
	tnl::Vector3 draw_pos_{ 0,0,0 };

protected:
	Attack(tnl::Vector3 first_pos, tnl::Vector3 target_pos);
	void Draw(float delta_time);
	void Update(float delta_time );
};