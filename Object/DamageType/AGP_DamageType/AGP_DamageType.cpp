// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/AGP_DamageType.h"
#include "AA29/Object/Actor/Controller/Playercontroller/HumanController/HumanController.h"

UAGP_DamageType::UAGP_DamageType()
{

}

TArray<ASideEffect*> UAGP_DamageType::GetSideEffects(AController* Affected, int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor)
{
	int32 i = 0;
	AHumanController* HC = nullptr;
	TArray<ASideEffect*> ResultingSideEffects={};
	HC = Cast<AHumanController>(Affected);
	if (HC != nullptr)
	{
		/*
		for (i = 0; i < Default.SideEffects.Num(); i++)
		{
			ResultingSideEffects.insert(ResultingSideEffects.Num(), 1);
			ResultingSideEffects[ResultingSideEffects.Num() - 1] = Default.SideEffects[i];
		}
		*/
	}
	return ResultingSideEffects;
}
