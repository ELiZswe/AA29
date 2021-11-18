// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/TestImagePage/TestImagePage.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUINumericEdit/GUINumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UTestImagePage::UTestImagePage()
{
	UGUINumericEdit* ImagePortionY2 = NewObject<UGUINumericEdit>(UGUINumericEdit::StaticClass());
	ImagePortionY2->MinValue = -1;
	ImagePortionY2->MaxValue = 1024;
	ImagePortionY2->Step = 10;
	ImagePortionY2->WinTop = 0.341354;
	ImagePortionY2->WinLeft = 0.003516;
	ImagePortionY2->WinWidth = 0.083203;
	ImagePortionY2->WinHeight = 0.04;
	ImagePortionY2->TabOrder = 10;
	//ImagePortionY2->OnDeActivate=ImagePortionY2.ValidateValue;
	//ImagePortionY2->OnChange=TestImagePage.ChangePortion;
	UGUINumericEdit* ImagePortionX2 = NewObject<UGUINumericEdit>(UGUINumericEdit::StaticClass());
	ImagePortionX2->MinValue = -1;
	ImagePortionX2->MaxValue = 1024;
	ImagePortionX2->Step = 10;
	ImagePortionX2->WinTop = 0.301354;
	ImagePortionX2->WinLeft = 0.003516;
	ImagePortionX2->WinWidth = 0.083203;
	ImagePortionX2->WinHeight = 0.04;
	ImagePortionX2->TabOrder = 9;
	//ImagePortionX2->OnDeActivate=ImagePortionX2.ValidateValue;
	//ImagePortionX2->OnChange=TestImagePage.ChangePortion;
	UGUINumericEdit* ImagePortionY1 = NewObject<UGUINumericEdit>(UGUINumericEdit::StaticClass());
	ImagePortionY1->MinValue = -1;
	ImagePortionY1->MaxValue = 1024;
	ImagePortionY1->Step = 10;
	ImagePortionY1->WinTop = 0.261354;
	ImagePortionY1->WinLeft = 0.003516;
	ImagePortionY1->WinWidth = 0.083203;
	ImagePortionY1->WinHeight = 0.04;
	ImagePortionY1->TabOrder = 8;
	//ImagePortionY1->OnDeActivate=ImagePortionY1.ValidateValue;
	//ImagePortionY1->OnChange=TestImagePage.ChangePortion;
	UGUINumericEdit* ImagePortionX1 = NewObject<UGUINumericEdit>(UGUINumericEdit::StaticClass());
	ImagePortionX1->MinValue = -1;
	ImagePortionX1->MaxValue = 1024;
	ImagePortionX1->Step = 10;
	ImagePortionX1->WinTop = 0.221354;
	ImagePortionX1->WinLeft = 0.003516;
	ImagePortionX1->WinWidth = 0.083203;
	ImagePortionX1->WinHeight = 0.04;
	ImagePortionX1->TabOrder = 7;
	//ImagePortionX1->OnDeActivate=ImagePortionX1.ValidateValue;
	//ImagePortionX1->OnChange=TestImagePage.ChangePortion;
	UGUINumericEdit* ImageHeight = NewObject<UGUINumericEdit>(UGUINumericEdit::StaticClass());
	ImageHeight->MinValue = 10;
	ImageHeight->MaxValue = 758;
	ImageHeight->Step = 10;
	ImageHeight->WinLeft = 0.838672;
	ImageHeight->WinWidth = 0.069531;
	ImageHeight->WinHeight = 0.04;
	ImageHeight->TabOrder = 3;
	//ImageHeight->OnDeActivate=ImageHeight.ValidateValue;
	//ImageHeight->OnChange=TestImagePage.ResizeImage;
	UGUINumericEdit* ImageWidth = NewObject<UGUINumericEdit>(UGUINumericEdit::StaticClass());
	ImageWidth->MinValue = 10;
	ImageWidth->MaxValue = 1014;
	ImageWidth->Step = 10;
	ImageWidth->WinLeft = 0.731055;
	ImageWidth->WinWidth = 0.107617;
	ImageWidth->WinHeight = 0.04;
	ImageWidth->TabOrder = 2;
	//ImageWidth->OnDeActivate=ImageWidth.ValidateValue;
	//ImageWidth->OnChange=TestImagePage.ResizeImage;
	UmoComboBox* ImageRenderStyle = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	ImageRenderStyle->bReadOnly = true;
	ImageRenderStyle->CaptionWidth = 0.1;
	ImageRenderStyle->Caption = "Render Style";
	//ImageRenderStyle->OnCreateComponent=ImageRenderStyle.InternalOnCreateComponent;
	ImageRenderStyle->WinTop = 0.045;
	ImageRenderStyle->WinLeft = 0.480469;
	ImageRenderStyle->WinWidth = 0.326172;
	ImageRenderStyle->WinHeight = 0.04;
	ImageRenderStyle->TabOrder = 6;
	//ImageRenderStyle->OnChange=TestImagePage.InternalOnChange;
	UmoComboBox* ImageAlign = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	ImageAlign->bReadOnly = true;
	ImageAlign->CaptionWidth = 0.1;
	ImageAlign->Caption = "Align";
	//ImageAlign->OnCreateComponent=ImageAlign.InternalOnCreateComponent;
	ImageAlign->WinTop = 0.045;
	ImageAlign->WinLeft = 0.265625;
	ImageAlign->WinWidth = 0.208984;
	ImageAlign->WinHeight = 0.04;
	ImageAlign->TabOrder = 5;
	//ImageAlign->OnChange=TestImagePage.OnNewImgAlign;
	UmoComboBox* ImageStyle = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	ImageStyle->bReadOnly = true;
	ImageStyle->CaptionWidth = 0.1;
	ImageStyle->Caption = "Image Style";
	//ImageStyle->OnCreateComponent=ImageStyle.InternalOnCreateComponent;
	ImageStyle->WinTop = 0.045;
	ImageStyle->WinLeft = 0;
	ImageStyle->WinWidth = 0.25;
	ImageStyle->WinHeight = 0.04;
	ImageStyle->TabOrder = 4;
	//ImageStyle->OnChange=TestImagePage.OnNewImgStyle;
	UGUIButton* AddImage = NewObject<UGUIButton>(UGUIButton::StaticClass());
	AddImage->Caption = "Add";
	AddImage->WinLeft = 0.539258;
	AddImage->WinWidth = 0.050273;
	AddImage->TabOrder = 1;
	//AddImage->OnClick=TestImagePage.InternalOnClick;
	//AddImage->OnKeyEvent=AddImage.InternalOnKeyEvent;
	UmoComboBox* SelectImage = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	SelectImage->CaptionWidth = 0.1;
	SelectImage->Caption = "Select Image";
	//SelectImage->OnCreateComponent=SelectImage.InternalOnCreateComponent;
	SelectImage->WinTop = 0;
	SelectImage->WinLeft = 0;
	SelectImage->WinWidth = 0.538086;
	SelectImage->WinHeight = 0.04;
	SelectImage->TabOrder = 0;
	//SelectImage->OnChange=TestImagePage.OnNewImgSelect;
	UGUIImage* TheImage = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TheImage->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	TheImage->WinTop = 0.115365;
	TheImage->WinLeft = 0.088281;
	TheImage->WinWidth = 0.6;
	TheImage->WinHeight = 0.976563;
	TheImage->RenderWeight = 0.4;
	UGUILabel* ImageDims = NewObject<UGUILabel>(UGUILabel::StaticClass());
	ImageDims->FontScale = EFontScale::FNS_Small;
	ImageDims->StyleName = "TextLabel";
	ImageDims->WinLeft = 0.594336;
	ImageDims->WinWidth = 0.121289;
	ImageDims->WinHeight = 0.04;
	i_Test = TheImage;
	co_Style = ImageStyle;
	co_Align = ImageAlign;
	co_Select = SelectImage;
	co_Render = ImageRenderStyle;
	nu_Width = ImageWidth;
	nu_Height = ImageHeight;
	nu_PortionX1 = ImagePortionX1;
	nu_PortionX2 = ImagePortionX2;
	nu_PortionY1 = ImagePortionY1;
	nu_PortionY2 = ImagePortionY2;
	b_Add = AddImage;
	l_ImageSize = ImageDims;
	Images = { "PlayerPictures.cEgyptFemaleBA","InterfaceContent.Menu.bg07","2K4Menus.Controls.menuBackground2","2K4Menus.Controls.popupBorder_b","2K4Menus.Controls.editbox2_b" };
	//OnOpen = TestImagePage.InternalOnOpen;
	//OnRendered = TestImagePage.InternalOnRendered;
}

