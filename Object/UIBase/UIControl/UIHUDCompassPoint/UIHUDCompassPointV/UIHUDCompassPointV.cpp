// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDCompassPoint/UIHUDCompassPointV/UIHUDCompassPointV.h"

UUIHUDCompassPointV::UUIHUDCompassPointV()
{

}

void UUIHUDCompassPointV::setVector(FVector pTrack)
{
	_TrackingLocation.X = pTrack.X;
	_TrackingLocation.Y = pTrack.Y;
	_TrackingLocation.Z = pTrack.Z;
}
FVector UUIHUDCompassPointV::GetLocation()
{
	return _TrackingLocation;
}