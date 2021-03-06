// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/SuperAdmin/SuperAdmin.h"
#include "AA29/Object/Actor/Extender/Extender.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "Engine/Canvas.h"

ASuperAdmin::ASuperAdmin()
{

}

/*
State Spectating
{
	simulated Function bool IsFrozen()
	{
		return false;
	}
}
*/

/*
replication
{
	reliable if ((Role < ROLE_Authority))
		ShowMapList, AdminChangePassword;
}
*/

void ASuperAdmin::PostNetBeginPlay()
{
	/*
	Super::PostNetBeginPlay();
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		SetDevMode(true);
	}
	*/
}

void ASuperAdmin::NotifyPawnSpawned(APawn* p)
{
	/*
	Super::NotifyPawnSpawned(p);
	if (bExtendersOn)
	{
		AddExtender(p);
	}
	*/
}

void ASuperAdmin::NotifyPawnDestroyed(APawn* p)
{
	/*
	Super::NotifyPawnDestroyed(p);
	if (bExtendersOn)
	{
		CleanupExtender(p);
	}
	*/
}

void ASuperAdmin::togwireframe()
{
	bWireFrame = (!bWireFrame);
	if (bWireFrame)
	{
		ConsoleCommand("rmode 1");
	}
	else
	{
		ConsoleCommand("rmode 5");
	}
}

void ASuperAdmin::togextend()
{
	bExtendersOn = (!bExtendersOn);
	if (bExtendersOn)
	{
		EnableExtenders();
	}
	else
	{
		DisableExtenders();
	}
}

void ASuperAdmin::lenextend()
{
	switch (ExtendLength)
	{
	case EExtendLength::ELEN_Long:
		ExtendLength = EExtendLength::ELEN_Medium;
		break;
	case EExtendLength::ELEN_Medium:
		ExtendLength = EExtendLength::ELEN_Short;
		break;
	case EExtendLength::ELEN_Short:
		ExtendLength = EExtendLength::ELEN_Long;
		break;
	default:
		ExtendLength = EExtendLength::ELEN_Long;
		break;
	}
	UpdateExtenders();
}

float ASuperAdmin::getExtendLength()
{
	switch (ExtendLength)
	{
	case EExtendLength::ELEN_Long:
		return 50000;
	case EExtendLength::ELEN_Medium:
		return 10000;
	case EExtendLength::ELEN_Short:
		return 1000;
	default:
		return 500;
	}
}

void ASuperAdmin::EnableExtenders()
{
	APawn* p = nullptr;
	/*
	ForEach DynamicActors(Class'Pawn', p)
	{
		AddExtender(p);
	}
	*/
}

void ASuperAdmin::DisableExtenders()
{
	AExtender* E = nullptr;
	AExtender* D = nullptr;
	E = EList;
	if (E != nullptr)
	{
		D = E;
		E = E->NextE;
		D->Destroy();
	}
}

void ASuperAdmin::AddExtender(APawn* p)
{
	if (p != nullptr)
	{
		//p->AttachToBone(GetExtender(p), "WeaponBone");
	}
}

AExtender* ASuperAdmin::GetExtender(APawn* p)
{
	AExtender* E = nullptr;
	/*
	E = Spawn(AExtender::StaticClass(), p);
	E.SetDrawScale3D(FVector(10, 10, getExtendLength()));
	E.NextE = EList;
	EList = E;
	*/
	return E;
}

void ASuperAdmin::CleanupExtender(APawn* p)
{
	AExtender* D = nullptr;
	AExtender* E = nullptr;
	/*
	if (EList.Owner == p)
	{
		D = EList;
		EList = EList.NextE;
	}
	else
	{
		E = EList;
		if (E.NextE != nullptr)
		{
			if (E.NextE.Owner == p)
			{
				D = E.NextE;
				E.NextE = E.NextE.NextE;
			}
			E = E.NextE;
		}
	}
	if (D != nullptr)
	{
		D.Destroy();
	}
	else
	{
		DebugLog(DEBUG_Warn, "SuperAdmin::CleanupExtenders()	Could not find E for " + FString::FromInt(p));
	}
	*/
}

