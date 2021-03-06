// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AttachmentHandler/AttachmentHandler.h"
#include "AA29/Object/Actor/BaseModAttachment/BaseModAttachment.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Base3pAmmoRound/Base3pAmmoRound.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/BaseMuzzleFlashEmitter.h"
#include "AA29/Object/Actor/Emitter/BaseShellEmitter/BaseShellEmitter.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/InventoryAttachment/InventoryAttachment.h"
#include "AA29/Object/Actor/LaserProjector/LaserProjector.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

ABaseWeaponAttachment::ABaseWeaponAttachment()
{
	_ShellOffset1P.VOffset	= FVector(0, 0, 0);
	_ShellOffset1P.ROffset	= FRotator(-90, 0, 0);
	_ShellOffset1P.nBone =	"M16-MagRound";
	_ShellOffset3P.VOffset	= FVector(0, 0, 0);
	_ShellOffset3P.ROffset	= FRotator(0, 0, 180);
	_ShellOffset3P.nBone	= "WeaponBone";
	_MuzzleOffset.VOffset	= FVector(0, 0, 0);
	_MuzzleOffset.ROffset	= FRotator(0, 0, 90);
	_MuzzleOffset.nBone		= "WeaponBone";
	bAttachMILES            = true;
	_WeaponOffset3P			= FVector( 25,  0,  0);
	PawnStdReloadAnimation	= "StdLgRld";
	PawnPrnReloadAnimation	= "PrnLgRld";
	DrawType				= EDrawType::DT_StaticMesh;
	RelativeRotation		= FRotator(-90, 0, 0);
}

bool ABaseWeaponAttachment::GetbIsDetaching()
{
	return false;
}

void ABaseWeaponAttachment::SetbIsDetaching(bool Detach)
{
}

void ABaseWeaponAttachment::PreBeginPlay()
{
	/*
		PreBeginPlay();
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			InitializeShellEmitter();
		}
	*/
}

void ABaseWeaponAttachment::InitializeShellEmitter()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		return;
	}
	if (FiringMode != "ROF_SingleGren")
	{
		if (_ShellEmitter == nullptr)
		{
			SpawnShellEmitters();
		}
	}
	else
	{
		if (_AuxShellEmitter == nullptr)
		{
			SpawnShellEmitters();
		}
	}
}

UStaticMesh* ABaseWeaponAttachment::GetStaticMesh(bool bFriendly)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly) || Level.GamePlayMode == 1 || Self.bDontSwapMeshes)
	{
		return Default.StaticMesh;
	}
	else
	{
		return EnemyAttachmentClass.Default.StaticMesh;
	}
	*/
	return nullptr;

}

USkeletalMesh* ABaseWeaponAttachment::GetMesh(bool bFriendly)
{
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly) || Level.GamePlayMode == 1 || Self.bDontSwapMeshes)
	{
		return Default.Mesh;
	}
	else
	{
		return EnemyAttachmentClass.Default.Mesh;
	}
	*/
	return nullptr;
}
void ABaseWeaponAttachment::NotifyNewMesh(bool bFriendly)
{
	ABaseWeaponAttachment* NewClass = nullptr;
	Super::NotifyNewMesh(bFriendly);
	/*
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly) || Level.GamePlayMode == 1 || Self.bDontSwapMeshes)
	{
		NewClass=Class;
	}
	else
	{
		NewClass=class<BaseWeaponAttachment>(EnemyAttachmentClass);
		if (NewClass == nullptr)
		{
			DebugLog(DEBUG_Warn,"BaseWeaponAttachment::NotifyNewMesh()	" + this + ": Invalid attachment class " + EnemyAttachmentClass);
			return;
		}
	}
	CleanUp();
	SetupForClass(NewClass);
	*/
}

