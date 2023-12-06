#pragma once
#include "../Scene/SceneBace.h"

class GameManager {
private:
	SceneBace* nowscene_ = nullptr;

public:
	GameManager(SceneBace* startscene);
	static GameManager* GetInstance(SceneBace* startscene = nullptr);
	void Update(float delta_time);
};