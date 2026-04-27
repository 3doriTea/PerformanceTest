#include "PerformanceReader.h"
#include <format>
#include <cassert>
#include "Engine/Input.h"
#include "PTScene.h"

PerformanceReader::PerformanceReader(GameObject* _pParent) :
	GameObject{ _pParent },
	tester_{},
	currentMicro_{},
	previousMicro_{}
{
}

void PerformanceReader::Update()
{
	static const float MICRO_TO_SEC{ 0.0000001f };  // マイクロ秒を秒に変換する

	if (QueryPerformanceCounter(&currentMicro_) == FALSE)
	{
		//assert(false && "CPU時間取得に失敗");
		return;
	}

	// 前フレームと今のマイクロ秒差
	const LONGLONG diff{ currentMicro_.QuadPart - previousMicro_.QuadPart };

	currentMicro_ = previousMicro_;

	// フレーム間時間
	static const float DT{ static_cast<float>(diff) * MICRO_TO_SEC };

	tester_.Update(DT);

	PTScene* pPTScene{ dynamic_cast<PTScene*>(GetParent()) };
	if (pPTScene)
	{
		if (Input::IsKey(DIK_G))
		{
			tester_.Stamp(std::format("SphereCount: {}", pPTScene->GetSphereCount()));
		}
	}

	if (Input::IsKeyDown(DIK_M))
	{
		tester_.Dump("./Performance.log");
	}
}
