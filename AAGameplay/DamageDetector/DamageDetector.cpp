// All the original content belonged to the US Army


#include "AA29/AAGameplay/DamageDetector/DamageDetector.h"

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
	//bCollideWorld = False;
	//bBlockActors = false;
	//bBlockPlayers = false;
	//bBlockCoronaTraces = false;
	//bDirectional = false;
}

/*
void ADamageDetector::TakeDamage(int Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial)
{
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 8, Level.GetClientPawn(), "DAMAGE," $ Damage $ "," $ DamageType);
	}
}
*/
void ADamageDetector::ActorNotify(AActor* NotifyActory, EEventType Event, AActor* aInstigator, FString Parms)
{
	/*
	if (EventLab != nullptr)
	{
		//Return EventLab.ActorNotify(Self, 8, Level.GetClientPawn(), Parms);
	}
	*/
}