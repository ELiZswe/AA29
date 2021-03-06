// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AA2_Controller.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Triggers/AvoidMarker/AvoidMarker.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/ReachSpec/ReachSpec.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "Engine/Canvas.h"

AAA2_Controller::AAA2_Controller()
{
	GoalList.SetNum(5);
	RouteCache.SetNum(63);
	FearSpots.SetNum(3);

	FovAngle = 85; 
	Handedness = 1;
	bAdvancedTactics = true;
	bAdrenalineEnabled = true;
	bSlowerZAcquire = true;
	CurrentTeam = 1;
	MinHitWall = -1;
	AcquisitionYawRate = 20000;
	//PlayerReplicationInfoClass = APlayerReplicationInfo::StaticClass();
	AdrenalineMax = 100;
	//bHidden = true;
	bOnlyRelevantToOwner = true;
	//RemoteRole = ROLE_None;
	//RotationRate = FRotator(3072, 30000, 2048);
	//bHiddenEd = true;
}

/*
replication
{
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		Pawn, PlayerReplicationInfo;
	reliable if (((bNetDirty && (Role == ROLE_Authority)) && bNetOwner))
		bAdrenalineEnabled, PawnClass, Adrenaline;
	reliable if ((RemoteRole == ROLE_AutonomousProxy))
		ClientSetWeapon, ClientSwitchToBestWeapon, ClientRoundEnded, ClientGameEnded, ClientDying, ClientSetRotation, ClientSetLocation;
	reliable if ((((!bDemoRecording) || (bClientDemoRecording && bClientDemoNetFunc)) && (Role == ROLE_Authority)))
		ClientVoiceMessage;
	reliable if ((Role < ROLE_Authority))
		SetPawnClass, SendVoiceMessage;
	reliable if ((Role < ROLE_Authority))
		ServerReStartPlayer;
}
*/

void AAA2_Controller::LIPSincAnimEnd()
{
	//Pawn.LIPSincAnimEnd();
}

void AAA2_Controller::DestinationOccupied()
{
	//Pawn.bAbortMoveIfGoalOccupied = true;
}

void AAA2_Controller::ClientSetPMessage(int32 messID)
{
}

void AAA2_Controller::NotifyComplete()
{
}

void AAA2_Controller::CleanUp()
{
}

bool AAA2_Controller::ShouldRenderWeapon()
{
	/*
	if (((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && (!Pawn.bIsDead))
	{
		return Pawn.Weapon.ShouldRenderWeapon();
	}
	*/
	return false;
}

bool AAA2_Controller::HandlePickupQuery(APickup* pick)
{
	//ScreenPrint("Problem!  Controller::HandlePickupQuery not overridden.");
	return false;
}

void AAA2_Controller::UpdateRotation(float DeltaTime, float maxPitch)
{
}

//native(500) final Latent Function MoveTo(Vector NewDestination, Actor ViewFocus, bool bShouldWalk);
void AAA2_Controller::MoveTo(FVector NewDestination, AActor* ViewFocus, bool bShouldWalk)
{

}

//native(502) final Latent Function MoveToward(AActor* NewTarget, Actor ViewFocus, float DestinationOffset, bool bUseStrafing, bool bShouldWalk);
void AAA2_Controller::MoveToward(AActor* NewTarget, AActor* ViewFocus, float DestinationOffset, bool bUseStrafing, bool bShouldWalk)
{

}

//native(508) final Latent Function FinishRotation();
void AAA2_Controller::FinishRotation()
{

}

//native(514) final Function bool LineOfSightTo(AActor* Other);
/*
bool AAA2_Controller::LineOfSightTo(AActor* Other)
{
	return false;     //FAKE   /EliZ
}
*/

//native(533) final Function bool CanSee(Pawn Other);
bool AAA2_Controller::CanSee(APawn* Other)
{
	return false;     //FAKE   /EliZ
}

//native(518) final Function Actor FindPathTo(Vector aPoint);
AActor* AAA2_Controller::FindPathTo(FVector aPoint)
{
	return nullptr;     //FAKE   /EliZ
}

//native(517) final Function Actor FindPathToward(AActor* anActor, bool bWeightDetours);
AActor* AAA2_Controller::FindPathToward(AActor* anActor, bool bWeightDetours)
{
	return nullptr;     //FAKE   /EliZ
}

