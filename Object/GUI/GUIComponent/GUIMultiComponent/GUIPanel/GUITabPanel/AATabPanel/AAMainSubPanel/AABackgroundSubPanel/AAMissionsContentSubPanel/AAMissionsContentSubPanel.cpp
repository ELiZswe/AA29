// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AAMissionsContentSubPanel/AAMissionsContentSubPanel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/AAGUIController/AAGUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/AAGUILabel/AAGUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUIGridLayout/GUIGridLayout.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabelButton/GUILabelButton.h"

UAAMissionsContentSubPanel::UAAMissionsContentSubPanel()
{
	
	UGUIImage* FieldBackground = NewObject<UGUIImage>(UGUIImage::StaticClass());
	FieldBackground->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	FieldBackground->ImageStyle = EImgStyle::ISTY_Stretched;
	FieldBackground->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	FieldBackground->WinTop=0.07;
	FieldBackground->WinLeft=0.01;
	FieldBackground->WinWidth=0.98;
	FieldBackground->WinHeight=0.92;
	FieldBackground->RenderWeight=0.2;
	UGUIContentBox* MyPanel = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	MyPanel->ItemSpacing=0.02;
	MyPanel->bScaleItemsToWidth=true;
	MyPanel->WinTop=0.08;
	MyPanel->WinLeft=0.02;
	MyPanel->WinWidth=0.96;
	MyPanel->WinHeight=0.9;
	MyPanel->RenderWeight=0.6;
	i_FieldBackground = FieldBackground;
	cob_Panel = MyPanel;
	ToursFile = "Tours.ini";
	ContentPackage = "T_AA2_UI";
	ContentPackageGroup = "Menu";
	NotAvailableText = "Not Available";
	AvailableText = "Available";
	CompletedText = "Completed";
	NotAvailableColor = FColor(0, 0, 192, 255);
	AvailableColor = FColor(64, 255, 0, 255);
	CompletedColor = FColor(255, 255, 255, 255);
}

void UAAMissionsContentSubPanel::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	LoadContent();
	*/
}

bool UAAMissionsContentSubPanel::ButtonClick(UGUIComponent* Sender)
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
	if (Cast<UGUIImageButton>(Sender) != nullptr)
	{
		Controller.OpenMenu("AGP_Interface.AATraining_Details", Cast<UGUIImageButton>(selected).Caption, Cast<UGUIImageButton>(selected).link);
	}
	if (Cast<UGUIImageButton>(Sender) != nullptr)
	{
	}
	*/
	return true;
}

void UAAMissionsContentSubPanel::LoadContent()
{
	int32 i = 0;
	int32 j = 0;
	int32 NumTours = 0;
	int32 NumMissions = 0;
	FString File = "";
	FString Text = "";
	UAAGUIController* C = nullptr;
	UMaterialInstance* mat = nullptr;
	UGUIImageButton* img = nullptr;
	UAAGUILabel* Lbl = nullptr;
	UGUIGridLayout* Grid = nullptr;
	C = Cast<UAAGUIController>(Controller);
	/*
	File = GetBaseDir() + ToursFile;
	NumTours = GetPrivateProfileInt(File, "Tours", "NumTours");
	for (i = 0; i < NumTours; i++)
	{
		TourID = i;
		if (UseTraining(TourID) && ((TourID != C.4) || (!C.bFilterNoSniper)))
		{
			mat = Cast<UMaterialInstance>(DynamicLoadObject(PlayerOwner().Level.GetTourImage(TourID), Class'Material', true));
			if (mat != nullptr)
			{
				img = Cast<UGUIImageButton>(cob_Panel.addItem("AGP_Interface.GUIImageButton"));
				img.Image = mat;
				img.ImageRenderStyle = 1;
				img.ImageStyle = 4;
				img.WinWidth = 0.21;
				img.WinHeight = 0.27;
				img.__OnClick__Delegate = ButtonClick;
				img.bAcceptsInput = false;
			}
			Text = "";
			Text = PlayerOwner().Level.GetTourName(TourID);
			if (Text != "")
			{
				Lbl = Cast<UAAGUILabel>(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
				Lbl.Caption = Text;
				Lbl.Style = Controller.GetStyle("Header", FontScale);
			}
			Text = "";
			Text = PlayerOwner().Level.GetTourName(PlayerOwner().Level.GetTourDependency(TourID));
			if (Text == "")
			{
				Text = "Requirements: None";
			}
			else
			{
				Text = "Requirements: " + Text;
			}
			if (Text != "")
			{
				Lbl = Cast<UAAGUILabel>(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
				Lbl.Caption = Text;
				Lbl.Style = Controller.GetStyle("SupportLabelText", FontScale);
			}
			Text = "";
			Text = PlayerOwner().Level.GetTourName(TourID);
			if (Text != "")
			{
				Lbl = Cast<UAAGUILabel>(cob_Panel.addItem("AGP_Interface.AAGUILabel"));
				Lbl.Caption = Text;
				Lbl.Style = Controller.GetStyle("SupportLabelText", FontScale);
			}
			NumMissions = PlayerOwner().Level.GetTourMissions(TourID);
			for (j = 0; j < NumMissions; j++)
			{
				MissionID = j;
				Grid = GUIGridLayout(cob_Panel.addItem("AGP_Interface.GUIGridLayout"));
				Grid->NumColumns = 2;
			}
		}
	}
	*/
}

bool UAAMissionsContentSubPanel::UseTraining(int32 Tour)
{
	return true;
}

void UAAMissionsContentSubPanel::SetStatusCaption(int32 Status)
{
}
