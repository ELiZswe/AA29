// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/KeyBindMenu/ControlBinder/ControlBinder.h"

UControlBinder::UControlBinder()
{
	BindingLabel.SetNum(151);

	BindingLabel[0] = "Movement";
	BindingLabel[1] = "Forward";
	BindingLabel[2] = "Backward";
	BindingLabel[3] = "Strafe Left";
	BindingLabel[4] = "Strafe Right";
	BindingLabel[5] = "Jump";
	BindingLabel[6] = "Walk";
	BindingLabel[7] = "Crouch";
	BindingLabel[8] = "Strafe Toggle";
	BindingLabel[9] = "Looking";
	BindingLabel[10] = "Turn Left";
	BindingLabel[11] = "Turn Right";
	BindingLabel[12] = "Look Up";
	BindingLabel[13] = "Look Down";
	BindingLabel[14] = "Center View";
	BindingLabel[15] = "Toggle \"BehindView\"";
	BindingLabel[16] = "Toggle Camera Mode";
	BindingLabel[17] = "Weapons";
	BindingLabel[18] = "Fire";
	BindingLabel[19] = "Alt-Fire";
	BindingLabel[20] = "Throw Weapon";
	BindingLabel[21] = "Best Weapon";
	BindingLabel[22] = "Next Weapon";
	BindingLabel[23] = "Prev Weapon";
	BindingLabel[24] = "Last Weapon";
	BindingLabel[25] = "Weapon Selection";
	BindingLabel[26] = "Super Weapon";
	BindingLabel[27] = "Shield Gun";
	BindingLabel[28] = "Assault Rifle";
	BindingLabel[29] = "Bio-Rifle";
	BindingLabel[30] = "Shock Rifle";
	BindingLabel[31] = "Link Gun";
	BindingLabel[32] = "Minigun";
	BindingLabel[33] = "Flak Cannon";
	BindingLabel[34] = "Rocket Launcher";
	BindingLabel[35] = "Lightning Rifle";
	BindingLabel[36] = "Translocator";
	BindingLabel[37] = "Communication";
	BindingLabel[38] = "Say";
	BindingLabel[39] = "Team Say";
	BindingLabel[40] = "In Game Chat";
	BindingLabel[41] = "Speech Menu";
	BindingLabel[42] = "Activate Microphone";
	BindingLabel[43] = "Speak in Public Channel";
	BindingLabel[44] = "Speak in local Channel";
	BindingLabel[45] = "Speak in Team Channel";
	BindingLabel[46] = "Toggle Public Channel";
	BindingLabel[47] = "Toggle Local Channel";
	BindingLabel[48] = "Toggle Team Channel";
	BindingLabel[49] = "Taunts";
	BindingLabel[50] = "Pelvic Thrust";
	BindingLabel[51] = "Ass Smack";
	BindingLabel[52] = "Throat Cut";
	BindingLabel[53] = "Brag";
	BindingLabel[54] = "Hud";
	BindingLabel[55] = "Grow Hud";
	BindingLabel[56] = "Shrink Hud";
	BindingLabel[57] = "Show Radar Map";
	BindingLabel[58] = "ScoreBoard Toggle";
	BindingLabel[59] = "ScoreBoard";
	BindingLabel[60] = "Game";
	BindingLabel[61] = "Use";
	BindingLabel[62] = "Pause";
	BindingLabel[63] = "Screenshot";
	BindingLabel[64] = "Find Red Base";
	BindingLabel[65] = "Find Blue Base";
	BindingLabel[66] = "Next Inventory Item";
	BindingLabel[67] = "Previous Inventory Item";
	BindingLabel[68] = "Activate Current Inventory Item";
	BindingLabel[69] = "Show Personal Stats";
	BindingLabel[70] = "View Next Player's Stats";
	BindingLabel[71] = "Server Info";
	BindingLabel[72] = "Vehicle Horn";
	BindingLabel[73] = "Miscellaneous";
	BindingLabel[74] = "Menu";
	BindingLabel[75] = "Music Player";
	BindingLabel[76] = "Voting Menu";
	BindingLabel[77] = "Toggle Console";
	BindingLabel[78] = "View Connection Status";
	BindingLabel[79] = "Cancel Pending Connection";
	Headings = { "Action" };
	PageCaption = "Configure Keys";
}

void UControlBinder::LoadCommands()
{
	/*
	int32 i = 0;
	Super::LoadCommands();
	for (i = 0; i < Bindings.Length; i++)
	{
		li_Binds.AddedItem();
	}
	*/
}

void UControlBinder::MapBindings()
{
	/*
	LoadCustomBindings();
	Super::MapBindings();
	*/
}

void UControlBinder::LoadCustomBindings()
{
	/*
	int32 i = 0;
	local TArray<FString> KeyBindClasses;
	local class<XInterface.GUIUserKeyBinding>  CustomKeyBindClass;
	PlayerOwner().GetAllInt("XInterface.GUIUserKeyBinding", KeyBindClasses);
	for (i = 0; i < KeyBindClasses.Length; i++)
	{
		CustomKeyBindClass = class<GUIUserKeyBinding>(DynamicLoadObject(KeyBindClasses[i], Class'Class'));
		if (CustomKeyBindClass != None)
		{
			AddCustomBindings(CustomKeyBindClass.Default.KeyData);
		}
	}
	*/
}

void UControlBinder::AddCustomBindings(TArray<FKeyInfo> KeyData)
{
	/*
	int32 i = 0;
	for (i = 0; i < KeyData.Length; i++)
	{
		CreateAliasMapping(KeyData[i].Alias, KeyData[i].KeyLabel, KeyData[i].bIsSection);
	}
	*/
}

void UControlBinder::ClearBindings()
{
	/*
	int32 i = 0;
	int32 Max = 0;
	Super::ClearBindings();
	Bindings = Default.Bindings;
	Max = Min(Bindings.Length, 150);
	for (i = 0; i < Max; i++)
	{
		if (BindingLabel[i] != "")
		{
			Bindings[i].KeyLabel = BindingLabel[i];
		}
	}
	*/
}

