// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/AgentController/AgentController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "AA29/Object/Actor/AI_Primitive/Goal_Interface/Goal_Interface.h"
#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/EffectLocation/EffectLocation.h"
#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_Ambient/NPC_Ambient.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_civilian/NPC_civilian.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_soldier.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_TowerObserver/NPC_TowerObserver.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_AT4_Rocket/Weapon_AT4_Rocket.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_GP30_Gren/Weapon_GP30_Gren.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_M203_Gren.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_M24_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M82_Sniper/Weapon_M82_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M870_Shotgun/Weapon_M870_Shotgun.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_MosinNagant_Sniper/Weapon_MosinNagant_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_RPG7_Rocket.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_SVD_Sniper/Weapon_SVD_Sniper.h"

AAgentController::AAgentController()
{
	Waypoint.SetNum(200);
	sPilot.SetNum(10);
	sEnemyLeader.SetNum(27);
	sWhisperSquad.SetNum(32);
	sShoutSquad.SetNum(32);
	sWhisperFriendly.SetNum(32);
	sShoutFriendly.SetNum(32);
	sWhisperEnemy.SetNum(32);
	sShoutEnemy.SetNum(32);
}

/*
auto State busy
{
}
*/

/*
State SuppressState
{
	Function NotifySeePawn()
	{
		DebugLog(DEBUG_Always,"AgentController::SuppressState{}::NotifySeePawn()");
		actionFailed=true;
	}
	simulated Function Rotator GetViewRotation()
	{
		FRotator R = FRotator(0,0,0);
		R=FRotator(int(((FMath::FRand() * float(4096)) - float(2048))),int(((FMath::FRand() * float(8192)) - float(4096))),0);
		return (Global.Weapon() + R);
	}
	Function EndState()
	{
		DebugLog(DEBUG_Always,"Leaving Suppression state");
	}
Begin:
	FireWeapon(true);
	if (actionFailed)
	{
		if (bFireSingleShot == false)
		{
			JL"FaceTarget"
;
		}
		else
		{
			DebugLog(DEBUG_Always,"AgentController::SuppressState{}::Fire: Failed");
			NotifyComplete();
			JL"End"
;
		}
	}
	else
	{
		Sleep(((FMath::FRand() * 0.2) + 0.1));
		if (FMath::FRand() < 0.1)
		{
			DebugLog(DEBUG_Always,"AgentController::SuppressState{}::Fire: Random");
			NotifyComplete();
		}
		JL"Fire"
;
	}
	actionFailed=false;
	if (Target == nullptr)
	{
		DebugLog(DEBUG_Always,"AgentController::SuppressState{}::Begin: No Target");
		actionFailed=true;
		NotifyComplete();
	}
	Pawn.Acceleration=FVector(0,0,0);
	SetPitch(Target.Location);
	Focus=Target;
	if (NeedToTurn(Target.Location))
	{
		DebugLog(DEBUG_AI,"Turning");
		FinishRotation();
	}
	JL"Fire"
;
}
*/

/*
State AttackState
{
	Function ThrowWeaponPickup AvoidGrenade()
	{
		AThrowWeaponPickup* TWP_Danger = nullptr;
		if (CheckGrenadeAwareTime())
		{
			TWP_Danger=ThreatGrenade();
			if (TWP_Danger != nullptr)
			{
				DangerEntity=TWP_Danger;
				SetGrenadeAwareTime(1);
				Pawn.ShouldStand(true);
			}
		}
		return TWP_Danger;
	}
	Function FindPath()
	{
		MoveTarget=FindPathToward(SafeDestN,true);
		if (MoveTarget == nullptr)
		{
			actionFailed=true;
			NotifyComplete();
		}
	}
	Function CoverPlace()
	{
		MoveTarget=nullptr;
		MoveTarget=FindCoverNode(Enemy.Location);
		if (MoveTarget == nullptr)
		{
			actionFailed=true;
			NotifyComplete();
			Log("CoverPlace MoveTarget == NONE");
		}
	}
	Function SafePlace()
	{
		SafeDestN=FindSafePlaceFrom(Enemy->GetActorLocation(),true,false);
	}
	Function HuntingPlace()
	{
		SafeDestN=FindSafePlaceFrom(Enemy->GetActorLocation(),true,true);
	}
	Function AttackMoveTime()
	{
		float fVal = 0;
		fVal=(fNPC_AttackMoveAroundTime - GetWorld()->GetTimeSeconds());
	}
	Function bool ReloadWeapon()
	{
		int32 rounds = 0;
		if (Enemy != nullptr)
		{
			rounds=Pawn.Weapon.GetCurrentAmmoType().AmmoAmount;
			if (rounds <= 0)
			{
				if (Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip > 0)
				{
					Cast<AAGP_Pawn>(GetPawn())->NPC_Reload();
					NPC_GiveAmmo();
					Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip --;
				}
				return true;
			}
		}
		return false;
	}
	Function bool CrouchProne(bool Test)
	{
		float Len = 0;
		FVector vec = FVector(0,0,0);
		float Dot = 0;
		if (fNPC_CrouchTime > GetWorld()->GetTimeSeconds())
		{
			return false;
		}
		vec=(Pawn.Location - Enemy.Location);
		Len=VSize(vec);
		Dot=infront(Pawn->GetActorLocation(),Enemy);
		if (Len > float(512))
		{
			if (CheckIfShouldProne(Pawn->GetActorLocation(),Enemy->GetActorLocation(),fNPC_LikesToProne) && NearWall(128))
			{
				Pawn.ShouldProne(true);
			}
			else
			{
				if (CheckIfShouldCrouch(Pawn->GetActorLocation(),Enemy->GetActorLocation(),fNPC_LikesToCrouch))
				{
					Pawn.ShouldCrouch(true);
				}
				else
				{
					if (FMath::FRand() > fNPC_LikesToStand)
					{
						Pawn.ShouldStand(true);
					}
				}
			}
			fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 10);
		}
		else
		{
			if (FMath::FRand() > fNPC_LikesToStand)
			{
				if (Pawn.bIsCrouched)
				{
					Pawn.ShouldStand(true);
				}
				else
				{
					if (Pawn.bIsProne)
					{
						Pawn.ShouldCrouch(true);
					}
				}
				fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 5);
			}
			else
			{
				if ((Len < 128) || (Dot < 0))
				{
					if (Pawn.bIsCrouched && (! Test))
					{
						Pawn.ShouldStand(true);
					}
					else
					{
						if (Pawn.bIsProne)
						{
							Pawn.ShouldCrouch(true);
						}
					}
					fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 3);
				}
			}
		}
		return true;
	}
	Function bool CanAttack()
	{
		Target=Enemy;
		if (CanSee(Enemy))
		{
			return true;
		}
		return false;
	}
	Function bool LostContact(bool Test)
	{
		if (! Test)
		{
			if (fNPC_LostContactTime < GetWorld()->GetTimeSeconds())
			{
				if ((FMath::FRand() * 100) > (100 - fNPC_Experience))
				{
					fNPC_LostContactTime=(GetWorld()->GetTimeSeconds() + 5);
					return true;
				}
			}
		}
		return false;
	}
	Function MoveAroundCanSeeCheck()
	{
		bMoveAroundCanSee=false;
		if (CanSee(Enemy))
		{
			bMoveAroundCanSee=true;
		}
	}
	Function bool NPC_HowAboutAGrenade()
	{
		if ((FMath::FRand() > fNPC_LikesToThrowGrenade) && (infront(Enemy->GetActorLocation(),Pawn) > 0.75))
		{
			return true;
		}
		return false;
	}
	Function NPC_GrenadeAttack()
	{
		APawn* p = nullptr;
		bool bFragGrenade = false;
		bool bStunGrenade = false;
		bool bSmokeGrenade = false;
		int32 iFragWt = 0;
		int32 iSmokeWt = 0;
		int32 iStunWt = 0;
		bool bTargetVisible = false;
		float fLen = 0;
		FVector vVec = FVector(0,0,0);
		if (CanSee(Enemy))
		{
			bTargetVisible=true;
		}
		vVec=(Pawn.Location - Enemy.Location);
		fLen=VSize(vVec);
		if (fLen > float(1024))
		{
			iSmokeWt=20;
			iFragWt=30;
			if (bTargetVisible)
			{
				(iSmokeWt += 10);
			}
			else
			{
				(iFragWt += 10);
			}
			ForEach DynamicActors(Class'Pawn',p)
			{
				if (infront(Enemy->GetActorLocation(),Pawn) > 0.5)
				{
					if ((p.PressingFire() || p.PressingAltFire()) || p.Weapon.IsFiring())
					{
						(iSmokeWt += 20);
					}
				}
			}
		}
		else
		{
			if (bTargetVisible)
			{
				(iFragWt += 20);
			}
			else
			{
				(iFragWt += 10);
				(iStunWt += 20);
			}
		}
		if (iNPC_FragGrenade > 0)
		{
			bFragGrenade=true;
		}
		if (iNPC_SmokeGrenade > 0)
		{
			bSmokeGrenade=true;
		}
		if (iNPC_StunGrenade > 0)
		{
			bStunGrenade=true;
		}
		if (bSmokeGrenade)
		{
			if (bFragGrenade)
			{
				if (iFragWt > iSmokeWt)
				{
					AttackWithGrenade(1,fLen);
				}
				else
				{
					AttackWithGrenade(3,fLen);
				}
			}
			else
			{
				AttackWithGrenade(3,fLen);
			}
		}
		else
		{
			if (bStunGrenade)
			{
				if (bFragGrenade)
				{
					if (iFragWt > iStunWt)
					{
						AttackWithGrenade(1,fLen);
					}
					else
					{
						AttackWithGrenade(2,fLen);
					}
				}
				else
				{
					AttackWithGrenade(2,fLen);
				}
			}
		}
	}
	Function AttackWithGrenade(int32 Type, float fLen)
	{
		if (Type == 1)
		{
			iNPC_FragGrenade --;
			Cast<AAGP_Pawn>(GetPawn())->GetGrenade(0);
		}
		else
		{
			if (Type == 2)
			{
				iNPC_StunGrenade --;
				Cast<AAGP_Pawn>(GetPawn())->GetGrenade(2);
			}
			else
			{
				if (Type == 3)
				{
					iNPC_SmokeGrenade --;
					Cast<AAGP_Pawn>(GetPawn())->GetGrenade(1);
				}
				else
				{
					Log("AttackWithGrenade(int32 type)::HAHA how did this happen");
				}
			}
		}
		Cast<AAGP_Pawn>(GetPawn())->getItemToPutInHands();
		if (fLen < float(512))
		{
			Cast<AAGP_Pawn>(GetPawn())->GrenadeThrow3p(Cast<AAGP_Pawn>(GetPawn())->8);
		}
		else
		{
			Cast<AAGP_Pawn>(GetPawn())->GrenadeThrow3p(Cast<AAGP_Pawn>(GetPawn())->7);
		}
	}
	Function bool DistanceToTargetGreater(float fLen)
	{
		float fDist = 0;
		FVector vVec = FVector(0,0,0);
		vVec=(Pawn.Location - Enemy.Location);
		fDist=VSize(vVec);
		if (fLen < fDist)
		{
			return false;
		}
		return true;
	}
	Function FriendMarkHisTarget()
	{
		OldTargetHealth=float(Enemy.Health);
	}
	Function bool FriendHitHisTarget()
	{
		if (OldTargetHealth > float(Enemy.Health))
		{
			return true;
		}
		return false;
	}
Begin:
	Sleep(0.1);
	Target=Enemy;
	Focus=Target;
	if (infront(Enemy->GetActorLocation(),Pawn) < 0.75)
	{
		if (NeedToTurn(Target.Location))
		{
			FinishRotation();
		}
		JL"AttackWithGrenade"
;
	}
	NPC_GrenadeAttack();
	NPC_Say(27,true,false,false);
	Sleep(1);
	Cast<AAGP_Pawn>(GetPawn())->DesiredGrenade=nullptr;
	Cast<AAGP_Pawn>(GetPawn())->getItemToPutInHands();
	Stand();
	if (Cast<AAGP_Pawn>(GetPawn())->isDead())
	{
		bIsDead=true;
		NPC_DeathFX();
		JL"End"
;
	}
	if (AvoidGrenade() != nullptr)
	{
		JL"AvoidGrenade"
;
	}
	if (ReloadWeapon())
	{
		fNPC_ReloadWeaponTime=(GetWorld()->GetTimeSeconds() + 5);
		JL"ReloadWeapon"
;
	}
	else
	{
		if (NPC_GotBuzzed())
		{
			if ((FMath::FRand() * 100) > float(Cast<AAGP_Pawn>(GetPawn())->fNPC_Moral))
			{
				NPC_TakeCover(false);
				JL"End"
;
			}
		}
		else
		{
			if (FMath::FRand() > (1 - Cast<AAGP_Pawn>(GetPawn())->fNPC_Agressiveness))
			{
				FriendMarkHisTarget();
				FireWeapon(false);
				if ((Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 5) || (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 6))
				{
					if (FriendHitHisTarget() == false)
					{
						actionFailed=true;
					}
					NPC_ResetToStand();
					JL"End"
;
				}
			}
		}
	}
	CrouchProne(actionFailed);
	if (Cast<AAGP_Pawn>(GetPawn())->bIsBoss && InRange())
	{
		NPC_Say(Rand(4),true,false,false);
	}
	else
	{
		NPC_Say(999,true,false,false);
	}
	if (LostContact(actionFailed))
	{
		iNPC_AlertLevel --;
		if (iNPC_AlertLevel <= 0)
		{
			iNPC_AlertLevel=0;
			NPC_ResetToStand();
		}
		JL"End"
;
	}
	if (actionFailed || (fNPC_AttackMoveAroundTime < GetWorld()->GetTimeSeconds()))
	{
		fNPC_AttackMoveAroundTime=((GetWorld()->GetTimeSeconds() + FMath::FRand()) + 3);
		SafePlace();
		FindPath();
		if (SafeDestN != nullptr)
		{
			JL"MoveAround"
;
		}
	}
	else
	{
		if (actionFailed)
		{
			if (LostContact(actionFailed))
			{
				if (iNPC_AlertLevel <= 0)
				{
					NPC_ResetToStand();
				}
			}
			JL"End"
;
		}
		else
		{
			if (fNPC_AttackMoveAroundTime < GetWorld()->GetTimeSeconds())
			{
				CoverPlace();
				fNPC_AttackMoveAroundTime=((GetWorld()->GetTimeSeconds() + FMath::FRand()) + 3);
				if (MoveTarget != nullptr)
				{
					MoveToward(MoveTarget,MoveTarget,((FMath::FRand() * 128) + 128),true,false);
					JL"End"
;
				}
			}
			else
			{
				Sleep(((FMath::FRand() * 0.1) + 0.1));
				JL"WaitFire"
;
			}
		}
	}
	Sleep(fNPC_AttackDelay);
	if ((Enemy != nullptr) && Cast<AAGP_Pawn>(Enemy).isDead())
	{
		NPC_ResetToStand();
		JL"End"
;
	}
	actionFailed=false;
	if (Target == nullptr)
	{
		Target=Enemy;
		if (Target == nullptr)
		{
			DebugLog(DEBUG_AI,"dnback:: AgentController, AttackState{}; no Enemy set, can't attack");
			actionFailed=true;
			NotifyComplete();
		}
	}
	Pawn.Acceleration=FVector(0,0,0);
	Focus=Target;
	SetPitch(Target.Location);
	if ((Enemy != nullptr) && Cast<AAGP_Pawn>(Enemy).isDead())
	{
		NPC_ResetToStand();
		JL"End"
;
	}
	Sleep(0.1);
	if (AvoidGrenade() != nullptr)
	{
		JL"AvoidGrenade"
;
	}
	MoveAroundCanSeeCheck();
	if (LostContact(bMoveAroundCanSee))
	{
		iNPC_AlertLevel --;
		if (iNPC_AlertLevel <= 0)
		{
			NPC_ResetToStand();
		}
		JL"End"
;
	}
	Target=Enemy;
	Focus=Target;
	if (NeedToTurn(Target.Location))
	{
		DebugLog(DEBUG_AI,"Turning");
		FinishRotation();
	}
	JL"Fire"
;
	if ((Enemy != nullptr) && Cast<AAGP_Pawn>(Enemy).isDead())
	{
		NPC_ResetToStand();
		JL"End"
;
	}
	if (AvoidGrenade() != nullptr)
	{
		JL"AvoidGrenade"
;
	}
	if (FMath::FRand() > Cast<AAGP_Pawn>(GetPawn())->fNPC_Agressiveness)
	{
		Sleep(0.1);
	}
	JL"Fire"
;
	Sleep(0.1);
	if (fNPC_ReloadWeaponTime > GetWorld()->GetTimeSeconds())
	{
		JL"ReloadWeapon"
;
	}
	if ((Enemy != nullptr) && Cast<AAGP_Pawn>(Enemy).isDead())
	{
		NPC_ResetToStand();
		JL"End"
;
	}
	if (AvoidGrenade() != nullptr)
	{
		JL"AvoidGrenade"
;
	}
	MoveAroundCanSeeCheck();
	if (LostContact(bMoveAroundCanSee))
	{
		iNPC_AlertLevel --;
		if (iNPC_AlertLevel <= 0)
		{
			NPC_ResetToStand();
			JL"End"
;
		}
	}
	if (Pawn.bIsProne)
	{
		Pawn.ShouldCrouch(true);
		Sleep(0.1);
		JL"End"
;
	}
	else
	{
		CrouchProne(bMoveAroundCanSee);
	}
	Target=Enemy;
	Focus=Target;
	if ((Pawn.bIsProne == false) && (infront(Enemy->GetActorLocation(),Pawn) < 0.75))
	{
		if (NeedToTurn(Target.Location))
		{
			DebugLog(DEBUG_AI,"Turning");
			FinishRotation();
		}
		Sleep(0.1);
		JL"TurnAndFace"
;
	}
	else
	{
		Sleep(0.1);
		JL"End"
;
	}
	if (AvoidGrenade() != nullptr)
	{
		SafeDestN=FindSafePlaceFrom(DangerEntity->GetActorLocation(),false,false);
		FindPath();
		Pawn.fRunSpeed=Cast<AAGP_Pawn>(GetPawn())->fNPC_RunSpeed;
		if (Cast<AAGP_Pawn>(GetPawn())->bIsBoss && InRange())
		{
			NPC_Say((Rand(10) + 4),true,false,false);
		}
		else
		{
			NPC_Say(22,true,false,false);
		}
		if (SafeDestN != nullptr)
		{
			MoveToward(SafeDestN);
		}
		else
		{
			MoveToward(MoveTarget);
		}
		if (SafeDestN != nullptr)
		{
			SafeDestN=nullptr;
		}
		Sleep(0.1);
		JL"End"
;
	}
	Sleep(0.1);
	if ((Enemy != nullptr) && Cast<AAGP_Pawn>(Enemy).isDead())
	{
		NPC_ResetToStand();
		JL"End"
;
	}
	if (AvoidGrenade() != nullptr)
	{
		JL"AvoidGrenade"
;
	}
	AttackMoveTime();
	if (Cast<AAGP_Pawn>(GetPawn())->isDead())
	{
		bIsDead=true;
		NPC_DeathFX();
		JL"End"
;
	}
	MoveAroundCanSeeCheck();
	if (bMoveAroundCanSee)
	{
		HuntingPlace();
	}
	if (bMoveAroundCanSee)
	{
		if (Cast<AAGP_Pawn>(GetPawn())->bIsBoss)
		{
			NPC_Say((Rand(6) + 4),true,false,false);
		}
		else
		{
			NPC_Say(1,true,false,false);
		}
		HuntingPlace();
	}
	else
	{
		if (LostContact(bMoveAroundCanSee))
		{
			iNPC_AlertLevel --;
			if (iNPC_AlertLevel <= 0)
			{
				NPC_ResetToStand();
			}
			JL"End"
;
		}
		else
		{
			if (Cast<AAGP_Pawn>(GetPawn())->bIsBoss)
			{
				NPC_Say((Rand(4) + 10),true,false,false);
			}
			else
			{
				NPC_Say(4,true,false,false);
			}
			SafePlace();
		}
	}
	FindPath();
	Pawn.fRunSpeed=Cast<AAGP_Pawn>(GetPawn())->fNPC_Speed;
	AdjustAround(PToucher);
	if ((VSize((Enemy.Location - Pawn.Location)) > 512) && (! FastTrace(SafeDestN->GetActorLocation(),Enemy.Location)))
	{
		MoveToward(MoveTarget);
	}
	if ((! bMoveAroundCanSee) && (fNPC_AttackMoveAroundTime > GetWorld()->GetTimeSeconds()))
	{
		Sleep(0.1);
		JL"MoveAround"
;
	}
	else
	{
		Sleep(0.1);
		JL"TurnAndFace"
;
	}
	Sleep(0.1);
	JL"Begin"
;
	Sleep(0.1);
	bAttackDone=true;
	if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 2)
	{
		CurrentOrder=5;
	}
	if (validEnemy() == false)
	{
		Enemy=nullptr;
	}
	Stand();
	NotifyComplete();
}
*/

