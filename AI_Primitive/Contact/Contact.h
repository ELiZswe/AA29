// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/AI_Primitive.h"
#include "Contact.generated.h"

/**
 * 
 */
class AAI_Stats;
class AMentalModel;
class AAGP_Pawn;

UCLASS()
class AA29_API AContact : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AContact();

	UPROPERTY()														float lastPerc;							//var float lastPerc;
	UPROPERTY()														bool perfect;							//var bool perfect;
	UPROPERTY()														float dynamicIL;						//var float dynamicIL;
	UPROPERTY()														float staticIL;							//var float staticIL;
	UPROPERTY()														AAI_Stats* Target;						//var AI_Stats Target;
	UPROPERTY()														AMentalModel* mm;						//var MentalModel mm;

	void BeginPlay();
	bool setMM(AMentalModel* pmm);
	void checkMyActor(AActor* contactTarget);
	void queryEnum(FString statName, int32& noInfo);
	void queryVector(FString statName, int32& noInfo);
	void queryFloat(FString statName, int32& noInfo);
	void rangeToTarget(FVector myPosit);
	void lineOfSightToMe(APawn* me, bool alt, FVector altLoc);
	void lineOfSightToHim(APawn* me, bool alt, FVector altLoc);
	void lineOfFireToMe(APawn* me, bool alt, FVector altLoc);
	void lineOfFireToHim(APawn* me, bool alt, FVector altLoc);
	void update(FString Type, APawn* perceiver, float Intensity);
	void threatAssessment(APawn* me, FString situation, FVector altLoc, float& cover);
	void vulnerability(APawn* Threat, FString situation, FVector altLoc);
	void getPawn();
	void isInvisible();
	void isMyFriend(AAGP_Pawn* me);
	void Timer();

};