void ASuperAdmin::UpdateExtenders()
{
	AExtender* E = nullptr;
	for (E = EList; E != nullptr; E = E->NextE)
	{
		//E.SetDrawScale3D(FVector(10, 10, getExtendLength()));
	}
}

void ASuperAdmin::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (bZoomIn != bZoomOut)
	{
		if (bZoomOut == 1)
		{
			//FovAngle = FMin((FovAngle + ((FovAngle * DeltaTime) * 2)), 85);
			bWasIn = false;
		}
		else
		{
			//FovAngle = FMax((FovAngle - ((FovAngle * DeltaTime) * 2)), 1.7);
			bWasIn = true;
		}
		//DesiredFOV = FovAngle;
		fZoomTime = 1.5;
	}
	else
	{
		if (fZoomTime > 0)
		{
			if (fZoomTime == 1.5)
			{
				//FovAngle = GetLockFOV();
			}
			(fZoomTime -= DeltaTime);
		}
	}
}

float ASuperAdmin::GetLockFOV()
{
	float mag = 0;
	float newmag = 0;
	float precision = 0;
	/*
	mag = (Default.FovAngle / FovAngle);
	if (mag < 2)
	{
		return FovAngle;
	}
	else
	{
		if (mag < 4)
		{
			precision = 10;
		}
		else
		{
			if (mag < 8)
			{
				precision = 4;
			}
			else
			{
				if (mag < float(18))
				{
					precision = 2;
				}
				else
				{
					if (mag < float(30))
					{
						precision = 1;
					}
					else
					{
						precision = 0.2;
					}
				}
			}
		}
	}
	newmag = (float(int((mag * precision))) / precision);
	if (bWasIn)
	{
		newmag = FMin((newmag + (1 / precision)), 50);
	}
	return (Default.FovAngle / newmag);
	*/
	return 0;    //FAKE   /ELiZ
}

void ASuperAdmin::PostRender(UCanvas* Canvas)
{
	float fScale = 0;
	float mag = 0;
	/*
	Super::PostRender(Canvas);
	if (fZoomTime > 0)
	{
		fScale = Cast<AAGP_HUD>(myHUD)._cHUDFrame.fScaleY;
		mag = (Default.FovAngle / FovAngle);
		Canvas.SetDrawColor(255, 0, 0, 255);
		Canvas.SetPos((400 * fScale), (300 * fScale));
		Canvas.DrawText("Zoom: " + FString::FromInt(mag) + "x");
	}
	*/
}

bool ASuperAdmin::CanBehindView()
{
	return true;
}

bool ASuperAdmin::IsSpectatePlayersOnly()
{
	return false;
}

bool ASuperAdmin::IsSpectateFirstPersonOnly()
{
	return false;
}

void ASuperAdmin::AdminChangePassword(FString sOldPassword, FString sNewPassword, FString sVerifyPassword)
{
	/*
	Log("AdminChangePassword requested by SuperAdmin user.");
	if (!PlayerReplicationInfo.bAdmin)
	{
		Log("Invalid server setting access");
		return;
	}
	if (Level.IsOfficialServer() && (!Level.IsLeasedServer()))
	{
		if ((PlayerReplicationInfo._Group != 1) && (PlayerReplicationInfo._Group != 20))
		{
			Level.Game.KickByController(this, "CHEATER");
			return;
		}
	}
	if (((Len(sOldPassword) == 0) || (Len(sNewPassword) == 0)) || (Len(sVerifyPassword) == 0))
	{
		ClientMessage("");
		ClientMessage("Note that the passwords shown here are not examples of secure passwords.");
		ClientMessage("");
		ClientMessage("    AdminChangePassword MyPassword YourPassword YourPassword\"");
		ClientMessage("Example: If your old admin password was \"MyPassword\" and you wanted to change to \"YourPassword\": ");
		ClientMessage("");
		ClientMessage("AdminChangePassword [oldpassword] [newpassword] [verifynewpassword]");
		ClientMessage("Invalid options for changing the administrator password.  The correct syntax is: ");
		return;
	}
	if (Level.Game.AccessControl.IsAdminPasswordValid(sOldPassword))
	{
		if (sNewPassword == sVerifyPassword)
		{
			Log("User " + PlayerReplicationInfo.PlayerName + " has changed the server password.");
			if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
			{
				Level.Game.BroadcastHandler.WritePRIChatLog(PlayerReplicationInfo, "Admin changing server admin password", "AdminPassword");
			}
			Level.Game.AccessControl.SetAdminPassword(sNewPassword);
			Level.Game.AccessControl.SaveConfig();
			ClientMessage("The password has been changed.");
			return;
		}
		else
		{
			ClientMessage("You must enter the new password and verify it exactly.");
			return;
		}
	}
	else
	{
		ClientMessage("You must enter the current server password correctly to change it.");
		return;
	}
	*/
}

