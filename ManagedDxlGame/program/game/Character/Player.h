#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"
#include "../Object/Attack/Attack.h"


class Player : public CharacterBase {
private:
	//‰æ‘œƒnƒ“ƒhƒ‹
	int graphhdl_;

	tnl::Vector3 mato_pos_{ 1000,100,0 };

	std::shared_ptr<Attack> attack_ = nullptr;

public:
	Player();
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Move(float delta_time);

};