void ABaseWeaponAttachment::SetupForClass(ABaseWeaponAttachment* NewClass)
{
	_cShellEmitterClass		= GetDefault<ABaseWeaponAttachment>()->_cShellEmitterClass;
	_ShellOffset1P			= GetDefault<ABaseWeaponAttachment>()->_ShellOffset1P;
	_ShellOffset3P			= GetDefault<ABaseWeaponAttachment>()->_ShellOffset3P;
	_ShellDirInfo			= GetDefault<ABaseWeaponAttachment>()->_ShellDirInfo;
	_bDelayShellEject		= GetDefault<ABaseWeaponAttachment>()->_bDelayShellEject;
	_cAuxShellEmitterClass	= GetDefault<ABaseWeaponAttachment>()->_cAuxShellEmitterClass;
	_AuxShellOffset1P		= GetDefault<ABaseWeaponAttachment>()->_AuxShellOffset1P;
	_AuxShellOffset3P		= GetDefault<ABaseWeaponAttachment>()->_AuxShellOffset3P;
	_AuxShellDirInfo		= GetDefault<ABaseWeaponAttachment>()->_AuxShellDirInfo;
	_bAuxDelayShellEject	= GetDefault<ABaseWeaponAttachment>()->_bAuxDelayShellEject;
	_cMuzzleFlashClass		= GetDefault<ABaseWeaponAttachment>()->_cMuzzleFlashClass;
	_MuzzleOffset			= GetDefault<ABaseWeaponAttachment>()->_MuzzleOffset;
	_cAuxMuzzleFlashClass	= GetDefault<ABaseWeaponAttachment>()->_cAuxMuzzleFlashClass;
	_AuxMuzzleOffset		= GetDefault<ABaseWeaponAttachment>()->_AuxMuzzleOffset;
	SupportedStaticMesh		= GetDefault<ABaseWeaponAttachment>()->SupportedStaticMesh;
}

FName ABaseWeaponAttachment::GetPawnReloadAnimation()
{
	if (Cast<AAGP_Pawn>(Base)->bIsProne)
	{
		return PawnPrnReloadAnimation;
	}
	else
	{
		return PawnStdReloadAnimation;
	}
}
void ABaseWeaponAttachment::PlayAttachmentReload(int32 SpecialReload)
{
}

AActor* ABaseWeaponAttachment::GetSource()
{
	/*
	if (GetInstigator() == nullptr || GetInstigator()->isDead())
	{
		return nullptr;
	}
	*/
	return GetInstigator();
}
bool ABaseWeaponAttachment::CanHaveMILES()
{
	return bAttachMILES;
}
void ABaseWeaponAttachment::SetLaser()
{
	/*
	Log("BaseWeaponAttachment(" + this + ") received SetLaser() event notification from server.");
	if (LaserSight == nullptr)
	{
		Log("Creating LaserProjector instance");
		LaserSight=Spawn('LaserProjector',Self,"None",Location);
		if (LaserSight == nullptr)
		{
			Log("Couldn't create LaserProjector object.");
			return;
		}
	}
	if (bLaserOn)
	{
		LaserSight.TurnOn(this);
		Log("BaseWeaponAttachment(" + this + ") turning 3rd-person laser on.");
	}
	else
	{
		LaserSight.TurnOff();
		Log("BaseWeaponAttachment(" + this + ") turning 3rd-person laser off.");
	}
	*/
}
void ABaseWeaponAttachment::NotifyWeaponAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	/*
	if (DrawType == 2)
	{
		if (HasAnim(Sequence))
		{
			if (bLoop)
			{
				LoopAnim(Sequence,Rate,TweenTime);
			}
			else
			{
				PlayAnim(Sequence,Rate,TweenTime);
			}
		}
	}
	*/
}
void ABaseWeaponAttachment::NotifyBaseChange()
{
	APawn* p;
	p = Cast<AAGP_Pawn>(Base);
	Super::NotifyBaseChange();
	if (p == NULL)
	{
		if (MILESBox != NULL)
		{
			MILESBox->SetDrawType(EDrawType::DT_None);
		}
		if (BlankPlug != NULL)
		{
			BlankPlug->SetDrawType(EDrawType::DT_None);
		}
	}
	
}
void ABaseWeaponAttachment::AdjustAttachmentFor(AInventory* Inv)
{
	AAGP_Weapon* W = nullptr;
	uint8 NewAnimState = 0;
	W = Cast<AAGP_Weapon>(Inv);
	/*
	if (W == nullptr)
	{
		DebugLog(DEBUG_Warn,"BaseWeaponAttachment::AdjustAttachmentFor()	Unknown Cast<AWeapon>(" @ Inv @ ") for attachment (" @ this @ ")");
		return;
	}
	NewAnimState=128;
	if (W.Instigator.Weapon == W)
	{
		NewAnimState=NewAnimState | 1;
	}
	if (W.IsSupported())
	{
		NewAnimState=NewAnimState | 2;
	}
	if (W.IsSuppressed())
	{
		NewAnimState=NewAnimState | 4;
	}
	if (W.bGuerrillaWeapon)
	{
		NewAnimState=NewAnimState | 8;
	}
	AnimState=AdjustForThirdPersonRounds(NewAnimState,Inv);
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		AttachmentAnimation();
	}
	*/
}

