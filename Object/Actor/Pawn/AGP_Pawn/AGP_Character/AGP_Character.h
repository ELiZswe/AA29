// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "Camera/CameraComponent.h"

#include "AGP_Character.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_Character : public AAGP_Pawn
{
	GENERATED_BODY()
public:

	AAGP_Character();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))					class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY()																bool bInventorySet;								//var bool bInventorySet;
	UPROPERTY()																bool bAlreadySetSkinsOnce;						//var bool bAlreadySetSkinsOnce;
	UPROPERTY()																ESkinColor SkinColor;							//var ESkinColor SkinColor;
	UPROPERTY()																int32 CurrentDir;								//var Actor.EDoubleClickDir CurrentDir;
	UPROPERTY()																uint8 LoadOut;									//var byte LoadOut;
	UPROPERTY()																bool bUseMedicAttachments;						//var bool bUseMedicAttachments;
	UPROPERTY()																bool bUseSniperAttachments;						//var bool bUseSniperAttachments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								TArray<FString> ClientSideMedicAttachments;		//var() string ClientSideMedicAttachments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								TArray<FString> ClientSideSniperAttachments;	//var() string ClientSideSniperAttachments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								TArray<FString> ClientSideAttachments;			//var() array<String> ClientSideAttachments;
	UPROPERTY(Config)														TArray<uint8> SelectedEquipment;				//var config byte SelectedEquipment;				// what player has selected (replicate using function)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								TArray<AInventory*> OptionalInventory;			//var() class<Inventory> OptionalInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)								TArray<AInventory*> RequiredInventory;			//var() class<Inventory> RequiredInventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")		bool bStaticSkinsAndMeshes;						//var(Display) bool bStaticSkinsAndMeshes;
	//UPROPERTY()															ATeamInfo* DeadBodyFormerTeam;					//var TeamInfo DeadBodyFormerTeam;
	UPROPERTY()																bool bWasTurningLeft;							//var bool bWasTurningLeft;

	//virtual void LoadMesh();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;



	//imported
	virtual void SetStaticSkinsAndMeshes(bool bEnable);
	virtual void PlayFootStep();
	virtual void DebugDropObjective();
	virtual void ServerDropObjective();
	virtual void FootStepping();
	virtual void PlayLadderFootStep();
	virtual void CheckLanding();
	virtual void PlayFalling();
	virtual void PlayJump();
	virtual void PlayLanded(float impactVel);
	virtual void PlayLandingAnimation(float impactVel);
	virtual void StopPlayFiring();
	virtual void PlayWaiting();
	virtual void PlayMoving();
	virtual void SetRates(float Rate);
	virtual void SetRates4(float R0, float r1, float r2, float R3);
	virtual void SetAnimRates();
	virtual void AnimateDead();
	virtual void AnimatePistolMoving();
	virtual void AnimateRPGMoving();
	virtual void AnimateAT4Moving();
	virtual void AnimateTubeMoving();
	virtual void AnimateGrenadeMoving();
	virtual void AnimateBinocularsMoving();
	virtual void AnimateCLUMoving();
	virtual void AnimateRunning();
	virtual void AnimateSprinting();
	virtual void AnimateParachuting();
	virtual void AnimateCrouchWalking();
	virtual void AnimateProneWalking();
	virtual void AnimateWalking();
	virtual void AnimateClimbing();
	virtual void AnimateStoppedOnLadder();
	virtual void AnimateStanding();
	virtual void AnimateCrouching();
	virtual void AnimateProneing();
	virtual void PlayProningSound();
	virtual void PossessedBy(AController* C) override;
	virtual void Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone);
	virtual void PlayDying(UaDamageType* DamageType, FVector HitLoc, FVector HitDir, FBoneInfo Bone);
	virtual bool UseParachuteDeath();
	virtual void UseMILESDeath(UaDamageType* DamageType);
	virtual bool UseGuerrillaGroup(bool bFriendly);
	virtual FString GetFaceGroup(bool bFriendly);
	virtual FString GetSkinGroup(bool bFriendly);
	virtual FString GetSkinOption(bool bFriendly);
	virtual void LoadSkinsAndMeshes();
	virtual void RemoveParachuteSkins();
	virtual bool MaybeGetSpecialFace(bool bFriend);
	virtual FString ThisOrThat(FString sthis, FString sthat, float ratio);
	virtual FString ThisOrThatOrThis(FString st1, FString st2, FString st3, float ratio1, float ratio2);
	virtual FString GetTag_Pants(bool bFriendly);
	virtual FString GetTag_PantsShirtOption(bool bFriendly);
	virtual FString GetTag_Shirt(bool bFriendly);
	virtual FString GetTag_ShirtOption(bool bFriendly);
	virtual FString GetTag_Hands(bool bFriendly);
	virtual FString GetTag_HandsOption(bool bFriendly);
	virtual FString GetTag_Face(bool bFriendly);
	virtual FString GetTag_FaceOption(bool bFriendly);
	virtual void SetSkinColor();
	virtual FString GetSkinColor();
	virtual USkeletalMesh* GetMesh(bool bFriendly);
	virtual USkeletalMesh* GetSoldierMesh();
	virtual USkeletalMesh* GetSFMesh();
	virtual USkeletalMesh* GetArcticMesh();
	virtual USkeletalMesh* GetSFArcticMesh();
	virtual EWeaponType GetMainWeaponType();
	virtual void SetSkinsAndMeshes();
	virtual void SetRagDollName();
	virtual void Destroyed();
	virtual void CreateClientSideAttachments();
	virtual void RegisterAttachment(AInventoryAttachment* att);
	virtual void NotifyFoundClient();
	virtual void IsInLoadout(AInventory* InventoryClass);
	virtual void AddDefaultInventory();
	virtual void CreateInventoryFromName(FString InventoryClassName, bool bIndigenous);
	virtual void CreateInventory(AInventory* InventoryClass, bool bRealInventory, bool bIndigenous);
	virtual void IsValidInventory(AInventory* InventoryClass, AInventory* out_AltClass);
	virtual void CreateVirtualInventory(AInventory* InventoryClass);
	virtual void UpdateEyeHeight(float DeltaTime);
	virtual FVector EyePosition();
	virtual void EyeRotation();
	virtual void DoAnimLoop();

	void SetPlayerMesh();


	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	UFUNCTION()		void OnStartJump();				//sets jump flag when key is pressed
	UFUNCTION()		void OnStopJump();				//clears jump flag when key is released
	UFUNCTION()		void ShowMenu();				//Show Menu

	
	
	UFUNCTION() void OnFire();
	
	UFUNCTION(Server, Reliable, WithValidation) void Server_OnFire();
	virtual void Server_OnFire_Implementation();
	

	UFUNCTION() void Client_SetPlayerMesh();
	UFUNCTION(NetMulticast, Reliable, WithValidation) void Server_SetPlayerMesh();
	virtual void Server_SetPlayerMesh_Implementation();

	void Interact();
	UFUNCTION(Server, Reliable, WithValidation) void Server_Interact();
	virtual void Server_Interact_Implementation();

	void Prone();
	UFUNCTION(Server, Reliable, WithValidation) void Server_Prone();
	virtual void Server_Prone_Implementation();

	void Crouch2();
	UFUNCTION(Server, Reliable, WithValidation) void Server_Crouch();
	void Server_Crouch_Implementation();


};