void UTestImagePage::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
	//Background = Controller.DefaultPens[1];
}

bool UTestImagePage::InternalOnClick(UGUIComponent* Sender)
{
	/*
	FString S = "";
	local Material M;
	if (Sender == b_Add)
	{
		S = co_Select.GetText();
		if (co_Select.FindIndex(S) == -1)
		{
			M = LoadTexture(S);
			if (M != None)
			{
				co_Select.addItem(S);
				Images[Images.Length] = S;
				SaveConfig();
				SetNewImage(S);
			}
		}
	}
	*/
	return true;
}

void UTestImagePage::InternalOnOpen()
{
	/*
	int32 i = 0;
	co_Style.addItem("Normal");
	co_Style.addItem("Stretched");
	co_Style.addItem("Scaled");
	co_Style.addItem("Bound");
	co_Style.addItem("Justified");
	co_Style.addItem("PartialScaled");
	co_Align.addItem("TopLeft");
	co_Align.addItem("Center");
	co_Align.addItem("BottomRight");
	co_Render.addItem("None");
	co_Render.addItem("Normal");
	co_Render.addItem("Masked");
	co_Render.addItem("Translucent");
	co_Render.addItem("Modulated");
	co_Render.addItem("Alpha");
	co_Render.addItem("Additive");
	co_Render.addItem("Subtractive");
	co_Render.addItem("Particle");
	co_Render.addItem("AlphaZ");
	for (i = 0; i < Images.Length; i++)
	{
		co_Select.addItem(Images[i]);
	}
	SetNewImage(co_Select.MyComboBox.List.Get(true));
	co_Render.SetIndex(1);
	co_Style.SetIndex(0);
	co_Align.SetIndex(0);
	nu_PortionX1.SetValue(-1);
	nu_PortionY1.SetValue(-1);
	nu_PortionX2.SetValue(-1);
	nu_PortionY2.SetValue(-1);
	*/
}

