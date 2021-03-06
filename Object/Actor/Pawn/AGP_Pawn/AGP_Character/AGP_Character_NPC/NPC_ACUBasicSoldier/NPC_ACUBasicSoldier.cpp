// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_ACUBasicSoldier/NPC_ACUBasicSoldier.h"
#include "AA29/AA2_WorldSettings.h"

ANPC_ACUBasicSoldier::ANPC_ACUBasicSoldier()
{
	fpAudioFullVolumeRadius	= 250;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/InfantryBasicACU.InfantryBasicACU"), NULL, LOAD_None, NULL);

	//PrimaryActorTick.bCanEverTick = true;
	LoadMesh();
}

void ANPC_ACUBasicSoldier::BeginPlay()
{
	Super::BeginPlay();
}


void ANPC_ACUBasicSoldier::PostBeginPlay()
{
	Super::PostBeginPlay();
	//SetCustomTimer((5 + float(Rand(5))), false, "RandomAudioTimer");
}

void ANPC_ACUBasicSoldier::MatchStarting()
{
	DoAnimLoop();
	//SetDrawType(DT_Mesh);
}

void ANPC_ACUBasicSoldier::PostNetBeginPlay()
{
	/*
	Super::PostNetBeginPlay();
	DoAnimLoop();
	SetDrawType(DT_Mesh);
	*/
}

void ANPC_ACUBasicSoldier::DoAnimLoop()
{
	if ((AnimSequence != "None") && (AnimSequence != "None"))
	{
		//LoopAnim(AnimSequence, AnimRate, AnimTime, AnimChannel);
	}
}

bool ANPC_ACUBasicSoldier::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_ACUBasicSoldier::LoadSkinsAndMeshes()
{
	int32 i = 0;
	/*
	if (GetNetMode() != ENetMode::NM_Client)
	{
		for (i = 0; i < Skins.Num(); i++)
		{
			FriendlyMaterial[i] = Skins[i];
		}
		FriendlyMesh = Mesh;
	}
	*/
}

void ANPC_ACUBasicSoldier::SetSkinsAndMeshes()
{
	int32 i = 0;
	/*
	if (!bUpdateSkinsAndMeshes)
	{
		return;
	}
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		Skins.Num() = 0;
		AlphaSkins.Num() = 0;
		BlackSkins.Num() = 0;
		for (i = 0; i < 5; i++)
		{
			if (FriendlyMaterial[i] != nullptr)
			{
				Skins.Num() = i;
				Skins[i] = FriendlyMaterial[i];
			}
		}
		LinkMesh(FriendlyMesh);
	}
	bUpdateSkinsAndMeshes = false;
	*/
}

void ANPC_ACUBasicSoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (((Cast<AAA2_WorldSettings>(GetWorldSettings())->GetClientPawn() != nullptr) && bTrackPlayer) && (GetNetMode() == ENetMode::NM_Standalone))
	{
		NPC_EyeTrack(Cast<AAA2_WorldSettings>(GetWorldSettings())->GetClientPawn()->GetActorLocation(), true);
	}
}

FRotator ANPC_ACUBasicSoldier::NPC_SwapAxes(FRotator R)
{
	FRotator t = FRotator(0, 0, 0);
	t = R;
	R.Pitch = (-t.Yaw);
	R.Yaw = t.Roll;
	R.Roll = t.Pitch;
	return R;
}

void ANPC_ACUBasicSoldier::NPC_EyeTrack(FVector TrackThis, bool useHead)
{
	FVector LookDir = FVector(0, 0, 0);
	FVector AimDir = FVector(0, 0, 0);
	FRotator LEyeRot = FRotator(0, 0, 0);
	FRotator REyeRot = FRotator(0, 0, 0);
	FRotator NeckRot = FRotator(0, 0, 0);
	float Dot = 0;
	FRotator Dir = FRotator(0, 0, 0);
	FRotator RDir = FRotator(0, 0, 0);
	FVector pos = FVector(0, 0, 0);
	float fyaw = 0;
	/*
	LookDir = Vector(Rotation);
	LookDir = Normal(LookDir);
	AimDir = (TrackThis - Location);
	AimDir = Normal(AimDir);
	if (!Self.bEyeTrack)
	{
		return;
	}
	Dot = (LookDir Dot AimDir);
	if (Dot > 0.65)
	{
		NeckRot = GetBoneRotation("Neck");
		AimDir = (TrackThis - Location);
		RDir = rotator(AimDir);
		Dir = rotator(LookDir);
		RDir.Yaw = (RDir.Yaw - Dir.Yaw);
		if (Dot > 0.9)
		{
			fyaw = float(RDir.Yaw);
			flastYaw = fyaw;
		}
		else
		{
			fyaw = flastYaw;
		}
		RDir = NPC_SwapAxes(RDir);
		NeckRot = RDir;
		if (Dot > 0.9)
		{
			SetBoneDirection("Neck", NeckRot);
		}
		pos = GetBoneCoords("BN_LEyeBall").Origin;
		pos.Z = Location.Z;
		AimDir = (TrackThis - pos);
		RDir = rotator(AimDir);
		Dir = rotator(LookDir);
		RDir.Yaw = int((float(RDir.Yaw) - (float(Dir.Yaw) + fyaw)));
		RDir = NPC_SwapAxes(RDir);
		LEyeRot = RDir;
		SetBoneDirection("BN_LEyeBall", LEyeRot);
		pos = GetBoneCoords("BN_REyeBall").Origin;
		pos.Z = Location.Z;
		AimDir = (TrackThis - pos);
		RDir = rotator(AimDir);
		Dir = rotator(LookDir);
		RDir.Yaw = int((float(RDir.Yaw) - (float(Dir.Yaw) + fyaw)));
		RDir = NPC_SwapAxes(RDir);
		REyeRot = RDir;
		SetBoneDirection("BN_REyeBall", REyeRot);
	}
	*/
}

void ANPC_ACUBasicSoldier::RandomAudioTimer()
{
	int32 iRandomAudioIndex = 0;
	/*
	if (((asndIdleRandomAudio.Num() > 0) && (!bUseLipSynch)) || ((anameIdleRandomLipSyncAudio.Num() > 0) && bUseLipSynch))
	{
		if (bUseLipSynch)
		{
			iRandomAudioIndex = Rand(anameIdleRandomLipSyncAudio.Num());
			PlayLIPSincAnim(anameIdleRandomLipSyncAudio[iRandomAudioIndex], 1, fpAudioFullVolumeRadius, 1);
		}
		else
		{
			iRandomAudioIndex = Rand(asndIdleRandomAudio.Num());
			PlaySound(asndIdleRandomAudio[iRandomAudioIndex], 0, 1, false, fpAudioFullVolumeRadius, , true);
		}
	}
	SetCustomTimer((5 + float(Rand(5))), false, "RandomAudioTimer");
	*/
}
