// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/AGP_NPC.h"
#include "NPC_MedInstructor.generated.h"

class ANPC_MedStudent;

UCLASS()
class AA29_API ANPC_MedInstructor : public AAGP_NPC
{
	GENERATED_BODY()
public:
	ANPC_MedInstructor();

	UPROPERTY()											FRotator vStartRotation;					//var Object.Rotator vStartRotation;
	UPROPERTY()											ANPC_MedStudent* ProfessorLookTarget;		//var NPC_MedStudent ProfessorLookTarget;
	UPROPERTY()											float fProfessorLookTime;					//var float fProfessorLookTime;


	FRotator NPC_SwapAxes(FRotator R);
	void NPC_EyeTrack(FVector TrackThis, bool useHead);
	void ProfessorEyeTrack();
	void Professor_EyeTrackPlayer();

};
