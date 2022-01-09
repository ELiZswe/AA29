// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RealHeroIcon.generated.h"

UCLASS()
class ARealHeroIcon : public AActor
{
	GENERATED_BODY()

public:	
	
	ARealHeroIcon();

	UPROPERTY()										UMaterialInstance* RHShader;				//var Shader RHShader;
	UPROPERTY()										UMaterialInstance* alphaFader;				//var ConstantColor alphaFader;
	UPROPERTY()										uint8 maxAlpha;								//var uint8 maxAlpha;
	UPROPERTY()										uint8 minAlpha;								//var uint8 minAlpha;
	UPROPERTY()										uint8 desiredAlpha;							//var uint8 desiredAlpha;
	UPROPERTY()										float fadePerSecond;						//var float fadePerSecond;

	void PostBeginPlay();
	void Destroyed();
	void SetToMaxAlpha();
	void SetToMinAlpha();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
