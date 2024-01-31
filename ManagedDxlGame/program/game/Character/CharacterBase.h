#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "../Object/Camera.h"

class CharacterBase {
protected:
	//�ړ����x
	float speed_ = 0;
	//�摜�T�C�Y
	tnl::Vector3 size_{ 0,0,0 };
	//�\�����W
	tnl::Vector3 pos_ { 0,0,0 };
	//���E���]�t���O
	bool isturn_ = false;
	//�L�����N�^�[�̌���
	enum DIRECTION {
		RIGHT,
		LEFT
	};
	//�A�j���[�V�����Đ��̃J�E���g
	float anim_time_ = 0.0f;
	//�Đ�����t���[��
	int anim_frame_ = 0;
	//�A�j���[�V�����̍Đ����x
	float anim_speed_ = 0.1f;
public:
	//���s�֐�
	virtual void Update(float delat_time) {};
	//�摜�\���֐�
	virtual void Draw(float delat_time, const Camera& camera) {};
	//�A�j���[�V�����Đ��֐�
	virtual void Anim_Play(std::shared_ptr<std::vector<int>> animhdl, float delta_time);
};