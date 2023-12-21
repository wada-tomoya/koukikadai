#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class CharacterBase {
protected:
	//�ړ����x
	float speed_ = 0;
	//�摜�T�C�Y
	tnl::Vector3 size_{ 0,0,0 };
	//�\�����W
	tnl::Vector3 pos_ { 0,0,0 };
public:
	virtual void Update(float delat_time) {};
	virtual void Draw(float delat_time) {};
};