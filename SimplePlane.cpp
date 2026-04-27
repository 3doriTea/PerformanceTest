#include "SimplePlane.h"
#include "Engine/Model.h"
#include <cassert>
#include "FileSystemInclude.h"

SimplePlane::SimplePlane(GameObject* _pParent) :
	GameObject{ _pParent },
	hModel_{ -1 }
{
}

void SimplePlane::Initialize()
{
	hModel_ = Model::Load("./SimplePlane/SimplePlane.fbx");
	assert(hModel_ >= 0 && "モデルの読み込みに失敗");
}

void SimplePlane::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}
