#pragma once
#include "BaseCharacter.h"
#include "Input.h"
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class Player : public BaseCharacter {
public:
	Player();
	~Player();

	Vector3 GetWorldPosition();

	const WorldTransform& GetWorldTransform() { return worldTransformBase_; }


	void SetViewProjection(const ViewProjection* viewprojection) {
		viewProjection_ = viewprojection;
	}

	void Initialize(const std::vector<Model*>& models) override;

	void Update() override;

	void Draw(const ViewProjection& viewProjection) override;

	// 浮遊ギミック初期化
	void InitializeFloatingGimmick();
	// 浮遊ギミック更新
	void UpdateFloatingGimmick();

	// 浮遊ギミックの媒介変数
	float floatingParameter_ = 0.0f;

	void Reset() { worldTransformBody_.translation_ = {0.0f, 1.0f, 0.0f}; }

	float GetPlayerX() { return worldTransformBase_.translation_.x; } 
	float GetPlayerY() { return worldTransformBase_.translation_.y; }
	float GetPlayerZ() { return worldTransformBase_.translation_.z; } 

private:

	WorldTransform worldTransformBase_;
	WorldTransform worldTransformBody_;
	WorldTransform worldTransformHead_;
	WorldTransform worldTransformL_arm_;
	WorldTransform worldTransformR_arm_;

	// 3Dモデル
	Model* modelFighterBody_ = nullptr;
	Model* modelFighterHead_ = nullptr;
	Model* modelFighterL_arm_ = nullptr;
	Model* modelFighterR_arm_ = nullptr;

	// モデル
	Model* playerModel_ = nullptr;

	// テクスチャ
	uint32_t playerTextureHandle_ = 0u;

	// キーボード入力
	Input* input_ = nullptr;

	// カメラのビュープロジェクション
	const ViewProjection* viewProjection_ = nullptr;
};
