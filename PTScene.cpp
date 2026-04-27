#include "PTScene.h"
#include "SimplePlane.h"
#include "SimpleSphere.h"
#include "SimpleCamera.h"

PTScene::PTScene(GameObject* _pParent) :
	GameObject{ _pParent }
{
}

void PTScene::Initialize()
{
	Instantiate<SimplePlane>(this);
	Instantiate<SimpleCamera>(this);
}

void PTScene::Update()
{
}
