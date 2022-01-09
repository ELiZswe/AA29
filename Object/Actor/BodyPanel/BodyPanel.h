// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "BodyPanel.generated.h"

class AVehicle;

UCLASS()
class ABodyPanel : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABodyPanel();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;


	UPROPERTY()					FString PassengerHintText;						//var string PassengerHintText;
	UPROPERTY()					FString ExteriorHintText;						//var string ExteriorHintText;
	UPROPERTY()					TArray<ABodyPanel*> LinkedPanels;				//var array<BodyPanel> LinkedPanels;
	UPROPERTY()					int32 LastDamageIndex;							//var int LastDamageIndex;
	UPROPERTY()					int32 DamageIndex;								//var int DamageIndex;
	UPROPERTY()					TArray<UStaticMesh*> DamagedMesh;				//var array<StaticMesh> DamagedMesh;
	UPROPERTY()					TArray<UTexture2D*> DamagedTexture;				//var array<Texture> DamagedTexture;
	UPROPERTY()					TArray<int32> ProjectileDamageThreshholds;		//var array<int> ProjectileDamageThreshholds;
	UPROPERTY()					TArray<int32> CollisionDamageThreshholds;		//var array<int> CollisionDamageThreshholds;
	UPROPERTY()					TArray<int32> ExplosionDamageThreshholds;		//var array<int> ExplosionDamageThreshholds;
	UPROPERTY()					int32 ProjectileDamage;							//var int ProjectileDamage;
	UPROPERTY()					int32 CollisionDamage;							//var int CollisionDamage;
	UPROPERTY()					int32 ExplosionDamage;							//var int ExplosionDamage;
	UPROPERTY()					bool bIsDestroyed;								//var bool bIsDestroyed;
	UPROPERTY()					bool bAcceptsProjectileDamage;					//var bool bAcceptsProjectileDamage;
	UPROPERTY()					bool bInvincible;								//var bool bInvincible;
	UPROPERTY()					int32 PanelID;									//var int PanelID;
	UPROPERTY()					FRotator RelRotation;							//var Object.Rotator RelRotation;
	UPROPERTY()					AVehicle* EntryVehicle;							//var Vehicle EntryVehicle;
	UPROPERTY()					bool bDoHighlight;								//var bool bDoHighlight;
	UPROPERTY()					float EntryRadius;								//var float EntryRadius;
	UPROPERTY()					FName EntryBone;								//var name EntryBone;


	void PostBeginPlay();
	void PostNetBeginPlay();
	AVehicle* FindEntryVehicle(APawn* p);
	void AddLinkedPanel(ABodyPanel* PanelToLink);
	bool UsedBy(APawn* User);
	//void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance HitMaterial);
	void HandleDamage(int32 Damage, eBodyPanelDamageType BPDT);
	void PostNetReceive();
	void RefreshDamageState();
	void SwapTexture(UMaterialInstance* NewTexture);


};
