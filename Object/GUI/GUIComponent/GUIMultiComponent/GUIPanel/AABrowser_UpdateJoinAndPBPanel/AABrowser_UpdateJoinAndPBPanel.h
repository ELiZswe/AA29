// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIPanel.h"
#include "AABrowser_UpdateJoinAndPBPanel.generated.h"

class UGUIStyles;
class UGUIButton;
class UmoCheckBox;
class UGUIImage;

/**
 * 
 */
UCLASS()
class AA29_API UAABrowser_UpdateJoinAndPBPanel : public UGUIPanel
{
	GENERATED_BODY()
public:
	UAABrowser_UpdateJoinAndPBPanel();

	UPROPERTY()										FString						UpdateServerListEyeCatcherStyleName;			//var string UpdateServerListEyeCatcherStyleName;
	UPROPERTY()										UGUIStyles*					UpdateServerListOriginalStyle;					//var XInterface.GUIStyles UpdateServerListOriginalStyle;
	UPROPERTY(EditAnywhere, Category = "Style")		UGUIStyles*					UpdateServerListEyeCatcherStyle;				//var(Style) XInterface.GUIStyles UpdateServerListEyeCatcherStyle;
	UPROPERTY()										bool						HideBorder;										//var bool HideBorder;
	UPROPERTY(EditAnywhere)							UGUIButton*					JoinServer;										//var() XInterface.GUIButton JoinServer;
	UPROPERTY(EditAnywhere)							UGUIButton*					UpdateServerList;								//var() XInterface.GUIButton UpdateServerList;
	UPROPERTY(EditAnywhere)							UmoCheckBox*				EnablePunkBuster;								//var() XInterface.moCheckBox EnablePunkBuster;
	UPROPERTY(EditAnywhere)							UGUIImage*					BackgroundBorder;								//var() XInterface.GUIImage BackgroundBorder;

	void OnPunkBusterChanged(bool Enabled);
	void OnUpdateServerList();
	void OnJoinServer();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetVisibility(bool bIsVisible);
	void SetUpdateServerListButtonText(FString Text);
	void ActivateServerListButtonEyecatcher();
	void DeactivateServerListButtonEyecatcher();
	void SetEnablePunkBusterColor(bool Enabled);
	void InternalOnChange(UGUIComponent* Sender);
	void InternalOnClick(UGUIComponent* Sender);
	void testonly_GetEnablePunkbuster();
	void testonly_GetUpdateServerList();
	void testonly_GetJoinServer();
};
