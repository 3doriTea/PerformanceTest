#include "SimpleCamera.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Vector3.h"

SimpleCamera::SimpleCamera(GameObject* _pParent) :
	GameObject{ _pParent },
	move_
	{
		.speedPerSec = 30.0f,
		.anglePerSecRad = 30.0f,//0.52359877559f
	}
{
}

void SimpleCamera::Initialize()
{
}

void SimpleCamera::Update()
{
	UpdatePosition();
	UpdateAngle();

	Camera::SetPosition(transform_.position_);
	Vector3 position{ transform_.position_ };
	Vector3 forward
	{
		DirectX::XMVector3TransformCoord(
			Vector3::Forward(),
			transform_.GetNormalMatrix())
	};

	Vector3 targetPosition{ XMLoadFloat3(&position) + XMLoadFloat3(&forward) };

	Camera::SetTarget(targetPosition);
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
	transform_.position_ = position;

	return true;  // TOOD: 移動しなかったらfalseを返すようにする
}

bool SimpleCamera::UpdateAngle()
{
	const float DT{ 1.0f / 60.0f };

	Vector3 moveAngle{};
	if (Input::IsKey(DIK_DOWN))
	{
		moveAngle.x += move_.anglePerSecRad;
	}
	if (Input::IsKey(DIK_UP))
	{
		moveAngle.x -= move_.anglePerSecRad;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		moveAngle.y += move_.anglePerSecRad;
	}
	if (Input::IsKey(DIK_LEFT))
	{
		moveAngle.y -= move_.anglePerSecRad;
	}

	Vector3 angle{ transform_.rotate_ };
	angle = angle + moveAngle * DT;
	transform_.rotate_ = angle;

	return true;  // TODO: 回転しなかったらfalseを返すようにする
}
