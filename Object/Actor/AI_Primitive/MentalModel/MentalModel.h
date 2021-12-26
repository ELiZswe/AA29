// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "MentalModel.generated.h"

class AContact;
class AAI_Stats;
class AAGP_Pawn;
class APickup;

UCLASS()
class AMentalModel : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AMentalModel();

	UPROPERTY()			bool StartUp;					//var bool StartUp;
	UPROPERTY()			float Tension;					//var float Tension;
	UPROPERTY()			int32 numContacts;				//var int numContacts;
	UPROPERTY()			AContact* allContacts;			//var Contact allContacts;

	void PostBeginPlay();
	void Timer();
	int32 getNumContacts();
	int32 getNumFriends(AAGP_Pawn* this_pawn);
	int32 getNumEnemies(AAGP_Pawn* this_pawn);
	void logDump();
	int32 findActorIdx(AActor* findThis);
	AContact* findContact(AActor* findThis);
	float getBestPickup(APawn* me, APickup* &out_pickup);
	AContact* getBiggestThreat(APawn* me, FString situation, FVector altLoc);
	float totalThreatAssessment(APawn* me, FString situation, FVector altLoc, float& cover);
	float attackAssessment(APawn* me, FString situation, FVector altLoc);
	AContact* getMostVulnerable(APawn* me, float& vuln, FString situation, FVector altLoc);
	AContact* addContact(AAI_Stats* contactInfo, float staticInfo, float dynInfo);
	AContact* removeContact(AActor* Contact);
	void receiveInfo(AActor* Source, FString recptType, APawn* Receiver, float Intensity);
	float getTension();
	void membersForceReweight();
};
