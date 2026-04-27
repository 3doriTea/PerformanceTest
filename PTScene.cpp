#include "PTScene.h"
#include "SimplePlane.h"
#include "SimpleSphere.h"

PTScene::PTScene(GameObject* _parent)
{
}

void PTScene::Initialize()
{
	Instantiate<SimplePlane>(this);
	Instantiate<SimpleSphere>(this);
}

void PTScene::Update()
{
}
