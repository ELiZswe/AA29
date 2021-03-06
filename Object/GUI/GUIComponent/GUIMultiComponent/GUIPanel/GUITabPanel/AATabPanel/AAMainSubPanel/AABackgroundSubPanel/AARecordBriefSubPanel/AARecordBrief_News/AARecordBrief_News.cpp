// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARecordBriefSubPanel/AARecordBrief_News/AARecordBrief_News.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/HttpLink/HttpLink.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabelButton/GUILabelButton.h"
#include "AA29/Object/GUI/GUIComponent/NMLContent/NMLContent.h"

UAARecordBrief_News::UAARecordBrief_News()
{
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing = 0.02;
	MyPanel->bScaleItemsToWidth = true;
	MyPanel->WinTop = 0.06625;
	MyPanel->WinHeight = 0.8825;
	MyPanel->RenderWeight = 0.6;
	MyPanel->bBoundToParent = true;
	MyPanel->bScaleToParent = true;

	guicbPanel = MyPanel;
	DefaultPanelText = "News";
	LoggedInPanelText = "News for ";
	PanelCaption = "News";
}

void UAARecordBrief_News::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	UNMLContent* MyNML = nullptr;
	Super::InitComponent(MyController, MyOwner);
	/*
	MyNML = new (None) UNMLContent::StaticClass();
	if (MyNML != nullptr)
	{
		if (MyNML.Controller == nullptr)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.ParseNMLFromServer("/x_rbrief_news.nml", "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

bool UAARecordBrief_News::ButtonClick(UGUIComponent* Sender)
{
	if ((Cast<UGUILabelButton>(Sender) != nullptr) || (Cast<UGUIImageButton>(Sender) != nullptr))
	{
		selected = Sender;
	}
	if (selected == nullptr)
	{
		return false;
	}
	if (Cast<UGUILabelButton>(Sender) != nullptr)
	{
		Controller->OpenMenu("AGP_Interface.AAExternalLinkPage", Cast<UGUILabelButton>(selected)->Caption, Cast<UGUILabelButton>(selected)->link);
	}
	else
	{
		if (Cast<UGUIImageButton>(Sender) != nullptr)
		{
			Controller->OpenMenu("AGP_Interface.AAExternalLinkPage", Cast<UGUIImageButton>(selected)->Caption, Cast<UGUIImageButton>(selected)->link);
		}
	}
	return true;
}
