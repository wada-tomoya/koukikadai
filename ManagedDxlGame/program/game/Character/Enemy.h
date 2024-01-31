#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"
#include "CharacterBase.h"
#include "../Manager/ResourceManager.h"

class Enemy : public CharacterBase {
private:
	//�A�j���[�V�����摜�n���h��
	std::shared_ptr<std::vector<int>> anim_hdl_;
	//�^�[�Q�b�g�̍��W
	tnl::Vector3 target_pos_ {0,0,0};
	//�ړ��p�x
	float angle_ = 0.0f;

public:
	Enemy(tnl::Vector3 target, tnl::Vector3 spon_pos, float speed);
	//���s�֐�
	void Update(float delta_time) override;
	//�\���֐�
	void Draw(float delta_time, const Camera& camera) override;
	//�ړ�
	void Move(float delta_time);
};