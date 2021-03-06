// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIContextMenu/GUIContextMenu.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIMultiComponent::UGUIMultiComponent()
{
	bDrawFocusedLast = true;
	bTabStop = true;
}

bool UGUIMultiComponent::HandleContextMenuOpen(UGUIComponent* Sender, UGUIContextMenu* Menu, UGUIComponent* ContextMenuOwner)
{
	return true;
}

bool UGUIMultiComponent::HandleContextMenuClose(UGUIContextMenu* Sender)
{
	return true;
}

bool UGUIMultiComponent::NotifyContextSelect(UGUIContextMenu* Sender, int32 ClickIndex)
{
	return false;
}

void UGUIMultiComponent::OnCreateComponent(UGUIComponent* NewComponent, UGUIComponent* Sender)
{
}

//native final Function InitializeControls();
void UGUIMultiComponent::InitializeControls()
{

}

//native final Function RemapComponents();
void UGUIMultiComponent::RemapComponents()
{

}

//native final Function FindComponentIndex(UGUIComponent* Who);
void UGUIMultiComponent::FindComponentIndex(UGUIComponent* Who)
{

}

void UGUIMultiComponent::InternalOnShow()
{
}

void UGUIMultiComponent::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	int32 i = 0;
	InitComponent(MyController, MyOwner);
	InitializeControls();
	for (i = 0; i < Controls.Num(); i++)
	{
		if (Controls[i] == nullptr)
		{
			if (Controller.bModAuthor)
			{
				Log(Name @ "- Invalid control found in" @ GetMenuPath() + "!! (Control" @ i + ")", 'ModAuthor');
			}
			Controls.RemoveAt(i--, 1);
		}
		else
		{
			OnCreateComponent(Controls[i], this);
			Controls[i].InitComponent(MyController, this);
		}
	}
	RemapComponents();
	*/
}

UGUIComponent* UGUIMultiComponent::AddComponent(FString ComponentClass, bool SkipRemap)
{
	UGUIComponent* NewCompClass = nullptr;
	UGUIComponent* NewComp = nullptr;
	/*
	if (Controller != nullptr)
	{
		NewCompClass = Controller.AddComponentClass(ComponentClass);
	}
	else
	{
		NewCompClass = class<GUIComponent>(DynamicLoadObject(ComponentClass, Class'Class'));
	}
	if (NewCompClass != nullptr)
	{
		NewComp = new (None) classNewCompClass;
		if (NewComp != nullptr)
		{
			NewComp = AppendComponent(NewComp, SkipRemap);
			return NewComp;
		}
	}
	Log(Name @ "could not create component" @ ComponentClass, 'AddComponent');
	*/
	return nullptr;
}

UGUIComponent* UGUIMultiComponent::InsertComponent(UGUIComponent* NewComp, int32 Index, bool SkipRemap)
{
	/*
	if (Index < 0 || Index >= Controls.Num())
	{
		return AppendComponent(NewComp);
	}
	Controls.insert(Index, 1);
	Controls[Index] = NewComp;
	if (!SkipRemap)
	{
		RemapComponents();
	}
	*/
	return NewComp;
}

UGUIComponent* UGUIMultiComponent::AppendComponent(UGUIComponent* NewComp, bool SkipRemap)
{
	int32 Index = 0;
	/*
	if (Index < Controls.Num())
	{
		if (NewComp.RenderWeight < Controls[Index].RenderWeight)
		{
			Controls.insert(Index, 1);
		}
		else
		{
			Index++;
		}
	}
	Controls[Index] = NewComp;
	OnCreateComponent(NewComp, this);
	if (NewComp.Controller == nullptr)
	{
		NewComp.InitComponent(Controller, this);
	}
	if (!SkipRemap)
	{
		RemapComponents();
	}
	if (Controller.bCurMenuInitialized)
	{
		NewComp.Opened(this);
	}
	*/
	return NewComp;
}

