#pragma once
#include "Engine/GameObject.h"

class SimpleCamera : public GameObject
{
public:
	SimpleCamera(GameObject* _pParent);

	void Initialize() override;

	void Update() override;

private:
	int hModel_;  // モデルハンドル
};
