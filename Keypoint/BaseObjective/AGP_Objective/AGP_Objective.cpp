// All the original content belonged to the US Army


#include "AGP_Objective.h"
#include "AA29/Info/ReplicationInfo/TeamInfo/TeamInfo.h"

AAGP_Objective::AAGP_Objective(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	bFirstObjective			= true;
	AccomplishedBy			= 255;
	AttackTeam				= 255;
	AccomplishMessage		= "Your team accomplished the objective.";
	FailedDefenseMessage	= "Your team failed to defend the objective.";
	AttackDescription		= "Attack the objective.";
	DefenseDescription		= "Defend the objective.";
	AccomplishSound			= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Objective/Generic/objectiveaccomplished.objectiveaccomplished"), NULL, LOAD_None, NULL);
	ProgressSound			= LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Objective/Generic/warningpip.warningpip"), NULL, LOAD_None, NULL);
	ProgressSoundStart		= 20;
	ProgressSoundInterval	= 41;
	fROE_Damage_Multiplier	= 1;
	USPickupMsg				= "Your Team has picked up the objective.";
	OPFORPickupMsg			= "The Opposing Team has picked up the objective.";
	//bStatic = false;
	//bHidden = false;
	Texture					= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/Engine/AGP_Objective.AGP_Objective"), NULL, LOAD_None, NULL);
}


