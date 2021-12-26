// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/AAShowFiltersDialog/AAShowFiltersDialog.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIContentBox/GUIContentBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"

UAAShowFiltersDialog::UAAShowFiltersDialog()
{
	UGUIButton* OkButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	OkButton->Caption = "OK";
	OkButton->WinTop = 0.916667;
	OkButton->WinLeft = 0.35875;
	OkButton->WinWidth = 0.2;
	OkButton->bBoundToParent = true;
	//OkButton->OnClick=AAShowFiltersDialog.InternalOnClick;
	//OkButton->OnKeyEvent=OkButton.InternalOnKeyEvent;
	UGUIContentBox* ContentBox = NewObject<UGUIContentBox>(UGUIContentBox::StaticClass());
	ContentBox->ItemSpacing = 0.02;
	ContentBox->bScaleItemsToWidth = true;
	ContentBox->WinTop = 0.065;
	ContentBox->WinLeft = 0.02;
	ContentBox->WinWidth = 0.98;
	ContentBox->WinHeight = 0.85;
	ContentBox->RenderWeight = 0.6;
	ContentBox->bBoundToParent = true;
	ContentBox->bScaleToParent = true;
	b_OK = OkButton;
	FilterSummary = ContentBox;
	NoFiltersMessage = "No filters selected.";
}

void UAAShowFiltersDialog::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	t_WindowTitle.SetCaption("Server Browser Filters");
	Super::InitComponent(MyController, MyOwner);
	*/
}

FString UAAShowFiltersDialog::FilterDescriptionsToNML(TArray<FKeyValuePair> FilterDescriptions)
{
	FString NML = "";
	/*
	int32 Index = 0;
	if (FilterDescriptions.Length == 0)
	{
		NML = "<text>";
		NML $ = "<content>" $ NoFiltersMessage $ "</content>";
		NML $ = "<style>MediumText</style>";
		NML $ = "</text>";
	}
	else
	{
		NML = "<grid>";
		NML $ = "<columns>2</columns><columnspacing>0.005</columnspacing><rowspacing>0.005</rowspacing>";
		for (Index = 0; Index < FilterDescriptions.Length; Index++)
		{
			NML $ = "<cell><text><content>" $ FilterDescriptions[Index].Key $ ":</content></text></cell>";
			NML $ = "<cell><text><content>" $ FilterDescriptions[Index].Value $ "</content></text></cell>";
		}
		NML $ = "</grid>";
	}
	*/
	return NML;
}

void UAAShowFiltersDialog::SetFilterDescriptions(TArray<FKeyValuePair> FilterDescriptions)
{
	/*
	local NMLContent MyNML;
	MyNML = new (None) class'AGP_Interface.NMLContent';
	if (MyNML != None)
	{
		if (MyNML.Controller == nullptr)
		{
			MyNML.InitComponent(Controller, MenuOwner);
		}
		MyNML.ParseNMLFromString(FilterDescriptionsToNML(FilterDescriptions), FilterSummary);
	}
	*/
}

bool UAAShowFiltersDialog::InternalOnClick(UGUIComponent* Sender)
{
	//Controller.CloseMenu(false);
	return true;
}
