// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AANPCPNB_PlayerStartOptions/AANPCPNB_PlayerStartOptions.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moEditBox/moEditBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moComboBox/moComboBox.h"

UAANPCPNB_PlayerStartOptions::UAANPCPNB_PlayerStartOptions()
{
	UGUIButton* ButtonSave = NewObject<UGUIButton>(UGUIButton::StaticClass());
	ButtonSave->Caption = "Save";
	ButtonSave->StyleName = "SquareMenuButton";
	ButtonSave->Hint = "Click here to save the .";
	ButtonSave->WinTop = 0.93;
	ButtonSave->WinLeft = 0.38;
	ButtonSave->WinWidth = 0.12;
	ButtonSave->WinHeight = 0.053476;
	//ButtonSave->OnClick=AANPCPNB_PlayerStartOptions.ButtonClick;
	//ButtonSave->OnKeyEvent=ButtonSave.InternalOnKeyEvent;
	UGUIButton* CloseButton = NewObject<UGUIButton>(UGUIButton::StaticClass());
	CloseButton->Caption = "Discard Changes";
	CloseButton->StyleName = "SquareMenuButton";
	CloseButton->Hint = "Click here to close the Command Post.";
	CloseButton->WinTop = 0.93;
	CloseButton->WinLeft = 0.5;
	CloseButton->WinWidth = 0.25;
	CloseButton->WinHeight = 0.053476;
	//CloseButton->OnClick=AANPCPNB_PlayerStartOptions.ButtonClick;
	//CloseButton->OnKeyEvent=CloseButton.InternalOnKeyEvent;
	UmoEditBox* EntryFieldDisplayName = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	EntryFieldDisplayName->CaptionWidth = 0.4;
	EntryFieldDisplayName->Caption = "Display Name:";
	//EntryFieldDisplayName->OnCreateComponent=EntryFieldDisplayName.InternalOnCreateComponent;
	EntryFieldDisplayName->IniOption = "@Internal";
	EntryFieldDisplayName->Hint = "Use this to enter the name of the NPC as it will appear in various status messages.";
	EntryFieldDisplayName->WinTop = 0.15;
	EntryFieldDisplayName->WinLeft = 0.05;
	EntryFieldDisplayName->WinWidth = 0.4;
	EntryFieldDisplayName->WinHeight = 0.04;
	EntryFieldDisplayName->TabOrder = 1;
	EntryFieldDisplayName->bStandardized = false;
	//EntryFieldDisplayName->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoCheckBox* CheckboxSpawnAsReserve = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	CheckboxSpawnAsReserve->Caption = "Spawn As Reserve";
	//CheckboxSpawnAsReserve->OnCreateComponent=CheckboxSpawnAsReserve.InternalOnCreateComponent;
	CheckboxSpawnAsReserve->IniOption = "@Internal";
	CheckboxSpawnAsReserve->Hint = "Checking this box cause the NPC to spawn as a reserve based on the standard reserve force spawning rules.";
	CheckboxSpawnAsReserve->WinTop = 0.15;
	CheckboxSpawnAsReserve->WinLeft = 0.5;
	CheckboxSpawnAsReserve->WinWidth = 0.4;
	CheckboxSpawnAsReserve->WinHeight = 0.04;
	CheckboxSpawnAsReserve->TabOrder = 2;
	CheckboxSpawnAsReserve->bStandardized = false;
	//CheckboxSpawnAsReserve->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoEditBox* EntryFieldWaypointTag = NewObject<UmoEditBox>(UmoEditBox::StaticClass());
	EntryFieldWaypointTag->CaptionWidth = 0.4;
	EntryFieldWaypointTag->Caption = "Waypoint Tag:";
	//EntryFieldWaypointTag->OnCreateComponent=EntryFieldWaypointTag.InternalOnCreateComponent;
	EntryFieldWaypointTag->IniOption = "@Internal";
	EntryFieldWaypointTag->Hint = "Use this to enter the tag to use for navigating waypoints.";
	EntryFieldWaypointTag->WinTop = 0.2;
	EntryFieldWaypointTag->WinLeft = 0.05;
	EntryFieldWaypointTag->WinWidth = 0.4;
	EntryFieldWaypointTag->WinHeight = 0.04;
	EntryFieldWaypointTag->TabOrder = 3;
	EntryFieldWaypointTag->bStandardized = false;
	//EntryFieldWaypointTag->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoCheckBox* CheckboxSpawnRandomLocation = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	CheckboxSpawnRandomLocation->Caption = "Spawn at Random Location";
	//CheckboxSpawnRandomLocation->OnCreateComponent=CheckboxSpawnRandomLocation.InternalOnCreateComponent;
	CheckboxSpawnRandomLocation->IniOption = "@Internal";
	CheckboxSpawnRandomLocation->Hint = "Checking this box cause the NPC to spawn at a random Patrol location.";
	CheckboxSpawnRandomLocation->WinTop = 0.2;
	CheckboxSpawnRandomLocation->WinLeft = 0.5;
	CheckboxSpawnRandomLocation->WinWidth = 0.4;
	CheckboxSpawnRandomLocation->WinHeight = 0.04;
	CheckboxSpawnRandomLocation->TabOrder = 4;
	CheckboxSpawnRandomLocation->bStandardized = false;
	//CheckboxSpawnRandomLocation->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownFaceSkin = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownFaceSkin->CaptionWidth = 0.28;
	DropDownFaceSkin->Caption = "Face Skin:";
	//DropDownFaceSkin->OnCreateComponent=DropDownFaceSkin.InternalOnCreateComponent;
	DropDownFaceSkin->IniOption = "@Internal";
	DropDownFaceSkin->Hint = "Select the face skin you want to apply to this NPC.";
	DropDownFaceSkin->WinTop = 0.25;
	DropDownFaceSkin->WinLeft = 0.05;
	DropDownFaceSkin->WinWidth = 0.4;
	DropDownFaceSkin->WinHeight = 0.04;
	DropDownFaceSkin->TabOrder = 5;
	DropDownFaceSkin->bStandardized = false;
	//DropDownFaceSkin->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoCheckBox* CheckboxAutoReversePatrolPath = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	CheckboxAutoReversePatrolPath->Caption = "Auto-Reverse Patrol Path";
	//CheckboxAutoReversePatrolPath->OnCreateComponent=CheckboxAutoReversePatrolPath.InternalOnCreateComponent;
	CheckboxAutoReversePatrolPath->IniOption = "@Internal";
	CheckboxAutoReversePatrolPath->Hint = "Checking this box cause the NPC to automatically reverse his patrol when he hits the last patrol path node.";
	CheckboxAutoReversePatrolPath->WinTop = 0.25;
	CheckboxAutoReversePatrolPath->WinLeft = 0.5;
	CheckboxAutoReversePatrolPath->WinWidth = 0.4;
	CheckboxAutoReversePatrolPath->WinHeight = 0.04;
	CheckboxAutoReversePatrolPath->TabOrder = 6;
	CheckboxAutoReversePatrolPath->bStandardized = false;
	//CheckboxAutoReversePatrolPath->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownShirtSkin = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownShirtSkin->CaptionWidth = 0.28;
	DropDownShirtSkin->Caption = "Shirt Skin:";
	//DropDownShirtSkin->OnCreateComponent=DropDownShirtSkin.InternalOnCreateComponent;
	DropDownShirtSkin->IniOption = "@Internal";
	DropDownShirtSkin->Hint = "Select the shirt skin you want to apply to this NPC.";
	DropDownShirtSkin->WinTop = 0.3;
	DropDownShirtSkin->WinLeft = 0.05;
	DropDownShirtSkin->WinWidth = 0.4;
	DropDownShirtSkin->WinHeight = 0.04;
	DropDownShirtSkin->TabOrder = 5;
	DropDownShirtSkin->bStandardized = false;
	//DropDownShirtSkin->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoCheckBox* CheckboxPatrolAscendingOrder = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	CheckboxPatrolAscendingOrder->Caption = "Walk Patrol Path Ascending";
	//CheckboxPatrolAscendingOrder->OnCreateComponent=CheckboxPatrolAscendingOrder.InternalOnCreateComponent;
	CheckboxPatrolAscendingOrder->IniOption = "@Internal";
	CheckboxPatrolAscendingOrder->Hint = "Checking this box cause the NPC to automatically reverse his patrol when he hits the last patrol path node.";
	CheckboxPatrolAscendingOrder->WinTop = 0.3;
	CheckboxPatrolAscendingOrder->WinLeft = 0.5;
	CheckboxPatrolAscendingOrder->WinWidth = 0.4;
	CheckboxPatrolAscendingOrder->WinHeight = 0.04;
	CheckboxPatrolAscendingOrder->TabOrder = 6;
	CheckboxPatrolAscendingOrder->bStandardized = false;
	//CheckboxPatrolAscendingOrder->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownPantsSkin = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownPantsSkin->CaptionWidth = 0.28;
	DropDownPantsSkin->Caption = "Pants Skin:";
	//DropDownPantsSkin->OnCreateComponent=DropDownPantsSkin.InternalOnCreateComponent;
	DropDownPantsSkin->IniOption = "@Internal";
	DropDownPantsSkin->Hint = "Select the pants skin you want to apply to this NPC.";
	DropDownPantsSkin->WinTop = 0.35;
	DropDownPantsSkin->WinLeft = 0.05;
	DropDownPantsSkin->WinWidth = 0.4;
	DropDownPantsSkin->WinHeight = 0.04;
	DropDownPantsSkin->TabOrder = 7;
	DropDownPantsSkin->bStandardized = false;
	//DropDownPantsSkin->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownSpawnChance = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownSpawnChance->CaptionWidth = 0.28;
	DropDownSpawnChance->Caption = "Spawn Chance:";
	//DropDownSpawnChance->OnCreateComponent=DropDownSpawnChance.InternalOnCreateComponent;
	DropDownSpawnChance->IniOption = "@Internal";
	DropDownSpawnChance->Hint = "Select how likely this NPC is to spawn.";
	DropDownSpawnChance->WinTop = 0.35;
	DropDownSpawnChance->WinLeft = 0.5;
	DropDownSpawnChance->WinWidth = 0.4;
	DropDownSpawnChance->WinHeight = 0.04;
	DropDownSpawnChance->TabOrder = 8;
	DropDownSpawnChance->bStandardized = false;
	//DropDownSpawnChance->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownHandsSkin = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownHandsSkin->CaptionWidth = 0.28;
	DropDownHandsSkin->Caption = "Hands Skin:";
	//DropDownHandsSkin->OnCreateComponent=DropDownHandsSkin.InternalOnCreateComponent;
	DropDownHandsSkin->IniOption = "@Internal";
	DropDownHandsSkin->Hint = "Select the hands skin you want to apply to this NPC.";
	DropDownHandsSkin->WinTop = 0.4;
	DropDownHandsSkin->WinLeft = 0.05;
	DropDownHandsSkin->WinWidth = 0.4;
	DropDownHandsSkin->WinHeight = 0.04;
	DropDownHandsSkin->TabOrder = 9;
	DropDownHandsSkin->bStandardized = false;
	//DropDownHandsSkin->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownInitialOrders = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownInitialOrders->CaptionWidth = 0.28;
	DropDownInitialOrders->Caption = "Initial Orders:";
	//DropDownInitialOrders->OnCreateComponent=DropDownInitialOrders.InternalOnCreateComponent;
	DropDownInitialOrders->IniOption = "@Internal";
	DropDownInitialOrders->Hint = "Select initial orders for this NPC.";
	DropDownInitialOrders->WinTop = 0.4;
	DropDownInitialOrders->WinLeft = 0.5;
	DropDownInitialOrders->WinWidth = 0.4;
	DropDownInitialOrders->WinHeight = 0.04;
	DropDownInitialOrders->TabOrder = 10;
	DropDownInitialOrders->bStandardized = false;
	//DropDownInitialOrders->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownHeadGear = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownHeadGear->CaptionWidth = 0.28;
	DropDownHeadGear->Caption = "Head Gear:";
	//DropDownHeadGear->OnCreateComponent=DropDownHeadGear.InternalOnCreateComponent;
	DropDownHeadGear->IniOption = "@Internal";
	DropDownHeadGear->Hint = "Select the type of head gear this NPC to wear.";
	DropDownHeadGear->WinTop = 0.45;
	DropDownHeadGear->WinLeft = 0.05;
	DropDownHeadGear->WinWidth = 0.4;
	DropDownHeadGear->WinHeight = 0.04;
	DropDownHeadGear->TabOrder = 11;
	DropDownHeadGear->bStandardized = false;
	//DropDownHeadGear->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoCheckBox* CheckboxHasBinoculars = NewObject<UmoCheckBox>(UmoCheckBox::StaticClass());
	CheckboxHasBinoculars->Caption = "Has Binoculars";
	//CheckboxHasBinoculars->OnCreateComponent=CheckboxHasBinoculars.InternalOnCreateComponent;
	CheckboxHasBinoculars->IniOption = "@Internal";
	CheckboxHasBinoculars->Hint = "Checking this box cause the NPC to spawn with binoculars in it's inventory.nTypically this is used for mortar spotters.";
	CheckboxHasBinoculars->WinTop = 0.5;
	CheckboxHasBinoculars->WinLeft = 0.05;
	CheckboxHasBinoculars->WinWidth = 0.4;
	CheckboxHasBinoculars->WinHeight = 0.04;
	CheckboxHasBinoculars->TabOrder = 12;
	CheckboxHasBinoculars->bStandardized = false;
	//CheckboxHasBinoculars->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownPrimaryWeapon = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownPrimaryWeapon->CaptionWidth = 0.28;
	DropDownPrimaryWeapon->Caption = "Primary Weapon:";
	//DropDownPrimaryWeapon->OnCreateComponent=DropDownPrimaryWeapon.InternalOnCreateComponent;
	DropDownPrimaryWeapon->IniOption = "@Internal";
	DropDownPrimaryWeapon->Hint = "Select the type of primary weapon this NPC should have.";
	DropDownPrimaryWeapon->WinTop = 0.55;
	DropDownPrimaryWeapon->WinLeft = 0.05;
	DropDownPrimaryWeapon->WinWidth = 0.4;
	DropDownPrimaryWeapon->WinHeight = 0.04;
	DropDownPrimaryWeapon->TabOrder = 13;
	DropDownPrimaryWeapon->bStandardized = false;
	//DropDownPrimaryWeapon->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownPrimaryWeaponReloads = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownPrimaryWeaponReloads->CaptionWidth = 0.28;
	DropDownPrimaryWeaponReloads->Caption = "Primary Weapon Reloads:";
	//DropDownPrimaryWeaponReloads->OnCreateComponent=DropDownPrimaryWeaponReloads.InternalOnCreateComponent;
	DropDownPrimaryWeaponReloads->IniOption = "@Internal";
	DropDownPrimaryWeaponReloads->Hint = "Select the number of primary weapon reloads this NPC should have.";
	DropDownPrimaryWeaponReloads->WinTop = 0.55;
	DropDownPrimaryWeaponReloads->WinLeft = 0.5;
	DropDownPrimaryWeaponReloads->WinWidth = 0.4;
	DropDownPrimaryWeaponReloads->WinHeight = 0.04;
	DropDownPrimaryWeaponReloads->TabOrder = 14;
	DropDownPrimaryWeaponReloads->bStandardized = false;
	//DropDownPrimaryWeaponReloads->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownSecondaryWeapon = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownSecondaryWeapon->CaptionWidth = 0.28;
	DropDownSecondaryWeapon->Caption = "Secondary Weapon:";
	//DropDownSecondaryWeapon->OnCreateComponent=DropDownSecondaryWeapon.InternalOnCreateComponent;
	DropDownSecondaryWeapon->IniOption = "@Internal";
	DropDownSecondaryWeapon->Hint = "Select the type of secondary weapon this NPC should have.";
	DropDownSecondaryWeapon->WinTop = 0.6;
	DropDownSecondaryWeapon->WinLeft = 0.05;
	DropDownSecondaryWeapon->WinWidth = 0.4;
	DropDownSecondaryWeapon->WinHeight = 0.04;
	DropDownSecondaryWeapon->TabOrder = 15;
	DropDownSecondaryWeapon->bStandardized = false;
	//DropDownSecondaryWeapon->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownSecondaryWeaponReloads = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownSecondaryWeaponReloads->CaptionWidth = 0.28;
	DropDownSecondaryWeaponReloads->Caption = "Secondary Weapon Reloads:";
	//DropDownSecondaryWeaponReloads->OnCreateComponent=DropDownSecondaryWeaponReloads.InternalOnCreateComponent;
	DropDownSecondaryWeaponReloads->IniOption = "@Internal";
	DropDownSecondaryWeaponReloads->Hint = "Select the number of secondary weapon reloads this NPC should have.";
	DropDownSecondaryWeaponReloads->WinTop = 0.6;
	DropDownSecondaryWeaponReloads->WinLeft = 0.5;
	DropDownSecondaryWeaponReloads->WinWidth = 0.4;
	DropDownSecondaryWeaponReloads->WinHeight = 0.04;
	DropDownSecondaryWeaponReloads->TabOrder = 16;
	DropDownSecondaryWeaponReloads->bStandardized = false;
	//DropDownSecondaryWeaponReloads->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownFragGrenades = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownFragGrenades->CaptionWidth = 0.28;
	DropDownFragGrenades->Caption = "Frag Grenades:";
	//DropDownFragGrenades->OnCreateComponent=DropDownFragGrenades.InternalOnCreateComponent;
	DropDownFragGrenades->IniOption = "@Internal";
	DropDownFragGrenades->Hint = "Select the number of fragmentary grenades the NPC should have.";
	DropDownFragGrenades->WinTop = 0.65;
	DropDownFragGrenades->WinLeft = 0.05;
	DropDownFragGrenades->WinWidth = 0.4;
	DropDownFragGrenades->WinHeight = 0.04;
	DropDownFragGrenades->TabOrder = 17;
	DropDownFragGrenades->bStandardized = false;
	//DropDownFragGrenades->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownSmokeGrenades = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownSmokeGrenades->CaptionWidth = 0.28;
	DropDownSmokeGrenades->Caption = "Smoke Grenades:";
	//DropDownSmokeGrenades->OnCreateComponent=DropDownSmokeGrenades.InternalOnCreateComponent;
	DropDownSmokeGrenades->IniOption = "@Internal";
	DropDownSmokeGrenades->Hint = "Select the number of smoke grenades the NPC should have.";
	DropDownSmokeGrenades->WinTop = 0.65;
	DropDownSmokeGrenades->WinLeft = 0.5;
	DropDownSmokeGrenades->WinWidth = 0.4;
	DropDownSmokeGrenades->WinHeight = 0.04;
	DropDownSmokeGrenades->TabOrder = 18;
	DropDownSmokeGrenades->bStandardized = false;
	//DropDownSmokeGrenades->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownWeaponSkill = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownWeaponSkill->CaptionWidth = 0.28;
	DropDownWeaponSkill->Caption = "Weapon Skill:";
	//DropDownWeaponSkill->OnCreateComponent=DropDownWeaponSkill.InternalOnCreateComponent;
	DropDownWeaponSkill->IniOption = "@Internal";
	DropDownWeaponSkill->Hint = "Select how skillful the NPC is with it's weapon.";
	DropDownWeaponSkill->WinTop = 0.75;
	DropDownWeaponSkill->WinLeft = 0.05;
	DropDownWeaponSkill->WinWidth = 0.4;
	DropDownWeaponSkill->WinHeight = 0.04;
	DropDownWeaponSkill->TabOrder = 19;
	DropDownWeaponSkill->bStandardized = false;
	//DropDownWeaponSkill->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownExperience = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownExperience->CaptionWidth = 0.28;
	DropDownExperience->Caption = "Experience:";
	//DropDownExperience->OnCreateComponent=DropDownExperience.InternalOnCreateComponent;
	DropDownExperience->IniOption = "@Internal";
	DropDownExperience->Hint = "Select the how experienced the NPC is.nMore experienced AI react faster, are less rattled by enemy actions.";
	DropDownExperience->WinTop = 0.75;
	DropDownExperience->WinLeft = 0.5;
	DropDownExperience->WinWidth = 0.4;
	DropDownExperience->WinHeight = 0.04;
	DropDownExperience->TabOrder = 20;
	DropDownExperience->bStandardized = false;
	//DropDownExperience->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownVisionSkill = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownVisionSkill->CaptionWidth = 0.28;
	DropDownVisionSkill->Caption = "Vision Skill:";
	//DropDownVisionSkill->OnCreateComponent=DropDownVisionSkill.InternalOnCreateComponent;
	DropDownVisionSkill->IniOption = "@Internal";
	DropDownVisionSkill->Hint = "Select how well the NPC sees.";
	DropDownVisionSkill->WinTop = 0.8;
	DropDownVisionSkill->WinLeft = 0.05;
	DropDownVisionSkill->WinWidth = 0.4;
	DropDownVisionSkill->WinHeight = 0.04;
	DropDownVisionSkill->TabOrder = 21;
	DropDownVisionSkill->bStandardized = false;
	//DropDownVisionSkill->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownHearingSkill = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownHearingSkill->CaptionWidth = 0.28;
	DropDownHearingSkill->Caption = "Hearing Range:";
	//DropDownHearingSkill->OnCreateComponent=DropDownHearingSkill.InternalOnCreateComponent;
	DropDownHearingSkill->IniOption = "@Internal";
	DropDownHearingSkill->Hint = "Select how far away the NPC hears actions in meters (note that vehicles and gunshots are heard at 1.5 times this distance).  The default is 10 meters for more NPCs.";
	DropDownHearingSkill->WinTop = 0.8;
	DropDownHearingSkill->WinLeft = 0.5;
	DropDownHearingSkill->WinWidth = 0.4;
	DropDownHearingSkill->WinHeight = 0.04;
	DropDownHearingSkill->TabOrder = 22;
	DropDownHearingSkill->bStandardized = false;
	//DropDownHearingSkill->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownPlatoon = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownPlatoon->CaptionWidth = 0.28;
	DropDownPlatoon->Caption = "Platoon:";
	//DropDownPlatoon->OnCreateComponent=DropDownPlatoon.InternalOnCreateComponent;
	DropDownPlatoon->IniOption = "@Internal";
	DropDownPlatoon->Hint = "Select platoon this NPC belongs to.";
	DropDownPlatoon->WinTop = 0.85;
	DropDownPlatoon->WinLeft = 0.05;
	DropDownPlatoon->WinWidth = 0.25;
	DropDownPlatoon->WinHeight = 0.04;
	DropDownPlatoon->TabOrder = 21;
	DropDownPlatoon->bStandardized = false;
	//DropDownPlatoon->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownSquad = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownSquad->CaptionWidth = 0.28;
	DropDownSquad->Caption = "Squad:";
	//DropDownSquad->OnCreateComponent=DropDownSquad.InternalOnCreateComponent;
	DropDownSquad->IniOption = "@Internal";
	DropDownSquad->Hint = "Select the squad this NPC will belong to.";
	DropDownSquad->WinTop = 0.85;
	DropDownSquad->WinLeft = 0.4;
	DropDownSquad->WinWidth = 0.2;
	DropDownSquad->WinHeight = 0.04;
	DropDownSquad->TabOrder = 22;
	DropDownSquad->bStandardized = false;
	//DropDownSquad->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UmoComboBox* DropDownFireteam = NewObject<UmoComboBox>(UmoComboBox::StaticClass());
	DropDownFireteam->CaptionWidth = 0.28;
	DropDownFireteam->Caption = "Fireteam:";
	//DropDownFireteam->OnCreateComponent=DropDownFireteam.InternalOnCreateComponent;
	DropDownFireteam->IniOption = "@Internal";
	DropDownFireteam->Hint = "Select the firetaem this NPC will belong to.";
	DropDownFireteam->WinTop = 0.85;
	DropDownFireteam->WinLeft = 0.7;
	DropDownFireteam->WinWidth = 0.25;
	DropDownFireteam->WinHeight = 0.04;
	DropDownFireteam->TabOrder = 22;
	DropDownFireteam->bStandardized = false;
	//DropDownFireteam->OnChange=AANPCPNB_PlayerStartOptions.InternalOnChange;
	UGUILabel* CPTitle = NewObject<UGUILabel>(UGUILabel::StaticClass());
	CPTitle->Caption = "AA NPC Path Builder NPCPlayerStart Options";
	CPTitle->TextAlign = ETextAlign::TXTA_Right;
	CPTitle->TextColor = FColor(200, 200, 200, 255);
	CPTitle->TextFont = "AAFontMedium";
	CPTitle->bMultiLine = true;
	CPTitle->WinTop = 0.028334;
	CPTitle->WinLeft = 0.5;
	CPTitle->WinWidth = 0.49;
	CPTitle->WinHeight = 0.1;
	guibtnSaveChanges = ButtonSave;
	guibtnClose = CloseButton;
	guilTitle = CPTitle;
	mebDisplayName = EntryFieldDisplayName;
	mebWaypointTag = EntryFieldWaypointTag;
	mcbFace = DropDownFaceSkin;
	mcbShirt = DropDownShirtSkin;
	mcbPants = DropDownPantsSkin;
	mcbHands = DropDownHandsSkin;
	mcbHeadgear = DropDownHeadGear;
	mchkbSpawnAsReserve = CheckboxSpawnAsReserve;
	mchkbSpawnRandomLocation = CheckboxSpawnRandomLocation;
	mchkbAutoReversePath = CheckboxAutoReversePatrolPath;
	mchkbPatrolAscending = CheckboxPatrolAscendingOrder;
	mcbSpawnChance = DropDownSpawnChance;
	mcbInitialOrders = DropDownInitialOrders;
	mcbPrimaryWeapon = DropDownPrimaryWeapon;
	mchkbHasBinoculars = CheckboxHasBinoculars;
	mcbSecondaryWeapon = DropDownSecondaryWeapon;
	mcbPrimaryWeaponReloads = DropDownPrimaryWeaponReloads;
	mcbSecondaryWeaponReloads = DropDownSecondaryWeaponReloads;
	mcbFragGrenades = DropDownFragGrenades;
	mcbSmokeGrenades = DropDownSmokeGrenades;
	mcbWeaponSkill = DropDownWeaponSkill;
	mcbVisionSkill = DropDownVisionSkill;
	mcbHearingRange = DropDownHearingSkill;
	mcbExperience = DropDownExperience;
	mcbPlatoon = DropDownPlatoon;
	mcbSquad = DropDownSquad;
	mcbFireteam = DropDownFireteam;
	WinHeight = 1;
}

