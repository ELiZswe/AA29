// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/ReplicationInfo/ReplicationInfo.h"
#include "PersonnelJacket.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APersonnelJacket : public AReplicationInfo
{
	GENERATED_BODY()
public:
	APersonnelJacket();

	UPROPERTY(Replicated)									bool bQualifiedES2;								//var bool bQualifiedES2;
	UPROPERTY(Replicated)									bool bQualifiedJavelin;							//var bool bQualifiedJavelin;
	UPROPERTY(Replicated)									bool bQualifiedSF;								//var bool bQualifiedSF;
	UPROPERTY(Replicated)									bool bQualifiedMedic;							//var bool bQualifiedMedic;
	UPROPERTY(Replicated)									bool bQualifiedRanger;							//var bool bQualifiedRanger;
	UPROPERTY(Replicated)									bool bQualifiedAirborne;						//var bool bQualifiedAirborne;
	UPROPERTY(Replicated)									bool bQualifiedSniper;							//var bool bQualifiedSniper;
	UPROPERTY(Replicated)									int32 Honor;									//var int Honor;
	UPROPERTY(Replicated)									int32 Experience;								//var int Experience;

	int32 GetExperience();
	int32 GetHonor();
	int32 CalculateHonor(int32 CurrentExperience);
	int32 CalculateExperience(int32 CurrentHonor);
	int32 CalculateExperienceNeeded(int32 CurrentExperience, int32 CurrentHonor);

};
