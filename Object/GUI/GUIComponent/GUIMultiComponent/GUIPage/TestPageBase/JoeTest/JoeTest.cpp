// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/TestPageBase/JoeTest/JoeTest.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUINumericEdit/GUINumericEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UJoeTest::UJoeTest()
{
	UGUIEditBox* TestNumEdit2 = NewObject<UGUIEditBox>(UGUIEditBox::StaticClass());
	TestNumEdit2->IniOption = "ini:Engine.Engine.RenderDevice HighDetailActors";
	TestNumEdit2->WinTop = 0.6;
	TestNumEdit2->WinLeft = 0.25;
	TestNumEdit2->WinWidth = 0.5;
	//TestNumEdit2->OnActivate=TestNumEdit2.InternalActivate;
	//TestNumEdit2->OnDeActivate=TestNumEdit2.InternalDeactivate;
	//TestNumEdit2->OnKeyType=TestNumEdit2.InternalOnKeyType;
	//TestNumEdit2->OnKeyEvent=TestNumEdit2.InternalOnKeyEvent;
	UGUINumericEdit* TestNumEdit = NewObject<UGUINumericEdit>(UGUINumericEdit::StaticClass());
	TestNumEdit->MinValue = 0;
	TestNumEdit->MaxValue = 999;
	TestNumEdit->WinTop = 0.4;
	TestNumEdit->WinLeft = 0.25;
	TestNumEdit->WinWidth = 0.125;
	//TestNumEdit->OnDeActivate=TestNumEdit.ValidateValue;
	UGUIButton* TestButton1 = NewObject<UGUIButton>(UGUIButton::StaticClass());
	TestButton1->Caption = "Close Window";
	TestButton1->WinTop = 0.25;
	TestButton1->WinLeft = 0.25;
	TestButton1->WinWidth = 0.5;
	//TestButton1->OnKeyEvent=TestButton1.InternalOnKeyEvent;
	UGUIImage* TitleStrip = NewObject<UGUIImage>(UGUIImage::StaticClass());
	TitleStrip->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBox_Mat.BorderBox_Mat'"), NULL, LOAD_None, NULL);
	TitleStrip->ImageStyle = EImgStyle::ISTY_Stretched;
	TitleStrip->WinTop = 0.05;
	TitleStrip->WinLeft = 0.05;
	TitleStrip->WinWidth = 0.9;
	TitleStrip->WinHeight = 0.125;
	UGUILabel* TitleText = NewObject<UGUILabel>(UGUILabel::StaticClass());
	TitleText->Caption = "Joe's Amazing Test GUI";
	TitleText->TextAlign = ETextAlign::TXTA_Center;
	TitleText->TextColor = FColor(128, 255, 0, 255);
	TitleText->TextFont = "UT2LargeFont";
	TitleText->WinTop = 0.05;
	TitleText->WinLeft = 0.05;
	TitleText->WinWidth = 0.9;
	TitleText->WinHeight = 0.125;
	bCheckResolution = true;
	Controls = {TitleStrip, TitleText, TestButton1, TestNumEdit, TestNumEdit2};
	WinHeight = 1;
}

void UJoeTest::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	//Super::InitComponent(MyController, MyOwner);
	//Controls[2].__OnClick__Delegate = OnClick1;
}

bool UJoeTest::OnClick1(UGUIComponent* Sender)
{
	//Controller.OpenMenu("xinterface.joetestB");
	return true;
}

bool UJoeTest::OnClick2(UGUIComponent* Sender)
{
	return true;
}