void ASuperAdmin::Help()
{
	ClientMessage("");
	ClientMessage("admin score - enable/disable scoreboard");
	ClientMessage("admin adminset [value] - change server settings");
	ClientMessage("admin kick/kickban/ban/banlist - kick or manage banned players");
	ClientMessage("admin mute - mute player");
	ClientMessage("admin say - send console message to players");
	ClientMessage("admin Message - send admin message popup to players");
	ClientMessage("admin A_SwitchTeam - change player team");
	ClientMessage("admin switch - change server maps (use ShowMapList to see available maps)");
	ClientMessage("admin spectate - spectate some player");
	ClientMessage("admin forceclass - change player class (use \"*\" for all players)");
	ClientMessage("AdminChangePassword - set admin password");
	ClientMessage("AdminResetView - Resets view");
	ClientMessage("PBHelp - get help with PB commands");
	ClientMessage("------------------------------------------");
	ClientMessage("Standard Admin Commands (use command name plus \"?\" for help): ");
	//Player.Console.ConsoleOpen();
}

void ASuperAdmin::PBBanHelp()
{
	ClientMessage("");
	ClientMessage("admin pb_sv_UpdBanFile [optional file name] - updates ban file with changes");
	ClientMessage("admin pb_sv_ReBan <slot #> - reban player mistakenly unbanned");
	ClientMessage("admin pb_sv_UnBan <slot #> - Unban player in ban list slot");
	ClientMessage("admin pb_sv_UnBanGuid <guid> - Unban player with specified GUID");
	ClientMessage("admin pb_sv_banempty - empty ban list");
	ClientMessage("admin pb_sv_ban <name><reason> - Removes and permanently bans player from server.");
	ClientMessage("admin pb_sv_autoupdban <0/1> - disable/enable automatically updating ban file");
	ClientMessage("admin pb_sv_banlist [optional search text] - displays ban list");
	ClientMessage("------------------------------------------");
	ClientMessage("Standard PunkBuster Ban Related Commands (see PB Documentation for details): ");
}

void ASuperAdmin::PBBadNameHelp()
{
	ClientMessage("");
	ClientMessage("admin pb_sv_badnamedel <slot#> - remove name from bad name list");
	ClientMessage("admin pb_sv_badname - adds a bad name to the bad name list");
	ClientMessage("admin pb_sv_badnamelist - lists current bad name list");
	ClientMessage("------------------------------------------");
	ClientMessage("Standard PunkBuster Bad Name Related Commands (see PB Documentation for details): ");
}

void ASuperAdmin::PBCvarHelp()
{
	ClientMessage("");
	ClientMessage("PB_SV_Cvar \"<section><cvar_name>\" <IN/OUT/EXCLUDE><Param1> [opt param2] - Adds automatic cvar check for item");
	ClientMessage("PB_SV_CvarVal \"<section><cvar_name>\" <player name/slot> - gets value from player");
	ClientMessage("PB_SV_CvarEmpty - empties Cvar check list");
	ClientMessage("PB_SV_CvarList - shows list of Cvar checks");
	ClientMessage("PB_SV_CvarDel <slot> - removes item from cvar check list");
	ClientMessage("------------------------------------------");
	ClientMessage("Standard PunkBuster CVAR Related Commands (see PB Documentation for details): ");
}

