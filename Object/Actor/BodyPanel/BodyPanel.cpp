// All the original content belonged to the US Army


#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"

// Sets default values
ABodyPanel::ABodyPanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//ExplosionDamageThreshholds = (0,100,200);
	//CollisionDamageThreshholds = (0, 200, 400);
	//ProjectileDamageThreshholds = (0, 100, 200);

	//DamagedTexture(0) = Texture'T_AAO_Vehicles.HMMWV1114.t_vehi_HMMWV1114_exterior_01a';
	//DamagedTexture(1) = Texture'T_AAO_Vehicles.HMMWV1114.t_vehi_HMMWV1114_exterior_01b';
	//DamagedTexture(2) = Texture'T_AAO_Vehicles.HMMWV1114.t_vehi_HMMWV1114_exterior_01c';
	//DamagedMesh(0) = class'None';
	//DamagedMesh(1) = class'None';
	//DamagedMesh(2) = class'None';
	//DrawType = 8;
	//StaticMesh = StaticMesh'M_AAO_Vehicles.HMMWV1114.m_vehi_HMMWV1114_Door_LF_01a';
	//bUseDynamicLights = true;
	//DrawScale = 1.13;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bCollideActors = true;
	//bBlockActors = true;
	//bProjTarget = true;
	//bUseCollisionStaticMesh = true;
}

// Called when the game starts or when spawned
void ABodyPanel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABodyPanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABodyPanel::PostBeginPlay()
{
	/*
	DebugLog(DEBUG_Vehicle, "BodyPanel::PostBeginPlay StaticMesh=" $ StaticMesh);
	SetBase(Owner);
	if (EntryRadius >= 1)
	{
		bDoHighlight = true;
	}
	*/
}
void ABodyPanel::PostNetBeginPlay()
{
	/*
	PostNetBeginPlay();
	SetRelativeRotation(RelRotation);
	Disable('Tick');
	*/
}
void ABodyPanel::FindEntryVehicle(APawn* p)
{
	/*
	DebugLog(DEBUG_Vehicle, "BODYPANEL::Trying to find Vehicle with " $ Self);
	if (VSize(p.Location - Owner.GetBoneCoords(EntryBone).Origin) <= EntryRadius)
	{
		Return EntryVehicle;
	}
	Return None;
	*/
}
void ABodyPanel::AddLinkedPanel(ABodyPanel* PanelToLink)
{
	/*
	LinkedPanels.insert(0, 1);
	LinkedPanels[0] = PanelToLink;
	*/
}
void ABodyPanel::UsedBy(APawn* User)
{
	/*
	DebugLog(DEBUG_Vehicle, "Used by Called for BodyPanel:" $ PanelID);
	if (EntryVehicle != None)
	{
		Return EntryVehicle.PanelUsedBy(User, PanelID);
	}
	else
	{
		Return False;
	}
	*/
}
/*
void ABodyPanel::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance HitMaterial)
{
	local int i;
	if (!bInvincible)
	{
		DebugLog(DEBUG_Vehicle, "Panel " $ PanelID $ " taking damage on bone: " $ Bone.Name $ ", owner: " $ Owner $ " vehicle: " $ EntryVehicle);
		if (EntryVehicle == None && Owner != None)
		{
			DebugLog(DEBUG_Vehicle, "Damage on body pane: " $ PanelID);
			Owner.GetVehicleWeaponDamageModifier(PanelID, DamageType, Damage, HitLocation, Bone);
			for (i = 0; i < LinkedPanels.Length; i++)
			{
				Owner.GetVehicleWeaponDamageModifier(LinkedPanels[i].PanelID, DamageType, Damage, HitLocation, Bone);
			}
			Return;
		}
		EntryVehicle.GetDamageModifier(PanelID, DamageType, Damage);
	}
}
*/

void ABodyPanel::HandleDamage(int32 Damage, eBodyPanelDamageType BPDT)
{
	/*
	local int idx;
	idx = 0;
	Switch(BPDT)
	{
			case 0:
				if (bAcceptsProjectileDamage)
				{
					ProjectileDamage += Damage;
					if (idx < ProjectileDamageThreshholds.Length)
					{
						if (ProjectileDamage <= ProjectileDamageThreshholds[idx])
						{
							idx--;
							break;
						}
						idx++;
					}
				}
				if (idx >= ProjectileDamageThreshholds.Length)
				{
					idx = ProjectileDamageThreshholds.Length - 1;
				}
	}
	GOTO JL015E;
		case 1:
			ExplosionDamage += Damage;
			if (idx < ExplosionDamageThreshholds.Length)
			{
				if (ExplosionDamage <= ExplosionDamageThreshholds[idx])
				{
					idx--;
				}
				else
				{
					idx++;
				}
			}
			if (idx >= ExplosionDamageThreshholds.Length)
			{
				idx = ExplosionDamageThreshholds.Length - 1;
			}
			GOTO JL015E;
		case 2:
			CollisionDamage += Damage;
			if (idx < CollisionDamageThreshholds.Length)
			{
				if (CollisionDamage <= CollisionDamageThreshholds[idx])
				{
					idx--;
				}
				else
				{
					idx++;
				}
			}
			if (idx >= CollisionDamageThreshholds.Length)
			{
				idx = CollisionDamageThreshholds.Length - 1;
			}
			GOTO JL015E;
		default:
		JL015E:
			if (idx > DamageIndex)
			{
				if (EntryVehicle != None)
				{
					EntryVehicle.NotifyVehiclePanelDamaged(PanelID, idx);
				}
				DamageIndex = idx;
				RefreshDamageState();
			}
			if (DamageIndex >= ProjectileDamageThreshholds.Length - 1 || DamageIndex >= ExplosionDamageThreshholds.Length - 1 || DamageIndex >= CollisionDamageThreshholds.Length - 1 && !bIsDestroyed)
			{
				if (PanelID <= 3 && DamageIndex < ExplosionDamageThreshholds.Length - 1)
				{
					bIsDestroyed = False;
				}
				else
				{
					bIsDestroyed = true;
				}
				if (EntryVehicle != None)
				{
					EntryVehicle.NotifyVehiclePanelDestroyed(PanelID);
				}
			}
	*/
}
void ABodyPanel::PostNetReceive()
{
	RefreshDamageState();
}
void ABodyPanel::RefreshDamageState()
{
	/*
	if (DamageIndex != LastDamageIndex)
	{
		SwapTexture(DamagedTexture[DamageIndex]);
		SetStaticMesh(DamagedMesh[DamageIndex]);
		LastDamageIndex = DamageIndex;
	}
*/
}
void ABodyPanel::SwapTexture(UMaterialInstance* NewTexture)
{
	/*
	if (Level.NetMode == 0)
	{
		Skins[0] = NewTexture;
	}
	else
	{
		RepSkin = NewTexture;
	}
	*/
}