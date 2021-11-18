// All the original content belonged to the US Army


#include "AttachW_Javelin.h"
#include "AA29/AA2_Emitter/BaseShellEmitter/Javelin_Tube_Emitter/Javelin_Tube_Emitter.h"
#include "AA29/AA2_Emitter/BaseMuzzleFlashEmitter/JavelinMuzzleFlash/JavelinMuzzleFlash.h"


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
		if (AmmoRound3P == None)
		{
			AmmoRound3P=Spawn('AmmoRound_3P_Javelin',,,,,True,True);
			AmmoRound3P.SetBase(Self);
			AttachToBone(AmmoRound3P,'TubeRoot');
		}
	*/
}
void AAttachW_Javelin::DestroyAR3P()
{
	/*
		if (AmmoRound3P != None)
		{
			AmmoRound3P.DetachFromBone(Self);
			AmmoRound3P.Destroy();
		}
	*/
}
void AAttachW_Javelin::GetbIsDetaching()
{
	/*
		Return bIsDetaching;
	*/
}
void AAttachW_Javelin::SetbIsDetaching(bool Detach)
{
	/*
		bIsDetaching=Detach;
	*/
}
void AAttachW_Javelin::SetbTubeAttached(bool Tube)
{
	/*
		bTubeAttached=Tube;
	*/
}
void AAttachW_Javelin::AdjustForThirdPersonRounds(uint8 NewAnimState, AInventory* Inv)
{
	/*
		AdjustForThirdPersonRounds(NewAnimState,Inv);
		if (AGP_Weapon(Inv).IsInState('BusyReloading'))
		{
			if (bTubeAttached)
			{
				bIsDetaching=False;
			}
			else
			{
				bIsDetaching=True;
			}
		}
		Return NewAnimState;
	*/
}
void AAttachW_Javelin::AttachmentAnimation()
{
	/*
		local AGP.AGP_Pawn p;
		p=AGP_Pawn(Base);
		if (p == None)
		{
			p=AGP_Pawn(Instigator);
		}
		if (p != None)
		{
			if (IsAnimState(1))
			{
				p.AttachToBone(Self,'WeaponBone');
				if (IsNotUS(p))
				{
					Self.SetRelativeLocation(vect(0 0 0));
				}
				SetDrawType(2);
				bCurrentlySelectedAttachment=True;
			}
			else
			{
				p.AttachToBone(Self,'ButtPouch');
				if (IsNotUS(p))
				{
					Self.SetRelativeLocation(_WeaponOffset3P);
				}
				SetDrawType(0);
				bCurrentlySelectedAttachment=False;
			}
		}
	*/
}
void AAttachW_Javelin::PlayAttachmentReload(int32 SpecialReload)
{
	/*
		local AGP.AGP_Pawn p;
		p=AGP_Pawn(Base);
		AttachmentAnimation();
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
	/*
		Destroyed();
		if (AmmoRound3P != None)
		{
			AmmoRound3P.Destroy();
		}
	*/
}
void AAttachW_Javelin::GetAttachBoneFor(AInventory* Inv)
{
	/*
		if (Inv.Instigator.Weapon == Inv)
		{
			Return Inv.Instigator.GetWeaponBoneFor(Inv);
		}
		else
		{
			Return 'ButtPouch';
		}
	*/
}
void AAttachW_Javelin::GetPawnReloadAnimation()
{
	/*
		Switch(AGP_Pawn(Base).JavelinReloadAnimation)
		{
			case 0:
			Return PawnReloadAnimation;
			break;
			case 1:
			Return PawnFullTubeUnloadAnimation;
			break;
			case 2:
			Return PawnEmptyTubeUnloadAnimation;
			break;
			default:
			Log("Warning: JavelinReloadAnimation byte out of bounds.",'PICA');
			Return PawnReloadAnimation;
		}
	*/
}
void AAttachW_Javelin::GetCurrentAnim()
{
	/*
		Switch(Pawn(Base).JavelinReloadAnimation)
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
		}
		Return CurrentAnimation;
	*/
}
