// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/BlackoutWindow/AAExternalLinkPage/AARHLinkPage/AARHLinkPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UAARHLinkPage::UAARHLinkPage()
{
	UGUIButton* cNoButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cNoButton->Caption = "Cancel";
	cNoButton->StyleName = "SquareMenuButton";
	cNoButton->WinTop = 0.6;
	cNoButton->WinLeft = 0.599;
	cNoButton->WinWidth = 0.126;
	cNoButton->WinHeight = 0.035;
	//cNoButton->OnClick=AARHLinkPage.InternalOnClick;
	//cNoButton->OnKeyEvent=cNoButton.InternalOnKeyEvent;
	UGUIButton* cYesButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	cYesButton->Caption = "Watch Video";
	cYesButton->StyleName = "SquareMenuButton";
	cYesButton->WinTop = 0.6;
	cYesButton->WinLeft = 0.275;
	cYesButton->WinWidth = 0.126;
	cYesButton->WinHeight = 0.035;
	//cYesButton->OnClick=AARHLinkPage.InternalOnClick;
	//cYesButton->OnKeyEvent=cYesButton.InternalOnKeyEvent;
	UGUILabel* cLinkDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cLinkDesc->Caption = "Launch an external link in your web browser?";
	cLinkDesc->TextAlign = ETextAlign::TXTA_Center;
	cLinkDesc->TextColor = FColor(229, 248, 251, 255);
	cLinkDesc->TextFont = "AAFontHeader";
	cLinkDesc->WinTop = 0.325;
	cLinkDesc->WinHeight = 32;
	cLinkDesc->RenderWeight = 4;
	UGUILabel* cURLDesc = NewObject<UGUILabel>(UGUILabel::StaticClass());
	cURLDesc->TextAlign = ETextAlign::TXTA_Center;
	cURLDesc->bMultiLine = true;
	cURLDesc->StyleName = "NMLMediumText";
	cURLDesc->WinTop = 0.425;
	cURLDesc->WinLeft = 0.2;
	cURLDesc->WinWidth = 0.6;
	cURLDesc->WinHeight = 0.75;
	cURLDesc->RenderWeight = 4;
	YesButton = cYesButton;
	NoButton = cNoButton;
	LinkDesc = cLinkDesc;
	URLDesc = cURLDesc;
	//OnKeyEvent = AARHLinkPage.InternalOnKeyEvent;
}

void UAARHLinkPage::HandleParameters(FString Param1, FString Param2)
{
	/*
	Super::HandleParameters(Param1, Param2);
	URLDesc.Caption = AGP_HUD(HumanController(PlayerOwner()).myHUD).sRHExternalLinkCaption;
	LinkDesc.Caption = AGP_HUD(HumanController(PlayerOwner()).myHUD).sRHExternalLinkTitle;
	LinkURL = Param2;
	*/
}

bool UAARHLinkPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	local StudentController SC;
	int32 i = 0;
	for (i = 0; i < 16; i++)
	{
		Log("iCompleted[" $ string(i) $ "]: " $ string(PlayerOwner().iCompleted[i]));
	}
	if (Sender == YesButton)
	{
		LaunchURL(Self);
		if (AAGUIController(Controller).bLoggedIn)
		{
			SC = StudentController(PlayerOwner());
			if (SC != None)
			{
				if (!((int((2 * *float(SC.iLastRealHeroVisited))) & SC.iCompleted[15]) > 0))
				{
					SC.bDontLockAfterMisionComplete = true;
					SC.SetAuthMissionPassFlag(true);
					SC.SendMissionComplete(14, SC.iLastRealHeroVisited);
					SC.iCompleted[15] = (int((2 * *float(SC.iLastRealHeroVisited))) | SC.iCompleted[15]);
				}
			}
		}
	}
	ParentPage.bVisible = true;
	HumanController(PlayerOwner()).ClientCloseMenu(false);
	*/
	return true;
}