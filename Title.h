#pragma once

#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "GameClear.h"
#include "Input.h"
#include "Model.h"
#include "Scene.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include <DebugCamera.h>
#include <Player.h>
#include <sstream>

class Title {

public:
	Title();

	~Title();

	void Initialize();

	void Update();

	void Draw();

	bool TitleSceneEnd_ = false;

	bool IsSceneEnd() { return TitleSceneEnd_; }
	SCENE NextScene() { return SCENE::Reset; }

	bool ClearSceneEnd_ = false;

	float TitleTime = 0;

	float fede = 1.0f;

	bool fedeoutFlag = false;

	void fedeinstart();

	void Start() { TitleSceneEnd_ = false; }

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// テクスチャハンドル
	uint32_t titletexture_ = 0;

	Sprite* sprite_ = nullptr;

	uint32_t fedetexture_ = 0;

	Sprite* Sprite_ = nullptr;

	// ワールド変換
	WorldTransform worldTransform_;

	// ビュープロジェクション
	ViewProjection viewProjection_;
};
