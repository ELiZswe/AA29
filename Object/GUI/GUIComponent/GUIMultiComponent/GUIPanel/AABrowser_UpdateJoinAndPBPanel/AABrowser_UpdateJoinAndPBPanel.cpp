// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_UpdateJoinAndPBPanel/AABrowser_UpdateJoinAndPBPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIStyles/GUIStyles.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UAABrowser_UpdateJoinAndPBPanel::UAABrowser_UpdateJoinAndPBPanel()
{
	UGUIButton* JoinServerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	JoinServerButton->Caption = "Join Server";
	JoinServerButton->FontScale = EeFontScale::FNS_Small;
	JoinServerButton->WinTop = 0.25438;
	JoinServerButton->WinLeft = 0.774564;
	JoinServerButton->WinWidth = 0.216374;
	JoinServerButton->WinHeight = 0.625229;
	//JoinServerButton->OnClick=AABrowser_UpdateJoinAndPBPanel.InternalOnClick;
	//JoinServerButton->OnKeyEvent=JoinServerButton.InternalOnKeyEvent;
	UGUIButton* UpdateServerListButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	UpdateServerListButton->Caption = "Obtain Server List";
	UpdateServerListButton->FontScale = EeFontScale::FNS_Small;
	UpdateServerListButton->WinTop = 0.25438;
	UpdateServerListButton->WinLeft = 0.432375;
	UpdateServerListButton->WinWidth = 0.325035;
	UpdateServerListButton->WinHeight = 0.625229;
	//UpdateServerListButton->OnClick=AABrowser_UpdateJoinAndPBPanel.InternalOnClick;
	//UpdateServerListButton->OnKeyEvent=UpdateServerListButton.InternalOnKeyEvent;
	UmoCheckBox* PunkBusterCheckBox = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	PunkBusterCheckBox->CaptionWidth = 0.9;
	PunkBusterCheckBox->Caption = "Enable PunkBuster";
	//PunkBusterCheckBox->OnCreateComponent=PunkBusterCheckBox.InternalOnCreateComponent;
	PunkBusterCheckBox->FontScale = EeFontScale::FNS_Small;
	PunkBusterCheckBox->Hint = "Check this box to enable PunkBuster.";
	PunkBusterCheckBox->WinTop = 0.264707;
	PunkBusterCheckBox->WinLeft = 0.041213;
	PunkBusterCheckBox->WinWidth = 0.366563;
	PunkBusterCheckBox->WinHeight = 0.677921;
	PunkBusterCheckBox->TabOrder = 4;
	PunkBusterCheckBox->bBoundToParent = true;
	PunkBusterCheckBox->bScaleToParent = true;
	PunkBusterCheckBox->bStandardized = false;
	//PunkBusterCheckBox->OnChange=AABrowser_UpdateJoinAndPBPanel.InternalOnChange;
	UGUIImage* PanelBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	PanelBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfill_Mat.backgroundfill_Mat'"), NULL, LOAD_None, NULL);
	PanelBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	PanelBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	PanelBackground->WinHeight = 1;
	PanelBackground->RenderWeight = 0;
	PanelBackground->bBoundToParent = true;
	PanelBackground->bScaleToParent = true;
	BackgroundBorder = PanelBackground;
	EnablePunkBuster = PunkBusterCheckBox;
	UpdateServerList = UpdateServerListButton;
	JoinServer = JoinServerButton;
	UpdateServerListEyeCatcherStyleName = "EyeCatcherSquareButton";
}

void UAABrowser_UpdateJoinAndPBPanel::OnPunkBusterChanged(bool Enabled)
{
}

void UAABrowser_UpdateJoinAndPBPanel::OnUpdateServerList()
{
}

void UAABrowser_UpdateJoinAndPBPanel::OnJoinServer()
{
}

void UAABrowser_UpdateJoinAndPBPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (HideBorder)
	{
		RemoveComponent(BackgroundBorder);
	}
	if (UpdateServerListEyeCatcherStyleName != "")
	{
		UpdateServerListEyeCatcherStyle = Controller.GetStyle(UpdateServerListEyeCatcherStyleName, FontScale);
	}
	*/
}

void UAABrowser_UpdateJoinAndPBPanel::SetVisibility(bool bIsVisible)
{
	/*
	if (bIsVisible && None != PlayerOwner())
	{
		SetEnablePunkBusterColor(PlayerOwner().Level.PBIsEnabled() != 0);
		EnablePunkBuster.SetComponentValue(PlayerOwner().Level.PBIsEnabled() != 0, true);
	}
	*/
}

void UAABrowser_UpdateJoinAndPBPanel::SetUpdateServerListButtonText(FString Text)
{
	UpdateServerList->Caption = Text;
}

void UAABrowser_UpdateJoinAndPBPanel::ActivateServerListButtonEyecatcher()
{
	if (nullptr == UpdateServerListOriginalStyle)
	{
		UpdateServerListOriginalStyle = UpdateServerList->Style;
		UpdateServerList->Style = UpdateServerListEyeCatcherStyle;
	}
}

void UAABrowser_UpdateJoinAndPBPanel::DeactivateServerListButtonEyecatcher()
{
	if (nullptr != UpdateServerListOriginalStyle)
	{
		UpdateServerList->Style = UpdateServerListOriginalStyle;
		UpdateServerListOriginalStyle = nullptr;
	}
}

void UAABrowser_UpdateJoinAndPBPanel::SetEnablePunkBusterColor(bool Enabled)
{
	FColor NewColor = FColor(0,0,0);
	if (Enabled)
	{
		NewColor.A = 255;
		NewColor.R = 0;
		NewColor.G = 255;
		NewColor.B = 0;
	}
	else
	{
		NewColor.A = 255;
		NewColor.R = 255;
		NewColor.G = 0;
		NewColor.B = 0;
	}
	EnablePunkBuster->MyLabel->Caption = MakeColorCode(NewColor) + StripColorCodes(EnablePunkBuster->MyLabel->Caption);
}

void UAABrowser_UpdateJoinAndPBPanel::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Sender == EnablePunkBuster)
	{
		SetEnablePunkBusterColor(Cast<UmoCheckBox>(Sender).IsChecked());
		OnPunkBusterChanged(Cast<UmoCheckBox>(Sender).IsChecked());
	}
	*/
}

bool UAABrowser_UpdateJoinAndPBPanel::InternalOnClick(UGUIComponent* Sender)
{
	if (Sender == UpdateServerList)
	{
		DeactivateServerListButtonEyecatcher();
		OnUpdateServerList();
		return true;
	}

	if (Sender == JoinServer)
	{
		OnJoinServer();
		return true;
	}
	return false;
}

UmoCheckBox* UAABrowser_UpdateJoinAndPBPanel::testonly_GetEnablePunkbuster()
{
	return EnablePunkBuster;
}

UGUIButton* UAABrowser_UpdateJoinAndPBPanel::testonly_GetUpdateServerList()
{
	return UpdateServerList;
}

UGUIButton* UAABrowser_UpdateJoinAndPBPanel::testonly_GetJoinServer()
{
	return JoinServer;
}
