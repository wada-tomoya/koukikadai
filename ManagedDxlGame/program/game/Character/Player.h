#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"
#include "../Object/Attack/NormalAttack.h"


class Player : public CharacterBase{
private:
	//‰æ‘œƒnƒ“ƒhƒ‹
	int graphhdl_;

public:
	Player();
	void Update(float delta_time, tnl::Vector3 target_pos) override;
	void Draw(float delta_time) override;
	void Move(float delta_time);
	void Attack(float delta_time);

	std::list<std::shared_ptr<NormalAttack>> normal_attacks_;
};

