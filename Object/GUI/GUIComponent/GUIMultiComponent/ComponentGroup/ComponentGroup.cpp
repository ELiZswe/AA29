// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/ComponentGroup/ComponentGroup.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/GUISectionBackground.h"

UComponentGroup::UComponentGroup()
{
	UGUISectionBackground* CGBackground = NewObject<UGUISectionBackground>(UGUISectionBackground::StaticClass());
	CGBackground->WinHeight = 1;
	CGBackground->bBoundToParent = true;
	CGBackground->bScaleToParent = true;
	//CGBackground->OnPreDraw=CGBackground.InternalPreDraw;
	i_Background = CGBackground;
}

void UComponentGroup::InitComponent(UGUIController* InController, UGUIComponent* InOwner)
{
	//InitComponent(InController, InOwner);
	//SetCaption(Caption);
}

UGUIComponent* UComponentGroup::ManageComponent(UGUIComponent* C)
{
	/*
	if (C != None)
	{
		i_Background.ManageComponent(C);
	}
	*/
	return C;
}

void UComponentGroup::AppendComponent(UGUIComponent* NewComp, bool bSkipRemap)
{
	//Return ManageComponent(AppendComponent(NewComp, bSkipRemap));
}

void UComponentGroup::InsertComponent(UGUIComponent* NewComp, int32 Index, bool bSkipRemap)
{
	//Return ManageComponent(InsertComponent(NewComp, Index, bSkipRemap));
}

void UComponentGroup::RemoveComponent(UGUIComponent* Comp, bool bSkipRemap)
{
	//i_Background.UnmanageComponent(Comp);
	//Return RemoveComponent(Comp, bSkipRemap);
}

void UComponentGroup::SetCaption(FString NewCaption)
{
	//Caption = NewCaption;
	//i_Background.Caption = Caption;
}