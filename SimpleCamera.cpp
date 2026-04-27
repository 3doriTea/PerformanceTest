#include "SimpleCamera.h"
#include "Engine/Input.h"
#include "Vector3.h"

SimpleCamera::SimpleCamera(GameObject* _pParent) :
	GameObject{ _pParent }
{
}

void SimpleCamera::Initialize()
{
}

void SimpleCamera::Update()
{
	if (Input::IsKey(DIK_W))
	{

	}
}

bool SimpleCamera::UpdatePosition()
{
	constexpr float DT{ 1.0f / 60.0f };

	Vector3 move{};
	if (Input::IsKey(DIK_W))
	{
		move.z += move_.speedPerSec;
	}
	if (Input::IsKey(DIK_S))
	{
		move.z -= move_.speedPerSec;
	}
	if (Input::IsKey(DIK_A))
	{
		move.x -= move_.speedPerSec;
	}
	if (Input::IsKey(DIK_D))
	{
		move.x += move_.speedPerSec;
	}
	if (Input::IsKey(DIK_Q))
	{
		move.y -= move_.speedPerSec;
	}
	if (Input::IsKey(DIK_E))
	{
		move.y += move_.speedPerSec;
	}

	Vector3 position{ transform_.position_ };
	Vector3 moveWorld{ DirectX::XMVector3TransformCoord(move, transform_.GetNormalMatrix()) };
	position = position + moveWorld * DT;
	Transform().SetPosition(position);

	return true;  // TOOD: 移動しなかったらfalseを返すようにする
}

bool SimpleCamera::UpdateAngle()
{
	const float DT{ System().Get<GameTime>().GetDeltaTime() };
	const auto& input{ System().Get<Input>().Getter() };

	Vector3 moveAngle{};
	if (input.IsKey(KeyCode::Down))
	{
		moveAngle.x += moveAnglePerSecRad_;
	}
	if (input.IsKey(KeyCode::Up))
	{
		moveAngle.x -= moveAnglePerSecRad_;
	}
	if (input.IsKey(KeyCode::Right))
	{
		moveAngle.y += moveAnglePerSecRad_;
	}
	if (input.IsKey(KeyCode::Left))
	{
		moveAngle.y -= moveAnglePerSecRad_;
	}

	Vector3 angle{ Transform().GetRotation() };
	angle = angle + moveAngle * DT;
	Transform().SetRotation(angle);

	return true;  // TODO: 回転しなかったらfalseを返すようにする
}
