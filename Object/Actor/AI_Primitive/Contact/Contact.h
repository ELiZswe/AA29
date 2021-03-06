// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "Contact.generated.h"

class AAI_Stats;
class AMentalModel;
class AAGP_Pawn;

UCLASS()
class AContact : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AContact();

	UPROPERTY()			float			lastPerc;				//var float lastPerc;
	UPROPERTY()			bool			perfect;				//var bool perfect;
	UPROPERTY()			float			dynamicIL;				//var float dynamicIL;
	UPROPERTY()			float			staticIL;				//var float staticIL;
	UPROPERTY()			AAI_Stats*		Target;					//var AI_Stats Target;
	UPROPERTY()			AMentalModel*	mm;						//var MentalModel mm;

	void BeginPlay();
	bool setMM(AMentalModel* pmm);
	bool checkMyActor(AActor* contactTarget);
	uint8 queryEnum(FString statName, int32& noInfo);
	FVector queryVector(FString statName, int32& noInfo);
	float queryFloat(FString statName, int32& noInfo);
	float rangeToTarget(FVector myPosit);
	float lineOfSightToMe(APawn* me, bool alt, FVector altLoc);
	float lineOfSightToHim(APawn* me, bool alt, FVector altLoc);
	float lineOfFireToMe(APawn* me, bool alt, FVector altLoc);
	float lineOfFireToHim(APawn* me, bool alt, FVector altLoc);
	bool update(FString Type, APawn* perceiver, float Intensity);
	float threatAssessment(APawn* me, FString situation, FVector altLoc, float& cover);
	float vulnerability(APawn* Threat, FString situation, FVector altLoc);
	AAGP_Pawn* getPawn();
	bool isInvisible();
	int32 isMyFriend(AAGP_Pawn* me);
	void Timer();
};
