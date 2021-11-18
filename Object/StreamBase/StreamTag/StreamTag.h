// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "AA29/AA29.h"

#include "StreamTag.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UStreamTag : public UStreamBase
{
	GENERATED_BODY()
public:
	UStreamTag();

	UPROPERTY()									Fpointer NativeID3Tag;									//var transient pointer NativeID3Tag;
	UPROPERTY(EditAnywhere)						TArray<FID3Field> Fields;								//var() const editconstarray editconst array<ID3Field> Fields;
	UPROPERTY(EditAnywhere)						FID3Field Duration;										//var() editconst StreamBase.ID3Field Duration;
	UPROPERTY(EditAnywhere)						FID3Field Genre;										//var() const editconst StreamBase.ID3Field Genre;
	UPROPERTY(EditAnywhere)						FID3Field Year;											//var() const editconst StreamBase.ID3Field Year;
	UPROPERTY(EditAnywhere)						FID3Field Album;										//var() const editconst StreamBase.ID3Field Album;
	UPROPERTY(EditAnywhere)						FID3Field Artist;										//var() const editconst StreamBase.ID3Field Artist;
	UPROPERTY(EditAnywhere)						FID3Field Title;										//var() const editconst StreamBase.ID3Field Title;
	UPROPERTY(EditAnywhere)						FID3Field TrackNumber;									//var() const editconst StreamBase.ID3Field TrackNumber;
	UPROPERTY(EditAnywhere)						FID3Field TagID;										//var() const editconst StreamBase.ID3Field TagID;

	void OnRefresh();
	void DumpScriptTag();
	void DumpTag();

};
