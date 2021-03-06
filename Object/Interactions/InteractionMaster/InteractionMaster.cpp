// All the original content belonged to the US Army

#include "AA29/Object/Interactions/InteractionMaster/InteractionMaster.h"
#include "AA29/Object/Interactions/Interaction/Interaction.h"
#include "Engine/Canvas.h"

UInteractionMaster::UInteractionMaster()
{

}

//native Function Travel(FString URL);
void UInteractionMaster::Travel(FString URL)
{

}

UInteraction* UInteractionMaster::AddInteraction(FString InteractionName, UPlayer* AttachTo)
{
	UInteraction* NewInteraction = nullptr;
	UInteraction*  NewInteractionClass = nullptr;
	/*
	NewInteractionClass = class<Interaction>(DynamicLoadObject(InteractionName, Class'Class'));
	if (NewInteractionClass != nullptr)
	{
		NewInteraction = new () classNewInteractionClass;
		if (NewInteraction != nullptr)
		{
			if (AttachTo != nullptr)
			{
				AttachTo.LocalInteractions.Num() = (AttachTo.LocalInteractions.Num() + 1);
				AttachTo.LocalInteractions[(AttachTo.LocalInteractions.Num() - 1)] = NewInteraction;
				NewInteraction.ViewportOwner = AttachTo;
			}
			else
			{
				GlobalInteractions.Num() = (GlobalInteractions.Num() + 1);
				GlobalInteractions[(GlobalInteractions.Num() - 1)] = NewInteraction;
			}
			NewInteraction.Initialize();
			NewInteraction.Master = this;
			return NewInteraction;
		}
		else
		{
			Log("Could not create interaction [" + InteractionName + "]", "IMaster");
		}
	}
	else
	{
		Log("Could not load interaction [" + InteractionName + "]", "IMaster");
	}
	*/
	return nullptr;
}

void UInteractionMaster::RemoveInteraction(UInteraction* RemoveMe)
{
	int32 Index = 0;
	/*
	if (RemoveMe->ViewportOwner != nullptr)
	{
		for (Index = 0; Index < RemoveMe->ViewportOwner->LocalInteractions.Num(); Index++)
		{
			if (RemoveMe->ViewportOwner->LocalInteractions[Index] == RemoveMe)
			{
				RemoveMe->ViewportOwner->LocalInteractions.RemoveAt(Index, 1);
				return;
			}
		}
	}
	else
	{
		for (Index = 0; Index < GlobalInteractions.Num(); Index++)
		{
			if (GlobalInteractions[Index] == RemoveMe)
			{
				GlobalInteractions.RemoveAt(Index, 1);
				return;
			}
		}
	}
	Log("Could not remove interaction [" + FString::FromInt(RemoveMe) + "] (Not Found)", "IMaster");
	*/
}

void UInteractionMaster::SetFocusTo(UInteraction* Inter, UPlayer* ViewportOwner)
{
	TArray<UInteraction*> InteractionArray;
	UInteraction* Temp = nullptr;
	int32 i = 0;
	int32 iIndex = 0;
	/*
	if (ViewportOwner != nullptr)
	{
		InteractionArray = ViewportOwner->LocalInteractions;
	}
	else
	{
		InteractionArray = GlobalInteractions;
	}
	if (InteractionArray.Num() == 0)
	{
		Log("Attempt to SetFocus on an empty Array.", "IMaster");
		return;
	}
	iIndex = -1;
	i = 0;
	if (i < InteractionArray.Num())
	{
		if (InteractionArray[i] == Inter)
		{
			iIndex = i;
		}
		else
		{
			i++;
		}
	}
	if (iIndex < 0)
	{
		Log("Interaction " + FString::FromInt(Inter) + " is not in " + FString::FromInt(ViewportOwner) + ".", "IMaster");
		return;
	}
	else
	{
		if (iIndex == 0)
		{
			return;
		}
	}
	Temp = InteractionArray[iIndex];
	for (i = 0; i < iIndex; i++)
	{
		InteractionArray[(i + 1)] = InteractionArray[i];
	}
	InteractionArray[0] = Temp;
	InteractionArray[0].bActive = true;
	InteractionArray[0].bVisible = true;
	*/
}

