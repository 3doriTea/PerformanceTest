#include "SimplePlane.h"
#include "Engine/Model.h"
#include <cassert>

SimplePlane::SimplePlane(GameObject* _pParent) :
	GameObject{ _pParent },
	hModel_{ 0 }
{
}

void SimplePlane::Initialize()
{
	hModel_ = Model::Load("SimplePlane/SimplePlane.fbx");
	assert(hModel_ && "モデルの読み込みに失敗");
}

void SimplePlane::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}
