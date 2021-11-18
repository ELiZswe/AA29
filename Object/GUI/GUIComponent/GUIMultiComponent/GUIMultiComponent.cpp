// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"

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
	local int32 i;
	InitComponent(MyController, MyOwner);
	InitializeControls();
	for (i = 0; i < Controls.Length; i++)
	{
		if (Controls[i] == None)
		{
			if (Controller.bModAuthor)
			{
				Log(Name @ "- Invalid control found in" @ GetMenuPath() $ "!! (Control" @ i $ ")", 'ModAuthor');
			}
			Controls.remove(i--, 1);
		}
		else
		{
			OnCreateComponent(Controls[i], Self);
			Controls[i].InitComponent(MyController, Self);
		}
	}
	RemapComponents();
	*/
}

void UGUIMultiComponent::AddComponent(FString ComponentClass, bool SkipRemap)
{
	/*
	local class<GUIComponent>  NewCompClass;
	local UGUIComponent* NewComp;
	if (Controller != None)
	{
		NewCompClass = Controller.AddComponentClass(ComponentClass);
	}
	else
	{
		NewCompClass = class<GUIComponent>(DynamicLoadObject(ComponentClass, Class'Class'));
	}
	if (NewCompClass != None)
	{
		NewComp = new (None) classNewCompClass;
		if (NewComp != None)
		{
			NewComp = AppendComponent(NewComp, SkipRemap);
			Return NewComp;
		}
	}
	Log(Name @ "could not create component" @ ComponentClass, 'AddComponent');
	Return None;
	*/
}

UGUIComponent* UGUIMultiComponent::InsertComponent(UGUIComponent* NewComp, int32 Index, bool SkipRemap)
{
	/*
	if (Index < 0 || Index >= Controls.Length)
	{
		Return AppendComponent(NewComp);
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
	/*
	local int32 Index;
	if (Index < Controls.Length)
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
	OnCreateComponent(NewComp, Self);
	if (NewComp.Controller == None)
	{
		NewComp.InitComponent(Controller, Self);
	}
	if (!SkipRemap)
	{
		RemapComponents();
	}
	if (Controller.bCurMenuInitialized)
	{
		NewComp.Opened(Self);
	}
	*/
	return NewComp;
}

bool UGUIMultiComponent::RemoveComponent(UGUIComponent* Comp, bool SkipRemap)
{
	/*
	local int32 i;
	for (i = 0; i < Controls.Length; i++)
	{
		if (Controls[i] == Comp)
		{
			Controls.remove(i, 1);
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
	/*
	local int32 i;
	SetFocusInstead(InFocusComp);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].SetFocusInstead(InFocusComp);
	}
	*/
}

void UGUIMultiComponent::SetFocus(UGUIComponent* Who)
{
	/*
	if (Who == None)
	{
		if (!FocusFirst(None))
		{
			SetFocus(None);
		}
		Return;
	}
	else
	{
		FocusedControl = Who;
	}
	MenuStateChange(2);
	if (MenuOwner != None)
	{
		MenuOwner.SetFocus(Self);
	}
	*/
}

void UGUIMultiComponent::LoseFocus(UGUIComponent* Sender)
{
	//FocusedControl = None;
	//LoseFocus(Sender);
}

bool UGUIMultiComponent::CanAcceptFocus()
{
	/*
	local int32 i;
	if (bAcceptsInput && CanAcceptFocus())
	{
		return true;
	}
	for (i = 0; i < Controls.Length; i++)
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
	/*
	local int32 i;
	if (Components.Length > 0)
	{
		for (i = 0; i < Components.Length; i++)
		{
			if (Components[i].FocusFirst(Sender))
			{
				return true;
			}
		}
	}
	for (i = 0; i < Controls.Length; i++)
	{
		if (Controls[i].FocusFirst(Sender))
		{
			return true;
		}
	}
	if (bAcceptsInput && CanAcceptFocus())
	{
		SetFocus(None);
		return true;
	}
	*/
	return false;
}

bool UGUIMultiComponent::FocusLast(UGUIComponent* Sender)
{
	/*
	local int32 i;
	if (Components.Length > 0)
	{
		for (i = Components.Length - 1; i >= 0; i--)
		{
			if (Components[i].FocusLast(Sender))
			{
				return true;
			}
		}
	}
	for (i = Controls.Length - 1; i >= 0; i--)
	{
		if (Controls[i].FocusLast(Sender))
		{
			return true;
		}
	}
	if (bAcceptsInput && CanAcceptFocus())
	{
		SetFocus(None);
		return true;
	}
	*/
	return false;
}

bool UGUIMultiComponent::NextControl(UGUIComponent* Sender)
{
	/*
	local int32 Index;
	Index = FindComponentIndex(Sender);
	if (Index >= 0)
	{
		if (++Index < Components.Length)
		{
			if (Components[Index].FocusFirst(None))
			{
				return true;
			}
		}
	}
	if (NextControl(Self))
	{
		return true;
	}
	*/
	return FocusFirst(nullptr);
}