bool UGUIMultiComponent::RemoveComponent(UGUIComponent* Comp, bool SkipRemap)
{
	int32 i = 0;
	/*
	for (i = 0; i < Controls.Num(); i++)
	{
		if (Controls[i] == Comp)
		{
			Controls.RemoveAt(i, 1);
			if (!SkipRemap)
			{
				RemapComponents();
			}
			return true;
		}
	}
	*/
	return false;
}

void UGUIMultiComponent::SetFocusInstead(UGUIComponent* InFocusComp)
{
	int32 i = 0;
	/*
	SetFocusInstead(InFocusComp);
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].SetFocusInstead(InFocusComp);
	}
	*/
}

void UGUIMultiComponent::SetFocus(UGUIComponent* Who)
{
	/*
	if (Who == nullptr)
	{
		if (!FocusFirst(None))
		{
			SetFocus(nullptr);
		}
		return;
	}
	else
	{
		FocusedControl = Who;
	}
	MenuStateChange(2);
	if (MenuOwner != nullptr)
	{
		MenuOwner.SetFocus(this);
	}
	*/
}

void UGUIMultiComponent::LoseFocus(UGUIComponent* Sender)
{
	//FocusedControl = nullptr;
	//LoseFocus(Sender);
}

bool UGUIMultiComponent::CanAcceptFocus()
{
	int32 i = 0;
	/*
	if (bAcceptsInput && CanAcceptFocus())
	{
		return true;
	}
	for (i = 0; i < Controls.Num(); i++)
	{
		if (Controls[i].CanAcceptFocus())
		{
			return true;
		}
	}
	*/
	return false;
}

bool UGUIMultiComponent::FocusFirst(UGUIComponent* Sender)
{
	int32 i = 0;
	/*
	if (Components.Num() > 0)
	{
		for (i = 0; i < Components.Num(); i++)
		{
			if (Components[i].FocusFirst(Sender))
			{
				return true;
			}
		}
	}
	for (i = 0; i < Controls.Num(); i++)
	{
		if (Controls[i].FocusFirst(Sender))
		{
			return true;
		}
	}
	if (bAcceptsInput && CanAcceptFocus())
	{
		SetFocus(nullptr);
		return true;
	}
	*/
	return false;
}

bool UGUIMultiComponent::FocusLast(UGUIComponent* Sender)
{
	int32 i = 0;
	/*
	if (Components.Num() > 0)
	{
		for (i = Components.Num() - 1; i >= 0; i--)
		{
			if (Components[i].FocusLast(Sender))
			{
				return true;
			}
		}
	}
	for (i = Controls.Num() - 1; i >= 0; i--)
	{
		if (Controls[i].FocusLast(Sender))
		{
			return true;
		}
	}
	if (bAcceptsInput && CanAcceptFocus())
	{
		SetFocus(nullptr);
		return true;
	}
	*/
	return false;
}

bool UGUIMultiComponent::NextControl(UGUIComponent* Sender)
{
	int32 Index = 0;
	/*
	Index = FindComponentIndex(Sender);
	if (Index >= 0)
	{
		if (++Index < Components.Num())
		{
			if (Components[Index].FocusFirst(None))
			{
				return true;
			}
		}
	}
	if (NextControl(this))
	{
		return true;
	}
	*/
	return FocusFirst(nullptr);
}

bool UGUIMultiComponent::PrevControl(UGUIComponent* Sender)
{
	int32 Index = 0;
	/*
	Index = FindComponentIndex(Sender);
	if (--Index >= 0)
	{
		if (Components[Index].FocusLast(None))
		{
			return true;
		}
	}
	if (Super::PrevControl(this))
	{
		return true;
	}
	*/
	return FocusLast(nullptr);
}

void UGUIMultiComponent::EnableMe()
{
	int32 i = 0;
	Super::EnableMe();
	for (i = 0; i < Controls.Num(); i++)
	{
		EnableComponent(Controls[i]);
	}
}

void UGUIMultiComponent::DisableMe()
{
	int32 i = 0;
	Super::DisableMe();
	for (i = 0; i < Controls.Num(); i++)
	{
		DisableComponent(Controls[i]);
	}
}