//native final Function Actor FindPathToIntercept(Pawn p, Actor RouteGoal, bool bWeightDetours);
AActor* AAA2_Controller::FindPathToIntercept(APawn* p, AActor* aRouteGoal, bool bWeightDetours)
{
	return nullptr;     //FAKE   /EliZ
}

//native final Function Actor FindPathTowardNearest(class<NavigationPoint>  GoalClass, bool bWeightDetours);
AActor* AAA2_Controller::FindPathTowardNearest(ANavigationPoint*  GoalClass, bool bWeightDetours)
{
	return nullptr;     //FAKE   /EliZ
}

//native(525) final Function NavigationPoint FindRandomDest();
ANavigationPoint* AAA2_Controller::FindRandomDest()
{
	return nullptr;     //FAKE   /EliZ
}

//native(523) final Function Vector EAdjustJump(float BaseZ, float XYSpeed);
FVector AAA2_Controller::EAdjustJump(float BaseZ, float XYSpeed)
{
	return FVector(0,0,0);     //FAKE   /EliZ
}

//native(521) final Function bool pointReachable(Vector aPoint);
bool AAA2_Controller::pointReachable(FVector aPoint)
{
	return false;     //FAKE   /EliZ
}

//native(520) final Function bool actorReachable(AActor* anActor);
bool AAA2_Controller::actorReachable(AActor* anActor)
{
	return false;     //FAKE   /EliZ
}

//native(526) final Function bool PickWallAdjust(Vector HitNormal);
bool AAA2_Controller::PickWallAdjust(FVector HitNormal)
{
	return false;     //FAKE   /EliZ
}

//native(527) final Latent Function WaitForLanding();
void AAA2_Controller::WaitForLanding()
{

}

//native(540) final Function Actor FindBestInventoryPath(float& MinWeight);
AActor* AAA2_Controller::FindBestInventoryPath(float& MinWeight)
{
	return nullptr;     //FAKE   /EliZ
}

//native final Function Actor FindBestSuperPickup(float MaxDist);
AActor* AAA2_Controller::FindBestSuperPickup(float MaxDist)
{
	return nullptr;     //FAKE   /EliZ
}

//native(529) final Function AddController();
void AAA2_Controller::AddController()
{

}

//native(530) final Function RemoveController();
void AAA2_Controller::RemoveController()
{

}

//native(531) final Function Pawn PickTarget(float& bestAim, float& bestDist, Vector FireDir, Vector projStart, float MaxRange);
APawn* AAA2_Controller::PickTarget(float& bestAim, float& bestDist, FVector FireDir, FVector projStart, float MaxRange)
{
	return nullptr;     //FAKE   /EliZ
}

//native(534) final Function Actor PickAnyTarget(float& bestAim, float& bestDist, Vector FireDir, Vector projStart);
AActor* AAA2_Controller::PickAnyTarget(float& bestAim, float& bestDist, FVector FireDir, FVector projStart)
{
	return nullptr;     //FAKE   /EliZ
}
//native final Function bool InLatentExecution(int32 LatentActionNumber);
bool AAA2_Controller::InLatentExecution(int32 LatentActionNumber)
{
	return false;     //FAKE   /EliZ
}

//native Function StopWaiting();
void AAA2_Controller::StopWaiting()
{

}

//native Function EndClimbLadder();
void AAA2_Controller::EndClimbLadder()
{

}

//native final Function bool CanMakePathTo(AActor* A);
bool AAA2_Controller::CanMakePathTo(AActor* A)
{
	return false;     //FAKE   /EliZ
}

//native final Function bool PbCanPlayerJoin();
bool AAA2_Controller::PbCanPlayerJoin()
{
	return false;     //FAKE   /EliZ
}

void AAA2_Controller::WeaponCollision(AActor* actorColliding)
{
}

void AAA2_Controller::MayFall()
{
}

void AAA2_Controller::MayDodgeToMoveTarget()
{
}

void AAA2_Controller::MissedDodge()
{
}

void AAA2_Controller::PendingStasis()
{
	//bStasis = true;
	//Pawn = nullptr;
}

void AAA2_Controller::AwardAdrenaline(float Amount)
{
	/*
	if (bAdrenalineEnabled)
	{
		(Adrenaline += Amount);
		Adrenaline = float(Clamp(int(Adrenaline), 0, int(AdrenalineMax)));
	}
	*/
}