void UAANPCPNB_PlayerStartOptions::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local StudentController SC;
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	SC = StudentController(PlayerOwner());
	SC.ClientMessage("Editing NPC Player Start");
	AGP_HUD(SC.myHUD).bShowHUD = false;
	Log("PlayerOwner: " $ string(PlayerOwner()) $ ", StudentController: " $ string(SC));
	Log("HUD text: " $ SC.npcpnbPathNodeBuilder.npcpsBeingEdited.HUDText);
	Log("Waypoint Tag: " $ SC.npcpnbPathNodeBuilder.npcpsBeingEdited.HUDText);
	mebDisplayName.SetComponentValue(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.HUDText, true);
	mebWaypointTag.SetComponentValue(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.sNPCWaypointTag, true);
	mcbFace.MyComboBox.List.Insert(0, "Default", , "Default");
	mcbFace.MyComboBox.Edit.bReadOnly = true;
	mcbPants.MyComboBox.List.Insert(0, "Default", , "Default");
	mcbPants.MyComboBox.Edit.bReadOnly = true;
	mcbShirt.MyComboBox.List.Insert(0, "Default", , "Default");
	mcbShirt.MyComboBox.Edit.bReadOnly = true;
	mcbHands.MyComboBox.List.Insert(0, "Default", , "Default");
	mcbHands.MyComboBox.Edit.bReadOnly = true;
	i = 0;
	if (i <= 100)
	{
		mcbHearingRange.MyComboBox.List.Insert(i, "" $ string(i) $ "m", , "" $ string(i));
		i += 5;
	}
	mcbHearingRange.MyComboBox.Edit.bReadOnly = true;
	mcbHearingRange.SetText("" $ string(int(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpNPCHearingRadius)));
	mcbHearingRange.SetIndex((int(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpNPCHearingRadius) / 5));
	mcbInitialOrders.MyComboBox.List.Insert(0, "Patrol", , "Patrol");
	mcbInitialOrders.MyComboBox.List.Insert(1, "Guard", , "Guard");
	mcbInitialOrders.MyComboBox.List.Insert(2, "Ambush", , "Ambush");
	mcbInitialOrders.MyComboBox.List.Insert(3, "Harass", , "Harass");
	mcbInitialOrders.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcoPrimaryOrders);
	i = 0;
	if (i <= 100)
	{
		mcbSpawnChance.MyComboBox.List.Insert(i, "" $ string(i) $ "%", , "" $ string(i));
		i += 5;
	}
	mcbSpawnChance.MyComboBox.Edit.bReadOnly = true;
	mcbSpawnChance.SetText("" $ string(int(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpChanceOfSpawning)));
	mcbSpawnChance.SetIndex((int(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpChanceOfSpawning) / 5));
	mcbVisionSkill.MyComboBox.List.Insert(0, "Perfect", , "" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.1));
	mcbVisionSkill.MyComboBox.List.Insert(1, "Execellent", , "" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.2));
	mcbVisionSkill.MyComboBox.List.Insert(2, "Superior", , "" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.3));
	mcbVisionSkill.MyComboBox.List.Insert(3, "Good", , "" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.4));
	mcbVisionSkill.MyComboBox.List.Insert(4, "Average", , "" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.5));
	mcbVisionSkill.MyComboBox.List.Insert(5, "Poor", , "" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.6));
	mcbVisionSkill.MyComboBox.List.Insert(6, "Bad", , "" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.7));
	mcbVisionSkill.MyComboBox.List.Insert(7, "Blind", , "" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.8));
	mcbVisionSkill.MyComboBox.List.SetIndex((SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility - 1));
	mcbVisionSkill.MyComboBox.Edit.bReadOnly = true;
	if (SC.npcpnbPathNodeBuilder.npcpsBeingEdited.IsA('NPCPlayerStartSoldier'))
	{
		mcbHeadgear.MyComboBox.Edit.bReadOnly = true;
		mcbHeadgear.MyComboBox.List.Insert(0, "None", , "0");
		mcbHeadgear.MyComboBox.List.Insert(1, "None", , "1");
		mcbHeadgear.MyComboBox.List.Insert(2, "WatchCap Black", , "2");
		mcbHeadgear.MyComboBox.List.Insert(3, "Beret", , "3");
		mcbHeadgear.MyComboBox.List.Insert(4, "Beanie", , "4");
		mcbHeadgear.MyComboBox.List.Insert(5, "Helmet", , "5");
		mcbHeadgear.MyComboBox.List.Insert(6, "Patrol Cap", , "6");
		mcbHeadgear.MyComboBox.List.Insert(7, "Patrol Cap Black", , "7");
		mcbHeadgear.MyComboBox.List.Insert(8, "Jungle Hat", , "8");
		mcbHeadgear.MyComboBox.List.Insert(9, "Jungle Hat Black", , "9");
		mcbHeadgear.MyComboBox.List.SetIndex(NPCPlayerStartSoldier(SC.npcpnbPathNodeBuilder.npcpsBeingEdited).eshgHeadGear);
		mcbPrimaryWeapon.MyComboBox.Edit.bReadOnly = true;
		mcbPrimaryWeapon.MyComboBox.List.Insert(0, "Default", , "Default");
		mcbPrimaryWeapon.MyComboBox.List.Insert(1, "AK47", , "AGP_Inventory.Weapon_AK47_Rifle");
		mcbPrimaryWeapon.MyComboBox.List.Insert(2, "RPK", , "AGP_Inventory.Weapon_RPK_SAW");
		mcbPrimaryWeapon.MyComboBox.List.Insert(3, "AK47su", , "AGP_Inventory.Weapon_AK47_suRifle");
		mcbPrimaryWeapon.MyComboBox.List.Insert(4, "GP30", , "AGP_Inventory.Weapon_GP30_Gren");
		mcbPrimaryWeapon.MyComboBox.List.Insert(5, "RPG", , "AGP_Inventory.Weapon_NPC_RPG7_rocket");
		mcbPrimaryWeapon.MyComboBox.List.Insert(6, "Vintorez", , "AGP_Inventory.Weapon_Vintorez_Sniper");
		Log("Primary weapon: " $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.namePrimaryWeapon));
		if (string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.namePrimaryWeapon) ~= "None")
		{
			mcbPrimaryWeapon.SetText("Default");
		}
		else
		{
			mcbPrimaryWeapon.SetText(WeaponClassToLabel(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.namePrimaryWeapon));
			mcbPrimaryWeapon.SetIndex(WeaponClassToIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.namePrimaryWeapon));
		}
		mcbSecondaryWeapon.MyComboBox.Edit.bReadOnly = true;
		mcbSecondaryWeapon.MyComboBox.List.Insert(0, "Default", , "Default");
		mcbSecondaryWeapon.MyComboBox.List.Insert(1, "AK47", , "AGP_Inventory.Weapon_AK47_Rifle");
		mcbSecondaryWeapon.MyComboBox.List.Insert(2, "RPK", , "AGP_Inventory.Weapon_RPK_SAW");
		mcbSecondaryWeapon.MyComboBox.List.Insert(3, "AK74su", , "AGP_Inventory.Weapon_AK74su_Rifle");
		mcbSecondaryWeapon.MyComboBox.List.Insert(4, "GP30", , "AGP_Inventory.Weapon_GP30_Gren");
		mcbSecondaryWeapon.MyComboBox.List.Insert(5, "RPG", , "AGP_Inventory.Weapon_NPC_RPG7_rocket");
		mcbSecondaryWeapon.MyComboBox.List.Insert(6, "Vintorez", , "AGP_Inventory.Weapon_Vintorez_Sniper");
		Log("Secondary weapon: " $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.nameSecondaryWeapon));
		if (string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.nameSecondaryWeapon) ~= "None")
		{
			mcbSecondaryWeapon.SetText("Default");
		}
		else
		{
			mcbSecondaryWeapon.SetText(WeaponClassToLabel(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.nameSecondaryWeapon));
			mcbSecondaryWeapon.SetIndex(WeaponClassToIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.nameSecondaryWeapon));
		}
		Log("Primary weapon reloads: " $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iPrimaryWeaponReloads));
		for (i = 0; i <= 10; i++)
		{
			mcbPrimaryWeaponReloads.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
		}
		mcbPrimaryWeaponReloads.MyComboBox.List.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iPrimaryWeaponReloads);
		mcbPrimaryWeaponReloads.MyComboBox.Edit.bReadOnly = true;
		mcbPrimaryWeaponReloads.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iPrimaryWeaponReloads);
		for (i = 0; i <= 10; i++)
		{
			mcbSecondaryWeaponReloads.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
		}
		mcbSecondaryWeaponReloads.MyComboBox.List.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSecondaryWeaponReloads);
		mcbSecondaryWeaponReloads.MyComboBox.Edit.bReadOnly = true;
		mcbSecondaryWeaponReloads.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSecondaryWeaponReloads);
		mcbFragGrenades.MyComboBox.Edit.bReadOnly = true;
		for (i = 0; i <= 10; i++)
		{
			mcbFragGrenades.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
		}
		mcbFragGrenades.SetText("" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iFragGrenadeCount), true);
		mcbFragGrenades.MyComboBox.Edit.bReadOnly = true;
		mcbFragGrenades.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iFragGrenadeCount);
		mcbSmokeGrenades.MyComboBox.Edit.bReadOnly = true;
		for (i = 0; i <= 10; i++)
		{
			mcbSmokeGrenades.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
		}
		mcbSmokeGrenades.SetText("" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSmokeGrenadeCount), true);
		mcbSmokeGrenades.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSmokeGrenadeCount);
		mcbSmokeGrenades.MyComboBox.Edit.bReadOnly = true;
		mchkbHasBinoculars.SetComponentValue(string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bHasBinoculars), true);
		mcbWeaponSkill.MyComboBox.Edit.bReadOnly = true;
		i = 0;
		if (i <= 100)
		{
			mcbWeaponSkill.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
			i += 5;
		}
		mcbWeaponSkill.SetText("" $ string(int(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpNPCWeaponAccuracy)), true);
		mcbWeaponSkill.SetIndex((int(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpNPCWeaponAccuracy) / 5));
		mcbWeaponSkill.MyComboBox.Edit.bReadOnly = true;
		mcbWeaponSkill.SetIndex((int(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpNPCWeaponAccuracy) / 5));
		for (i = 0; i < 8; i++)
		{
			mcbPlatoon.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
		}
		mcbPlatoon.SetText("" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iPlatoonID), true);
		mcbPlatoon.MyComboBox.Edit.bReadOnly = true;
		mcbPlatoon.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iPlatoonID);
		for (i = 0; i < 8; i++)
		{
			mcbSquad.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
		}
		mcbSquad.SetText("" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSquadID), true);
		mcbSquad.MyComboBox.Edit.bReadOnly = true;
		mcbSquad.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSquadID);
		for (i = 0; i < 8; i++)
		{
			mcbFireteam.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
		}
		mcbFireteam.SetText("" $ string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iFireteamID), true);
		mcbFireteam.MyComboBox.Edit.bReadOnly = true;
		mcbFireteam.SetIndex(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iFireteamID);
	}
	else
	{
		mcbHeadgear.DisableMe();
		mcbPrimaryWeapon.DisableMe();
		mcbPrimaryWeaponReloads.DisableMe();
		mcbSecondaryWeapon.DisableMe();
		mcbSecondaryWeaponReloads.DisableMe();
		mcbFragGrenades.DisableMe();
		mcbSmokeGrenades.DisableMe();
		mcbWeaponSkill.DisableMe();
		mchkbHasBinoculars.DisableMe();
		mcbFireteam.DisableMe();
		mcbSquad.DisableMe();
		mcbPlatoon.DisableMe();
	}
	i = 0;
	if (i <= 100)
	{
		mcbExperience.MyComboBox.List.Insert(i, "" $ string(i), , "" $ string(i));
		i += 5;
	}
	mcbExperience.SetText("" $ string(int(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fNPCExperience)), true);
	mcbExperience.MyComboBox.Edit.bReadOnly = true;
	mchkbSpawnAsReserve.SetComponentValue(string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bSpawnAsReserve), true);
	mchkbSpawnRandomLocation.SetComponentValue(string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bStartAndSpawnAtRandomNode), true);
	mchkbAutoReversePath.SetComponentValue(string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bAutoReversePath), true);
	mchkbPatrolAscending.SetComponentValue(string(SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bAscendingNodeDirection), true);
	*/
}

