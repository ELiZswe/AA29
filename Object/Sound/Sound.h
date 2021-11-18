// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "Sound.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API USound : public UObject
{
	GENERATED_BODY()
public:
	USound();

	UPROPERTY(EditAnywhere)			float VelocityScale;						//var() float VelocityScale;
	UPROPERTY(EditAnywhere)			float BaseRadius;							//var() float BaseRadius;
	UPROPERTY()						float InitialSeekTime;						//var const native float InitialSeekTime;
	UPROPERTY()						int32 VoiceCodec;							//var const native int VoiceCodec;
	UPROPERTY()						int32 Flags;								//var const native int Flags;
	UPROPERTY()						Fpointer Handle;							//var const native transient pointer Handle;
	UPROPERTY()						float Duration;								//var const native float Duration;
	UPROPERTY()						int32 OriginalSize;							//var const native int OriginalSize;
	UPROPERTY()						FString Filename;							//var const native string Filename;
	UPROPERTY()						FName FileType;								//var const native name FileType;
	UPROPERTY()						uint8 Data;									//var const native byte Data;
	UPROPERTY(EditAnywhere)			float Likelihood;							//var() native float Likelihood;

};