void UTestImagePage::InternalOnRendered(UCanvas* C)
{
	/*
	if (i_Test.bPositioned)
	{
		nu_Width.Value = string(i_Test.ActualWidth());
		nu_Height.Value = string(i_Test.ActualHeight());
		__OnRendered__Delegate = None;
	}
	*/
}

void UTestImagePage::OnNewImgStyle(UGUIComponent* Sender)
{
	/*
	FString NewImgStyle = "";
	NewImgStyle = co_Style.GetText();
	switch (NewImgStyle)
	{
	case "Normal":
		i_Test.ImageStyle = 0;
		break;
	case "Stretched":
		i_Test.ImageStyle = 1;
		break;
	case "Scaled":
		i_Test.ImageStyle = 2;
		break;
	case "Bound":
		i_Test.ImageStyle = 3;
		break;
	case "Justified":
		i_Test.ImageStyle = 4;
		break;
	case "PartialScaled":
		i_Test.ImageStyle = 5;
		break;
	default:
	}
	*/
}

void UTestImagePage::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Sender == co_Render)
	{
		switch (co_Render.GetText())
		{
		case "None":
			i_Test.ImageRenderStyle = 0;
			break;
		case "Normal":
			i_Test.ImageRenderStyle = 1;
			break;
		case "Masked":
			i_Test.ImageRenderStyle = 2;
			break;
		case "Translucent":
			i_Test.ImageRenderStyle = 3;
			break;
		case "Modulated":
			i_Test.ImageRenderStyle = 4;
			break;
		case "Alpha":
			i_Test.ImageRenderStyle = 5;
			break;
		case "Additive":
			i_Test.ImageRenderStyle = 6;
			break;
		case "Subtractive":
			i_Test.ImageRenderStyle = 7;
			break;
		case "Particle":
			i_Test.ImageRenderStyle = 8;
			break;
		case "AlphaZ":
			i_Test.ImageRenderStyle = 9;
			break;
		default:
		}
	}
	*/
}

void UTestImagePage::OnNewImgAlign(UGUIComponent* Sender)
{
	/*
	FString NewImgAlign = "";
	NewImgAlign = co_Align.GetText();
	if (NewImgAlign == "TopLeft")
	{
		i_Test.ImageAlign = 0;
	}
	else
	{
		if (NewImgAlign == "Center")
		{
			i_Test.ImageAlign = 1;
		}
		else
		{
			if (NewImgAlign == "BottomRight")
			{
				i_Test.ImageAlign = 2;
			}
		}
	}
	*/
}

void UTestImagePage::OnNewImgSelect(UGUIComponent* Sender)
{
	/*
	FString S = "";
	S = co_Select.GetText();
	if (co_Select.FindIndex(S) != -1)
	{
		SetNewImage(S);
	}
	*/
}

void UTestImagePage::SetNewImage(FString ImageName)
{
	/*
	i_Test.Image = LoadTexture(ImageName);
	if (i_Test.Image != None)
	{
		l_ImageSize.Caption = string(i_Test.Image.MaterialUSize()) $ "x" $ string(i_Test.Image.MaterialVSize());
	}
	*/
}

UMaterialInstance* UTestImagePage::LoadTexture(FString TextureFullName)
{
	//return Material(DynamicLoadObject(TextureFullName, Class'Material'));
	return nullptr;
}

void UTestImagePage::ResizeImage(UGUIComponent* Sender)
{
	/*
	if (Sender == nu_Width)
	{
		i_Test.WinWidth = i_Test.RelativeWidth(float(int(nu_Width.Value)));
	}
	else
	{
		i_Test.WinHeight = i_Test.RelativeHeight(float(int(nu_Height.Value)));
	}
	*/
}

void UTestImagePage::ChangePortion(UGUIComponent* Sender)
{
	/*
	switch (Sender)
	{
	case nu_PortionX1:
		i_Test.X1 = int(GUINumericEdit(Sender).Value);
		break;
	case nu_PortionX2:
		i_Test.X2 = int(GUINumericEdit(Sender).Value);
		break;
	case nu_PortionY1:
		i_Test.Y1 = int(GUINumericEdit(Sender).Value);
		break;
	case nu_PortionY2:
		i_Test.Y2 = int(GUINumericEdit(Sender).Value);
		break;
	default:
	}
	*/
}