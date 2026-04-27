#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// パフォーマンス計測シーン
/// </summary>
class PTScene : public GameObject
{
public:
	PTScene(GameObject* _parent);

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 毎フレームの更新処理
	/// </summary>
	void Update() override;
};
