#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// シンプルな平らな地面
/// </summary>
class SimplePlane : public GameObject
{
public:
	SimplePlane(GameObject* _pParent);

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;

private:
	int hModel_;  // モデルのハンドル
};
