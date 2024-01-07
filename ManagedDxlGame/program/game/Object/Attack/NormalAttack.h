#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "math.h"
#include "../../Manager/ResourceManager.h"

class NormalAttack {
private:	
	//�摜�n���h��
	int graph_hdl_ = 0;
	//�摜�̃T�C�Y
	tnl::Vector3 attack_size_ = {0,0,0};
	//�������W
	tnl::Vector3 spawn_pos_{0,0,0};
	//�U���̐i�s�����i�N���b�N�������W�j
	tnl::Vector3 target_pos_ = {0,0,0};
	//�e�̑��x
	float speed_ = 0;
	//�e�𔭎˂���p�x
	int angle_ = 0;
	//�e�̐���
	bool is_alive_ = true;

public:	
	NormalAttack(const tnl::Vector3& spawn_pos, const tnl::Vector3& target_pos, const float& speed);

	//�U���֐�
	void Update(float delta_time);
	//�U���̏���
	void Delete();
	//�e�̕\��
	void Draw(float delta_time);

};
