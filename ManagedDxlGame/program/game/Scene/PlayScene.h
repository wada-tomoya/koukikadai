#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include "SceneBace.h"
#include "../Object/Block.h"
#include "../Object/Camera.h"
#include "../Character/Player.h"

class PlayScene : public SceneBace{
private:
	int background_hdl_ = 0;
	
	std::shared_ptr<Block> block_ = nullptr;
	std::shared_ptr<Camera> camera_ = nullptr;
	std::shared_ptr<Player> player_ = nullptr;

	//表示するブロックのリスト
	std::list<std::shared_ptr<Block>> blocks_;
public:
	PlayScene();
	void Update(float delta_time) override;
	void Draw(float delta_tjime) override;
};
