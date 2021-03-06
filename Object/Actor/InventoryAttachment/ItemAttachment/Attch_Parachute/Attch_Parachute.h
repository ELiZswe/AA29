// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "Attch_Parachute.generated.h"

class AItemAttachment;

class AInventory;
UCLASS()
class AAttch_Parachute : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAttch_Parachute();

	UPROPERTY()		float						_ParachuteSoundUpdate;			//var float _ParachuteSoundUpdate;
	UPROPERTY()		USoundBase*					sParachuteOpenSound;			//var Sound sParachuteOpenSound;
	UPROPERTY()		USoundBase*					sParachuteFlutterSound;			//var Sound sParachuteFlutterSound;
	UPROPERTY()		USoundBase*					sParachuteCollapseSound;		//var Sound sParachuteCollapseSound;
	UPROPERTY()		FVector						fScaleDeploy;					//var FVector fScaleDeploy;
	UPROPERTY()		bool						bStartScaleDeploy;				//var bool bStartScaleDeploy;
	UPROPERTY()		TArray<AItemAttachment*>	ParaItems;						//var AItemAttachment* ParaItems[2];
	UPROPERTY()		uint8						PrevAnimState;					//var byte PrevAnimState;
	UPROPERTY()		bool						bNoInstigator;					//var bool bNoInstigator;

	void NotifyBaseChange();
	void SetMesh();
	UStaticMesh* GetStaticMesh(bool bFriendly);
	void PostNetBeginPlay();
	void Destroyed();
	void CreateClientSideParachuteAttachments();
	void HandleClientAttachments();
	void BeginPlay();
	FName GetAttachBoneFor(AInventory* Inv);
	void AttachmentAnimation();
	void NotifyNewParachuteState(int32 NewState);
	void PrepareCleanup();
	void CleanupParachute();
	void Timer();
	void AnimEnd(int32 Channel);
	void Tick(float DeltaTime);
	FString DisplayDebugMessage();
	void MatchEnding();
};
