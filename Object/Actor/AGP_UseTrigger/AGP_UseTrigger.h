// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/BillboardComponent.h"
#include "AGP_UseTrigger.generated.h"

UCLASS()
class AAGP_UseTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_UseTrigger();


	UPROPERTY()														FString TempHUDText;		//var string TempHUDText;
	UPROPERTY(EditAnywhere)											bool bDisabled;				//var() bool bDisabled;
	UPROPERTY(EditAnywhere, Category = "SwappablePosters")			bool bSwappablePoster;		//var(SwappablePosters) bool bSwappablePoster;
	UPROPERTY(EditAnywhere, Category = "SwappablePosters")			FString sSwapName;			//var(SwappablePosters) string sSwapName;
	UPROPERTY(EditAnywhere)											bool bActive;				//var() bool bActive;
	UPROPERTY(EditAnywhere)											int32 ResetTime;			//var() int ResetTime;
	UPROPERTY(EditAnywhere)											USoundBase* UseSound;		//var() Sound UseSound;
	UPROPERTY(EditAnywhere)											bool bSwitched;				//var() bool bSwitched;
	UPROPERTY(EditAnywhere)											FString HUDText;			//Mine   ELiZ.. from actor

	UPROPERTY()							UTexture2D* Texture;
	UPROPERTY()							USceneComponent* Root;
	UPROPERTY(EditAnywhere)				UCapsuleComponent* Capsule;
	UPROPERTY()							UBillboardComponent* SpriteComponent;
	UPROPERTY(EditAnywhere)				UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere)				TArray<UMaterialInstance*> OverrideMaterials;

	bool IsSwitched();
	bool IsActive();
	void SetActive(bool Active);
	void SetHUDText(FString NewText);
	void BeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	bool UsedBy(APawn* User);
	void Timer();

protected:
	

	UFUNCTION()							void LoadEditorIcon();
	UFUNCTION()							void LoadMesh();
public:	
	
	virtual void Tick(float DeltaTime) override;

};
