// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedStudent/NPC_MedStudent.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/NPC_MedInstructor/NPC_MedInstructor.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"

ANPC_MedStudent::ANPC_MedStudent()
{
	VAdrienneBusy.SetNum(4);
	VLauraBusy.SetNum(4);
	VRachelBusy.SetNum(4);
	VTavBusy.SetNum(4);
	VPhillipBusy.SetNum(4);
	VMartinBusy.SetNum(4);
	VGregBusy.SetNum(4);
	VEvanBusy.SetNum(4);
	VChristianBusy.SetNum(4);
	VAdrienneGreet.SetNum(6);
	VLauraGreet.SetNum(6);
	VRachelGreet.SetNum(6);
	VTavGreet.SetNum(6);
	VPhillipGreet.SetNum(6);
	VMartinGreet.SetNum(6);
	VGregGreet.SetNum(6);
	VEvanGreet.SetNum(6);
	VChristianGreet.SetNum(6);
	MyName = "Some Dude";
	VChristianGreet = { "ChristianGreet1","ChristianGreet2","ChristianGreet3","ChristianGreet4","ChristianGreet5","ChristianGreet6"};
	VEvanGreet      = { "EvanGreet1","EvanGreet2","EvanGreet3","EvanGreet4","EvanGreet5","EvanGreet6"};
	VGregGreet      = { "GregGreet1","GregGreet2","GregGreet3","GregGreet4","GregGreet5","GregGreet6"};
	VMartinGreet    = { "MartinGreet1","MartinGreet2","MartinGreet3","MartinGreet4","MartinGreet5","MartinGreet6"};
	VPhillipGreet   = { "PhillipGreet1","PhillipGreet2","PhillipGreet3","PhillipGreet4","PhillipGreet5","PhillipGreet6"};
	VTavGreet       = { "TavGreet1","TavGreet2","TavGreet3","TavGreet4","TavGreet5","TavGreet6"};
	VRachelGreet    = { "RachelGreet1","RachelGreet2","RachelGreet3","RachelGreet4","RachelGreet5","RachelGreet6"};
	VLauraGreet     = { "LauraGreet1","LauraGreet2","LauraGreet3","LauraGreet4","LauraGreet5","LauraGreet6"};
	VAdrienneGreet  = { "AdrienneGreet1","AdrienneGreet2","AdrienneGreet3","AdrienneGreet4","AdrienneGreet5","AdrienneGreet6"};
	VChristianBusy  = { "ChristianBusy1","ChristianBusy2","ChristianBusy3","ChristianBusy4"};
	VEvanBusy       = { "EvanBusy1","EvanBusy2","EvanBusy3","EvanBusy4"};
	VGregBusy       = { "GregBusy1","GregBusy2","GregBusy3","GregBusy4"};
	VMartinBusy     = { "MartinBusy1","MartinBusy2","MartinBusy3","MartinBusy4"};
	VPhillipBusy    = { "PhillipBusy1","PhillipBusy2","PhillipBusy3","PhillipBusy4"};
	VTavBusy        = { "TavBusy1","TavBusy2","TavBusy3","TavBusy4"};
	VRachelBusy     = { "RachelBusy1","RachelBusy2","RachelBusy3","RachelBusy4"};
	VLauraBusy      = { "LauraBusy1","LauraBusy2","LauraBusy3","LauraBusy4"};
	VAdrienneBusy   = {"AdrienneBusy1","AdrienneBusy2","AdrienneBusy3","AdrienneBusy4"};
	//RagdollOverride = "CivilianM";
	//RemoteRole = 1
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB"), NULL, LOAD_None, NULL);
	LoadMesh();
}

/*
State StudentEyeTrackState
{
Begin:
	Sleep(0.05);
	StudentEyeTrack();
	JL"Loop"
;
}
*/

/*
State StudentIdle extends StudentEyeTrackState
{
Begin:
	LoopAnim(AnimSequence,1,1);
	bLookAtInstructor=false;
}
*/

/*
State StudentTakeNotes extends StudentEyeTrackState
{
Begin:
	Sleep(0.1);
	if (fAnimTimer < GetWorld()->GetTimeSeconds())
	{
		LoopAnim("Student01_takenote",1,0.5);
	}
	else
	{
		JL"Begin"
;
	}
}
*/

/*
State StudentRaiseHand extends StudentEyeTrackState
{
	Function findMedInstructor()
	{
		ANPC_MedInstructor* MedInstruct = nullptr;
		ForEach AllActors(ANPC_MedInstructor::StaticClass(),MedInstruct)
		{
			if (MedInstruct.Tag == "InstructorOne")
			{
				MI=MedInstruct;
			}
		}
	}
Begin:
	findMedInstructor();
	PlayAnim("Student_HandRaiseRT",1,0.25);
	bLookAtInstructor=true;
}
*/

/*
State StudentAnswer extends StudentEyeTrackState
{
Begin:
	bLookAtInstructor=true;
}
*/

