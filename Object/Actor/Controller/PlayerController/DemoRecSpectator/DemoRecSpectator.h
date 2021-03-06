// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DemoRecSpectator.generated.h"

UCLASS()
class ADemoRecSpectator : public APlayerController
{
	GENERATED_BODY()
public:
	ADemoRecSpectator();

	UPROPERTY()		bool		bTempBehindView;			//var bool bTempBehindView;
	UPROPERTY()		bool		bFoundPlayer;				//var bool bFoundPlayer;
	UPROPERTY()		FString		RemoteViewTarget;			//var FString RemoteViewTarget;

	void PostBeginPlay();
	void InitPlayerReplicationInfo();
	void ViewClass(AActor* aClass, bool bQuiet, bool bCheat);
	void DemoViewNextPlayer();
	void PlayerCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
};
