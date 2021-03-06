// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCDummyPawnController/NPCDummyPawnController.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Keypoint/NPCItemOfInterest/NPCItemOfInterest.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"

ANPCDummyPawnController::ANPCDummyPawnController()
{

}

/*
State PawnStartsAsPermanentDummy
{
	simulated Function PlayLoopingAnimation()
	{
		Pawn.AnimBlendParams(AnimChannel,1,Pawn.BlendChangeTime,Pawn.BlendChangeTime);
		Pawn.LoopAnim(AnimSequence,1,0,AnimChannel);
	}
	simulated Function StopAnimation()
	{
		StopAnimating(false);
	}
Begin:
	NPCLog(string(this) + "." + FString::FromInt(GetStateName()) + " trying to start dummy pawn with anim: " + FString::FromInt(AnimSequence));
	if (bDummyPawnLoopIdleAnim)
	{
		Disable("AnimEnd");
		PlayLoopingAnimation();
		if (fpAnimFreezeTime > 0)
		{
			Sleep(fpAnimFreezeTime);
			StopAnimation();
		}
		JL"DoNothing"
;
	}
}
*/

void ANPCDummyPawnController::PostBeginPlay()
{
	Super::PostBeginPlay();
	Start();
}

void ANPCDummyPawnController::SeePlayer(APawn* Seen)
{
}

void ANPCDummyPawnController::NotifyBuzzedByBullet(AActor* aShooter)
{
}

void ANPCDummyPawnController::HearNoise(float Loudness, AActor* NoiseMaker, FVector vSoundLocation)
{
}

bool ANPCDummyPawnController::NotifyBump(AActor* Other)
{
	return false;   //FAKE   /ELiZ
}

bool ANPCDummyPawnController::NotifyHitWall(FVector HitNormal, AActor* Wall)
{
	return false;   //FAKE   /ELiZ
}

void ANPCDummyPawnController::AdjustConfidenceByTime()
{
}

void ANPCDummyPawnController::NotifyItemOfInterestFound(ANPCItemOfInterest* npcioi)
{
}

void ANPCDummyPawnController::NotifyPlayerPawnWatchingMe(APawn* pawnSeen)
{
}

bool ANPCDummyPawnController::NearWall(float walldist)
{
	return false;   //FAKE   /ELiZ
}

void ANPCDummyPawnController::ArrivedAtPathnode()
{
}

void ANPCDummyPawnController::NotifyFlashBanged(float Duration, float VisIntensity, float AudIntensity)
{
}

void ANPCDummyPawnController::Touch(AActor* Other)
{
}

void ANPCDummyPawnController::EnemyNotVisible()
{
}

void ANPCDummyPawnController::NotifyEnemyGrenadeClose(AThrowWeaponPickup* twpGrenade)
{
}

void ANPCDummyPawnController::Timer()
{
}

void ANPCDummyPawnController::NotifyAnotherPawnDied(ANPCBaseController* npcpc)
{
}

void ANPCDummyPawnController::NotifyAnotherPawnTookDamage(APawn* pInstigator, ANPCBaseController* anpcbcDamaged)
{
}

void ANPCDummyPawnController::NotifyNPCTouchedByPlayer(APawn* pawnTouch)
{
}

void ANPCDummyPawnController::NotifyHeardWeaponNoise(float fpLoudness, AAGP_Weapon* agpwWeaponHeard, FVector vSoundLocation)
{
}

void ANPCDummyPawnController::NotifyHeardPlayerNoise(float fpLoudness, APawn* pawnHeard)
{
}

void ANPCDummyPawnController::NotifyPlayerPawnInSight(APawn* pawnSeen)
{
}

void ANPCDummyPawnController::NotifyGrenadeLanded(AThrowWeaponPickup* twpGrenade)
{
}

void ANPCDummyPawnController::NotifyNPCSeen(APawn* Seen)
{
}

void ANPCDummyPawnController::SeeMonster(APawn* Seen)
{
}

void ANPCDummyPawnController::Start()
{
	Super::Start();
	NPCChangeState("PawnStartsAsPermanentDummy","");
}

void ANPCDummyPawnController::NPCChangeState(FName nmState, FName nmLabel)
{
	if ((nmState != "Dead") && (nmState != "PawnStartsAsPermanentDummy"))
	{
		return;
	}
	Super::NPCChangeState(nmState, nmLabel);
}

bool ANPCDummyPawnController::UsedBy(APawn* User)
{
	return true;
}