bool AAA2_Controller::NeedsAdrenaline()
{
	//return (((Pawn != nullptr) && (!Pawn.InCurrentCombo())) && (Adrenaline < AdrenalineMax));
	return false;    //FAKE   /ELiZ
}

void AAA2_Controller::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
{
	/*
	FString DebugString = "";
	if (Pawn == nullptr)
	{
		Super::DisplayDebug(Canvas, YL, YPos);
		return;
	}
	Canvas.SetDrawColor(255, 0, 0);
	Canvas.DrawText("CONTROLLER " + GetItemName(string(this)) + " Pawn " + GetItemName(string(Pawn)) + " viewpitch " + FString::FromInt(Rotation.Pitch));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	if (Enemy != nullptr)
	{
		Canvas.DrawText("     STATE: " + FString::FromInt(
		()) + " LABEL: " + FString::FromInt(GetLastLabelName()) + " LAST STATE: " + FString::FromInt(GetLastStateName()) + " Timer: " + FString::FromInt(TimerCounter) + " Enemy " + Enemy.GetHumanReadableName(), false);
	}
	else
	{
		Canvas.DrawText("     STATE: " + FString::FromInt(GetStateName()) + " LABEL: " + FString::FromInt(GetLastLabelName()) + " LAST STATE: " + FString::FromInt(GetLastStateName()) + " Timer: " + FString::FromInt(TimerCounter) + " NO Enemy ", false);
	}
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Rot.Pitch:" + FString::FromInt(Rotation.Pitch) + " Yaw:" + FString::FromInt(Rotation.Yaw) + " Roll:" + FString::FromInt(Rotation.Roll) + " FOV:" + FString::FromInt(FovAngle));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	if (MonitoredPawn != nullptr)
	{
		(DebugString += "     MonitoredPawn: " @ MonitoredPawn.GetHumanReadableName());
	}
	else
	{
		(DebugString += "     MonitoredPawn: None");
	}
	if (Target != nullptr)
	{
		(DebugString += "     Target: " @ Target.GetHumanReadableName());
	}
	else
	{
		(DebugString += "     Target: None");
	}
	Canvas.DrawText(DebugString);
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	if (PlayerReplicationInfo == nullptr)
	{
		Canvas.DrawText("     NO PLAYERREPLICATIONINFO", false);
	}
	else
	{
		PlayerReplicationInfo.DisplayDebug(Canvas, YL, YPos);
	}
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Advanced: " + FString::FromInt(bAdvancedTactics));
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	*/
}

/*

FString AAA2_Controller::GetHumanReadableName()
{
	if (PlayerReplicationInfo != nullptr)
	{
		return PlayerReplicationInfo.PlayerName;
	}
	return GetItemName(string(this));
	return "FAKE";    //FAKE   /ELiZ
}
	*/

FRotator AAA2_Controller::GetViewRotation()
{
	//return Rotation;
	return FRotator(0,0,0);
}

void AAA2_Controller::Reset()
{
	Super::Reset();
	Enemy = nullptr;
	LastSeenTime = 0;
	StartSpot = nullptr;
	Adrenaline = 0;
	bAdjusting = false;
	bPreparingMove = false;
	bJumpOverWall = false;
	bEnemyAcquired = false;
	bHuntPlayer = false;
	bInDodgeMove = false;
	MoveTimer = -1;
	MoveTarget = nullptr;
	PendingMover = nullptr;
	CurrentPath = nullptr;
	RouteGoal = nullptr;
	MonitoredPawn = nullptr;
	WarningProjectile = nullptr;
}

bool AAA2_Controller::AvoidCertainDeath()
{
	return false;
}

void AAA2_Controller::ClientSetLocation(FVector NewLocation, FRotator NewRotation)
{
	/*
	SetActorRotation(NewRotation);
	if ((Rotation.Pitch > RotationRate.Pitch) && (Rotation.Pitch < (65536 - RotationRate.Pitch)))
	{
		if (Rotation.Pitch < 32768)
		{
			NewRotation.Pitch = RotationRate.Pitch;
		}
		else
		{
			NewRotation.Pitch = (65536 - RotationRate.Pitch);
		}
	}
	if (Pawn != nullptr)
	{
		NewRotation.Roll = 0;
		Pawn.SetRotation(NewRotation);
		Pawn.SetLocation(NewLocation);
	}
	*/
}

