#pragma once

#include "../dxlib_ext/dxlib_ext.h"

class ResourceManager {
private:
	// ‰æ‘œ‚ÌƒpƒX‚Ìcsv—p
	std::vector<std::vector<std::string>> graphics_csv_;
	// ‰æ‘œ‚ğ•Û‘¶‚·‚émap
	std::unordered_map < std::string, int> graphics_map_;

	ResourceManager();
public:
	static ResourceManager* GetInstance_ResourceManager();

	// ‰æ‘œ‚ğ“Ç‚İ‚ŞŠÖ”
	int LoadGraph_(std::string graph_name);
	// ‰æ‘œ‚ğíœ‚·‚éŠÖ”
	void deleteGraph_(std::string graph_name);

};