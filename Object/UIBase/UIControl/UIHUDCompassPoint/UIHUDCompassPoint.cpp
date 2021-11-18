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
	//return IsEnabled();
	return false;    //FAKE   /EliZ
}
FVector UUIHUDCompassPoint::GetLocation()
{
	FVector V = FVector( 0,0,0 );
	
	/*
	if (_TrackingActor != None)
	{
		return _TrackingActor.Location;
	}
	else
	{
		return V;
	}
	*/
	return V;    //FAKE   /ELiZ
}
float UUIHUDCompassPoint::GetRotation(AActor* fromactor, FVector fromlocation)
{
	float Result=0;
	/*
	local Object.Vector fromloc;
	local Object.Vector toloc;
	local float Temp;
	local Object.Vector U;
	local Object.Vector V;
	if (!_bEnabled)
	{
		Return 0;
	}
	toloc = GetLocation();
	if (fromactor != None)
	{
		fromloc = fromactor.Location;
	}
	else
	{
		fromloc = fromlocation;
	}
	U.X = 1;
	V.X = toloc.X - fromloc.X;
	V.Y = toloc.Y - fromloc.Y;
	Result = V Dot U;
	Temp = VSize(V);
	if (Temp != 0)
	{
		Result /= Temp;
	}
	Result = Acos(Result);
	Result = Result * 180 / 3.141593;
	if (V.Y < 0)
	{
		Result = -Result;
	}
	*/
	return Result;
}
UMaterialInstance* UUIHUDCompassPoint::GetTexture()
{
	/*
	if (_bEnabled)
	{
		return _CompassIcon;
	}
	else
	{
		return nullptr;
	}
	*/
	return nullptr;     //FAKE   /ELiZ
}
void UUIHUDCompassPoint::CompareHeight(AActor* fromactor, FVector fromlocation)
{
	/*
	local float fromZ;
	local float toZ;
	if (!_bEnabled)
	{
		Return 0;
	}
	toZ = GetLocation().Z;
	if (fromactor != None)
	{
		fromZ = fromactor.Location.Z;
	}
	else
	{
		fromZ = fromlocation.Z;
	}
	Return toZ - fromZ;
	*/
}