/*
State IdleState
{
	Function NotifySeePawn()
	{
		DebugLog(DEBUG_Always,"AgentController::IdleState{}::NotifySeePawn()");
		actionFailed=true;
		NotifyComplete();
	}
	Function bool isPassive()
	{
		return true;
	}
Begin:
	actionFailed=false;
	Sleep(0.1);
	MoveToward(Pawn,Pawn,Pawn.fRunSpeed);
	DebugLog(DEBUG_AI,"AgentController::IdleState{}	Pawn " + FString::FromInt(GetPawn()) + " at " + FString::FromInt(Pawn.Location));
	DebugLog(DEBUG_AI,"AgentController::IdleState{}	Got " + FString::FromInt(MoveTarget) + " at " + FString::FromInt(MoveTarget.Location));
	Focus=MoveTarget;
	FinishRotation();
	DebugLog(DEBUG_AI,"AgentController::IdleState{}	Finished");
	DebugLog(DEBUG_Always,"AgentController::IdleState{}");
	NotifyComplete();
	JL"Begin"
;
}
*/

/*
State PatrolState
{
	Function StartPatrolObject()
	{
		ANavigationPoint* N = nullptr;
		for (N=Level.NavigationPointList; N!=nullptr; N=N.nextNavigationPoint)
		{
			if (Cast<APathNode>(N).Name != Pawn.Tag)
			{
			}
			MoveObject=N;
		}
	}
	Function FindPatrolObject()
	{
		ANavigationPoint* N = nullptr;
		for (N=Level.NavigationPointList; N!=nullptr; N=N.nextNavigationPoint)
		{
			if (Cast<APathNode>(N).Name != MoveObject.Tag)
			{
			}
			MoveObject=N;
		}
	}
Begin:
	StartPatrolObject();
	Sleep(0.01);
	JL"Move"
;
	if (Cast<AAGP_Pawn>(GetPawn())->bIsScripted)
	{
		Sleep(1);
		JL"Begin"
;
	}
	else
	{
		Sleep(FMath::FRand());
		JL"Start"
;
	}
	if (Enemy != nullptr)
	{
		Target=Enemy;
		Focus=Enemy;
		if (NeedToTurn(Target.Location))
		{
			FinishRotation();
		}
		Cast<AAGP_Pawn>(GetPawn())->bIsPatrolling=false;
		bPatrolling=false;
		JL"End"
;
	}
	else
	{
		FindPatrolObject();
	}
	Sleep(0.1);
	if (Enemy != nullptr)
	{
		Target=Enemy;
		Focus=Enemy;
		if (NeedToTurn(Target.Location))
		{
			FinishRotation();
		}
		MoveToward(GetPawn());
		Cast<AAGP_Pawn>(GetPawn())->bIsPatrolling=false;
		bPatrolling=false;
		JL"End"
;
	}
	else
	{
		MoveTarget=FindPathToward(MoveObject,true);
	}
	if (MoveTarget.Tag == "PathNodeEnd")
	{
		Pawn.Controller=nullptr;
		Pawn.Destroy();
		JL"Destroy"
;
	}
	MoveToward(MoveTarget);
	if (MoveTarget == MoveObject)
	{
		JL"FindPatrol"
;
	}
	else
	{
		JL"Move"
;
	}
	Sleep(0.1);
	Stand();
}
*/

/*
State QuickMovementState
{
	Function bool FollowTheLeaderMoved()
	{
		FVector vVec = FVector(0,0,0);
		float fLen = 0;
		vVec=(PUserOldPos - PUser.Location);
		fLen=VSize(vVec);
		PUserOldPos=PUser.Location;
		if (fLen > 0)
		{
			return true;
		}
		return false;
	}
	Function UpdateFollowPosture()
	{
		if (fUpdateFollowPostureTime > GetWorld()->GetTimeSeconds())
		{
			fUpdateFollowPostureTime=(GetWorld()->GetTimeSeconds() + 1);
			return;
		}
		if ((! PUser.bIsCrouched) && (! PUser.bIsProne))
		{
			if (Pawn.bIsCrouched || Pawn.bIsProne)
			{
				Pawn.ShouldStand(true);
			}
		}
		else
		{
			if (PUser.bIsCrouched && (! Pawn.bIsCrouched))
			{
				Pawn.ShouldCrouch(true);
			}
			else
			{
				if (PUser.bIsProne && (! Pawn.bIsCrouched))
				{
					Pawn.ShouldCrouch(true);
				}
			}
		}
	}
	Function bool TouchedMoveAway()
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector vVec = FVector(0,0,0);
		FVector vec1 = FVector(0,0,0);
		FVector vec2 = FVector(0,0,0);
		if (((PToucher != nullptr) && isTouched()) && (infront(touchLocation,PToucher) > 0.75))
		{
			GetAxes(PUser.GetViewRotation(),X,Y,Z);
			vVec=PUser.Location;
			(vVec += (X * (PUser.CollisionRadius * 2)));
			if (FastTrace(Pawn->GetActorLocation(),vVec))
			{
				vUpdateFollowLocation=vVec;
				return true;
			}
			vec1=Y;
			vec1=Normal(vec1);
			vec2=vVec;
			vec2=Normal(vec2);
			if ((vec1 Dot vec2) < 0)
			{
				(vVec += (Y * (PUser.CollisionRadius * 1)));
			}
			else
			{
				(Y *= float(-1));
				(vVec += (Y * (PUser.CollisionRadius * 1)));
			}
			if (FastTrace(Pawn->GetActorLocation(),vVec))
			{
				vUpdateFollowLocation=vVec;
				return true;
			}
			else
			{
				MoveObject=FindSafePlaceFrom(PUser->GetActorLocation(),true,true);
			}
		}
		return false;
	}
	Function UpdateMe()
	{
		bool bPUserMoved = false;
		bPUserMoved=FollowTheLeaderMoved();
		if (bPUserMoved)
		{
			UpdateFollowPosture();
		}
	}
	Function FindPath()
	{
		DebugLog(DEBUG_AI,"dnback:: AgentController, MovementState{}; MoveObject = " + FString::FromInt(MoveObject));
		MoveTarget=FindPathToward(MoveObject,true);
		if (MoveTarget == nullptr)
		{
			Log("CurrentDest is: " + FString::FromInt(CurrentDestination));
			DebugLog(DEBUG_AI,"dnback:: AgentController, MovementState{}; could not find a path to " + FString::FromInt(MoveObject));
			actionFailed=true;
			NotifyComplete();
		}
	}
	Function AvoidFearGrenade()
	{
		AThrowWeaponPickup* TWP_Danger = nullptr;
		TWP_Danger=ThreatGrenade();
		if (TWP_Danger._EffectDuration > 0)
		{
			fAvoidFearGrenadeTime=(GetWorld()->GetTimeSeconds() + TWP_Danger._EffectDuration);
			TWP_AvoidFearGrenade=TWP_Danger;
		}
		if (fAvoidFearGrenadeTime < GetWorld()->GetTimeSeconds())
		{
			TWP_AvoidFearGrenade=nullptr;
		}
		if (FearGrenade != nullptr)
		{
			if (CheckGrenadeAwareTime())
			{
				if (TWP_Danger != nullptr)
				{
					SetGrenadeAwareTime(1);
					MoveObject=FindSafePlaceFrom(TWP_Danger->GetActorLocation(),false,false);
				}
			}
		}
		else
		{
			if (TWP_AvoidFearGrenade != nullptr)
			{
				if (VSize((TWP_AvoidFearGrenade.Location - Pawn.Location)) < 1024)
				{
					MoveObject=FindSafePlaceFrom(TWP_AvoidFearGrenade->GetActorLocation(),false,false);
				}
				else
				{
					MoveObject=Pawn;
				}
			}
			else
			{
				if ((PUser != nullptr) && (Enemy == nullptr))
				{
					MoveObject=PUser;
				}
			}
		}
	}
Begin:
	DebugLog(DEBUG_AI,"dnback:: AgentController, MovementState{}; entered Movement state, going to " + FString::FromInt(MoveObject));
	actionFailed=false;
	Sleep(0.1);
	Sleep(0.1);
	UpdateMe();
	if (TouchedMoveAway())
	{
		MoveObject=nullptr;
	}
	else
	{
		AvoidFearGrenade();
	}
	if (MoveObject == PUser)
	{
		if ((Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 5) || (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 6))
		{
			Enemy=nullptr;
			NPC_EnemyDetection();
			if (Enemy != nullptr)
			{
				NPC_Say(3,true,false,true);
				JL"End"
;
			}
		}
		if ((VSize((Pawn.Location - PUser.Location)) > 256) && pointReachable(MoveObject.Location))
		{
			FindPath();
			if (MoveTarget == MoveObject)
			{
				JL"ShortMove"
;
			}
			MoveToward(MoveTarget,PUser,128,true,false);
		}
	}
	else
	{
		if (MoveObject != nullptr)
		{
			FindPath();
			if (MoveTarget == MoveObject)
			{
				JL"ShortMove"
;
			}
			MoveToward(MoveTarget);
		}
		else
		{
			MoveTarget=FindPathTo(vFollowDestination);
			MoveToward(MoveTarget);
			if (VSize((PUser.Location - Pawn.Location)) > (PUser.CollisionRadius * 2))
			{
				MoveObject=PUser;
				(vFollowDestination *= 0);
			}
		}
	}
	JL"LongMove"
;
	DebugLog(DEBUG_AI,"dnback:: AgentController, MovementState{}; got close to " + FString::FromInt(MoveObject) + ", going short");
	MoveToward(MoveObject,MoveObject,Pawn.fRunSpeed);
	DebugLog(DEBUG_Always,"5");
	UpdateMe();
	if (CurrentOrder == 5)
	{
		MoveObject=PUser;
		JL"LongMove"
;
	}
	else
	{
		Stand();
	}
	NotifyComplete();
}
*/

