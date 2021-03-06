// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "CameraTextureClient.generated.h"

UCLASS()
class ACameraTextureClient : public AAA2_Info
{
	GENERATED_BODY()
public:
	ACameraTextureClient();

	UPROPERTY(EditAnywhere)		UMaterialInstance*	DestTexture;	//var() ScriptedTexture DestTexture;
	UPROPERTY(EditAnywhere)		FName				CameraTag;		//var() FName CameraTag;
	UPROPERTY(EditAnywhere)		float				RefreshRate;	//var() float RefreshRate;
	UPROPERTY(EditAnywhere)		float				FOV;			//var() float FOV;
	UPROPERTY()					AActor*				CameraActor;	//var Actor CameraActor;

	void PostBeginPlay();
	void Timer();
	//void RenderTexture(AScriptedTexture* Tex);
};
