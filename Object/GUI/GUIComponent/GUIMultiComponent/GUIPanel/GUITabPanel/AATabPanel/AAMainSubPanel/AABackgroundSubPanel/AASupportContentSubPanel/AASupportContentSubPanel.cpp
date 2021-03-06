// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AASupportContentSubPanel/AASupportContentSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIGridLayout/GUIGridLayout.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabelButton/GUILabelButton.h"

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
		Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", Cast<UGUILabelButton>(selected).Caption, Cast<UGUILabelButton>(selected).link);
	}
	else
	{
		if (Cast<UGUIImageButton>(Sender) != nullptr)
		{
			Controller.OpenMenu("AGP_Interface.AAExternalLinkPage", Cast<UGUIImageButton>(selected).Caption, Cast<UGUIImageButton>(selected).link);
		}
	}
	if (Cast<UGUILabelButton>(Sender) != nullptr)
	{
		GOTO JL012E;
	}
	if (Cast<UGUIImageButton>(Sender) != nullptr)
		JL012E:
	{
	}
	*/
	return true;
}

void UAASupportContentSubPanel::LoadContent()
{
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
	UAAGUILabel* Lbl = nullptr;
	UGUIGridLayout* Grid = nullptr;
	UMaterialInstance* mat = nullptr;
	UGUIImageButton* img = nullptr;
	UGUILabelButton* lb_Link = nullptr;
	/*
	File = GetBaseDir() + SupportFile;
	NumSections = GetPrivateProfileInt(File, "List", "NUMSECTIONS");
	for (i = 0; i < NumSections; i++)
	{
		Text = GetPrivateProfileString(File, "List", "SectionLabel(" + FString::FromInt(i) + ")");
		if (Text != "")
		{
			Lbl = Cast<UAAGUILabel>(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
			Lbl.Caption = Text;
			Lbl.Style = Controller.GetStyle("Header", FontScale);
		}
		NumSets = GetPrivateProfileInt(File, "List", "NUMSETS(" + FString::FromInt(i) + ")");
		for (j = 0; j < NumSets; j++)
		{
			Grid = GUIGridLayout(cob_Panel.addItem("AGP_Interface.GUIGridLayout"));
			Grid->NumColumns = 2;
			Text = GetPrivateProfileString(File, "List", "SectionSet_" + FString::FromInt(j) + "(" + FString::FromInt(i) + ")");
			Lbl = Cast<UAAGUILabel>(Grid->CreateItem("AGP_Interface.AAGUILabel", 5));
			Lbl.Style = Controller.GetStyle("TextLabel", FontScale);
			Lbl.Caption = Text;
			Lbl.bMultiLine = true;
			mat = Cast<UMaterialInstance>(DynamicLoadObject("" + ContentPackage + "." + ContentPackageGroup + "." + GetPrivateProfileString(File, Text, "Image"), Class'Material', true));
			DisplayLink = GetPrivateProfileString(File, Text, "DisplayLink");
			link = GetPrivateProfileString(File, Text, "Link");
			if (mat != nullptr)
			{
				img = Cast<UGUIImageButton>(Grid->CreateItem("AGP_Interface.GUIImageButton", 3));
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
				Lbl = Cast<UAAGUILabel>(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
				Lbl.Style = Controller.GetStyle("SupportLabelText", FontScale);
				Lbl.bMultiLine = true;
				Lbl.Caption = text1;
			}
			text2 = GetPrivateProfileString(File, Text, "Text2");
			if (text2 != "")
			{
				Lbl = Cast<UAAGUILabel>(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
				Lbl.Style = Controller.GetStyle("SupportLabelText", FontScale);
				Lbl.bMultiLine = true;
				Lbl.Caption = text2;
			}
			if ((link != "") && (DisplayLink != ""))
			{
				lb_Link = Cast<UGUILabelButton>(cob_Panel.addItem("AGP_Interface.GUILabelButton"));
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
