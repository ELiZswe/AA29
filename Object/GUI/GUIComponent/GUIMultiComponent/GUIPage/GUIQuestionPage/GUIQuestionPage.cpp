// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIQuestionPage/GUIQuestionPage.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/FloatingImage/FloatingImage.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UGUIQuestionPage::UGUIQuestionPage()
{
	UFloatingImage* imgBack = NewObject<UFloatingImage>(UFloatingImage::StaticClass());
	imgBack->Image = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindo_Mat.field_tabwindo_Mat'"), NULL, LOAD_None, NULL);
	imgBack->ImageStyle = EImgStyle::ISTY_Stretched;
	imgBack->ImageRenderStyle = EMenuRenderStyle::MSTY_Normal;
	imgBack->WinTop = 0;
	imgBack->WinLeft = 0;
	imgBack->WinWidth = 1;
	imgBack->WinHeight = 1;
	UGUILabel* lblQuestion = NewObject<UGUILabel>(UGUILabel::StaticClass());
	lblQuestion->bMultiLine = true;
	lblQuestion->WinTop = 0.2;
	lblQuestion->WinLeft = 0.1;
	lblQuestion->WinWidth = 0.8;
	lblQuestion->WinHeight = 0.4;
	ButtonNames = { "Ok","Cancel","Retry","Continue","Yes","No","Abort","Ignore" };
	bRenderWorld = true;
	bRequire640x480 = false;
	Controls = { imgBack,lblQuestion };
	WinTop = 0.3;
	WinLeft = 0.125;
	WinWidth = 0.75;
	WinHeight = 0.38;
	//OnPreDraw = GUIQuestionPage.InternalOnPreDraw;
}

void UGUIQuestionPage::OnButtonClick(uint8 bButton)
{
}

bool UGUIQuestionPage::NewOnButtonClick(uint8 bButton)
{
	return true;
}

void UGUIQuestionPage::InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(pMyController, MyOwner);
	lMessage = GUILabel(Controls[1]);
	ParentPage.InactiveFadeColor = Class'Canvas'.MakeColor(128, 128, 128, 255);
	*/
}

bool UGUIQuestionPage::InternalOnPreDraw(UCanvas* C)
{
	/*
	float XL = 0;
	float YL = 0;
	int32 i = 0;
	local TArray<FString> MsgArray;
	if (lMessage.TextFont != "")
	{
		C.Font = Controller.GetMenuFont(lMessage.TextFont).GetFont(C.SizeX);
	}
	C.TextSize("W", XL, YL);
	C.WrapStringToArray(lMessage.Caption, MsgArray, lMessage.ActualWidth(), "|");
	YL *= float(MsgArray.Length);
	if (lMessage.Style != None)
	{
		YL += float((lMessage.Style.BorderOffsets[1] + lMessage.Style.BorderOffsets[3]));
	}
	lMessage.WinHeight = ((YL + 1) / float(C.SizeY));
	WinHeight = (((YL + Buttons[0].ActualHeight()) + float(60)) / float(C.SizeY));
	WinTop = ((float(C.SizeY) - ActualHeight()) / 2);
	lMessage.WinTop = (WinTop + float(20));
	for (i = 0; i < Buttons.Length; i++)
	{
		Buttons[i].WinTop = ((WinTop + float(40)) + YL);
	}
	__OnPreDraw__Delegate = None;
	*/
	return false;
}

void UGUIQuestionPage::SetupQuestion(FString Question, uint8 bButtons, uint8 ActiveButton, bool bClearFirst)
{
	/*
	if (lMessage != None)
	{
		lMessage.Caption = Question;
	}
	if (bClearFirst)
	{
		RemoveButtons();
	}
	AddButton(byte((bButtons & 16)));
	AddButton(byte((bButtons & 32)));
	AddButton(byte((bButtons & 1)));
	AddButton(byte((bButtons & 64)));
	AddButton(byte((bButtons & 4)));
	AddButton(byte((bButtons & 8)));
	CancelButton = AddButton(byte((bButtons & 2)));
	AddButton(byte((bButtons & 128)));
	LayoutButtons(ActiveButton);
	*/
}

UGUIButton* UGUIQuestionPage::AddButton(uint8 idesc)
{
	UGUIButton* Btn = nullptr;
	/*
	uint8 Mask = 0;
	int32 cnt = 0;
	if (idesc == 0)
	{
		return None;
	}
	Mask = 1;
	if (!bool((Mask & idesc)))
	{
		cnt++;
		Mask = byte((Mask << 1));
	}
	if (cnt >= ButtonNames.Length)
	{
		Log("GUIQuestionPage.AddButton() button mask was larger than button name array!");
		return None;
	}
	Btn = GUIButton(AddComponent("XInterface.GUIButton"));
	if (Btn == None)
	{
		return None;
	}
	Btn.Tag = idesc;
	Btn.TabOrder = Components.Length;
	Btn.Caption = ButtonNames[cnt];
	Btn.__OnClick__Delegate = ButtonClick;
	Buttons[Buttons.Length] = Btn;
	*/
	return Btn;
}

void UGUIQuestionPage::LayoutButtons(uint8 ActiveButton)
{
	/*
	int32 i = 0;
	float Left = 0;
	float colw = 0;
	float btnw = 0;
	colw = (1 / float((Buttons.Length + 1)));
	btnw = (colw * 0.66);
	Left = (colw - (btnw / 2));
	for (i = 0; i < Buttons.Length; i++)
	{
		Buttons[i].WinLeft = Left;
		Buttons[i].WinWidth = btnw;
		Buttons[i].WinHeight = 0.036;
		Buttons[i].WinTop = 0.6;
		Left += colw;
		if (bool((Buttons[i].Tag & ActiveButton)))
		{
			Buttons[i].SetFocus(None);
		}
	}
	*/
}

bool UGUIQuestionPage::ButtonClick(UGUIComponent* Sender)
{
	/*
	int32 t = 0;
	local GUIController C;
	C = Controller;
	t = GUIButton(Sender).Tag;
	ParentPage.InactiveFadeColor = ParentPage.Default.InactiveFadeColor;
	OnButtonClick(byte(t));
	if (NewOnButtonClick(byte(t)))
	{
		C.CloseMenu(bool((t & (2 | 64))));
	}
	*/
	return true;
}

FString UGUIQuestionPage::Replace(FString Src, FString aTag, FString Value)
{
	/*
	if (Left(aTag, 1) != "%")
	{
		aTag = "%" $ aTag;
	}
	if (Right(aTag, 1) != "%")
	{
		(aTag $ = "%");
	}
	return Repl(Src, aTag, Value);
	*/
	return "FAKE";    //FAKE    /ELiZ
}

void UGUIQuestionPage::RemoveButtons()
{
	/*
	int32 i = 0;
	for (i = 0; i < Buttons.Length; i++)
	{
		RemoveComponent(Buttons[i], true);
	}
	if (Buttons.Length > 0)
	{
		Buttons.remove(0, Buttons.Length);
	}
	RemapComponents();
	*/
}