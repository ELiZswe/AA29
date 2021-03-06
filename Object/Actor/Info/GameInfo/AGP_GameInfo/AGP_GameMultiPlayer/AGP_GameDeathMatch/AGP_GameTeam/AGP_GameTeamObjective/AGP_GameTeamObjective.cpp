// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeamObjective/AGP_GameTeamObjective.h"

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/AGP_TeamInfo/AGP_TeamInfo.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/VehicleTrigger/VehicleTrigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_TriggeredObjective.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"
#include "AA29/Object/Actor/Info/VoiceChatRoom/VoiceChatRoom.h"

AAGP_GameTeamObjective::AAGP_GameTeamObjective()
{
	ForceObjectiveSlot.SetNum(32);
	ForceObjectiveGroupTag.SetNum(32);
	bAllowPrivateChat = true;
	ObjectiveHints = { "Pressing the forward movement key twice in rapid succession will make your character run in that direction.",
	"You can lean around corners by pressing either %LEANLEFT% or %LEANRIGHT%.",
	"To jump, press %JUMP%.",
	"You can change your pace to Walk (by pressing %WALKING%), Sprint (by pressing %SPRINT%), or Fast Walk (by pressing %FASTMOVE%).",
	"To crouch, press %CROUCHING%. Press again to return to a standing position.",
	"To go Prone, press %CRAWLING%. Press again to return to a standing position.",
	"Most weapons have two firing modes - a regular fire mode when you press %FIRE% and an auto/burst fire mode when you press %ALTFIRE%.",
	"You can change weapons by pressing the associated weapon number, or scroll through your weapons using %NEXTWEAPON% and %PREVWEAPON%.",
	"You can toss your current weapon for a teammate by pressing %THROWWEAPON%.",
	"You can zoom in on your target by pressing %ZOOM%.",
	"If your weapon runs out of ammunition, press %RELOAD% to get back in the action.",
	"If your weapon jams, press %FIXJAM% to fix the jam.",
	"On ranged weapons, the range can be increased (by pressing %INCREASERANGE%) or decreased (by pressing %DECREASERANGE%), or zeroed (by pressing %ZERORANGE%).",
	"",
	"",
	"To add or remove a Barrel Mod (Suppressor), press %SUPPRESSOR%.",
	"You can switch to the Frag Grenade by pressing %GRENADEFRAG%.",
	"You can switch to the Smoke Grenade by pressing %GRENADESMOKE%.",
	"You can switch to the Flash Grenade by pressing %GRENADEFLASH%.",
	"You can switch to the Thermite Grenade by pressing %GRENADEINCENDIARY%.",
	"You can switch to the Door Breacher by pressing %DEMOLITIONITEM%.",
	"You can switch to the Pistol by pressing %PISTOL%.",
	"Press %TALK% and type your message to send text messages to other players.",
	"Press %TEAMTALK% and type your message to send text messages to other team members.",
	"",
	"You can give orders and cycle through other commo voice messages by pressing %COMMOCYCLE%.",
	"To report in to your teammates, press %REPORTIN%.",
	"If you are wounded, you can call for a medic by pressing %CALLMEDIC%.",
	"As Squad Leader, you can identify an objective and set it as the squad target by pressing %SETSQUADTARGET%.",
	"You can toggle the Scoreboard display on or off at any time by pressing %SHOWSCORES%.",
	"You can toggle the Weapon Class Selection display on or off at any time by pressing %SELECTCLASS%.",
	"You can toggle the Team Selection display on or off at any time by pressing %SELECTTEAM%.",
	"You can toggle the Map and Mission Objectives display on or off at any time by pressing %SHOWOBJECTIVES%.",
	"You can perform various in-game actions such as accomplishing objectives, opening doors, and controlling a teammate's bleeding, all by pressing %ACTION% at the appropriate time.",
	"If you have Binoculars in your inventory, you can use them by pressing %BINOCULARS%.",
	"If you have Night Vision Goggles in your inventory, you can use them by pressing %NV%.",
	"To take a screenshot, press %SHOT%.",
	"You can toggle console at any time by pressing %CONSOLETOGGLE%.",
	"To view the current connection status, press %STAT NET%.",
	"While connecting to a server, you can cancel the pending connection by pressing %CANCEL%.",
	"The text-to-speech feature that makes the game read text messages aloud can be enabled in the audio settings menu.",
	"You can see the progress of the PunkBuster update in the console text area.",
	"You can pan the view around using your mouse while you wait for PunkBuster to update.",
	"PunkBuster updates can take up to seven minutes using dial-up or on busy servers.",
	 "You can get additional PunkBuster support at www.evenbalance.com.",
	 "You can learn more at www.americasarmy.com.",
	 "The automatic PunkBuster update service may not be available." };
	ScoreBoardType = "AGP_Gameplay.AGP_ScoreboardTeamObjective";
	BeaconName = "Objective";
	//VoiceReplicationInfoClass = Class'AGP_Game.TeamObjectiveVoiceChatReplicationInfo';
	GameName = "America's Army";
	Description = "Your team must score by either taking objectives or by taking out Opposing Forces.";
}

