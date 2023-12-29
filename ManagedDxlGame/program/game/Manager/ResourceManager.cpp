#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	//csv�ǂݍ���
	graphics_csv_ = tnl::LoadCsv<std::string>("csv/graph.csv");

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
		if (graphics_csv_[y][0].c_str() == graph_name) {
			int gpc_hdl = LoadGraph(graphics_csv_[y][1].c_str(), true);

			//map�ɓǂݍ��񂾉摜��ۑ�
			graphics_map_.insert(std::make_pair(graph_name,gpc_hdl));

			//�摜�n���h����Ԃ�
			return gpc_hdl;
		}
	}

	//�ǂݍ��ݏo���Ȃ������ꍇ-1��Ԃ�
	return -1;
}

void ResourceManager::deleteGraph_(std::string graph_name) {
	// file_path�ɑΉ�����摜�n���h����T��
	auto it = graphics_map_.find(graph_name);

	// �摜�n���h�������
	DeleteGraph(it->second);

	// file_path�̉摜�p�X���폜����
	if (it != graphics_map_.end()) {
		graphics_map_.erase(graph_name);
	}
}