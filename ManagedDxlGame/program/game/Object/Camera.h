#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Camera {
private:

public:
	tnl::Vector3 target_ ;
	void Update(tnl::Vector3 target_pos);
};