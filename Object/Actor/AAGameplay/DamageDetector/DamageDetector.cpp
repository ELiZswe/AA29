// All the original content belonged to the US Army

#include "AA29/Object/Actor/AAGameplay/DamageDetector/DamageDetector.h"

ADamageDetector::ADamageDetector()
{
	//DrawType = 1;
	//bUseDynamicLights = false;
	//bAcceptsProjectors = false;
	//bAcceptsNoLargeProjectors = false;
	//bUnlit = true;
	//bShadowCast = false;
	//CollisionRadius = 32;
	//CollisionHeight = 32;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bBlockPlayers = false;
	//bBlockCoronaTraces = false;
	//bDirectional = false;
}

/*
void ADamageDetector::TakeDamage(int32 Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 8, Level.GetClientPawn(), "DAMAGE," $ Damage $ "," $ DamageType);
	}
}
*/

bool ADamageDetector::ActorNotify(AActor* NotifyActory, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	if (EventLab != nullptr)
	{
		//return EventLab.ActorNotify(this, 8, Level.GetClientPawn(), Parms);
	}
	*/
	return false;    //FAKE  /ELiZ
}
