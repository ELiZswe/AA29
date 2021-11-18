// All the original content belonged to the US Army


#include "AA29/Object/Interactions/Interaction/BaseGUIController/BaseGUIController.h"

UBaseGUIController::UBaseGUIController()
{

	DefaultPens = {
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuBlack_Mat.MenuBlack_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuGray_Mat.MenuGray_Mat'"), NULL, LOAD_None, NULL)
	};

	bActive = false;
	bNativeEvents = true;
}

void UBaseGUIController::OnAdminReply(FString Reply)
{
}
bool UBaseGUIController::OpenMenu(FString NewMenuName, FString Param1, FString Param2)
{
	return false;
}
void UBaseGUIController::AutoLoadMenus()
{
}
bool UBaseGUIController::ReplaceMenu(FString NewMenuName, FString Param1, FString Param2, bool bCancelled)
{
	return false;
}
bool UBaseGUIController::CloseMenu(bool bCanceled)
{
	return true;
}
void UBaseGUIController::CloseAll(bool bCancel, bool bForced)
{
}
void UBaseGUIController::SetControllerStatus(bool On)
{
	bActive = On;
	bVisible = On;
	bRequiresTick = On;
}
void UBaseGUIController::InitializeController()
{
}
bool UBaseGUIController::NeedsMenuResolution()
{
	return false;   //Mine /ELiZ
}
void UBaseGUIController::SetRequiredGameResolution(FString GameRes)
{
}
void UBaseGUIController::NotifyDCDSDownload(FString AssetName)
{
}
int32 UBaseGUIController::GetMenuStackLength()
{
	return 0;
}