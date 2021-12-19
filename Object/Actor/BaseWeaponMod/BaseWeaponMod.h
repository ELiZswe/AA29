// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "GameFramework/Actor.h"
#include "BaseWeaponMod.generated.h"

class AAGP_Weapon;
class ABaseModAttachment;

UCLASS()
class ABaseWeaponMod : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeaponMod();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)	    USkeletalMesh* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool bCanSwapLense;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool bUseModZoomOffset;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool bSupportMod;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool bSuppressorMod;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool bOnlyDrawIfAttached;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float mFov;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8 ValidSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 ModScopeTexSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 FillExtraSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 ModSlot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString modname;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TArray<TSubclassOf<ABaseWeaponMod>> ExclusiveModsList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class ABaseWeaponMod>  EnemyModClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class ABaseWeaponMod>  NextWeaponMod;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FName WeaponBone;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* ModImageOverlay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* ModImage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* ScriptedLensTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		UTexture2D* StandardLensTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FVector mZoomAnimOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)     TSubclassOf<class ABaseScope> ScopeClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		AAGP_Weapon* weap;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		ESuppressorState SuppressorState;
	
	//From Actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		EDrawType DrawType;

	//remaining:
	//	var() ScriptedTexture ModScopeScriptedTexture;
	   	  
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PostNetBeginPlay();
	FString GetActorLevelSkin(int32 Index, UTexture2D* old_material, FString level_tag);
	ABaseModAttachment* GetModAttachment();
	FString GetModName();
	bool IsSuppressorReady();
	bool IsReplicationComplete();
	void NotifyReplicationComplete();
	virtual void Destroyed();
	virtual bool MutuallyExclusive(ABaseWeaponMod* OtherMod);
	bool ModNotAllowed();
	bool CanAttachToWeapon();
	FName GetAttachBone(int32 Slot);
	bool AttachToWeapon(AAGP_Weapon* W, int32 attach_slot);
	virtual void Toggle();
	bool IsSuppressor();
	void SetSuppressor();
	void NotifyWeaponAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop);
	virtual void NotifyWeaponZoom(bool bNewZoom);
	virtual void ModifyWeapon();
	void Setup3dScope();
	virtual void SetupScope();
	void SetupSupport();
	void SetupSuppressor();
	//void Tick float DeltaTime);
	void IncrementCounter();
	//void RenderTexture(ScriptedTexture Tex);
};
