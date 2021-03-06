// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_Javelin/AttachW_Javelin.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Javelin_Tube_Emitter/Javelin_Tube_Emitter.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/JavelinMuzzleFlash/JavelinMuzzleFlash.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Base3pAmmoRound/Base3pAmmoRound.h"

AAttachW_Javelin::AAttachW_Javelin()
{
	PawnFullTubeUnloadAnimation		= FName("stdunloadclu");
	PawnEmptyTubeUnloadAnimation	= FName("StdUnloadCLUSpent");
	PawnReloadAnimation				= FName("stdreloadclu");
	FullTubeUnloadAnimation			= FName("Unload");
	EmptyTubeUnloadAnimation		= FName("unloadspent");
	ReloadAnimation					= FName("Reload");
	MaxSize							= 1.13f;
	MinSize							= 0.8f;
	TimeToGrow						= 1;
	TimeToShrink					= 1;
	_bDelayShellEject				= true;
	bHasAttachmentReload			= true;
	IdleAnim						= FName("Idle");
	_cShellEmitterClass				= AJavelin_Tube_Emitter::StaticClass();
	_ShellOffset1P.VOffset			= FVector(-30, 0, 35);
	_ShellOffset1P.ROffset			= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone			= "TubeRoot";
	_ShellOffset3P.VOffset			= FVector(0, 0, 0);
	_ShellOffset3P.ROffset			= FRotator(0, 0, 180);
	_ShellOffset3P.nBone			= "TubeRoot";
	_cMuzzleFlashClass				= AJavelinMuzzleFlash::StaticClass();
	_MuzzleOffset.VOffset			= FVector(0, 0, 0);
	_MuzzleOffset.ROffset			= FRotator(0, 0, 0);
	_MuzzleOffset.nBone				= "Backblast";
	EnemyAttachmentClass			= AAttachW_Javelin::StaticClass();
	DrawType						= EDrawType::DT_Mesh;
	DrawScale						= 1.13;
	Mesh							= LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AAO_Armory/clu.clu"), NULL, LOAD_None, NULL);
}

/*
simulated State PlayAttachReload
{
	simulated Function Timer()
	{
		if (CurrentAnimation == FullTubeUnloadAnimation)
		{
			WEAPON_Javelin(Cast<APawn>(GetOwner())->Weapon).SpawnTube();
			SetbIsDetaching(false);
		}
		else
		{
			if (CurrentAnimation == EmptyTubeUnloadAnimation)
			{
				ThirdPersonEffectsEject(Cast<AHumanController>(Level.GetClientController()));
			}
		}
	}
	simulated Function DestroyTube()
	{
		AAGP_Weapon* Tube = nullptr;
		AAGP_Pawn* p = nullptr;
		if (Cast<AAGP_Pawn>(Base) != nullptr)
		{
			p=Cast<AAGP_Pawn>(Base);
			Tube=Cast<AAGP_Weapon>(p.getAltShoulderInventory());
			if (Tube != nullptr)
			{
				p.DeleteInventory(Tube);
				Tube.Destroy();
			}
		}
	}
	Function SetJavelinReloadAnimation()
	{
		if (CurrentAnimation == ReloadAnimation)
		{
			Cast<APawn>(Base).ChangeJavelinReloadAnimation(1);
		}
		else
		{
			Cast<APawn>(Base).ChangeJavelinReloadAnimation(0);
		}
	}
Begin:
	if ((CurrentAnimation == ReloadAnimation) && (GetNetMode() != ENetMode::NM_Client))
	{
		DestroyTube();
	}
	if ((CurrentAnimation == FullTubeUnloadAnimation) && (GetNetMode() != ENetMode::NM_Client))
	{
		SetTimer(2.4,false);
	}
	if ((CurrentAnimation == EmptyTubeUnloadAnimation) && (Cast<AHumanController>(Level.GetClientController()) != nullptr))
	{
		SetTimer(0.75,false);
	}
	if (GetWorld()->GetNetMode() == NM_DedicatedServer)
	{
		Sleep(GetAnimDuration(CurrentAnimation));
	}
	else
	{
		FinishAnim();
	}
	SetJavelinReloadAnimation();
	EndState();
}
*/

/*
State Growing
{
	simulated Function Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
		if (DrawScale < MaxSize)
		{
			SetDrawScale((DrawScale + (DeltaTime * fSizeToGrow)));
		}
		else
		{
			SetDrawScale(MaxSize);
			EndState();
		}
	}
Begin:
	fSizeToGrow=((MaxSize - DrawScale) / float(TimeToGrow));
}
*/

/*
State Shrinking
{
	simulated Function Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
		if (DrawScale > MinSize)
		{
			SetDrawScale((DrawScale - (DeltaTime * fSizeToGrow)));
		}
		else
		{
			SetDrawScale(MinSize);
			EndState();
		}
	}
Begin:
	fSizeToGrow=((DrawScale - MinSize) / float(TimeToShrink));
}
*/

