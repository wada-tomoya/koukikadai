#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	//�摜csv�ǂݍ���
	graphics_csv_ = tnl::LoadCsv("csv/Resource_csv/graph.csv");
	//�A�j���[�V����csv�ǂݍ���
	animation_csv_ = tnl::LoadCsv("csv/Resource_csv/animation.csv");
}

ResourceManager* ResourceManager::GetInstance_ResourceManager() {
	static ResourceManager* instance(nullptr);
	if (!instance) {
		instance = new ResourceManager();
	}
	return instance;
}

int ResourceManager::LoadGraph_(std::string graph_name) {
	//map����graph_name�ɑΉ�����摜�n���h����������
	auto it = graphics_map_.find(graph_name);

	//���łɃ��[�h���Ă���ꍇ�A���̉摜�n���h����������
	if (it != graphics_map_.end()) {
		return graphics_map_[graph_name];
	}

	//���[�h���ĂȂ��ꍇ�A�摜�ǂݍ���
	for (int y = 1; y < graphics_csv_.size(); ++y) {
		if (graphics_csv_[y][0].getString().c_str() == graph_name) {
			int gpc_hdl = LoadGraph(graphics_csv_[y][1].getString().c_str(), true);

			//map�ɓǂݍ��񂾉摜��ۑ�
			graphics_map_.insert(std::make_pair(graph_name,gpc_hdl));

			//�摜�n���h����Ԃ�
			return gpc_hdl;
		}
	}

	//�ǂݍ��ݏo���Ȃ������ꍇ-1��Ԃ�
	return -1;
}

void ResourceManager::DeleteGraph_(std::string graph_name) {
	// file_path�ɑΉ�����摜�n���h����T��
	auto it = graphics_map_.find(graph_name);

	// �摜�n���h�������
	DeleteGraph(it->second);

	// file_path�̉摜�p�X���폜����
	if (it != graphics_map_.end()) {
		graphics_map_.erase(graph_name);
	}
}

std::shared_ptr<std::vector<int>> ResourceManager::LoadAnim_(std::string animation_name) {
	//animation_name�ɑΉ�����A�j���[�V�����n���h����T��
	auto it = animation_map_.find(animation_name);

	//���łɃ��[�h���Ă���ꍇ�A���̃A�j���[�V�����n���h����������
	if (it != animation_map_.end()) {
		return animation_map_[animation_name];
	}

	//���[�h���Ă��Ȃ��ꍇ�A�ǂݍ���
	for (int y = 1; y < animation_csv_.size(); ++y) {
		if (animation_csv_[y][0].getString().c_str() == animation_name) {

			std::shared_ptr<std::vector<int>> anim_hdl_ 
				= std::make_shared<std::vector<int>>(animation_csv_[y][ANIMATION_CSV_ITEM::TOTAL_DIV_NUM].getInt());

			//anim_hdl_��csv����ǂݎ�����f�[�^������
			LoadDivGraph(animation_csv_[y][ANIMATION_CSV_ITEM::PATH].getString().c_str(),
				(int)animation_csv_[y][ANIMATION_CSV_ITEM::TOTAL_DIV_NUM].getInt(),
				(int)animation_csv_[y][ANIMATION_CSV_ITEM::X_DIV_NUM].getInt(),
				(int)animation_csv_[y][ANIMATION_CSV_ITEM::Y_DIV_NUM].getInt(),
				(int)animation_csv_[y][ANIMATION_CSV_ITEM::X_SIZE].getInt(),
				(int)animation_csv_[y][ANIMATION_CSV_ITEM::Y_SIZE].getInt(),
				anim_hdl_->data());

			//animation_map_�ɕۑ�
			animation_map_.insert(std::make_pair(animation_name, anim_hdl_));

			return anim_hdl_;
		}
	}
}
