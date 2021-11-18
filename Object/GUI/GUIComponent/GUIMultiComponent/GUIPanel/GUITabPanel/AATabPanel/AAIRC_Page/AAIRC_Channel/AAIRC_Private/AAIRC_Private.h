// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAIRC_Page/AAIRC_Channel/AAIRC_Channel.h"
#include "AAIRC_Private.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAAIRC_Private : public UAAIRC_Channel
{
	GENERATED_BODY()
public:
	UAAIRC_Private();

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ProcessInput(FString Text);
	void PrivateText(FString Nick, FString Text);
	void PrivateAction(FString Nick, FString Text);
	void PrintAwayMessage(FString Nick, FString Message);
	int32 GetUser(FString Nick);
	bool FindNick(FString Nick);
	void AddUser(FString Nick);
	void RemoveUser(FString Nick);
	void ChangeNick(FString OldNick, FString NewNick);
	void ChangeOwner(FString Nick, bool NewOwner);
	void ChangeProtected(FString Nick, bool NewProtected);
	void ChangeOp(FString Nick, bool NewOp);
	void ChangeHalfOp(FString Nick, bool NewHalfOp);
	void ChangeVoice(FString Nick, bool NewVoice);
	bool ContextMenuOpen(UGUIContextMenu* Sender);
};
