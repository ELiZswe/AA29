// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/VehicleMessage/VehicleMessage.h"

AVehicleMessage::AVehicleMessage()
{
	MessageAnnouncements.SetNum(35);
	RedTeamDominatesString					= "Red Team Achieves Victory!";
	BlueTeamDominatesString					= "Blue Team Achieves Victory!";
	RedTeamPowerCoreString					= "Red Team PowerNode Constructed!";
	BlueTeamPowerCoreString					= "Blue Team PowerNode Constructed!";
	VehicleLockedString						= "Vehicle is Locked!";
	InvincibleCoreString					= "You Are Unable To Damage Unlinked PowerNodes!";
	UnattainableNodeString					= "You Are Unable To Obtain Unlinked PowerNodes!";
	RedPowerCoreAttackedString				= "Red Team PowerCore is under Attack!";
	BluePowerCoreAttackedString				= "Blue Team PowerCore is under Attack!";
	RedPowerNodeAttackedString				= "Red Team PowerNode is under Attack!";
	BluePowerNodeAttackedString				= "Blue Team PowerNode is under Attack!";
	InWayOfVehicleSpawnString				= "You are in the way of a vehicle spawning!";
	MissileLockOnString						= "Missile Lock-On!";
	UnpoweredString							= "Turret is Unpowered!";
	RedPowerCoreDestroyedString				= "Red PowerCore Destroyed";
	BluePowerCoreDestroyedString			= "Blue PowerCore Destroyed";
	RedPowerNodeDestroyedString				= "Red PowerNode Destroyed";
	BluePowerNodeDestroyedString			= "Blue PowerNode Destroyed";
	RedPowerCoreCriticalString				= "Red PowerCore is Critical!";
	BluePowerCoreCriticalString				= "Blue PowerCore is Critical!";
	PressUseToTeleportString				= "Press Use to teleport to another node";
	RedPowerCoreVulnerableString			= "Red PowerCore is Vulnerable!";
	BluePowerCoreVulnerableString			= "Blue PowerCore is Vulnerable!";
	RedPowerNodeUnderConstructionString		= "Red PowerNode under Construction!";
	BluePowerNodeUnderConstructionString	= "Blue PowerNode under Construction!";
	RedPowerCoreDamagedString				= "Red PowerCore is at 50%!";
	BluePowerCoreDamagedString				= "Blue PowerCore is at 50%!";
	RedPowerNodeSeveredString				= "Red PowerNode Isolated!";
	BluePowerNodeSeveredString				= "Blue PowerNode Isolated!";
	PowerCoresAreDrainingString				= "PowerCores are draining!";
	UnhealablePowerCoreString				= "You can't heal your PowerCore!";
	AvrilLockOnString						= "Incoming Heat-Seeking Missile!";
	CameraDeploy							= "Press Alt-Fire to deploy camera!";
	MoveReticle								= "Use Forward and Strafe to Aim Reticle";
	SPMAAcquiredString						= "SPMA Acquired";
	MessageAnnouncements					= { "", "", "", "", "", "", "","Red_Powercore_under_attack","Blue_Powercore_under_attack","","","","","","Red_Powercore_destroyed","Blue_Powercore_destroyed","Red_powernode_destroyed","Blue_powernode_destroyed","Red_Powercore_critical","Blue_Powercore_critical","Red_Powercore_vulnerable","Blue_Powercore_vulnerable","Red_powernode_under_construction","Blue_powernode_under_construction","Red_powercore_damaged","Blue_powercore_damaged","Red_powernode_isolated","Blue_powernode_isolated" };
	RedColor								= FColor(0, 0, 255, 255);
	YellowColor								= FColor(0, 255, 255, 255);
	bIsUnique								= false;
	bIsPartiallyUnique						= true;
	Lifetime								= 2;
	StackMode								=  EStackMode::SM_Down;
	PosY									= 0.1;
}

void AVehicleMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	if (p.bViewingMatineeCinematic)
	{
		return;
	}
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (GetDefault<AVehicleMessage>()->MessageAnnouncements[Switch] != "None")
	{
		p.PlayStatusAnnouncement(GetDefault<AVehicleMessage>()->MessageAnnouncements[Switch], 2, true);
	}
	if (p.PlayerReplicationInfo != nullptr && p.PlayerReplicationInfo.Team != nullptr && p.PlayerReplicationInfo.Team.TeamIndex == Switch)
	{
		p.ClientPlaySound(GetDefault<AVehicleMessage>()->VictorySound);
	}
	*/
}

