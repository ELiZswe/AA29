// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "MessageTextureClient.generated.h"

UCLASS()
class AMessageTextureClient : public AAA2_Info
{
	GENERATED_BODY()
public:
	AMessageTextureClient();

	UPROPERTY(EditAnywhere)				UMaterialInstance*	MessageTexture;				//var() ScriptedTexture MessageTexture;
	UPROPERTY(EditAnywhere)				FString				ScrollingMessage;			//var() localized FString ScrollingMessage;
	UPROPERTY(EditAnywhere)				FString				HisMessage;					//var localized FString HisMessage;
	UPROPERTY(EditAnywhere)				FString				HerMessage;					//var localized FString HerMessage;
	UPROPERTY(EditAnywhere)				UFont*				Font;						//var() Font Font;
	UPROPERTY(EditAnywhere)				FColor				FontColor;					//var() Color FontColor;
	UPROPERTY(EditAnywhere)				bool				bCaps;						//var() bool bCaps;
	UPROPERTY(EditAnywhere)				FString				OldText;					//var FString OldText;

	void PostNetBeginPlay();
	void Timer();
	void RenderTexture(UMaterialInstance* Tex);
	FString Replace(FString Text, FString Match, FString Replacement);
};
