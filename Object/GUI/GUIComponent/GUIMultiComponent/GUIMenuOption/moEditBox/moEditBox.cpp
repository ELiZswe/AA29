// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIEditBox/GUIEditBox.h"

UmoEditBox::UmoEditBox()
{
	ComponentClassName = "XInterface.GUIEditBox";
}

void UmoEditBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyEditBox = GUIEditBox(MyComponent);
	ReadOnly((bReadOnly || bValueReadOnly));
	MaskText(bMaskText);
	*/
}

void UmoEditBox::SetComponentValue(FString NewValue, bool bNoChange)
{
	if (bNoChange)
	{
		bIgnoreChange = true;
	}
	SetText(NewValue);
	bIgnoreChange = false;
}

FString UmoEditBox::GetComponentValue()
{
	return GetText();
}

FString UmoEditBox::GetText()
{
	return MyEditBox->GetText();
}

void UmoEditBox::SetText(FString NewText)
{
	MyEditBox->SetText(NewText);
}

void UmoEditBox::ReadOnly(bool B)
{
	SetReadOnly(B);
}

void UmoEditBox::SetReadOnly(bool B)
{
	//Super::SetReadOnly(B);
	MyEditBox->bReadOnly = B;
}

void UmoEditBox::IntOnly(bool B)
{
	MyEditBox->bIntOnly = B;
}

void UmoEditBox::FloatOnly(bool B)
{
	MyEditBox->bFloatOnly = B;
}

void UmoEditBox::MaskText(bool B)
{
	MyEditBox->bMaskText = B;
}