void AAGP_Objective::BlinkObjectiveOnRadar(int32 iTeam, float BlinkDuration)
{
	/*
		if (iTeam == 0)
		{
			if (GetWorld()->GetTimeSeconds() > RadarBlinkEndTime)
			{
				RadarBlinkStartTime=GetWorld()->GetTimeSeconds();
			}
			if (GetWorld()->GetTimeSeconds() + BlinkDuration > RadarBlinkEndTime)
			{
				RadarBlinkEndTime=GetWorld()->GetTimeSeconds() + BlinkDuration;
			}
		}
		else
		{
			if (iTeam == 1)
			{
				if (GetWorld()->GetTimeSeconds() > RadarBlinkEndTime1)
				{
					RadarBlinkStartTime1=GetWorld()->GetTimeSeconds();
				}
				if (GetWorld()->GetTimeSeconds() + BlinkDuration > RadarBlinkEndTime1)
				{
					RadarBlinkEndTime1=GetWorld()->GetTimeSeconds() + BlinkDuration;
				}
			}
		}
	*/
}
void AAGP_Objective::BeginPlay()
{
	_OriginalAttackTeam=AttackTeam;
	_OriginalObjectiveOnCompass=ObjectiveOnCompass;
	Super::BeginPlay();
}
void AAGP_Objective::InitializeVolumesAndZones()
{
	/*
		local Actor A;
		local Volume V;
		local ZoneInfo Z;
		if (ObjectiveTag == 'None' || ObjectiveTag == 'None')
		{
			Return;
		}
		ForEach AllActors(Class'Actor',A)
		{
			if (A.IsA('Volume'))
			{
				V=Volume(A);
				if (V.LocationObjective == ObjectiveTag)
				{
					V.Objective=Self;
				}
			}
			else
			{
				if (A.IsA('ZoneInfo'))
				{
					Z=ZoneInfo(A);
					if (Z.LocationObjective == ObjectiveTag)
					{
						Z.Objective=Self;
					}
				}
			}
		}
	*/
}
void AAGP_Objective::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	InitializeVolumesAndZones();
}
void AAGP_Objective::PostBeginPlay()
{
	/*
		local AGP_Objective O;
		local AGP_Objective CurrentObjective;
		PostBeginPlay();
		if (bFirstObjective)
		{
			CurrentObjective=Self;
			ForEach AllActors('AGP_Objective',O)
			{
				if (O != CurrentObjective)
				{
					CurrentObjective.nextObjective=O;
					O.bFirstObjective=False;
					CurrentObjective=O;
				}
			}
		}
		if (bFirstObjective && Role == 4)
		{
			AGP_GameInfo(Level.Game).SetFirstObjective(Self);
		}
		InitializeNPCObjective();
		InitializeVisibilityObjective();
		InitializeSequenceObjective();
		InitializeInventoryObjective();
		ResetLocationProxy();
		SetTeamMesh();
		pawnMustBeUsedBy=None;
		bPlayerRadioedObectiveInfo=False;
		ctrlrESSReporter=None;
	*/
}
void AAGP_Objective::InitializeNPCObjective()
{
	/*
		local Pawn NPC;
		ForEach RadiusActors(Class'Pawn',NPC,24)
		{
			if (NPC.IsA('AGP_Pawn') && ! NPC.IsPlayerPawn())
			{
				LinkedNPC=NPC;
			}
			else
			{
			}
		}
	*/
}
void AAGP_Objective::HandleGrenadeDamage()
{
	/*
		if (LinkedNPC != None)
		{
			if (! LinkedNPC.bHidden)
			{
				Return True;
			}
		}
		Return False;
	*/
}
void AAGP_Objective::InitializeVisibilityObjective()
{
	/*
		local AGP_Objective AO;
		if (VisibilityChildTag != 'None')
		{
			ForEach AllActors('AGP_Objective',AO)
			{
				if (AO.VisibilityTag == VisibilityChildTag)
				{
					VisibilityChildren[VisibilityChildren.Length]=AO;
				}
			}
		}
	*/
}
void AAGP_Objective::InitializeInventoryObjective()
{
	/*
		local AGP_ObjectivePickup OPickup;
		if (InventoryTag != 'None')
		{
			ForEach AllActors('AGP_ObjectivePickup',OPickup)
			{
				if (InventoryTag == OPickup.InventoryTag)
				{
					if (InventoryPickup == None)
					{
						InventoryPickup=OPickup;
					}
					else
					{
						DebugLog(DEBUG_Warn,"AGP_Objective::InitializeInventoryObjective()	Found multiple matching InventoryPickups! Tag(" @ InventoryTag @ ") Duplicate(" @ OPickup @ ")");
					}
				}
			}
			if (InventoryPickup != None)
			{
				if (InventoryPickup.Objective == None)
				{
					InventoryPickup.setObjective(Self);
				}
				else
				{
					InventoryPickup=None;
					DebugLog(DEBUG_Warn,"AGP_Objective::InitializeInventoryObjective()	InventoryPickup already has an objective! Existing(" @ InventoryPickup @ ")");
				}
			}
			else
			{
				DebugLog(DEBUG_Warn,"AGP_Objective::InitializeInventoryObjective() Failed to find an InventoryPickup with matching Tag(" @ InventoryTag @ ")");
			}
		}
	*/
}
void AAGP_Objective::ResetLocationProxy()
{
	LocationProxy=NULL;
}
void AAGP_Objective::SetLocationProxy(TSubclassOf<class AActor> new_proxy)
{
	LocationProxy=new_proxy;
}
void AAGP_Objective::IsOnCompass(AController* ctrlRequesting)
{
	/*
		local PlayerReplicationInfo ProxyPRI;
		local PlayerReplicationInfo ClientPRI;
		if (ctrlRequesting == None)
		{
			ctrlRequesting=Level.GetClient().GetController();
		}
		Switch(ObjectiveOnCompass)
		{
			case 1:
			Return False;
			case 2:
			if (ctrlRequesting.PlayerReplicationInfo.Team != None)
			{
				Return ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex == 0;
				break;
			}
			Return False;
		}
		GOTO JL028D;
		case 3:
		if (ctrlRequesting.PlayerReplicationInfo.Team != None)
		{
			Return ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex == 1;
		}
		else
		{
			Return False;
		}
		GOTO JL028D;
		case 4:
		if (! IsEnabled() || ctrlRequesting.PlayerReplicationInfo.Team != None && ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex != 0)
		{
			Return False;
		}
		if (IsA('AGP_ESSObjective') && ctrlRequesting.PlayerReplicationInfo.Team != None && ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex != 0)
		{
			Return False;
		}
		GOTO JL028D;
		case 5:
		if (! IsEnabled() || ctrlRequesting.PlayerReplicationInfo.Team != None && ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex != 1)
		{
			Return False;
		}
		if (IsA('AGP_ESSObjective') && ctrlRequesting.PlayerReplicationInfo.Team != None && ctrlRequesting.PlayerReplicationInfo.Team.TeamIndex != 1)
		{
			Return False;
		}
		GOTO JL028D;
		case 6:
		if (IsEnabled() && Level.GetClient() != None && ctrlRequesting != None && ctrlRequesting.Pawn == pawnMustBeUsedBy)
		{
			Return True;
		}
		else
		{
			Return False;
		}
		GOTO JL028D;
		default:
	JL028D:
		if (LocationProxy != None)
		{
			if (LocationProxy.IsA('PlayerReplicationInfo'))
			{
				ClientPRI=ctrlRequesting.PlayerReplicationInfo;
				ProxyPRI=PlayerReplicationInfo(LocationProxy);
				if (ProxyPRI == ClientPRI || ClientPRI == None)
				{
					Return False;
				}
				else
				{
					Return ClientPRI.IsFriend(ProxyPRI);
				}
			}
			else
			{
				if (LocationProxy.IsA('AGP_ObjectivePickup'))
				{
					Return AGP_ObjectivePickup(LocationProxy).ReadyToPickup(0);
				}
				else
				{
					Return True;
				}
			}
		}
		else
		{
			Return IsEnabled();
		}
	*/
}
FVector AAGP_Objective::GetCompassLocation()
{
	if (LocationProxy == NULL)
	{
		//return Location;
	}
	else
	{
		/*
		if (LocationProxy.IsA('PlayerReplicationInfo'))
		{
			return PlayerReplicationInfo(LocationProxy).GetPawnLocation();
		}
		else
		{
			return LocationProxy->Location;
		}
		*/
	}
	return FVector(0, 0, 0);    //FAKE    /ELiZ
}
void AAGP_Objective::InitializeSequenceObjective()
{
	/*
		local AGP_Objective AO;
		local int i;
		if (ParentTags.Length > 0)
		{
			ForEach AllActors('AGP_Objective',AO)
			{
				if (AO.SequenceTag != 'None')
				{
					for (i=0; i<ParentTags.Length; i++)
					{
						if (AO.SequenceTag == ParentTags[i])
						{
							AddSequenceParent(AO);
						}
					}
				}
			}
		}
		VerifyAllParentsFound();
		if (ParentSequence.Length != 0)
		{
			SetDisabled(True);
		}
	*/
}
void AAGP_Objective::VerifyAllParentsFound()
{
	/*
	local int i;
		local int j;
		local bool bFound;
		if (ParentTags.Length == ParentSequence.Length)
		{
			Return;
		}
		for (i=0; i<ParentTags.Length; i++)
		{
			bFound=False;
			j=0;
			if (j < ParentSequence.Length)
			{
				if (ParentSequence[j].SequenceTag == ParentTags[i])
				{
					bFound=True;
				}
				else
				{
					j ++;
				}
			}
			if (! bFound)
			{
				DebugLog(DEBUG_Warn,"AGP_Objective::WarnParentsMissing()	Could not find parent" @ ParentTags[i]);
			}
		}
	*/
}
bool AAGP_Objective::IsAParentOf(TSubclassOf<AAGP_Objective> AO)
{
	int32 i;
	if (Cast<AAGP_Objective>(AO) == this)
	{
		return true;
	}
	for (i=0; i<ParentSequence.Num(); i++)
	{
		if (Cast<AAGP_Objective>(ParentSequence[i])->IsAParentOf(AO))
		{
			return true;
		}
	}
	return false;
}
void AAGP_Objective::AddSequenceParent(TSubclassOf<AAGP_Objective> AO)
{
	/*
	int32 i;
	if (Cast<AAGP_Objective>(AO)->IsAParentOf(this))
	{
		//DebugLog(DEBUG_Error,"AGP_Objective::AddSequenceParent()	Avoiding parent loop: Cannot make" @ AO @ " a parent of" @ Self);
		return;
	}
	i=ParentSequence.Num();
	ParentSequence[i]=AO;
	Cast<AAGP_Objective>(AO)->AddSequenceChild(this);
	*/
}
void AAGP_Objective::AddSequenceChild(TSubclassOf<AAGP_Objective> AO)
{
	ChildSequence[ChildSequence.Num()]=AO;
}
void AAGP_Objective::NotifySequenceChildren()
{
	/*
		local int i;
		for (i=0; i<ChildSequence.Length; i++)
		{
			ChildSequence[i].ParentAccomplished(Self);
		}
	*/
}
void AAGP_Objective::ParentAccomplished(TSubclassOf<AAGP_Objective> AO)
{
	bool bActivate=false;
	bool bSomeInactive=false;
	bool bFound = false;
	int32 i;
	for (i=0; i<ParentSequence.Num(); i++)
	{
		if (AO == ParentSequence[i])
		{
			bFound=true;
		}
		else
		{
			if (Cast<AAGP_Objective>(ParentSequence[i])->AccomplishedBy == 255 && !Cast<AAGP_Objective>(ParentSequence[i])->bInactive)
			{
				bSomeInactive=true;
			}
		}
	}
	if (! bFound)
	{
		//DebugLog(DEBUG_Warn,"AGP_Objective::ParentEnabled()	Could not find parent:" @ AO);
		return;
	}
	switch(ActivateOn)
	{
		case EActivateOn::ACTON_AnyParent:
			bActivate=true;
			break;
		case EActivateOn::ACTON_AllParents:
			bActivate=! bSomeInactive;
			break;
		case EActivateOn::ACTON_SameTeam:
			bActivate= Cast<AAGP_Objective>(AO)->AccomplishedBy == AttackTeam;
			break;
		default:
			break;
	}
	SetDisabled(! bActivate);
}
void AAGP_Objective::NotifyLinkUsedBy(APawn* User)
{
	/*
		local byte new_team;
		if (bUseLinkAccomplishes)
		{
			new_team=User.PlayerReplicationInfo.Team.TeamIndex;
			Log("AGP_Objective::NotifyLinkUsedBy()	" @ User @ new_team);
			if (! WasAccomplishedBy(new_team))
			{
				AccomplishObjective(User);
			}
		}
	*/
}
void AAGP_Objective::NotifyLinkDecoDamage(APawn* instigatedBy, int32 DestroyPoints)
{
	/*
		local TeamInfo Team;
		if (Instigator != None && Instigator.PlayerReplicationInfo != None)
		{
			Team=Instigator.PlayerReplicationInfo.Team;
		}
		if (Team != None)
		{
			if (AGP_GameInfo(Level.Game) != None)
			{
				AGP_GameInfo(Level.Game).ScoreDecoMesh(Team,Self,DestroyPoints,Instigator.PlayerReplicationInfo,True);
			}
		}
	*/
}
void AAGP_Objective::NotifyLinkDamage(APawn* instigatedBy, int32 Damage)
{
	/*
		if (DamageTag == 'Civiliandamage' && fROE_Damage_Multiplier == 0)
		{
			fROE_Damage_Multiplier=1;
		}
		NotifyShortCut(instigatedBy,Damage * fROE_Damage_Multiplier,bKickInstigator_Damage,DoWhenLinkDamaged);
	*/
}
void AAGP_Objective::NotifyLinkKill(APawn* instigatedBy)
{
	/*
		NotifyShortCut(instigatedBy,Kill_ROE_Penalty,bKickInstigator_Kill,DoWhenLinkKilled);
	*/
}
void AAGP_Objective::NotifyShortCut(APawn* instigatedBy, int32 ROE, bool Kick, EGameDo DoWhen)
{
	/*
		local PlayerReplicationInfo Winner;
		local string Reason;
		local AGP_GameInfo G;
		G=AGP_GameInfo(Level.Game);
		if (ROE > 0)
		{
			if (instigatedBy != None && instigatedBy.Controller != None && instigatedBy.Controller.IsA('HumanController'))
			{
				HumanController(instigatedBy.Controller).NotifyAdminMessage("Cease Fire - You are hitting a non-combatant.");
			}
			G.RecordFriendlyFire(instigatedBy.PlayerReplicationInfo,None,ROE);
		}
		if (Kick)
		{
			G.Kick(instigatedBy.PlayerReplicationInfo.PlayerName,"ROE");
		}
		Switch(DoWhen)
		{
			case 2:
			Winner=None;
			Reason="ObjectiveImpossible";
			break;
			case 1:
			Winner=None;
			Reason="NoScore";
			break;
			case 3:
			Winner=instigatedBy.PlayerReplicationInfo.Team.GetOtherTeam().GetSquadLeader();
			Reason="ObjectiveImpossible";
			break;
			case 4:
			Winner=instigatedBy.PlayerReplicationInfo;
			Reason="ObjectiveImpossible";
			break;
			case 5:
			Winner=instigatedBy.PlayerReplicationInfo;
			Reason="NoWinner";
			break;
			default:
		}
		if (Reason != "")
		{
			G.EndGame(Winner,Reason);
		}
	*/
}
void AAGP_Objective::SetTeamMesh()
{
	
		switch(AttackTeam)
		{
			case 0:
				if (smTeam1Holds != NULL)
				{
					//SetDrawType(8);
					//SetStaticMesh(smTeam1Holds);
				}
				break;
			case 1:
				if (smTeam0Holds != NULL)
				{
					//SetDrawType(8);
					//SetStaticMesh(smTeam0Holds);
				}
				break;
			case 255:
				if (smUncaptured != NULL)
				{
					//SetDrawType(8);
					//SetStaticMesh(smUncaptured);
				}
				break;
			default:
				break;
		}
	
}
void AAGP_Objective::PawnDied(APawn* p)
{
}
void AAGP_Objective::StopCounting()
{
}
void AAGP_Objective::NotifyParentInactive()
{
	int32 i;
	if (! bInactive)
	{
		for (i=0; i<ParentSequence.Num(); i++)
		{
			if (!Cast<AAGP_Objective>(ParentSequence[i])->bInactive)
			{
				return;
			}
		}
		SetInactive(true);
	}
}
void AAGP_Objective::SetInactive(bool new_inactive)
{
	/*
		local int i;
		bInactive=new_inactive;
		if (bInactive)
		{
			ObjectiveOnCompass=1;
			SetLocationProxy(None);
			SetDisabled(True);
			for (i=0; i<ChildSequence.Length; i++)
			{
				ChildSequence[i].NotifyParentInactive();
			}
		}
		SetCollision(! new_inactive);
		if (InventoryPickup != None)
		{
			InventoryPickup.SetInactiveForRound(bInactive);
		}
		if (LinkedNPC != None)
		{
			if (! new_inactive)
			{
				LinkedNPC.TurnOnPawn(LinkedNPC);
				LinkedNPC.SetCollision(LinkedNPC.Default.bCollideActors,LinkedNPC.Default.bBlockActors,LinkedNPC.Default.bBlockPlayers);
				LinkedNPC.bHidden=False;
				LinkedNPC.bStasis=False;
			}
			else
			{
				LinkedNPC.TurnOffPawn(LinkedNPC);
				LinkedNPC.SetCollision(False,False,False);
				LinkedNPC.bHidden=True;
				LinkedNPC.bStasis=True;
			}
		}
	*/
}
void AAGP_Objective::SetDisabled(bool E)
{
	/*
		if (bInactive)
		{
			bDisabled=True;
		}
		else
		{
			if (E == False && EnabledEvent != 'None' && EnabledEvent != 'None')
			{
				TriggerEvent(EnabledEvent,Self,None);
			}
			bDisabled=E;
		}
	*/
}
void AAGP_Objective::SetSquadTarget(int32 iTeam, bool E)
{
	BlinkObjectiveOnRadar(iTeam,6);
	if (iTeam == 0)
	{
		_bSquadTarget=E;
	}
	else
	{
		if (iTeam == 1)
		{
			_bSquadTarget1=E;
		}
	}
}
bool AAGP_Objective::IsEnabled()
{
	return !bDisabled;
}
bool AAGP_Objective::IsInstantWin()
{
	return bInstantWin;
}
bool AAGP_Objective::IsSquadTarget(int32 iTeam)
{
	if (iTeam == 0)
	{
		return _bSquadTarget;
	}
	else
	{
		return _bSquadTarget1;
	}
}
bool AAGP_Objective::IsRequired()
{
	return bRequiredToWin && ! bInactive;
}
void AAGP_Objective::CheckAllowedPickupTeam(APawn* User)
{
}
void AAGP_Objective::DetermineCarriedCompassVisbility(APawn* ObjCarrier, bool bDropped)
{
}
void AAGP_Objective::CarryObjectiveUsed(APawn* User)
{
}
int32 AAGP_Objective::GetPickupTeamOwner()
{
	return 0;
}
bool AAGP_Objective::IsAlternating()
{
	return bTakeTurns;
}
float AAGP_Objective::GetPercentComplete()
{
	if (bDisabled)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void AAGP_Objective::GetAccomplishMessageByTeam(uint8 Accomplisher, uint8 listener)
{
	/*
		if (AnyTeamCanAttack())
		{
			if (Accomplisher == listener)
			{
				Return AccomplishMessage;
			}
			else
			{
				Return FailedDefenseMessage;
			}
		}
		if (listener == AttackTeam)
		{
			Return AccomplishMessage;
		}
		else
		{
			Return FailedDefenseMessage;
		}
	*/
}
void AAGP_Objective::GetDescriptionByTeam(uint8 listener)
{
	/*
		if (AnyTeamCanAttack())
		{
			Return AttackDescription;
		}
		if (! AGP_GameInfo(Level.Game).IsTeamGame())
		{
			Return AttackDescription;
		}
		if (listener == AttackTeam)
		{
			Return AttackDescription;
		}
		else
		{
			Return DefenseDescription;
		}
	*/
}
void AAGP_Objective::GetDescriptionByPawn(APawn* listener)
{
	/*
		if (listener == None)
		{
			Return AttackDescription;
		}
		if (AnyTeamCanAttack())
		{
			Return AttackDescription;
		}
		if (Role == 4)
		{
			if (! AGP_GameInfo(Level.Game).IsTeamGame())
			{
				Return AttackDescription;
			}
		}
		else
		{
			if (listener.PlayerReplicationInfo == None || listener.PlayerReplicationInfo.Team == None)
			{
				Return AttackDescription;
			}
		}
		if (listener.PlayerReplicationInfo.Team.TeamIndex == AttackTeam)
		{
			Return AttackDescription;
		}
		else
		{
			Return DefenseDescription;
		}
	*/
}
void AAGP_Objective::GetDescriptionByController(AController* listener)
{
	/*
		local int i;
		if (! IsEnabled())
		{
			Return "";
		}
		if (ObjectiveOnCompass == 6 && listener.Pawn != pawnMustBeUsedBy)
		{
			Return "";
		}
		if (listener == None)
		{
			Return AttackDescription;
		}
		if (AnyTeamCanAttack())
		{
			Return AttackDescription;
		}
		if (Role == 4)
		{
			if (! AGP_GameInfo(Level.Game).IsTeamGame())
			{
				Return AttackDescription;
			}
		}
		else
		{
			if (listener.PlayerReplicationInfo == None || listener.PlayerReplicationInfo.Team == None)
			{
				Return AttackDescription;
			}
		}
		if (listener.PlayerReplicationInfo.Team.TeamIndex == AttackTeam && ! listener.PlayerReplicationInfo.bGuerrillaPS)
		{
			if (MustBeClass == None)
			{
				Return AttackDescription;
			}
			if (listener.PlayerReplicationInfo.requiredClass == MustBeClass)
			{
				Return MBCAttackDescription;
			}
			for (i=0; i<32; i++)
			{
				if (listener.PlayerReplicationInfo.Team.TeamList[i] != None)
				{
					if (ClassIsChildOf(listener.PlayerReplicationInfo.Team.TeamList[i].requiredClass,MustBeClass) && ! listener.PlayerReplicationInfo.Team.TeamList[i].bDead)
					{
						Return AttackDescription;
					}
				}
			}
			Return altAttackDescription;
		}
		else
		{
			if (listener.PlayerReplicationInfo.Team.TeamIndex == AttackTeam && listener.PlayerReplicationInfo.bGuerrillaPS)
			{
				if (MustBeClass == None)
				{
					Return IFAttackDescription;
				}
				if (listener.PlayerReplicationInfo.requiredClass == MustBeClass)
				{
					Return MBCAttackDescription;
				}
				for (i=0; i<32; i++)
				{
					if (listener.PlayerReplicationInfo.Team.TeamList[i] != None)
					{
						if (ClassIsChildOf(listener.PlayerReplicationInfo.Team.TeamList[i].requiredClass,MustBeClass) && ! listener.PlayerReplicationInfo.Team.TeamList[i].bDead)
						{
							Return IFAttackDescription;
						}
					}
				}
				Return altAttackDescription;
			}
			else
			{
				if (listener.PlayerReplicationInfo.Team.TeamIndex != AttackTeam && ! listener.PlayerReplicationInfo.bGuerrillaPS)
				{
					if (MustBeClass == None)
					{
						Return DefenseDescription;
					}
					if (listener.PlayerReplicationInfo.requiredClass == MustBeClass)
					{
						Return MBCDefenseDescription;
					}
					for (i=0; i<32; i++)
					{
						if (listener.PlayerReplicationInfo.Team.TeamList[i] != None)
						{
							if (ClassIsChildOf(listener.PlayerReplicationInfo.Team.TeamList[i].requiredClass,MustBeClass) && ! listener.PlayerReplicationInfo.Team.TeamList[i].bDead)
							{
								Return DefenseDescription;
							}
						}
					}
					Return altDefenseDescription;
				}
				else
				{
					if (listener.PlayerReplicationInfo.Team.TeamIndex != AttackTeam && listener.PlayerReplicationInfo.bGuerrillaPS)
					{
						if (MustBeClass == None)
						{
							Return IFDefenseDescription;
						}
						if (listener.PlayerReplicationInfo.requiredClass == MustBeClass)
						{
							Return MBCDefenseDescription;
						}
						for (i=0; i<32; i++)
						{
							if (listener.PlayerReplicationInfo.Team.TeamList[i] != None)
							{
								if (ClassIsChildOf(listener.PlayerReplicationInfo.Team.TeamList[i].requiredClass,MustBeClass) && ! listener.PlayerReplicationInfo.Team.TeamList[i].bDead)
								{
									Return IFDefenseDescription;
								}
							}
						}
						Return altDefenseDescription;
					}
				}
			}
		}
	*/
}
void AAGP_Objective::IsHigherPriorityThan(ABaseObjective* otherb)
{
	/*
		local AGP_Objective Other;
		if (otherb == None || ! otherb.IsEnabled() || ! otherb.IsA('AGP_Objective'))
		{
			Return True;
		}
		Other=AGP_Objective(otherb);
		if (! IsEnabled())
		{
			Return False;
		}
		if (bInstantWin && ! Other.bInstantWin)
		{
			Return True;
		}
		if (! bInstantWin && Other.bInstantWin)
		{
			Return False;
		}
		Return AttackPriority >= Other.AttackPriority;
	*/
}
uint8 AAGP_Objective::GetHUDPosition()
{
	return HUDLetter;
}
bool AAGP_Objective::AnyTeamCanAttack()
{
	return AttackTeam == 255;
}
bool AAGP_Objective::CanTeamAttack(uint8 B)
{
	if(GetNetMode() == ENetMode::NM_Standalone)
	{
		return true;
	}
	return AnyTeamCanAttack() || B == AttackTeam;
}
bool AAGP_Objective::CanTeamInfoAttack(ATeamInfo* t)
{
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		return true;
	}
	if (t == NULL)
	{
		return false;
	}
	return false;
	//return AnyTeamCanAttack() || Cast<ATeamInfo>(t)->TeamIndex == AttackTeam;
}

