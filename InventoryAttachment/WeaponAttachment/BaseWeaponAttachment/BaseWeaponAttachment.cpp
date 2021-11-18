// All the original content belonged to the US Army


#include "BaseWeaponAttachment.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
	/*
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			Return;
		}
		if (FiringMode != 'ROF_SingleGren')
		{
			if (_ShellEmitter == None)
			{
				SpawnShellEmitters();
			}
		}
		else
		{
			if (_AuxShellEmitter == None)
			{
				SpawnShellEmitters();
			}
		}
	*/
}
void ABaseWeaponAttachment::GetStaticMesh(bool bFriendly)
{
	/*
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly) || Level.GamePlayMode == 1 || Self.bDontSwapMeshes)
		{
			Return Default.StaticMesh;
		}
		else
		{
			Return EnemyAttachmentClass.Default.StaticMesh;
		}
	*/
}
void ABaseWeaponAttachment::GetMesh(bool bFriendly)
{
	/*
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly) || Level.GamePlayMode == 1 || Self.bDontSwapMeshes)
		{
			Return Default.Mesh;
		}
		else
		{
			Return EnemyAttachmentClass.Default.Mesh;
		}
	*/
}
void ABaseWeaponAttachment::NotifyNewMesh(bool bFriendly)
{
	/*
		local class<BaseWeaponAttachment>  NewClass;
		NotifyNewMesh(bFriendly);
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsUSSkin(bFriendly) || Level.GamePlayMode == 1 || Self.bDontSwapMeshes)
		{
			NewClass=Class;
		}
		else
		{
			NewClass=class<BaseWeaponAttachment>(EnemyAttachmentClass);
			if (NewClass == None)
			{
				DebugLog(DEBUG_Warn,"BaseWeaponAttachment::NotifyNewMesh()	" $ Self $ ": Invalid attachment class " $ EnemyAttachmentClass);
				Return;
			}
		}
		CleanUp();
		SetupForClass(NewClass);
	*/
}
void ABaseWeaponAttachment::SetupForClass(ABaseWeaponAttachment* NewClass)
{
	_cShellEmitterClass= GetDefault<ABaseWeaponAttachment>()->_cShellEmitterClass;
	_ShellOffset1P= GetDefault<ABaseWeaponAttachment>()->_ShellOffset1P;
	_ShellOffset3P= GetDefault<ABaseWeaponAttachment>()->_ShellOffset3P;
	_ShellDirInfo= GetDefault<ABaseWeaponAttachment>()->_ShellDirInfo;
	_bDelayShellEject= GetDefault<ABaseWeaponAttachment>()->_bDelayShellEject;
	_cAuxShellEmitterClass= GetDefault<ABaseWeaponAttachment>()->_cAuxShellEmitterClass;
	_AuxShellOffset1P= GetDefault<ABaseWeaponAttachment>()->_AuxShellOffset1P;
	_AuxShellOffset3P= GetDefault<ABaseWeaponAttachment>()->_AuxShellOffset3P;
	_AuxShellDirInfo= GetDefault<ABaseWeaponAttachment>()->_AuxShellDirInfo;
	_bAuxDelayShellEject= GetDefault<ABaseWeaponAttachment>()->_bAuxDelayShellEject;
	_cMuzzleFlashClass= GetDefault<ABaseWeaponAttachment>()->_cMuzzleFlashClass;
	_MuzzleOffset= GetDefault<ABaseWeaponAttachment>()->_MuzzleOffset;
	_cAuxMuzzleFlashClass= GetDefault<ABaseWeaponAttachment>()->_cAuxMuzzleFlashClass;
	_AuxMuzzleOffset= GetDefault<ABaseWeaponAttachment>()->_AuxMuzzleOffset;
	SupportedStaticMesh= GetDefault<ABaseWeaponAttachment>()->SupportedStaticMesh;
}
void ABaseWeaponAttachment::GetPawnReloadAnimation()
{
	/*
		if (AGP_Pawn(Base).bIsProne)
		{
			Return PawnPrnReloadAnimation;
		}
		else
		{
			Return PawnStdReloadAnimation;
		}
	*/
}
void ABaseWeaponAttachment::PlayAttachmentReload(int32 SpecialReload)
{
}
void ABaseWeaponAttachment::GetSource()
{
	/*
		if (Instigator == None || Instigator.isDead())
		{
			Return None;
		}
		Return Instigator;
	*/
}
bool ABaseWeaponAttachment::CanHaveMILES()
{
	return bAttachMILES;
}
void ABaseWeaponAttachment::SetLaser()
{
	/*
		Log("BaseWeaponAttachment(" $ Self $ ") received SetLaser() event notification from server.");
		if (LaserSight == None)
		{
			Log("Creating LaserProjector instance");
			LaserSight=Spawn('LaserProjector',Self,'None',Location);
			if (LaserSight == None)
			{
				Log("Couldn't create LaserProjector object.");
				Return;
			}
		}
		if (bLaserOn)
		{
			LaserSight.TurnOn(Self);
			Log("BaseWeaponAttachment(" $ Self $ ") turning 3rd-person laser on.");
		}
		else
		{
			LaserSight.TurnOff();
			Log("BaseWeaponAttachment(" $ Self $ ") turning 3rd-person laser off.");
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
	/*
		local AGP_Weapon W;
		local byte NewAnimState;
		W=AGP_Weapon(Inv);
		if (W == None)
		{
			DebugLog(DEBUG_Warn,"BaseWeaponAttachment::AdjustAttachmentFor()	Unknown weapon(" @ Inv @ ") for attachment (" @ Self @ ")");
			Return;
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
void ABaseWeaponAttachment::IsAnimState(uint8 test_byte)
{
	/*
		Return AnimState & test_byte == test_byte;
	*/
}
void ABaseWeaponAttachment::IsNotUS(APawn* p)
{
	/*
		local PlayerReplicationInfo PRI;
		if (p != None)
		{
			PRI=p.PlayerReplicationInfo;
			if (PRI == None)
			{
				Return False;
			}
			if (! p.bClientFriend || p.bClientFriend && PRI.bGuerrillaPS || p.bClientFriend && PRI.bSpecialForcesPS && ! PRI.bQualifiedSF)
			{
				Return True;
			}
		}
		Return False;
	*/
}
void ABaseWeaponAttachment::AttachmentAnimation()
{
	/*
		local AGP_Pawn p;
		local Inventory W;
		AttachmentAnimation();
		if (Level.GamePlayMode == 1 && CanHaveMILES())
		{
			SpawnMILESAttachments();
			AttachToMe(MILESBox);
			AttachToMe(BlankPlug);
		}
		p=AGP_Pawn(Base);
		if (p != None)
		{
			if (IsAnimState(1))
			{
				p.AttachToBone(Self,'WeaponBone');
				Self.SetRelativeLocation(vect(0 0 0));
				SetDrawType(Default.DrawType);
				bCurrentlySelectedAttachment=True;
			}
			else
			{
				W=p.getAltShoulderInventory();
				p.AttachToBone(Self,'RSlungWeapon');
				if (W == None)
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
						Self.SetRelativeLocation(_WeaponOffset3P + vect(0 -2 0));
					}
					else
					{
						Self.SetRelativeLocation(vect(0 -2 0));
					}
				}
				SetDrawType(Default.DrawType);
				bCurrentlySelectedAttachment=False;
			}
		}
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			if (IsAnimState(2))
			{
				if (SupportedStaticMesh != None)
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
					bDontSwapMeshes=True;
					SetMesh();
				}
			}
			else
			{
				if (bDontSwapMeshes)
				{
					bDontSwapMeshes=False;
					SetMesh();
				}
			}
			if (AttachHandler != None)
			{
				AttachHandler.NotifyModAttachmentAnimation(AnimState);
			}
		}
	*/
}
void ABaseWeaponAttachment::GetSuppressor()
{
	/*
		local BaseModAttachment BM;
		if (AttachHandler != None)
		{
			BM=AttachHandler.ModAttachmentList;
			if (BM != None)
			{
				if (BM != None)
				{
					if (BM.IsSuppressor())
					{
						Return BM;
					}
				}
				BM=BM.NextModAttachment;
			}
		}
		Return None;
	*/
}
void ABaseWeaponAttachment::SpawnModAttachments(AAGP_Weapon* W)
{
	/*
		if (W.WeaponModList != None)
		{
			AttachHandler=Spawn('AttachmentHandler');
			AttachHandler.SetupHandler(Self,Instigator,W);
		}
	*/
}
void ABaseWeaponAttachment::SpawnMILESAttachments()
{
	/*
		local class<InventoryAttachment>  iclass;
		if (MILESBox == None)
		{
			iclass=class<InventoryAttachment>(DynamicLoadObject("AGP_Inventory.WAttch_MILESBox",Class'Class'));
			MILESBox=Spawn(iclass,GetSource());
		}
		if (BlankPlug == None)
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
	/*
		Instigator=i.Instigator;
	*/
}
void ABaseWeaponAttachment::GetShellEmitter()
{
	/*
		if (FiringMode != 'ROF_SingleGren')
		{
			if (_ShellEmitter == None)
			{
				SpawnShellEmitters();
			}
			Return _ShellEmitter;
		}
		else
		{
			if (_AuxShellEmitter == None)
			{
				SpawnShellEmitters();
			}
			Return _AuxShellEmitter;
		}
	*/
}
void ABaseWeaponAttachment::GetDelayShellEject()
{
	/*
		if (FiringMode != 'ROF_SingleGren')
		{
			Return _bDelayShellEject;
		}
		else
		{
			Return _bAuxDelayShellEject;
		}
	*/
}
void ABaseWeaponAttachment::SpawnShellEmitters()
{
	/*
		local Actor AttachTo3P;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			Return;
		}
		if (_ShellEmitter == None && _cShellEmitterClass != None)
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
		if (_AuxShellEmitter == None && _cAuxShellEmitterClass != None)
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
	/*
		local Actor AttachTo;
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsServer())
		{
			Return;
		}
		if (DrawType == 2 && HasBone(_MuzzleOffset.nBone))
		{
			AttachTo=Self;
		}
		else
		{
			AttachTo=GetSource();
		}
		if (_MuzzleFlashEmitter == None && _cMuzzleFlashClass != None)
		{
			_MuzzleFlashEmitter=Spawn(_cMuzzleFlashClass,GetSource());
			_MuzzleFlashEmitter.bRenderAttachmentSeperately=True;
			AttachTo.AttachToBoneOffset(_MuzzleFlashEmitter,_MuzzleOffset);
		}
		if (_AuxMuzzleFlashEmitter == None && _cAuxMuzzleFlashClass != None)
		{
			_AuxMuzzleFlashEmitter=Spawn(_cAuxMuzzleFlashClass,GetSource());
			_AuxMuzzleFlashEmitter.bRenderAttachmentSeperately=True;
			AttachTo.AttachToBoneOffset(_AuxMuzzleFlashEmitter,_AuxMuzzleOffset);
		}
	*/
}
void ABaseWeaponAttachment::GetMuzzleFlashEmitter()
{
	/*
		if (FiringMode != 'ROF_SingleGren')
		{
			if (GetSuppressor() != None && GetSuppressor().IsSuppressed())
			{
				Return GetSuppressor().GetSuppressorMuzzleFlash();
			}
			if (_MuzzleFlashEmitter == None)
			{
				SpawnMuzzleFlashEmitters();
			}
			Return _MuzzleFlashEmitter;
		}
		else
		{
			if (_AuxMuzzleFlashEmitter == None)
			{
				SpawnMuzzleFlashEmitters();
			}
			Return _AuxMuzzleFlashEmitter;
		}
	*/
}
void ABaseWeaponAttachment::DoDelayedShell()
{
	/*
		Return FlashCount == 255;
	*/
}
void ABaseWeaponAttachment::ThirdPersonEffects()
{
	/*
		local HumanController HC;
		if (GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			HC=HumanController(Level.GetClientController());
			if (GetSource() == None || HC == None)
			{
				Return;
			}
			if (GetSource().IsA('Pawn'))
			{
				Pawn(GetSource()).PlayFiring(1,FiringMode);
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
	/*
		local AGP_Effects.BaseShellEmitter SE;
		local bool bFirstPerson;
		if (HC.bNoClientSideEffects)
		{
			Return;
		}
		SE=GetShellEmitter();
		if (SE != None)
		{
			bFirstPerson=! HC.bBehindView && HC.ViewTarget == GetSource();
			SE.Eject(bFirstPerson);
		}
	*/
}
void ABaseWeaponAttachment::ThirdPersonEffectsMuzzleFlash(AHumanController* HC)
{
	/*
		local AGP_Effects.BaseMuzzleFlashEmitter MFE;
		local int i;
		local bool bFirstPerson;
		bFirstPerson=HC.bBehindView == False && HC.ViewTarget == GetSource() && HC.IsInState('Manning_Turret') == False;
		if (! bFirstPerson)
		{
			MFE=GetMuzzleFlashEmitter();
			if (MFE != None)
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
void ABaseWeaponAttachment::ShouldDoTraceEffects()
{
	/*
		local HumanController HC;
		if (Level.GamePlayMode == 0 && GetNetMode() != ENetMode::NM_DedicatedServer)
		{
			HC=HumanController(Level.GetClientController());
			if (HC != None && ! HC.bNoClientSideEffects)
			{
				Return True;
			}
		}
		Return False;
	*/
}
void ABaseWeaponAttachment::ThirdPersonTrace()
{
	/*
		local Actor TraceSource;
		if (! ShouldDoTraceEffects())
		{
			Return;
		}
		TraceSource=GetSource();
		if (TraceSource == None || TraceSource != None && TraceSource.bDeleteMe)
		{
			Return;
		}
		DoEffectTrace(TraceSource,PVtoV(BulletTrace[0]),0);
	*/
}
void ABaseWeaponAttachment::DoEffectTrace(AActor* TraceFrom, FVector StartTrace, int32 end_trace, bool bDoExit)
{
	/*
		local Actor HitActor;
		local FVector HitLocation;
		local FVector HitNormal;
		local Material HitMaterial;
		local Actor.BoneInfo HitBone;
		local FVector ServerHitLocation;
		local FVector EndTrace;
		local bool bNextDoExit;
		local Object.EBulletImpactType BType;
		DebugLog(DEBUG_Bullet,"DoEffectTrace() entered for end_trace: " $ end_trace $ " and max traces: " $ GetMaxBulletTraces());
		if (end_trace == GetMaxBulletTraces() - 1)
		{
			DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due max bullet traces");
			Return False;
		}
		end_trace ++;
		if (! NewPV(BulletTrace[end_trace]))
		{
			DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due to empty bullettrace entry");
			Return False;
		}
		ServerHitLocation=PVtoV(BulletTrace[end_trace]);
		EndTrace=ServerHitLocation - StartTrace * 1.1 + StartTrace;
		if (TraceFrom == None || TraceFrom.bDeleteMe || Instigator.isDead())
		{
			DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due TraceFrom or instigator being dead");
			Return False;
		}
		HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,False);
		if (HitMaterial == None)
		{
			DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due to no hit material");
			Return False;
		}
		if (HitActor == None || HitActor != None && HitActor.bDeleteMe)
		{
			DebugLog(DEBUG_Bullet,"DoEffectTrace() leaving due to no hitactor");
			Return False;
		}
		BType=GetBulletImpactType(end_trace);
		if (BType == 1)
		{
			bNextDoExit=True;
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
		Return False;
	*/
}
void ABaseWeaponAttachment::BulletExitTrace(AActor* TraceFrom, FVector StartTrace, FVector EndTrace)
{
	/*
		local Actor HitActor;
		local FVector HitLocation;
		local FVector HitNormal;
		local Material HitMaterial;
		local Actor.BoneInfo HitBone;
		if (TraceFrom != None)
		{
			HitActor=TraceFrom.BoneTrace(HitLocation,HitNormal,EndTrace,StartTrace,HitMaterial,HitBone,False);
		}
		DoBulletEffect(HitActor,HitMaterial,HitLocation,HitNormal,1);
	*/
}
void ABaseWeaponAttachment::GetBulletImpactType(int32 trace_index)
{
	/*
		Return BulletImpact[trace_index - 1];
	*/
}
void ABaseWeaponAttachment::SetBulletImpactType(int32 trace_index, EBulletImpactType new_type)
{
	/*
		BulletImpact[trace_index - 1]=new_type;
	*/
}
void ABaseWeaponAttachment::DoBulletEffect(AActor* HitActor, UTexture2D* HitMaterial, FVector HitLocation, FVector HitNormal, EBulletImpactType BType)
{
	/*
		if (HitActor != None && HitMaterial != None && HitMaterial.Outer != None)
		{
			HitMaterial.PlayBulletContactSound(GetSource(),HitLocation,HitNormal,BType);
			HitMaterial.PlayBulletContactProjector(HitActor,HitLocation,HitNormal,BType);
			HitMaterial.PlayBulletContactEmitter(GetSource(),HitLocation,HitNormal,BType);
		}
	*/
}