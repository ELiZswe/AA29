// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_NPC/AGP_NPC.h"
#include "NPC_MedStudent.generated.h"

class ANPC_MedInstructor;

UCLASS()
class AA29_API ANPC_MedStudent : public AAGP_NPC
{
	GENERATED_BODY()
public:
	ANPC_MedStudent();


	UPROPERTY()											float fAnimTimer;				//var float fAnimTimer;
	UPROPERTY(EditAnywhere)								float fEyeTrackPitchOffset;		//var() float fEyeTrackPitchOffset;
	UPROPERTY()											int32 UseCountBusy;				//var int UseCountBusy;
	UPROPERTY()											int32 UseCountGreet;			//var int UseCountGreet;

	UPROPERTY()											TArray<FName> VGreet;					//var name VGreet;
	UPROPERTY()											TArray<FName> VBusy;					//var name VBusy;
	UPROPERTY()											TArray<FName> VAdrienneBusy;			//var name VAdrienneBusy;
	UPROPERTY()											TArray<FName> VLauraBusy;				//var name VLauraBusy;
	UPROPERTY()											TArray<FName> VRachelBusy;				//var name VRachelBusy;
	UPROPERTY()											TArray<FName> VTavBusy;					//var name VTavBusy;
	UPROPERTY()											TArray<FName> VPhillipBusy;				//var name VPhillipBusy;
	UPROPERTY()											TArray<FName> VMartinBusy;				//var name VMartinBusy;
	UPROPERTY()											TArray<FName> VGregBusy;				//var name VGregBusy;
	UPROPERTY()											TArray<FName> VEvanBusy;				//var name VEvanBusy;
	UPROPERTY()											TArray<FName> VChristianBusy;			//var name VChristianBusy;
	UPROPERTY()											TArray<FName> VAdrienneGreet;			//var name VAdrienneGreet;
	UPROPERTY()											TArray<FName> VLauraGreet;				//var name VLauraGreet;
	UPROPERTY()											TArray<FName> VRachelGreet;				//var name VRachelGreet;
	UPROPERTY()											TArray<FName> VTavGreet;				//var name VTavGreet;
	UPROPERTY()											TArray<FName> VPhillipGreet;			//var name VPhillipGreet;
	UPROPERTY()											TArray<FName> VMartinGreet;				//var name VMartinGreet;
	UPROPERTY()											TArray<FName> VGregGreet;				//var name VGregGreet;
	UPROPERTY()											TArray<FName> VEvanGreet;				//var name VEvanGreet;
	UPROPERTY()											TArray<FName> VChristianGreet;			//var name VChristianGreet;

	UPROPERTY()											ANPC_MedInstructor* MI;			//var NPC_MedInstructor MI;
	UPROPERTY()											bool bLookAtInstructor;			//var bool bLookAtInstructor;
	UPROPERTY(EditAnywhere)								bool EyesTrack;					//var() bool EyesTrack;
	UPROPERTY()											bool busy;						//var bool busy;
	UPROPERTY(EditAnywhere)								bool bSpawnPRI;					//var() bool bSpawnPRI;
	UPROPERTY(EditAnywhere)								FString MyName;					//var() string MyName;
	UPROPERTY(EditAnywhere)								EVoiceType VoiceType;			//var() EVoiceType VoiceType;

	void findMedInstructor();
	void BeginPlay();
	void UsedBy(APawn* User);
	void BusyTalk();
	void GreetTalk();
	void Timer();
	void CallForMedic();
	void SetVoiceType(EVoiceType VoiceType);
	FRotator NPC_SwapAxes(FRotator R);
	void NPC_EyeTrack(FVector TrackThis, bool useHead);
	void StudentEyeTrack();


};
