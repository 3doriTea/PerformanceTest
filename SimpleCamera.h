#pragma once
#include "Engine/GameObject.h"

/// <summary>
/// シンプルなカメラ
/// </summary>
class SimpleCamera : public GameObject
{
public:
	SimpleCamera(GameObject* _pParent);

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize() override;

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

	/// <summary>
	/// 座標の更新
	/// </summary>
	/// <returns>座標の更新が発生した true / false</returns>
	bool UpdatePosition();

	/// <summary>
	/// 角度の更新
	/// </summary>
	/// <returns>角度の更新が発生した true / false</returns>
	bool UpdateAngle();

private:
	struct
	{
		float speedPerSec;     // 1秒間あたりの移動量
		float anglePerSecRad;  // 1秒間あたりの回転角度(ラジアン)
	} move_;  // 移動情報
};