void AAGP_GameTeamObjective::BeginPlay()
{
	FString HintText;

	UE_LOG(LogTemp, Warning, TEXT("AAGP_GameTeamObjective::BeginPlay()"));
	Super::BeginPlay();
	bTournamentMode=false;
	if(!(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer()))
	{
		UE_LOG(LogTemp, Log, TEXT("IMPORTANT: Global server forcing authorization requirement."));
		bRequireAuthorization=true;
		//Level.Game.SaveConfig();
	}
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Using AAGP_GameTeamObjective"));
		HintText = GetNextLoadHint("");
		GEngine->AddOnScreenDebugMessage(-1, 200, FColor::Green, FString::Printf(TEXT("Hint %s"), *HintText));
		
	}
	PostBeginPlay();
	//SaveConfig();
}

void AAGP_GameTeamObjective::PostBeginPlay()
{
	Super::PostBeginPlay();
	SetupRandomObjectives();
}

void AAGP_GameTeamObjective::StartMatch()
{
	ResetAllObjectives();
	SelectRandomObjectives();
	Super::StartMatch();
}

/*
APlayerController* AAGP_GameTeamObjective::Login(FString Portal, FString Options, FString& Error)
{
	APlayerController* PC;
	PC=Super::Login(Portal,Options,Error);
	return PC;
}
*/

void AAGP_GameTeamObjective::InitVoiceReplicationInfo()
{
	AVoiceChatReplicationInfo* VRIClass = nullptr;
	int32 i = 0;
	/*
	if(GetNetMode() == ENetMode::NM_Standalone || GetNetMode() == ENetMode::NM_Client)
	{
		return;
	}
	if(VoiceReplicationInfoType != "")
	{
		VRIClass=class<VoiceChatReplicationInfo>(DynamicLoadObject(VoiceReplicationInfoType,Class'Class'));
		if(VRIClass != nullptr)
		{
			VoiceReplicationInfoClass=VRIClass;
		}
	}
	if(VoiceReplicationInfoClass != nullptr && VoiceReplicationInfo == nullptr)
	{
		VoiceReplicationInfo=Spawn(VoiceReplicationInfoClass);
	}
	InitVoiceReplicationInfo();
	VoiceReplicationInfo.bPrivateChat=bAllowPrivateChat;
	i=VoiceReplicationInfo.GetChannelIndex(DefaultVoiceChannel);
	if(i != -1 && i != VoiceReplicationInfo.DefaultChannel)
	{
		VoiceReplicationInfo.DefaultChannel=i;
	}
	if(VoiceReplicationInfo != nullptr && TeamObjectiveVoiceChatReplicationInfo(VoiceReplicationInfo) != nullptr)
	{
		TeamObjectiveVoiceChatReplicationInfo(VoiceReplicationInfo).bTeamChatOnly=! bAllowNonTeamChat;
	}
	*/
}

