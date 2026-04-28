#pragma once
#include "Engine/GameObject.h"
#include "PerformanceTester.h"

#pragma comment(lib, "Winmm.lib")  // timeBeginPeriodと timeEndPeriodで必要

// LARGE_INTEGER の前方宣言
typedef union _LARGE_INTEGER LARGE_INTEGER;

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

	LARGE_INTEGER currentMicro_;   // 現在のCPU時間 (マイクロ秒)
	LARGE_INTEGER previousMicro_;  // 前回のCPU時間 (マイクロ秒)
	LARGE_INTEGER cpuFrequency_;   // CPU 周波数
};