/*
// ======================================================================================
// AGP function - AdjustForThirdPersonRounds
// Checks to see if the third person rounds need adjusted
// input: byte newanimstate - current animstate
// output: byte newanimstate - modified animstate
// Created by: Ramm 09/17/03
// ======================================================================================
*/
uint8 ABaseWeaponAttachment::AdjustForThirdPersonRounds(uint8 NewAnimState, AInventory* Inv)
{
	return NewAnimState;
}

bool ABaseWeaponAttachment::IsAnimState(uint8 test_byte)
{
	//return AnimState & test_byte == test_byte;
	return false;			//FAKE  /EliZ
}
bool ABaseWeaponAttachment::IsNotUS(APawn* p)
{
	/*
	AAA2_PlayerState* PRI;
	if (p != nullptr)
	{
		PRI=p.PlayerReplicationInfo;
		if (PRI == nullptr)
		{
			return false;
		}
		if (! p.bClientFriend || p.bClientFriend && PRI.bGuerrillaPS || p.bClientFriend && PRI.bSpecialForcesPS && ! PRI.bQualifiedSF)
		{
			return true;
		}
	}
	*/
	return false;
}
void ABaseWeaponAttachment::AttachmentAnimation()
{
	AAGP_Pawn* p = nullptr;
	AInventory* W = nullptr;
	Super::AttachmentAnimation();
	/*
	if (Level.GamePlayMode == 1 && CanHaveMILES())
	{
		SpawnMILESAttachments();
		AttachToMe(MILESBox);
		AttachToMe(BlankPlug);
	}
	p=Cast<AAGP_Pawn>(Base);
	if (p != nullptr)
	{
		if (IsAnimState(1))
		{
			p.AttachToBone(this,'WeaponBone');
			Self.SetRelativeLocation(FVector(0,0,0));
			SetDrawType(Default.DrawType);
			bCurrentlySelectedAttachment=true;
		}
		else
		{
			W=p.getAltShoulderInventory();
			p.AttachToBone(this,'RSlungWeapon');
			if (W == nullptr)
			{
				if (IsNotUS(p))
				{
					Self.SetRelativeLocation(_WeaponOffset3P);
				}
			}
			else
			{
				if (IsNotUS(p))
				{
					Self.SetRelativeLocation(_WeaponOffset3P + FVector(0 -2 0));
				}
				else
				{
					Self.SetRelativeLocation(FVector(0 -2 0));
				}
			}
			SetDrawType(Default.DrawType);
			bCurrentlySelectedAttachment=false;
		}
	}
	if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		if (IsAnimState(2))
		{
			if (SupportedStaticMesh != nullptr)
			{
				NormalStaticMesh=StaticMesh;
				SetStaticMesh(SupportedStaticMesh);
			}
		}
		else
		{
			if (StaticMesh == SupportedStaticMesh)
			{
				SetStaticMesh(NormalStaticMesh);
			}
		}
		if (IsAnimState(8))
		{
			if (! bDontSwapMeshes)
			{
				bDontSwapMeshes=true;
				SetMesh();
			}
		}
		else
		{
			if (bDontSwapMeshes)
			{
				bDontSwapMeshes=false;
				SetMesh();
			}
		}
		if (AttachHandler != nullptr)
		{
			AttachHandler.NotifyModAttachmentAnimation(AnimState);
		}
	}
	*/
}

ABaseModAttachment* ABaseWeaponAttachment::GetSuppressor()
{
	ABaseModAttachment* BM = nullptr;
	if (AttachHandler != nullptr)
	{
		for (BM = AttachHandler->ModAttachmentList; BM != nullptr; BM = BM->NextModAttachment)
		{
			if (BM != nullptr)
			{
				if (BM->IsSuppressor())
				{
					return BM;
				}
			}
		}
	}
	return nullptr;
}

void ABaseWeaponAttachment::SpawnModAttachments(AAGP_Weapon* W)
{
	if (W->WeaponModList != nullptr)
	{
		//AttachHandler = Spawn(AAttachmentHandler::StaticClass());
		AttachHandler->SetupHandler(this, GetInstigator(), W);
	}
}

