#pragma once
#include "Engine/GameObject.h"
#include <cstdint>
#include "Vector3.h"

/// <summary>
/// パフォーマンス計測シーン
/// </summary>
class PTScene : public GameObject
{
public:
	PTScene(GameObject* _pParent);

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 毎フレームの更新処理
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

	/// <summary>
	/// 球を配置する座標を取得する
	/// </summary>
	/// <returns></returns>
	Vector3 GetInstancePositionSphere();

private:
	uint32_t sphereCount_;  // 球体の数
};
