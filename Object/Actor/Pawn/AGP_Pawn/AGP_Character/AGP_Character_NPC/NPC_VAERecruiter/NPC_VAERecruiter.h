// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_VAERecruiter.generated.h"

class ARealHeroIcon;
class ARealHeroAwarenessCylinder;
class ARealHeroFadeInCylinder;

UCLASS()
class ANPC_VAERecruiter : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_VAERecruiter();

	UPROPERTY()					ARealHeroIcon*					RHI;				//var ARealHeroIcon* RHI;
	UPROPERTY()					ARealHeroAwarenessCylinder*		RHAC;				//var ARealHeroAwarenessCylinder* RHAC;
	UPROPERTY()					ARealHeroFadeInCylinder*		RHFIC;				//var ARealHeroFadeInCylinder* RHFIC;
	UPROPERTY()					int32							MissionID;			//var int32 MissionID;

	void PostBeginPlay();
	//void PossessedBy(AController* C);
	void AnimEnd(int32 iChannel);
	void PlayWaiting();
	void AnimateRunning();
	void AnimateStanding();
	void PlayLanding();
};
