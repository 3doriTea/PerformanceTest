#include "PTScene.h"
#include "Engine/Input.h"
#include "SimplePlane.h"
#include "SimpleSphere.h"
#include "SimpleCamera.h"
#include "PerformanceReader.h"
#include <cmath>

PTScene::PTScene(GameObject* _pParent) :
	GameObject{ _pParent },
	sphereCount_{ 0 }
{
}

void PTScene::Initialize()
{
	Instantiate<SimplePlane>(this);
	Instantiate<SimpleCamera>(this);
	Instantiate<PerformanceReader>(this);
}

void PTScene::Update()
{
	if (Input::IsKey(DIK_G))
	{
		for (int i = 0; i < 30; i++)
		{
			Instantiate<SimpleSphere>(this)
				->SetPosition(GetInstancePositionSphere());
			sphereCount_++;
		}
	}
}

Vector3 PTScene::GetInstancePositionSphere()
{
	using namespace DirectX;

	static float angle{ 0.0f };
	static float distance{ 0.0f };
	static int countMax{ 0 };
	static const int ADD_COUNT{ 4 };
	static const float ADD_DISTANCE{ 2.0f };

	angle += XM_2PI / countMax;
	if ((angle + FLT_EPSILON) >= XM_2PI)
	{
		angle = 0.0f;
		distance += ADD_DISTANCE;
		countMax += ADD_COUNT;
	}
	Vector3 position{};

	// 円形に広がる
	position.x = std::sinf(angle) * distance;
	position.y = std::cosf(angle) * distance;

	return position;
}
