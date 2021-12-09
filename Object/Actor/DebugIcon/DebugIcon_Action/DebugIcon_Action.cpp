// All the original content belonged to the US Army


#include "AA29/Object/Actor/DebugIcon/DebugIcon_Action/DebugIcon_Action.h"

ADebugIcon_Action::ADebugIcon_Action()
{
	Action_Advance_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_advance_Mat.action_advance_Mat"), NULL, LOAD_None, NULL);
	Action_Breakout_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_breakout_Mat.action_breakout_Mat"), NULL, LOAD_None, NULL);
	Action_Collapse_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_collapse_Mat.action_collapse_Mat"), NULL, LOAD_None, NULL);
	Action_Cower_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_cower_Mat.action_cower_Mat"), NULL, LOAD_None, NULL);
	Action_Duck_Tex				= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_duck_Mat.action_duck_Mat"), NULL, LOAD_None, NULL);
	Action_Engage_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_engage_Mat.action_engage_Mat"), NULL, LOAD_None, NULL);
	Action_Fallback_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_fallback_Mat.action_fallback_Mat"), NULL, LOAD_None, NULL);
	Action_Fireblind_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_fireblind_Mat.action_fireblind_Mat"), NULL, LOAD_None, NULL);
	Action_Flank_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_flank_Mat.action_flank_Mat"), NULL, LOAD_None, NULL);
	Action_Ivan_Tex				= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_ivan_Mat.action_ivan_Mat"), NULL, LOAD_None, NULL);
	Action_Pursue_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_pursue_Mat.action_pursue_Mat"), NULL, LOAD_None, NULL);
	Action_Reload_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_reload_Mat.action_reload_Mat"), NULL, LOAD_None, NULL);
	Action_Rush_Tex				= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_rush_Mat.action_rush_Mat"), NULL, LOAD_None, NULL);
	Action_Scan_Tex				= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_scan_Mat.action_scan_Mat"), NULL, LOAD_None, NULL);
	Action_SeekCover_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_seekcover_Mat.action_seekcover_Mat"), NULL, LOAD_None, NULL);
	Action_Shift_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_shift_Mat.action_shift_Mat"), NULL, LOAD_None, NULL);
	Action_Suppress_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_supress_Mat.action_supress_Mat"), NULL, LOAD_None, NULL);
	Action_Surrender_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_surrender_Mat.action_surrender_Mat"), NULL, LOAD_None, NULL);
	Action_Switch_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_switch_Mat.action_switch_Mat"), NULL, LOAD_None, NULL);
	Action_Taunt_Tex			= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_taunt_Mat.action_taunt_Mat"), NULL, LOAD_None, NULL);
	Action_ThrowFrag_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_throwfrag_Mat.action_throwfrag_Mat"), NULL, LOAD_None, NULL);
	Action_ThrowSmoke_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_throwsmoke_Mat.action_throwsmoke_Mat"), NULL, LOAD_None, NULL);
	Action_ResumePatrol_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_resumepatrol_Mat.action_resumepatrol_Mat"), NULL, LOAD_None, NULL);
	Action_RunFromGrenade_Tex	= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_rungrenade_Mat.action_rungrenade_Mat"), NULL, LOAD_None, NULL);
	Action_DoNothing_Tex		= LoadObject<UMaterialInstance>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/IconsAI/action_donothing_Mat.action_donothing_Mat"), NULL, LOAD_None, NULL);
	Texture						= Action_DoNothing_Tex;
}
void ADebugIcon_Action::UpdateAction(FString NewAction)
{
	if (NewAction == "Advance")			{		Texture = Action_Advance_Tex;		return; }
	if (NewAction == "SupressEnemy")	{		Texture = Action_Suppress_Tex;		return; }
	if (NewAction == "ThrowFrag")		{		Texture = Action_ThrowFrag_Tex;		return; }
	if (NewAction == "ThrowSmoke")		{		Texture = Action_ThrowSmoke_Tex;	return;	}
	if (NewAction == "CrazyIvan")		{		Texture = Action_Ivan_Tex;			return;	}
	if (NewAction == "SwitchWeapons")	{		Texture = Action_Switch_Tex;		return;	}
	if (NewAction == "PursueEnemy")		{		Texture = Action_Pursue_Tex;		return;	}
	if (NewAction == "FallBack")		{		Texture = Action_Fallback_Tex;		return;	}
	if (NewAction == "FlankEnemy")		{		Texture = Action_Flank_Tex;			return;	}
	if (NewAction == "RushEnemy")		{		Texture = Action_Rush_Tex;			return;	}
	if (NewAction == "TauntEnemy")		{		Texture = Action_Taunt_Tex;			return;	}
	if (NewAction == "SeekCover")		{		Texture = Action_SeekCover_Tex;		return;	}
	if (NewAction == "DuckAndCover")	{		Texture = Action_Duck_Tex;			return;	}
	if (NewAction == "Collapse")		{		Texture = Action_Collapse_Tex;		return;	}
	if (NewAction == "Surrender")		{		Texture = Action_Surrender_Tex;		return;	}
	if (NewAction == "FireBlindly")		{		Texture = Action_Fireblind_Tex;		return;	}
	if (NewAction == "BreakOut")		{		Texture = Action_Breakout_Tex;		return;	}
	if (NewAction == "ReloadWeapon")	{		Texture = Action_Reload_Tex;		return;	}
	if (NewAction == "ShiftPosition")	{		Texture = Action_Shift_Tex;			return;	}
	if (NewAction == "ScanForEnemy")	{		Texture = Action_Scan_Tex;			return;	}
	if (NewAction == "EngageEnemy")		{		Texture = Action_Engage_Tex;		return;	}
	if (NewAction == "ReturnToPatrol")	{		Texture = Action_ResumePatrol_Tex;	return;	}
	if (NewAction == "RunFromGrenade")	{		Texture = Action_RunFromGrenade_Tex;return;	}
	Texture = Action_DoNothing_Tex;
}


