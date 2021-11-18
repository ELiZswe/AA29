// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyStructs.h"
#include "GameFramework/Actor.h"
#include "InventoryAttachment.generated.h"


class AInventory;
class USkeletalMesh;
class UMaterialInstance;


UCLASS()
class AA29_API AInventoryAttachment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryAttachment();

	UPROPERTY()					bool bDontSwapMeshes;													//var bool bDontSwapMeshes;
	UPROPERTY()					bool bFastAttachmentReplication;										//var bool bFastAttachmentReplication; // only replicates the subset of actor properties needed by basic attachments whose 
	UPROPERTY()					uint8 AnimState;														//var byte AnimState;
	UPROPERTY()					int32 inventoryattachment_dummy;										//var int inventoryattachment_dummy; // packing for hammer. disregard.  --ryan.
	UPROPERTY()					UStaticMesh* FriendlyStaticMesh;										//var StaticMesh	FriendlyStaticMesh;
	UPROPERTY()					UStaticMesh* EnemyStaticMesh;											//var StaticMesh	EnemyStaticMesh;
	UPROPERTY()					AInventoryAttachment* NextAttachment;									//var InventoryAttachment NextAttachment;
	UPROPERTY()					TSubclassOf<class AInventoryAttachment> EnemyAttachmentClass;			//var class<InventoryAttachment> EnemyAttachmentClass;
	UPROPERTY()					FName AttachmentBone;
	UPROPERTY()					UStaticMesh* StaticMesh;
	UPROPERTY()					USkeletalMesh* Mesh;
	UPROPERTY()					FVector RelativeLocation;
	UPROPERTY()					FRotator RelativeRotation;
	
	//from Actor
	UPROPERTY()					EDrawType DrawType;
	UPROPERTY()					float DrawScale;
	UPROPERTY()					FVector DrawScale3D;
	UPROPERTY()					bool bOrientOnSlope;
	UPROPERTY()					TArray<UMaterialInstance*> Skins;
	UPROPERTY()					AActor* Base;							//var const Actor Base;
protected:
	// Called when the game starts or when spawned


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void InitFor(AInventory* i);
	virtual void BeginPlay();
	virtual void GetAttachBoneFor(AInventory* Inv);
	virtual void GetMesh(bool bFriendly);
	virtual void GetStaticMesh(bool bFriendly);
	virtual void NotifyBaseChange();
	virtual void NotifyFoundClient();
	virtual float GetDrawScaleDecision(float PawnScale);
	virtual void SetMesh();
	virtual void NotifyNewMesh(bool bFriendly);
	virtual void AttachmentAnimation();
	//From Actor:
	virtual void SetDrawType(EDrawType NewDrawType);										//native final Function SetDrawType (EDrawType NewDrawType);
};