void AAttachW_Javelin::SetMesh()
{
	/*
		SetMesh();
		PlayAnim(IdleAnim,1,0.05);
	*/
}
void AAttachW_Javelin::SpawnAndAttachAR3P()
{
	/*
		if (AmmoRound3P == nullptr)
		{
			AmmoRound3P=Spawn('AmmoRound_3P_Javelin',,,,,True,true);
			AmmoRound3P.SetBase(this);
			AttachToBone(AmmoRound3P,'TubeRoot');
		}
	*/
}
void AAttachW_Javelin::DestroyAR3P()
{
	/*
		if (AmmoRound3P != nullptr)
		{
			AmmoRound3P.DetachFromBone(this);
			AmmoRound3P.Destroy();
		}
	*/
}

bool AAttachW_Javelin::GetbIsDetaching()
{
	return bIsDetaching;
}

void AAttachW_Javelin::SetbIsDetaching(bool Detach)
{
	bIsDetaching=Detach;
}

void AAttachW_Javelin::SetbTubeAttached(bool Tube)
{
	bTubeAttached=Tube;
}

uint8 AAttachW_Javelin::AdjustForThirdPersonRounds(uint8 NewAnimState, AInventory* Inv)
{
	/*
	AdjustForThirdPersonRounds(NewAnimState,Inv);
	if (Cast<AAGP_Weapon>(Inv).IsInState('BusyReloading'))
	{
		if (bTubeAttached)
		{
			bIsDetaching=false;
		}
		else
		{
			bIsDetaching=true;
		}
	}
	*/
	return NewAnimState;
}

void AAttachW_Javelin::AttachmentAnimation()
{
	AAGP_Pawn* p = nullptr;
	p = Cast<AAGP_Pawn>(Base);
	/*
	if (p == nullptr)
	{
		p=Cast<AAGP_Pawn>(Instigator);
	}
	if (p != nullptr)
	{
		if (IsAnimState(1))
		{
			p.AttachToBone(this,'WeaponBone');
			if (IsNotUS(p))
			{
				Self.SetRelativeLocation(FVector(0,0,0));
			}
			SetDrawType(2);
			bCurrentlySelectedAttachment=true;
		}
		else
		{
			p.AttachToBone(this,'ButtPouch');
			if (IsNotUS(p))
			{
				Self.SetRelativeLocation(_WeaponOffset3P);
			}
			SetDrawType(0);
			bCurrentlySelectedAttachment=false;
		}
	}
	*/
}
void AAttachW_Javelin::PlayAttachmentReload(int32 SpecialReload)
{
	AAGP_Pawn* p = nullptr;
	p = Cast<AAGP_Pawn>(Base);
	AttachmentAnimation();
	/*
	if (SpecialReload == -1)
	{
		PlayAnim(IdleAnim,1,0.05);
	}
	else
	{
		GetCurrentAnim();
		PlayAnim(CurrentAnimation,1,0);
		GotoState('PlayAttachReload');
	}
	*/
}

void AAttachW_Javelin::Destroyed()
{
	Super::Destroyed();
	if (AmmoRound3P != nullptr)
	{
		AmmoRound3P->Destroy();
	}
}

FName AAttachW_Javelin::GetAttachBoneFor(AInventory* Inv)
{
	/*
	if (Inv.Instigator.Weapon == Inv)
	{
		return Inv.Instigator.GetWeaponBoneFor(Inv);
	}
	else
	{
		return 'ButtPouch';
	}
	*/
	return "FAKE";     //FAKE /EliZ
}

FName AAttachW_Javelin::GetPawnReloadAnimation()
{
	switch(Cast<AAGP_Pawn>(Base)->JavelinReloadAnimation)
	{
		case 0:
			return PawnReloadAnimation;
			break;
		case 1:
			return PawnFullTubeUnloadAnimation;
			break;
		case 2:
			return PawnEmptyTubeUnloadAnimation;
			break;
		default:
			//Log("Warning: JavelinReloadAnimation byte out of bounds.",'PICA');
			return PawnReloadAnimation;
	}
}

FName AAttachW_Javelin::GetCurrentAnim()
{
	switch(Cast<AAGP_Pawn>(Base)->JavelinReloadAnimation)
	{
		case 0:
			CurrentAnimation=ReloadAnimation;
			break;
		case 1:
			CurrentAnimation=FullTubeUnloadAnimation;
			break;
		case 2:
			CurrentAnimation=EmptyTubeUnloadAnimation;
			break;
		default:
			CurrentAnimation=ReloadAnimation;
			break;
	}
	return CurrentAnimation;
}