void AAGP_GameTeamObjective::ChangeVoiceChannel(AAA2_PlayerState* PRI, int32 NewChannelIndex, int32 OldChannelIndex)
{
	AVoiceChatRoom* NewChannel = nullptr;
	AVoiceChatRoom* OldChannel = nullptr;
	if(PRI == nullptr)
	{
		return;
	}
	if(VoiceReplicationInfo == nullptr)
	{
		return;
	}
	/*
	if(NewChannelIndex >= 0)
	{
		NewChannel=VoiceReplicationInfo.GetChannelAt(NewChannelIndex);
		if(NewChannel == nullptr)
		{
			return;
		}
		NewChannel.AddMember(PRI);
	}
	OldChannel=VoiceReplicationInfo.GetChannelAt(OldChannelIndex);
	if(OldChannel != nullptr)
	{
		OldChannel.RemoveMember(PRI);
	}
	*/
}
void AAGP_GameTeamObjective::SetupRandomObjectives()
{
	TSubclassOf<AAGP_Objective*> obj = nullptr;
	/*
	for (obj = firstObjective; obj != nullptr; obj = obj->nextObjective)
	{
		if (ShouldAddToList(obj))
		{
			RandomTags[RandomTags.Num()] = obj->RandomTag;
		}
	}
	*/
}
bool AAGP_GameTeamObjective::ShouldAddToList(AAGP_Objective* Add)
{
	int32 i = 0;
	TSubclassOf<AAGP_Objective*> obj = nullptr;
	if ((Add->RandomTag == "None") || (Add->RandomTag == "None"))
	{
		return false;
	}
	for (i = 0; i < RandomTags.Num(); i++)
	{
		if (RandomTags[i] == Add->RandomTag)
		{
			return false;
		}
	}
	/*
	for (obj = Add->nextObjective; obj != nullptr; obj = obj->nextObjective)
	{
		if (obj->RandomTag == Add->RandomTag)
		{
			return true;
		}
	}
	*/
	//DebugLog(DEBUG_Warn, "AGP_GameTeamObjective::ShouldAddToList()	Objective(" @ FString::FromInt(Add) @ ") has a unique RandomTag(" @ FString::FromInt(Add.RandomTag) @ "). This objective will always be on");
	return false;
}

void AAGP_GameTeamObjective::SelectRandomObjectives()
{
	int32 i = 0;
	DumpObjectives();
	for(i=0; i<RandomTags.Max(); i++)
	{
		//DebugLog(DEBUG_Multi,Self + " Selecting Objective for Tag: " + RandomTags[i]);
		SelectObjectiveForTag(RandomTags[i]);
	}
}

