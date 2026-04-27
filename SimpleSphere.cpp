#include "SimpleSphere.h"
#include "Engine/Model.h"
#include <cassert>

SimpleSphere::SimpleSphere(GameObject* _pParent) :
	GameObject{ _pParent },
	hModel_{ 0 }
{
}

void SimpleSphere::Initialize()
{
	hModel_ = Model::Load("SimpleSphere/SimpleSphere.fbx");
	assert(hModel_ >= 0 && "シンプルな球体モデルの読み込みに失敗");
}

void SimpleSphere::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}
