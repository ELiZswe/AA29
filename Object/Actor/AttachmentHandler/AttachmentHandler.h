// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttachmentHandler.generated.h"

class ABaseModAttachment;
class AInventory;

UCLASS()
class AAttachmentHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAttachmentHandler();

	UPROPERTY()										bool bSpinnyEnemy;							//var bool bSpinnyEnemy;
	UPROPERTY()										bool bSpinny;								//var bool bSpinny;
	UPROPERTY()										UStaticMesh* DefaultWeaponMesh;				//var Mesh DefaultWeaponMesh;
	UPROPERTY()										FString special_skin_tag;					//var string special_skin_tag;
	UPROPERTY()										uint8 AnimState;							//var byte AnimState;
	UPROPERTY()										AActor* AttachProxy;						//var Actor AttachProxy;
	UPROPERTY()										ABaseModAttachment* ModAttachmentList;		//var BaseModAttachment ModAttachmentList;
	UPROPERTY()										ABaseModAttachment* WM_Attachment;			//var class<BaseModAttachment> WM_Attachment;
	UPROPERTY()										int32 num_mods;								//var int num_mods;

	void NotifyReplicationComplete();
	bool IsReplicationComplete();
	void SetupHandler(AActor* newproxy, AActor* AttachTo, AInventory* i);
	void SetSlotDraw(int32 Slot, bool bDraw);
	void LoadModAttachment(ABaseModAttachment* BMA, int32 Slot);
	void CopyModsFrom(AInventory* i);
	void CountModAttachments();
	bool IsEnemy();
	bool InvalidAttachProxy();
	void SpawnModAttachments();
	ABaseModAttachment* SpawnSingleAttachment(int32 Slot, bool bIsEnemy);
	void SetSpecialSkinTag(FString skin_tag);
	void SetDefaultWeaponMesh(UStaticMesh* NewDefaultWeaponMesh);
	void SetWeaponMesh(UStaticMesh* NewWeaponMesh);
	void NotifyModAttachmentAnimation(uint8 NewAnimState);
	void AddModAttachment(ABaseModAttachment* MA);
	void Destroyed();
	void ClearModAttachments();
	void SetFriendly(bool bFriendly);

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;
};