void ANPC_MedStudent::findMedInstructor()
{
	for (TActorIterator<ANPC_MedInstructor> Itr(GetWorld()); Itr; ++Itr)
	{
		ANPC_MedInstructor* MedInstruct = *Itr;
		if (MedInstruct->ActorHasTag("InstructorOne"))
		{
			MI = MedInstruct;
		}
	}
}

/*
}
State StudentAnswer
{
}
*/
void ANPC_MedStudent::BeginPlay()
{
	/*
	SetTimer(30, true);
	SetVoiceType(VoiceType);
	if (bSpawnPRI)
	{
		PlayerReplicationInfo = Spawn(APlayerReplicationInfo::StaticClass(), Controller);
		PlayerReplicationInfo.PlayerName = MyName;
		PlayerReplicationInfo.ServerSetMyPawn(this);
	}
	*/
}

bool ANPC_MedStudent::UsedBy(APawn* User)
{
	if (VoiceType != EVoiceType::VT_None)
	{
		if (busy)
		{
			BusyTalk();
		}
		else
		{
			GreetTalk();
		}
	}
	return Super::UsedBy(User);
}
void ANPC_MedStudent::BusyTalk()
{
	if (UseCountBusy > 4)
	{
		return;
	}
	//PlayLIPSincAnim(VBusy[Rand(4)], 1, 512);
	UseCountBusy++;
}

void ANPC_MedStudent::GreetTalk()
{
	if (UseCountGreet > 4)
	{
		UseCountGreet++;
		if (UseCountBusy <= 4 && UseCountGreet > 4 + 4)
		{
			//PlayLIPSincAnim(VBusy[Rand(4)], 1, 512);
			UseCountBusy++;
		}
	}
	else
	{
		//PlayLIPSincAnim(VGreet[Rand(6)], 1, 512);
		UseCountGreet++;
	}
}

void ANPC_MedStudent::Timer()
{
	if (UseCountBusy > 4)
	{
		UseCountBusy = 4;
	}
	else
	{
		if (UseCountBusy > 0)
		{
			UseCountBusy = 0;
		}
		else
		{
			UseCountGreet = 0;
		}
	}
}

void ANPC_MedStudent::CallForMedic()
{
	//PlayerReplicationInfo.bCallForMedic = true;
}

