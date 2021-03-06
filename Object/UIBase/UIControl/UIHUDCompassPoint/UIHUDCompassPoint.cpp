// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPoint.h"

UUIHUDCompassPoint::UUIHUDCompassPoint()
{
	_FT = 255;
}

void UUIHUDCompassPoint::Destroyed()
{
	Super::Destroyed();
	_TrackingActor = nullptr;
	_CompassIcon = nullptr;
}

void UUIHUDCompassPoint::SetActor(AActor* pTrack)
{
	_TrackingActor = pTrack;
}

void UUIHUDCompassPoint::SetTexture(UMaterialInstance* pTexture)
{
	_CompassIcon = pTexture;
}

void UUIHUDCompassPoint::setFT(uint8 FT)
{
	_FT = FT;
}

void UUIHUDCompassPoint::setOrder(int32 Order)
{
	_iOrder = Order;
}

int32 UUIHUDCompassPoint::getOrder()
{
	return _iOrder;
}

uint8 UUIHUDCompassPoint::getFT()
{
	return _FT;
}

bool UUIHUDCompassPoint::IsOnCompass(AController* ctrlRequesting)
{
	return IsEnabled();
}

FVector UUIHUDCompassPoint::GetLocation()
{
	FVector V = FVector( 0,0,0 );
	if (_TrackingActor != nullptr)
	{
		return _TrackingActor->GetActorLocation();
	}
	else
	{
		return V;
	}
}

float UUIHUDCompassPoint::GetRotation(AActor* fromactor, FVector fromlocation)
{
	FVector fromloc = FVector(0, 0, 0);
	FVector toloc = FVector(0, 0, 0);
	float Result = 0;
	float Temp = 0;
	FVector U = FVector(0, 0, 0);
	FVector V = FVector(0, 0, 0);
	if (!_bEnabled)
	{
		return 0;
	}
	toloc = GetLocation();
	if (fromactor != nullptr)
	{
		fromloc = fromactor->GetActorLocation();
	}
	else
	{
		fromloc = fromlocation;
	}
	U.X = 1;
	V.X = (toloc.X - fromloc.X);
	V.Y = (toloc.Y - fromloc.Y);
	/*
	Result = (V Dot U);
	Temp = VSize(V);
	if (Temp != 0)
	{
		(Result /= Temp);
	}
	Result = Acos(Result);
	Result = ((Result * 180) / 3.141593);
	if (V.Y < 0)
	{
		Result = (-Result);
	}
	*/
	return Result;
}

UMaterialInstance* UUIHUDCompassPoint::GetTexture()
{
	if (_bEnabled)
	{
		return _CompassIcon;
	}
	else
	{
		return nullptr;
	}
}

float UUIHUDCompassPoint::CompareHeight(AActor* fromactor, FVector fromlocation)
{
	float fromZ = 0;
	float toZ = 0;
	if (!_bEnabled)
	{
		return 0;
	}
	toZ = GetLocation().Z;
	if (fromactor != nullptr)
	{
		fromZ = fromactor->GetActorLocation().Z;
	}
	else
	{
		fromZ = fromlocation.Z;
	}
	return (toZ - fromZ);
}
