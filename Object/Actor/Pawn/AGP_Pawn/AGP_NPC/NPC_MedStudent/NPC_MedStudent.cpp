// All the original content belonged to the US Army


#include "NPC_MedStudent.h"

ANPC_MedStudent::ANPC_MedStudent()
{
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
}
State StudentIdle
{
}
State StudentTakeNotes
{
}
State StudentRaiseHand
{
*/

void ANPC_MedStudent::findMedInstructor()
{
	/*
	local NPC_MedInstructor MedInstruct;
	ForEach AllActors('NPC_MedInstructor',MedInstruct)
	{
		if (MedInstruct.Tag == 'InstructorOne')
		{
			MI = MedInstruct;
		}
	}
	*/
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
		PlayerReplicationInfo = Spawn(Class'PlayerReplicationInfo', Controller);
		PlayerReplicationInfo.PlayerName = MyName;
		PlayerReplicationInfo.ServerSetMyPawn(Self);
	}
	*/
}
void ANPC_MedStudent::UsedBy(APawn* User)
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
	HController = HumanController(Level.GetClientController());
	Player = AGP_Pawn(Level.GetClientPawn());
	if (StudentController(HController).IsSeated() == false)
	{
		NPC_EyeTrack(Player.Location, false);
	}
	else
	{
		if (bLookAtInstructor == true)
		{
			NPC_EyeTrack(MI.Location, true);
		}
	}
	*/
}
