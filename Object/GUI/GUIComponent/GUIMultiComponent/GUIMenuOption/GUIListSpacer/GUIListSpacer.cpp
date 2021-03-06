// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/GUIListSpacer/GUIListSpacer.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UGUIListSpacer::UGUIListSpacer()
{
	CaptionWidth = 1;
	ComponentWidth = 0;
	ComponentClassName = "XInterface.GUILabel";
	StyleName = "NoBackground";
	Tag = -2;
	bNeverFocus = true;
	OnClickSound = EClickSound::CS_None;
}

void UGUIListSpacer::InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender)
{
	/*
	if ((Sender == this) && (Cast<UGUILabel>(NewComp) != nullptr))
	{
		NewComp.FontScale = FontScale;
	}
	Super::InternalOnCreateComponent(NewComp, Sender);
	*/
}
