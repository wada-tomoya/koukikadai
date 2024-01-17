#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"

class Enemy : public CharacterBase {
private:

public:
	Enemy();
	//é¿çsä÷êî
	void Update(float delta_time) override;
	//ï\é¶ä÷êî
	void Draw(float delta_time) override;
};