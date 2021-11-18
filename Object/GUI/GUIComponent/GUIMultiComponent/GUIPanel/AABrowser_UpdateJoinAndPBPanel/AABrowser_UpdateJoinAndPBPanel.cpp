// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/AABrowser_UpdateJoinAndPBPanel/AABrowser_UpdateJoinAndPBPanel.h"

UAABrowser_UpdateJoinAndPBPanel::UAABrowser_UpdateJoinAndPBPanel()
{
	//BackgroundBorder = GUIImage'AGP_Interface.AABrowser_UpdateJoinAndPBPanel.PanelBackground';
	//EnablePunkBuster = moCheckBox'AGP_Interface.AABrowser_UpdateJoinAndPBPanel.PunkBusterCheckBox';
	//UpdateServerList = GUIButton'AGP_Interface.AABrowser_UpdateJoinAndPBPanel.UpdateServerListButton';
	//JoinServer = GUIButton'AGP_Interface.AABrowser_UpdateJoinAndPBPanel.JoinServerButton';
	//UpdateServerListEyeCatcherStyleName = "EyeCatcherSquareButton";
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
		UpdateServerListOriginalStyle = None;
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
				Return True;
				break;
			case JoinServer:
				OnJoinServer();
				Return True;
				break;
			default:
				Return False;
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