bool AAGP_Objective::CanAccomplish(APawn* p)
{
	/*
		local int i;
		local Controller C;
		local bool TeammateCanAccomplish;
		if (p == None || p.Controller == None)
		{
			Return False;
		}
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			Return True;
		}
		if (bCheckRequiredChildObjectives)
		{
			for (i=0; i<ChildSequence.Length; i++)
			{
				if (ChildSequence[i].IsRequired() && ! ChildSequence[i].CanAccomplish(p))
				{
					TeammateCanAccomplish=False;
					C=Level.ControllerList;
					if (C != None)
					{
						if (! C.Pawn.IsHumanControlled())
						{
						}
						if (C.Pawn.GetTeam().TeamIndex != p.GetTeam().TeamIndex)
						{
						}
						if (ChildSequence[i].CanAccomplish(C.Pawn))
						{
							TeammateCanAccomplish=True;
						}
						else
						{
							C=C.nextController;
						}
					}
					if (! TeammateCanAccomplish)
					{
						Return False;
					}
				}
			}
		}
		if (p.Controller.IsA('HumanController') && HumanController(p.Controller).StartupStage == 6 || GetNetMode() == ENetMode::NM_Standalone)
		{
			if (p.PlayerReplicationInfo != None)
			{
				if (CanTeamInfoAttack(p.PlayerReplicationInfo.Team))
				{
					Return True;
				}
			}
		}
		Return False;
	*/
	return true;   //FAKE /ELiZ
}
bool AAGP_Objective::WasAccomplishedBy(uint8 some_team)
{
	return some_team == AccomplishedBy;
}

