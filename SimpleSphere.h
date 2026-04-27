#pragma once
#include "Engine/GameObject.h"

class SimpleSphere : public GameObject
{
public:
	SimpleSphere(GameObject* _pParent);

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
