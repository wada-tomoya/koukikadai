#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Attack {
private:
	//�摜�n���h��
	int graph_hdl_ = 0;
	//�^�[�Q�b�g�i�i�s�����j�̍��W
	tnl::Vector3 target_pos_{ 0,0,0 };
	//�ŏ��̍��W
	tnl::Vector3 first_pos_{ 0,0,0 };
	//�\�����W
	tnl::Vector3 draw_pos_{ 0,0,0 };

protected:
	Attack(tnl::Vector3 first_pos, tnl::Vector3 target_pos);
	void Draw(float delta_time);
	void Update(float delta_time );
};