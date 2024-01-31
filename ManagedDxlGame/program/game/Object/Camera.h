#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Camera {
private:

public:
	//カメラのターゲットの座標
	tnl::Vector3 target_{0,0,0};
	//カメラのアップデートの処理
	void Update(tnl::Vector3 target_pos);
};