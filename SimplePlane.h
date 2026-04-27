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
	/// 更新処理
	/// </summary>
	inline void Update() override {}

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 解放処理
	/// </summary>
	inline void Release() override {}

private:
	int hModel_;  // モデルのハンドル
};
