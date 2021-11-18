// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/AnimatedEditBox/AnimatedEditBox.h"

UAnimatedEditBox::UAnimatedEditBox()
{
	increment = 0.1;
	bAutoSizeCaption = false;
	CaptionWidth = 1;
	//OnActivate = AnimatedEditBox.InternalOnActivate;
	//OnDeActivate = AnimatedEditBox.InternalOnDeactivate;
}

bool UAnimatedEditBox::InternalOnPreDraw(UCanvas* C)
{
	/*
	(CaptionWidth += increment);
	MyEditBox.CaretPos = 0;
	if ((CaptionWidth <= 0) || (CaptionWidth >= 1))
	{
		__OnPreDraw__Delegate = None;
	}
	*/
	return true;
}

void UAnimatedEditBox::SetText(FString str)
{
	/*
	Super::SetText(str);
	if (bUseValueForCaption)
	{
		SetCaption(MyEditBox.GetText());
	}
	*/
}

void UAnimatedEditBox::InternalOnActivate()
{
	ShowEditBox();
}

void UAnimatedEditBox::InternalOnDeactivate()
{
	/*
	ShowLabel();
	if (bUpdated)
	{
		InternalOnChange(Self);
	}
	bUpdated = false;
	*/
}

void UAnimatedEditBox::ShowEditBox()
{
	/*
	if (CaptionWidth > 0)
	{
		if (increment > 0)
		{
			(increment *= -1);
		}
		__OnPreDraw__Delegate = InternalOnPreDraw;
	}
	*/
}

void UAnimatedEditBox::ShowLabel()
{
	/*
	if (CaptionWidth < 1)
	{
		if (increment < 0)
		{
			(increment *= -1);
		}
		__OnPreDraw__Delegate = InternalOnPreDraw;
	}
	*/
}

void UAnimatedEditBox::InternalOnChange(UGUIComponent* Sender)
{
	/*
	if (Controller.bCurMenuInitialized)
	{
		if (Sender != Self)
		{
			bUpdated = true;
		}
		if ((Sender == Self) || (MenuState != 2))
		{
			if (!bIgnoreChange)
			{
				if (bUseValueForCaption)
				{
					SetCaption(MyEditBox.GetText());
				}
				OnChange(Self);
			}
		}
	}
	bIgnoreChange = false;
	*/
}