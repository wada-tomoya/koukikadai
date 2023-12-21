#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "math.h"

class Attack {
private:
	//�摜�n���h��
	int graph_hdl_ = 0;
	tnl::Vector3 draw_pos_;
	//�e�𔭎˂���p�x
	int angle_ = 0;

public:
	Attack();
	void Draw(tnl::Vector3 draw_pos, int graph_hdl);

	void Shot(float speed, tnl::Vector3 first_pos, tnl::Vector3 target_pos);
};