int32 UAANPCPNB_PlayerStartOptions::WeaponClassToIndex(UObject*  nameWeaponClass)
{
	/*
	Log("Weapon class \"" $ string(nameWeaponClass) $ "\"");
	if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_AK47_Rifle")
	{
		return 1;
	}
	else
	{
		if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_RPK_SAW")
		{
			return 2;
		}
		else
		{
			if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_AK74su_Rifle")
			{
				return 3;
			}
			else
			{
				if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_GP30_Gren")
				{
					return 4;
				}
				else
				{
					if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_NPC_RPG7_rocket")
					{
						return 5;
					}
					else
					{
						if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_Vintorez_Sniper")
						{
							return 6;
						}
						else
						{
							return 0;
						}
					}
				}
			}
		}
	}
	*/
	return 0;    //FAKE   /ELiZ
}

FString UAANPCPNB_PlayerStartOptions::WeaponClassToLabel(UObject*  nameWeaponClass)
{
	/*
	Log("Weapon class \"" $ string(nameWeaponClass) $ "\"");
	if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_AK47_Rifle")
	{
		return "AK47";
	}
	else
	{
		if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_RPK_SAW")
		{
			return "RPK";
		}
		else
		{
			if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_AK74su_Rifle")
			{
				return "AK74su";
			}
			else
			{
				if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_GP30_Gren")
				{
					return "GP30";
				}
				else
				{
					if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_NPC_RPG7_rocket")
					{
						return "RPG";
					}
					else
					{
						if (string(nameWeaponClass) ~= "AGP_Inventory.Weapon_Vintorez_Sniper")
						{
							return "Vintorez";
						}
						else
						{
							return "Default";
						}
					}
				}
			}
		}
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

void UAANPCPNB_PlayerStartOptions::OnOpen()
{
	/*
	local AGP_HUD HUD;
	Super::OnOpen();
	HUD = AGP_HUD(PlayerOwner().myHUD);
	bPlayerHUD = HUD.bShowHUD;
	HUD.bShowVersion = true;
	HUD.bShowSpectatorInfo = false;
	HUD.bShowHUD = false;
	*/
}

