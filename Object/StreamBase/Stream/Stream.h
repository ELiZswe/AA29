// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "Stream.generated.h"

class UStreamTag;

UCLASS()
class UStream : public UStreamBase
{
	GENERATED_BODY()
public:
	UStream();

	UPROPERTY(EditAnywhere)									bool bReadOnly;									//var() const editconst bool bReadOnly;
	UPROPERTY(EditAnywhere)									EFileType Type;									//var() const editconst StreamBase.EFileType Type;
	UPROPERTY(EditAnywhere)									FaFilePath PathName;								//var() const editconst StreamBase.FilePath PathName;
	UPROPERTY(EditAnywhere)									UStreamTag* IDTag;								//var() const editconst StreamTag IDTag;
	UPROPERTY(EditAnywhere)									FString DefaultExtension;						//var() const editconst string DefaultExtension;
	UPROPERTY(EditAnywhere)									int32 Handle;									//var() editconst int Handle;

	void SaveID3Tag();
	void LoadID3Tag();
	bool IsReadOnly();
	int32 GetHandle();
	UStreamTag* GetTag();
	EFileType GetType();
	FString GetDirectory();
	FString GetFileName();
	FString GetExtension();
	FString GetPath();
	FString GetFullName();
	FString GetSongTitle();
	bool SetHandle(int32 NewHandle);
	void DumpScriptTag();
	void DumpTags();
};