void ANPC_MedStudent::SetVoiceType(EVoiceType aVoiceType)
{
	switch(aVoiceType)
	{
		case EVoiceType::VT_Leader:
			VGreet[0] = VChristianGreet[0];
			VGreet[1] = VChristianGreet[1];
			VGreet[2] = VChristianGreet[2];
			VGreet[3] = VChristianGreet[3];
			VGreet[4] = VChristianGreet[4];
			VGreet[5] = VChristianGreet[5];
			VBusy[0] = VChristianBusy[0];
			VBusy[1] = VChristianBusy[1];
			VBusy[2] = VChristianBusy[2];
			VBusy[3] = VChristianBusy[3];
			break;
		case EVoiceType::VT_Commander:
			VGreet[0] = VEvanGreet[0];
			VGreet[1] = VEvanGreet[1];
			VGreet[2] = VEvanGreet[2];
			VGreet[3] = VEvanGreet[3];
			VGreet[4] = VEvanGreet[4];
			VGreet[5] = VEvanGreet[5];
			VBusy[0] = VEvanBusy[0];
			VBusy[1] = VEvanBusy[1];
			VBusy[2] = VEvanBusy[2];
			VBusy[3] = VEvanBusy[3];
			break;
		case EVoiceType::VT_Sergeant:
			VGreet[0] = VGregGreet[0];
			VGreet[1] = VGregGreet[1];
			VGreet[2] = VGregGreet[2];
			VGreet[3] = VGregGreet[3];
			VGreet[4] = VGregGreet[4];
			VGreet[5] = VGregGreet[5];
			VBusy[0] = VGregBusy[0];
			VBusy[1] = VGregBusy[1];
			VBusy[2] = VGregBusy[2];
			VBusy[3] = VGregBusy[3];
			break;
		case EVoiceType::VT_Weapons:
			VGreet[0] = VMartinGreet[0];
			VGreet[1] = VMartinGreet[1];
			VGreet[2] = VMartinGreet[2];
			VGreet[3] = VMartinGreet[3];
			VGreet[4] = VMartinGreet[4];
			VGreet[5] = VMartinGreet[5];
			VBusy[0] = VMartinBusy[0];
			VBusy[1] = VMartinBusy[1];
			VBusy[2] = VMartinBusy[2];
			VBusy[3] = VMartinBusy[3];
			break;
		case EVoiceType::VT_Engineer:
			VGreet[0] = VPhillipGreet[0];
			VGreet[1] = VPhillipGreet[1];
			VGreet[2] = VPhillipGreet[2];
			VGreet[3] = VPhillipGreet[3];
			VGreet[4] = VPhillipGreet[4];
			VGreet[5] = VPhillipGreet[5];
			VBusy[0] = VPhillipBusy[0];
			VBusy[1] = VPhillipBusy[1];
			VBusy[2] = VPhillipBusy[2];
			VBusy[3] = VPhillipBusy[3];
			break;
		case EVoiceType::VT_Medical:
			VGreet[0] = VTavGreet[0];
			VGreet[1] = VTavGreet[1];
			VGreet[2] = VTavGreet[2];
			VGreet[3] = VTavGreet[3];
			VGreet[4] = VTavGreet[4];
			VGreet[5] = VTavGreet[5];
			VBusy[0] = VTavBusy[0];
			VBusy[1] = VTavBusy[1];
			VBusy[2] = VTavBusy[2];
			VBusy[3] = VTavBusy[3];
			break;
		case EVoiceType::VT_Communication:
			VGreet[0] = VRachelGreet[0];
			VGreet[1] = VRachelGreet[1];
			VGreet[2] = VRachelGreet[2];
			VGreet[3] = VRachelGreet[3];
			VGreet[4] = VRachelGreet[4];
			VGreet[5] = VRachelGreet[5];
			VBusy[0] = VRachelBusy[0];
			VBusy[1] = VRachelBusy[1];
			VBusy[2] = VRachelBusy[2];
			VBusy[3] = VRachelBusy[3];
			break;
		case EVoiceType::VT_Intelligence:
			VGreet[0] = VLauraGreet[0];
			VGreet[1] = VLauraGreet[1];
			VGreet[2] = VLauraGreet[2];
			VGreet[3] = VLauraGreet[3];
			VGreet[4] = VLauraGreet[4];
			VGreet[5] = VLauraGreet[5];
			VBusy[0] = VLauraBusy[0];
			VBusy[1] = VLauraBusy[1];
			VBusy[2] = VLauraBusy[2];
			VBusy[3] = VLauraBusy[3];
			break;
		case EVoiceType::VT_StudentVendingMachine:
			VGreet[0] = VAdrienneGreet[0];
			VGreet[1] = VAdrienneGreet[1];
			VGreet[2] = VAdrienneGreet[2];
			VGreet[3] = VAdrienneGreet[3];
			VGreet[4] = VAdrienneGreet[4];
			VGreet[5] = VAdrienneGreet[5];
			VBusy[0] = VAdrienneBusy[0];
			VBusy[1] = VAdrienneBusy[1];
			VBusy[2] = VAdrienneBusy[2];
			VBusy[3] = VAdrienneBusy[3];
			break;
		default:
			break;
	}
}

FRotator ANPC_MedStudent::NPC_SwapAxes(FRotator R)
{
	FRotator t;
	t = R;
	R.Pitch = -t.Yaw;
	R.Yaw = t.Roll;
	R.Roll = t.Pitch;
	return R;
}

void ANPC_MedStudent::NPC_EyeTrack(FVector TrackThis, bool useHead)
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
	if (fEyeTrackPitchOffset == 0)
	{
		fEyeTrackPitchOffset = 24;
	}
	LookDir = Vector(Rotation);
	LookDir = Normal(LookDir);
	AimDir = TrackThis - Location;
	AimDir = Normal(AimDir);
	Dot = LookDir Dot AimDir;
	if (Dot > 0.55)
	{
		NeckRot = GetBoneRotation('Neck');
		AimDir = TrackThis - Location;
		RDir = AimDir;
		Dir = LookDir;
		RDir.Yaw = RDir.Yaw - Dir.Yaw;
		if (Dot > 0.95)
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
		if (Dot > 0.95)
		{
			SetBoneDirection('Neck', NeckRot);
		}
		pos = GetBoneCoords('BN_LEyeBall').Origin;
		TrackThis.Z = pos.Z + fEyeTrackPitchOffset;
		AimDir = TrackThis - pos;
		RDir = AimDir;
		Dir = LookDir;
		RDir.Yaw = RDir.Yaw - Dir.Yaw + fyaw;
		RDir = NPC_SwapAxes(RDir);
		LEyeRot = RDir;
		SetBoneDirection('BN_LEyeBall', LEyeRot);
		pos = GetBoneCoords('BN_REyeBall').Origin;
		TrackThis.Z = pos.Z + fEyeTrackPitchOffset;
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

void ANPC_MedStudent::StudentEyeTrack()
{
	/*
	HController = Cast<AHumanController>(Level.GetClientController());
	Player = Cast<AAGP_Pawn>(Level.GetClientPawn());
	if (Cast<AStudentController>(HController).IsSeated() == false)
	{
		NPC_EyeTrack(Player->GetActorLocation(), false);
	}
	else
	{
		if (bLookAtInstructor == true)
		{
			NPC_EyeTrack(MI->GetActorLocation(), true);
		}
	}
	*/
}
