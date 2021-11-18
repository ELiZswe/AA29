// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "Stream.generated.h"

class UStreamTag;

UCLASS()
class AA29_API UStream : public UStreamBase
{
	GENERATED_BODY()
public:
	UStream();

	UPROPERTY(EditAnywhere)									bool bReadOnly;									//var() const editconst bool bReadOnly;
	UPROPERTY(EditAnywhere)									EFileType Type;									//var() const editconst StreamBase.EFileType Type;
	UPROPERTY(EditAnywhere)									FFilePath PathName;								//var() const editconst StreamBase.FilePath PathName;
	UPROPERTY(EditAnywhere)									UStreamTag* IDTag;								//var() const editconst StreamTag IDTag;
	UPROPERTY(EditAnywhere)									FString DefaultExtension;						//var() const editconst string DefaultExtension;
	UPROPERTY(EditAnywhere)									int32 Handle;									//var() editconst int Handle;

	void SaveID3Tag();
	void LoadID3Tag();
	bool IsReadOnly();
	int32 GetHandle();
	void GetTag();
	void GetType();
	void GetDirectory();
	void GetFileName();
	void GetExtension();
	void GetPath();
	void GetFullName();
	void GetSongTitle();
	bool SetHandle(int32 NewHandle);
	void DumpScriptTag();
	void DumpTags();
};