/*
State MovementState
{
	Function FindSafeSpot()
	{
		MoveObject=FindSafePlaceFrom(MoveObject->GetActorLocation(),true,false);
	}
	Function bool WalkRun(float fLen)
	{
		bool bwalk = false;
		float sfactor = 0;
		float minfactor = 0;
		Cast<AAGP_Pawn>(GetPawn())->fRunSpeed=170;
		Cast<AAGP_Pawn>(GetPawn())->fWalkSpeed=85;
		if ((fLen < 384) && (MoveObject == PUser))
		{
			bwalk=true;
		}
		minfactor=0.25;
		sfactor=(float(Cast<AAGP_Pawn>(GetPawn())->Health) / fStartHealth);
		if (sfactor < minfactor)
		{
			sfactor=minfactor;
		}
		(Cast<AAGP_Pawn>(GetPawn())->fRunSpeed *= sfactor);
		(Cast<AAGP_Pawn>(GetPawn())->fWalkSpeed *= sfactor);
		Cast<AAGP_Pawn>(GetPawn())->SetWalking(false);
		Log("Cast<AAGP_Pawn>(GetPawn())->SetWalking(false);");
		return bwalk;
	}
	Function DistanceToDestination()
	{
		float fLen = 0;
		FVector vVec = FVector(0,0,0);
		vVec=(MoveObject.Location - Pawn.Location);
		fLen=VSize(vVec);
	}
	Function bool TouchedMoveAway()
	{
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		FVector vVec = FVector(0,0,0);
		FVector vec1 = FVector(0,0,0);
		FVector vec2 = FVector(0,0,0);
		if (((PUser != nullptr) && isTouched()) && (infront(touchLocation,PUser) > 0.75))
		{
			GetAxes(PUser.GetViewRotation(),X,Y,Z);
			vVec=PUser.Location;
			(vVec += (X * (PUser.CollisionRadius * 2)));
			if (FastTrace(Pawn->GetActorLocation(),vVec))
			{
				vUpdateFollowLocation=vVec;
				return true;
			}
			vec1=Y;
			vec1=Normal(vec1);
			vec2=vVec;
			vec2=Normal(vec2);
			if ((vec1 Dot vec2) < 0)
			{
				(vVec += (Y * (PUser.CollisionRadius * 1)));
			}
			else
			{
				(Y *= float(-1));
				(vVec += (Y * (PUser.CollisionRadius * 1)));
			}
			if (FastTrace(Pawn->GetActorLocation(),vVec))
			{
				vUpdateFollowLocation=vVec;
				return true;
			}
			else
			{
				MoveObject=FindSafePlaceFrom(PUser->GetActorLocation(),true,true);
			}
		}
		return false;
	}
	Function AvoidFearGrenade()
	{
		AThrowWeaponPickup* TWP_Danger = nullptr;
		TWP_Danger=ThreatGrenade();
		if (TWP_Danger._EffectDuration > 0)
		{
			fAvoidFearGrenadeTime=(GetWorld()->GetTimeSeconds() + TWP_Danger._EffectDuration);
			TWP_AvoidFearGrenade=TWP_Danger;
		}
		if (fAvoidFearGrenadeTime < GetWorld()->GetTimeSeconds())
		{
			TWP_AvoidFearGrenade=nullptr;
		}
		if (FearGrenade != nullptr)
		{
			if (CheckGrenadeAwareTime())
			{
				if (TWP_Danger != nullptr)
				{
					SetGrenadeAwareTime(1);
					MoveObject=FindSafePlaceFrom(TWP_Danger->GetActorLocation(),false,false);
				}
			}
		}
		else
		{
			if (TWP_AvoidFearGrenade != nullptr)
			{
				if (VSize((TWP_AvoidFearGrenade.Location - Pawn.Location)) < 1024)
				{
					MoveObject=FindSafePlaceFrom(TWP_AvoidFearGrenade->GetActorLocation(),false,false);
				}
				else
				{
					MoveObject=Pawn;
				}
			}
			else
			{
				if ((PUser != nullptr) && (Enemy == nullptr))
				{
					MoveObject=PUser;
				}
			}
		}
	}
	Function FindPath()
	{
		DebugLog(DEBUG_AI,"dnback:: AgentController, MovementState{}; MoveObject = " + FString::FromInt(MoveObject));
		MoveTarget=FindPathToward(MoveObject,false);
		if (MoveTarget == nullptr)
		{
			Log("STUCK CurrentDest is: " + FString::FromInt(CurrentDestination.Location));
			actionFailed=true;
			NotifyComplete();
		}
	}
	Function bool FollowTheLeaderMoved()
	{
		FVector vVec = FVector(0,0,0);
		float fLen = 0;
		vVec=(PUserOldPos - PUser.Location);
		fLen=VSize(vVec);
		PUserOldPos=PUser.Location;
		if (fLen > 0)
		{
			return true;
		}
		return false;
	}
	Function UpdateFollowLocation()
	{
		FVector vVec = FVector(0,0,0);
		float fLen = 0;
		float fDistance = 0;
		fDistance=4;
		vVec=(vUpdateFollowLocation - PUser.Location);
		fLen=VSize(vVec);
		if (fLen > (PUser.CollisionRadius * fDistance))
		{
			vUpdateFollowLocation=PUser.Location;
		}
	}
	Function UpdateFollowPosture(bool bPUserMoved, float fLen)
	{
		WalkRun(fLen);
		if (fUpdateFollowPostureTime > GetWorld()->GetTimeSeconds())
		{
			fUpdateFollowPostureTime=(GetWorld()->GetTimeSeconds() + 1);
			return;
		}
		if ((! PUser.bIsCrouched) && (! PUser.bIsProne))
		{
			if (Pawn.bIsCrouched || Pawn.bIsProne)
			{
				Pawn.ShouldStand(true);
			}
		}
		else
		{
			if (PUser.bIsCrouched && (! Pawn.bIsCrouched))
			{
				Pawn.ShouldCrouch(true);
			}
			else
			{
				if (PUser.bIsProne && (! Pawn.bIsCrouched))
				{
					Pawn.ShouldCrouch(true);
				}
			}
		}
	}
	Function bool zdiffCheck()
	{
		float fpawnz = 0;
		float fpuserz = 0;
		float zdiff = 0;
		fpawnz=Pawn.Location.Z;
		fpuserz=PUser.Location.Z;
		zdiff=(fpawnz - fpuserz);
		if ((zdiff < -64) && (zdiff > 64))
		{
			return false;
		}
		return true;
	}
	Function Vector FollowMe()
	{
		float fLen = 0;
		FVector vVec = FVector(0,0,0);
		FVector vDest = FVector(0,0,0);
		FVector X = FVector(0,0,0);
		FVector Y = FVector(0,0,0);
		FVector Z = FVector(0,0,0);
		float fDistance = 0;
		FVector vec1 = FVector(0,0,0);
		FVector vec2 = FVector(0,0,0);
		bool bPUserMoved = false;
		if (CurrentOrder == 5)
		{
			UpdateFollowLocation();
			bPUserMoved=FollowTheLeaderMoved();
			vVec=(MoveObject.Location - Pawn.Location);
			fLen=VSize(vVec);
			UpdateFollowPosture(bPUserMoved,fLen);
			fDistance=6;
			if ((fLen < (MoveObject.CollisionRadius * fDistance)) && bPUserMoved)
			{
				GetAxes(PUser.GetViewRotation(),X,Y,Z);
				vDest=vUpdateFollowLocation;
				(vDest += (X * (MoveObject.CollisionRadius * 4)));
				if (infront(Pawn->GetActorLocation(),PUser) > 0.5)
				{
					vec1=Y;
					vec1=Normal(vec1);
					vec2=vVec;
					vec2=Normal(vec2);
					if ((vec1 Dot vec2) < 0)
					{
						(vDest += (Y * (MoveObject.CollisionRadius * 2)));
					}
					else
					{
						(Y *= float(-1));
						(vDest += (Y * (MoveObject.CollisionRadius * 2)));
					}
				}
			}
			else
			{
				if (((fLen < ((MoveObject.CollisionRadius * fDistance) * 2)) && zdiffCheck()) && (Physics != 11))
				{
					vDest=Pawn.Location;
				}
				else
				{
					if (Physics == 11)
					{
						vDest=PUser.Location;
					}
				}
			}
		}
		return vDest;
	}
	Function FriendStartAttack()
	{
		float fLen = 0;
		FVector vVec = FVector(0,0,0);
		vVec=(Enemy.Location - Pawn.Location);
		fLen=VSize(vVec);
		Attack(fLen);
	}
	Function AssesDangerAndSomeFX()
	{
		AActor* dActor = nullptr;
		APawn* p = nullptr;
		float fLen = 0;
		FVector vVec = FVector(0,0,0);
		float fdetectdistance = 0;
		APlayerReplicationInfo* PRI = nullptr;
		APlayerReplicationInfo* UserPRI = nullptr;
		fdetectdistance=1024;
		ForEach DynamicActors(Class'Pawn',p)
		{
			if (p == PUser)
			{
				continue;
			}
			if ((p != nullptr) && (Cast<APlayerController>(p.Controller) != nullptr))
			{
				vVec=(Pawn.Location - p.Location);
				fLen=VSize(vVec);
				if ((fLen < fdetectdistance) && (infront(p->GetActorLocation(),Pawn) > 0.4))
				{
					dActor=p;
					PRI=PlayerReplicationInfo(dActor);
					UserPRI=PUser.PlayerReplicationInfo;
					if (CanSee(p) && (PRI.Team.TeamIndex != UserPRI.Team.TeamIndex))
					{
						if (p.Weapon.IsFiring())
						{
							if (FMath::FRand() > 0.5)
							{
								NPC_PilotSay(0,true);
							}
							else
							{
								if (FMath::FRand() > 0.5)
								{
									NPC_PilotSay(1,true);
								}
								else
								{
									NPC_PilotSay(5,true);
								}
							}
						}
						else
						{
							NPC_PilotSay(0,true);
						}
					}
				}
			}
		}
	}
Begin:
	actionFailed=false;
	Sleep(0.1);
	Pawn.ShouldCrouch(true);
	Sleep(3);
	Sleep(0.1);
	AvoidFearGrenade();
	AssesDangerAndSomeFX();
	if (NPC_GotBuzzed() && (ThreatGrenade() == nullptr))
	{
		JL"TakeCover"
;
	}
	if (MoveObject == PUser)
	{
		if (! TouchedMoveAway())
		{
			vFollowDestination=FollowMe();
		}
		if ((Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 5) || (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 6))
		{
			Enemy=nullptr;
			NPC_EnemyDetection();
			if (Enemy != nullptr)
			{
				NPC_Say(3,true,false,true);
				JL"End"
;
			}
		}
		if (VSize(vFollowDestination) == 0)
		{
			vFollowDestination=PUser.Location;
			(vFollowDestination.Z += 16);
			MoveTarget=FindPathTo(vFollowDestination);
			if (! pointReachable(MoveTarget.Location))
			{
				MoveTarget=ClosestNavPoint();
				if (! pointReachable(MoveTarget.Location))
				{
					JL"LongMove"
;
				}
			}
			if (MoveTarget == MoveObject)
			{
				JL"ShortMove"
;
			}
			MoveToward(MoveTarget);
		}
		else
		{
			if (VSize((vFollowDestination - Pawn.Location)) < 16)
			{
				Focus=PUser;
				FinishRotation();
			}
			else
			{
				MoveTarget=FindPathTo(vFollowDestination);
				if (MoveTarget != nullptr)
				{
					if (MoveTarget == MoveObject)
					{
						JL"ShortMove"
;
					}
					if (! pointReachable(MoveTarget.Location))
					{
						MoveTarget=ClosestNavPoint();
						if (! pointReachable(MoveTarget.Location))
						{
							JL"LongMove"
;
						}
					}
					MoveToward(MoveTarget);
				}
				else
				{
					if (pointReachable(vFollowDestination))
					{
						MoveTo(vFollowDestination);
					}
					else
					{
						vFollowDestination=Pawn.Location;
						MoveTo(vFollowDestination);
					}
				}
			}
			JL"LongMove"
;
		}
	}
	else
	{
		FindSafeSpot();
		if (MoveTarget == MoveObject)
		{
			JL"ShortMove"
;
		}
		MoveToward(MoveTarget);
		JL"LongMove"
;
	}
	Sleep(0.1);
	WalkRun(1);
	if (NPC_GotBuzzed() && (ThreatGrenade() == nullptr))
	{
		JL"TakeCover"
;
	}
	MoveToward(MoveObject,MoveObject,Pawn.fWalkSpeed);
	if (bRunning == true)
	{
		bCower=true;
	}
	if (CurrentOrder == 5)
	{
		MoveObject=PUser;
		JL"LongMove"
;
	}
	else
	{
		Stand();
	}
	NotifyComplete();
	if (Enemy != nullptr)
	{
		Attack(1);
	}
	else
	{
		Stand();
	}
}
*/

/*
State ChargeState
{
	Function FindPath()
	{
		DebugLog(DEBUG_AI,"dnback:: AgentController, ChargeState{}; MoveObject = " + FString::FromInt(MoveObject));
		MoveTarget=FindPathToward(MoveObject,true);
		if (MoveTarget == nullptr)
		{
			DebugLog(DEBUG_AI,"dnback:: AgentController, ChargeState{}; could not find a MoveTarget");
			actionFailed=true;
			DebugLog(DEBUG_Always,"6");
			NotifyComplete();
		}
	}
Begin:
	DebugLog(DEBUG_AI,"dnback:: AgentController, ChargeState{}; charging at " + FString::FromInt(MoveObject));
	actionFailed=false;
	Sleep(0.1);
	FindPath();
	if (Pawn.bIsProne)
	{
		Pawn.ShouldStand();
	}
	MoveToward(MoveTarget,Enemy,Pawn.fRunSpeed);
	if (enemyCont.lineOfFireToHim(GetPawn()) > 0)
	{
		if (VSize((Enemy.Location - Pawn.Location)) < Cast<AAGP_Weapon>(Pawn.Weapon).GetMaximumRange())
		{
			JL"FoundHim"
;
		}
	}
	JL"CheckingAndMove"
;
	DebugLog(DEBUG_AI,"dnback:: AgentController, ChargeState{}; " + FString::FromInt(MoveObject) + ", in sight and in range");
	DebugLog(DEBUG_Always,"7");
	NotifyComplete();
}
*/

/*
State RecoveryState
{
	Function FindPath()
	{
		MoveTarget=FindPathToward(MoveObject,true);
		if (MoveTarget == nullptr)
		{
			actionFailed=true;
			DebugLog(DEBUG_Always,"8");
			NotifyComplete();
		}
	}
Begin:
	Sleep(0.1);
	FindPath();
	if (MoveTarget == MoveObject)
	{
		JL"Recover"
;
	}
	MoveToward(MoveTarget);
	JL"Movement"
;
	MoveToward(MoveObject);
	Cast<APickup>(MoveObject).TakeItem(GetPawn());
	DebugLog(DEBUG_Always,"9");
	NotifyComplete();
}
*/

/*
State WanderState
{
Begin:
	DebugLog(DEBUG_AI,"AgentController::WanderState");
}
*/

/*
State DuckingState
{
Begin:
	actionFailed=false;
	DebugLog(DEBUG_AI,"dnback:: AgentController::DuckingState, crouching");
	Pawn.ShouldCrouch(true);
	DebugLog(DEBUG_Always,"10");
	NotifyComplete();
	JL"End"
;
	DebugLog(DEBUG_AI,"dnback:: AgentController::DuckingState, going prone");
	Pawn.ShouldProne(true);
	DebugLog(DEBUG_Always,"11");
	NotifyComplete();
	if (CanSee(Enemy))
	{
		Pawn.ShouldStand(true);
		Stand();
	}
	Sleep(0.1);
	JL"End"
;
}
*/

/*
State CowerState
{
	Function FindSafeSpot()
	{
		SafeDestN=FindSafePlaceFrom(Enemy->GetActorLocation(),false,false);
		MoveTarget=FindPathToward(SafeDestN,true);
	}
	Function bool CrouchProne(bool Type)
	{
		float Len = 0;
		FVector vec = FVector(0,0,0);
		float Dot = 0;
		if (fNPC_CrouchTime > GetWorld()->GetTimeSeconds())
		{
			return false;
		}
		vec=(Pawn.Location - Enemy.Location);
		Len=VSize(vec);
		Dot=infront(Pawn->GetActorLocation(),Enemy);
		if (Len > float(512))
		{
			if (((FastTrace(Enemy->GetActorLocation(),Pawn.Location) && (Dot > 0.7)) && (FMath::FRand() > fNPC_LikesToProne)) && NearWall(128))
			{
				Pawn.ShouldProne(true);
			}
			else
			{
				if ((Dot > 0.9) && (FMath::FRand() > fNPC_LikesToCrouch))
				{
					Pawn.ShouldCrouch(true);
				}
				else
				{
					if (FMath::FRand() > fNPC_LikesToStand)
					{
						Pawn.ShouldStand(true);
					}
				}
			}
			fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 10);
		}
		else
		{
			if (FMath::FRand() > fNPC_LikesToStand)
			{
				if (Pawn.bIsCrouched)
				{
					Pawn.ShouldStand(true);
				}
				else
				{
					if (Pawn.bIsProne)
					{
						Pawn.ShouldCrouch(true);
					}
				}
				fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 5);
			}
			else
			{
				if ((Len < 128) || (Dot < 0))
				{
					if (Pawn.bIsCrouched && (! Type))
					{
						Pawn.ShouldStand(true);
					}
					else
					{
						if (Pawn.bIsProne)
						{
							Pawn.ShouldCrouch(true);
						}
					}
					fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 3);
				}
				else
				{
					Pawn.ShouldCrouch(true);
				}
			}
		}
		return true;
	}
Begin:
	Cast<AAGP_Pawn>(GetPawn())->Cower(Rand(2));
	Sleep(5);
	Pawn.ShouldCrouch(true);
	NotifyComplete();
	if (Cast<AAGP_Pawn>(GetPawn())->isDead())
	{
		bIsDead=true;
		NPC_DeathFX();
		JL"End"
;
	}
	Stand();
}
*/

