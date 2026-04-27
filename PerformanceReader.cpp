#include "PerformanceReader.h"
#include "Engine/Input.h"

PerformanceReader::PerformanceReader(GameObject* _pParent) :
	GameObject{ _pParent },
	tester_{}
{
}

void PerformanceReader::Update()
{
	static const float DT{ 1.0f / 60.0f };

	tester_.Update(DT);

	GetParent();
	if ()
	{
	}
}
