#include "RailCamera.h"
#include "ImGuiManager.h"
#include "MatrixTrans.h"

void RailCamera::Initialize() {

	worldTransform_.Initialize();

	// ビュープロジェクション初期化
	viewProjection_.Initialize();

	// ビュープロジェクションの初期化
	viewProjection_.farZ = 3000.0f;
}

void RailCamera::Update() {

	worldTransform_.UpdateMatrix();

	// カメラオブジェクトのワールド行列を計算する
	viewProjection_.matView = Inverse(worldTransform_.matWorld_);

	viewProjection_.UpdateMatrix();
}