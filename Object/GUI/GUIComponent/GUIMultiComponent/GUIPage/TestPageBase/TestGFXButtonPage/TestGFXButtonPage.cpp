// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/TestGFXButtonPage/TestGFXButtonPage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUICheckBoxButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIComboBox/GUIComboBox.h"

UTestGFXButtonPage::UTestGFXButtonPage()
{
	UGUICheckBoxButton* cbbClientBound = NewObject<UGUICheckBoxButton>(UGUICheckBoxButton::StaticClass());
	cbbClientBound->WinTop = 0.5;
	cbbClientBound->WinLeft = 0.75;
	cbbClientBound->WinWidth = 0.2;
	cbbClientBound->WinHeight = 0.06;
	//cbbClientBound->OnChange=TestGFXButtonPage.OnNewClientBound;
	//cbbClientBound->OnKeyEvent=cbbClientBound.InternalOnKeyEvent;
	UGUIComboBox* cboImgSelect = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	cboImgSelect->bReadOnly = true;
	cboImgSelect->WinTop = 0.4;
	cboImgSelect->WinLeft = 0.75;
	cboImgSelect->WinWidth = 0.2;
	//cboImgSelect->OnChange=TestGFXButtonPage.OnNewImgSelect;
	//cboImgSelect->OnKeyEvent=cboImgSelect.InternalOnKeyEvent;
	UGUIComboBox* cboImgAlign = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	cboImgAlign->bReadOnly = true;
	cboImgAlign->WinTop = 0.3;
	cboImgAlign->WinLeft = 0.75;
	cboImgAlign->WinWidth = 0.2;
	//cboImgAlign->OnChange=TestGFXButtonPage.OnNewImgAlign;
	//cboImgAlign->OnKeyEvent=cboImgAlign.InternalOnKeyEvent;
	UGUIComboBox* cboImgStyle = NewObject<UGUIComboBox>(UGUIComboBox::StaticClass());
	cboImgStyle->bReadOnly = true;
	cboImgStyle->WinTop = 0.2;
	cboImgStyle->WinLeft = 0.75;
	cboImgStyle->WinWidth = 0.2;
	//cboImgStyle->OnChange=TestGFXButtonPage.OnNewImgStyle;
	//cboImgStyle->OnKeyEvent=cboImgStyle.InternalOnKeyEvent;
	UGUIGFXButton* TheButton = NewObject<UGUIGFXButton>(UGUIGFXButton::StaticClass());
	TheButton->WinTop = 0.2;
	TheButton->WinLeft = 0.1;
	TheButton->WinWidth = 0.2;
	TheButton->WinHeight = 0.2;
	//TheButton->OnKeyEvent=TheButton.InternalOnKeyEvent;
	UGUIImage* Backdrop = NewObject<UGUIImage>(UGUIImage::StaticClass());
	Backdrop->ImageStyle = EImgStyle::ISTY_Bound;
	Backdrop->WinTop = 0.2;
	Backdrop->WinLeft = 0.1;
	Backdrop->WinWidth = 0.2;
	Backdrop->WinHeight = 0.2;
	UGUILabel* lblImgStyle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblImgStyle->Caption = "Image Style";
	lblImgStyle->WinTop = 0.2;
	lblImgStyle->WinLeft = 0.5;
	lblImgStyle->WinWidth = 0.2;
	UGUILabel* lblImgAlign = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblImgAlign->Caption = "Menu State";
	lblImgAlign->WinTop = 0.3;
	lblImgAlign->WinLeft = 0.5;
	lblImgAlign->WinWidth = 0.2;
	UGUILabel* lblImgSelect = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblImgSelect->Caption = "Select Image";
	lblImgSelect->WinTop = 0.4;
	lblImgSelect->WinLeft = 0.5;
	lblImgSelect->WinWidth = 0.2;
	UGUILabel* lblClientBound = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblClientBound->Caption = "Client Bound ?";
	lblClientBound->WinTop = 0.5;
	lblClientBound->WinLeft = 0.5;
	lblClientBound->WinWidth = 0.2;
	//OnOpen = TestGFXButtonPage.MyOnOpen;
	Controls = { Backdrop,TheButton,lblImgStyle,cboImgStyle,lblImgAlign,cboImgAlign,lblImgSelect,cboImgSelect,lblClientBound,cbbClientBound };
}

void UTestGFXButtonPage::MyOnOpen()
{
	/*
	Btn = GUIGFXButton(Controls[1]);
	ImgStyle = GUIComboBox(Controls[3]);
	ImgAlign = GUIComboBox(Controls[5]);
	ImgSelect = GUIComboBox(Controls[7]);
	ImgStyle.addItem("Normal");
	ImgStyle.addItem("Center");
	ImgStyle.addItem("Stretched");
	ImgStyle.addItem("Scaled");
	ImgStyle.addItem("Bound");
	ImgAlign.addItem("Blurry");
	ImgAlign.addItem("Watched");
	ImgAlign.addItem("Focused");
	ImgAlign.addItem("Pressed");
	ImgAlign.addItem("Disabled");
	*/
}

void UTestGFXButtonPage::OnNewImgStyle(UGUIComponent* Sender)
{
	/*
	FString NewImgStyle = "";
	NewImgStyle = ImgStyle.Get();
	if (NewImgStyle == "Normal")
	{
		Btn.Position = 0;
	}
	else
	{
		if (NewImgStyle == "Center")
		{
			Btn.Position = 1;
		}
		else
		{
			if (NewImgStyle == "Stretched")
			{
				Btn.Position = 3;
			}
			else
			{
				if (NewImgStyle == "Scaled")
				{
					Btn.Position = 2;
				}
				else
				{
					if (NewImgStyle == "Bound")
					{
						Btn.Position = 4;
					}
				}
			}
		}
	}
	*/
}

void UTestGFXButtonPage::OnNewImgAlign(UGUIComponent* Sender)
{
	/*
	FString NewImgAlign = "";
	NewImgAlign = ImgAlign.Get();
	if (NewImgAlign == "Blurry")
	{
		Btn.MenuState = 0;
	}
	else
	{
		if (NewImgAlign == "Watched")
		{
			Btn.MenuState = 1;
		}
		else
		{
			if (NewImgAlign == "Focused")
			{
				Btn.MenuState = 2;
			}
			else
			{
				if (NewImgAlign == "Pressed")
				{
					Btn.MenuState = 3;
				}
				else
				{
					if (NewImgAlign == "Disabled")
					{
						Btn.MenuState = 4;
					}
				}
			}
		}
	}
	*/
}

void UTestGFXButtonPage::OnNewImgSelect(UGUIComponent* Sender)
{
	//SetNewImage(ImgSelect.Get());
}

void UTestGFXButtonPage::OnNewClientBound(UGUIComponent* Sender)
{
	//Btn.bClientBound = GUICheckBoxButton(Sender).bChecked;
}

void UTestGFXButtonPage::SetNewImage(FString ImageName)
{
	Btn->Graphic = DLOTexture(ImageName);
}

UMaterialInstance* UTestGFXButtonPage::DLOTexture(FString TextureFullName)
{
	//return Material(DynamicLoadObject(TextureFullName, Class'Material'));
	return nullptr;
}