void UAANPCPNB_PlayerStartOptions::OnClose(bool bCanceled)
{
	/*
	local AGP_HUD HUD;
	local PlayerController PC;
	PC = PlayerOwner();
	HumanController(PlayerOwner()).guipCommandPost = None;
	Super::OnClose(bCanceled);
	HUD = AGP_HUD(PlayerOwner().myHUD);
	HUD.bShowVersion = false;
	HUD.bShowSpectatorInfo = true;
	HUD.bShowHUD = bPlayerHUD;
	*/
}

bool UAANPCPNB_PlayerStartOptions::OnCanClose(bool bCancelled)
{
	return true;
}

bool UAANPCPNB_PlayerStartOptions::ButtonClick(UGUIComponent* Sender)
{
	/*
	local StudentController SC;
	SC = StudentController(PlayerOwner());
	switch (Sender)
	{
	case guibtnSaveChanges:
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.HUDText = mebDisplayName.GetText();
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.sNPCWaypointTag = mebWaypointTag.GetText();
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpNPCHearingRadius = float(mcbHearingRange.GetText());
		switch (mcbVisionSkill.GetIndex())
		{
		case 0:
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility = SC.npcpnbPathNodeBuilder.npcpsBeingEdited.1;
			break;
		case 1:
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility = SC.npcpnbPathNodeBuilder.npcpsBeingEdited.2;
			break;
		case 2:
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility = SC.npcpnbPathNodeBuilder.npcpsBeingEdited.3;
			break;
		case 3:
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility = SC.npcpnbPathNodeBuilder.npcpsBeingEdited.4;
			break;
		case 4:
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility = SC.npcpnbPathNodeBuilder.npcpsBeingEdited.5;
			break;
		case 5:
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility = SC.npcpnbPathNodeBuilder.npcpsBeingEdited.6;
			break;
		case 6:
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility = SC.npcpnbPathNodeBuilder.npcpsBeingEdited.7;
			break;
		case 7:
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.enpcvaVisionAbility = SC.npcpnbPathNodeBuilder.npcpsBeingEdited.8;
			break;
		default:
		}
		if (SC.npcpnbPathNodeBuilder.npcpsBeingEdited.IsA('NPCPlayerStartSoldier'))
		{
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.namePrimaryWeapon = class<AGP_Weapon>(DynamicLoadObject(mcbPrimaryWeapon.GetExtra(), Class'Class'));
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.nameSecondaryWeapon = class<AGP_Weapon>(DynamicLoadObject(mcbSecondaryWeapon.GetExtra(), Class'Class'));
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iPrimaryWeaponReloads = int(mcbPrimaryWeaponReloads.GetText());
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSecondaryWeaponReloads = int(mcbSecondaryWeaponReloads.GetText());
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iFragGrenadeCount = int(mcbFragGrenades.GetText());
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSmokeGrenadeCount = int(mcbSmokeGrenades.GetText());
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bHasBinoculars = mchkbHasBinoculars.IsChecked();
			SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpNPCWeaponAccuracy = float(mcbWeaponSkill.GetText());
		}
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iPlatoonID = int(mcbPlatoon.GetText());
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iSquadID = int(mcbSquad.GetText());
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.iFireteamID = int(mcbFireteam.GetText());
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fNPCExperience = float(mcbExperience.GetText());
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bSpawnAsReserve = mchkbSpawnAsReserve.IsChecked();
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bStartAndSpawnAtRandomNode = mchkbSpawnRandomLocation.IsChecked();
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bAutoReversePath = mchkbAutoReversePath.IsChecked();
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.bAscendingNodeDirection = mchkbPatrolAscending.IsChecked();
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.fpChanceOfSpawning = float(mcbSpawnChance.GetText());
		SC.npcpnbPathNodeBuilder.npcpsBeingEdited.SetInitialPrimaryOrders(mcbInitialOrders.GetIndex());
		AGP_HUD(SC.myHUD).bShowHUD = true;
		Sender.SetFocus(None);
		fCloseRequested = true;
		HumanController(PlayerOwner()).ClientCloseMenu(true);
		GOTO JL0755;
	case guibtnClose:
		AGP_HUD(SC.myHUD).bShowHUD = true;
		Sender.SetFocus(None);
		fCloseRequested = true;
		HumanController(PlayerOwner()).ClientCloseMenu(true);
		GOTO JL0755;
	default:
	JL0755:
		return true;
	}
	*/
	return false;    //FAKE   /ELiZ
}

void UAANPCPNB_PlayerStartOptions::InternalOnChange(UGUIComponent* Sender)
{
}