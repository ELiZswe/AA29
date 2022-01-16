// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/InfoPageBase/InfoPageBase.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIListBoxBase/GUIScrollTextBox/GUIScrollTextBox.h"

UInfoPageBase::UInfoPageBase()
{
	UGUIScrollTextBox* infobox = NewObject<UGUIScrollTextBox>(UGUIScrollTextBox::StaticClass());
	infobox->CharDelay = 0.0015;
	infobox->EOLDelay = 0.25;
	infobox->bVisibleWhenEmpty = true;
	//infobox->OnCreateComponent=infobox.InternalOnCreateComponent;
	infobox->FontScale = EeFontScale::FNS_Small;
	infobox->StyleName = "SmallText";
	infobox->WinTop = 0.2;
	infobox->WinLeft = 0.1;
	infobox->WinWidth = 0.8;
	infobox->WinHeight = 0.6;
	infobox->RenderWeight = 0.51;
	infobox->TabOrder = 0;
	infobox->bAcceptsInput = false;
	infobox->bNeverFocus = true;
	lb_Info = infobox;

}

void UInfoPageBase::HandleParameters(FString Param1, FString Param2)
{
	/*
	FString Directory = "";
	FString File = "";
	Super::HandleParameters(Param1, Param2);
	t_WindowTitle.SetCaption(Param2);
	Param2 = ReplaceSpaces(Param2);
	Directory = GetBaseDir() $ "Descriptions\\";
	File = "Mod_" $ Param2 $ ".txt";
	if (AAGUIController(Controller) != nullptr)
	{
		lb_Info.SetContent(AAGUIController(Controller).LoadTextFromFile(Directory $ File));
	}
	*/
}

FString UInfoPageBase::ReplaceSpaces(FString S)
{
	/*
	int32 i = 0;
	FString Temp = "";
	i = InStr(S, " ");
	if (i != -1)
	{
		Temp = Left(S, i) $ "_" $ Mid(S, (i + 1), Len(S));
		S = Temp;
		i = InStr(S, " ");
	}
	*/
	return S;
}