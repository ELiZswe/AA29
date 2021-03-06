// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "ShadowProjector.generated.h"

UCLASS()
class AShadowProjector : public AProjector
{
	GENERATED_BODY()
public:
	AShadowProjector();

	UPROPERTY(EditAnywhere)				AActor*				ShadowActor;		//var() Actor ShadowActor;
	UPROPERTY(EditAnywhere)				FVector				LightDirection;		//var() Vector LightDirection;
	UPROPERTY(EditAnywhere)				float				LightDistance;		//var() float LightDistance;
	UPROPERTY(EditAnywhere)				bool				RootMotion;			//var() bool RootMotion;
	UPROPERTY(EditAnywhere)				bool				bShadowActive;		//var() bool bShadowActive;
	UPROPERTY()							UMaterialInstance*	ShadowTexture;		//var ShadowBitmapMaterial ShadowTexture;

	void PostBeginPlay();
	void Destroyed();
	void InitShadow();
	void UpdateShadow();
	void Tick(float DeltaTime);
	void LightUpdate(TArray<AActor*> LightSources, TArray<float> LightRadii, TArray<FVector> LightDirections);
};
