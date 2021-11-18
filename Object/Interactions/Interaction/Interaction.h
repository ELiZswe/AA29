// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Interactions/Interactions.h"
#include "AA29/AA29.h"

#include "Interaction.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UInteraction : public UInteractions
{
	GENERATED_BODY()
public:
	UInteraction();

	//UPROPERTY()											FString Master;									//var InteractionMaster Master;
	//UPROPERTY()											UPlayer* ViewportOwner;									//var Player ViewportOwner;
	UPROPERTY()											bool bNativeEvents;									//var bool bNativeEvents;
	UPROPERTY()											bool bRequiresTick;									//var bool bRequiresTick;
	UPROPERTY()											bool bVisible;									//var bool bVisible;
	UPROPERTY()											bool bActive;									//var bool bActive;



	void Initialize();
	void ConsoleCommand(FString S);
	void WorldToScreen(FVector Location, FVector CameraLocation, FRotator CameraRotation);
	void ScreenToWorld(FVector Location, FVector CameraLocation, FRotator CameraRotation);
	void Initialized();
	void NotifyLevelChange();
	void Message(FString Msg, float MsgLife, FColor Color);
	bool KeyType(EInputKey &Key, FString Unicode);
	bool KeyEvent(EInputKey &Key, EInputAction &Action, float Delta);
	void PreRender(UCanvas* Canvas);
	void PostRender(UCanvas* Canvas);
	void SetFocus();
	void Tick(float DeltaTime);
	void StreamFinished(int32 Handle, EStreamFinishReason Reason);
	void NotifyMusicChange();
	void NotifyDemoCompleted();
	void InteractionChanged(UInteraction* Changed, bool bOpen);

};
