#pragma once
#include "Audio.h"
#include "GameScene.h"
#include "Input.h"
#include "Model.h"
#include "Scene.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <DirectXCommon.h>

class GameClear {
public:
	GameClear();

	~GameClear();

	void Initialize();

	void Update();

	void Draw();

	bool ClearSceneEnd_ = false;

	bool IsSceneEnd() { return ClearSceneEnd_; }
	SCENE NextScene() { return SCENE::Title; }

	float fede = 1.0f;

	bool fedeoutFlag = false;

	void fedeinstart();

	bool GameSceneEnd_ = false;

	void Start() { ClearSceneEnd_ = false; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t gamecleartexture_ = 0;

	Sprite* sprite_ = nullptr;

	uint32_t fedetexture_ = 0;

	Sprite* Sprite_ = nullptr;

	// ワールド変換
	WorldTransform worldTransform_;

	// ビュープロジェクション
	ViewProjection viewProjection_;
};
