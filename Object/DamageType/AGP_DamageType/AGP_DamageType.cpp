// All the original content belonged to the US Army


#include "AGP_DamageType.h"

UAGP_DamageType::UAGP_DamageType()
{

}


void UAGP_DamageType::GetSideEffects(AController* Affected, int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor)
{
	/*
	local int i;
	local HumanController HC;
	local array<class<SideEffect> > ResultingSideEffects;
	HC = HumanController(Affected);
	if (HC != None)
	{
		for (i = 0; i < Default.SideEffects.Length; i++)
		{
			ResultingSideEffects.insert(ResultingSideEffects.Length, 1);
			ResultingSideEffects[ResultingSideEffects.Length - 1] = Default.SideEffects[i];
		}
	}
	Return ResultingSideEffects;
	*/
}