/*
State StandState
{
	Function bool CrouchProne(bool Type)
	{
		float Len = 0;
		FVector vec = FVector(0,0,0);
		float Dot = 0;
		if (fNPC_CrouchTime > GetWorld()->GetTimeSeconds())
		{
			return false;
		}
		vec=(Pawn.Location - Enemy.Location);
		Len=VSize(vec);
		Dot=infront(Pawn->GetActorLocation(),Enemy);
		if (Len > float(512))
		{
			if (((FastTrace(Enemy->GetActorLocation(),Pawn.Location) && (Dot > 0.7)) && (FMath::FRand() > fNPC_LikesToProne)) && NearWall(128))
			{
				Pawn.ShouldProne(true);
			}
			else
			{
				if (((Dot > 0.9) && (FMath::FRand() > fNPC_LikesToCrouch)) && NearWall(128))
				{
					Pawn.ShouldCrouch(true);
				}
				else
				{
					if (((Dot > 0.7) && (FMath::FRand() > fNPC_LikesToProne)) && NearWall(128))
					{
						Pawn.ShouldProne(true);
					}
					else
					{
						if (FMath::FRand() > fNPC_LikesToStand)
						{
							Pawn.ShouldStand(true);
						}
					}
				}
			}
			fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 10);
		}
		else
		{
			if (FMath::FRand() > fNPC_LikesToStand)
			{
				if (Pawn.bIsCrouched)
				{
					Pawn.ShouldStand(true);
				}
				else
				{
					if (Pawn.bIsProne)
					{
						Pawn.ShouldCrouch(true);
					}
				}
				fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 5);
			}
			else
			{
				if ((Len < 128) || (Dot < 0))
				{
					if (Pawn.bIsCrouched && (! Type))
					{
						Pawn.ShouldStand(true);
					}
					else
					{
						if (Pawn.bIsProne)
						{
							Pawn.ShouldCrouch(true);
						}
					}
					fNPC_CrouchTime=(GetWorld()->GetTimeSeconds() + 3);
				}
			}
		}
		return true;
	}
	Function bool NPC_TryToRunAway()
	{
		FVector vVec = FVector(0,0,0);
		float fLen = 0;
		vVec=(Enemy.Location - Pawn.Location);
		fLen=VSize(vVec);
		if (fLen > float(1024))
		{
			return true;
		}
		return false;
	}
	Function NPC_StandThink()
	{
		bool dangerGrenade = false;
		AThrowWeaponPickup* TWP_Danger = nullptr;
		float rounds = 0;
		FVector vVec = FVector(0,0,0);
		float fLen = 0;
		dangerGrenade=false;
		if ((Enemy != nullptr) && Cast<AAGP_Pawn>(Enemy).isDead())
		{
			NPC_ResetToStand();
		}
		if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 0)
		{
			return;
		}
		else
		{
			if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType > 0)
			{
				if (CheckGrenadeAwareTime())
				{
					TWP_Danger=ThreatGrenade();
					if (TWP_Danger != nullptr)
					{
						bGrenadeCheck=true;
						dangerGrenade=true;
						SetGrenadeAwareTime(1);
					}
					else
					{
						dangerGrenade=false;
					}
				}
				if (Cast<AAGP_Pawn>(Enemy).IsHeDead())
				{
					Enemy=nullptr;
				}
				if (Enemy == nullptr)
				{
					NPC_EnemyDetection();
				}
			}
		}
		NPC_UpdateOldVisionDistanceChecked();
		NPC_AmmoCheck();
		if (Enemy != nullptr)
		{
			rounds=float(Pawn.Weapon.GetCurrentAmmoType().AmmoAmount);
			if (rounds <= 0)
			{
				if (Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip > 0)
				{
					Reload();
					NPC_GiveAmmo();
					Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip --;
				}
				else
				{
					if ((Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip == 0) && (bRunning == false))
					{
						bRunning=true;
						Cast<AAGP_Pawn>(GetPawn())->fNPC_Moral=0;
						Cast<AAGP_Pawn>(GetPawn())->TossWeapon(((Pawn.Velocity + ( Vector(Rotation) * float(200))) + FVector(0,0,200)));
					}
				}
			}
		}
		if (dangerGrenade == true)
		{
			SafeDestN=FindSafePlaceFrom(TWP_Danger->GetActorLocation(),false,false);
			if (SafeDestN != nullptr)
			{
				MovementToward(SafeDestN);
				if (bHasWeapon == false)
				{
					bHasWeapon=true;
					NPC_GiveWeapon(1);
					NPC_GiveAmmo();
				}
				Stand();
				return;
			}
			else
			{
				Log("can't find safe place from");
				Cower();
			}
		}
		if (bCower == true)
		{
			Cower();
		}
		else
		{
			if (bRunning == true)
			{
				Cower();
			}
			else
			{
				if ((bTookDamage == true) || (Enemy != nullptr))
				{
					if (bHasWeapon == false)
					{
						bHasWeapon=true;
						NPC_GiveWeapon(1);
						NPC_GiveAmmo();
					}
					if (NPC_CanReactDelayIsDone() && (Enemy != nullptr))
					{
						bAttackDone=false;
						if (CurrentOrder == 12)
						{
							Log("NPC_TakeCover :::::::::::::::");
							NPC_TakeCover(false);
						}
						else
						{
							vVec=(Enemy.Location - Pawn.Location);
							fLen=VSize(vVec);
							Attack(fLen);
						}
					}
				}
			}
		}
		if ((dangerGrenade == true) || (bRunning == true))
		{
			Cast<AAGP_Pawn>(GetPawn())->fNPC_Speed=Cast<AAGP_Pawn>(GetPawn())->fNPC_RunSpeed;
		}
		else
		{
			if (SafeDestN != nullptr)
			{
				Cast<AAGP_Pawn>(GetPawn())->fNPC_Speed=Cast<AAGP_Pawn>(GetPawn())->fNPC_RunSpeed;
			}
			else
			{
				Cast<AAGP_Pawn>(GetPawn())->fNPC_Speed=Cast<AAGP_Pawn>(GetPawn())->fNPC_WalkSpeed;
			}
		}
	}
Begin:
	if (validEnemy() == false)
	{
		Enemy=nullptr;
	}
	if (bNewOrder)
	{
		if (CurrentOrder == 5)
		{
			Cast<AAGP_Pawn>(GetPawn())->fNPC_Speed=Cast<AAGP_Pawn>(GetPawn())->fNPC_RunSpeed;
			MovementToward(CurrentDestination);
		}
		else
		{
			if (CurrentOrder == 3)
			{
				Idle();
				Log("CURRENTORDER == m_Idle :::::::::::::::::::");
			}
		}
		bNewOrder=false;
	}
	else
	{
		if (bIsSniper)
		{
			JL"Binocular"
;
		}
		else
		{
			if ((bTookDamage == true) || (Enemy == nullptr))
			{
				JL"Begin"
;
			}
		}
	}
	Sleep((1 + (FMath::FRand() * 2)));
	JL"Start"
;
	Sleep(0.1);
	NPC_EnemyDetection();
	if ((bTookDamage == true) || (Enemy != nullptr))
	{
		Sleep(1);
		Cast<AAGP_Pawn>(GetPawn())->DesiredBinoculars=nullptr;
		Cast<AAGP_Pawn>(GetPawn())->getItemToPutInHands();
		JL"Begin"
;
	}
	else
	{
		JL"Begin"
;
	}
	Sleep(0.1);
	if (validEnemy() == false)
	{
		Enemy=nullptr;
	}
	if (Pawn.bIsProne)
	{
		if (infront(Pawn->GetActorLocation(),Enemy) < 0.5)
		{
			Pawn.ShouldCrouch(true);
		}
	}
	else
	{
		CrouchProne(true);
	}
	if (! NPC_GotBuzzed())
	{
		NPC_StandThink();
	}
	else
	{
		if ((FMath::FRand() * 100) > float(Cast<AAGP_Pawn>(GetPawn())->fNPC_Moral))
		{
			NPC_TakeCover(false);
			JL"End"
;
		}
	}
	JL"Begin"
;
	Sleep(0.1);
	JL"Start"
;
}
*/

/*
State NPC_InvestigateState
{
	Function ThrowWeaponPickup AvoidGrenade()
	{
		AThrowWeaponPickup* TWP_Danger = nullptr;
		if (CheckGrenadeAwareTime())
		{
			TWP_Danger=ThreatGrenade();
			if (TWP_Danger != nullptr)
			{
				DangerEntity=TWP_Danger;
				SetGrenadeAwareTime(1);
				Pawn.ShouldStand(true);
			}
		}
		return TWP_Danger;
	}
	Function FindPath()
	{
		MoveTarget=FindPathToward(InvestigateObject,true);
		if (MoveTarget == nullptr)
		{
			actionFailed=true;
			NotifyComplete();
		}
	}
	Function FindSafeDestNPath()
	{
		MoveTarget=FindPathToward(SafeDestN,true);
		if (MoveTarget == nullptr)
		{
			actionFailed=true;
			NotifyComplete();
		}
	}
	Function bool NPC_TryToRunAway()
	{
		FVector vVec = FVector(0,0,0);
		float fLen = 0;
		vVec=(Enemy.Location - Pawn.Location);
		fLen=VSize(vVec);
		if (fLen > float(1024))
		{
			return true;
		}
		return false;
	}
	Function CallABuddy()
	{
		if (((FMath::FRand() * 100) > (100 - fNPC_Experience)) && (FMath::FRand() > 0.8))
		{
			NPC_InvestigateForceBuddyToSearch();
		}
	}
	Function bool StillSearching()
	{
		if (fNPC_SearchingTime > GetWorld()->GetTimeSeconds())
		{
			return true;
		}
		return false;
	}
	Function NPC_LookAround()
	{
		LookAround();
	}
Begin:
	actionFailed=false;
	Sleep(0.1);
	Pawn.fRunSpeed=Cast<AAGP_Pawn>(GetPawn())->fNPC_WalkSpeed;
	if (fNPC_InvestigateTime < GetWorld()->GetTimeSeconds())
	{
		NPC_Say((Rand(6) + 10),true,true,false);
		FindPath();
		fNPC_InvestigateTime=(GetWorld()->GetTimeSeconds() + 5);
	}
	else
	{
		Focus=InvestigateObject;
		NPC_LookAround();
		FinishRotation();
	}
	if (MoveTarget == InvestigateObject)
	{
		JL"ShortMove"
;
	}
	if (AvoidGrenade() != nullptr)
	{
		JL"AvoidGrenade"
;
	}
	NPC_InvestigateThink();
	MoveToward(MoveTarget);
	JL"LongMove"
;
	Sleep(0.1);
	MoveToward(MoveObject,MoveObject,Pawn.fRunSpeed);
	if ((FMath::FRand() * 100) > (100 - fNPC_Experience))
	{
		fNPC_SearchingTime=(GetWorld()->GetTimeSeconds() + 10);
		JL"Searching"
;
	}
	bNPC_GoCheckItOut=false;
	NPC_Say(6,true,false,false);
	Stand();
	Sleep(0.1);
	NPC_InvestigateThink();
	if (StillSearching())
	{
		CallABuddy();
		JL"Searching"
;
	}
	Stand();
	Log("AvoidGrenade " + FString::FromInt(GetPawn()));
	if (((DangerEntity == nullptr) && (AvoidGrenade() != nullptr)) && FastTrace(Pawn->GetActorLocation(),DangerEntity.Location))
	{
		if (SafeDestN == nullptr)
		{
			SafeDestN=FindSafePlaceFrom(DangerEntity->GetActorLocation(),true,false);
		}
		FindSafeDestNPath();
		Pawn.fRunSpeed=Cast<AAGP_Pawn>(GetPawn())->fNPC_RunSpeed;
		NPC_Say(22,true,false,false);
		if (SafeDestN != nullptr)
		{
			MoveToward(SafeDestN);
		}
		else
		{
			MoveToward(MoveTarget);
		}
		if (SafeDestN != nullptr)
		{
			SafeDestN=nullptr;
		}
		Sleep(0.1);
		JL"End"
;
	}
	Sleep(0.1);
}
*/

/*
State NPC_GoToStartState
{
	Function ThrowWeaponPickup AvoidGrenade()
	{
		AThrowWeaponPickup* TWP_Danger = nullptr;
		if (CheckGrenadeAwareTime())
		{
			TWP_Danger=ThreatGrenade();
			if (TWP_Danger != nullptr)
			{
				DangerEntity=TWP_Danger;
				SetGrenadeAwareTime(1);
				Pawn.ShouldStand(true);
			}
		}
		return TWP_Danger;
	}
	Function FindSafeDestNPath()
	{
		MoveTarget=FindPathToward(SafeDestN,true);
		if (MoveTarget == nullptr)
		{
			actionFailed=true;
			NotifyComplete();
		}
	}
	Function NavigationPoint FindPathToStartLocation()
	{
		ANavigationPoint* N = nullptr;
		ANavigationPoint* thisN = nullptr;
		float fLen = 0;
		FVector vVec = FVector(0,0,0);
		float fOldLen = 0;
		fOldLen=99999;
		for (N=Level.NavigationPointList; N!=nullptr; N=N.nextNavigationPoint)
		{
			vVec=(N.Location - vNPC_StartLocation);
			fLen=VSize(vVec);
			if (fLen < fOldLen)
			{
				fOldLen=fLen;
				thisN=N;
			}
		}
		if (thisN != nullptr)
		{
			MoveTarget=FindPathToward(thisN,true);
		}
		return thisN;
	}
	Function FindPath()
	{
		MoveTarget=FindPathToward(MoveObject,true);
	}
Begin:
	Sleep(0.1);
	MoveObject=FindPathToStartLocation();
	Sleep(0.1);
	Pawn.fRunSpeed=Cast<AAGP_Pawn>(GetPawn())->fNPC_WalkSpeed;
	FindPath();
	if (MoveTarget == MoveObject)
	{
		bNPC_GoCheckItOut=false;
		JL"ShortMove"
;
	}
	if (AvoidGrenade() != nullptr)
	{
		bNPC_GoCheckItOut=false;
		JL"AvoidGrenade"
;
	}
	MoveToward(MoveTarget);
	JL"LongMove"
;
	Sleep(0.1);
	MoveToward(MoveObject,MoveObject,Pawn.fWalkSpeed);
	NPC_Say(6,true,false,false);
	Stand();
	if (((DangerEntity == nullptr) && (AvoidGrenade() != nullptr)) && FastTrace(Pawn->GetActorLocation(),DangerEntity.Location))
	{
		if (SafeDestN == nullptr)
		{
			SafeDestN=FindSafePlaceFrom(DangerEntity->GetActorLocation(),true,false);
		}
		FindSafeDestNPath();
		Pawn.fRunSpeed=Cast<AAGP_Pawn>(GetPawn())->fNPC_RunSpeed;
		if (SafeDestN != nullptr)
		{
			MoveToward(SafeDestN);
		}
		else
		{
			MoveToward(MoveTarget);
		}
		if (SafeDestN != nullptr)
		{
			SafeDestN=nullptr;
		}
		NPC_Say(22,true,false,false);
		Sleep(0.1);
		JL"AvoidGrenade"
;
	}
	Sleep(0.1);
	Sleep(0.1);
	Stand();
}
*/

