#include "Skydome.h"
#include <assert.h>

void Skydome::Initialize(Model* model) {
	assert(model);

	// 引数として受け取ったデータをメンバ変数に記録する
	model_ = model;

	worldTransform_.Initialize();

	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};

	worldTransform_.translation_.z = 0.0f;
}

void Skydome::Update() {

	worldTransform_.UpdateMatrix();

	// worldTransform_.TransferMatrix();
}

void Skydome::Draw(ViewProjection& viewProjection_) {

	model_->Draw(worldTransform_, viewProjection_);
}