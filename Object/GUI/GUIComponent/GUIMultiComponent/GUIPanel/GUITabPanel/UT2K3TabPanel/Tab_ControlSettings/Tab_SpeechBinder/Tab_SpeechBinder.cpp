// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/UT2K3TabPanel/Tab_ControlSettings/Tab_SpeechBinder/Tab_SpeechBinder.h"

UTab_SpeechBinder::UTab_SpeechBinder()
{
	SpeechLabel = "Phrase";
}

void UTab_SpeechBinder::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	GUILabel(Controls[4]).Caption = SpeechLabel;
	Controls[7].bVisible = false;
	LoadSpeechCommands();
	bNoMatureLanguage = MyController.ViewportOwner.Actor.bNoMatureLanguage;
	Super::InitComponent(MyController, MyOwner);
	*/
}

void UTab_SpeechBinder::InitBindings()
{
	/*
	int32 i = 0;
	int32 j = 0;
	int32 k = 0;
	int32 Index = 0;
	FString KeyName = "";
	FString Alias = "";
	FString LocalizedKeyName = "";
	for (i = 0; i < Bindings.Length; i++)
	{
		if (Bindings[i].Binds.Length > 0)
		{
			Bindings[i].Binds.remove(0, Bindings[i].Binds.Length);
		}
		if (Bindings[i].BindKeyNames.Length > 0)
		{
			Bindings[i].BindKeyNames.remove(0, Bindings[i].BindKeyNames.Length);
		}
		if (Bindings[i].BindLocalizedKeyNames.Length > 0)
		{
			Bindings[i].BindLocalizedKeyNames.remove(0, Bindings[i].BindLocalizedKeyNames.Length);
		}
		MyListBox.List.Add(Bindings[i].KeyLabel);
	}
	for (i = 0; i < 255; i++)
	{
		KeyName = PlayerOwner().ConsoleCommand("KEYNAME" @ string(i));
		LocalizedKeyName = PlayerOwner().ConsoleCommand("LOCALIZEDKEYNAME" @ string(i));
		if (KeyName != "")
		{
			Alias = PlayerOwner().ConsoleCommand("KEYBINDING" @ KeyName);
			if (Alias != "")
			{
				for (j = 0; j < Bindings.Length; j++)
				{
					if (Bindings[j].Alias ~= Alias)
					{
						Index = Bindings[j].Binds.Length;
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
	/*
	int32 At = 0;
	At = Bindings.Length;
	Bindings.Length = (Bindings.Length + 1);
	Bindings[At].bIsSectionLabel = IsSection;
	Bindings[At].KeyLabel = KeyLabel;
	Bindings[At].Alias = Alias;
	*/
}

void LoadSpeechCommands()
{
}