void AAGP_GameTeamObjective::DumpObjectives()
{
	int32 i = 0;
	int32 X=0;
	TSubclassOf<AAGP_Objective> obj;

	UE_LOG(LogTemp, Warning, TEXT("========================================================"));
	UE_LOG(LogTemp, Warning, TEXT("= DUMP PSSETS"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================"));

	for(i=0; i<PSSets.Num(); i++)
	{
		//UE_LOG(LogTemp, Warning, TEXT("= SLOT %s: Found PSSet: %s for Team: %s"), FString::FromInt(i), PSSets[i]->SetTag, FString::FromInt(PSSets[i]->Team));
	}
	UE_LOG(LogTemp, Warning, TEXT("========================================================"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================"));
	UE_LOG(LogTemp, Warning, TEXT("= DUMP OBJECTIVES"));
	UE_LOG(LogTemp, Warning, TEXT("========================================================"));

	for(i=0; i<RandomTags.Num(); i++)
	{
		//UE_LOG(LogTemp, Warning, TEXT("= Found objective group: %s"), (RandomTags[i]).ToString());
		/*
		for (obj = firstObjective; obj != nullptr; obj = obj->nextObjective)
		{
			if (obj->RandomTag == RandomTags[i])
			{
				//DebugLog(DEBUG_Multi, "*** Slot: " + FString::FromInt(X) + " Object: " + FString::FromInt(obj) + ". Location: " + FString::FromInt(obj.Location));
				X++;
			}
		}
		*/
		X=0;
	}
	UE_LOG(LogTemp, Warning, TEXT("==================================================================================="));
}

/* =================================================================================== *
 * AGP function SelectObjectiveForTag()
 *	For a given tag, activate one objective that has that tag, and inactivate the rest
 *
 * last modified by: cmb
 * =================================================================================== */

void AAGP_GameTeamObjective::SelectObjectiveForTag(FName Tag)
{
	AAGP_Objective* obj = nullptr;
	TArray<AAGP_Objective*> ObjList;
	int32 i = 0;
	int32 X = 0;
	int32 Index = 0;
	bool bFound = false;
	/*
	AVehicleTrigger* VT = nullptr;
	for (obj = firstObjective; obj != nullptr; obj = obj.nextObjective)
	{
		if (obj.RandomTag == Tag)
		{
			ObjList[ObjList.Num()] = obj;
		}
	}
	X = 0;
	if (X < 32)
	{
		if (ForceObjectiveGroupTag[X] != "None")
		{
			if (Tag == ForceObjectiveGroupTag[X])
			{
				Index = ForceObjectiveSlot[X];
				bFound = true;
			}
			else
			{
			}
		else
		{
		}
		X++;
		}
	}
	if (!bFound)
	{
		Index = Rand(ObjList.Num());
	}
	for (i = 0; i < ObjList.Num(); i++)
	{
		if (i == Index)
		{
			if ((ObjList[i].RandomSelectedEvent != "None") && (ObjList[i].RandomSelectedEvent != "None"))
			{
				TriggerEvent(ObjList[i].RandomSelectedEvent, ObjList[i], nullptr);
				ForEach AllActors(AVehicleTrigger::StaticClass(), VT)
				{
					VT.RandomObjectiveTag = ObjList[i].RandomSelectedEvent;
				}
			}
			DebugLog(DEBUG_Multi, FString::FromInt(this) + " ActiveObject : " + FString::FromInt(ObjList[i]) + " at Location: " + FString::FromInt(ObjList[i].Location));
		}
		ObjList[i].SetInactive((i != Index));
	}
	*/
}
void AAGP_GameTeamObjective::ScoreAGPObjective(ATeamInfo* Team, AActor* Objective, bool _bGameEnded, AAA2_PlayerState* Scorer, bool bScorerOnly)
{
	AAGP_Objective* obj;
	AAGP_TeamInfo* ateam;
	obj=Cast<AAGP_Objective>(Objective);
	ateam=Cast<AAGP_TeamInfo>(Team);
	if(obj == nullptr || ateam == nullptr)
	{
		//DebugLog(DEBUG_Warn,"AGP_GameTeamObjective::ScoreAGPObjective()	Invalid input " + obj @ ateam);
		return;
	}
	if(obj->CanTeamInfoAttack(ateam))
	{
		ateam->ScoreAGPObjective(obj,Scorer,bScorerOnly);
	}
	else
	{
		//DebugLog(DEBUG_Warn,"AGP_GameTeamObjective::ScoreAGPObjective()	Can't score" @ obj @ "for team" @ Team);
	}
	if(_bGameEnded)
	{
		return;
	}
	CheckIfGameOver();
}
void AAGP_GameTeamObjective::ScoreDecoMesh(ATeamInfo* Team, AActor* Objective, int32 ScorePoints, AAA2_PlayerState* Scorer, bool bScorerOnly)
{
	AAGP_TeamInfo* ateam;
	ateam=Cast<AAGP_TeamInfo>(Team);
	if(ateam != nullptr)
	{
		ateam->ScoreDecoMesh(Scorer,ScorePoints,bScorerOnly);
	}
}
void AAGP_GameTeamObjective::ScoreKill(AController* Killer, AController* Other, UaDamageType* DamageType)
{
	AAGP_Objective* defended = nullptr;
	AAGP_TeamInfo* kTeam;

	if(Other != nullptr && Cast<AHumanController>(Other)->PlayerReplicationInfo != nullptr)
	{
		defended=Cast<AAGP_Objective>(Cast<AHumanController>(Other)->PlayerReplicationInfo->GetNearbyObjective(nullptr,true));
	}
	if(Killer != nullptr && Cast<AHumanController>(Killer)->PlayerReplicationInfo != nullptr && Other != nullptr && Cast<AHumanController>(Other)->PlayerReplicationInfo != nullptr && Cast<AHumanController>(Other)->PlayerReplicationInfo->Team != nullptr)
	{
		if(defended != nullptr && Cast<AHumanController>(Killer)->PlayerReplicationInfo->Team != Cast<AHumanController>(Other)->PlayerReplicationInfo->Team && defended->CanTeamAttack(Cast<AHumanController>(Other)->PlayerReplicationInfo->Team->TeamIndex))
		{
			kTeam=Cast<AAGP_TeamInfo>(Cast<AHumanController>(Killer)->PlayerReplicationInfo->Team);
			kTeam->ScoreDefendObjective(defended, Cast<AHumanController>(Killer)->PlayerReplicationInfo);
		}
	}
	Super::ScoreKill(Killer,Other,DamageType);
}

void AAGP_GameTeamObjective::SetSquadTarget(int32 iTeamIndex, uint8 objnum)
{
	TSubclassOf<AAGP_Objective> obj;
	bool objfound;
	objfound=false;
	obj=firstObjective;
	if(obj != nullptr)
	{
		if(Cast<AAGP_Objective>(obj)->HUDLetter == objnum)
		{
			objfound=true;
		}
		else
		{
			obj= Cast<AAGP_Objective>(obj)->nextObjective;
		}
	}
	if(! objfound)
	{
		//DebugLog(DEBUG_Multi,"AGP_GameTeamObjective::SetSquadTarget() found no target numbered" @ objnum);
		return;
	}
	/*
	for (obj = firstObjective; obj != nullptr; obj = obj->nextObjective)
	{
		if (obj->HUDLetter == objnum)
		{
			obj->SetSquadTarget(iTeamIndex, true);
		}
		else
		{
			obj->SetSquadTarget(iTeamIndex, false);
		}
	}
	*/
}

void AAGP_GameTeamObjective::CheckScore(AAA2_PlayerState* Scorer)
{
	AAGP_Objective* obj = nullptr;
	AAGP_TriggeredObjective* trigObj = nullptr;
	AController* C = nullptr;
	bool bFoundSomeone = false; 
	/*
	if(! IsInState('MatchInProgress'))
	{
		return;
	}
	obj=firstObjective;
	if(obj != nullptr)
	{
		if(! obj.IsRequired() || ! obj.IsEnabled())
		{
		}
		trigObj=AGP_TriggeredObjective(obj);
		if(trigObj == nullptr)
		{
		}
		if(trigObj.MustBeClass == nullptr)
		{
			if(! trigObj.bCheckRequiredChildObjectives || trigObj.ChildSequence.Num() == 0)
			{
			}
		}
		else
		{
			bFoundSomeone=false;
			C=Level.ControllerList;
			if(C != nullptr)
			{
				if(C->IsA(AaAIController::StaticClass()))
				{
				}
				if(! C.bIsPlayer || C.PlayerReplicationInfo == nullptr || C.Pawn == nullptr)
				{
				}
				if(trigObj.CanAccomplish(C.Pawn))
				{
					bFoundSomeone=true;
				}
				else
				{
					C=C.nextController;
				}
			}
			if(! bFoundSomeone)
			{
				switch(trigObj.AttackTeam)
				{
					case 0:
					PendingEndGame(Teams[1].GetSquadLeader(None),"ObjectiveImpossible");
					return;
					case 1:
					PendingEndGame(Teams[0].GetSquadLeader(None),"ObjectiveImpossible");
					return;
					default:
					PendingEndGame(None,"ObjectiveImpossible");
					return;
				}
			}
			obj=obj.nextObjective;
			break;
		}
		CheckScore(Scorer);
	*/
}

void AAGP_GameTeamObjective::EndGame(AAA2_PlayerState* Winner, FString Reason)
{
	bool bTeam0Won=false;
	bool bTeam1Won = false;
	bool bRequiredObjectivesFound = false;
	bool bDefenseWinsOnTie = false;
	bool bTeam0HasObj = false;
	bool bTeam1HasObj = false;
	TSubclassOf<AAGP_Objective> obj;
	if(CheckDontEndGame(Reason))
	{
		return;
	}
	if(Reason == "TimeLimit")
	{
		bDefenseWinsOnTie=true;
		for (obj = firstObjective; obj != nullptr; obj = Cast<AAGP_Objective>(obj)->nextObjective)
		{
			if (Cast<AAGP_Objective>(obj)->AttackTeam == 0)
			{
				bTeam0HasObj = true;
			}
			if (Cast<AAGP_Objective>(obj)->AttackTeam == 1)
			{
				bTeam1HasObj = true;
			}
			if (Cast<AAGP_Objective>(obj)->IsRequired())
			{
				bRequiredObjectivesFound = true;
			}
			if (Cast<AAGP_Objective>(obj)->IsAlternating())
			{
				bDefenseWinsOnTie = false;
			}
		}
		if(! bRequiredObjectivesFound)
		{
			UE_LOG(LogTemp, Warning, TEXT("WARNING: no required objectives found on map"));
		}

		for (obj = firstObjective; obj != nullptr; obj = Cast<AAGP_Objective>(obj)->nextObjective)
		{
			if ((Cast<AAGP_Objective>(obj)->IsEnabled() && Cast<AAGP_Objective>(obj)->IsRequired()) && (!Cast<AAGP_Objective>(obj)->IsAlternating()))
			{
				if (Cast<AAGP_Objective>(obj)->AttackTeam == 0)
				{
					if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
					{
						ScoreAGPObjective(Teams[1], Cast<AAGP_Objective>(obj), true, nullptr, false);
					}
					bTeam1Won = true;
				}
				else
				{
					if (Cast<AAGP_Objective>(obj)->AttackTeam == 1)
					{
						ScoreAGPObjective(Teams[0], Cast<AAGP_Objective>(obj), true, nullptr,false);
						bTeam0Won = true;
					}
				}
			}
		}
		if(bTeam0Won && bTeam1Won)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeamObjective::EndGame()	Got two winners?!"));
		}
		else
		{
			if(bTeam0Won)
			{
				Reason="Objective";
				Winner=Teams[0]->GetAnyTeamMember();
			}
			else
			{
				if(bTeam1Won)
				{
					Reason="Objective";
					if(Teams[1] != nullptr)
					{
						Winner=Teams[1]->GetAnyTeamMember();
					}
					else
					{
						Winner=nullptr;
					}
				}
				else
				{
					if(bDefenseWinsOnTie && ! bTeam0HasObj && bTeam1HasObj)
					{
						if(! bTeam0HasObj)
						{
							Reason="Objective";
							Winner=Teams[0]->GetAnyTeamMember();
						}
						else
						{
							if(! bTeam1HasObj)
							{
								Reason="Objective";
								if(Teams[1] != nullptr)
								{
									Winner=Teams[1]->GetAnyTeamMember();
								}
							}
						}
					}
				}
			}
		}
	}
	else
	{
		if(Reason == "TeamDead" || Reason == "CheatEndGame")
		{
			if(Winner != nullptr && Winner->Team != nullptr)
			{
				for (obj = firstObjective; obj != nullptr; obj = Cast<AAGP_Objective>(obj)->nextObjective)
				{
					if (Cast<AAGP_Objective>(obj)->IsEnabled() && Cast<AAGP_Objective>(obj)->IsRequired())
					{
						ScoreAGPObjective(Winner->Team, Cast<AAGP_Objective>(obj), true, nullptr, false);
					}
				}
			}
		}
	}
	for (obj = firstObjective; obj != nullptr; obj = Cast<AAGP_Objective>(obj)->nextObjective)
	{
		Cast<AAGP_Objective>(obj)->StopCounting();
	}
	Super::EndGame(Winner,Reason);
}

void AAGP_GameTeamObjective::PendingEndGame(AAA2_PlayerState* Winner, FString Reason, int32 _EndTime)
{
	TSubclassOf<AAGP_Objective> obj;
	Super::PendingEndGame(Winner, Reason, EndTime);
	for (obj = firstObjective; obj != nullptr; obj = Cast<AAGP_Objective>(obj)->nextObjective)
	{
		Cast<AAGP_Objective>(obj)->StopCounting();
	}

}

bool AAGP_GameTeamObjective::CheckTeamWon(uint8 Team)
{
	TSubclassOf<AAGP_Objective> obj;
	bool bAccomplishedRequired = false;
	bool bMissingRequired = false;
	int32 iNumAccomplishedObjectives = 0;
	for (obj = firstObjective; obj != nullptr; obj = Cast<AAGP_Objective>(obj)->nextObjective)
	{
		if (Cast<AAGP_Objective>(obj)->WasAccomplishedBy(Team))
		{
			if (Cast<AAGP_Objective>(obj)->IsInstantWin())
			{
				return true;
			}
			else
			{
				if (Cast<AAGP_Objective>(obj)->IsRequired())
				{
					bAccomplishedRequired = true;
					iNumAccomplishedObjectives++;
				}
			}
		}
		else
		{
			if (Cast<AAGP_Objective>(obj)->IsRequired())
			{
				bMissingRequired = true;
			}
		}
	}
	if (Team < 2)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->NumAccomplishedObjectivesRequired[Team] > 0)
		{
			if (iNumAccomplishedObjectives == Cast<AAA2_WorldSettings>(GetWorldSettings())->NumAccomplishedObjectivesRequired[Team])
			{
				return (iNumAccomplishedObjectives == Cast<AAA2_WorldSettings>(GetWorldSettings())->NumAccomplishedObjectivesRequired[Team]);
			}
		}
	}
	if (bAccomplishedRequired)
	{
		return (!bMissingRequired);
	}
	else
	{
		return false;
	}
}
void AAGP_GameTeamObjective::CheckIfGameOver()
{
	bool bTeam0Won;
	bool bTeam1Won;
	bTeam0Won=CheckTeamWon(0);
	if(Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		bTeam1Won=CheckTeamWon(2);
	}
	else
	{
		bTeam1Won=CheckTeamWon(1);
	}
	if(bTeam0Won && bTeam1Won)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameTeamObjective::CheckIfGameOver()	Got two winners?!"));
		EndGame(nullptr,"ObjectiveImpossible");
	}
	else
	{
		if(bTeam0Won)
		{
			EndGame(Teams[0]->GetAnyTeamMember(),"Objective");
		}
		else
		{
			if(bTeam1Won)
			{
				EndGame(Teams[1]->GetAnyTeamMember(),"Objective");
			}
		}
	}
}
void AAGP_GameTeamObjective::ResetAllObjectives()
{
	TSubclassOf<AAGP_Objective> obj;
	for (obj = firstObjective; obj != nullptr; obj = Cast<AAGP_Objective>(obj)->nextObjective)
	{
		Cast<AAGP_Objective>(obj)->Reset();
	}
}

