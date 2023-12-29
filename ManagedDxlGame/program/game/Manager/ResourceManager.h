#pragma once

#include "../dxlib_ext/dxlib_ext.h"

class ResourceManager {
private:
	// �摜�̃p�X��csv�p
	std::vector<std::vector<std::string>> graphics_csv_;
	// �摜��ۑ�����map
	std::unordered_map < std::string, int> graphics_map_;

	ResourceManager();
public:
	static ResourceManager* GetInstance_ResourceManager();

	// �摜��ǂݍ��ފ֐�
	int LoadGraph_(std::string graph_name);
	// �摜���폜����֐�
	void deleteGraph_(std::string graph_name);

};