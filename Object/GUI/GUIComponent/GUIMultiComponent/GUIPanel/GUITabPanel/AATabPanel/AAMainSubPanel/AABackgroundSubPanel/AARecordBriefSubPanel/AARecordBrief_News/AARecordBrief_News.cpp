// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARecordBriefSubPanel/AARecordBrief_News/AARecordBrief_News.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

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
	/*
	local NMLContent MyNML;
	Super::InitComponent(MyController, MyOwner);
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == None)
		{
			MyNML.InitComponent(MyController, MyOwner);
		}
		MyNML.ParseNMLFromServer("/x_rbrief_news.nml", "dms1.americasarmy.com", 80, guicbPanel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

bool UAARecordBrief_News::ButtonClick(UGUIComponent* Sender)
{
	/*
	if ((GUILabelButton(Sender) != None) || (GUIImageButton(Sender) != None))
	{
		selected = Sender;
	}
	if (selected == None)
	{
		return false;
	}
	if (GUILabelButton(Sender) != None)
	{
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", GUILabelButton(selected).Caption, GUILabelButton(selected).link);
	}
	else
	{
		if (GUIImageButton(Sender) != None)
		{
			Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", GUIImageButton(selected).Caption, GUIImageButton(selected).link);
		}
	}
	*/
	return true;
}