void AAA2_Controller::ClientSetRotation(FRotator NewRotation)
{
	/*
	SetActorRotation(NewRotation);
	if (Pawn != nullptr)
	{
		NewRotation.Pitch = 0;
		NewRotation.Roll = 0;
		Pawn.SetRotation(NewRotation);
	}
	*/
}

void AAA2_Controller::ClientDying(UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone)
{
	/*
	if (Pawn != nullptr)
	{
		Pawn.PlayDying(DamageType, HitLocation, HitDir, Bone);
		Pawn.GotoState('Dying');
	}
	*/
}

void AAA2_Controller::AIHearSound(AActor* Actor, int32 Id, USoundBase* S, FVector SoundLocation, FVector Parameters, bool Attenuate)
{
}

void AAA2_Controller::SoakStop(FString problem)
{
}
/*

void AAA2_Controller::Possess(APawn* aPawn)
{
	aPawn.PossessedBy(this);
	Pawn = aPawn;
	if (PlayerReplicationInfo != nullptr)
	{
		if ((Cast<AVehicle>(Pawn) != nullptr) && (Cast<AVehicle>(Pawn).Driver != nullptr))
		{
			PlayerReplicationInfo.bIsFemale = Vehicle(Pawn).Driver.bIsFemale;
		}
		else
		{
			PlayerReplicationInfo.bIsFemale = Pawn.bIsFemale;
		}
	}
	FocalPoint = (Pawn.Location + (float(512) * Vector(Pawn.Rotation)));
	Restart();
}
	*/

	/*

void AAA2_Controller::UnPossess()
{
	if (Pawn != nullptr)
	{
		Pawn.UnPossessed();
	}
	Pawn = nullptr;
}
	*/

void AAA2_Controller::WasKilledBy(AController* Other)
{
}

AWeapon* AAA2_Controller::GetLastWeapon()
{
	/*
	if ((Pawn == nullptr) || (Pawn.Weapon == nullptr))
	{
		return LastPawnWeapon;
	}
	return Pawn.Weapon.Class;
	*/
	return nullptr;    //FAKE   /ELiZ
}

void AAA2_Controller::PawnDied(APawn* p)
{
	/*
	if (Pawn != p)
	{
		return;
	}
	if (Pawn != nullptr)
	{
		if (Pawn.InCurrentCombo())
		{
			Adrenaline = 0;
		}
		SetActorLocation(Pawn.Location);
		Pawn.UnPossessed();
	}
	Pawn = nullptr;
	PendingMover = nullptr;
	if (bIsPlayer)
	{
		if ((!IsInState('GameEnded')) && (!IsInState('RoundEnded')))
		{
			GotoState('Dead');
		}
	}
	else
	{
		Destroy();
	}
	*/
}

void AAA2_Controller::Restart()
{
	Enemy = nullptr;
}

void AAA2_Controller::LongFall()
{
}

bool AAA2_Controller::NotifyPhysicsVolumeChange(APhysicsVolume* NewVolume)
{
	return false;    //FAKE   /ELiZ
}

bool AAA2_Controller::NotifyHeadVolumeChange(APhysicsVolume* NewVolume)
{
	return false;    //FAKE   /ELiZ
}

bool AAA2_Controller::NotifyLanded(FVector HitNormal)
{
	return false;    //FAKE   /ELiZ
}

void AAA2_Controller::NotifyPostLanded()
{
}

bool AAA2_Controller::NotifyHitWall(FVector HitNormal, AActor* Wall)
{
	return false;    //FAKE   /ELiZ
}

void AAA2_Controller::NotifyFallingHitWall(FVector HitNormal, AActor* Wall)
{
}

bool AAA2_Controller::NotifyBump(AActor* Other)
{
	return false;    //FAKE   /ELiZ
}

void AAA2_Controller::NotifyHitMover(FVector HitNormal, AMover* Wall)
{
}

void AAA2_Controller::NotifyJumpApex()
{
}

void AAA2_Controller::NotifyMissedJump()
{
}

void AAA2_Controller::SetDoubleJump()
{
}

void AAA2_Controller::NotifyAddInventory(AInventory* NewItem)
{
}

void AAA2_Controller::NotifyTakeHit(APawn* instigatedBy, FVector HitLocation, int32 Damage, UaDamageType* DamageType, FVector Momentum)
{
	/*
	if ((instigatedBy != nullptr) && (instigatedBy != Pawn))
	{
		damageAttitudeTo(instigatedBy, float(Damage));
	}
	*/
}

