// All the original content belonged to the US Army


#include "SniperRifle.h"

ASniperRifle::ASniperRifle()
{
	fpWeaponThreatLevel = 4;
}

void ASniperRifle::DoChangeFireMode()
{
}
void ASniperRifle::ChangeFireMode()
{
}
bool ASniperRifle::IsSniperRifle()
{
	return true;
}
bool ASniperRifle::ShouldDrawCrosshair()
{
	if (bDebugSights)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void ASniperRifle::AltFire(float Value)
{
	//PlayerController(Pawn(Owner).Controller).Zoom();
}
float ASniperRifle::GetSoundDampening()
{
	return 1.0f;
}
void ASniperRifle::AdjustAim(bool bBreatheBonus)
{
	/*
	if (IsZoomed())
	{
		if (_Scope != None && _Scope.bUseAimAdjust)
		{
			Return rot(0 0 0) + _Scope.GetAimAdjustment();
		}
		else
		{
			Return rot(0 0 0);
		}
	}
	else
	{
		Return AdjustAim(bBreatheBonus);
	}
	*/
}