void AAGP_Objective::AccomplishObjective(APawn* _Instigator, AController* Killer)
{
	/*
		local TeamInfo Team;
		local string Msg;
		local int i;
		local PlayerController PC;
		local NPCAICombatController npcaiccIterator;
		local int iObjCommandIndex;
		if (Instigator != None && Instigator.PlayerReplicationInfo != None)
		{
			Team=Instigator.PlayerReplicationInfo.Team;
			if (Team != None)
			{
				AccomplishedBy=Team.TeamIndex;
			}
		}
		else
		{
			if (Killer != None && Killer.PlayerReplicationInfo != None)
			{
				Instigator=Killer.Pawn;
				Team=Killer.PlayerReplicationInfo.Team;
				if (Team != None)
				{
					AccomplishedBy=Team.TeamIndex;
				}
			}
			else
			{
				AccomplishedBy=255;
			}
		}
		NotifySequenceChildren();
		for (i=0; i<VisibilityChildren.Length; i++)
		{
			if (! VisibilityChildren[i].bInactive)
			{
				Switch(AccomplishedBy)
				{
					case 0:
					VisibilityChildren[i].ObjectiveOnCompass=2;
					break;
					case 1:
					VisibilityChildren[i].ObjectiveOnCompass=3;
					break;
					default:
					VisibilityChildren[i].ObjectiveOnCompass=0;
					break;
				}
			}
		}
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			Msg=GetAccomplishMessageByTeam(AccomplishedBy,0);
			if (Msg != "")
			{
				Level.Game.BroadcastHandler.BroadcastTeamByIndex(0,Msg,'Center');
			}
			Msg=GetAccomplishMessageByTeam(AccomplishedBy,1);
			if (Msg != "")
			{
				Level.Game.BroadcastHandler.BroadcastTeamByIndex(1,Msg,'Center');
			}
		}
		PlaySound(AccomplishSound,0,,,,,False);
		SetDisabled(True);
		TriggerEvent(Event,Self,Instigator);
		if (bChangeObjectiveOnCompassOnCompletion)
		{
			ObjectiveOnCompass=CompletedObjectiveOnCompass;
		}
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			if (IsAlternating())
			{
				if (AccomplishedBy == 0)
				{
					AttackTeam=1;
				}
				else
				{
					if (AccomplishedBy == 1)
					{
						AttackTeam=0;
					}
					else
					{
						AttackTeam=255;
					}
				}
				SideReset();
			}
			if (AGP_GameInfo(Level.Game) != None)
			{
				AGP_GameInfo(Level.Game).ScoreAGPObjective(Team,Self,False,Instigator.PlayerReplicationInfo);
				if (ctrlrESSReporter != None && ctrlrESSReporter != Instigator.Controller)
				{
					AGP_GameInfo(Level.Game).ScoreAGPObjective(ctrlrESSReporter.PlayerReplicationInfo.Team,Self,False,Instigator.PlayerReplicationInfo);
				}
			}
			if (IsAlternating())
			{
				SetDisabled(False);
			}
		}
		PC=PlayerController(Instigator.Controller);
		if (Level.Game.Stats != None && PC != None && PC.PlayerStatsIndex >= 0)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_CapturedObjective();
		}
		if (_Target != None)
		{
			_Target.Notify();
		}
		ForEach AllActors('NPCAICombatController',npcaiccIterator)
		{
			if (! npcaiccIterator.bDisableCombatController)
			{
				for (iObjCommandIndex=0; iObjCommandIndex<anpcoaNPCResponse.Length; iObjCommandIndex++)
				{
					Switch(anpcoaNPCResponse[iObjCommandIndex].enpcrocNPCCommand)
					{
						case 0:
						npcaiccIterator.SpawnTriggeredReinforcements(anpcoaNPCResponse[iObjCommandIndex].iReservePlatoonID,anpcoaNPCResponse[iObjCommandIndex].iReserveSquadID,anpcoaNPCResponse[iObjCommandIndex].iReserveFireteamID,"FollowOrders",Location);
						break;
						case 1:
						npcaiccIterator.SpawnTriggeredReinforcements(anpcoaNPCResponse[iObjCommandIndex].iReservePlatoonID,anpcoaNPCResponse[iObjCommandIndex].iReserveSquadID,anpcoaNPCResponse[iObjCommandIndex].iReserveFireteamID,"GotoObjective",Location);
						break;
						default:
					}
				}
				npcaiccIterator.NotifyObjectiveAccomplished(Self);
			}
			else
			{
			}
		}
		if (bPlayerRadioedObectiveInfo)
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ESSPostRadioLinkedObjectTaken();
		}
		else
		{
			if (sndESSObjectiveCompletionAcknowledgement != None)
			{
				Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ESSNoRadioLinkedObjectTaken();
			}
		}
		PlayESSCompletionMessage(PC);
	*/
}