/*
State NPC_TakingCoverState
{
	Function SafePlace()
	{
		SafeDestN=FindSafePlaceFrom(Enemy->GetActorLocation(),true,false);
	}
	Function FindPath()
	{
		SafePlace();
		MoveTarget=FindPathToward(SafeDestN,true);
		if (MoveTarget == nullptr)
		{
			actionFailed=true;
			NotifyComplete();
		}
	}
	Function int32 PickBehavior()
	{
		if (Cast<AAGP_Pawn>(GetPawn())->MoralCheck(float(Cast<AAGP_Pawn>(GetPawn())->fNPC_Moral)) == 0)
		{
			Cower();
			NotifyComplete();
			return 0;
		}
		else
		{
			if (FMath::FRand() > Cast<AAGP_Pawn>(GetPawn())->fNPC_Agressiveness)
			{
				CurrentOrder=2;
				Stand();
				NotifyComplete();
				return 0;
			}
		}
		if ((Enemy != nullptr) && (! FastTrace(Enemy->GetActorLocation(),Pawn.Location)))
		{
			if ((FMath::FRand() > 0.5) || NearWall(128))
			{
				Pawn.ShouldProne(true);
			}
			else
			{
				Pawn.ShouldCrouch(true);
			}
			NotifyComplete();
			return 0;
		}
		NotifyComplete();
		return 1;
	}
Begin:
	Sleep(0.1);
	Log("NPC_TakingCoverState :: Begin");
	actionFailed=false;
	Sleep(0.1);
	Log("NPC_TakingCoverState :: LongMove");
	Pawn.fRunSpeed=Cast<AAGP_Pawn>(GetPawn())->fNPC_WalkSpeed;
	if ((Pawn.bIsProne == false) && (fNPC_TakingCoverTime < GetWorld()->GetTimeSeconds()))
	{
		SafePlace();
		FindPath();
		fNPC_TakingCoverTime=(GetWorld()->GetTimeSeconds() + 5);
		MoveToward(MoveObject,MoveObject,Pawn.fRunSpeed);
		JL"LongMove"
;
	}
	else
	{
		Stand();
	}
	Sleep(0.1);
	Log("NPC_TakingCoverState :: Prone");
	if (Pawn.bIsProne)
	{
		Pawn.ShouldStand(true);
		JL"RunLikeHell"
;
	}
	Sleep(0.1);
	Log("NPC_TakingCoverState :: Crouched");
	if (Pawn.bIsCrouched)
	{
		Pawn.ShouldStand(true);
		JL"RunLikeHell"
;
	}
	Sleep(0.1);
	Log("NPC_TakingCoverState :: Drop");
	if (FMath::FRand() > 0.5)
	{
		Cast<AAGP_Pawn>(GetPawn())->NPC_Drop2Prone(1);
		Sleep(5);
		Pawn.ShouldStand(true);
	}
	else
	{
		Cast<AAGP_Pawn>(GetPawn())->NPC_Drop2Prone(2);
		Sleep(5);
		Pawn.ShouldStand(true);
	}
	Sleep(0.1);
	Log("NPC_TakingCoverState :: RunLikeHell1");
	if (PickBehavior() == 1)
	{
		JL"LongMove"
;
	}
	NotifyComplete();
	Log("TakingCoverState  -  ended");
	Sleep(0.1);
	Stand();
}
*/

/*
State NPC_DeathState
{
	Function Respawn()
	{
	}
	Function BloodPool()
	{
	}
	Function Flies()
	{
	}
	Function Gibletts()
	{
	}
	Function Flambe()
	{
	}
	Function Dead_Dead()
	{
		bIsDead_Dead=true;
	}
Begin:
	Sleep(0.1);
	if (Cast<AAGP_Pawn>(GetPawn())->bNPC_BloodPool == true)
	{
		bNPC_ActorBloodPoolFX=true;
		BloodPool();
	}
	if (Cast<AAGP_Pawn>(GetPawn())->bNPC_Flies == true)
	{
		bNPC_FliesFX=true;
		Flies();
	}
	if (Cast<AAGP_Pawn>(GetPawn())->bNPC_Gibletts == true)
	{
		bNPC_GiblettsFX=true;
		Gibletts();
	}
	if (Cast<AAGP_Pawn>(GetPawn())->bNPC_Flambe == true)
	{
		bNPC_FlambeFX=true;
		Flambe();
	}
	if (Cast<AAGP_Pawn>(GetPawn())->bActorRespawn == true)
	{
	}
	Sleep(0.1);
	if (FMath::FRand() > 0.5)
	{
		JL"StiffPullingTrigger"
;
	}
	Dead_Dead();
	Sleep(1);
	JL"End"
;
}
*/

//native Function CalculatePathToGoal (FVector NewDestination);

void AAgentController::CalculatePathToGoal(FVector NewDestination)
{
}

//native Function GetNextWaypoint();
FVector AAgentController::GetNextWaypoint()
{
	return FVector(0, 0, 0);     //FAKE   /EliZ
}

void AAgentController::Reset()
{
	/*
		Super::Reset();
		Enemy=nullptr;
		CurrentDestination=nullptr;
		PUser=nullptr;
		SafeDestN=nullptr;
		InvestigateObject=nullptr;
		DangerEntity=nullptr;
		enemyCont=nullptr;
		TWP_AvoidFearGrenade=nullptr;
		*/
}
void AAgentController::Destroyed()
{
	Super::Destroyed();
}
/*
void AAgentController::Possess(APawn* aPawn)
{
		if (! Cast<AAGP_Pawn>(aPawn).bDummyPawn)
		{
			Possess(aPawn);
			Pawn.SetMovementPhysics();
			if (! aPawn->IsA(AAGP_Pawn::StaticClass()))
			{
				Log("ERROR:	AgentController::Possess()	Unknown Pawn " + aPawn);
			}
			bPerfectAccuracy=true;
		}
}
*/

void AAgentController::CreateGoalDecider()
{
	AGoal_Interface* local_interface = nullptr;
	AGoal_Interface* interface_class = nullptr;
	/*
	interface_class=class<Goal_Interface>(DynamicLoadObject("AGP_AI.GoalDecider",Class'Class'));
	local_interface=Spawn(interface_class,Self);
	if (local_interface == nullptr)
	{
		Log("ERROR: AgentController::createGoalDecider() failed to create interface");
	}
	else
	{
		my_goal_decider=local_interface;
	}
	*/
}
bool AAgentController::isPassive()
{
	return false;
}
bool AAgentController::weaponJammed()
{
	/*
		if (Cast<AAGP_Weapon>(Pawn.Weapon).bIsJammed == true)
		{
			return true;
		}
		else
		{
			return false;
		}
		*/
	return false;    //FAKE /ELiZ
}
bool AAgentController::weaponOutOfAmmo()
{
	/*
		if (Pawn.Weapon.GetCurrentAmmoType().AmmoAmount <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	*/
	return false;    //FAKE /ELiZ
}
AMentalModel* AAgentController::getMentalModel()
{
	//return Cast<AAGP_Pawn>(GetPawn())->getMentalModel();
	return nullptr;    //FAKE /ELiZ

}
void AAgentController::NPC_Walk(float Speed)
{
	/*
		Cast<AAGP_Pawn>(GetPawn())->fWalkSpeed=Speed;
		Cast<AAGP_Pawn>(GetPawn())->SetWalking(true);
		*/
}
void AAgentController::NPC_TakeCover(bool isProne)
{
	/*
		if (! NPC_CheckIfDead())
		{
			GotoState('NPC_TakingCoverState','Begin');
		}
		*/
}
void AAgentController::NPC_GoToStart()
{
	/*
		if (! NPC_CheckIfDead())
		{
			GotoState('NPC_GoToStartState','Begin');
		}
		*/
}
void AAgentController::NPC_Investigate()
{
	/*
		if (! NPC_CheckIfDead())
		{
			GotoState('NPC_InvestigateState','Begin');
		}
		*/
}
void AAgentController::NPC_DeadDead()
{
	/*
		GotoState('NPC_DeathState','End');
		*/
}
void AAgentController::NPC_DeathFX()
{
	/*
		GotoState('NPC_DeathState','Start');
		*/
}
void AAgentController::Start()
{
	/*
		if (Cast<AAGP_Pawn>(GetPawn())->bIsPatrolling == true)
		{
			bPatrolling=true;
			if (Cast<AAGP_Pawn>(GetPawn())->bIsScripted)
			{
				GotoState('PatrolState','Begin');
			}
			else
			{
				GotoState('PatrolState','Start');
			}
		}
		else
		{
			GotoState('StandState','Start');
		}
		*/
}
void AAgentController::Stand()
{
	//GotoState('StandState','Begin');
}
void AAgentController::Cower()
{
	/*
	Log("Cower state");
	if (! NPC_CheckIfDead())
	{
		GotoState('CowerState','Begin');
	}
	*/
}

void AAgentController::Suppress(AActor* SuppressionTarget)
{
	/*
	DebugLog(DEBUG_Always,"Got here " + SuppressionTarget);
	Target=SuppressionTarget;
	GotoState('SuppressState','Begin');
	*/
}

void AAgentController::Attack(float fLen)
{
	float fDelay = 0;
	/*
	if (! NPC_CheckIfDead())
	{
		if (iNPC_AlertLevel <= 0)
		{
			iNPC_AlertLevel=1;
		}
		fDelay=1;
		fNPC_AttackDelay=fDelay;
		fNPC_AttackDelay += FMath::FRand() * 2;
		Check=1;
		GotoState('AttackState','Start');
	}
	*/
}

void AAgentController::Idle()
{
	//GotoState('IdleState','Begin');
}
void AAgentController::Patrol()
{
	//GotoState('PatrolState','Begin');
}
void AAgentController::MovementToward(AActor* new_move_object)
{
	/*
		MoveObject=new_move_object;
		if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 5 || Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 6)
		{
			GotoState('QuickMovementState','Begin');
		}
		else
		{
			if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 1)
			{
				GotoState('MovementState','Begin');
			}
			else
			{
				GotoState('QuickMovementState','Begin');
			}
		}
		*/
}
void AAgentController::MovementTo(FVector NewDestination)
{
	/*
		MoveDestination=NewDestination;
		MoveObject=nullptr;
		GotoState('MovementState','Begin');
		*/
}
void AAgentController::Wander()
{
	//GotoState('WanderState','Begin');
}
void AAgentController::Flee()
{
	//GotoState('MovementState','Begin');
}
void AAgentController::FixJam()
{
	/*
		GotoState('busy');
		Cast<AAGP_Weapon>(Pawn.Weapon).FixJam();
		*/
}
void AAgentController::Reload()
{
	/*
		if (! NPC_CheckIfDead())
		{
			Cast<AAGP_Pawn>(GetPawn())->NPC_Reload();
			fNPC_ReloadWeaponTime=GetWorld()->GetTimeSeconds() + 5;
			GotoState('busy');
		}
		*/
}
void AAgentController::Recovery(APickup* recovery_pickup)
{
	/*
		DebugLog(DEBUG_InvAI,"AgentController::Recovery()	" + recovery_pickup);
		MoveObject=recovery_pickup;
		GotoState('RecoveryState');
		*/
}
void AAgentController::TakeCover(bool goProne)
{
	/*
		DebugLog(DEBUG_AI,"dnback:: AgentController.TakeCover(); goProne = " + goProne);
		if (goProne)
		{
			GotoState('DuckingState','Prone');
		}
		else
		{
			GotoState('DuckingState','Begin');
		}
		*/
}

void AAgentController::Charge()
{
	/*
	DebugLog(DEBUG_AI,"dnback:: AgentController.Charge()");
	GotoState('ChargeState','Begin');
	*/
}

bool AAgentController::AdjustAround(APawn* Other)
{
	float Speed = 0;
	FVector VelDir = FVector(0, 0, 0);
	FVector OtherDir = FVector(0, 0, 0);
	FVector SideDir = FVector(0,0,0);
	/*
	Speed=VSize(Pawn.Acceleration);
	if (Speed < Pawn.WalkingPct * Pawn.GroundSpeed)
	{
		return false;
	}
	VelDir=Pawn.Acceleration / Speed;
	VelDir.Z=0;
	OtherDir=Other.Location - Pawn.Location;
	OtherDir.Z=0;
	OtherDir=Normal(OtherDir);
	if (VelDir Dot OtherDir > 0.8)
	{
		bAdjusting=true;
		SideDir.X=VelDir.Y;
		SideDir.Y=-1 * VelDir.X;
		if (SideDir Dot OtherDir > 0)
		{
			SideDir *= -1;
		}
		AdjustLoc=Pawn.Location + 2 * Other.CollisionRadius * 0.5 * VelDir + SideDir;
	}
	*/
	return false;	//FAKE   /ELiZ
}

int32 AAgentController::SetPitch(FVector targ)
{
	FVector D = FVector(0,0,0);
	FRotator R = FRotator(0,0,0);
	/*
	D=targ - Pawn.Location;
	R=D;
	NewPitch=R.Pitch;
	return NewPitch;
	*/
	return 0;    //FAKE   /ELiZ
}

bool AAgentController::NeedToTurn(FVector targ)
{
	FVector LookDir = FVector(0, 0, 0);
	FVector AimDir = FVector(0, 0, 0);
	/*
	LookDir= Vector(Pawn.Rotation);
	LookDir=Normal(LookDir);
	AimDir=targ - Pawn.Location;
	AimDir=Normal(AimDir);
	DebugLog(DEBUG_AI,"dnback:: AgentController.NeedToTurn(); Dot Product =" + LookDir Dot AimDir);
	return LookDir Dot AimDir < 0.99;
	*/
	return false;    //FAKE   /ELiZ
}

void AAgentController::NPC_GiveAmmo()
{
	//Pawn.Weapon.GetCurrentAmmoType().AmmoAmount=30;
}

int32 AAgentController::NPC_isWeaponInstantHit()
{
	/*
	if (Pawn.Weapon->IsA(AWeapon_RPG7_Rocket::StaticClass()) || Pawn.Weapon->IsA(AWeapon_AT4_Rocket::StaticClass()) || Pawn.Weapon->IsA("Weapon_Guerilla_RPG7_Rocket::StaticClass()))
	{
		bNPC_RocketOnlyWeapon=true;
		return 1;
	}
	else
	{
		if (Pawn.Weapon->IsA(AWeapon_M203_Gren::StaticClass()) || Pawn.Weapon->IsA(AWeapon_GP30_Gren::StaticClass()))
		{
			bNPC_DualWeapon=true;
			return 2;
		}
	}
	*/
	return 0;
}
void AAgentController::NPC_SingleShotReloadTime()
{
	/*
		bIsSingleShot=false;
		fSingleShotTime=0;
		if (Pawn.Weapon->IsA(AWeapon_M870_Shotgun::StaticClass()))
		{
			bIsSingleShot=true;
			fSingleShotTime=2;
		}
		else
		{
			if (Pawn.Weapon->IsA(AWeapon_M203_Gren::StaticClass()))
			{
				bIsSingleShot=true;
				fSingleShotTime=3;
			}
			else
			{
				if (Pawn.Weapon->IsA(AWeapon_GP30_Gren::StaticClass()))
				{
					bIsSingleShot=true;
					fSingleShotTime=3;
				}
				else
				{
					if (Pawn.Weapon->IsA(AWeapon_M82_Sniper::StaticClass()))
					{
						bIsSingleShot=true;
						fSingleShotTime=4.5;
					}
					else
					{
						if (Pawn.Weapon->IsA(AWeapon_M24_Sniper::StaticClass()))
						{
							bIsSingleShot=true;
							fSingleShotTime=2.5;
						}
						else
						{
							if (Pawn.Weapon->IsA(AWeapon_MosinNagant_Sniper::StaticClass()))
							{
								bIsSingleShot=true;
								fSingleShotTime=3;
							}
							else
							{
								if (Pawn.Weapon->IsA(AWeapon_SVD_Sniper::StaticClass()))
								{
									bIsSingleShot=true;
									fSingleShotTime=3.5;
								}
								else
								{
									if (Pawn.Weapon->IsA(AWeapon_Freekin_Lasers::StaticClass()))
									{
										bIsSingleShot=true;
										fSingleShotTime=1;
									}
								}
							}
						}
					}
				}
			}
		}
		if (bIsSingleShot == true)
		{
			Cast<AAGP_Weapon>(Pawn.Weapon).eROF=1;
		}
		*/
}
void AAgentController::NPC_GiveWeapon(int32 whichone)
{
	AWeapon* dWeapon = nullptr;
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->NPC_Weapon != nullptr)
	{
		dWeapon=Cast<AAGP_Pawn>(GetPawn())->NPC_Weapon;
		Pawn.NPC_GiveWeapon(dWeapon);
		NPC_SingleShotReloadTime();
		NPC_isWeaponInstantHit();
		Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[0]=10;
		Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[1]=10;
		Cast<AAGP_Pawn>(GetPawn())->_InvGrenades[2]=10;
		return;
	}
	else
	{
		Pawn.GiveWeapon("AGP_Inventory.Weapon_AK47_Rifle");
		NPC_isWeaponInstantHit();
		NPC_SingleShotReloadTime();
	}
	*/
}

