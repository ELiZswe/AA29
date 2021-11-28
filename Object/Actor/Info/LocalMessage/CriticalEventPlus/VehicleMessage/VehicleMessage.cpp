// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/VehicleMessage/VehicleMessage.h"

AVehicleMessage::AVehicleMessage()
{
	RedTeamDominatesString = "Red Team Achieves Victory!";
	BlueTeamDominatesString = "Blue Team Achieves Victory!";
	RedTeamPowerCoreString = "Red Team PowerNode Constructed!";
	BlueTeamPowerCoreString = "Blue Team PowerNode Constructed!";
	VehicleLockedString = "Vehicle is Locked!";
	InvincibleCoreString = "You Are Unable To Damage Unlinked PowerNodes!";
	UnattainableNodeString = "You Are Unable To Obtain Unlinked PowerNodes!";
	RedPowerCoreAttackedString = "Red Team PowerCore is under Attack!";
	BluePowerCoreAttackedString = "Blue Team PowerCore is under Attack!";
	RedPowerNodeAttackedString = "Red Team PowerNode is under Attack!";
	BluePowerNodeAttackedString = "Blue Team PowerNode is under Attack!";
	InWayOfVehicleSpawnString = "You are in the way of a vehicle spawning!";
	MissileLockOnString = "Missile Lock-On!";
	UnpoweredString = "Turret is Unpowered!";
	RedPowerCoreDestroyedString = "Red PowerCore Destroyed";
	BluePowerCoreDestroyedString = "Blue PowerCore Destroyed";
	RedPowerNodeDestroyedString = "Red PowerNode Destroyed";
	BluePowerNodeDestroyedString = "Blue PowerNode Destroyed";
	RedPowerCoreCriticalString = "Red PowerCore is Critical!";
	BluePowerCoreCriticalString = "Blue PowerCore is Critical!";
	PressUseToTeleportString = "Press Use to teleport to another node";
	RedPowerCoreVulnerableString = "Red PowerCore is Vulnerable!";
	BluePowerCoreVulnerableString = "Blue PowerCore is Vulnerable!";
	RedPowerNodeUnderConstructionString = "Red PowerNode under Construction!";
	BluePowerNodeUnderConstructionString = "Blue PowerNode under Construction!";
	RedPowerCoreDamagedString = "Red PowerCore is at 50%!";
	BluePowerCoreDamagedString = "Blue PowerCore is at 50%!";
	RedPowerNodeSeveredString = "Red PowerNode Isolated!";
	BluePowerNodeSeveredString = "Blue PowerNode Isolated!";
	PowerCoresAreDrainingString = "PowerCores are draining!";
	UnhealablePowerCoreString = "You can't heal your PowerCore!";
	AvrilLockOnString = "Incoming Heat-Seeking Missile!";
	CameraDeploy = "Press Alt-Fire to deploy camera!";
	MoveReticle = "Use Forward and Strafe to Aim Reticle";
	SPMAAcquiredString = "SPMA Acquired";
	MessageAnnouncements = { "", "", "", "", "", "", "","Red_Powercore_under_attack","Blue_Powercore_under_attack","","","","","","Red_Powercore_destroyed","Blue_Powercore_destroyed","Red_powernode_destroyed","Blue_powernode_destroyed","Red_Powercore_critical","Blue_Powercore_critical","Red_Powercore_vulnerable","Blue_Powercore_vulnerable","Red_powernode_under_construction","Blue_powernode_under_construction","Red_powercore_damaged","Blue_powercore_damaged","Red_powernode_isolated","Blue_powernode_isolated" };
	RedColor = FColor(0, 0, 255, 255);
	YellowColor = FColor(0, 255, 255, 255);
	bIsUnique = false;
	bIsPartiallyUnique = true;
	Lifetime = 2;
	StackMode =  EStackMode::SM_Down;
	PosY = 0.1;
}

void AVehicleMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	if (p.bViewingMatineeCinematic)
	{
		Return;
	}
	ClientReceive(p, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	if (Default.MessageAnnouncements[Switch] != 'None')
	{
		p.PlayStatusAnnouncement(Default.MessageAnnouncements[Switch], 2, true);
	}
	if (p.PlayerReplicationInfo != None && p.PlayerReplicationInfo.Team != None && p.PlayerReplicationInfo.Team.TeamIndex == Switch)
	{
		p.ClientPlaySound(Default.VictorySound);
	}
	*/
}
void AVehicleMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	switch(Switch)
	{
			case 0:
				Return Default.RedTeamDominatesString;
				break;
			case 1:
				Return Default.BlueTeamDominatesString;
				break;
			case 2:
				Return Default.RedTeamPowerCoreString;
				break;
			case 3:
				Return Default.BlueTeamPowerCoreString;
				break;
			case 4:
				Return Default.VehicleLockedString;
				break;
			case 5:
				Return Default.InvincibleCoreString;
				break;
			case 6:
				Return Default.UnattainableNodeString;
				break;
			case 7:
				Return Default.RedPowerCoreAttackedString;
				break;
			case 8:
				Return Default.BluePowerCoreAttackedString;
				break;
			case 9:
				Return Default.RedPowerNodeAttackedString;
				break;
			case 10:
				Return Default.BluePowerNodeAttackedString;
				break;
			case 11:
				Return Default.InWayOfVehicleSpawnString;
				break;
			case 12:
				Return Default.MissileLockOnString;
				break;
			case 13:
				Return Default.UnpoweredString;
				break;
			case 14:
				Return Default.RedPowerCoreDestroyedString;
				break;
			case 15:
				Return Default.BluePowerCoreDestroyedString;
				break;
			case 16:
				Return Default.RedPowerNodeDestroyedString;
				break;
			case 17:
				Return Default.BluePowerNodeDestroyedString;
				break;
			case 18:
				Return Default.RedPowerCoreCriticalString;
				break;
			case 19:
				Return Default.BluePowerCoreCriticalString;
				break;
			case 20:
				Return Default.RedPowerCoreVulnerableString;
				break;
			case 21:
				Return Default.BluePowerCoreVulnerableString;
				break;
			case 22:
				Return Default.PressUseToTeleportString;
				break;
			case 23:
				Return Default.RedPowerNodeUnderConstructionString;
				break;
			case 24:
				Return Default.BluePowerNodeUnderConstructionString;
				break;
			case 25:
				Return Default.RedPowerCoreDamagedString;
				break;
			case 26:
				Return Default.BluePowerCoreDamagedString;
				break;
			case 27:
				Return Default.RedPowerNodeSeveredString;
				break;
			case 28:
				Return Default.BluePowerNodeSeveredString;
				break;
			case 29:
				Return Default.PowerCoresAreDrainingString;
				break;
			case 30:
				Return Default.UnhealablePowerCoreString;
				break;
			case 31:
				Return Default.AvrilLockOnString;
				break;
			case 32:
				Return Default.SPMAAcquiredString;
				break;
			case 33:
				Return Default.MoveReticle;
				break;
			case 34:
				Return Default.CameraDeploy;
				break;
			default:
	}
	Return "";
	*/
}
void AVehicleMessage::GetColor(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2)
{
	/*
	if (Switch > 6 && Switch < 11 || Switch == 12 || Switch > 17 && Switch < 22 || Switch > 24)
	{
		Return Default.RedColor;
	}
	else
	{
		if (Switch == 11)
		{
			Return Default.YellowColor;
		}
		else
		{
			Return Default.DrawColor;
		}
	}
	*/
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
void AVehicleMessage::GetLifeTime(int32 Switch)
{
	/*
	if (Switch == 29)
	{
		Return 4;
	}
	Return Default.Lifetime;
	*/
}
void AVehicleMessage::IsConsoleMessage(int32 Switch)
{
	/*
	if (Switch < 5 || Switch > 12 && Switch < 18 || Switch > 19 && Switch < 24 && Switch != 22 || Switch > 25)
	{
		Return True;
	}
	Return False;
	*/
}