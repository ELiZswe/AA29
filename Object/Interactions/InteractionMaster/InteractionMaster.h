// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Interactions/Interactions.h"
#include "InteractionMaster.generated.h"

class UInteraction;

UCLASS()
class UInteractionMaster : public UInteractions
{
	GENERATED_BODY()
public:
	UInteractionMaster();

	// UPROPERTY()				FClient					Client;							//var transient Client* Client;
	UPROPERTY()				UInteraction*			BaseMenu;						//var const transient UInteraction* BaseMenu;
	UPROPERTY()				UInteraction*			Console;						//var const transient UInteraction* Console;
	UPROPERTY()				TArray<UInteraction*>	GlobalInteractions;				//var transient TArray<Interaction> GlobalInteractions;
	UPROPERTY()				bool					bRequireRawJoystick;			//var transient bool bRequireRawJoystick;

	void Travel(FString URL);
	UInteraction* AddInteraction(FString InteractionName, UPlayer* AttachTo);
	void RemoveInteraction(UInteraction* RemoveMe);
	void SetFocusTo(UInteraction* Inter, UPlayer* ViewportOwner);
	bool Process_KeyType(TArray<UInteraction*> InteractionArray, EInputKey& Key, FString Unicode);
	bool Process_KeyEvent(TArray<UInteraction*> InteractionArray, EInputKey& Key, EInputAction& Action, float Delta);
	void Process_PreRender(TArray<UInteraction*> InteractionArray, UCanvas* Canvas);
	void Process_PostRender(TArray<UInteraction*> InteractionArray, UCanvas* Canvas);
	void Process_Tick(TArray<UInteraction*> InteractionArray, float DeltaTime);
	void Process_Message(FString Msg, float MsgLife, TArray<UInteraction*> InteractionArray);
	void NotifyLevelChange(TArray<UInteraction*> InteractionArray);
	void NotifyInteractions(UInteraction* Changed, bool bOpen);
	void NotifyDemoCompleted(TArray<UInteraction*> InteractionArray);
};
