// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupport_Links/AASupport_Links.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

UAASupport_Links::UAASupport_Links()
{
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0.005;
	MyPanel->bScaleItemsToWidth=true;
	MyPanel->WinTop=0.06625;
	MyPanel->WinHeight=0.8825;
	MyPanel->RenderWeight=0.6;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;

	cob_Panel = MyPanel;
	SupportFile = "/x_support_links.nml";
	PanelCaption = "Links";
}

void UAASupport_Links::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
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
		MyNML.__dInterPanelLink__Delegate = OnInterPanelLink;
		MyNML.ParseNMLFromServer(SupportFile, "dms1.americasarmy.com", 80, cob_Panel, i_NMLStatusIcon, l_NMLStatusText);
	}
	*/
}

void UAASupport_Links::OnInterPanelLink(FString PanelName, int32 Param1, int32 Param2, FString Param3)
{
	//Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", Param3, PanelName);
}