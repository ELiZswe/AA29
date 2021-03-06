// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedInstructor/NPC_MedInstructor.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedStudent/NPC_MedStudent.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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

/*
State Professor
{
Begin:
	Sleep(0.05);
	ProfessorEyeTrack();
	JL"Loop"
;
}
*/

/*
State ProfessorEyeTrackPlayer
{
Begin:
	Sleep(0.05);
	Professor_EyeTrackPlayer();
	JL"Loop"
;
}
*/

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
	FVector LookDir = FVector(0, 0, 0);
	FVector AimDir = FVector(0, 0, 0);
	FRotator LEyeRot = FRotator(0,0,0);
	FRotator REyeRot = FRotator(0, 0, 0);
	FRotator NeckRot = FRotator(0, 0, 0);
	float Dot = 0;
	FRotator Dir = FRotator(0, 0, 0);
	FRotator RDir = FRotator(0, 0, 0);
	FVector pos = FVector(0,0,0);
	float fyaw = 0;
	/*
	LookDir = Vector(Rotation);
	LookDir = Normal(LookDir);
	AimDir = TrackThis - Location;
	AimDir = Normal(AimDir);
	if (!Self.bEyeTrack)
	{
		return;
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
	ANPC_MedStudent* MS = nullptr;
	int32 Count = 0;
	int32 rval = 0;
	/*
	HController = Cast<AHumanController>(Level.GetClientController());
	Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
	if (Cast<AStudentController>(HController).IsSeated())
	{
		if (fProfessorLookTime < GetWorld()->GetTimeSeconds())
		{
			rval = Rand(6);
			fProfessorLookTime = GetWorld()->GetTimeSeconds() + FMath::FRand() * 10 + 1;
			ForEach AllActors('NPC_MedStudent', MS)
			{
				Count++;
				if (rval == Count)
				{
					ProfessorLookTarget = MS;
				}
			}
		}
		NPC_EyeTrack(ProfessorLookTarget->GetActorLocation(), true);
	}
	else
	{
		NPC_EyeTrack(Player->GetActorLocation(), true);
	}
	*/
}
void ANPC_MedInstructor::Professor_EyeTrackPlayer()
{
	/*
	Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
	NPC_EyeTrack(Player->GetActorLocation(), true);
	*/
}
