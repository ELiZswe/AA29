// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "StreamInterface.generated.h"

class UStream;

UCLASS(Config = Game)
class UStreamInterface : public UStreamBase
{
	GENERATED_BODY()
public:
	UStreamInterface();

	UPROPERTY(globalconfig)									FString CurrentDirectory;									//var globalconfig string CurrentDirectory;

	FString GetBaseDirectory();
	bool GetDriveLetters(TArray<FString>& Letters);
	bool GetDirectoryContents(TArray<FString>& Contents, FString DirectoryName, EFileType FileType);
	FString CreateDirectory(FString DirectoryName);
	bool RemoveDirectory(FString DirectoryName);
	bool ValidDirectory(FString DirectoryPath);
	UStream* CreateStream(FString Filename, bool bStrict);
	bool ValidFile(FString Filename);
	bool LoadPlaylist(FString Filename, TArray<FString>& Lines, bool bStrict);
	FString GetCurrentDirectory();
	void ChangeDirectory(FString DirectoryName);
	bool HandleDebugExec(FString Command, FString Param);
};
