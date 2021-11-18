// All the original content belonged to the US Army

#include "AA29/Info/AccessControl/AccessControl.h"
#include "AA29/MyStructs.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/AA29.h"


AAccessControl::AAccessControl()
{
	IPPolicies = "ACCEPT,*";
	MACBanned = "Your MAC address has been banned on this server.";
	IPBanned = "Your IP address has been banned on this server.";
	WrongPassword = "The password you entered is incorrect.";
	NeedPassword = "You need to enter a password to join this game.";
	NameBanned = "Your user name has been banned on this server.";
	AdminSpaceFilled = "There are already the maximum number of admins on this server.";
	BanListFilename = "BanList.txt";
	AdminClassName = "AGP.HumanController";
	PlayerAdmin = { "","","" };
}


void AAccessControl::GetFutureTimestamp(int32 weeks_into_the_future, int32 days_into_the_future, int32 hours_into_the_future, int32 minutes_into_the_future, int32 low_word_result, int32 hi_word_result)
{
}
void AAccessControl::CheckTimestampExpired(int32 low_word_part, int32 high_word_part, int32 secs_until)
{
}
void AAccessControl::LoadOldBanList()
{
}
void AAccessControl::SaveOldBanList()
{
}
void AAccessControl::UpdateOldBanList()
{
}
void AAccessControl::VerifyUserOldBanList(FString sPlayerName, FString sIP, FString sIPNoPort, FString sMAC, FString sError, FString sFailCode)
{
}
void AAccessControl::BanListInitialize()
{
}
void AAccessControl::BanListRetrieveUpdate()
{
}
void AAccessControl::BanListSubmitUpdates()
{
}
void AAccessControl::BanListCheckPlayerBanStatus(FString sPlayerName, FString sPBGUID)
{
}
void AAccessControl::BanListQueryPlayerBanStatus(FString sPlayerName, FString sPBGUID)
{
}
void AAccessControl::BanListBanPlayer(APlayerController* PCAdmin, FString sPlayerName, FString sPBGUID, int32 iLength, FString sReason)
{
}
void AAccessControl::SignalPlayerQualified(APlayerController* PCAdmin, bool bQualified)
{
}