void AAGP_Objective::PlayESSCompletionMessage(APlayerController* PC)
{
	/*
		local Controller ctrlIterator;
		if (sndESSObjectiveCompletionAcknowledgement == None)
		{
			Return;
		}
		if (bESSObjectiveCompleteSoundPlayerOnly)
		{
			HumanController(PC).ClientESSRadioSuccessMessage(sndESSObjectiveCompletionAcknowledgement);
		}
		else
		{
			ctrlIterator=Level.ControllerList;
			if (ctrlIterator != None)
			{
				if (HumanController(ctrlIterator) != None && HumanController(ctrlIterator).PlayerReplicationInfo != None && PlayerController(ctrlIterator).PlayerReplicationInfo.Team != None && HumanController(ctrlIterator).PlayerReplicationInfo.Team.TeamIndex == PC.PlayerReplicationInfo.Team.TeamIndex)
				{
					HumanController(ctrlIterator).ClientESSRadioSuccessMessage(sndESSObjectiveCompletionAcknowledgement);
				}
				ctrlIterator=ctrlIterator.nextController;
			}
		}
	*/
}
void AAGP_Objective::SendPercentage(APawn* whocares)
{
	/*
		local int iPercent;
		local PlayerController PC;
		if (whocares == None || whocares.Controller == None)
		{
			Return;
		}
		PC=PlayerController(whocares.Controller);
		if (PC == None)
		{
			Return;
		}
		iPercent=GetPercentComplete() * 100;
		if (iLastPercent != iPercent)
		{
			Level.Game.BroadcastHandler.BroadcastLocalized(Self,PC,'ObjLocalMessage',iPercent);
			if (iPercent > ProgressSoundStart)
			{
				if (iLastProgressPercent < ProgressSoundStart || iPercent > iLastProgressPercent + ProgressSoundInterval)
				{
					PlaySound(ProgressSound,0,0.5);
					iLastProgressPercent=iPercent;
				}
			}
			iLastPercent=iPercent;
		}
	*/
}
void AAGP_Objective::SideReset()
{
	/*
		SetTeamMesh();
	*/
}
void AAGP_Objective::Reset()
{
	/*
		Reset();
		InitializeNPCObjective();
		SetInactive(False);
		AttackTeam=_OriginalAttackTeam;
		ObjectiveOnCompass=_OriginalObjectiveOnCompass;
		_bSquadTarget=False;
		iLastPercent=0;
		iLastProgressPercent=0;
		SetTeamMesh();
		if (ParentSequence.Length == 0)
		{
			SetDisabled(False);
		}
		else
		{
			SetDisabled(True);
		}
		ResetLocationProxy();
		AccomplishedBy=255;
	*/
}
void AAGP_Objective::grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController)
{
}
void AAGP_Objective::getReportDistance()
{
}
void AAGP_Objective::getObserveDistance()
{
}
void AAGP_Objective::getDangerDistance()
{
}
void AAGP_Objective::isDangerous()
{
}
void AAGP_Objective::isReportable()
{
}
void AAGP_Objective::MakeES2ObjectiveReportable()
{
}
void AAGP_Objective::getAcknowledgeVO()
{
}
void AAGP_Objective::getAcknowledgeText()
{
}
void AAGP_Objective::getFlagTag()
{
}
void AAGP_Objective::getFlagReference()
{
}
void AAGP_Objective::isUseable()
{
}
void AAGP_Objective::getDialogLength()
{
}
void AAGP_Objective::getLinkedArray()
{
}
/*
void AAGP_Objective::ActivateFromRadio(AHumanController* Instigator)
{
}
*/
void AAGP_Objective::isOnRadar()
{
}
void AAGP_Objective::MakeESSObjectAppearOnRadar()
{
}
void AAGP_Objective::getReportEventName()
{
}
void AAGP_Objective::isDummyTrainingObject()
{
}
void AAGP_Objective::getBecomeActiveEvent()
{
}
void AAGP_Objective::isUseOnReport()
{
}
