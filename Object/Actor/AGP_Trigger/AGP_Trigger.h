// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/BillboardComponent.h"
#include "AGP_Trigger.generated.h"

UCLASS()
class AAGP_Trigger : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAGP_Trigger();


	UPROPERTY()							UTexture2D* Texture;
	UPROPERTY()							USceneComponent* Root;
	UPROPERTY(EditAnywhere)				UCapsuleComponent* Capsule;
	UPROPERTY()							UBillboardComponent* SpriteComponent;


	UPROPERTY()							bool bActive;							//var bool bActive;
	UPROPERTY()							int32 _TouchCounter;					//var int _TouchCounter;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()							void LoadEditorIcon();



	void SetActive(bool Active);
	void Touch(AActor* Other);
	void UnTouch(AActor* Other);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);


	UFUNCTION() void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION() void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
