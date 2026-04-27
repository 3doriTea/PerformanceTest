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
	/// 描画処理
	/// </summary>
	void Draw() override;
};
