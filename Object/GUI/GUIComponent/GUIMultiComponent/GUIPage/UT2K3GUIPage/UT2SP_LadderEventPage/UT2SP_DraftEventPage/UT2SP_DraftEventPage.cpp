// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2SP_LadderEventPage/UT2SP_DraftEventPage/UT2SP_DraftEventPage.h"

UUT2SP_DraftEventPage::UUT2SP_DraftEventPage()
{
	MessageDraft = "You have proven your valor in the qualification round,|and won the right to form your own team for the tournament.|Draft your team from the available free agents,|then enter the ladders of the team tournament--|but only after you have proven that you are fit to lead.";
	MessageDraftTitle = "Welcome to the Tournament";
}

void UUT2SP_DraftEventPage::InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(pMyController, MyOwner);
	lblCaption.Caption = MessageDraft;
	lblTitle.Caption = MessageDraftTitle;
	*/
}

bool UUT2SP_DraftEventPage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (Sender == btnOK)
	{
		return Controller.ReplaceMenu("xInterface.UT2DraftTeam");
	}
	else
	{
		return Super::InternalOnClick(Sender);
	}
	*/
	return false;   //FAKE   /ELiZ
}

void UUT2SP_DraftEventPage::SetTutorialName(FString tutname)
{
}