void AAA2_Controller::SetFall()
{
}

void AAA2_Controller::PawnIsInPain(APhysicsVolume* PainVolume)
{
}

void AAA2_Controller::PreBeginPlay()
{
	/*
	AddController();
	Super::PreBeginPlay();
	if (bDeleteMe)
	{
		return;
	}
	SightCounter = (0.2 * FMath::FRand());
	*/
}

void AAA2_Controller::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	if (((!bDeleteMe) && bIsPlayer) && (GetNetMode() != ENetMode::NM_Client))
	{
		PlayerReplicationInfo = Spawn(PlayerReplicationInfoClass, this, , FVector(0, 0, 0), FRotator(0, 0, 0));
		InitPlayerReplicationInfo();
	}
	*/
}

void AAA2_Controller::InitPlayerReplicationInfo()
{
	/*
	if (PlayerReplicationInfo.PlayerName == "")
	{
		PlayerReplicationInfo.SetPlayerName(AGameInfo::StaticClass().Default.DefaultPlayerName);
	}
	PlayerReplicationInfo.bNoTeam = (!Level.Game.bTeamGame);
	*/
}

int32 AAA2_Controller::GetTeamNum()
{
	if ((PlayerReplicationInfo == nullptr) || (PlayerReplicationInfo->Team == nullptr))
	{
		return 255;
	}
	return PlayerReplicationInfo->Team->TeamIndex;
}

bool AAA2_Controller::SameTeamAs(AController* C)
{
	/*
	return (CurrentTeam == C.CurrentTeam);
	*/
	return false;    //FAKE   /ELiZ
}

void AAA2_Controller::HandlePickup(APickup* pick)
{
	/*
	if (MoveTarget == pick)
	{
		if (pick.myMarker != nullptr)
		{
			MoveTarget = pick.myMarker;
			Pawn.Anchor = pick.myMarker;
			MoveTimer = 0.5;
		}
		else
		{
			MoveTimer = -1;
		}
	}
	*/
}

void AAA2_Controller::Destroyed()
{
	/*
	if (Role < 4)
	{
		Super::Destroyed();
		return;
	}
	RemoveController();
	if (bIsPlayer && (Level.Game != nullptr))
	{
		Level.Game.Logout(this);
	}
	if (PlayerReplicationInfo != nullptr)
	{
		if ((!PlayerReplicationInfo.bOnlySpectator) && (PlayerReplicationInfo.Team != nullptr))
		{
			PlayerReplicationInfo.Team.RemoveFromTeam(this);
		}
		PlayerReplicationInfo.Destroy();
		PlayerReplicationInfo = nullptr;
	}
	Super::Destroyed();
	*/
}

bool AAA2_Controller::AllowDetourTo(ANavigationPoint* N)
{
	return true;
}

void AAA2_Controller::AdjustView(float DeltaTime)
{
	/*
	AController* C = nullptr;
	C = Level.ControllerList;
	if (C != nullptr)
	{
		if (C->IsA(APlayerController::StaticClass()) && (Cast<APlayerController>(C).ViewTarget == Pawn))
		{
			return;
		}
		C = C.nextController;
	}
	Pawn.bUpdateEyeheight = false;
	Pawn.EyeHeight = Pawn.BaseEyeHeight;
	*/
}

bool AAA2_Controller::WantsSmoothedView()
{
	//return (((Pawn != nullptr) && ((Pawn.Physics == 1) || (Pawn.Physics == 9))) && (!Pawn.bJustLanded));
	return false;    //FAKE   /ELiZ
}
/*
void AAA2_Controller::GameHasEnded()
{
	if (Pawn != nullptr)
	{
		Pawn.bNoWeaponFiring = true;
	}
	GotoState('GameEnded');
}
*/
void AAA2_Controller::ClientGameEnded()
{
	//GotoState('GameEnded');
}

void AAA2_Controller::RoundHasEnded()
{
	/*
	if (Pawn != nullptr)
	{
		Pawn.bNoWeaponFiring = true;
	}
	GotoState('RoundEnded');
	*/
}

void AAA2_Controller::ClientRoundEnded()
{
	//GotoState('RoundEnded');
}

void AAA2_Controller::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
	if (((Pawn != nullptr) && (Pawn.Weapon != nullptr)) && ShouldRenderWeapon())
	{
		Pawn.Weapon.RenderOverlays(Canvas, bWeaponAndAttachmentsOnly);
	}
	*/
}

