// All the original content belonged to the US Army


#include "NPC_MedInstructor.h"

ANPC_MedInstructor::ANPC_MedInstructor()
{

	RagdollOverride  = "CivilianM";
	Skins            = {
	Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_PANTS_Forest_BDU_Clean_Mat.Soldier_PANTS_Forest_BDU_Clean_Mat'"))),
	Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_SHIRT_Forest_BDU_Clean_Mat.Soldier_SHIRT_Forest_BDU_Clean_Mat'"))),
	Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Cauc_Mat.Soldier_HAND_Inf_Cauc_Mat'"))),
	Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_CaucA_Mat.Soldier_FACE_CaucA_Mat'"))),
	Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/SF/Skn_m9_Spec_Mat.Skn_m9_Spec_Mat'")))
	};
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB"), NULL, LOAD_None, NULL);
	LoadMesh();
}



FRotator ANPC_MedInstructor::NPC_SwapAxes(FRotator R)
{
	FRotator t;
	t = R;
	R.Pitch = -t.Yaw;
	R.Yaw = t.Roll;
	R.Roll = t.Pitch;
	return R;
}
void ANPC_MedInstructor::NPC_EyeTrack(FVector TrackThis, bool useHead)
{
	/*
	local FVector LookDir;
	local FVector AimDir;
	local Object.Rotator LEyeRot;
	local Object.Rotator REyeRot;
	local Object.Rotator NeckRot;
	local float Dot;
	local Object.Rotator Dir;
	local Object.Rotator RDir;
	local FVector pos;
	local float fyaw;
	LookDir = Vector(Rotation);
	LookDir = Normal(LookDir);
	AimDir = TrackThis - Location;
	AimDir = Normal(AimDir);
	if (!Self.bEyeTrack)
	{
		Return;
	}
	Dot = LookDir Dot AimDir;
	if (Dot > 0.65)
	{
		NeckRot = GetBoneRotation('Neck');
		AimDir = TrackThis - Location;
		RDir = AimDir;
		Dir = LookDir;
		RDir.Yaw = RDir.Yaw - Dir.Yaw;
		if (Dot > 0.9)
		{
			fyaw = RDir.Yaw;
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
			SetBoneDirection('Neck', NeckRot);
		}
		pos = GetBoneCoords('BN_LEyeBall').Origin;
		pos.Z = Location.Z;
		AimDir = TrackThis - pos;
		RDir = AimDir;
		Dir = LookDir;
		RDir.Yaw = RDir.Yaw - Dir.Yaw + fyaw;
		RDir = NPC_SwapAxes(RDir);
		LEyeRot = RDir;
		SetBoneDirection('BN_LEyeBall', LEyeRot);
		pos = GetBoneCoords('BN_REyeBall').Origin;
		pos.Z = Location.Z;
		AimDir = TrackThis - pos;
		RDir = AimDir;
		Dir = LookDir;
		RDir.Yaw = RDir.Yaw - Dir.Yaw + fyaw;
		RDir = NPC_SwapAxes(RDir);
		REyeRot = RDir;
		SetBoneDirection('BN_REyeBall', REyeRot);
	}
	*/
}
void ANPC_MedInstructor::ProfessorEyeTrack()
{
	/*
	local NPC_MedStudent MS;
	local int Count;
	local int rval;
	HController = HumanController(Level.GetClientController());
	Player = AGP_Pawn(Level.GetClientPawn());
	if (StudentController(HController).IsSeated())
	{
		if (fProfessorLookTime < GetWorld()->GetTimeSeconds())
		{
			rval = Rand(6);
			fProfessorLookTime = GetWorld()->GetTimeSeconds() + FRand() * 10 + 1;
			ForEach AllActors('NPC_MedStudent', MS)
			{
				Count++;
				if (rval == Count)
				{
					ProfessorLookTarget = MS;
				}
			}
		}
		NPC_EyeTrack(ProfessorLookTarget.Location, true);
	}
	else
	{
		NPC_EyeTrack(Player.Location, true);
	}
	*/
}
void ANPC_MedInstructor::Professor_EyeTrackPlayer()
{
	/*
	Player = AGP_Pawn(Level.GetClientPawn());
	NPC_EyeTrack(Player.Location, true);
	*/
}