FString AVehicleMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	switch(Switch)
	{
		case 0:
			return GetDefault<AVehicleMessage>()->RedTeamDominatesString;
			break;
		case 1:
			return GetDefault<AVehicleMessage>()->BlueTeamDominatesString;
			break;
		case 2:
			return GetDefault<AVehicleMessage>()->RedTeamPowerCoreString;
			break;
		case 3:
			return GetDefault<AVehicleMessage>()->BlueTeamPowerCoreString;
			break;
		case 4:
			return GetDefault<AVehicleMessage>()->VehicleLockedString;
			break;
		case 5:
			return GetDefault<AVehicleMessage>()->InvincibleCoreString;
			break;
		case 6:
			return GetDefault<AVehicleMessage>()->UnattainableNodeString;
			break;
		case 7:
			return GetDefault<AVehicleMessage>()->RedPowerCoreAttackedString;
			break;
		case 8:
			return GetDefault<AVehicleMessage>()->BluePowerCoreAttackedString;
			break;
		case 9:
			return GetDefault<AVehicleMessage>()->RedPowerNodeAttackedString;
			break;
		case 10:
			return GetDefault<AVehicleMessage>()->BluePowerNodeAttackedString;
			break;
		case 11:
			return GetDefault<AVehicleMessage>()->InWayOfVehicleSpawnString;
			break;
		case 12:
			return GetDefault<AVehicleMessage>()->MissileLockOnString;
			break;
		case 13:
			return GetDefault<AVehicleMessage>()->UnpoweredString;
			break;
		case 14:
			return GetDefault<AVehicleMessage>()->RedPowerCoreDestroyedString;
			break;
		case 15:
			return GetDefault<AVehicleMessage>()->BluePowerCoreDestroyedString;
			break;
		case 16:
			return GetDefault<AVehicleMessage>()->RedPowerNodeDestroyedString;
			break;
		case 17:
			return GetDefault<AVehicleMessage>()->BluePowerNodeDestroyedString;
			break;
		case 18:
			return GetDefault<AVehicleMessage>()->RedPowerCoreCriticalString;
			break;
		case 19:
			return GetDefault<AVehicleMessage>()->BluePowerCoreCriticalString;
			break;
		case 20:
			return GetDefault<AVehicleMessage>()->RedPowerCoreVulnerableString;
			break;
		case 21:
			return GetDefault<AVehicleMessage>()->BluePowerCoreVulnerableString;
			break;
		case 22:
			return GetDefault<AVehicleMessage>()->PressUseToTeleportString;
			break;
		case 23:
			return GetDefault<AVehicleMessage>()->RedPowerNodeUnderConstructionString;
			break;
		case 24:
			return GetDefault<AVehicleMessage>()->BluePowerNodeUnderConstructionString;
			break;
		case 25:
			return GetDefault<AVehicleMessage>()->RedPowerCoreDamagedString;
			break;
		case 26:
			return GetDefault<AVehicleMessage>()->BluePowerCoreDamagedString;
			break;
		case 27:
			return GetDefault<AVehicleMessage>()->RedPowerNodeSeveredString;
			break;
		case 28:
			return GetDefault<AVehicleMessage>()->BluePowerNodeSeveredString;
			break;
		case 29:
			return GetDefault<AVehicleMessage>()->PowerCoresAreDrainingString;
			break;
		case 30:
			return GetDefault<AVehicleMessage>()->UnhealablePowerCoreString;
			break;
		case 31:
			return GetDefault<AVehicleMessage>()->AvrilLockOnString;
			break;
		case 32:
			return GetDefault<AVehicleMessage>()->SPMAAcquiredString;
			break;
		case 33:
			return GetDefault<AVehicleMessage>()->MoveReticle;
			break;
		case 34:
			return GetDefault<AVehicleMessage>()->CameraDeploy;
			break;
		default:
			break;
	}
	return "";
}

FColor AVehicleMessage::GetColor(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2)
{
	if (Switch > 6 && Switch < 11 || Switch == 12 || Switch > 17 && Switch < 22 || Switch > 24)
	{
		return GetDefault<AVehicleMessage>()->RedColor;
	}
	else
	{
		if (Switch == 11)
		{
			return GetDefault<AVehicleMessage>()->YellowColor;
		}
		else
		{
			return GetDefault<AVehicleMessage>()->DrawColor;
		}
	}
}

void AVehicleMessage::GetPos(int32 Switch, EDrawPivot &OutDrawPivot, EStackMode &OutStackMode, float &OutPosX, float &OutPosY)
{
	/*
	GetPos(Switch, OutDrawPivot, OutStackMode, OutPosX, OutPosY);
	if (Switch == 12 || Switch == 31 || Switch == 32)
	{
		OutPosY = 0.75;
	}
	else
	{
		if (Switch == 29)
		{
			OutPosY = 0.9;
		}
		else
		{
			if (Switch == 30)
			{
				OutPosY = 0.3;
			}
		}
	}
	*/
}

float AVehicleMessage::GetLifeTime(int32 Switch)
{
	if (Switch == 29)
	{
		return 4;
	}
	return GetDefault<AVehicleMessage>()->Lifetime;
}

bool AVehicleMessage::IsConsoleMessage(int32 Switch)
{
	if (Switch < 5 || Switch > 12 && Switch < 18 || Switch > 19 && Switch < 24 && Switch != 22 || Switch > 25)
	{
		return true;
	}
	return false;
}
