// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/SniperRifle.h"

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

FRotator ASniperRifle::AdjustAim(bool bBreatheBonus)
{
	/*
	if (IsZoomed())
	{
		if (_Scope != None && _Scope.bUseAimAdjust)
		{
			return rot(0 0 0) + _Scope.GetAimAdjustment();
		}
		else
		{
			return rot(0 0 0);
		}
	}
	else
	{
		return AdjustAim(bBreatheBonus);
	}
	*/
	return FRotator(0, 0, 0);    //FAKE  /EliZ
}
