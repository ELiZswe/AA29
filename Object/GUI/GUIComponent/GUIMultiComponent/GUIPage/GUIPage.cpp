// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"

UGUIPage::UGUIPage()
{
	bCaptureInput = true;
	bRequire640x480 = true;
	BackgroundColor = FColor(255, 255, 255, 255);
	InactiveFadeColor = FColor(64, 64, 64, 255);
	BackgroundRStyle = EMenuRenderStyle::MSTY_Normal;
	RenderWeight = 0.0001;
	bTabStop = false;
	bAcceptsInput = true;
}

void UGUIPage::NotifyCommandPostPage(FString sPanelName, FString sParam1, FString sParam2, FString sParam3)
{
}

void UGUIPage::NotifyStatsPage(FString sStatRequested, FString sValue)
{
}

void UGUIPage::OnOpen()
{
	/*
	if ((Controller != None) && Controller.bSnapCursor)
	{
		CenterMouse();
	}
	*/
}

void UGUIPage::OnReOpen()
{
}

void UGUIPage::OnClose(bool bCancelled)
{
}

bool UGUIPage::OnCanClose(bool bCancelled)
{
	return true;
}

void UGUIPage::Closed(UGUIComponent* Sender, bool bCancelled)
{
	//Super::Closed(Sender, bCancelled);
	//OnClose(bCancelled);
}

void UGUIPage::PlayOpenSound()
{
	//PlayerOwner().PlayOwnedSound(OpenSound, 6, 1);
}

void UGUIPage::PlayCloseSound()
{
	//PlayerOwner().PlayOwnedSound(CloseSound, 6, 1);
}

void UGUIPage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
	//FocusFirst(None);
}

void UGUIPage::CheckResolution(bool Closing, UGUIController* InController)
{
	/*
	local FString CurrentRes;
	local FString Xstr;
	local FString Ystr;
	local int32 ResX;
	local int32 ResY;
	if (InController == None)
	{
		return;
	}
	if ((InController.ResX == 0) || (InController.ResY == 0))
	{
		CurrentRes = PlayerOwner().ConsoleCommand("GETCURRENTRES");
		if (Divide(CurrentRes, "x", Xstr, Ystr))
		{
			ResX = int(Xstr);
			ResY = int(Ystr);
		}
	}
	else
	{
		ResX = InController.ResX;
		ResY = InController.ResY;
		CurrentRes = string(InController.ResX) $ "x" $ string(InController.ResY);
	}
	if (!Closing)
	{
		if ((((InController != None) && (ResX < 640)) && (ResY < 480)) && bRequire640x480)
		{
			if (InController.bModAuthor)
			{
				Log(string(Name) $ ".CheckResolution() - menu requires 640x480.  Currently at " $ CurrentRes, 'ModAuthor');
			}
			InController.GameResolution = CurrentRes;
			Console(InController.Master.Console).DelayedConsoleCommand("TEMPSETRES 640x480");
		}
		return;
	}
	if ((!bRequire640x480) || (InController.GameResolution == ""))
	{
		return;
	}
	if (CurrentRes != InController.GameResolution)
	{
		if (!InController.NeedsMenuResolution())
		{
			if (InController.bModAuthor)
			{
				Log(string(Name) $ ".CheckResolution() - restoring menu resolution to standard value:" @ InController.GameResolution, 'ModAuthor');
			}
			Console(InController.Master.Console).DelayedConsoleCommand("SETRES" @ InController.GameResolution);
			InController.GameResolution = "";
		}
		else
		{
			if (InController.bModAuthor)
			{
				Log(string(Name) $ ".CheckResolution() - not restoring resolution to standard value: ParentMenu would abort.", 'ModAuthor');
			}
		}
	}
	*/
}

void UGUIPage::ChangeHint(FString NewHint)
{
	//SetHint(NewHint);
}

void UGUIPage::SetFocus(UGUIComponent* Who)
{
	/*
	if (Who == None)
	{
		return;
	}
	Super::SetFocus(Who);
	*/
}

void UGUIPage::HandleParameters(FString Param1, FString Param2)
{
}

bool UGUIPage::GetRestoreParams(FString& Param1, FString& Param2)
{
	return false;   //FAKE   /ELiZ
}

void UGUIPage::HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2)
{
}

FString UGUIPage::GetDataString()
{
	return "";
}

void UGUIPage::SetDataString(FString str)
{
}

bool UGUIPage::NotifyLevelChange()
{
	//LevelChanged();
	return true;
}

void UGUIPage::Free()
{
	/*
	local int32 i;
	if (!bPersistent)
	{
		for (i = 0; i < Timers.Length; i++)
		{
			Timers[i] = None;
		}
		Super::Free();
	}
	*/
}

bool UGUIPage::IsOpen()
{
	/*
	if (Controller == None)
	{
		return false;
	}
	return (Controller.FindMenuIndex(Self) != -1);
	*/
	return false;    //FAKE   /ELiZ
}

bool UGUIPage::AllowOpen(FString MenuClass)
{
	return true;
}