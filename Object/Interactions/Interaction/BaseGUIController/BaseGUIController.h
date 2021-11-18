// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Interactions/Interaction/Interaction.h"
#include "BaseGUIController.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UBaseGUIController : public UInteraction
{
	GENERATED_BODY()
public:
	UBaseGUIController();

	UPROPERTY()											FString QuestionMenuClass;									//var config string QuestionMenuClass;
	UPROPERTY()											FString NetworkMsgMenu;										//var config string NetworkMsgMenu;
	UPROPERTY()											TArray<UMaterialInstance*> DefaultPens;						//var Material DefaultPens;

	void OnAdminReply(FString Reply);
	bool OpenMenu(FString NewMenuName, FString Param1, FString Param2);
	void AutoLoadMenus();
	bool ReplaceMenu(FString NewMenuName, FString Param1, FString Param2, bool bCancelled);
	bool CloseMenu(bool bCanceled);
	void CloseAll(bool bCancel, bool bForced);
	void SetControllerStatus(bool On);
	void InitializeController();
	bool NeedsMenuResolution();
	void SetRequiredGameResolution(FString GameRes);
	void NotifyDCDSDownload(FString AssetName);
	int32 GetMenuStackLength();
};
