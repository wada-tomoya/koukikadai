#include "ResourceManager.h"

ResourceManager::ResourceManager() {
	//csv読み込み
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
	//mapからgraph_nameに対応する画像ハンドルをさがす
	auto it = graphics_map_.find(graph_name);

	//すでにロードしている場合、その画像ハンドルをかえす
	if (it != graphics_map_.end()) {
		return graphics_map_[graph_name];
	}

	//ロードしてない場合、画像読み込み
	for (int y = 1; y < graphics_csv_.size(); ++y) {
		if (graphics_csv_[y][0].c_str() == graph_name) {
			int gpc_hdl = LoadGraph(graphics_csv_[y][1].c_str(), true);

			//mapに読み込んだ画像を保存
			graphics_map_.insert(std::make_pair(graph_name,gpc_hdl));

			//画像ハンドルを返す
			return gpc_hdl;
		}
	}

	//読み込み出来なかった場合-1を返す
	return -1;
}

void ResourceManager::deleteGraph_(std::string graph_name) {
	// file_pathに対応する画像ハンドルを探す
	auto it = graphics_map_.find(graph_name);

	// 画像ハンドルを解放
	DeleteGraph(it->second);

	// file_pathの画像パスを削除する
	if (it != graphics_map_.end()) {
		graphics_map_.erase(graph_name);
	}
}