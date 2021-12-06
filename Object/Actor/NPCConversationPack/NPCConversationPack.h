// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "NPCConversationPack.generated.h"

class APawn;
class ANPCBaseController;

UCLASS()
class AA29_API ANPCConversationPack : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)			FString					sConversationName;					//var() FString sConversationName;
	UPROPERTY(EditAnywhere)			TArray<FConvSpeech>		acsSpeechEntries;					//var() TArray<ConvSpeech> acsSpeechEntries;
	UPROPERTY(EditAnywhere)			bool					bUseLipSynch;						//var() bool bUseLipSynch;
	UPROPERTY(EditAnywhere)			float					Volume;								//var() float Volume;
	UPROPERTY(EditAnywhere)			float					Radius;								//var() float Radius;
	UPROPERTY(EditAnywhere)			float					Pitch;								//var() float Pitch;
	UPROPERTY(EditAnywhere)			bool					bLoopConversation;					//var() bool bLoopConversation;
	UPROPERTY(EditAnywhere)			float					fpMaxRangeBeforeTermination;		//var() float fpMaxRangeBeforeTermination;
	UPROPERTY(EditAnywhere)			bool					bConversationPackOwnedByNPC;		//var() bool bConversationPackOwnedByNPC;
	UPROPERTY()						TArray<APawn*>			apawnConversationMembers;			//var TArray<Pawn> apawnConversationMembers;
	UPROPERTY()						int32					iConvEntryIndex;					//var int32 iConvEntryIndex;
	UPROPERTY()						APawn*					pawnNPCTalking;						//var Pawn pawnNPCTalking;
	UPROPERTY()						float					fpSoundStart;						//var float fpSoundStart;
	UPROPERTY()						float					fpSoundDuration;					//var float fpSoundDuration;
	UPROPERTY()						ANPCBaseController*		npcbcConversationOwner;				//var NPCBaseController npcbcConversationOwner;

	void PostBeginPlay();
	void AttachPrimaryToTag();
	void StartConversation();
	void NPCStartConversation(ANPCBaseController* npcbc);
	bool IsPawnMemberOfConversation(APawn* pawnToCheck);
	bool IsPawnNameMemberOfConversation(FString sPawnName);
	void CachePawnsForConversationEntry();
	void AddPawnToMemberList(FString sTagNameOfPawnToAdd);
	APawn* FindCachedPawnByTagName(FString sTagName);
	void EndConversation();


public:	
	// Sets default values for this actor's properties
	ANPCConversationPack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