void UGUIMultiComponent::SetVisibility(bool bIsVisible)
{
	int32 i = 0;
	Super::SetVisibility(bIsVisible);
	if (!PropagateVisibility)
	{
		return;
	}
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i]->SetVisibility(bIsVisible);
	}
}

void UGUIMultiComponent::Opened(UGUIComponent* Sender)
{
	int32 i = 0;
	if (Sender == nullptr)
	{
		Sender = this;
	}
	Super::Opened(Sender);
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i]->Opened(Sender);
	}
}

void UGUIMultiComponent::Closed(UGUIComponent* Sender, bool bCancelled)
{
	int32 i = 0;
	/*
	if (Sender == nullptr)
	{
		Sender = this;
	}
	Closed(Sender, bCancelled);
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].Closed(Sender, bCancelled);
	}
	*/
}

void UGUIMultiComponent::Free()
{
	int32 i = 0;
	/*
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].Free();
	}
	Controls.RemoveAt(0, Controls.Num());
	Components.RemoveAt(0, Components.Num());
	FocusedControl = nullptr;
	Super::Free();
	*/
}

void UGUIMultiComponent::BeginAnimation(UGUIComponent* Animating)
{
	/*
	AnimationCount++;
	if (AnimationCount > 0)
	{
		bAnimating = true;
	}
	if (MenuOwner != nullptr)
	{
		MenuOwner.BeginAnimation(Animating);
	}
	*/
}

void UGUIMultiComponent::EndAnimation(UGUIComponent* Animating, EAnimationType Type)
{
	/*
	AnimationCount--;
	if (AnimationCount <= 0)
	{
		bAnimating = false;
		AnimationCount = 0;
	}
	if (MenuOwner != nullptr)
	{
		MenuOwner.EndAnimation(Animating, Type);
	}
	if (Animating == this)
	{
		OnEndAnimation(Animating, Type);
	}
	*/
}

void UGUIMultiComponent::LevelChanged()
{
	/*
	int32 i = 0;
	LevelChanged();
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].LevelChanged();
	}
	*/
}

void UGUIMultiComponent::CenterMouse()
{
	/*
	int32 i = 0;
	if (FocusedControl != nullptr)
	{
		FocusedControl.CenterMouse();
		return;
	}
	for (i = 0; i < Components.Num(); i++)
	{
		if (Components[i].CanAcceptFocus())
		{
			Components[i].CenterMouse();
			return;
		}
	}
	CenterMouse();
	*/
}

void UGUIMultiComponent::DebugTabOrder()
{
	/*
	int32 i = 0;
	CheckInvalidTabOrder();
	CheckDuplicateTabOrder();
	for (i = 0; i < Controls.Num(); i++)
	{
		Controls[i].DebugTabOrder();
	}
	*/
}

void UGUIMultiComponent::CheckInvalidTabOrder()
{
	/*
	int32 i = 0;
	for (i = 0; i < Components.Num(); i++)
	{
		if (Components[i].TabOrder == -1)
		{
			Log(GetMenuPath() @ "Component[" + i + "] (" + Components[i].GetMenuPath() + ") has no tab order assigned!");
		}
	}
	*/
}

void UGUIMultiComponent::CheckDuplicateTabOrder()
{
	int32 i = 0;
	int32 j = 0;
	TArray<FIntBox> TabOrders ={};
	bool bDup = false;
	/*
	for (i = 0; i < Components.Num(); i++)
	{
		bDup = false;
		if (Components[i].TabOrder == -1)
		{
		}
		for (j = 0; j < TabOrders.Num(); j++)
		{
			if (Components[i].TabOrder == TabOrders[j].X2)
			{
				Log(GetMenuPath() @ "Dulicate tab order (" + Components[i].TabOrder + ") - components " + TabOrders[j].X1 + " (" + Components[TabOrders[j].X1].GetMenuPath() + ") & " + i + " (" + Components[i].GetMenuPath() + ")");
				bDup = true;
			}
		}
		if (!bDup)
		{
			j = TabOrders.Num();
			TabOrders.Num() = j + 1;
			TabOrders[j].X1 = j;
			TabOrders[j].X2 = Components[i].TabOrder;
		}
	}
	*/
}