bool UGUIMultiComponent::PrevControl(UGUIComponent* Sender)
{
	/*
	local int32 Index;
	Index = FindComponentIndex(Sender);
	if (--Index >= 0)
	{
		if (Components[Index].FocusLast(None))
		{
			return true;
		}
	}
	if (PrevControl(Self))
	{
		return true;
	}
	*/
	return FocusLast(nullptr);
}

void UGUIMultiComponent::EnableMe()
{
	/*
	local int32 i;
	EnableMe();
	for (i = 0; i < Controls.Length; i++)
	{
		EnableComponent(Controls[i]);
	}
	*/
}

void UGUIMultiComponent::DisableMe()
{
	/*
	local int32 i;
	DisableMe();
	for (i = 0; i < Controls.Length; i++)
	{
		DisableComponent(Controls[i]);
	}
	*/
}

void UGUIMultiComponent::SetVisibility(bool bIsVisible)
{
	/*
	local int32 i;
	SetVisibility(bIsVisible);
	if (!PropagateVisibility)
	{
		Return;
	}
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].SetVisibility(bIsVisible);
	}
	*/
}

void UGUIMultiComponent::Opened(UGUIComponent* Sender)
{
	/*
	local int32 i;
	if (Sender == None)
	{
		Sender = Self;
	}
	Opened(Sender);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].Opened(Sender);
	}
	*/
}

void UGUIMultiComponent::Closed(UGUIComponent* Sender, bool bCancelled)
{
	/*
	local int32 i;
	if (Sender == None)
	{
		Sender = Self;
	}
	Closed(Sender, bCancelled);
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].Closed(Sender, bCancelled);
	}
	*/
}

void UGUIMultiComponent::Free()
{
	/*
	local int32 i;
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].Free();
	}
	Controls.remove(0, Controls.Length);
	Components.remove(0, Components.Length);
	FocusedControl = None;
	Super::Free();
	*/
}

void UGUIMultiComponent::BeginAnimation(UGUIComponent* Animating)
{
	/*
	AnimationCount++;
	if (AnimationCount > 0)
	{
		bAnimating = True;
	}
	if (MenuOwner != None)
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
		bAnimating = False;
		AnimationCount = 0;
	}
	if (MenuOwner != None)
	{
		MenuOwner.EndAnimation(Animating, Type);
	}
	if (Animating == Self)
	{
		OnEndAnimation(Animating, Type);
	}
	*/
}

void UGUIMultiComponent::LevelChanged()
{
	/*
	local int32 i;
	LevelChanged();
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].LevelChanged();
	}
	*/
}

void UGUIMultiComponent::CenterMouse()
{
	/*
	local int32 i;
	if (FocusedControl != None)
	{
		FocusedControl.CenterMouse();
		Return;
	}
	for (i = 0; i < Components.Length; i++)
	{
		if (Components[i].CanAcceptFocus())
		{
			Components[i].CenterMouse();
			Return;
		}
	}
	CenterMouse();
	*/
}

void UGUIMultiComponent::DebugTabOrder()
{
	/*
	local int32 i;
	CheckInvalidTabOrder();
	CheckDuplicateTabOrder();
	for (i = 0; i < Controls.Length; i++)
	{
		Controls[i].DebugTabOrder();
	}
	*/
}

void UGUIMultiComponent::CheckInvalidTabOrder()
{
	/*
	local int32 i;
	for (i = 0; i < Components.Length; i++)
	{
		if (Components[i].TabOrder == -1)
		{
			Log(GetMenuPath() @ "Component[" $ i $ "] (" $ Components[i].GetMenuPath() $ ") has no tab order assigned!");
		}
	}
	*/
}

void UGUIMultiComponent::CheckDuplicateTabOrder()
{
	/*
	local int32 i;
	local int32 j;
	local array<IntBox> TabOrders;
	local bool bDup;
	for (i = 0; i < Components.Length; i++)
	{
		bDup = False;
		if (Components[i].TabOrder == -1)
		{
		}
		for (j = 0; j < TabOrders.Length; j++)
		{
			if (Components[i].TabOrder == TabOrders[j].X2)
			{
				Log(GetMenuPath() @ "Dulicate tab order (" $ Components[i].TabOrder $ ") - components " $ TabOrders[j].X1 $ " (" $ Components[TabOrders[j].X1].GetMenuPath() $ ") & " $ i $ " (" $ Components[i].GetMenuPath() $ ")");
				bDup = True;
			}
		}
		if (!bDup)
		{
			j = TabOrders.Length;
			TabOrders.Length = j + 1;
			TabOrders[j].X1 = j;
			TabOrders[j].X2 = Components[i].TabOrder;
		}
	}
	*/
}