void AAccessControl::PreBeginPlay()
{
	/*
	local int i;
	local array<String> asNameAndPassword;
	PreBeginPlay();
	for (i=0; i<PlayerAdmin.Length; i++)
	{
		Split(PlayerAdmin[i],",",asNameAndPassword);
		if (asNameAndPassword.Length == 2)
		{
			apaaPlayerAdmins.insert (0,1);
			apaaPlayerAdmins[0].sPlayerName=asNameAndPassword[0];
			apaaPlayerAdmins[0].sPassword=asNameAndPassword[1];
		}
		else
		{
			Log("WARNING: Player administrator entry """ $ PlayerAdmin[i] $ """ is not using the correct format of ""Name,Password"".");
		}
	}
	if (bUseNewBanListFormat)
	{
		BanListInitialize();
	}
	else
	{
		LoadOldBanList();
	}
	*/
}
bool AAccessControl::ValidatePlayerAdmin(FString sPlayerName, FString sPassword)
{
	
	int32 i;
	//UE_LOG(LogTemp, Warning, TEXT("INFORMATION: Testing player for player admin rights: """ $ sPlayerName $ """, pw: """ $ sPassword $ """"));
	UE_LOG(LogTemp, Warning, TEXT("INFORMATION: Testing player for player admin rights: ""%s"", pw: """""),*sPlayerName, *sPassword);
	if (sPlayerName =="" || sPassword=="")
	{
		return false;
	}
	for (i=0; i<PlayerAdmin.Max(); i++)
	{
		if (apaaPlayerAdmins[i].sPlayerName == sPlayerName && apaaPlayerAdmins[i].sPassword == sPassword)
		{
			UE_LOG(LogTemp, Warning, TEXT("INFORMATION: Valid player admin trying to join in with user name of ""%s""."),*sPlayerName);
			return true;
		}
	}
	return false;
}

bool AAccessControl::IsAdminPasswordValid(FString sPassword)
{
	if (AdminPassword == sPassword)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AAccessControl::SetAdminPassword(FString p)
{
	AdminPassword = p;
}
void AAccessControl::SetGamePassword(FString p)
{
	GamePassword = p;
}
FString AAccessControl::GetGamePassword()
{
	return GamePassword;
}
bool AAccessControl::RequiresPassword()
{
	return GamePassword != "";
}
bool AAccessControl::AdminLogin(APlayerController* p, FString Password)
{
	if (AdminPassword == "")
	{
		return false;
	}
	if (Password == AdminPassword)
	{
		UE_LOG(LogTemp, Warning, TEXT("Administrator logged in."));
		return true;
	}
	return false;
}

void AAccessControl::PreLogin(FString Options, FString Address, FString Error, FString FailCode, bool bSpectator, bool bAdmin)
{
	Error = "";
	/*
	FString InPassword;
	FString sBanLength;
	int32 iBanLengthSeconds;
	FString InName;
	FString InMAC;
	FString InIPAddressSansPort;
	int32 iPortPos;
	InPassword = Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->ParseOption(Options,"Password");
	InName     = Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->ParseOption(Options,"UserName");
	InMAC      = Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->ParseOption(Options,"MAC");

	if (Len(InName) == 0 || InName ~= "UserName")
	{
		UE_LOG(LogTemp, Log, TEXT("Player tried to join with an empty username, rejecting connection from %s"),  *Address);
		FailCode="WRONGPW";
		Error="Bad User Name";
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone && Len(AdminPassword) > 0 && InPassword ~= AdminPassword)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->NumAdmins >= Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->MaxAdmins)
		{
			FailCode="FULLSERVER";
			Error=AdminSpaceFilled;
			return;
		}
	}
	if (GetNetMode() != ENetMode::NM_Standalone && Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->AtCapacity(bSpectator,bAdmin))
	{
		FailCode="FULLSERVER";
		//Error= Cast<AAA2_WorldSettings>(GetWorldSettings())->Game->GameMessageClass.Default.MaxedOutMessage;
		return;
	}
	else
	{
		if (GamePassword != "" && Caps(InPassword) != Caps(GamePassword) && AdminPassword == "" || Caps(InPassword) != Caps(AdminPassword))
		{
			if (InPassword == "")
			{
				Error=NeedPassword;
				FailCode="NEEDPW";
			}
			else
			{
				Error=WrongPassword;
				FailCode="WRONGPW";
			}
			return;
		}
	}
	if (! CheckIPPolicy(Address))
	{
		Error=IPBanned;
		FailCode="LIPBAN";
		return;
	}
	iPortPos=InStr(Address,":");
	if (iPortPos > 0)
	{
		InIPAddressSansPort=Left(Address,iPortPos);
	}
	else
	{
		InIPAddressSansPort=Address;
	}
	if (bUseNewBanListFormat)
	{
		//UE_LOG(LogTemp, Warning, TEXT("INFORMATION: Using new ban list management to test player """ $ InName $ """ with PBGUID: " $ Level.GetPBGUIDFromIP(InIPAddressSansPort)));
		if (BanListCheckPlayerBanStatus(InName, Cast<AAA2_WorldSettings>(GetWorldSettings())->GetPBGUIDFromIP(InIPAddressSansPort)))
		{
			iBanLengthSeconds=BanListQueryPlayerBanStatus(InName, Cast<AAA2_WorldSettings>(GetWorldSettings())->GetPBGUIDFromIP(InIPAddressSansPort));
			if (iBanLengthSeconds > 0)
			{
				if (iBanLengthSeconds > 24 * 3600)
				{
					sBanLength=iBanLengthSeconds / 24 * 3600 $ " days";
					iBanLengthSeconds -= 24 * 3600 * iBanLengthSeconds / 24 * 3600;
				}
				if (iBanLengthSeconds > 3600)
				{
					sBanLength=sBanLength $ iBanLengthSeconds / 3600 $ " hours";
					iBanLengthSeconds -= iBanLengthSeconds / 3600 * 3600;
				}
				if (iBanLengthSeconds > 60)
				{
					sBanLength=sBanLength $ iBanLengthSeconds / 60 $ " minutes";
				}
				Error=NameBanned $ " for " $ sBanLength;
				FailCode="USRBAN";
				return;
			}
		}
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("INFORMATION: Using old ban list management, IP: " $ InIPAddressSansPort));
		VerifyUserOldBanList(InName,Address,InIPAddressSansPort,InMAC,Error,FailCode);
	}
	*/
}

void AAccessControl::CheckIPPolicy(FString Address)
{
	/*
	local int i;
	local int j;
	local int LastMatchingPolicy;
	local string Policy;
	local string Mask;
	local bool bAcceptAddress;
	local bool bAcceptPolicy;
	j=InStr(Address,":");
	if (j != -1)
	{
		Address=Left(Address,j);
	}
	bAcceptAddress=True;
	i=0;
	if (i < 50 && IPPolicies[i] != "")
	{
		j=InStr(IPPolicies[i],",");
		if (j == -1)
		{
		}
		Policy=Left(IPPolicies[i],j);
		Mask=Mid(IPPolicies[i],j + 1);
		if (Policy ~= "ACCEPT")
		{
			bAcceptPolicy=True;
		}
		else
		{
			if (Policy ~= "DENY")
			{
				bAcceptPolicy=False;
			}
			else
			{
			}
		}
		else
		{
			j=InStr(Mask,"*");
			if (j != -1)
			{
				if (Left(Mask,j) == Left(Address,j))
				{
					bAcceptAddress=bAcceptPolicy;
					LastMatchingPolicy=i;
				}
			}
			else
			{
				if (Mask == Address)
				{
					bAcceptAddress=bAcceptPolicy;
					LastMatchingPolicy=i;
				}
			}
		}
		i ++;
	}
	if (! bAcceptAddress)
	{
		Log("Denied connection for " $ Address $ " with IP policy " $ IPPolicies[LastMatchingPolicy]);
	}
	Return bAcceptAddress;
*/
}
void AAccessControl::Kick(FString S, FString Reason, bool bMaybeFail)
{
	/*
	local PlayerController p;
	local PlayerController PKick;
	local bool bFoundAnotherPlayer;
	ForEach DynamicActors('PlayerController',p)
	{
		if (PKick != None)
		{
			bFoundAnotherPlayer=True;
		}
		else
		{
			if (p.PlayerReplicationInfo.PlayerName ~= S)
			{
				PKick=p;
				if (! bDontKickLastPlayer || bFoundAnotherPlayer)
				{
				}
			}
			else
			{
				else
				{
					bFoundAnotherPlayer=True;
				}
			}
		}
	}
	if (PKick != None)
	{
		if (bDontKickLastPlayer && ! bFoundAnotherPlayer && Reason != "Cheater")
		{
			UE_LOG(LogTemp, Warning, TEXT("Cannot kick last player!" @ S @ Reason));
			Return False;
		}
		else
		{
			if (KickMe.Length > 0 && bMaybeFail && bAllowMaybeFail)
			{
				UE_LOG(LogTemp, Warning, TEXT("Failed to kick because someone else was going to be kicked." @ S @ Reason));
			}
			else
			{
				SetupKick(PKick,Reason);
			}
			return true;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not find player to kick." @ S @ Reason));
		return false;
	}
*/
}

void AAccessControl::SetupKick(APlayerController* PKick, FString Reason)
{
	/*
	local int i;
	local int new_index;
	if (NetConnection(PKick.Player) == None)
	{
		UE_LOG(LogTemp, Warning, TEXT("NULL NetConnection for " @ PKick.GetHumanReadableName() @ Reason));
	}
	if (PKick.PlayerReplicationInfo != None && ! IsPlayerAdmin(PKick.PlayerReplicationInfo) && PKick.PlayerReplicationInfo.bAdmin)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not allowing the kicking of " $ PKick.GetHumanReadableName() $ " because that player is an admin."));
		return;
	}
	for (i=0; i<KickMe.Length; i++)
	{
		if (KickMe[i] == PKick)
		{
			if (GetKickPenalty(Reason) > GetKickPenalty(KickReason[i]))
			{
				KickReason[i]=Reason;
			}
			Return;
		}
	}
	new_index=KickMe.Length;
	KickMe[new_index]=PKick;
	KickReason[new_index]=Reason;
	PrintKickMessage(PKick,new_index);
	if (! bKickPending)
	{
		SetTimer(5,False);
		bKickPending=True;
	}
*/
}

void AAccessControl::PrintKickMessage(APlayerController* PKick, int32 i)
{
	/*
	local string Message;
	local string Reason;
	Message="KICK NOTIFICATION: " $ KickMe[i].PlayerReplicationInfo.PlayerName;
	Reason=Caps(KickReason[i]);
	Switch(Reason)
	{
		case "ROE":
		Message=Message $ " has violated the Rules of Engagement.";
		break;
		case "VOTEKICK":
		Message=Message $ " has been voted out of the game.";
		break;
		case "ADMIN":
		case "TELNET":
		Message=Message $ " has been kicked by an Administrator.";
		break;
		case "IDLEROUNDS":
		case "IDLETIME":
		Message=Message $ " has been idle for too long.";
		break;
		case "CHEATER":
		Message=Message $ " has been disconnected by an unknown communications or log-in error.";
		break;
		case "DUPNAME":
		Message=Message $ " has been kicked for attempting a duplicate login.";
		break;
		case "DEV":
		Message=Message $ " has been kicked by a Dev.";
		break;
		default:
		if (InStr("PUNKBUSTER",Reason) != -1)
		{
			Message=Message $ ": " $ Reason;
			break;
			break;
		}
		Message=Message $ " has been kicked for an undefined reason: " $ Reason;
		break;
	}
	Level.Game.Broadcast(Level.Game,Message);
	LogFileWrite("DevNet",Message);
	if (PKick != None)
	{
		PKick.ClientSetAccessControlKickMessage(Message);
	}
*/
}
void AAccessControl::GetKickPenalty(FString Reason)
{
	/*
	Reason=Caps(Reason);
	Switch(Reason)
	{
		case "ROE":
		Return 0.5 * Level.Game.GetROELimit();
		case "ADMIN":
		case "TELNET":
		Return 0;
		case "DUPNAME":
		case "IDLEROUNDS":
		case "IDLETIME":
		Return 100;
		case "VOTEKICK":
		Return 0;
		case "CHEATER":
		Return 0;
		case "DEV":
		Return 0;
		default:
		Return 0;
		}
*/

}
void AAccessControl::DoKick()
{
	/*
	local int KickPenalty;
	local string sKickReason;
	sKickReason=KickReason[0];
	UE_LOG(LogTemp, Warning, TEXT("Kicking" @ KickMe[0] @ sKickReason));
	if (KickMe[0] != None)
	{
		if (Level.Game.Stats != None && KickMe[0].PlayerStatsIndex >= 0)
		{
			if (InStr("PUNKBUSTER",sKickReason) != -1)
			{
				Level.Game.Stats.PlayerStats[KickMe[0].PlayerStatsIndex].StatEvent_KickPlayerPB();
			}
			else
			{
				if (sKickReason ~= "ADMIN")
				{
					Level.Game.Stats.PlayerStats[KickMe[0].PlayerStatsIndex].StatEvent_KickPlayerAdmin();
				}
				else
				{
					Level.Game.Stats.PlayerStats[KickMe[0].PlayerStatsIndex].StatEvent_KickPlayer();
				}
			}
		}
		KickPenalty=GetKickPenalty(sKickReason);
		KickMe[0].PlayerReplicationInfo.PScoreFF(KickPenalty);
		if (sKickReason ~= "ROE")
		{
			KickMe[0].ClientOpenMap("leavenworth");
		}
		else
		{
			if (sKickReason ~= "CHEATER")
			{
				sKickReason="CommError";
			}
			UE_LOG(LogTemp, Warning, TEXT("Engine.AccessControl.DoKick() - reason: " $ sKickReason));
			KickMe[0].ClientOpenMap("entry?" $ sKickReason);
		}
		KickMe[0].Destroy();
	}
	KickMe.remove (0,1);
	KickReason.remove (0,1);
	if (KickMe.Length > 0)
	{
		SetTimer(1,False);
	}
	else
	{
		bKickPending=False;
	}
*/
}

void AAccessControl::Timer()
{
	DoKick();
}

bool AAccessControl::IsPlayerAdmin(AAA2_PlayerState* PRI)
{
	if (PRI == nullptr)
	{
		return false;
	}
	return PRI->bPlayerAdmin;
}

bool AAccessControl::GameNeedsPassword()
{
	if (GamePassword == "")
	{
		return false;
	}
	else
	{
		return true;
	}
}
void AAccessControl::UpdateBanPolicies()
{
	/*
	local int i;
	local int j;
	local int k;
	local bool bAnyEntriesRemoved;
	local bool bEntryRemoved;
	bAnyEntriesRemoved=False;
	bEntryRemoved=False;
	i=0;
	if (i < BanList.Length)
	{
		if (BanList[i].BanEndDate_LoWord > 0 && BanList[i].BanEndDate_HiWord >= 0 && CheckTimestampExpired(BanList[i].BanEndDate_LoWord,BanList[i].BanEndDate_HiWord,k))
		{
			Log("Ban against '" $ BanList[i].Banee $ "' has expired. Removing...",'AccessControl');
			j=i;
			if (j < BanList.Length - 1)
			{
				BanList[j]=BanList[j + 1];
				j ++;
			}
			BanList.Length=BanList.Length - 1;
			bEntryRemoved=True;
			bAnyEntriesRemoved=True;
		}
		else
		{
			i ++;
		}
	}
	if (bEntryRemoved == false)
	{
		if (bAnyEntriesRemoved)
		{
			SaveOldBanList();
		}
	*/
}
bool AAccessControl::AddPBGUIDBan(FString sPBGUID, int32 weeks, int32 days, int32 hours, int32 minutes, FString sPlayerName, APlayerController* PCAdmin)
{
	int32 iTimeSeconds;
	if (bUseNewBanListFormat)
	{
		iTimeSeconds=(weeks * 7 * 3600 * 24) + (days * 24 * 3600) + (hours * 3600) + (minutes * 60);
		BanListBanPlayer(PCAdmin,sPlayerName,sPBGUID,iTimeSeconds,"");
		return true;
	}
	else
	{
		return AddBanee(sPBGUID,"PBGUID",weeks,days,hours,minutes,sPlayerName);
	}
}
bool AAccessControl::AddBanee(FString banee_descriptor, FString banee_type_name, int32 weeks_to_ban, int32 days_to_ban, int32 hours_to_ban, int32 minutes_to_ban_for, FString banee_owner)
{
	/*
	local int i;
	local int NumBanees;
	local int NewEntryIndex;
	local EBanType banee_type;
	Log("Add Ban - Banee: " $ banee_descriptor $ " type: " $ banee_type_name);
	banee_type=BanTypeNameToBanType(banee_type_name);
	if (4 == banee_type)
	{
		Return False;
	}
	NumBanees=BanList.Length;
	NewEntryIndex=-1;
	i=0;
	if (i < NumBanees)
	{
		if (BanList[i].BanType == banee_type && BanList[i].Banee == banee_descriptor)
		{
			NewEntryIndex=i;
		}
		else
		{
			i ++;
		}
	}
	if (NewEntryIndex == -1)
	{
		NewEntryIndex=BanList.Length;
		BanList.Length=BanList.Length + 1;
	}
	if (weeks_to_ban > 0 || days_to_ban > 0 || hours_to_ban > 0 || minutes_to_ban_for > 0)
	{
		GetFutureTimestamp(weeks_to_ban,days_to_ban,hours_to_ban,minutes_to_ban_for,BanList[NewEntryIndex].BanEndDate_LoWord,BanList[NewEntryIndex].BanEndDate_HiWord);
	}
	else
	{
		BanList[NewEntryIndex].BanEndDate_LoWord=0;
		BanList[NewEntryIndex].BanEndDate_HiWord=0;
	}
	BanList[NewEntryIndex].BanType=banee_type;
	BanList[NewEntryIndex].Banee=banee_descriptor;
	BanList[NewEntryIndex].OriginalUserName=banee_owner;
	Return True;
	*/
	return false;		//FAKE ELiZ
}
void AAccessControl::CheckBanPolicy(FString PlayerName, FString PlayerIP, FString PlayerMAC, FString Error, FString FailCode)
{
	/*
	local int i;
	local string sPBGUID;
	sPBGUID="""" $ Level.GetPBGUIDFromIP(PlayerIP) $ """";
	Log("Checking Ban Policy for: PBGUID=" $ sPBGUID $ " Name=""" $ PlayerName $ """ IP=""" $ PlayerIP $ """ MAC=$""" $ PlayerMAC $ """");
	UpdateBanPolicies();
	Log("Examining " $ BanList.Length $ " Ban list entries");
	for (i=0; i<BanList.Length; i++)
	{
		Log("Ban entry """ $ BanList[i].Banee $ """ vs """ $ PlayerName $ """ Type: " $ BanList[i].BanType);
		if (BanList[i].BanType == 3 && BanList[i].Banee ~= sPBGUID)
		{
			Log("Name = " $ PlayerName $ " PBGUID banned!");
			Error=NameBanned $ "  " $ GetBanLength(i);
			FailCode="USRBAN";
			Return;
		}
		if (BanList[i].BanType == 0 && BanList[i].Banee ~= PlayerName)
		{
			Log("Name=" $ PlayerName @ "banned!");
			Error=NameBanned $ "  " $ GetBanLength(i);
			FailCode="USRBAN";
			Return;
		}
		else
		{
			if (BanList[i].BanType == 1 && BanList[i].Banee == PlayerIP)
			{
				Log("IP=" $ PlayerIP @ "banned!");
				Error=IPBanned $ "  " $ GetBanLength(i);
				FailCode="IP_BAN";
				Return;
			}
			else
			{
				if (BanList[i].BanType == 2 && BanList[i].Banee == PlayerMAC)
				{
					Log("MAC=" $ PlayerMAC @ "banned!");
					Error=MACBanned $ "  " $ GetBanLength(i);
					FailCode="MACBAN";
					Return;
				}
			}
		}
	}
	*/
}
void AAccessControl::DisplayBanList(APlayerController* PC, int32 iBanStartIndex)
{
	/*
	local int i;
	local int secs_until;
	local int iDisplayedItems;
	local string str;
	local int weeks;
	local int days;
	local int hours;
	local int minutes;
	local bool bWroteTime;
	UpdateOldBanList();
	PC.ClientMessage("------------------------------");
	iBanStartIndex --;
	for (iDisplayedItems=0; iDisplayedItems<25; iDisplayedItems++)
	{
		i=iBanStartIndex + 24 - iDisplayedItems;
		if (i < 0)
		{
		}
		if (i > BanList.Length - 1)
		{
		}
		str=i + 1 $ "> ";
		if (BanList[i].BanEndDate_LoWord > 0 || BanList[i].BanEndDate_HiWord > 0)
		{
			if (CheckTimestampExpired(BanList[i].BanEndDate_LoWord,BanList[i].BanEndDate_HiWord,secs_until))
			{
				UE_LOG(LogTemp, Warning, TEXT("Entry in banlist has expired but is still in list!"));
			}
			else
			{
			}
			else
			{
				secs_until=0;
			}
			Switch(BanList[i].BanType)
			{
				case 3:
				str=str $ "PBGUID ban against ";
				break;
				case 0:
				str=str $ "User Name ban against ";
				break;
				case 1:
				str=str $ "IP Address ban against ";
				break;
				case 2:
				str=str $ "MAC Address ban against ";
				break;
				default:
			}
			str=str $ "'" $ BanList[i].Banee $ "' with ";
			if (secs_until < 60 && secs_until > 0)
			{
				str=str @ secs_until $ " second";
				if (secs_until > 1)
				{
					str=str $ "s";
				}
			}
			weeks=secs_until / 604800;
			secs_until -= weeks * 604800;
			days=secs_until / 86400;
			secs_until -= days * 86400;
			hours=secs_until / 3600;
			secs_until -= hours * 3600;
			minutes=secs_until / 60;
			bWroteTime=False;
			if (secs_until == 0)
			{
				str=str @ "eternity";
			}
			if (weeks > 0)
			{
				str=str $ weeks $ " week";
				if (weeks > 1)
				{
					str=str $ "s";
				}
				bWroteTime=True;
			}
			if (days > 0)
			{
				if (bWroteTime)
				{
					str=str $ ", ";
				}
				str=str $ days $ " day";
				if (days > 1)
				{
					str=str $ "s";
				}
				bWroteTime=True;
			}
			if (hours > 0)
			{
				if (bWroteTime)
				{
					str=str $ ", ";
				}
				str=str $ hours $ " hour";
				bWroteTime=True;
				if (hours > 1)
				{
					str=str $ "s";
				}
				bWroteTime=True;
			}
			if (minutes > 0)
			{
				if (bWroteTime)
				{
					str=str $ " and ";
				}
				str=str $ minutes $ " minute";
				if (minutes > 1)
				{
					str=str $ "s";
				}
				bWroteTime=True;
			}
			str=str $ " remaining";
			if (BanList[i].BanType != 0)
			{
				str=str $ " (initiated against user '" $ BanList[i].OriginalUserName $ "')";
			}
			PC.ClientMessage(str);
		}
	}
	if (BanList.Length > 25)
	{
		PC.ClientMessage("You can enter a ban number to list bans starting at that location");
	}
	PC.ClientMessage("---------- Ban List ----------");
	*/
}
void AAccessControl::GetBanLength(int32 iBanItem)
{
	/*
	local int i;
	local int secs_until;
	local string str;
	local int weeks;
	local int days;
	local int hours;
	local int minutes;
	local bool bWroteTime;
	if (BanList[i].BanEndDate_LoWord > 0 || BanList[i].BanEndDate_HiWord > 0)
	{
		CheckTimestampExpired(BanList[i].BanEndDate_LoWord,BanList[i].BanEndDate_HiWord,secs_until);
	}
	else
	{
		secs_until=0;
	}
	if (secs_until < 60 && secs_until > 0)
	{
		str=str @ secs_until $ " second";
		if (secs_until > 1)
		{
			str=str $ "s";
		}
	}
	weeks=secs_until / 604800;
	secs_until -= weeks * 604800;
	days=secs_until / 86400;
	secs_until -= days * 86400;
	hours=secs_until / 3600;
	secs_until -= hours * 3600;
	minutes=secs_until / 60;
	bWroteTime=False;
	if (secs_until == 0)
	{
		Return "|The ban is permanent.";
	}
	if (weeks > 0)
	{
		str=str $ weeks $ " week";
		if (weeks > 1)
		{
			str=str $ "s";
		}
		bWroteTime=True;
	}
	if (days > 0)
	{
		if (bWroteTime)
		{
			str=str $ ", ";
		}
		str=str $ days $ " day";
		if (days > 1)
		{
			str=str $ "s";
		}
		bWroteTime=True;
	}
	if (hours > 0)
	{
		if (bWroteTime)
		{
			str=str $ ", ";
		}
		str=str $ hours $ " hour";
		bWroteTime=True;
		if (hours > 1)
		{
			str=str $ "s";
		}
		bWroteTime=True;
	}
	if (minutes > 0)
	{
		if (bWroteTime)
		{
			str=str $ " and ";
		}
		str=str $ minutes $ " minute";
		if (minutes > 1)
		{
			str=str $ "s";
		}
		bWroteTime=True;
	}
	str="|The ban has " $ str $ " remaining.";
	Return str;
	*/
}
void AAccessControl::Unban(APlayerController* PCAdmin, int32 Index)
{
	/*
	local int i;
	if (bUseNewBanListFormat)
	{
		Return;
	}
	Index=Index - 1;
	if (Index < 0 || Index >= BanList.Length)
	{
		PCAdmin.ClientMessage("(Use 'admin banlist' for list of entries to pick from)");
		PCAdmin.ClientMessage("Usage: admin unban <ban_index>");
	}
	else
	{
		PCAdmin.ClientMessage("Removing ban against '" $ BanList[Index].Banee $ "' (original user was '" $ BanList[Index].OriginalUserName $ "')");
		if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
		{
			Level.Game.BroadcastHandler.WritePRIChatLog(PCAdmin.PlayerReplicationInfo,"Player: """ $ BanList[Index].Banee $ """",'AdminUnBan');
		}
		i=Index;
		if (i < BanList.Length - 1)
		{
			BanList[i]=BanList[i + 1];
			i ++;
		}
		BanList.Length=BanList.Length - 1;
		SaveOldBanList();
	}
	*/
}
void AAccessControl::BanListLoad()
{
	/*
	local bool success;
	local string L;
	BanList.Length=0;
	success=FOpen(BanListFilename);
	if (! success)
}
{
	if (success && FReadLine(L))
	{
		Log("Ban list entry: " $ L);
		success=BanListParseLine(L);
	}
	FClose();
	Return success;
	*/
}
void AAccessControl::BanListParseLine(FString S)
{
	/*
	local string banTypeName;
	local string tmpString;
	local int banEndDateInSeconds_Lo;
	local int banEndDateInSeconds_Hi;
	local int remainingBanInSeconds;
	local int weeksToBan;
	local int daysToBan;
	local int hoursToBan;
	local int minutesToBan;
	local string bannedItem;
	local string originalBannedItem;
	local bool success;
	local string endToken;
	local int tokenLen;
	local int pos;
	pos=InStr(S,",");
	success=pos != -1;
	if (success)
	{
		EatStr(banTypeName,S,pos);
		EatStr(tmpString,S,1);
		if (Left(S,1) == """")
		{
			endToken=""",";
			tokenLen=2;
			EatStr(tmpString,S,1);
		}
		else
		{
			endToken=",";
			tokenLen=1;
		}
		if (Len(S) > 0 && Left(S,tokenLen) != endToken)
		{
			EatStr(bannedItem,S,1);
			if (Left(S,1) == "\")
			{
				EatStr(tmpString,S,1);
				EatStr(bannedItem,S,1);
			}
		}
		EatStr(tmpString,S,tokenLen);
		pos=InStr(S,",");
		success=pos != -1;
		tmpString="";
		EatStr(tmpString,S,pos);
		banEndDateInSeconds_Lo=tmpString;
		EatStr(tmpString,S,1);
		pos=InStr(S,",");
		success=pos != -1;
		tmpString="";
		EatStr(tmpString,S,pos);
		banEndDateInSeconds_Hi=tmpString;
		EatStr(tmpString,S,1);
		if (Left(S,1) == """")
		{
			endToken="""";
			tokenLen=1;
			EatStr(tmpString,S,1);
			if (Len(S) > 0 && Left(S,tokenLen) != endToken)
			{
				EatStr(originalBannedItem,S,1);
				if (Left(S,1) == "\")
				{
					EatStr(tmpString,S,1);
					EatStr(originalBannedItem,S,1);
				}
			}
		}
		else
		{
			originalBannedItem=S;
		}
	}
	if (success)
	{
		if (0 == banEndDateInSeconds_Lo && 0 == banEndDateInSeconds_Hi)
		{
			success=AddBanee(bannedItem,banTypeName,weeksToBan,daysToBan,hoursToBan,minutesToBan,originalBannedItem);
		}
		else
		{
			if (! CheckTimestampExpired(banEndDateInSeconds_Lo,banEndDateInSeconds_Hi,remainingBanInSeconds))
			{
				GetDurationOfRemainingBan(remainingBanInSeconds,weeksToBan,daysToBan,hoursToBan,minutesToBan);
				success=AddBanee(bannedItem,banTypeName,weeksToBan,daysToBan,hoursToBan,minutesToBan,originalBannedItem);
			}
		}
	}
	Return success;
	*/
}
EBanType AAccessControl::BanTypeNameToBanType(FString banTypeName)
{
	
	EBanType Type;

	Type = EBanType::BanType_Unknown;

	if (banTypeName == "NAME")					{		Type = EBanType::BanType_PlayerName;	}
	if (banTypeName == "")						{		Type = EBanType::BanType_PlayerName;	}
	if (banTypeName == "IP")					{		Type = EBanType::BanType_PlayerIP;		}
	if (banTypeName == "**ban_ip_address**")	{		Type = EBanType::BanType_PlayerIP;		}
	if (banTypeName == "MAC")					{		Type = EBanType::BanType_PlayerMAC;		}
	if (banTypeName == "**ban_mac_address**")	{		Type = EBanType::BanType_PlayerMAC;		}
	if (banTypeName == "PBGUID")				{		Type = EBanType::BanType_PBGUID;		}
	return Type;
}
FString AAccessControl::BanTypeToBanTypeName(EBanType BanType)
{
	FString banTypeName;
	switch (BanType)
	{
		case EBanType::BanType_PlayerName:
			banTypeName = "NAME";
			break;
		case EBanType::BanType_PlayerIP:
			banTypeName = "IP";
			break;
		case EBanType::BanType_PlayerMAC:
			banTypeName = "MAC";
			break;
		case EBanType::BanType_Unknown:
			break;
		default:
			break;
	}
	return banTypeName;
}
void AAccessControl::GetDurationOfRemainingBan(int32 remainingBanInSeconds, int32 weeksToBan, int32 daysToBan, int32 hoursToBan, int32 minutesToBan)
{
	weeksToBan = remainingBanInSeconds / 60 * 60 * 24 * 7;
	remainingBanInSeconds = remainingBanInSeconds % 60 * 60 * 24 * 7;
	daysToBan = remainingBanInSeconds / 60 * 60 * 24;
	remainingBanInSeconds = remainingBanInSeconds % 60 * 60 * 24;
	hoursToBan = remainingBanInSeconds / 60 * 60;
	remainingBanInSeconds = remainingBanInSeconds % 60 * 60;
	minutesToBan = remainingBanInSeconds / 60;
}
bool AAccessControl::BanListSave()
{
	return true;
}
