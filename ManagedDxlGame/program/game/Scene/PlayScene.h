#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "SceneBace.h"
#include "../Object/Block.h"
#include "../Object/Camera.h"
#include "../Character/Player.h"
#include "../Manager/ResourceManager.h"
#include "../Character/Enemy.h"
#include "../Manager/Sspawner.h"
#include "../Object/ProtectObject.h"

class PlayScene : public SceneBace{
private:
	//�w�i�̉摜�n���h��
	int background_hdl_ = 0;
	//�w�i�\�����W,����̍��W�ƉE���̍��W
	tnl::Vector3 bg_pos_{ 0,-100,0 }, map_endpos_{1968,724,0};
	//�I�u�W�F�N�g�̃v���n�u
	std::shared_ptr<Block> block_ = nullptr;
	std::shared_ptr<Camera> camera_ = nullptr;
	std::shared_ptr<Player> player_ = nullptr;
	std::shared_ptr<ProtectObject> protectobj_= nullptr;
	std::shared_ptr<Enemy> enemy_ = nullptr;
	//�\������u���b�N�̃��X�g
	std::list<std::shared_ptr<Block>> blocks_;

	//���G�X�|���ʒu
	tnl::Vector3 enemy_spon_pos{ 200,200,0 };
	tnl::Vector3 enemy_spon_pos2{ 1000,200,0 };

public:
	PlayScene();

	//���s�֐�
	void Update(float delta_time) override;
	//�\���֐�
	void Draw(float delta_time) override;
};
