#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"

class Enemy : public CharacterBase {
private:

public:
	Enemy();
	//���s�֐�
	void Update(float delta_time) override;
	//�\���֐�
	void Draw(float delta_time) override;
};