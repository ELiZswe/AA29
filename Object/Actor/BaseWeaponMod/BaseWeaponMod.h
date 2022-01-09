// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "GameFramework/Actor.h"
#include "BaseWeaponMod.generated.h"

class AAGP_Weapon;
class ABaseModAttachment;
class ABaseScope;

UCLASS()
class ABaseWeaponMod : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABaseWeaponMod();
	
	UPROPERTY()					ABaseWeaponMod*							NextWeaponMod;				//var ABaseWeaponMod* NextWeaponMod;
	UPROPERTY()					AAGP_Weapon*							weap;						//var AAGP_Weapon* weap;
	UPROPERTY()					FName									WeaponBone;					//var FName WeaponBone;
	UPROPERTY()					int32									ModSlot;					//var int32 ModSlot;
	UPROPERTY()					int32									FillExtraSlot;				//var int32 FillExtraSlot;
	UPROPERTY()					TSubclassOf<ABaseScope>						ScopeClass;					//var class<BaseScope> ScopeClass;
	UPROPERTY()					bool									bSupportMod;				//var bool bSupportMod;
	UPROPERTY()					UMaterialInstance*						ModImage;					//var UMaterial* ModImage;
	UPROPERTY()					UMaterialInstance*						ModImageOverlay;			//var UMaterial* ModImageOverlay;
	UPROPERTY()					bool									bSuppressorMod;				//var bool bSuppressorMod;
	UPROPERTY()					TArray<TSubclassOf<ABaseWeaponMod>>		ExclusiveModsList;			//var TArray<class<BaseWeaponMod> > ExclusiveModsList;
	UPROPERTY()					TArray<uint8>							ValidSlot;					//var uint8 ValidSlot[6];
	UPROPERTY()					TSubclassOf<ABaseWeaponMod>				EnemyModClass;				//var class<BaseWeaponMod> EnemyModClass;
	UPROPERTY()					FString									modname;					//var FString modname;
	UPROPERTY(EditAnywhere)	    UMaterialInstance*						ModScopeScriptedTexture;	//var() UScriptedTexture* ModScopeScriptedTexture;
	UPROPERTY(EditAnywhere)	    float									mFov;						//var() float mFov;
	UPROPERTY(EditAnywhere)	    TArray<int32>							ModScopeTexSize;			//var() int32 ModScopeTexSize[4];
	UPROPERTY(EditAnywhere)	    FVector									mZoomAnimOffset;			//var() Vector mZoomAnimOffset;
	UPROPERTY(EditAnywhere)	    bool									bUseModZoomOffset;			//var() bool bUseModZoomOffset;
	UPROPERTY(EditAnywhere)	    bool									bCanSwapLense;				//var() bool bCanSwapLense;
	UPROPERTY(EditAnywhere)	    UMaterialInstance*						StandardLensTexture;		//var() UMaterial* StandardLensTexture;
	UPROPERTY(EditAnywhere)	    UMaterialInstance*						ScriptedLensTexture;		//var() UMaterial* ScriptedLensTexture;

	//From Actor
	UPROPERTY(EditAnywhere)		ESuppressorState	SuppressorState;
	UPROPERTY(EditAnywhere)		EDrawType			DrawType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)		bool				bOnlyDrawIfAttached;
	UPROPERTY()										USkeletalMesh*		Mesh;
	UPROPERTY()										FName				AttachmentBone;						//var const FName AttachmentBone;

	//remaining:
	//	var() ScriptedTexture ModScopeScriptedTexture;
	   	  
protected:
	
	virtual void BeginPlay() override;

public:	
	
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