void AAgentController::NPC_AmmoCheck()
{
	int32 rounds = 0;
	/*
	if (Enemy != nullptr)
	{
		rounds=Pawn.Weapon.GetCurrentAmmoType().AmmoAmount;
		if (rounds <= 0)
		{
			if (Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip > 0)
			{
				Reload();
				NPC_GiveAmmo();
				Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip --;
			}
			else
			{
				if (Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip == 0 && bRunning == false)
				{
					bRunning=true;
					Cast<AAGP_Pawn>(GetPawn())->fNPC_Moral=0;
					Cast<AAGP_Pawn>(GetPawn())->TossWeapon(Pawn.Velocity +  Vector(Rotation) * 200 + FVector(0 0 200));
				}
			}
		}
	}
	*/
}
void AAgentController::ShootTarget(AActor* NewTarget)
{
}
void AAgentController::NotifyTakeHit(APawn* instigatedBy, FVector HitLocation, int32 Damage, UaDamageType DamageType, FVector Momentum)
{
}
void AAgentController::Killed(AController* Killer, APawn* Other, UaDamageType DamageType)
{
	if (Other == Enemy)
	{

	}
}

void AAgentController::NotifySeePawn()
{
}

void AAgentController::SeePawn(APawn* Seen)
{
	FVector vVec = FVector(0,0,0);
	float fLen = 0;
	float fVisibilityDistance = 0;
	APawn* p = nullptr;
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 1 && Enemy == nullptr)
	{
		if (Cast<APlayerController>(Seen.Controller) != nullptr || Cast<AAGP_Pawn>(Seen).iNPC_ThinkType == 5 || Cast<AAGP_Pawn>(Seen).iNPC_ThinkType == 6)
		{
			vVec=Seen.Location - Pawn.Location;
			fLen=VSize(vVec);
			if (bIsSniper && Cast<AAGP_Pawn>(GetPawn())->DesiredBinoculars != nullptr)
			{
				fVisibilityDistance=Cast<AAGP_Pawn>(GetPawn())->fVisionDistance * 2;
			}
			else
			{
				fVisibilityDistance=Cast<AAGP_Pawn>(GetPawn())->fVisionDistance;
			}
			if (fVisibilityDistance > fLen && NPC_isDistanceDetected(fLen,Seen) == true && NPC_CanReactDelayIsDone() || fLen < 512)
			{
				Log("SeePawn found :: " + Seen);
				SetEnemy(Seen);
				bTookDamage=true;
				bNewOrder=true;
				bAttackDone=true;
				CurrentOrder=2;
				iNPC_AlertLevel ++;
				if (iNPC_AlertLevel > 3)
				{
					iNPC_AlertLevel=3;
				}
				fNPC_ReactDelayTime=GetWorld()->GetTimeSeconds() + FMath::FRand() * 5 + 1 - fNPC_Experience * 10 + 3;
				ForEach DynamicActors(Class'Pawn',p)
				{
					if (p == this)
					{
					}
					else
					{
						if (Cast<AAgentController>(p.Controller).Enemy != nullptr)
						{
						}
						else
						{
							vVec=Seen.Location - p.Location;
							fLen=VSize(vVec);
							if (bIsSniper && Cast<AAGP_Pawn>(p).DesiredBinoculars != nullptr)
							{
								fVisibilityDistance=Cast<AAGP_Pawn>(p).fVisionDistance * 2;
							}
							else
							{
								fVisibilityDistance=Cast<AAGP_Pawn>(p).fVisionDistance;
							}
							if (fVisibilityDistance > fLen && AgentController(p.Controller).NPC_isDistanceDetected(fLen,Seen) == true && AgentController(p.Controller).NPC_CanReactDelayIsDone() || fLen < 512)
							{
								Log("Tell a friend :: " + Seen);
								AgentController(p.Controller).SetEnemy(Seen);
								AgentController(p.Controller).bTookDamage=true;
								AgentController(p.Controller).bNewOrder=true;
								AgentController(p.Controller).bAttackDone=true;
								AgentController(p.Controller).CurrentOrder=2;
								AgentController(p.Controller).iNPC_AlertLevel ++;
								if (Cast<AAgentController>(p.Controller).iNPC_AlertLevel > 3)
								{
									AgentController(p.Controller).iNPC_AlertLevel=3;
								}
								AgentController(p.Controller).fNPC_ReactDelayTime=GetWorld()->GetTimeSeconds() + FMath::FRand() * 5 + 1 - AgentController(p.Controller).fNPC_Experience * 10 + 3;
							}
						}
					}
				}
			}
		}
	}
	*/
}
void AAgentController::SeePlayer(APawn* Seen)
{
	SeePawn(Seen);
}

void AAgentController::SeeMonster(APawn* Seen)
{
	SeePawn(Seen);
}

void AAgentController::HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation)
{
	APawn* dNoiseMaker = nullptr;
	bool jumpy = false;
	/*
	dNoiseMaker=Pawn(NoiseMaker);
	jumpy=false;
	if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 1 && Enemy == nullptr)
	{
		jumpy=true;
		if (jumpy && PlayerController(dNoiseMaker.Controller) != nullptr || Cast<AAGP_Pawn>(dNoiseMaker).iNPC_ThinkType == 5 || Cast<AAGP_Pawn>(dNoiseMaker).iNPC_ThinkType == 6)
		{
			Log("HearNoise found :: " + dNoiseMaker);
			SetEnemy(dNoiseMaker);
			bTookDamage=true;
			bNewOrder=true;
			bAttackDone=true;
			CurrentOrder=2;
			iNPC_AlertLevel ++;
			if (iNPC_AlertLevel > 3)
			{
				iNPC_AlertLevel=3;
			}
			fNPC_ReactDelayTime=GetWorld()->GetTimeSeconds() + FMath::FRand() * 5 + 1 - fNPC_Experience * 10 + 3;
		}
	}
	*/
}
bool AAgentController::SetEnemy(APawn* NewEnemy)
{
	if (NewEnemy == nullptr)
	{
		Enemy=nullptr;
		return false;
	}
	if (Enemy == NewEnemy)
	{
		return true;
	}
	/*
	if (NewEnemy == GetPawn() || NewEnemy == nullptr || NewEnemy->Health <= 0)
	{
		return false;
	}
	*/
	Enemy=NewEnemy;
	return true;
}

bool AAgentController::validEnemy()
{
	/*
	if (Enemy == nullptr || Enemy == Pawn || Enemy.Health <= 0)
	{
		return false;
	}
	*/
	return true;
}

void AAgentController::NPC_ResetToStand()
{
	bCower=false;
	bRunning=false;
	bTookDamage=false;
	Enemy=nullptr;
}

FRotator AAgentController::GetViewRotation()
{
	FRotator ViewRot = FRotator(0,0,0);
	//ViewRot=Rotation;
	//ViewRot.Pitch=NewPitch;
	return ViewRot;
}

FRotator AAgentController::NPC_AdjustAim(FVector projStart, int32 aimerror)
{
	FVector D = FVector(0,0,0);
	FRotator R = FRotator(0, 0, 0);
	FRotator ViewRot = FRotator(0, 0, 0);
	/*
	D=Enemy.Location - Pawn.Location;
	R=D;
	NewPitch=R.Pitch;
	ViewRot=R;
	ViewRot.Pitch=NewPitch;
	*/
	return R;
}

void AAgentController::DoFireEffectSwitchMode()
{
	/*
	if (fNPC_ProjectileAimTime < GetWorld()->GetTimeSeconds())
	{
		fNPC_ProjectileAimTime=GetWorld()->GetTimeSeconds() + 20;
		Pawn.Weapon.GetCurrentAmmoType().bInstantHit=false;
		Pawn.Weapon.NPC_Fire(1,Enemy);
		Pawn.Weapon.GetCurrentAmmoType().bInstantHit=true;
		Cast<AAGP_Pawn>(GetPawn())->NPC_Reload();
	}
	*/
}

void AAgentController::DoFireEffect()
{
	FVector StartPos = FVector(0,0,0);
	FVector EndPos = FVector(0, 0, 0);
	FRotator Aim = FRotator(0, 0, 0);;
	float Spread = 0;
	float aimerror = 0;
	FVector D = FVector(0, 0, 0);
	FVector d1 = FVector(0, 0, 0);
	FRotator r1 = FRotator(0, 0, 0);
	/*
	d1=Enemy.Location - Pawn.Location;
	r1=d1;
	Spread=0;
	aimerror=FMath::FRand() * 0;
	Pawn.MakeNoise(1);
	StartPos=Pawn.Location + Pawn.EyePosition();
	EndPos=Enemy.Location;
	D=EndPos - StartPos;
	Aim.Pitch=r1.Pitch;
	Pawn.SetViewRotation(Aim);
	if (Cast<AAGP_Pawn>(GetPawn())->IsHeDead())
	{
		Log("Dead guy is shooting !!!!!!!!");
	}
	if (FMath::FRand() < fNPC_ShootAccuracy)
	{
		Pawn.Weapon.NPC_Fire(1,Enemy);
	}
	else
	{
		Pawn.Weapon.NPC_Fire(0,Enemy);
	}
	*/
}

bool AAgentController::InRange()
{
	float fLen = 0;
	FVector vVec = FVector(0,0,0);
	/*
	vVec=Enemy.Location - Pawn.Location;
	fLen=VSize(vVec);
	fNPC_AquireAimDistance=fLen;
	if (fLen < Cast<AAGP_Pawn>(GetPawn())->fVisionDistance * iNPC_AlertLevel + 1)
	{
		return true;
	}
	*/
	return false;
}

bool AAgentController::InExtendedRange()
{
	float fLen = 0;
	float fAlert = 0;
	fAlert=iNPC_AlertLevel;
	if (fAlert > 3)
	{
		fAlert=2;
	}
	if (fAlert <= 0)
	{
		fAlert=1;
	}
	fLen=Cast<AAGP_Pawn>(GetPawn())->fVisionDistance * fAlert * 2 / 1 / fNPC_Experience * fNPC_ShootAccuracy;
	if (fNPC_AquireAimDistance < Cast<AAGP_Pawn>(GetPawn())->fVisionDistance * iNPC_AlertLevel + 1 + fLen)
	{
		return true;
	}
	return false;
}

void AAgentController::SetAquireAimTime()
{
	float CrouchedAquireTime = 0;
	float ProneAquireTime = 0;
	float StandingAquireTime = 0;
	float fFuzzyTime = 0;
	/*
	fFuzzyTime=FMath::FRand() * 10 - 5;
	CrouchedAquireTime=3 + fFuzzyTime;
	ProneAquireTime=5 + fFuzzyTime;
	StandingAquireTime=10 + fFuzzyTime;
	if (Pawn.bIsCrouched)
	{
		fNPC_AquireAimTime=GetWorld()->GetTimeSeconds() + CrouchedAquireTime + fNPC_Experience * fNPC_ShootAccuracy;
	}
	else
	{
		if (Pawn.bIsProne)
		{
			fNPC_AquireAimTime=GetWorld()->GetTimeSeconds() + ProneAquireTime + fNPC_Experience * fNPC_ShootAccuracy;
		}
		else
		{
			fNPC_AquireAimTime=GetWorld()->GetTimeSeconds() + StandingAquireTime + fNPC_Experience * fNPC_ShootAccuracy;
		}
	}
	*/
}

bool AAgentController::NPC_FriendlyFire()
{
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	AActor* Other = nullptr;
	FVector VStart = FVector(0, 0, 0);
	FVector vEnd = FVector(0, 0, 0);
	/*
	if (bNoFriendlyFire || fNPC_Experience > FMath::FRand() * 100)
	{
		VStart=Pawn.Location;
		if (Pawn.bIsProne)
		{
			VStart.Z += Pawn.ProneEyeHeight;
		}
		else
		{
			if (Pawn.bIsCrouched)
			{
				VStart.Z += Pawn.CrouchEyeHeight;
			}
			else
			{
				VStart.Z += Pawn.BaseEyeHeight;
			}
		}
		vEnd=Enemy.Location;
		if (Enemy.bIsProne)
		{
			vEnd.Z += Enemy.ProneEyeHeight;
		}
		else
		{
			if (Enemy.bIsCrouched)
			{
				vEnd.Z += Enemy.CrouchEyeHeight;
			}
			else
			{
				vEnd.Z += Enemy.BaseEyeHeight;
			}
		}
		VStart=Pawn.Location + Pawn.Location;
		Other=Trace(HitLocation,HitNormal,vEnd,VStart,true);
		if (Other != nullptr)
		{
			if (iNPC_GroupID == AgentController(Cast<APawn>(Other).Controller).iNPC_GroupID)
			{
				return true;
			}
		}
	}
	*/
	return false;
}
bool AAgentController::NearWall(float walldist)
{
	AActor* HitActor = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	FVector ViewSpot = FVector(0, 0, 0);
	FVector ViewDist = FVector(0, 0, 0);
	FVector LookDir = FVector(0, 0, 0);
	/*
	LookDir= Vector(Rotation);
	ViewSpot=Pawn.Location + Pawn.BaseEyeHeight * FVector(0 0 1);
	ViewDist=LookDir * walldist;
	HitActor=Trace(HitLocation,HitNormal,ViewSpot + ViewDist,ViewSpot,false);
	if (HitActor == nullptr)
	{
		return false;
	}
	ViewDist=Normal(HitNormal Cross FVector(0 0 1)) * walldist;
	if (FMath::FRand() < 0.5)
	{
		ViewDist *= -1;
	}
	Focus=nullptr;
	if (FastTrace(ViewSpot + ViewDist,ViewSpot))
	{
		FocalPoint=Pawn.Location + ViewDist;
		return true;
	}
	if (FastTrace(ViewSpot - ViewDist,ViewSpot))
	{
		FocalPoint=Pawn.Location - ViewDist;
		return true;
	}
	FocalPoint=Pawn.Location - LookDir * 300;
	*/
	return true;
}

bool AAgentController::CheckIfShouldCrouch(FVector StartPosition, FVector TargetPosition, float Probability)
{
	AActor* HitActor = nullptr;
	FVector HitNormal = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector projStart = FVector(0, 0, 0);
	/*
		if (! Pawn.bCanCrouch || ! Pawn.bIsCrouched && FMath::FRand() > Probability)
		{
			Pawn.bWantsToCrouch=false;
			return false;
		}
		GetAxes(Rotation,X,Y,Z);
		projStart=Pawn.Weapon.GetFireStart(X,Y,Z);
		projStart=projStart + StartPosition - Pawn.Location;
		projStart.Z=projStart.Z - 1.8 * Pawn.CollisionHeight - Pawn.CrouchHeight;
		HitActor=Trace(HitLocation,HitNormal,TargetPosition,projStart,false);
		if (HitActor == nullptr)
		{
			Pawn.bWantsToCrouch=true;
			return true;
		}
		projStart.Z=projStart.Z + 1.8 * Pawn.Default.CollisionHeight - Pawn.CrouchHeight;
		HitActor=Trace(HitLocation,HitNormal,TargetPosition,projStart,false);
		if (HitActor == nullptr)
		{
			Pawn.bWantsToCrouch=false;
			return false;
		}
		Pawn.bWantsToCrouch=true;
		*/
	return true;
}

