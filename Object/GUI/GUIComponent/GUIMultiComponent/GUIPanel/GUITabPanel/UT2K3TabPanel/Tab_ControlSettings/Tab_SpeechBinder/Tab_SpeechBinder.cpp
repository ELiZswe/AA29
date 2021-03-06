// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_ControlSettings/Tab_SpeechBinder/Tab_SpeechBinder.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UTab_SpeechBinder::UTab_SpeechBinder()
{
	SpeechLabel = "Phrase";
}

void UTab_SpeechBinder::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Cast<UGUILabel>(Controls[4]).Caption = SpeechLabel;
	Controls[7].bVisible = false;
	LoadSpeechCommands();
	bNoMatureLanguage = MyController.ViewportOwner.Actor.bNoMatureLanguage;
	Super::InitComponent(MyController, MyOwner);
	*/
}

void UTab_SpeechBinder::InitBindings()
{
	int32 i = 0;
	int32 j = 0;
	int32 k = 0;
	int32 Index = 0;
	FString KeyName = "";
	FString Alias = "";
	FString LocalizedKeyName = "";
	/*
	for (i = 0; i < Bindings.Num(); i++)
	{
		if (Bindings[i].Binds.Num() > 0)
		{
			Bindings[i].Binds.RemoveAt(0, Bindings[i].Binds.Num());
		}
		if (Bindings[i].BindKeyNames.Num() > 0)
		{
			Bindings[i].BindKeyNames.RemoveAt(0, Bindings[i].BindKeyNames.Num());
		}
		if (Bindings[i].BindLocalizedKeyNames.Num() > 0)
		{
			Bindings[i].BindLocalizedKeyNames.RemoveAt(0, Bindings[i].BindLocalizedKeyNames.Num());
		}
		MyListBox.List.Add(Bindings[i].KeyLabel);
	}
	for (i = 0; i < 255; i++)
	{
		KeyName = PlayerOwner().ConsoleCommand("KEYNAME" @ FString::FromInt(i));
		LocalizedKeyName = PlayerOwner().ConsoleCommand("LOCALIZEDKEYNAME" @ FString::FromInt(i));
		if (KeyName != "")
		{
			Alias = PlayerOwner().ConsoleCommand("KEYBINDING" @ KeyName);
			if (Alias != "")
			{
				for (j = 0; j < Bindings.Num(); j++)
				{
					if (Bindings[j].Alias ~= Alias)
					{
						Index = Bindings[j].Binds.Num();
						Bindings[j].Binds[Index] = i;
						Bindings[j].BindKeyNames[Index] = KeyName;
						Bindings[j].BindLocalizedKeyNames[Index] = LocalizedKeyName;
						k = 0;
						if (k < Index)
						{
							if (Weight(Bindings[j].Binds[k]) < Weight(Bindings[j].Binds[Index]))
							{
								Swap(j, k, Index);
							}
							else
							{
								k++;
							}
						}
					}
				}
			}
		}
	}
	*/
}

void UTab_SpeechBinder::AddCommand(bool IsSection, FString KeyLabel, FString Alias)
{
	int32 At = 0;
	FKeyBinding tmpKeyBinding;
	tmpKeyBinding.bIsSectionLabel = IsSection;
	tmpKeyBinding.KeyLabel = KeyLabel;
	tmpKeyBinding.Alias = Alias;
	Bindings.Add(tmpKeyBinding);
}

void UTab_SpeechBinder::LoadSpeechCommands()
{
}
