#include "Title.h"
#include "AxisIndicator.h"
#include "GameClear.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "MatrixTrans.h"
#include "Player.h"
#include "TextureManager.h"
#include <cassert>
#include <fstream>

Title::Title() {}

Title::~Title() { delete sprite_; }

void Title::Initialize() {

	// シーンのクラス化をするときはCPPに下の三つが必要
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	titletexture_ = TextureManager::Load("title.png");
	fedetexture_ = TextureManager::Load("kabe.png");

	sprite_ = Sprite::Create(titletexture_, {0, 0});
	Sprite_ = Sprite::Create(fedetexture_, {0, 0});
	// ビュープロジェクションの初期化
	viewProjection_.farZ = 1000.0f;

	worldTransform_.Initialize();

	viewProjection_.Initialize();
}

// void TitleScene::Scene() {}

void Title::fedeinstart() {}

void Title::Update() {

	Sprite_->SetColor({1, 1, 1, fede});

	TitleTime--;
	sprite_->SetPosition({0, TitleTime});

	if (TitleTime < -60) {
		TitleTime = 0;
	}

	if (input_->TriggerKey(DIK_SPACE)) {
		fedeoutFlag = true;
		fede = 0;
		// TitleSceneEnd_ = true;
	}
	if (fedeoutFlag == true) {
		fede += 0.01f;
		if (fede >= 1.0) {
			TitleSceneEnd_ = true;
			fede = 1.0;
			fedeoutFlag = false;
		}
	} else {
		fede -= 0.01f;
	}
}

void Title::Draw() {

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