int32 AAA2_Controller::GetFacingDirection()
{
	return 0;
}

uint8 AAA2_Controller::GetMessageIndex(FName PhraseName)
{
	return 0;
}

void AAA2_Controller::SendMessage(AAA2_PlayerState* Recipient, FName messagetype, uint8 MessageID, float Wait, FName BroadcastType)
{
	//SendVoiceMessage(PlayerReplicationInfo, Recipient, messagetype, MessageID, BroadcastType);
}

bool AAA2_Controller::AllowVoiceMessage(FName messagetype)
{
	/*
	if ((GetWorld()->GetTimeSeconds() - OldMessageTime) < float(10))
	{
		return false;
	}
	else
	{
		OldMessageTime = GetWorld()->GetTimeSeconds();
	}
	*/
	return true;
}

void AAA2_Controller::SendVoiceMessage(AAA2_PlayerState* Sender, AAA2_PlayerState* Recipient, FName messagetype, uint8 MessageID, FName BroadcastType)
{
	AController* p = nullptr;
	/*
	if (((Recipient == nullptr) || (Cast<AAIController>(this) == nullptr)) && (!AllowVoiceMessage(messagetype)))
	{
		return;
	}
	p = Level.ControllerList;
	if (p != nullptr)
	{
		if (Cast<APlayerController>(p) != nullptr)
		{
			if ((p.PlayerReplicationInfo == Sender) || ((p.PlayerReplicationInfo == Recipient) && ((Level.Game.BroadcastHandler == nullptr) || Level.Game.BroadcastHandler.AcceptBroadcastSpeech(Cast<APlayerController>(p), Sender))))
			{
				p.ClientVoiceMessage(Sender, Recipient, messagetype, MessageID);
			}
			else
			{
				if ((Recipient == nullptr) || (GetWorld()->GetNetMode() == NM_Standalone))
				{
					if (((BroadcastType == 'Global') || (!Level.Game.bTeamGame)) || (Sender.Team == p.PlayerReplicationInfo.Team))
					{
						if ((Level.Game.BroadcastHandler == nullptr) || Level.Game.BroadcastHandler.AcceptBroadcastSpeech(Cast<APlayerController>(p), Sender))
						{
							p.ClientVoiceMessage(Sender, Recipient, messagetype, MessageID);
						}
					}
				}
			}
		}
		else
		{
			if ((messagetype == 'Order') && ((Recipient == nullptr) || (Recipient == p.PlayerReplicationInfo)))
			{
				p.BotVoiceMessage(messagetype, MessageID, this);
			}
		}
		p = p.nextController;
	}
	*/
}

void AAA2_Controller::ClientVoiceMessage(AAA2_PlayerState* Sender, AAA2_PlayerState* Recipient, FName messagetype, uint8 MessageID)
{
}

void AAA2_Controller::BotVoiceMessage(FName messagetype, uint8 MessageID, AController* Sender)
{
}

bool AAA2_Controller::WouldReactToNoise(float Loudness, AActor* NoiseMaker)
{
	return false;
}

bool AAA2_Controller::WouldReactToSeeing(APawn* Seen)
{
	return false;
}

FVector AAA2_Controller::AdjustToss(float TSpeed, FVector Start, FVector End, bool bNormalize)
{
	FVector Dest2D = FVector(0, 0, 0);
	FVector Result = FVector(0, 0, 0);
	FVector Vel2D = FVector(0, 0, 0);
	float Dist2D = 0;
	/*
	if (Start.Z > (End.Z + float(64)))
	{
		Dest2D = End;
		Dest2D.Z = Start.Z;
		Dist2D = VSize((Dest2D - Start));
		(TSpeed *= (Dist2D / VSize((End - Start))));
		Result = SuggestFallVelocity(Dest2D, Start, TSpeed, TSpeed);
		Vel2D = Result;
		Vel2D.Z = 0;
		Result.Z = (Result.Z + (((End.Z - Start.Z) * VSize(Vel2D)) / Dist2D));
	}
	else
	{
		Result = SuggestFallVelocity(End, Start, TSpeed, TSpeed);
	}
	if (bNormalize)
	{
		return (TSpeed * Normal(Result));
	}
	else
	{
		return Result;
	}
	*/
	return FVector(0, 0, 0);     //FAKE   /EliZ
}

