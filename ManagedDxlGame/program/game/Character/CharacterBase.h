#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class CharacterBase {
protected:
	//移動速度
	float speed_ = 0;
	//画像サイズ
	tnl::Vector3 size_{ 0,0,0 };
	//表示座標
	tnl::Vector3 pos_ { 0,0,0 };
public:
	virtual void Update(float delat_time) {};
	virtual void Draw(float delat_time) {};
};