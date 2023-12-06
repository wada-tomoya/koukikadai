#pragma once
#include "SceneBace.h"

class PlayScene : public SceneBace
{
private:

public:
	PlayScene();
	void Update(float delta_time) override;
	void Draw(float delta_tjime) override;
};

