// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "I3DL2Listener.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UI3DL2Listener : public UObject
{
	GENERATED_BODY()
public:
	UI3DL2Listener();

	UPROPERTY()									int32 Updated;							//var transient int Updated;
	UPROPERTY()									int32 Environment;						//var transient int Environment;
	UPROPERTY(EditAnywhere)						bool bDecayHFLimit;						//var() bool bDecayHFLimit;
	UPROPERTY(EditAnywhere)						bool bModulationTimeScale;				//var() bool bModulationTimeScale;
	UPROPERTY(EditAnywhere)						bool bEchoTimeScale;					//var() bool bEchoTimeScale;
	UPROPERTY(EditAnywhere)						bool bReverbDelayScale;					//var() bool bReverbDelayScale;
	UPROPERTY(EditAnywhere)						bool bReverbScale;						//var() bool bReverbScale;
	UPROPERTY(EditAnywhere)						bool bReflectionsDelayScale;			//var() bool bReflectionsDelayScale;
	UPROPERTY(EditAnywhere)						bool bReflectionsScale;					//var() bool bReflectionsScale;
	UPROPERTY(EditAnywhere)						bool bDecayTimeScale;					//var() bool bDecayTimeScale;
	UPROPERTY(EditAnywhere)						float LFReference;						//var() float LFReference;
	UPROPERTY(EditAnywhere)						float HFReference;						//var() float HFReference;
	UPROPERTY(EditAnywhere)						float AirAbsorptionHF;					//var() float AirAbsorptionHF;
	UPROPERTY(EditAnywhere)						float RoomRolloffFactor;				//var() float RoomRolloffFactor;
	UPROPERTY(EditAnywhere)						float ModulationDepth;					//var() float ModulationDepth;
	UPROPERTY(EditAnywhere)						float ModulationTime;					//var() float ModulationTime;
	UPROPERTY(EditAnywhere)						float EchoDepth;						//var() float EchoDepth;
	UPROPERTY(EditAnywhere)						float EchoTime;							//var() float EchoTime;
	UPROPERTY(EditAnywhere)						FVector ReverbPan;						//var() Object.Vector ReverbPan;
	UPROPERTY(EditAnywhere)						float ReverbDelay;						//var() float ReverbDelay;
	UPROPERTY(EditAnywhere)						int32 Reverb;							//var() int Reverb;
	UPROPERTY(EditAnywhere)						FVector FilenReflectionsPaname;			//var() Object.Vector ReflectionsPan;
	UPROPERTY(EditAnywhere)						float ReflectionsDelay;					//var() float ReflectionsDelay;
	UPROPERTY(EditAnywhere)						int32 Reflections;						//var() int Reflections;
	UPROPERTY(EditAnywhere)						float DecayLFRatio;						//var() float DecayLFRatio;
	UPROPERTY(EditAnywhere)						float DecayHFRatio;						//var() float DecayHFRatio;
	UPROPERTY(EditAnywhere)						float DecayTime;						//var() float DecayTime;
	UPROPERTY(EditAnywhere)						int32 RoomLF;							//var() int RoomLF;
	UPROPERTY(EditAnywhere)						int32 RoomHF;							//var() int RoomHF;
	UPROPERTY(EditAnywhere)						int32 Room;								//var() int Room;
	UPROPERTY(EditAnywhere)						float EnvironmentDiffusion;				//var() float EnvironmentDiffusion;
	UPROPERTY(EditAnywhere)						float EnvironmentSize;					//var() float EnvironmentSize;

};