void ABaseWeaponAttachment::SpawnMILESAttachments()
{
	AInventoryAttachment* iclass = nullptr;
	/*
	if (MILESBox == nullptr)
	{
		iclass=class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.WAttch_MILESBox",Class'Class'));
		MILESBox=Spawn(iclass,GetSource());
	}
	if (BlankPlug == nullptr)
	{
		iclass=class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.WAttch_BlankPlug",Class'Class'));
		BlankPlug=Spawn(iclass,GetSource());
	}
	*/
}

void ABaseWeaponAttachment::AttachToMe(AInventoryAttachment* att)
{
	/*
	if (IsAnimState(1))
	{
		GetSource().AttachToBone(att,'WeaponBone');
	}
	else
	{
		GetSource().AttachToBone(att,'RSlungWeapon');
	}
	att.SetRelativeLocation(_MuzzleOffset.VOffset);
	att.SetRelativeRotation(RelativeRotation);
	att.SetDrawType(DrawType);
	*/
}

void ABaseWeaponAttachment::Destroyed()
{
	Super::Destroyed();
	CleanUp();
}

void ABaseWeaponAttachment::CleanUp()
{
	if (_MuzzleFlashEmitter != NULL)
	{
		//_MuzzleFlashEmitter->Destroy();
		_MuzzleFlashEmitter=NULL;
	}
	if (_AuxMuzzleFlashEmitter != NULL)
	{
		//_AuxMuzzleFlashEmitter->Destroy();
		_AuxMuzzleFlashEmitter=NULL;
	}
	if (_ShellEmitter != NULL)
	{
		//_ShellEmitter->DestroySoon();
		_ShellEmitter= NULL;
	}
	if (_AuxShellEmitter != NULL)
	{
		//_AuxShellEmitter->DestroySoon();
		_AuxShellEmitter= NULL;
	}
	/*
	if (LaserSight != NULL)
	{
		LaserSight->TurnOff();
		LaserSight->Destroy();
		LaserSight= NULL;
	}
	*/
	if (MILESBox != NULL)
	{
		MILESBox->Destroy();
		MILESBox= NULL;
	}
	if (BlankPlug != NULL)
	{
		BlankPlug->Destroy();
		BlankPlug= NULL;
	}
	/*
	if (AttachHandler != NULL)
	{
		AttachHandler->Destroy();
		AttachHandler= NULL;
	}
	*/
}
void ABaseWeaponAttachment::InitFor(AInventory* i)
{
	//Instigator=i.Instigator;
}

ABaseShellEmitter* ABaseWeaponAttachment::GetShellEmitter()
{
	/*
	if (FiringMode != 'ROF_SingleGren')
	{
		if (_ShellEmitter == nullptr)
		{
			SpawnShellEmitters();
		}
		return _ShellEmitter;
	}
	else
	{
		if (_AuxShellEmitter == nullptr)
		{
			SpawnShellEmitters();
		}
		return _AuxShellEmitter;
	}
	*/
	return nullptr;    //FAKE   /EliZ
}

bool ABaseWeaponAttachment::GetDelayShellEject()
{
	if (FiringMode != "ROF_SingleGren")
	{
		return _bDelayShellEject;
	}
	else
	{
		return _bAuxDelayShellEject;
	}
}
void ABaseWeaponAttachment::SpawnShellEmitters()
{
	AActor* AttachTo3P = nullptr;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		return;
	}
	/*
	if (_ShellEmitter == nullptr && _cShellEmitterClass != nullptr)
	{
		if (DrawType == 2 && HasBone(_ShellOffset3P.nBone))
		{
			AttachTo3P=Self;
		}
		else
		{
			AttachTo3P=Instigator;
		}
		_ShellEmitter=Spawn(_cShellEmitterClass,GetSource());
		_ShellEmitter.Initialize(_ShellDirInfo,_ShellOffset1P,_ShellOffset3P,AttachTo3P);
	}
	if (_AuxShellEmitter == nullptr && _cAuxShellEmitterClass != nullptr)
	{
		if (DrawType == 2 && HasBone(_AuxShellOffset3P.nBone))
		{
			AttachTo3P=Self;
		}
		else
		{
			AttachTo3P=Instigator;
		}
		_AuxShellEmitter=Spawn(_cAuxShellEmitterClass,GetSource());
		_AuxShellEmitter.Initialize(_AuxShellDirInfo,_AuxShellOffset1P,_AuxShellOffset3P,AttachTo3P);
	}
	*/
}
void ABaseWeaponAttachment::SpawnMuzzleFlashEmitters()
{
	AActor* AttachTo = nullptr;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
	{
		return;
	}
	/*
	if (DrawType == 2 && HasBone(_MuzzleOffset.nBone))
	{
		AttachTo=Self;
	}
	else
	{
		AttachTo=GetSource();
	}
	if (_MuzzleFlashEmitter == nullptr && _cMuzzleFlashClass != nullptr)
	{
		_MuzzleFlashEmitter=Spawn(_cMuzzleFlashClass,GetSource());
		_MuzzleFlashEmitter.bRenderAttachmentSeperately=true;
		AttachTo.AttachToBoneOffset(_MuzzleFlashEmitter,_MuzzleOffset);
	}
	if (_AuxMuzzleFlashEmitter == nullptr && _cAuxMuzzleFlashClass != nullptr)
	{
		_AuxMuzzleFlashEmitter=Spawn(_cAuxMuzzleFlashClass,GetSource());
		_AuxMuzzleFlashEmitter.bRenderAttachmentSeperately=true;
		AttachTo.AttachToBoneOffset(_AuxMuzzleFlashEmitter,_AuxMuzzleOffset);
	}
	*/
}

