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
	int target_pos_x_ = 0, target_pos_y_ = 0;
	//�e�̑��x
	float speed_ = 0;
	//�e�𔭎˂���p�x
	float angle_ = 0.0f;
	//�e�̐���
	bool is_alive_ = true;

public:	
	NormalAttack(const tnl::Vector3& spawn_pos, const int& mouse_pos_x, const int& mouse_pos_y, const float& speed);
	//�U���֐�
	void Update(float delta_time);
	//�U���̏���
	void Delete();
	//�e�̕\��
	void Draw(float delta_time);

};
