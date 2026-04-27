#pragma once
#include "Engine/GameObject.h"
#include "PerformanceTester.h"

/// <summary>
/// ゲームのパフォーマンスを読み取るゲームオブジェクト
/// </summary>
class PerformanceReader : public GameObject
{
public:
	PerformanceReader(GameObject* _pParent);

	/// <summary>
	/// 初期化処理
	/// </summary>
	inline void Initialize() override {}

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	inline void Draw() override {}

	/// <summary>
	/// 解放処理
	/// </summary>
	inline void Release() override {}

private:
	PerformanceTester tester_;  // パフォーマンス計測
};
