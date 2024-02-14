#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class Ground {
public:
	void Initialize(Model* model);

	void Update();

	void Draw(const ViewProjection& viewProjection);

private:
	// ワールド変換データ
	WorldTransform worldTransform_;


	// モデル
	Model* GroundModel_ = nullptr;
};
