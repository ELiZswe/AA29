// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moFormatNumEdit/moFormatNumEdit.h"

UmoFormatNumEdit::UmoFormatNumEdit()
{
	ComponentClassName = "XInterface.GUIFormatNumEdit";
}

FString UmoFormatNumEdit::FormatValue(int32 NewValue)
{
	//return "$ " $ string(NewValue);
	return "FAKE";    //FAKE  /ELiZ
}

void UmoFormatNumEdit::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	GUIFormatNumEdit(MyNumericEdit).__FormatValue__Delegate = InternalFormatValue;
	*/
}

FString UmoFormatNumEdit::InternalFormatValue(int32 NewValue)
{
	return FormatValue(NewValue);
}