void AAGP_GameTeamObjective::FakeRestartGame()
{
	ResetAllObjectives();
	Super::FakeRestartGame();
}

int32 AAGP_GameTeamObjective::GetAliveTeam()
{
	if(Teams[0]->bDead && ! Teams[1]->bDead)
	{
		return 1;
	}
	if(! Teams[0]->bDead && Teams[1]->bDead)
	{
		return 0;
	}
	return -1;
}

TSubclassOf<AAGP_Objective> AAGP_GameTeamObjective::GetNextObjective(uint8 Team, bool Attacking)
{
	TSubclassOf<AAGP_Objective> cgo;
	TSubclassOf<AAGP_Objective> bestobj;
	int32 bestpriority = 0;
	bestpriority = -1;
	bestobj = nullptr;
	for (cgo = firstObjective; cgo != nullptr; cgo = Cast<AAGP_Objective>(cgo)->nextObjective)
	{
		if (Cast<AAGP_Objective>(cgo)->IsEnabled())
		{
			if ((Cast<AAGP_Objective>(cgo)->CanTeamAttack(Team) && Attacking) || ((!Cast<AAGP_Objective>(cgo)->CanTeamAttack(Team)) && (!Attacking)))
			{
				if (Cast<AAGP_Objective>(cgo)->bInstantWin)
				{
					return cgo;
				}
				if (Cast<AAGP_Objective>(cgo)->AttackPriority > bestpriority)
				{
					bestpriority = Cast<AAGP_Objective>(cgo)->AttackPriority;
					bestobj = cgo;
				}
			}
		}
	}
	if (bestpriority > 0)
	{
		return bestobj;
	}
	return nullptr;
}

void AAGP_GameTeamObjective::SetFirstObjective(AActor* Objective)
{
	/*
	TSubclassOf<AAGP_Objective> AO;
	AO = Cast<AAGP_Objective>(Objective);
	if(firstObjective == nullptr)
	{
		firstObjective=AO;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GAMETEAMOBJECTIVE:  attempted to reset first objective."));
	}
	*/
}

void AAGP_GameTeamObjective::grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController)
{
	TSubclassOf<AAGP_Objective> obj;
	for (obj = firstObjective; obj != nullptr; obj = Cast<AAGP_Objective>(obj)->nextObjective)
	{
		Cast<AAGP_Objective>(obj)->grenadeNotifier(Explosive, DamageType, KillerController);
	}
}

FString AAGP_GameTeamObjective::GetNextLoadHint(FString MapName)
{
	TArray<FString> Hints;
	Hints = GetAllLoadHints(true);
	return Hints[FMath::RandRange(0,Hints.Max()-1)];
}

TArray<FString> AAGP_GameTeamObjective::GetAllLoadHints(bool bThisClassOnly) 
{
	return ObjectiveHints;
}

void AAGP_GameTeamObjective::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	if (GameSession != nullptr)
	{
		Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	}
}
