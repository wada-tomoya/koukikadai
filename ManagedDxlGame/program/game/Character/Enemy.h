#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"

class Enemy : public CharacterBase {
private:

public:
	Enemy();
	//実行関数
	void Update(float delta_time) override;
	//表示関数
	void Draw(float delta_time) override;
};