ABaseMuzzleFlashEmitter* ABaseWeaponAttachment::GetMuzzleFlashEmitter()
{
	/*
	if (FiringMode != "ROF_SingleGren")
	{
		if (GetSuppressor() != nullptr && GetSuppressor()->IsSuppressed())
		{
			return GetSuppressor()->GetSuppressorMuzzleFlash();
		}
		if (_MuzzleFlashEmitter == nullptr)
		{
			SpawnMuzzleFlashEmitters();
		}
		return _MuzzleFlashEmitter;
	}
	else
	{
		if (_AuxMuzzleFlashEmitter == nullptr)
		{
			SpawnMuzzleFlashEmitters();
		}
		return _AuxMuzzleFlashEmitter;
	}
	*/
	return nullptr;   //FAKE   /EliZ
}

bool ABaseWeaponAttachment::DoDelayedShell()
{
	return FlashCount == 255;
}
void ABaseWeaponAttachment::ThirdPersonEffects()
{
	/*
		AHumanController* HC = nullptr;
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			HC=Cast<AHumanController>(Level.GetClientController());
			if (GetSource() == nullptr || HC == nullptr)
			{
				return;
			}
			if (GetSource()->IsA(APawn::StaticClass()))
			{
				Cast<APawn>(GetSource()).PlayFiring(1,FiringMode);
			}
			if (DoDelayedShell() || ! GetDelayShellEject())
			{
				ThirdPersonEffectsEject(HC);
			}
			if (! DoDelayedShell())
			{
				ThirdPersonEffectsMuzzleFlash(HC);
			}
		}
	*/
}
void ABaseWeaponAttachment::ThirdPersonEffectsEject(AHumanController* HC)
{
	ABaseShellEmitter* SE = nullptr;
	bool bFirstPerson = false;
	/*
	if (HC.bNoClientSideEffects)
	{
		return;
	}
	SE=GetShellEmitter();
	if (SE != nullptr)
	{
		bFirstPerson=! HC.bBehindView && HC.ViewTarget == GetSource();
		SE.Eject(bFirstPerson);
	}
	*/
}

void ABaseWeaponAttachment::ThirdPersonEffectsMuzzleFlash(AHumanController* HC)
{
	ABaseMuzzleFlashEmitter* MFE = nullptr;
	int32 i = 0;
	bool bFirstPerson = false;
	/*
	bFirstPerson=HC.bBehindView == false && HC.ViewTarget == GetSource() && HC.IsInState('Manning_Turret') == false;
	if (! bFirstPerson)
	{
		MFE=GetMuzzleFlashEmitter();
		if (MFE != nullptr)
		{
			for (i=0; i<MFE.EmitterCount(); i++)
			{
				MFE.Emitters[i].SpawnParticle(MFE.Emitters[i].iFlashSpawnCount);
			}
			MFE.DynamicFlash();
		}
	}
	*/
}

bool ABaseWeaponAttachment::ShouldDoTraceEffects()
{
	AHumanController* HC = nullptr;
	/*
	if (Level.GamePlayMode == 0 && GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		HC=Cast<AHumanController>(Level.GetClientController());
		if (HC != nullptr && ! HC.bNoClientSideEffects)
		{
			return true;
		}
	}
	*/
	return false;
}
void ABaseWeaponAttachment::ThirdPersonTrace()
{
	AActor* TraceSource = nullptr;
	/*
	if (! ShouldDoTraceEffects())
	{
		return;
	}
	TraceSource=GetSource();
	if (TraceSource == nullptr || TraceSource != nullptr && TraceSource.bDeleteMe)
	{
		return;
	}
	DoEffectTrace(TraceSource,PVtoV(BulletTrace[0]),0);
	*/
}

