#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class ResourceManager {
private:
	//�ꖇ�摜�֘A
	//�摜�̃p�X��csv�p
	std::vector <std::vector<tnl::CsvCell>> graphics_csv_;
	//�摜��ۑ�����map
	std::unordered_map <std::string, int> graphics_map_;
//-----------------------------------------------------------------------------------------------
 
	//�A�j���[�V�����֘A�ƃ}�b�v�`�b�v
	//�A�j���[�V�����̃p�X��csv
	std::vector <std::vector<tnl::CsvCell>> animation_csv_;
	//�A�j���[�V������ۑ�����map
	std::unordered_map <std::string, std::shared_ptr<std::vector<int>>> animation_map_;
	//csv�t�@�C���̃A�C�e��
	enum ANIMATION_CSV_ITEM {
		PATH = 1,
		TOTAL_DIV_NUM,
		X_DIV_NUM,
		Y_DIV_NUM,
		X_SIZE,
		Y_SIZE,
	};
	
	
//-----------------------------------------------------------------------------------------------

	ResourceManager();
public:
	static ResourceManager* GetInstance_ResourceManager();

//----------------------------------------------------------------------------------------------

	//�摜��ǂݍ��ފ֐�
	int LoadGraph_(std::string graph_name);
	//�摜���폜����֐�
	void DeleteGraph_(std::string graph_name);

//-----------------------------------------------------------------------------------------------

	//�A�j���[�V�����ƃ}�b�v�`�b�v��ǂݍ��ފ֐�
	std::shared_ptr<std::vector<int>> LoadAnim_(std::string animation_name);
};
