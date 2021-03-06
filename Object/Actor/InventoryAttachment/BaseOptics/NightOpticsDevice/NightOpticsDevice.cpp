// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/BaseOptics/NightOpticsDevice/NightOpticsDevice.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "Engine/Canvas.h"

// Sets default values
ANightOpticsDevice::ANightOpticsDevice()
{
	RandArray.SetNum(5);
	SwitchOnSound		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Foley/Nightvision/NOD_on_Cue.NOD_on_Cue'"), NULL, LOAD_None, NULL);
	SwitchOffSound		= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Foley/Nightvision/NOD_off_Cue.NOD_off_Cue'"), NULL, LOAD_None, NULL);
	NightVisionTexture	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Optics/Nightvision1_Mat.Nightvision1_Mat'"), NULL, LOAD_None, NULL);
	NightVisionOverlay	= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Optics/Nightvision_overlay_Mat.Nightvision_overlay_Mat'"), NULL, LOAD_None, NULL);
	NVG_Up				= LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-nvg_up.m-nvg_up'"), NULL, LOAD_None, NULL);
	NVG_Down			= LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-nvg_dwn.m-nvg_dwn'"), NULL, LOAD_None, NULL);
	DrawType			= EDrawType::DT_StaticMesh;
}

static const int32 NVANIM_ON = 2;
static const int32 NVANIM_OFF = 1;

/*
replication
{
	reliable if ((Role < ROLE_Authority))
		ServerSetAnimation;
}
*/

void ANightOpticsDevice::BeginPlay()
{
	int32 i = 0;
	/*
	Super::BeginPlay();
	for (i = 0; i < 5; i++)
	{
		RandArray[i] = (FMath::FRand() * float(256));
	}
	*/
}

void ANightOpticsDevice::StatusChanged()
{
	/*
	Super::StatusChanged();
	if (Cast<APawn>(GetOwner()) != nullptr)
	{
		if (IsActive())
		{
			ServerSetAnimation(2);
			Cast<APawn>(GetOwner())->PlayOwnedSound(SwitchOnSound, 1, 0.55, false, 0, , true, false);
		}
		else
		{
			ServerSetAnimation(1);
			Cast<APawn>(GetOwner())->PlayOwnedSound(SwitchOffSound, 1, 0.55, false, 0, , true, false);
		}
		if ((Cast<AHumanController>(Cast<APawn>(GetOwner())->Controller) != nullptr) && (!bDisableNightVision))
		{
			Cast<AHumanController>(Cast<APawn>(GetOwner())->Controller).SetNightVision(IsActive());
		}
	}
	*/
}

void ANightOpticsDevice::CleanUp()
{
	/*
	AHumanController* HC = nullptr;
	Deactivate();
	HC = Cast<AHumanController>(Cast<APawn>(GetOwner())->Controller);
	if (HC != nullptr)
	{
		HC.SetNightVision(false);
	}
	*/
}

void ANightOpticsDevice::ServerSetAnimation(uint8 NewState)
{
	/*
	AnimState = NewState;
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		AttachmentAnimation();
	}
	*/
}

void ANightOpticsDevice::RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly)
{
	/*
	Super::RenderOverlays(Canvas, bWeaponAndAttachmentsOnly);
	if (bWeaponAndAttachmentsOnly == false)
	{
		Canvas.SetPos(0, 0);
		Canvas.Style = ERenderStyle.STY_TrueModulated;
		Canvas.DrawTile(NightVisionTexture, float(Canvas.SizeX), float(Canvas.SizeY), RandArray[RandInd], RandArray[RandInd], 256, 256);
		RandInd = int((float((RandInd + 1)) % 5));
		Canvas.SetPos(0, 0);
		Canvas.Style = ERenderStyle.STY_Alpha;
		Canvas.DrawTile(NightVisionOverlay, float(Canvas.SizeX), float(Canvas.SizeY), 0, 0, 256, 256);
	}
	*/
}

void ANightOpticsDevice::DoAttachStuffWhichShouldBeDoneInInventory()
{
	/*
	Instigator = Cast<APawn>(GetOwner());
	ServerSetAnimation(1);
	Instigator.AttachToBone(this, "BN_HeadEnd");
	SetRelativeRotation(FRotator(0, 32768, 16384));
	*/
}

void ANightOpticsDevice::AttachmentAnimation()
{
	/*
	Instigator = Cast<APawn>(GetOwner());
	if ((((Cast<APawn>(Base) != nullptr) && (!Level.IsUSSkin(Cast<APawn>(Base).bClientFriend))) || ((Instigator != nullptr) && Instigator.bGuerrillaMesh)) || (Level.GetMesh(true) == 6))
	{
		SetDrawType(DT_None);
		return;
	}
	else
	{
		SetDrawType(DT_StaticMesh);
	}
	if (AnimState == 1)
	{
		SetStaticMesh(NVG_Up);
	}
	else
	{
		SetStaticMesh(NVG_Down);
	}
	*/
}

void ANightOpticsDevice::NotifyBRoll(bool bRoll)
{
	/*
	if (bRoll)
	{
		Cast<AHumanController>(Cast<APawn>(GetOwner())->Controller).SetNightVision(false);
	}
	else
	{
		Cast<AHumanController>(Cast<APawn>(GetOwner())->Controller).SetNightVision(IsActive());
	}
	bDisableNightVision = bRoll;
	*/
}
