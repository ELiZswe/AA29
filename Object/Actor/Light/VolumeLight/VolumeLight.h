// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Light/AA2_Light.h"
#include "AA29/AA29.h"
#include "VolumeLight.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AVolumeLight : public AAA2_Light
{
	GENERATED_BODY()
public:
	AVolumeLight();


	UPROPERTY()											FRotator LastRotation;					//var Object.Rotator LastRotation;
	UPROPERTY()											float InitialBrightness;				//var float InitialBrightness;
	//UPROPERTY()											bool bEnabled;							//var bool bEnabled;
	UPROPERTY()											FSprite SS;								//var array<Sprite> SS;
	UPROPERTY()											float WaitTime;							//var float WaitTime;
	UPROPERTY()											bool bFading;							//var bool bFading;
	UPROPERTY(EditAnywhere, Category = "Projector")		UMaterialInstance* ProjTexture;			//var(Projector) Texture ProjTexture;
	UPROPERTY(EditAnywhere, Category = "Projector")		bool bProjectBeamTexture;				//var(Projector) bool bProjectBeamTexture;
	UPROPERTY(EditAnywhere)								ERenderStyle SpriteStyle;				//var() Actor.ERenderStyle SpriteStyle;
	UPROPERTY(EditAnywhere)								UMaterialInstance* SpriteTexture;		//var() Texture SpriteTexture;
	UPROPERTY(EditAnywhere)								uint8 SpriteFadeEnd;					//var() byte SpriteFadeEnd;
	UPROPERTY(EditAnywhere)								uint8 SpriteFadeBegin;					//var() byte SpriteFadeBegin;
	UPROPERTY(EditAnywhere)								float MinFadeMultiplier;				//var() float MinFadeMultiplier;
	UPROPERTY(EditAnywhere)								float LightDistance;					//var() float LightDistance;
	UPROPERTY(EditAnywhere)								float SpriteScaleEnd;					//var() float SpriteScaleEnd;
	UPROPERTY(EditAnywhere)								float SpriteScaleBegin;					//var() float SpriteScaleBegin;
	UPROPERTY(EditAnywhere)								bool bActorsBlock;						//var() bool bActorsBlock;
	UPROPERTY(EditAnywhere)								bool bSpriteFade;						//var() bool bSpriteFade;
	UPROPERTY(EditAnywhere)								bool bSpriteDynamic;					//var() bool bSpriteDynamic;
	UPROPERTY(EditAnywhere)								bool bStartOn;							//var() bool bStartOn;
	UPROPERTY(EditAnywhere)								int32 SpriteNum;						//var() int SpriteNum;


	void PreBeginPlay();
	void GetNewLocation(float Rad);
	void BeginPlay();
	void Tick(float DeltaTime);
	void DoFade(FSprite SSprite, bool FadeOut);
	void SetFade(FSprite& SSprite, float Value);
	void Activate(bool bEnable);
	void Trigger(AActor* Other, APawn* EventInstigator);
};