bool AAgentController::CheckIfShouldProne(FVector StartPosition, FVector TargetPosition, float Probability)
{
	AActor* HitActor = nullptr;
	FVector HitNormal = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector X = FVector(0, 0, 0);
	FVector Y = FVector(0, 0, 0);
	FVector Z = FVector(0, 0, 0);
	FVector projStart = FVector(0, 0, 0);
	/*
	if (! Pawn.bCanProne || ! Pawn.bIsProne && FMath::FRand() > Probability)
	{
		Pawn.bWantsToProne=false;
		return false;
	}
	GetAxes(Rotation,X,Y,Z);
	projStart=Pawn.Weapon.GetFireStart(X,Y,Z);
	projStart=projStart + StartPosition - Pawn.Location;
	projStart.Z=projStart.Z - 1.8 * Pawn.CollisionHeight - Pawn.ProneHeight;
	HitActor=Trace(HitLocation,HitNormal,TargetPosition,projStart,false);
	if (HitActor == nullptr)
	{
		Pawn.bWantsToProne=true;
		return true;
	}
	projStart.Z=projStart.Z + 1.8 * Pawn.Default.CollisionHeight - Pawn.ProneHeight;
	HitActor=Trace(HitLocation,HitNormal,TargetPosition,projStart,false);
	if (HitActor == nullptr)
	{
		Pawn.bWantsToProne=false;
		return false;
	}
	Pawn.bWantsToProne=true;
	*/
	return true;
}

void AAgentController::FireWeapon(bool bSuppressiveFire)
{
	FVector StartPos = FVector(0, 0, 0);
	FVector vVec = FVector(0, 0, 0);
	/*
	if (Pawn.Weapon != nullptr)
	{
		if (InRange() == false)
		{
			if (fNPC_AquireAimTime < GetWorld()->GetTimeSeconds())
			{
				if (InExtendedRange() == true)
				{
					SetAquireAimTime();
				}
				else
				{
					actionFailed=true;
					return;
				}
			}
			else
			{
				actionFailed=true;
				return;
			}
		}
		if (! CanSee(Enemy))
		{
			actionFailed=true;
			return;
		}
		if (Cast<AAGP_Weapon>(Pawn.Weapon).WeaponDisabled() == true)
		{
			DebugLog(DEBUG_AI,"AgentController::FireWeapon()	Weapon Disabled");
			actionFailed=true;
			return;
		}
		if (bIsSingleShot)
		{
			if (fSingleShotDelayTime < GetWorld()->GetTimeSeconds())
			{
				bFireSingleShot=true;
				fSingleShotDelayTime=GetWorld()->GetTimeSeconds() + fSingleShotTime;
			}
			else
			{
				actionFailed=true;
				bFireSingleShot=false;
				return;
			}
		}
		if (NPC_FriendlyFire())
		{
			actionFailed=true;
			return;
		}
		if (NPC_isWeaponInstantHit() == 0)
		{
			DoFireEffect();
		}
		else
		{
			StartPos=Pawn.Location;
			vVec= Vector(Pawn.Rotation);
			vVec += 32 * vVec;
			StartPos += vVec;
			if (Pawn.bIsProne)
			{
				StartPos.Z += Pawn.ProneEyeHeight;
			}
			else
			{
				if (Pawn.bIsCrouched)
				{
					StartPos.Z += Pawn.CrouchEyeHeight;
				}
				else
				{
					StartPos.Z += Pawn.BaseEyeHeight;
				}
			}
			if (FastTrace(Enemy->GetActorLocation(),StartPos))
			{
				DoFireEffectSwitchMode();
			}
			else
			{
				actionFailed=true;
				return;
			}
		}
		DebugLog(DEBUG_AI,"dnback:: AgentController.fireWeapon(); " + Pawn + " shot at " + Enemy);
		DebugLog(DEBUG_AI,"AgentController::FireWeapon()	" + Pawn.Weapon.GetCurrentAmmoType().AmmoAmount + " rounds");
		actionFailed=false;
	}
	else
	{
		actionFailed=true;
	}
	*/
}

void AAgentController::registerNotification(AAction* new_action)
{
	ActiveAction=new_action;
	actionFailed=false;
}

void AAgentController::NotifyComplete()
{
	if (ActiveAction != nullptr)
	{
		//ActiveAction.NotifyComplete(actionFailed);
		ActiveAction=nullptr;
	}
}
bool AAgentController::HandlePickupQuery(APickup* pick)
{
	return true;
}
bool AAgentController::NPC_isDistanceDetected(float fLen, APawn* p)
{
	float ratio = 0;
	FVector D = FVector(0,0,0);
	float distanceofD = 0;
	bool bCreeping = false;
	/*
	bCreeping=false;
	if (VSize(EnemyTrackedPosition) == 0)
	{
		EnemyTrackedPosition=p.Location;
	}
	D=EnemyTrackedPosition - p.Location;
	distanceofD=VSize(D);
	EnemyTrackedPosition=p.Location;
	if (distanceofD < 64 && fLen > 1024)
	{
		ratio=fLen / Cast<AAGP_Pawn>(GetPawn())->fVisionDistance;
		ratio *= fNPC_Experience;
		if (p.bIsCrouched)
		{
			ratio *= 0.8;
		}
		else
		{
			if (p.bIsProne)
			{
				ratio *= 0.6;
			}
		}
		if (iNPC_AlertLevel == 0)
		{
			ratio *= 0.8;
		}
		else
		{
			if (iNPC_AlertLevel == 1)
			{
				ratio *= 1;
			}
			else
			{
				if (iNPC_AlertLevel == 2)
				{
					ratio *= 1.2;
				}
				else
				{
					if (iNPC_AlertLevel == 3)
					{
						ratio *= 2;
					}
				}
			}
		}
		if (0.5 > ratio)
		{
			return true;
		}
		bCreeping=true;
	}
	if (p.bIsCrouched)
	{
		fLen *= 0.8;
	}
	else
	{
		if (p.bIsProne)
		{
			fLen *= 0.6;
		}
	}
	if (bCreeping == true)
	{
		fLen *= 0.5;
	}
	if (iNPC_AlertLevel == 0)
	{
		fLen *= 0.8;
	}
	else
	{
		if (iNPC_AlertLevel == 1)
		{
			fLen *= 1;
		}
		else
		{
			if (iNPC_AlertLevel == 2)
			{
				fLen *= 1.2;
			}
			else
			{
				if (iNPC_AlertLevel == 3)
				{
					fLen *= 2;
				}
			}
		}
	}
	if (fLen < 0)
	{
		return false;
	}
	if (bAsleep)
	{
		return false;
	}
	if (fNPC_OldVisionDistanceChecked - FMath::FRand() * 256 < fLen || 1024 > fLen)
	{
		InvestigateObject=p;
		InvestigateTrackedPosition=p.Location;
		return true;
	}
	fNPC_OldVisionDistanceChecked=fLen;
	*/
	return false;
}

void AAgentController::NPC_UpdateOldVisionDistanceChecked()
{
	/*
	if (FMath::FRand() < fNPC_Experience)
	{
		if (fNPC_OldVisionDistanceChecked > 0)
		{
			fNPC_OldVisionDistanceChecked -= FMath::FRand() * fNPC_Experience;
		}
		else
		{
			fNPC_OldVisionDistanceChecked=0;
		}
	}
	*/
}

void AAgentController::NPC_AlertYourBuddies(APawn* p)
{
	AAgentController* Buddy = nullptr;
	float HearIt = 0;
	float SeeIt = 0;
	FVector vec = FVector(0,0,0);
	/*
	ForEach DynamicActors('AgentController',Buddy)
	{
		if (APawn* == Buddy)
		{
		}
		else
		{
			if (bIsSniper)
			{
			}
			else
			{
				if (Buddy.Enemy != nullptr)
				{
				}
				else
				{
					if (Buddy.iNPC_GroupID == iNPC_GroupID || bIsALeader)
					{
						if (bHandSignalsOnly)
						{
							vec=Buddy.Location - Pawn.Location;
							SeeIt=VSize(vec);
							if (Buddy.CanSee(GetPawn()) && SeeIt < Cast<AAGP_Pawn>(GetPawn())->fVisionDistance)
							{
								if (iNPC_AlertLevel < 3)
								{
									iNPC_AlertLevel ++;
								}
							}
						}
						else
						{
							if (Buddy.fNPC_ReactDelayTime == 0)
							{
								vec=Buddy.Location - Pawn.Location;
								HearIt=VSize(vec);
								if (HearIt < Cast<AAGP_Pawn>(GetPawn())->fHearingDistance)
								{
									if (iNPC_AlertLevel < 3)
									{
										iNPC_AlertLevel ++;
									}
									Buddy.fNPC_ReactDelayTime=GetWorld()->GetTimeSeconds() + FMath::FRand() * 5 + 1 - fNPC_Experience * 3;
									Buddy.SetEnemy(Enemy);
								}
							}
						}
					}
				}
			}
		}
	}
	*/
}
bool AAgentController::NPC_CanReactDelayIsDone()
{
	/*
	if (fNPC_ReactDelayTime > GetWorld()->GetTimeSeconds())
	{
		return false;
	}
	fNPC_ReactDelayTime=0;
	return true;
	*/
	return false;    //FAKE /ELiZ
}

void AAgentController::NPC_EnemyDetection()
{
	APawn* p = nullptr;
	FVector vVec = FVector(0, 0, 0);
	float fLen = 0;
	FVector StartPos = FVector(0, 0, 0);
	FVector EndPos = FVector(0, 0, 0);
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 1)
	{
		GOTO JL0263;
	}
	if ((Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 5) || (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 6))
	{
		ForEach DynamicActors(Class'Pawn', p)
		{
			if ((p != nullptr) && (Cast<APlayerController>(p.Controller) == nullptr))
			{
				if (Cast<AAGP_Pawn>(p).iNPC_ThinkType == 1)
				{
					vVec = (p.Location - Pawn.Location);
					fLen = VSize(vVec);
					if (Cast<AAGP_Pawn>(GetPawn())->fVisionDistance > fLen)
					{
						StartPos = p.Location;
						if (p.bIsProne)
						{
							(StartPos.Z += p.ProneEyeHeight);
						}
						else
						{
							if (p.bIsCrouched)
							{
								(StartPos.Z += p.CrouchEyeHeight);
							}
							else
							{
								(StartPos.Z += p.BaseEyeHeight);
							}
						}
						EndPos = Pawn.Location;
						if (Pawn.bIsProne)
						{
							(EndPos.Z += Pawn.ProneEyeHeight);
						}
						else
						{
							if (Pawn.bIsCrouched)
							{
								(EndPos.Z += Pawn.CrouchEyeHeight);
							}
							else
							{
								(EndPos.Z += Pawn.BaseEyeHeight);
							}
						}
						if (CanSee(p) || FastTrace(p->GetActorLocation(), Pawn.Location))
						{
							SetEnemy(p);
							bTookDamage = true;
							bNewOrder = true;
							bAttackDone = true;
							CurrentOrder = 2;
						}
					}
				}
			}
		}
	JL0263:
	}
	*/
}
void AAgentController::NPC_InvestigateThink()
{
	FVector vVec = FVector(0, 0, 0);
	float fLen = 0;
	/*
	vVec=(InvestigateObject.Location - Pawn.Location);
	fLen=VSize(vVec);
	if (1024 > fLen)
	{
		if (CanSee(InvestigateObject))
		{
			SetEnemy(InvestigateObject);
			Attack(fLen);
			NPC_Say(3,true,true,false);
			NPC_AlertYourBuddies(InvestigateObject);
		}
	}
	vVec=(InvestigateTrackedPosition - Pawn.Location);
	fLen=VSize(vVec);
	if (200 > fLen)
	{
		NPC_GoToStart();
		NPC_Say(6,true,true,false);
	}
	*/
}
void AAgentController::NPC_InvestigateForceBuddyToSearch()
{
	AAgentController* Buddy = nullptr;
	float HearIt = 0;
	float SeeIt = 0;
	FVector vec = FVector(0, 0, 0);
	/*
	ForEach DynamicActors(AAgentController::StaticClass(),Buddy)
	{
		if (Pawn == Buddy)
		{
			continue;
		}
		if (bIsSniper)
		{
			continue;
		}
		if (Buddy.Enemy != nullptr)
		{
			continue;
		}
		if ((Buddy.iNPC_GroupID == iNPC_GroupID) || bIsALeader)
		{
			if (bHandSignalsOnly)
			{
				vec=(Buddy.Location - Pawn.Location);
				SeeIt=VSize(vec);
				if (Buddy.CanSee(GetPawn()) && (SeeIt < Cast<AAGP_Pawn>(GetPawn())->fVisionDistance))
				{
					if (iNPC_AlertLevel < 3)
					{
						iNPC_AlertLevel ++;
					}
				}
			}
			else
			{
				if ((Buddy.fNPC_ReactDelayTime == 0) && (Buddy.bNPC_GoCheckItOut == false))
				{
					vec=(Buddy.Location - Pawn.Location);
					HearIt=VSize(vec);
					if (HearIt < Cast<AAGP_Pawn>(GetPawn())->fHearingDistance)
					{
						if (iNPC_AlertLevel < 3)
						{
							iNPC_AlertLevel ++;
						}
						Buddy.fNPC_ReactDelayTime=((GetWorld()->GetTimeSeconds() + (FRand() * 5)) + ((1 - fNPC_Experience) * 10));
						Buddy.bNPC_GoCheckItOut=true;
						Buddy.InvestigateObject=InvestigateObject;
						Buddy.InvestigateTrackedPosition=InvestigateObject.Location;
						Buddy.EnemyTrackedPosition=InvestigateObject.Location;
						Buddy.NPC_Investigate();
						if (Cast<AAGP_Pawn>(GetPawn())->bIsBoss && InRange())
						{
							NPC_Say((Rand(10) + 4),true,false,false);
						}
						else
						{
							Buddy.NPC_Say(0,true,true,false);
						}
						if (Buddy.bHasWeapon == false)
						{
							Buddy.bHasWeapon=true;
							Buddy.NPC_GiveWeapon(1);
							Buddy.NPC_GiveAmmo();
						}
					}
				}
			}
		}
	}
	*/
}

bool AAgentController::LookAround()
{
	/*
	if (fIsLookingTime < GetWorld()->GetTimeSeconds())
	{
		fIsLookingTime=GetWorld()->GetTimeSeconds() + 2;
		DesiredRotation=Pawn.Rotation;
		if (bIsLookingAroundDir == true)
		{
			DesiredRotation.Yaw += 1024;
			bIsLookingAroundDir=false;
			bRotateToDesired=true;
		}
		else
		{
			DesiredRotation.Yaw -= 1024;
			bIsLookingAroundDir=true;
			bRotateToDesired=true;
		}
		return true;
	}
	*/
	return false;
}
bool AAgentController::NPC_GotBuzzed()
{
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->IsHeDead())
	{
		return false;
	}
	if (Cast<AAGP_Pawn>(GetPawn())->NPC_isGotBuzzed() == true)
	{
		if (PUser != nullptr || Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType != 1)
		{
			if (FMath::FRand() > 0.5)
			{
				NPC_PilotSay(1,true);
			}
			else
			{
				NPC_PilotSay(5,true);
			}
		}
		else
		{
			if (Cast<AAGP_Pawn>(GetPawn())->bIsBoss)
			{
				NPC_Say(Rand(7) + 4,True,false,false);
			}
			else
			{
				NPC_Say(4,True,false,false);
			}
		}
		return true;
	}
	*/
	return false;
}

bool AAgentController::CheckGrenadeAwareTime()
{
	/*
	if (Cast<AAGP_Pawn>(GetPawn())->fGrenadeAwareTime > GetWorld()->GetTimeSeconds())
	{
		return false;
	}
	else
	{
		Cast<AAGP_Pawn>(GetPawn())->fGrenadeAwareTime=0;
	}
	*/
	return true;
}

