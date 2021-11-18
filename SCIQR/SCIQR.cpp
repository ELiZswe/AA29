// All the original content belonged to the US Army


#include "AA29/SCIQR/SCIQR.h"
#include "AA29/AA2_WorldSettings.h"

// Sets default values
ASCIQR::ASCIQR()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bHidden = true;
	//RemoteRole = 0;
}

// Called when the game starts or when spawned
void ASCIQR::BeginPlay()
{
	//Manually run PreBeginPlay
	PreBeginPlay();

	Super::BeginPlay();
	
}

// Called every frame
void ASCIQR::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ASCIQR::PreBeginPlay()
{
	
	//PreBeginPlay();
	bRegistered=false;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer())
	{
		UE_LOG(LogTemp, Warning, TEXT("SCIQR: This is a LAN server. Not talking to Andromeda master."));
		sciqrState = ESCIQRState::SCIQR_Nothing;
		//Disable('Tick');
		return;
	}
	if (IP == "" || IP == "0.0.0.0")
	{
		UE_LOG(LogTemp, Warning, TEXT("SCIQR: You need to set [IpDrv.SCIQR]'s 'IP' field in your .ini"));
		UE_LOG(LogTemp, Warning, TEXT("SCIQR:   ...otherwise, we won't talk to the Andromeda server."));
		UE_LOG(LogTemp, Warning, TEXT("SCIQR:   ...Set IP to your server's public address!"));
		sciqrState = ESCIQRState::SCIQR_Nothing;
		//Disable('Tick');
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("SCIQR: Spawning..."));
	//UE_LOG(LogTemp, Warning, TEXT("SCIQR: IP %s port %s"),IP, GetGameMode()->GetServerPort());
	sciqrState = ESCIQRState::SCIQR_Opening;
	//link=Spawn('TcpLinkSCI',Self);
	//link.Connect();
	//SetTimer(0.1,true);
}
void ASCIQR::Destroyed()
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("SCIQR: Destroying..."));
	//SetTimer(0,False);
	//Disable('Tick');
	if (link != nullptr)
	{
		link.Disconnect();
		link.Destroy();
		link=nullptr;
	}
	*/
	Super::Destroyed();
}
void ASCIQR::doRegistration()
{
	/*
	local int official;
	local int leased;
	local int ultimatearena;
	local int tournament;
	local int Tour;
	local int MinHonor;
	local int MaxHonor;
	local int miles;
	local int punkbuster;
	local int cheats;
	local int needpass;
	local string ver;
	local string extraxml;
	local string convServerName;
	local string convTitle;
	local GameInfo.ServerResponseLine S;
	official=Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer();
	leased=Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer();
	ultimatearena=Level.IsUltimateArenaServer();
	tournament=Level.Game.IsTournamentMode();
	cheats=! Level.Game.CheatsDisabled();
	Tour=Level.GetLevelTour();
	MinHonor=Level.Game.GetMinHonor();
	MaxHonor=Level.Game.GetMaxHonor();
	miles=Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES();
	punkbuster=Level.PBIsEnabled();
	needpass=Level.Game.NeedPassword();
	Level.Game.GetServerInfo(S);
	ver=GetVersionAGPMajor() $ "." $ GetVersionAGPMinor() $ "." $ GetVersionAGPTiny() $ "." $ GetVersionAGPSubTiny();
	extraxml="<PROPERTIES>" $ "<PROPERTY><NAME>OFFICIAL</NAME><VALUE>" $ official $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>LEASED</NAME><VALUE>" $ leased $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>TOUR</NAME><VALUE>" $ Tour $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>MINHONOR</NAME><VALUE>" $ MinHonor $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>MAXHONOR</NAME><VALUE>" $ MaxHonor $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>SV_PUNKBUSTER</NAME><VALUE>" $ punkbuster $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>MILES</NAME><VALUE>" $ miles $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>CHEATS</NAME><VALUE>" $ cheats $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>TOURNAMENT</NAME><VALUE>" $ tournament $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>ULTIMATEARENA</NAME><VALUE>" $ ultimatearena $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>CUSTOMFLAGS</NAME><VALUE>0</VALUE></PROPERTY>" $ "</PROPERTIES>";
	convServerName=S.ServerName;
	link.convToMetaChars(convServerName);
	convTitle=Level.Title;
	link.convToMetaChars(convTitle);
	link.RequestRegistration("AAO",ver,convServerName,IP,S.Port,S.Port + 1,convTitle,needpass,S.CurrentPlayers,S.MaxPlayers,"A" $ S.GameType,extraxml);
	*/
}
void ASCIQR::parseRegistrationResponse(FString responseString)
{
	/*
	local int pos;
	myGuid="";
	pos=InStr(responseString,"<GUID>");
	if (pos != -1)
	{
		responseString=Mid(responseString,pos + 6);
		pos=InStr(responseString,"</GUID>");
		if (pos != -1)
		{
			myGuid=Left(responseString,pos);
		}
	}
	*/
}
void ASCIQR::doHeartbeat()
{
	/*
	local string xml;
	local string playersxml;
	local string players;
	local int i;
	local int Max;
	local PlayerReplicationInfo PRI;
	local string convPlayerName;
	Max=Level.Game.GameReplicationInfo.PRIArray.Length;
	if (Max > 0)
	{
		for (i=0; i<Max; i++)
		{
			PRI=Level.Game.GameReplicationInfo.PRIArray[i];
			convPlayerName=PRI.PlayerName;
			link.convToMetaChars(convPlayerName);
			players=players $ "<PLAYER><ACTION>ADD</ACTION><MBS_ID>" $ PRI.PlayerID $ "</MBS_ID><MBS_NAME>" $ convPlayerName $ "</MBS_NAME><MBS_PING>" $ PRI.Ping $ "</MBS_PING><MBS_SCORE>" $ PRI.Score_Total $ "</MBS_SCORE><PROPERTIES>" $ "<PROPERTY><NAME>KIA</NAME><VALUE>" $ PRI.Score_Deaths $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>ENEMY</NAME><VALUE>" $ PRI.Score_Kills $ "</VALUE></PROPERTY>" $ "<PROPERTY><NAME>ROE</NAME><VALUE>" $ PRI.Score_ROE $ "</VALUE></PROPERTY>" $ "</PROPERTIES></PLAYER>";
		}
		playersxml="<MESSAGE><ACTION>UPDATEPLAYERS</ACTION><GUID>" $ myGuid $ "</GUID><PLAYERS>" $ players $ "</PLAYERS></MESSAGE>";
	}
	xml="<?xml version=""1.0""?><GSMS><MESSAGES>" $ "<MESSAGE><ACTION>CLEARPLAYERS</ACTION><GUID>" $ myGuid $ "</GUID></MESSAGE>" $ playersxml $ "</MESSAGES></GSMS>";
	link.dlog("SCIQR: Sending heartbeat xml" @ xml);
	link.RequestRawXML(xml);
	*/
}
void ASCIQR::Timer()
{
	/*
	if (sciqrState == 0 || link.StillProcessing())
	{
		Return;
	}
	else
	{
		if (sciqrState == 5)
		{
			link.dlog("SCIQR: Leaving wait state and connecting...");
			sciqrState=1;
			link.Connect();
			SetTimer(0.1,True);
		}
		else
		{
			if (sciqrState == 4)
			{
				link.dlog("SCIQR: Link is closed.");
				sciqrState=5;
				SetTimer(60,False);
			}
			else
			{
				if (link.HadError())
				{
					link.dlog("SCIQR: Link reported error.");
					if (sciqrState == 1 || sciqrState == 5)
					{
						sciqrState=5;
						SetTimer(60,False);
					}
					else
					{
						sciqrState=4;
						link.Disconnect();
						SetTimer(0.1,True);
					}
				}
				else
				{
					if (sciqrState == 1)
					{
						if (bRegistered)
						{
							link.dlog("SCIQR: Sending heartbeat...");
							sciqrState=3;
							doRegistration();
							doHeartbeat();
						}
						else
						{
							link.dlog("SCIQR: Sending server registration...");
							sciqrState=2;
							doRegistration();
						}
						SetTimer(0.1,True);
					}
					else
					{
						if (sciqrState == 2)
						{
							parseRegistrationResponse(link.GetResponseString());
							if (myGuid != "")
							{
								Log("SCIQR: Our andromeda GUID is:" @ myGuid);
								bRegistered=True;
							}
							else
							{
								Log("SCIQR: Master server didn't assign us a GUID, or we misparsed it.");
								Log("SCIRQ:   ...will try again in" @ 60 @ "seconds.");
								bRegistered=False;
							}
							sciqrState=4;
							link.Disconnect();
							SetTimer(0.1,True);
						}
						else
						{
							if (sciqrState == 3)
							{
								sciqrState=4;
								link.Disconnect();
								SetTimer(0.1,True);
							}
						}
					}
				}
			}
		}
	}
	*/
}
