#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Enemy.h"
#include "FollowCamera.h"
#include "Ground.h"
#include "Input.h"
#include "MatrixTrans.h"
#include "Model.h"
#include "Player.h"
#include "Scene.h"
#include "Skydome.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "reset.h"
#include <memory>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	bool GameSceneEnd_ = false;

	bool IsSceneEnd() { return GameSceneEnd_; }
	SCENE NextScene() { return SCENE::Clear; }

	bool ResetSceneEnd_ = false;

	void Start() { GameSceneEnd_ = false; }

	float fede = 1.0f;

	bool fedeoutFlag = false;

	void fedeinstart();

	void playerReset() { player_->Reset(); }

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// ワールドトランスフォーム
	WorldTransform worldTransform_;

	// ビュープロジェクション
	ViewProjection viewProjection_;

	// デバッグカメラ
	DebugCamera* debugCamera_ = nullptr;
	// デバッグカメラ
	bool isDebugCameraActive_ = false;

	// プレイヤーのテクスチャ
	uint32_t TextureHandle_ = 0;

	uint32_t fedetexture_ = 0;

	Sprite* Sprite_ = nullptr;

	// スプライト
	Sprite* playerSprite_ = nullptr;

	// Model* model_ = nullptr;
	std::unique_ptr<Model> model_;

	// プレイヤー
	std::unique_ptr<Player> player_;

	// 敵キャラ
	std::unique_ptr<Enemy> enemy_;

	// 天球
	std::unique_ptr<Skydome> skydome_;

	std::unique_ptr<Model> skydomeModel_;

	// グラウンド
	std::unique_ptr<Ground> ground_;

	std::unique_ptr<Model> groundModel_;

	// フォローカメラ
	std::unique_ptr<FollowCamera> followCamera_;

	// 3Dモデル
	// 自機
	std::unique_ptr<Model> modelFighterBody_;
	std::unique_ptr<Model> modelFighterHead_;
	std::unique_ptr<Model> modelFighterL_arm_;
	std::unique_ptr<Model> modelFighterR_arm_;

	//  エネミーモデルデータ
	std::unique_ptr<Model> modelEnemy_;
	// エネミーモデル
	std::unique_ptr<Model> enemyFighterBody_;
	std::unique_ptr<Model> enemyFighterHead_;
	std::unique_ptr<Model> enemyFighterL_arm_;
	std::unique_ptr<Model> enemyFighterR_arm_;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
