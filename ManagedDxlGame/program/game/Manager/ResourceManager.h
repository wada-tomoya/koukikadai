#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class ResourceManager {
private:
	//�ꖇ�摜�֘A
	//�摜�̃p�X��csv�p
	std::vector <std::vector<std::string>> graphics_csv_;
	//�摜��ۑ�����map
	std::unordered_map <std::string, int> graphics_map_;

	//�}�b�v�`�b�v�֘A
	//�}�b�v�`�b�v�̃p�X��csv
	std::vector <std::vector<std::string>> animation_csv_;
	//�}�b�v�`�b�v��ۑ�����map
	std::unordered_map <std::string, int> animation_map_;

	ResourceManager();
public:
	static ResourceManager* GetInstance_ResourceManager();

	//�摜��ǂݍ��ފ֐�
	int LoadGraph_(std::string graph_name);
	//�摜���폜����֐�
	void DeleteGraph_(std::string graph_name);
};
