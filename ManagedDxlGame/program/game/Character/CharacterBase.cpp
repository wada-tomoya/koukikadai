#include "CharacterBase.h"

void CharacterBase::Anim_Play(std::shared_ptr<std::vector<int>> animhdl, float delta_time) {
	//list�̃T�C�Y
	int hdlsize_ = animhdl->size();

	//�A�j���[�V�����Đ�
	anim_time_ += delta_time;
	for (; anim_time_ > anim_speed_;) {
		anim_frame_++;
		anim_frame_ %= hdlsize_;
		anim_time_ = 0;
	}
}