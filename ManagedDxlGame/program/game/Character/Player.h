#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"
#include "../Object/Attack/NormalAttack.h"


class Player : public CharacterBase{
private:
	//�摜�n���h��
	int graphhdl_;
	//�U�������̍��W�i�}�E�X���W�j
	int mposx = 0, mposy = 0;

public:
	Player();
	//���s�֐�
	void Update(float delta_time) override;
	//�\���֐�
	void Draw(float delta_time) override;
	//�ړ�
	void Move(float delta_time);
	//�U��
	void Attack(float delta_time);

	//���������W���U�������郊�X�g
	std::list<std::shared_ptr<NormalAttack>> normal_attacks_;
};

