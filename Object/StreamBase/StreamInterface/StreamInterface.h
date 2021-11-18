// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/StreamBase/StreamBase.h"
#include "StreamInterface.generated.h"

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API UStreamInterface : public UStreamBase
{
	GENERATED_BODY()
public:
	UStreamInterface();


	UPROPERTY(globalconfig)									FString CurrentDirectory;									//var globalconfig string CurrentDirectory;


	void GetBaseDirectory();
	void GetDriveLetters(TArray<FString>& Letters);
	void GetDirectoryContents(TArray<FString>& Contents, FString DirectoryName, EFileType FileType);
	void CreateDirectory(FString DirectoryName);
	void RemoveDirectory(FString DirectoryName);
	void ValidDirectory(FString DirectoryPath);
	void CreateStream(FString Filename, bool bStrict);
	void ValidFile(FString Filename);
	void LoadPlaylist(FString Filename, TArray<FString>& Lines, bool bStrict);
	void GetCurrentDirectory();
	void ChangeDirectory(FString DirectoryName);
	void HandleDebugExec(FString Command, FString Param);
};
