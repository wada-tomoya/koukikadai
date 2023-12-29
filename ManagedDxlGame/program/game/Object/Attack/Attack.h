#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "math.h"

class Attack {
protected:	
	struct NORMAL_SHOT {

	};
	//�摜�n���h��
	int graph_hdl_ = 0;
	//�\�����W
	tnl::Vector3 draw_pos_;
	//�摜�̃T�C�Y
	tnl::Vector3 attack_size_;
	//�e�𔭎˂���p�x
	int angle_ = 0;
	//�e�̐���
	bool is_alive_ = true;

public:
	std::list<Attack> bullets;
	Attack(tnl::Vector3 first_pos, tnl::Vector3 target_pos);
	void Shot_normal(float speed, tnl::Vector3 first_pos, tnl::Vector3 target_pos );
	void Draw(tnl::Vector3 draw_pos, int graph_hdl);
};