bool ABaseWeaponAttachment::DoEffectTrace(AActor* TraceFrom, FVector StartTrace, int32 end_trace, bool bDoExit)
{
	AActor* HitActor = nullptr;
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	UMaterialInstance* HitMaterial = nullptr;
	FBoneInfo HitBone = FBoneInfo({});
	FVector ServerHitLocation = FVector(0, 0, 0);
	FVector EndTrace = FVector(0,0,0);
	bool bNextDoExit = false;
	EBulletImpactType BType = EBulletImpactType::BT_Impact;
	/*
	DebugLog(DEBUG_Bullet,"DoEffectTrace() entered for end_trace: " + end_trace + " and max traces: " + GetMaxBulletTraces());
	if (end_trace == GetMaxBulletTraces() - 1)
	{
		DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due max bullet traces");
		return false;
	}
	end_trace ++;
	if (! NewPV(BulletTrace[end_trace]))
	{
		DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due to empty bullettrace entry");
		return false;
	}
	ServerHitLocation=PVtoV(BulletTrace[end_trace]);
	EndTrace=ServerHitLocation - StartTrace * 1.1 + StartTrace;
	if (TraceFrom == nullptr || TraceFrom.bDeleteMe || Instigator.isDead())
	{
		DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due TraceFrom or instigator being dead");
		return false;
	}
	HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,false);
	if (HitMaterial == nullptr)
	{
		DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due to no hit material");
		return false;
	}
	if (HitActor == nullptr || HitActor != nullptr && HitActor.bDeleteMe)
	{
		DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due to no hitactor");
		return false;
	}
	BType=GetBulletImpactType(end_trace);
	if (BType == 1)
	{
		bNextDoExit=true;
		BType=0;
	}
	if (bDoExit)
	{
		DebugLog(DEBUG_Bullet,"DoEffectTrace() performing bulletexittrace call");
		BulletExitTrace(HitActor,HitLocation,StartTrace);
	}
	DebugLog(DEBUG_Bullet,"DoEffectTrace() performing DoBulletEffect call");
	DoBulletEffect(HitActor,HitMaterial,HitLocation,HitNormal,BType);
	if (end_trace < GetMaxBulletTraces())
	{
		DebugLog(DEBUG_Bullet,"DoEffectTrace() recursing");
		DoEffectTrace(HitActor,ServerHitLocation,end_trace,bNextDoExit);
	}
	DebugLog(DEBUG_Bullet,"DoEffectTrace() finished, exiting");
	*/
	return false;
}

void ABaseWeaponAttachment::BulletExitTrace(AActor* TraceFrom, FVector StartTrace, FVector EndTrace)
{
	AActor* HitActor = nullptr;
	FVector HitLocation = FVector(0,0,0);
	FVector HitNormal = FVector(0, 0, 0);
	UMaterialInstance* HitMaterial = nullptr;
	FBoneInfo HitBone = FBoneInfo({});
	if (TraceFrom != nullptr)
	{
		//HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,false);
	}
	//DoBulletEffect(HitActor,HitMaterial,HitLocation,HitNormal,1);
}

EBulletImpactType ABaseWeaponAttachment::GetBulletImpactType(int32 trace_index)
{
	return BulletImpact[trace_index - 1];
}

void ABaseWeaponAttachment::SetBulletImpactType(int32 trace_index, EBulletImpactType new_type)
{
	BulletImpact[trace_index - 1]=new_type;
}
void ABaseWeaponAttachment::DoBulletEffect(AActor* HitActor, UTexture2D* HitMaterial, FVector HitLocation, FVector HitNormal, EBulletImpactType BType)
{
	/*
	if (HitActor != nullptr && HitMaterial != nullptr && HitMaterial.Outer != nullptr)
	{
		HitMaterial.PlayBulletContactSound(GetSource(),HitLocation,HitNormal,BType);
		HitMaterial.PlayBulletContactProjector(HitActor,HitLocation,HitNormal,BType);
		HitMaterial.PlayBulletContactEmitter(GetSource(),HitLocation,HitNormal,BType);
	}
	*/
}
