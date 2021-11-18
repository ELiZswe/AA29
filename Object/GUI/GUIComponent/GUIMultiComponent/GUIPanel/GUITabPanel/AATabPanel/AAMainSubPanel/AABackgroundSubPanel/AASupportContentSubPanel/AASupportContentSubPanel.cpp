// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupportContentSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"

UAASupportContentSubPanel::UAASupportContentSubPanel()
{
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0.02;
	MyPanel->bScaleItemsToWidth=true;
	MyPanel->WinTop=0.06625;
	MyPanel->WinHeight=0.8825;
	MyPanel->RenderWeight=0.6;
	MyPanel->bBoundToParent=true;
	MyPanel->bScaleToParent=true;
	
	cob_Panel = MyPanel;
	ContentPackage = "T_AA2_UI";
	ContentPackageGroup = "Menu";
}

void UAASupportContentSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	LoadContent();
}

bool UAASupportContentSubPanel::ButtonClick(UGUIComponent* Sender)
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
	if (GUILabelButton(Sender) != None)
	{
		GOTO JL012E;
	}
	if (GUIImageButton(Sender) != None)
		JL012E:
	{
	}
	*/
	return true;
}

void UAASupportContentSubPanel::LoadContent()
{
	/*
	int32 i = 0;
	int32 j = 0;
	int32 NumSections = 0;
	int32 NumSets = 0;
	FString File = "";
	FString Text = "";
	FString text1 = "";
	FString text2 = "";
	FString DisplayLink = "";
	FString link = "";
	local AAGUILabel Lbl;
	local GUIGridLayout Grid;
	local Material mat;
	local GUIImageButton img;
	local GUILabelButton lb_Link;
	File = GetBaseDir() $ SupportFile;
	NumSections = GetPrivateProfileInt(File, "List", "NUMSECTIONS");
	for (i = 0; i < NumSections; i++)
	{
		Text = GetPrivateProfileString(File, "List", "SectionLabel(" $ string(i) $ ")");
		if (Text != "")
		{
			Lbl = AAGUILabel(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
			Lbl.Caption = Text;
			Lbl.Style = Controller.GetStyle("Header", FontScale);
		}
		NumSets = GetPrivateProfileInt(File, "List", "NUMSETS(" $ string(i) $ ")");
		for (j = 0; j < NumSets; j++)
		{
			Grid = GUIGridLayout(cob_Panel.addItem("AGP_Interface.GUIGridLayout"));
			Grid.NumColumns = 2;
			Text = GetPrivateProfileString(File, "List", "SectionSet_" $ string(j) $ "(" $ string(i) $ ")");
			Lbl = AAGUILabel(Grid.CreateItem("AGP_Interface.AAGUILabel", 5));
			Lbl.Style = Controller.GetStyle("TextLabel", FontScale);
			Lbl.Caption = Text;
			Lbl.bMultiLine = true;
			mat = Material(DynamicLoadObject("" $ ContentPackage $ "." $ ContentPackageGroup $ "." $ GetPrivateProfileString(File, Text, "Image"), Class'Material', true));
			DisplayLink = GetPrivateProfileString(File, Text, "DisplayLink");
			link = GetPrivateProfileString(File, Text, "Link");
			if (mat != None)
			{
				img = GUIImageButton(Grid.CreateItem("AGP_Interface.GUIImageButton", 3));
				img.Image = mat;
				img.ImageRenderStyle = 1;
				img.ImageStyle = 4;
				img.WinWidth = 1;
				img.WinHeight = 0.116667;
				img.__OnClick__Delegate = ButtonClick;
				img.Caption = DisplayLink;
				img.link = link;
				img.bAcceptsInput = false;
			}
			text1 = GetPrivateProfileString(File, Text, "Text1");
			if (text1 != "")
			{
				Lbl = AAGUILabel(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
				Lbl.Style = Controller.GetStyle("SupportLabelText", FontScale);
				Lbl.bMultiLine = true;
				Lbl.Caption = text1;
			}
			text2 = GetPrivateProfileString(File, Text, "Text2");
			if (text2 != "")
			{
				Lbl = AAGUILabel(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
				Lbl.Style = Controller.GetStyle("SupportLabelText", FontScale);
				Lbl.bMultiLine = true;
				Lbl.Caption = text2;
			}
			if ((link != "") && (DisplayLink != ""))
			{
				lb_Link = GUILabelButton(cob_Panel.addItem("AGP_Interface.GUILabelButton"));
				lb_Link.Style = Controller.GetStyle("LinkButton", FontScale);
				lb_Link.Caption = DisplayLink;
				lb_Link.link = link;
				lb_Link.bMultiLine = true;
				lb_Link.__OnClick__Delegate = ButtonClick;
				lb_Link.Hint = "Click to open link in a web browser";
			}
		}
	}
	*/
}
