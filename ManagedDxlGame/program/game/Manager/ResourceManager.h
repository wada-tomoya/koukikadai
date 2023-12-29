#pragma once

#include "../dxlib_ext/dxlib_ext.h"

class ResourceManager {
private:
	// 画像のパスのcsv用
	std::vector<std::vector<std::string>> graphics_csv_;
	// 画像を保存するmap
	std::unordered_map < std::string, int> graphics_map_;

	ResourceManager();
public:
	static ResourceManager* GetInstance_ResourceManager();

	// 画像を読み込む関数
	int LoadGraph_(std::string graph_name);
	// 画像を削除する関数
	void deleteGraph_(std::string graph_name);

};