void ASuperAdmin::PBWebsiteHelp()
{
	ConsoleCommand("start http://www.evenbalance.com");
	ClientMessage("When the Even Balance site opens click on the \"America's Army\" link to find the documentation.");
}

void ASuperAdmin::PBHelp()
{
	ClientMessage("");
	ClientMessage("PBCvarHelp - shows list of CVAR related PB commands");
	ClientMessage("PBBadNameHelp - shows list of PB bad name related commands");
	ClientMessage("PBBanHelp - shows list of PB ban related commands");
	ClientMessage("PBWebsiteHelp - Visit PB Website in your browser");
	ClientMessage("------------------------------------------");
	ClientMessage("For more help see: ");
	ClientMessage("");
	ClientMessage("admin pb_sv_kick <name/slot><minutes><reason> - PB kick player");
	ClientMessage("admin pb_sv_plist - display list of players");
	ClientMessage("admin pb_sv_autoss <0/1> - disable/enable auto screenshots");
	ClientMessage("admin pb_sv_update - Force PB to update itself");
	ClientMessage("admin pb_sv_ver - Shows PB version");
	ClientMessage("admin pb_sv_disable - Disable PB (requires server restart)");
	ClientMessage("admin pb_sv_enable - Enable PB");
	ClientMessage("------------------------------------------");
	ClientMessage("Standard PunkBuster Commands (see PB Documentation for details): ");
	//Player.Console.ConsoleOpen();
}

void ASuperAdmin::ShowMapList(FString sTourIndex)
{
	FString File = "";
	int32 iNumTours = 0;
	int32 iNumMissions = 0;
	int32 iMissionIndex = 0;
	int32 iTourIndex = 0;
	/*
	File = GetBaseDir() + "Tours.ini";
	iNumTours = GetPrivateProfileInt(File, "Tours", "NumTours");
	if (Len(sTourIndex) == 0)
	{
		ClientMessage("");
		ClientMessage("To view missions for a specific tour enter \"ShowMapList [tour #]\"");
		for (iTourIndex = (iNumTours - 1); iTourIndex >= 0; iTourIndex--)
		{
			if (!Level.GetTourIsTraining(iTourIndex))
			{
				ClientMessage("Tour " + FString::FromInt(iTourIndex) + ": " + Level.GetTourName(iTourIndex));
			}
		}
		ClientMessage("------------------------------------------------------------------------------------");
		ClientMessage("Available Tours:");
		ClientMessage("");
		return;
	}
	iTourIndex = int(sTourIndex);
	if ((iTourIndex >= iNumTours) || (iTourIndex < 0))
	{
		ClientMessage("Invalid tour index specified.  Use \"ShowMapList\" to get a list of tours.");
		return;
	}
	if (Level.GetTourIsTraining(iTourIndex))
	{
		ClientMessage("Invalid tour index specified.  Use \"ShowMapList\" to get a list of tours.");
		return;
	}
	ClientMessage("");
	ClientMessage("Use \"admin switch [MapName]\" to change maps.");
	if (!Level.GetTourIsTraining(iTourIndex))
	{
		iNumMissions = Level.GetTourMissions(iTourIndex);
		for (iMissionIndex = 0; iMissionIndex < iNumMissions; iMissionIndex++)
		{
			ClientMessage("Mission: " + Level.GetTourMissionTitle(iTourIndex, iMissionIndex) + " uses map \"" + Level.GetTourMissionMapFilename(iTourIndex, iMissionIndex) + "\"");
		}
	}
	ClientMessage("------------------------------------------------------------------------------------");
	ClientMessage("Available Missions for tour \"" + Level.GetTourName(iTourIndex) + "\"");
	*/
	ClientMessage("");
}

void ASuperAdmin::ShowAdminCommandPost()
{
	//ClientOpenMenu("AGP_Interface.AAGameMenu_CommandPost", , "Map", "");
}

void ASuperAdmin::AdminResetView()
{
	SetViewTarget(nullptr);
	ServerSetViewTarget(nullptr);
	fpLastViewChange = 0;
	ServerCycleViewPreference();
}
