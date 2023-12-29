#include "Block.h"

Block::Block(){
	LoadDivGraph("graphics/MapChip/[A]Water3_Cave1_pipo.png", 40, 8, 5, 32, 32, graph_hdl_);
	
	mapchip_csv_ = tnl::LoadCsv<int>("csv/map.csv");
}

Block::~Block() {
	for (int i = 0; i < 40; i++)
		DeleteGraph(graph_hdl_[i]);
}

void Block::Draw(const Camera& camera) {
	//マップチップ表示
	for (int y = 0; y < mapchip_csv_.size(); y++) {
		for (int x = 0; x < mapchip_csv_[0].size(); x++) {
			tnl::Vector3 draw_pos_ = tnl::Vector3(x * size_, y * size_, 0.0f) - camera.target_;

			if (mapchip_csv_[y][x] <= 0) continue; 
			DrawGraph(draw_pos_.x, draw_pos_.y, graph_hdl_[mapchip_csv_[y][x]], true);
		}
	}
}