void AAA2_Controller::PrepareForMove(ANavigationPoint* Goal, UReachSpec* Path)
{
}

void AAA2_Controller::WaitForMover(AMover* M)
{
}

void AAA2_Controller::MoverFinished()
{
}

void AAA2_Controller::UnderLift(AMover* M)
{
}

void AAA2_Controller::StopMoving()
{
	/*
	Pawn.Velocity.X = 0;
	Pawn.Velocity.Y = 0;
	Pawn.Acceleration.X = 0;
	Pawn.Acceleration.Y = 0;
	MoveTimer = -1;
	*/
}

void AAA2_Controller::FearThisSpot(AAvoidMarker* aSpot)
{
	/*
	int32 i = 0;
	if (Pawn == nullptr)
	{
		return;
	}
	if (!LineOfSightTo(aSpot))
	{
		return;
	}
	for (i = 0; i < 2; i++)
	{
		if (FearSpots[i] == nullptr)
		{
			FearSpots[i] = aSpot;
			return;
		}
	}
	for (i = 0; i < 2; i++)
	{
		if (VSize((Pawn.Location - FearSpots[i].Location)) > VSize((Pawn.Location - aSpot.Location)))
		{
			FearSpots[i] = aSpot;
			return;
		}
	}
	*/
}

float AAA2_Controller::Desireability(APickup* p)
{
	//return p.BotDesireability(Pawn);
	return false;     //FAKE   /EliZ
}

float AAA2_Controller::SuperDesireability(APickup* p)
{
	//return p.BotDesireability(Pawn);
	return 0;     //FAKE   /EliZ
}

void AAA2_Controller::SetupSpecialPathAbilities()
{
}

void AAA2_Controller::HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation)
{
}

void AAA2_Controller::HearBulletImpactNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation)
{
}

void AAA2_Controller::SeePlayer(APawn* Seen)
{
}

void AAA2_Controller::SeeMonster(APawn* Seen)
{
}

void AAA2_Controller::EnemyNotVisible()
{
}

void AAA2_Controller::DamageShake(int32 Damage)
{
}

void AAA2_Controller::ShakeView(FVector shRotMag, FVector shRotRate, float shRotTime, FVector shOffsetMag, FVector shOffsetRate, float shOffsetTime)
{
}

void AAA2_Controller::NotifyKilled(AController* Killer, AController* Killed, APawn* Other)
{
	if (Enemy == Other)
	{
		Enemy = nullptr;
	}
}

void AAA2_Controller::damageAttitudeTo(APawn* Other, float Damage)
{
}

float AAA2_Controller::AdjustDesireFor(APickup* p)
{
	return 0;     //FAKE   /EliZ
}

bool AAA2_Controller::FireWeaponAt(AActor* A)
{
	return false;     //FAKE   /EliZ
}

void AAA2_Controller::StopFiring()
{
	/*
	if (Pawn != nullptr)
	{
		Pawn.StopWeaponFiring();
	}
	bFire = 0;
	bAltFire = 0;
	*/
}

float AAA2_Controller::RateWeapon(AWeapon* W)
{
	//return W.SwitchPriority();
	return 0;     //FAKE   /EliZ
}

float AAA2_Controller::WeaponPreference(AWeapon* W)
{
	return 0;
}

FRotator AAA2_Controller::AdjustAim(AAmmunition* FiredAmmunition, FVector projStart, int32 aimerror)
{
	//return Rotation;
	return FRotator(0, 0, 0);
}

void AAA2_Controller::InstantWarnTarget(AActor* aTarget, FFireProperties FiredAmmunition, FVector FireDir)
{
	/*
	float dist = 0;
	if ((FiredAmmunition.bInstantHit && (Cast<APawn>(aTarget) != nullptr)) && (Cast<APawn>(aTarget).Controller != nullptr))
	{
		dist = VSize((Pawn.Location - aTarget.Location));
		if (VSize(((FireDir * dist) - aTarget.Location)) < aTarget.CollisionRadius)
		{
			return;
		}
		if (FMath::FRand() < FiredAmmunition.WarnTargetPct)
		{
			Cast<APawn>(aTarget).Controller.ReceiveWarning(Pawn, -1, FireDir);
		}
		return;
	}
	*/
}

void AAA2_Controller::ReceiveWarning(APawn* shooter, float projSpeed, FVector FireDir)
{
}

