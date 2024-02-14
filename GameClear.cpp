#include "GameClear.h"
#include "AxisIndicator.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "MatrixTrans.h"
#include "Player.h"
#include "TextureManager.h"
#include <cassert>
#include <fstream>

GameClear::GameClear() {}

GameClear::~GameClear() { delete sprite_; }

void GameClear::Initialize() {

	// シーンのクラス化をするときはCPPに下の三つが必要
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	gamecleartexture_ = TextureManager::Load("gameclear.png");
	fedetexture_ = TextureManager::Load("kabe.png");

	Sprite_ = Sprite::Create(fedetexture_, {0, 0});

	sprite_ = Sprite::Create(gamecleartexture_, {0, 0});
	// ビュープロジェクションの初期化
	viewProjection_.farZ = 1000.0f;

	worldTransform_.Initialize();

	viewProjection_.Initialize();
}

void GameClear::Update() {
	if (input_->TriggerKey(DIK_SPACE)) {
		ClearSceneEnd_ = true;
	}

	Sprite_->SetColor({1, 1, 1, fede});

	if (input_->TriggerKey(DIK_SPACE)) {
		fedeoutFlag = true;
		fede = 0;
	}
	if (fedeoutFlag == true) {
		fede += 0.01f;
		if (fede >= 1.0) {
			ClearSceneEnd_ = true;
			fede = 1.0;
			fedeoutFlag = false;
		}
	} else {
		fede -= 0.01f;
	}
}

void GameClear::Draw() {
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	sprite_->Draw();
	Sprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
#pragma endregion
}