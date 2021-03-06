// All the original content belonged to the US Army

#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

// Sets default values
ABodyPanel::ABodyPanel()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ExplosionDamageThreshholds = {
		0,
		100,
		200
	};
	CollisionDamageThreshholds = {
		0,
		200,
		400
	};
	ProjectileDamageThreshholds = {
		0,
		100,
		200
	};
	DamagedTexture = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/HMMWV1114/t_vehi_HMMWV1114_exterior_01a_Mat.t_vehi_HMMWV1114_exterior_01a_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/HMMWV1114/t_vehi_HMMWV1114_exterior_01b_Mat.t_vehi_HMMWV1114_exterior_01b_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_Vehicles/HMMWV1114/t_vehi_HMMWV1114_exterior_01c_Mat.t_vehi_HMMWV1114_exterior_01c_Mat'"), NULL, LOAD_None, NULL)
	};
	DamagedMesh = {
		nullptr,
		nullptr,
		nullptr
	};
	//DrawType = DT_StaticMesh;
	//StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AAO_Vehicles/HMMWV1114/m_vehi_HMMWV1114_Door_LF_01a.m_vehi_HMMWV1114_Door_LF_01a'"), NULL, LOAD_None, NULL);
	//bUseDynamicLights = true;
	//DrawScale = 1.13;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bCollideActors = true;
	//bBlockActors = true;
	//bProjTarget = true;
	//bUseCollisionStaticMesh = true;

	PassengerHintText.SetNum(8);
}

void ABodyPanel::BeginPlay()
{
	Super::BeginPlay();
	
}


void ABodyPanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABodyPanel::PostBeginPlay()
{
	/*
	DebugLog(DEBUG_Vehicle, "BodyPanel::PostBeginPlay StaticMesh=" + StaticMesh);
	SetBase(GetOwner());
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

AVehicle* ABodyPanel::FindEntryVehicle(APawn* p)
{
	/*
	DebugLog(DEBUG_Vehicle, "BODYPANEL::Trying to find Vehicle with " + Self);
	if (VSize(p.Location - Owner.GetBoneCoords(EntryBone).Origin) <= EntryRadius)
	{
		return EntryVehicle;
	}
	*/
	return nullptr;
}
void ABodyPanel::AddLinkedPanel(ABodyPanel* PanelToLink)
{
	/*
	LinkedPanels.insert(0, 1);
	LinkedPanels[0] = PanelToLink;
	*/
}
bool ABodyPanel::UsedBy(APawn* User)
{
	/*
	DebugLog(DEBUG_Vehicle, "Used by Called for BodyPanel:" + PanelID);
	if (EntryVehicle != nullptr)
	{
		return EntryVehicle.PanelUsedBy(User, PanelID);
	}
	else
	{
		return false;
	}
	*/
	return false;   //FAKE   /EliZ
}
/*
void ABodyPanel::TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance HitMaterial)
{
	int32 i = 0;
	if (!bInvincible)
	{
		DebugLog(DEBUG_Vehicle, "Panel " + PanelID + " taking damage on bone: " + Bone.Name + ", owner: " + Owner + " vehicle: " + EntryVehicle);
		if (EntryVehicle == nullptr && Owner != nullptr)
		{
			DebugLog(DEBUG_Vehicle, "Damage on body pane: " + PanelID);
			Owner.GetVehicleWeaponDamageModifier(PanelID, DamageType, Damage, HitLocation, Bone);
			for (i = 0; i < LinkedPanels.Num(); i++)
			{
				Owner.GetVehicleWeaponDamageModifier(LinkedPanels[i].PanelID, DamageType, Damage, HitLocation, Bone);
			}
			return;
		}
		EntryVehicle.GetDamageModifier(PanelID, DamageType, Damage);
	}
}
*/

void ABodyPanel::HandleDamage(int32 Damage, eBodyPanelDamageType BPDT)
{
	/*
	int32 idx;
	idx = 0;
	switch(BPDT)
	{
			case 0:
				if (bAcceptsProjectileDamage)
				{
					ProjectileDamage += Damage;
					if (idx < ProjectileDamageThreshholds.Num())
					{
						if (ProjectileDamage <= ProjectileDamageThreshholds[idx])
						{
							idx--;
							break;
						}
						idx++;
					}
				}
				if (idx >= ProjectileDamageThreshholds.Num())
				{
					idx = ProjectileDamageThreshholds.Num() - 1;
				}
	}
	GOTO JL015E;
		case 1:
			ExplosionDamage += Damage;
			if (idx < ExplosionDamageThreshholds.Num())
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
			if (idx >= ExplosionDamageThreshholds.Num())
			{
				idx = ExplosionDamageThreshholds.Num() - 1;
			}
			GOTO JL015E;
		case 2:
			CollisionDamage += Damage;
			if (idx < CollisionDamageThreshholds.Num())
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
			if (idx >= CollisionDamageThreshholds.Num())
			{
				idx = CollisionDamageThreshholds.Num() - 1;
			}
			GOTO JL015E;
		default:
		JL015E:
			if (idx > DamageIndex)
			{
				if (EntryVehicle != nullptr)
				{
					EntryVehicle.NotifyVehiclePanelDamaged(PanelID, idx);
				}
				DamageIndex = idx;
				RefreshDamageState();
			}
			if (DamageIndex >= ProjectileDamageThreshholds.Num() - 1 || DamageIndex >= ExplosionDamageThreshholds.Num() - 1 || DamageIndex >= CollisionDamageThreshholds.Num() - 1 && !bIsDestroyed)
			{
				if (PanelID <= 3 && DamageIndex < ExplosionDamageThreshholds.Num() - 1)
				{
					bIsDestroyed = false;
				}
				else
				{
					bIsDestroyed = true;
				}
				if (EntryVehicle != nullptr)
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
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		Skins[0] = NewTexture;
	}
	else
	{
		RepSkin = NewTexture;
	}
	*/
}
