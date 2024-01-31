#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"
#include "../Object/Attack/NormalAttack.h"
#include "../Manager/ResourceManager.h"

class Player : public CharacterBase{
private:
	//�A�j���[�V�����摜�n���h��
	std::shared_ptr<std::vector<int>> anim_hdl_;	
	//�U�������̍��W�i�}�E�X���W�j
	int mposx = 0, mposy = 0;
	//�U���̈ړ����x
	float attack_speed_ = 10.0f;
	//��ʂ̒[
	float up_edge_, down_edge_, right_edge_, left_edge_;

public:
	Player(float up_edge, float down_edge, float right_edge, float left_edge);
	//���s�֐�
	void Update(float delta_time) override;
	//�\���֐�
	void Draw(float delta_time, const Camera& camera) override;
	//�ړ�
	void Move(float delta_time, float up_edge, float down_edge, float right_edge, float left_edge);
	//�U��
	void Attack(float delta_time);
	//�v���C���[�̍��W�̃Q�b�^�[
	tnl::Vector3 GetterPos();

	//���������W���U�������郊�X�g
	std::list<std::shared_ptr<NormalAttack>> normal_attacks_;	
};

