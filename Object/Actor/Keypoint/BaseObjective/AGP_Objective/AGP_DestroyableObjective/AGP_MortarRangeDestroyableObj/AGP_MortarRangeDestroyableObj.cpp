// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_DestroyableObjective/AGP_MortarRangeDestroyableObj/AGP_MortarRangeDestroyableObj.h"

AAGP_MortarRangeDestroyableObj::AAGP_MortarRangeDestroyableObj(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{

}
/*

void AAGP_MortarRangeDestroyableObj::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType*  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UTexture2D* HitMaterial)
{
	Log(Self + "." + Tag + " TakeDamage Enabled " + IsEnabled() + ", Health: " + Health + " Damage: " + Damage + " damage type: " + DamageType + " accepted: " + ShouldTakeDamage(DamageType) + " instigator: " + instigatedBy);
	if (Damage <= 0 || !IsEnabled())
	{
		return;
	}
	if (ShouldTakeDamage(DamageType))
	{
		AccumulatedDamage += Damage;
		if (AccumulatedDamage >= DamageEventThreshold)
		{
			if (EventLab != nullptr)
			{
				EventLab.MortarDamagedTarget(this, instigatedBy);
			}
			AccumulatedDamage = 0;
		}
		Health -= Damage;
		if (Health <= 0 && !bDestuctionReported)
		{
			bDestuctionReported = true;
			if (EventLab != nullptr)
			{
				EventLab.MortarDestroyedTarget(this, instigatedBy);
			}
			Log(Self + " Triggering destroyed event " + DestroyEvent + " instigated by " + instigatedBy);
		}
	}
}
*/
