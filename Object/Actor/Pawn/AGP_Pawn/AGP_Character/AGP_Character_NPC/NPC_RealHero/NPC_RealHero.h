// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/AGP_Character_NPC.h"
#include "NPC_RealHero.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ANPC_RealHero : public AAGP_Character_NPC
{
	GENERATED_BODY()
public:
	ANPC_RealHero();



	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 MissionID;		//var int MissionID;
	//var AGP.RealHeroFadeInCylinder RHFIC;
	//var AGP.RealHeroAwarenessCylinder RHAC;
	//var AGP.RealHeroIcon RHI;

};
