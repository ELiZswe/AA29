// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moNumericEdit/moFormatNumEdit/moFormatNumEdit.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UmoFormatNumEdit::UmoFormatNumEdit()
{
	ComponentClassName = "XInterface.GUIFormatNumEdit";
}

FString UmoFormatNumEdit::FormatValue(int32 NewValue)
{
	//return "$ " + FString::FromInt(NewValue);
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
