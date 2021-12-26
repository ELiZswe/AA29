// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_UpdateJoinAndPBPanel/AABrowser_UpdateJoinAndPBPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"

UAABrowser_UpdateJoinAndPBPanel::UAABrowser_UpdateJoinAndPBPanel()
{
	UGUIButton* JoinServerButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	JoinServerButton->Caption = "Join Server";
	JoinServerButton->FontScale = EFontScale::FNS_Small;
	JoinServerButton->WinTop = 0.25438;
	JoinServerButton->WinLeft = 0.774564;
	JoinServerButton->WinWidth = 0.216374;
	JoinServerButton->WinHeight = 0.625229;
	//JoinServerButton->OnClick=AABrowser_UpdateJoinAndPBPanel.InternalOnClick;
	//JoinServerButton->OnKeyEvent=JoinServerButton.InternalOnKeyEvent;
	UGUIButton* UpdateServerListButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	UpdateServerListButton->Caption = "Obtain Server List";
	UpdateServerListButton->FontScale = EFontScale::FNS_Small;
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
	PunkBusterCheckBox->FontScale = EFontScale::FNS_Small;
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
	PanelBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfil_Mat.backgroundfil_Mat'"), NULL, LOAD_None, NULL);
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
		EnablePunkBuster.SetComponentValue(PlayerOwner().Level.PBIsEnabled() != 0, True);
	}
	*/
}

void UAABrowser_UpdateJoinAndPBPanel::SetUpdateServerListButtonText(FString Text)
{
	//UpdateServerList.Caption = Text;
}

void UAABrowser_UpdateJoinAndPBPanel::ActivateServerListButtonEyecatcher()
{
	/*
	if (None == UpdateServerListOriginalStyle)
	{
		UpdateServerListOriginalStyle = UpdateServerList.Style;
		UpdateServerList.Style = UpdateServerListEyeCatcherStyle;
	}
	*/
}

void UAABrowser_UpdateJoinAndPBPanel::DeactivateServerListButtonEyecatcher()
{
	/*
	if (None != UpdateServerListOriginalStyle)
	{
		UpdateServerList.Style = UpdateServerListOriginalStyle;
		UpdateServerListOriginalStyle = nullptr;
	}
	*/
}

void UAABrowser_UpdateJoinAndPBPanel::SetEnablePunkBusterColor(bool Enabled)
{
	/*
	local Object.Color NewColor;
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
	EnablePunkBuster.MyLabel.Caption = MakeColorCode(NewColor) $ StripColorCodes(EnablePunkBuster.MyLabel.Caption);
	*/
}

void UAABrowser_UpdateJoinAndPBPanel::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Sender == EnablePunkBuster)
	{
		SetEnablePunkBusterColor(moCheckBox(Sender).IsChecked());
		OnPunkBusterChanged(moCheckBox(Sender).IsChecked());
	}
	*/
}

void UAABrowser_UpdateJoinAndPBPanel::InternalOnClick(UGUIComponent* Sender)
{
	/*
	Switch(Sender)
	{
			case UpdateServerList:
				DeactivateServerListButtonEyecatcher();
				OnUpdateServerList();
				return true;
				break;
			case JoinServer:
				OnJoinServer();
				return true;
				break;
			default:
				return false;
				break;
	}
	*/
}

void UAABrowser_UpdateJoinAndPBPanel::testonly_GetEnablePunkbuster()
{
	//Return EnablePunkBuster;
}

void UAABrowser_UpdateJoinAndPBPanel::testonly_GetUpdateServerList()
{
	//Return UpdateServerList;
}

void UAABrowser_UpdateJoinAndPBPanel::testonly_GetJoinServer()
{
	//Return JoinServer;
}