// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/IngameChat/IngameChat.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"

UIngameChat::UIngameChat()
{
	UGUIEditBox* ChatEdit = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	ChatEdit->StyleName = "SquareButton";
	ChatEdit->WinTop = 0.94;
	ChatEdit->bBoundToParent = true;
	ChatEdit->bScaleToParent = true;
	//ChatEdit->OnActivate=ChatEdit.InternalActivate;
	//ChatEdit->OnDeActivate=ChatEdit.InternalDeactivate;
	//ChatEdit->OnKeyType=ChatEdit.InternalOnKeyType;
	//ChatEdit->OnKeyEvent=ChatEdit.InternalOnKeyEvent;
	UGUIScrollTextBox* chatText = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	chatText->bNoTeletype = true;
	chatText->CharDelay = 0.0025;
	chatText->EOLDelay = 0;
	//chatText->OnCreateComponent=chatText.InternalOnCreateComponent;
	chatText->WinTop = 0.02;
	chatText->WinLeft = 0.03;
	chatText->WinWidth = 0.94;
	chatText->WinHeight = 0.88;
	chatText->bBoundToParent = true;
	chatText->bScaleToParent = true;
	chatText->bNeverFocus = true;
	UGUIImage* ChatBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	ChatBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/SquareBox_Mat.SquareBox_Mat'"), NULL, LOAD_None, NULL);
	ChatBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	ChatBackground->WinHeight = 1;
	ChatBackground->bBoundToParent = true;
	ChatBackground->bScaleToParent = true;
	ChatBackground->bNeverFocus = true;
	bRequire640x480 = false;
	bPersistent = true;
	bAllowedAsLast = true;
	Controls = { ChatBackground,chatText,ChatEdit };
	WinTop = 0.1;
	WinLeft = 0.1;
	WinWidth = 0.8;
	WinHeight = 0.8;
}

void UIngameChat::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	FString KeyName = "";
	Super::InitComponent(MyController, MyOwner);
	MyEditBox = GUIEditBox(Controls[2]);
	MyEditBox.__OnKeyEvent__Delegate = InternalOnKeyEvent;
	MyEditBox.__OnKeyType__Delegate = InternalOnKeyType;
	__OnClose__Delegate = MyOnClose;
	GUIScrollTextBox(Controls[1]).MyScrollText.bNeverFocus = true;
	KeyName = PlayerOwner().ConsoleCommand("BINDINGTOKEY InGameChat");
	if (KeyName != "")
	{
		CloseKey = byte(PlayerOwner().ConsoleCommand("KEYNUMBER" @ KeyName));
	}
	*/
}

void UIngameChat::Clear()
{
	/*
	local GUIScrollTextBox MyText;
	MyText = GUIScrollTextBox(Controls[1]);
	MyText.MyScrollText.SetContent("");
	*/
}

void UIngameChat::HandleParameters(FString Param1, FString Param2)
{
	/*
	bIgnoreChar = true;
	MyEditBox.SetFocus(None);
	OldCMC = PlayerOwner().myHUD.ConsoleMessageCount;
	PlayerOwner().myHUD.ConsoleMessageCount = 0;
	*/
}

void UIngameChat::MyOnClose(bool bCanceled)
{
	/*
	if (MyConsole != None)
	{
		MyConsole.ChatMenu = None;
		MyConsole = None;
	}
	PlayerOwner().myHUD.ConsoleMessageCount = OldCMC;
	OnClose(bCanceled);
	*/
}

bool UIngameChat::InternalOnKeyType(uint8& Key, FString Unicode)
{
	/*
	if (bIgnoreChar)
	{
		bIgnoreChar = false;
		return true;
	}
	return MyEditBox.InternalOnKeyType(Key, Unicode);
	*/
	return false;    //FAKE   /EliZ
}

bool UIngameChat::InternalOnKeyEvent(uint8& Key, uint8& State, float Delta)
{
	/*
	FString Cmd = "";
	if ((Key == CloseKey) && (State == 1))
	{
		Controller.CloseMenu(false);
		return true;
	}
	if ((Key == 13) && (State == 3))
	{
		if (Left(MyEditBox.TextStr, 1) == "/")
		{
			Cmd = Right(MyEditBox.TextStr, (Len(MyEditBox.TextStr) - 1));
		}
		else
		{
			if (Left(MyEditBox.TextStr, 1) == ".")
			{
				Cmd = "teamsay" @ Right(MyEditBox.TextStr, (Len(MyEditBox.TextStr) - 1));
			}
			else
			{
				Cmd = "say" @ MyEditBox.TextStr;
			}
		}
		PlayerOwner().ConsoleCommand(Cmd);
		MyEditBox.TextStr = "";
		return true;
	}
	return MyEditBox.InternalOnKeyEvent(Key, State, Delta);
	*/
	return false;    //FAKE   /EliZ
}
