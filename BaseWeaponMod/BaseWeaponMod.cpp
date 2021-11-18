// All the original content belonged to the US Army


#include "BaseWeaponMod.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

// Sets default values
ABaseWeaponMod::ABaseWeaponMod()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ModSlot              = -1;
	FillExtraSlot        = -1;
	modname              = "NAME NOT SET";
	bOnlyDrawIfAttached  = true;

}

// Called when the game starts or when spawned
void ABaseWeaponMod::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseWeaponMod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
		if (GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			Return;
		}
		IncrementCounter();
	*/
}

void ABaseWeaponMod::PostNetBeginPlay()
{
	/*
		GetModAttachment();
		PostNetBeginPlay();
	*/
	}

void ABaseWeaponMod::GetActorLevelSkin (int32 Index, UTexture2D* old_material, FString level_tag)
{
/*
	if (bCanSwapLense && Index == 1)
	{
		if (HumanController(weap.Instigator.Controller).bUseOverlayScopes)
		{
			Return "" $ StandardLensTexture;
		}
		else
		{
			Return "" $ ScriptedLensTexture;
		}
	}
	else
	{
		Return GetActorLevelSkin(Index,old_material,level_tag);
	}
*/
}
void ABaseWeaponMod::GetModAttachment()
{
	/*
		local int loc;
		local string mod_name;
		local string attch_name;
		local string front;
		local string back;
		local class<BaseModAttachment>  ModAttachment;
		mod_name=Default.Class;
		loc=InStr(mod_name,"WeaponMod_");
		front=Left(mod_name,loc);
		back=Mid(mod_name,loc + Len("WeaponMod_"),Len(mod_name));
		attch_name=front $ "AttachMod_" $ back;
		ModAttachment=class<BaseModAttachment>(DynamicLoadObject(attch_name,Class'Class',True));
		Return ModAttachment;
	*/
}
void ABaseWeaponMod::GetModName()
{
	/*
		Return Default.modname;
	*/
}
void ABaseWeaponMod::IsSuppressorReady()
{
	/*
		Return ! bSuppressorMod || SuppressorState != 0;
	*/
}
void ABaseWeaponMod::IsReplicationComplete()
{
	/*
		Return weap != None && ModSlot != -1 && IsSuppressorReady();
	*/
}
void ABaseWeaponMod::NotifyReplicationComplete()
{
	/*
		weap.AddWeaponMod(Self);
		ModifyWeapon();
	*/
}
void ABaseWeaponMod::Destroyed()
{
	/*
		if (ModScopeScriptedTexture != None)
		{
			ModScopeScriptedTexture.Client=None;
		}
		if (NextWeaponMod != None)
		{
			NextWeaponMod.Destroy();
		}
	*/
}
void ABaseWeaponMod::MutuallyExclusive(ABaseWeaponMod* OtherMod)
{
	/*
		local int i;
		if (ModSlot == OtherMod.ModSlot || WeaponBone == OtherMod.WeaponBone)
		{
			Return True;
		}
		if (FillExtraSlot == OtherMod.ModSlot || ModSlot == OtherMod.FillExtraSlot)
		{
			Return True;
		}
		for (i=0; i<ExclusiveModsList.Length; i++)
		{
			if (OtherMod.Class == ExclusiveModsList[i])
			{
				Return True;
			}
		}
		for (i=0; i<OtherMod.ExclusiveModsList.Length; i++)
		{
			if (Class == OtherMod.ExclusiveModsList[i])
			{
				Return True;
			}
		}
		Return False;
	*/
}
void ABaseWeaponMod::ModNotAllowed()
{
}
void ABaseWeaponMod::CanAttachToWeapon()
{
	/*
		local BaseWeaponMod WM;
		if (ModNotAllowed())
		{
			Return False;
		}
		if (! weap.IsLegalMod(Class))
		{
			Return False;
		}
		if (! weap.HasBone(WeaponBone))
		{
			Return False;
		}
		if (ValidSlot[ModSlot] == 0)
		{
			Return False;
		}
		if (weap.bCanSupport && bSupportMod)
		{
			Return False;
		}
		if (weap.GetSuppressor() != None && bSuppressorMod)
		{
			Return False;
		}
		WM=weap.WeaponModList;
		if (WM != None)
		{
			if (WM.MutuallyExclusive(Self))
			{
				Return False;
			}
			WM=WM.NextWeaponMod;
		}
		Return True;
	*/
}
void ABaseWeaponMod::GetAttachBone(int32 Slot)
{
	/*
		if (Default.WeaponBone != 'None' && Default.WeaponBone != 'None')
		{
			Return Default.WeaponBone;
		}
		else
		{
			Switch(Slot)
			{
				case 0:
				Return 'RailMain';
				case 1:
				Return 'RailTop';
				case 2:
				Return 'RailLT';
				case 3:
				Return 'RailRT';
				case 4:
				Return 'RailBTM';
				case 5:
				Return 'Suppressor';
				default:
				Return 'None';
			}
		)
	*/
}
void ABaseWeaponMod::AttachToWeapon(AAGP_Weapon* W, int32 attach_slot)
{
	/*
		weap=W;
		ModSlot=attach_slot;
		WeaponBone=GetAttachBone(ModSlot);
		if (CanAttachToWeapon())
		{
			SetOwner(weap);
			weap.AttachToBone(Self,WeaponBone);
			ModifyWeapon();
			Return True;
		}
		else
		{
			Return False;
		}
	*/
}
void ABaseWeaponMod::Toggle()
{
}
bool ABaseWeaponMod::IsSuppressor()
{
	return bSuppressorMod;
}
void ABaseWeaponMod::SetSuppressor()
{
	/*
		if (weap.IsSuppressed())
		{
			SuppressorState=1;
			SetDrawType(Default.DrawType);
		}
		else
		{
			SuppressorState=2;
			SetDrawType(0);
		}
	*/
}
void ABaseWeaponMod::NotifyWeaponAnimation(FName Sequence, float Rate, float TweenTime, bool bLoop)
{
	/*
		if (DrawType == 2 && HasAnim(Sequence))
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
	*/
}
void ABaseWeaponMod::NotifyWeaponZoom(bool bNewZoom)
{
}
void ABaseWeaponMod::ModifyWeapon()
{
	/*
		if (GetNetMode() == ENetMode::NM_Client)
		{
			if (weap == None)
			{
				weap=AGP_Weapon(Owner);
				if (weap == None)
				{
					weap=AGP_Weapon(Base);
				}
			}
		}
		SetupScope();
		SetupSupport();
		SetupSuppressor();
		Setup3dScope();
	*/
}
void ABaseWeaponMod::Setup3dScope()
{
	/*
		if (bUseModZoomOffset)
		{
			weap.vZoomAnimOffset=mZoomAnimOffset;
		}
		if (Instigator != None && ModScopeScriptedTexture != None && ScopeClass != None)
		{
			Switch(HumanController(weap.Instigator.Controller).ScopeDetail)
			{
				case 0:
				ModScopeScriptedTexture.SetSize(ModScopeTexSize[0],ModScopeTexSize[0]);
				break;
				case 1:
				ModScopeScriptedTexture.SetSize(ModScopeTexSize[1],ModScopeTexSize[1]);
				break;
				case 2:
				ModScopeScriptedTexture.SetSize(ModScopeTexSize[2],ModScopeTexSize[2]);
				break;
				case 3:
				ModScopeScriptedTexture.SetSize(ModScopeTexSize[3],ModScopeTexSize[3]);
				break;
				default:
				ModScopeScriptedTexture.SetSize(ModScopeTexSize[1],ModScopeTexSize[1]);
				break;
			}
		}
	*/
}
void ABaseWeaponMod::SetupScope()
{
	if (ScopeClass != NULL)
	{
		Cast<AAGP_Weapon>(weap)->_cScopeClass=ScopeClass;
	}
}
void ABaseWeaponMod::SetupSupport()
{
	if (bSupportMod)
	{
		Cast<AAGP_Weapon>(weap)->bCanSupport=true;
	}
}
void ABaseWeaponMod::SetupSuppressor()
{
	/*
		if (bSuppressorMod)
		{
			if (Role == 4)
			{
				weap.DoSuppressor(weap.IsSuppressed());
			}
			else
			{
				Switch(SuppressorState)
				{
					case 1:
					weap.DoSuppressor(True);
					break;
					case 2:
					weap.DoSuppressor(False);
					break;
					default:
					DebugLog(DEBUG_Warn,"BaseWeaponMod::SetupSuppressor()	Invalid SuppressorState (" @ SuppressorState @ ")");
				}
			}
			SetSuppressor();
			if (weap != None && weap.ThirdPersonActor != None)
			{
				BaseWeaponAttachment(weap.ThirdPersonActor).AdjustAttachmentFor(weap);
			}
		}
	*/
}

void ABaseWeaponMod::IncrementCounter()
{
	/*
		if (ModScopeScriptedTexture != None)
		{
			ModScopeScriptedTexture.Client=Self;
			ModScopeScriptedTexture.Revision=ModScopeScriptedTexture.Revision + 1;
		}
	*/
}
/*
void RenderTexture(ScriptedTexture Tex)
{
	if (Owner != None && Tex != None)
	{
		Tex.DrawPortal(0,0,Tex.USize,Tex.VSize,weap.Owner,weap.Get3dScopeLocation(),weap.Get3dScopeRotation(),mFov,True);
	}
}
*/