bool UInteractionMaster::Process_KeyType(TArray<UInteraction*> InteractionArray, EInputKey& Key, FString Unicode)
{
	int32 Index = 0;
	for (Index = 0; Index < InteractionArray.Num(); Index++)
	{
		if ((InteractionArray[Index]->bActive && (!InteractionArray[Index]->bNativeEvents)) && InteractionArray[Index]->KeyType(Key, Unicode))
		{
			return true;
		}
	}
	return false;
}

bool UInteractionMaster::Process_KeyEvent(TArray<UInteraction*> InteractionArray, EInputKey& Key, EInputAction& Action, float Delta)
{
	int32 Index = 0;
	for (Index = 0; Index < InteractionArray.Num(); Index++)
	{
		if ((InteractionArray[Index]->bActive && (!InteractionArray[Index]->bNativeEvents)) && InteractionArray[Index]->KeyEvent(Key, Action, Delta))
		{
			return true;
		}
	}
	return false;
}

void UInteractionMaster::Process_PreRender(TArray<UInteraction*> InteractionArray, UCanvas* Canvas)
{
	int32 Index = 0;
	for (Index = InteractionArray.Num(); Index > 0; Index--)
	{
		if (InteractionArray[(Index - 1)]->bVisible && (!InteractionArray[(Index - 1)]->bNativeEvents))
		{
			InteractionArray[(Index - 1)]->PreRender(Canvas);
		}
	}
}

void UInteractionMaster::Process_PostRender(TArray<UInteraction*> InteractionArray, UCanvas* Canvas)
{
	int32 Index = 0;
	for (Index = InteractionArray.Num(); Index > 0; Index--)
	{
		if (InteractionArray[(Index - 1)]->bVisible && (!InteractionArray[(Index - 1)]->bNativeEvents))
		{
			InteractionArray[(Index - 1)]->PostRender(Canvas);
		}
	}
}

void UInteractionMaster::Process_Tick(TArray<UInteraction*> InteractionArray, float DeltaTime)
{
	int32 Index = 0;
	for (Index = 0; Index < InteractionArray.Num(); Index++)
	{
		if (InteractionArray[Index]->bRequiresTick && (!InteractionArray[Index]->bNativeEvents))
		{
			InteractionArray[Index]->Tick(DeltaTime);
		}
	}
}

void UInteractionMaster::Process_Message(FString Msg, float MsgLife, TArray<UInteraction*> InteractionArray)
{
	int32 Index = 0;
	for (Index = 0; Index < InteractionArray.Num(); Index++)
	{
		InteractionArray[Index]->Message(Msg, MsgLife, FColor(0,0,0,0));
	}
}

void UInteractionMaster::NotifyLevelChange(TArray<UInteraction*> InteractionArray)
{
	int32 Index = 0;
	for (Index = 0; Index < InteractionArray.Num(); Index++)
	{
		InteractionArray[Index]->NotifyLevelChange();
	}
}

void UInteractionMaster::NotifyInteractions(UInteraction* Changed, bool bOpen)
{
	int32 i = 0;
	for (i = 0; i < GlobalInteractions.Num(); i++)
	{
		GlobalInteractions[i]->InteractionChanged(Changed, bOpen);
	}
}

void UInteractionMaster::NotifyDemoCompleted(TArray<UInteraction*> InteractionArray)
{
	int32 Index = 0;
	for (Index = 0; Index < InteractionArray.Num(); Index++)
	{
		if (InteractionArray[Index]->bRequiresTick && (!InteractionArray[Index]->bNativeEvents))
		{
			InteractionArray[Index]->NotifyDemoCompleted();
		}
	}
}
