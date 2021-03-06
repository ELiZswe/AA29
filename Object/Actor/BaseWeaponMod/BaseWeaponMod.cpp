// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/BaseModAttachment/BaseModAttachment.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

// Sets default values
ABaseWeaponMod::ABaseWeaponMod()
{
	ModScopeTexSize.SetNum(4);
	ValidSlot.SetNum(6);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ModSlot              = -1;
	FillExtraSlot        = -1;
	modname              = "NAME NOT SET";
	bOnlyDrawIfAttached  = true;
}


void ABaseWeaponMod::BeginPlay()
{
	Super::BeginPlay();
}


void ABaseWeaponMod::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if (GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		return;
	}
	IncrementCounter();
	*/
}

void ABaseWeaponMod::PostNetBeginPlay()
{
	GetModAttachment();
	//Super::PostNetBeginPlay();
}

FString ABaseWeaponMod::GetActorLevelSkin(int32 Index, UTexture2D* old_material, FString level_tag)
{
	/*
	if (bCanSwapLense && Index == 1)
	{
		if (Cast<AHumanController>(weap.Instigator.Controller).bUseOverlayScopes)
		{
			return "" + StandardLensTexture;
		}
		else
		{
			return "" + ScriptedLensTexture;
		}
	}
	else
	{
		return GetActorLevelSkin(Index,old_material,level_tag);
	}
	*/
	return "FAKE";   //FAKE   /ELiZ
}

ABaseModAttachment* ABaseWeaponMod::GetModAttachment()
{
	int32 loc = 0;
	FString mod_name = "";
	FString attch_name = "";
	FString front = "";
	FString back = "";
	ABaseModAttachment* ModAttachment = nullptr;
	/*
	mod_name=Default.Class;
	loc=InStr(mod_name,"WeaponMod_");
	front=Left(mod_name,loc);
	back=Mid(mod_name,loc + Len("WeaponMod_"),Len(mod_name));
	attch_name=front + "AttachMod_" + back;
	ModAttachment=class<BaseModAttachment>(DynamicLoadObject(attch_name,Class'Class',True));
	*/
	return ModAttachment;
}

FString ABaseWeaponMod::GetModName()
{
	return GetDefault<ABaseWeaponMod>()->modname;
}

bool ABaseWeaponMod::IsSuppressorReady()
{
	return ! bSuppressorMod || SuppressorState != ESuppressorState::SUPSTATE_None;
}

bool ABaseWeaponMod::IsReplicationComplete()
{
	return weap != nullptr && ModSlot != -1 && IsSuppressorReady();
}
void ABaseWeaponMod::NotifyReplicationComplete()
{
	weap->AddWeaponMod(this);
	ModifyWeapon();
}
void ABaseWeaponMod::Destroyed()
{
	/*
	if (ModScopeScriptedTexture != nullptr)
	{
		ModScopeScriptedTexture.Client=nullptr;
	}
	if (NextWeaponMod != nullptr)
	{
		NextWeaponMod.Destroy();
	}
	*/
}
bool ABaseWeaponMod::MutuallyExclusive(ABaseWeaponMod* OtherMod)
{
	/*
	int32 i = 0;
	if (ModSlot == OtherMod.ModSlot || WeaponBone == OtherMod.WeaponBone)
	{
		return true;
	}
	if (FillExtraSlot == OtherMod.ModSlot || ModSlot == OtherMod.FillExtraSlot)
	{
		return true;
	}
	for (i=0; i<ExclusiveModsList.Num(); i++)
	{
		if (OtherMod.Class == ExclusiveModsList[i])
		{
			return true;
		}
	}
	for (i=0; i<OtherMod.ExclusiveModsList.Num(); i++)
	{
		if (Class == OtherMod.ExclusiveModsList[i])
		{
			return true;
		}
	}
	*/
	return false;
}
bool ABaseWeaponMod::ModNotAllowed()
{
	return false;    //FAKE    /EliZ
}

bool ABaseWeaponMod::CanAttachToWeapon()
{
	ABaseWeaponMod* WM = nullptr;
	if (ModNotAllowed())
	{
		return false;
	}
	/*
	if (!weap->IsLegalMod(Class))
	{
		return false;
	}
	if (!weap->HasBone(WeaponBone))
	{
		return false;
	}
	if (ValidSlot[ModSlot] == 0)
	{
		return false;
	}
	if (weap.bCanSupport && bSupportMod)
	{
		return false;
	}
	if ((weap.GetSuppressor() != nullptr) && bSuppressorMod)
	{
		return false;
	}
	for (WM = weap.WeaponModList; WM != nullptr; WM = WM.NextWeaponMod)
	{
		if (WM.MutuallyExclusive(this))
		{
			return false;
		}
	}
	*/
	return true;
}

FName ABaseWeaponMod::GetAttachBone(int32 Slot)
{
	if (GetDefault<ABaseWeaponMod>()->WeaponBone != "None" && GetDefault<ABaseWeaponMod>()->WeaponBone != "None")
	{
		return GetDefault<ABaseWeaponMod>()->WeaponBone;
	}
	else
	{
		switch (Slot)
		{
		case 0:
			return "RailMain";
		case 1:
			return "RailTop";
		case 2:
			return "RailLT";
		case 3:
			return "RailRT";
		case 4:
			return "RailBTM";
		case 5:
			return "Suppressor";
		default:
			return "None";
		}
	}
}

bool ABaseWeaponMod::AttachToWeapon(AAGP_Weapon* W, int32 attach_slot)
{
	/*
	weap=W;
	ModSlot=attach_slot;
	WeaponBone=GetAttachBone(ModSlot);
	if (CanAttachToWeapon())
	{
		SetOwner(weap);
		weap.AttachToBone(this,WeaponBone);
		ModifyWeapon();
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
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
			if (weap == nullptr)
			{
				weap=Cast<AAGP_Weapon>(GetOwner());
				if (weap == nullptr)
				{
					weap=Cast<AAGP_Weapon>(Base);
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
		if (Instigator != nullptr && ModScopeScriptedTexture != nullptr && ScopeClass != nullptr)
		{
			switch(Cast<AHumanController>(weap.Instigator.Controller).ScopeDetail)
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
			if (GetRemoteRole() == ENetRole::ROLE_MAX)
			{
				weap.DoSuppressor(weap.IsSuppressed());
			}
			else
			{
				switch(SuppressorState)
				{
					case 1:
					weap.DoSuppressor(true);
					break;
					case 2:
					weap.DoSuppressor(false);
					break;
					default:
					DebugLog(DEBUG_Warn,"BaseWeaponMod::SetupSuppressor()	Invalid SuppressorState (" @ SuppressorState @ ")");
				}
			}
			SetSuppressor();
			if (weap != nullptr && weap.ThirdPersonActor != nullptr)
			{
				BaseWeaponAttachment(weap.ThirdPersonActor).AdjustAttachmentFor(weap);
			}
		}
	*/
}

void ABaseWeaponMod::IncrementCounter()
{
	/*
		if (ModScopeScriptedTexture != nullptr)
		{
			ModScopeScriptedTexture.Client=Self;
			ModScopeScriptedTexture.Revision=ModScopeScriptedTexture.Revision + 1;
		}
	*/
}
/*
void RenderTexture(ScriptedTexture Tex)
{
	if (Owner != nullptr && Tex != nullptr)
	{
		Tex.DrawPortal(0,0,Tex.USize,Tex.VSize,weap.Owner,weap.Get3dScopeLocation(),weap.Get3dScopeRotation(),mFov,true);
	}
}
*/

