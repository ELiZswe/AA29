// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/ComponentGroup/ComponentGroup.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/GUISectionBackground.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

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
	Super::InitComponent(InController, InOwner);
	SetCaption(Caption);
}

UGUIComponent* UComponentGroup::ManageComponent(UGUIComponent* C)
{
	if (C != nullptr)
	{
		i_Background->ManageComponent(C);
	}
	return C;
}

UGUIComponent* UComponentGroup::AppendComponent(UGUIComponent* NewComp, bool bSkipRemap)
{
	return ManageComponent(Super::AppendComponent(NewComp, bSkipRemap));
}

UGUIComponent* UComponentGroup::InsertComponent(UGUIComponent* NewComp, int32 Index, bool bSkipRemap)
{
	return ManageComponent(Super::InsertComponent(NewComp, Index, bSkipRemap));
}

bool UComponentGroup::RemoveComponent(UGUIComponent* Comp, bool bSkipRemap)
{
	i_Background->UnmanageComponent(Comp);
	return Super::RemoveComponent(Comp, bSkipRemap);
}

void UComponentGroup::SetCaption(FString NewCaption)
{
	Caption = NewCaption;
	i_Background->Caption = Caption;
}