void AAA2_Controller::WarnAboutToRunOverTeammate(AController* ctrlTeammate)
{
}

void AAA2_Controller::ReceiveProjectileWarning(AProjectile* Proj)
{
	/*
	if (WarningProjectile == nullptr)
	{
		ReceiveWarning(Proj.Instigator, Proj.Speed, Normal(Proj.Velocity));
	}
	*/
}

void AAA2_Controller::DelayedWarning()
{
}

void AAA2_Controller::SwitchToBestWeapon()
{
	/*
	float rating = 0;
	if ((Pawn == nullptr) || (Pawn.Inventory == nullptr))
	{
		return;
	}
	if ((Pawn.PendingWeapon == nullptr) || (Cast<AAIController>(this) != nullptr))
	{
		Pawn.PendingWeapon = Pawn.Inventory.RecommendWeapon(rating);
		if (Pawn.PendingWeapon == Pawn.Weapon)
		{
			Pawn.PendingWeapon = nullptr;
		}
		if (Pawn.PendingWeapon == nullptr)
		{
			return;
		}
	}
	StopFiring();
	if (Pawn.Weapon == nullptr)
	{
		Pawn.ChangedWeapon();
	}
	else
	{
		if (Pawn.Weapon != Pawn.PendingWeapon)
		{
			Pawn.Weapon.PutDown();
		}
	}
	*/
}

void AAA2_Controller::ClientSwitchToBestWeapon()
{
	//SwitchToBestWeapon();
}

void AAA2_Controller::ClientSetWeapon(AWeapon* WeaponClass)
{
	AInventory* Inv = nullptr;
	int32 Count = 0;
	/*
	Inv = Pawn.Inventory;
	if (Inv != nullptr)
	{
		Count++;
		if (Count > 1000)
		{
			return;
		}
		if (!ClassIsChildOf(Inv.Class, WeaponClass))
		{
		}
		if (Pawn.Weapon == nullptr)
		{
			Pawn.PendingWeapon = Cast<AWeapon>(Inv);
			Pawn.ChangedWeapon();
		}
		else
		{
			if (Pawn.Weapon != Cast<AWeapon>(Inv))
			{
				Pawn.PendingWeapon = Cast<AWeapon>(Inv);
				Pawn.Weapon.PutDown();
			}
		}
		return;
		Inv = Inv.Inventory;
	}
	*/
}

void AAA2_Controller::SetPawnClass(FString inClass, FString inCharacter)
{
	APawn* pClass = nullptr;
	/*
	if (inClass == "")
	{
		return;
	}
	pClass = class<Pawn>(DynamicLoadObject(inClass, Class'Class'));
	if (pClass != nullptr)
	{
		PawnClass = pClass;
	}
	*/
}

void AAA2_Controller::SetPawnFemale()
{
}

bool AAA2_Controller::CheckFutureSight(float DeltaTime)
{
	return true;
}

void AAA2_Controller::ChangedWeapon()
{
	/*
	if (Pawn.Weapon != nullptr)
	{
		LastPawnWeapon = Pawn.Weapon.Class;
	}
	*/
}

void AAA2_Controller::ServerReStartPlayer()
{
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	if (Pawn != nullptr)
	{
		ServerGivePawn();
	}
	*/
}

void AAA2_Controller::ServerGivePawn()
{
}

void AAA2_Controller::MonitoredPawnAlert()
{
}

void AAA2_Controller::StartMonitoring(APawn* p, float MaxDist)
{
	/*
	MonitoredPawn = p;
	MonitorStartLoc = p.Location;
	MonitorMaxDistSq = (MaxDist * MaxDist);
	*/
}

bool AAA2_Controller::AutoTaunt()
{
	return false;
}

bool AAA2_Controller::DontReuseTaunt(int32 t)
{
	return false;
}

FString AAA2_Controller::ParseChatPercVar(FString Cmd)
{
	/*
	if (Cmd ~= "%A")
	{
		return FString::FromInt(int(Adrenaline)) @ "Adrenaline";
	}
	if ((Pawn != nullptr) && (Cmd ~= "%S"))
	{
		return FString::FromInt(int(Pawn.ShieldStrength)) @ "Shield";
	}
	*/
	return Cmd;
}

int32 AAA2_Controller::getReportNPCDistance()
{
	return 0;    //FAKE   /ELiZ
}