void AAgentController::SetGrenadeAwareTime(float Time)
{
	//Cast<AAGP_Pawn>(GetPawn())->fGrenadeAwareTime=GetWorld()->GetTimeSeconds() + Time;
}

AThrowWeaponPickup* AAgentController::ThreatGrenade()
{
	float dist = 0;
	FVector vec = FVector(0,0,0);
	FVector ZOffset = FVector(0, 0, 0);
	/*
	vec=FearGrenade.Location - Pawn.Location;
	dist=VSize(vec);
	ZOffset=Pawn.Location;
	ZOffset.Z=ZOffset.Z + Pawn.CrouchHeight;
	if (FastTrace(FearGrenade->GetActorLocation(),ZOffset) && dist < 1024)
	{
		return FearGrenade;
	}
	*/
	return nullptr;
}

void AAgentController::NPC_GiveClip(int32 Num)
{
	//Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip=Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip + Num;
}

void AAgentController::NPC_SetActorAttributes()
{
	/*
	fNPC_LikesToProne=Cast<AAGP_Pawn>(GetPawn())->NPC_LikesToProne / 100;
	fNPC_LikesToCrouch=Cast<AAGP_Pawn>(GetPawn())->NPC_LikesToCrouch / 100;
	fNPC_LikesToStand=Cast<AAGP_Pawn>(GetPawn())->NPC_LikesToStand / 100;
	fNPC_LikesToAmbush=Cast<AAGP_Pawn>(GetPawn())->NPC_LikesToAmbush / 100;
	fNPC_LikesToAssault=Cast<AAGP_Pawn>(GetPawn())->NPC_LikesToAssault / 100;
	fNPC_LikesToTalk=Cast<AAGP_Pawn>(GetPawn())->NPC_LikesToTalk / 100;
	fNPC_LikesToAmbient=Cast<AAGP_Pawn>(GetPawn())->NPC_LikesToAmbient / 100;
	fNPC_LikesToThrowGrenade=Cast<AAGP_Pawn>(GetPawn())->NPC_LikesToThrowGrenade / 100;
	fNPC_ShootAccuracy=Cast<AAGP_Pawn>(GetPawn())->NPC_ShootAccuracy / 100;
	fNPC_Experience=Cast<AAGP_Pawn>(GetPawn())->fNPC_Experience;
	iNPC_GroupID=Cast<AAGP_Pawn>(GetPawn())->iNPC_GroupID;
	iNPC_FragGrenade=Cast<AAGP_Pawn>(GetPawn())->iNPC_FragGrenade;
	iNPC_SmokeGrenade=Cast<AAGP_Pawn>(GetPawn())->iNPC_SmokeGrenade;
	iNPC_StunGrenade=Cast<AAGP_Pawn>(GetPawn())->iNPC_StunGrenade;
	bIsSniper=Cast<AAGP_Pawn>(GetPawn())->bIsSniper;
	if (bIsSniper)
	{
		Log("We have a sniper");
	}
	Pawn.PeripheralVision=0.7;
	SetDrawType(2);
	*/
}
void AAgentController::NPC_Think()
{
	/*
	if (bStart == false)
	{
		Level.Game.GameDifficulty=2;
		bStart=true;
		fStartHealth=Cast<AAGP_Pawn>(GetPawn())->Health;
		NPC_SetActorAttributes();
		if (Cast<AAGP_Pawn>(GetPawn())->bDummyPawn == true && Cast<AAGP_Pawn>(GetPawn())->NPC_Weapon != nullptr)
		{
			bHasWeapon=true;
			NPC_GiveWeapon(1);
			NPC_GiveAmmo();
			NPC_GiveClip(10);
			Reload();
			return;
		}
		if (Pawn->IsA(ANPC_soldier::StaticClass()))
		{
			if (Cast<AAGP_Pawn>(GetPawn())->bIsScriptedWalking)
			{
				NPC_Walk(85);
			}
			if (Cast<AAGP_Pawn>(GetPawn())->NPC_ActorType() == 5 || Cast<AAGP_Pawn>(GetPawn())->NPC_ActorType() == 6)
			{
				bCanBeUsed=true;
				bNoFriendlyFire=true;
				fNPC_ShootAccuracy=1;
				Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType=5;
				iNPC_GroupID=777;
			}
			else
			{
				Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType=1;
			}
			if (Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip == 0)
			{
				NPC_GiveClip(10);
			}
			if (iNPC_GroupID == 0)
			{
				iNPC_GroupID=1;
			}
			if (Cast<AAGP_Pawn>(GetPawn())->bIsStartsWithWeapon)
			{
				if (bHasWeapon == false)
				{
					bHasWeapon=true;
					NPC_GiveWeapon(1);
					NPC_GiveAmmo();
				}
			}
			Start();
		}
		else
		{
			if (Pawn->IsA(ANPC_TowerObserver::StaticClass()))
			{
			}
			if (Pawn->IsA(ANPC_doctor::StaticClass) || Pawn->IsA(ANPC_Ambient::StaticClass()) || Pawn->IsA(ANPC_civilian::StaticClass()))
			{
				if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 5 || Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 6 || Cast<AAGP_Pawn>(GetPawn())->NPC_ActorType() == 5 || Cast<AAGP_Pawn>(GetPawn())->NPC_ActorType() == 6)
				{
					fNPC_ShootAccuracy=1;
					Cast<AAGP_Pawn>(GetPawn())->fNPC_Agressiveness=100;
					bCanBeUsed=true;
					Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType=5;
					iNPC_GroupID=777;
					if (Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip == 0)
					{
						NPC_GiveClip(30);
					}
					if (bHasWeapon == false)
					{
						bHasWeapon=true;
						NPC_GiveWeapon(1);
						NPC_GiveAmmo();
					}
				}
				else
				{
					bCanBeUsed=true;
					Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType=3;
					if (Cast<AAGP_Pawn>(GetPawn())->iNPC_Clip == 0)
					{
						NPC_GiveClip(0);
					}
				}
				Start();
			}
		}
	}
	*/
}

bool AAgentController::NPC_CheckIfDead()
{
	if (bIsDead == false && Cast<AAGP_Pawn>(GetPawn())->IsHeDead())
	{
		//SetPhysics(0);
		bIsDead=true;
		NPC_DeathFX();
		return true;
	}
	else
	{
		if (bIsDead_Dead == true)
		{
			NPC_DeadDead();
			return true;
		}
	}
	return false;
}

void AAgentController::Timer()
{
	NPC_Think();
}

void AAgentController::BeginPlay()
{
	//SetTimer(1,true);
}

bool AAgentController::UsedBy(APawn* User)
{
	if (Cast<AAGP_Pawn>(GetPawn())->bIsScripted)
	{
		Cast<AAGP_Pawn>(GetPawn())->bIsScripted=false;
		return true;
	}
	if (bCanBeUsed == true)
	{
		if (fWait < GetWorld()->GetTimeSeconds())
		{
			return true;
		}
	}
	return false;
}

bool AAgentController::isTouched()
{
	if (bTouched == true)
	{
		bTouched=false;
		return true;
	}
	bTouched=false;
	PToucher=nullptr;
	return false;
}

void AAgentController::Touch(AActor* Other)
{
	APawn* User = nullptr;
	AAGP_Pawn* IDPawn = nullptr;
	bTouched=true;
	/*
	if (Other->IsA(AAuxCollisionCylinder::StaticClass()))
	{
		IDPawn=Cast<AAGP_Pawn>(Cast<AAuxCollisionCylinder>(Other).Owner);
		User=IDPawn;
		PToucher=User;
		touchLocation=PToucher.Location;
	}
	if (User == nullptr)
	{
		return;
	}
	if (Pawn->IsA(ANPC_soldier::StaticClass()))
	{
		if (IDPawn.Controller->IsA(AHumanController::StaticClass()))
		{
			if ((Cast<AAGP_Pawn>(GetPawn())->NPC_ActorType() != 5) || (Cast<AAGP_Pawn>(GetPawn())->NPC_ActorType() != 6))
			{
				if (Pawn.bIsProne)
				{
					Pawn.ShouldStand(true);
				}
				iNPC_AlertLevel=3;
				SetEnemy(User);
				bTookDamage=true;
				if ((Cast<AAGP_Pawn>(GetPawn())->IsHeDead() == true) && (bIsDead_Dead == true))
				{
					bDeadDeadTwitch=true;
				}
				if (Cast<AAGP_Pawn>(GetPawn())->bIsBoss)
				{
					NPC_Say((Rand(14) + 4),true,false,false);
				}
				else
				{
					NPC_Say(24,true,false,false);
				}
			}
		}
	}
	*/
}

ANavigationPoint* AAgentController::ClosestNavPoint()
{
	ANavigationPoint* N = nullptr;
	ANavigationPoint* dN = nullptr;
	float Distance = 0;
	float fLen = 0;
	Distance = 99999;
	for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
	{
		/*
		fLen = VSize((N.Location - Pawn.Location));
		if (((fLen < Distance) && FastTrace(N->GetActorLocation(), Pawn.Location)) && (MoveObject != N))
		{
			dN = N;
			Distance = fLen;
		}
		*/
	}
	return dN;
}

ANavigationPoint* AAgentController::FindCoverNode(FVector VPosition)
{
	ANavigationPoint* N = nullptr;
	FVector vVec = FVector(0, 0, 0);
	ANavigationPoint* Dest = nullptr;
	float fOldLen = 0;
	float fLen = 0;
	fOldLen = 99999;
	for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
	{
		if (Cast<APathNode>(N)->NodeType != ENodeType::NT_Cover)
		{
		}
		if (N == NCoverPlace)
		{
		}
		if (Cast<APathNode>(N)->CoverTaken > 2)
		{
		}
		/*
		vVec = (N.Location - Pawn.Location);
		fLen = VSize(vVec);
		if (fLen < fOldLen)
		{
			fOldLen = fLen;
			Dest = N;
			PathNode(N).CoverTaken++;
		}
		*/
	}
	NCoverPlace = Dest;
	return Dest;
}

ANavigationPoint* AAgentController::FindSafePlaceFrom(FVector InstigatedByLocation, bool bNear, bool abHunting)
{
	ANavigationPoint* N = nullptr;
	ANavigationPoint* DestN = nullptr;
	float Distance = 0;
	FVector vVec = FVector(0, 0, 0);
	float fLen = 0;
	float fLenToPlayer = 0;
	float fLenToLocation = 0;
	float fMINDIST = 0;
	fMINDIST = 256;
	DestN = nullptr;
	if (bNear == true)
	{
		Distance = 99999;
	}
	else
	{
		Distance = 0;
	}
	fLenToPlayer = 0;
	fLenToLocation = 0;
	fLen = 0;
	for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
	{
		/*
		vVec = (N.Location - Pawn.Location);
		fLenToLocation = VSize(vVec);
		fLen = fLenToLocation;
		if (SafeDestN == N)
		{
		}
		if (!FastTrace(N.vFloor, InstigatedByLocation))
		{
			vVec = (N.Location - InstigatedByLocation);
			fLenToPlayer = VSize(vVec);
			if (bHunting == true)
			{
				if (fLenToLocation > fLenToPlayer)
				{
					if (bNear == true)
					{
						if ((fLen < Distance) && (fLen > fMINDIST))
						{
							Distance = fLen;
							DestN = N;
						}
					}
					else
					{
						if (fLen > Distance)
						{
							Distance = fLen;
							DestN = N;
						}
					}
				}
			}
			else
			{
				if (fLenToLocation < fLenToPlayer)
				{
					if (bNear == true)
					{
						if (fLen < Distance)
						{
							Distance = fLen;
							DestN = N;
						}
					}
					else
					{
						if (fLen > Distance)
						{
							Distance = fLen;
							DestN = N;
							Log("FindSafePlaceFrom: " + FString::FromInt(Distance));
						}
					}
				}
			}
		}
		*/
	}
	return DestN;
}

/*
void AAgentController::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* AHitMaterial)
{
		if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 1)
		{
			iNPC_AlertLevel=3;
			SetEnemy(instigatedBy);
			if (bTookDamage == false)
			{
				CurrentOrder=12;
			}
			bTookDamage=true;
			if (Cast<AAGP_Pawn>(GetPawn())->IsHeDead() == true && bIsDead_Dead == true)
			{
				bDeadDeadTwitch=true;
			}
			if (Cast<AAGP_Pawn>(GetPawn())->bIsBoss)
			{
				NPC_Say(Rand(14) + 4,True,false,false);
			}
			else
			{
				NPC_Say(24,True,false,false);
			}
		}
		else
		{
			if (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 5 || Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 6)
			{
				SetEnemy(instigatedBy);
				if (bTookDamage == false)
				{
					CurrentOrder=12;
				}
				bTookDamage=true;
				if (Cast<AAGP_Pawn>(GetPawn())->IsHeDead() == true && bIsDead_Dead == true)
				{
					bDeadDeadTwitch=true;
				}
				Attack(1);
				NPC_Say(24,True,false,true);
			}
			else
			{
				fNPC_TalkFrequency=1;
				NPC_PilotSay(Rand(3) + 2,false);
			}
		}
}
*/

void AAgentController::GrenadeTakeCover(bool bProne)
{
	bGrenadeCheck=false;
	TakeCover(bProne);
}

float AAgentController::infront(FVector vec, APawn* Who)
{
	FVector LookDir = FVector(0, 0, 0);
	FVector AimDir = FVector(0, 0, 0);
	/*
	LookDir= Vector(Who.Rotation);
	LookDir=Normal(LookDir);
	AimDir=(vec - Who.Location);
	AimDir=Normal(AimDir);
	return (LookDir Dot AimDir);
	*/
	return 0;    //FAKE   /ELiZ
}

void AAgentController::NPC_PilotSay(int32 Snd, bool Force)
{
	AActor* SoundActor = nullptr;
	USoundBase* SoundPtr = nullptr;
	/*
	if ((fNPC_LastTalkTime < GetWorld()->GetTimeSeconds()) || (Force == true))
	{
		fNPC_LastTalkTime=((GetWorld()->GetTimeSeconds() + (1 * FRand())) + 2);
		SoundPtr=sPilot[Snd];
		if (SoundPtr != nullptr)
		{
			SoundActor=Spawn(AEffectLocation::StaticClass(),,,Pawn.Location);
			SoundActor.LifeSpan=GetSoundDuration(SoundPtr);
			SoundActor.PlaySound(SoundPtr,0,1,,,,false);
		}
	}
	*/
}

void AAgentController::NPC_Say(int32 theSound, bool shout, bool forceplay, bool bFriend)
{
	AActor* SoundActor = nullptr;
	USoundBase* SoundPtr = nullptr;
	int32 R = 0;
	/*
	if ((Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 5) || (Cast<AAGP_Pawn>(GetPawn())->iNPC_ThinkType == 6))
	{
		if (Level.bCoOpGame)
		{
			bFriend=true;
		}
	}
	if (((FRand() > fNPC_TalkFrequency) && (fNPC_LastTalkTime < GetWorld()->GetTimeSeconds())) || (forceplay == true))
	{
		fNPC_LastTalkTime=((GetWorld()->GetTimeSeconds() + (5 * FRand())) + 5);
		if (! Cast<AAGP_Pawn>(GetPawn())->bIsBoss)
		{
			if (theSound == 999)
			{
				R=Rand(27);
			}
			else
			{
				R=theSound;
			}
			if (shout == true)
			{
				if (bFriend)
				{
					SoundPtr=sShoutFriendly[R];
				}
				else
				{
					SoundPtr=sShoutEnemy[R];
				}
			}
			else
			{
				R=Rand(27);
				if (bFriend)
				{
					SoundPtr=sWhisperFriendly[R];
				}
				else
				{
					SoundPtr=sWhisperEnemy[R];
				}
			}
		}
		else
		{
			R=theSound;
			SoundPtr=sEnemyLeader[R];
		}
		if (SoundPtr != nullptr)
		{
			SoundActor=Spawn(AEffectLocation::StaticClass(),,,Pawn.Location);
			SoundActor.LifeSpan=GetSoundDuration(SoundPtr);
			SoundActor.PlaySound(SoundPtr,0,1,,,,false);
		}
	}
	*/
}
