// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/AA2_Info.h"
#include "FileLog.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFileLog : public AAA2_Info
{
	GENERATED_BODY()
	

public:

	AFileLog();

	UPROPERTY()		FString FilePath;									//var string FilePath;
	UPROPERTY()		FString FileExtension;								//var string FileExtension;
	UPROPERTY()		FString TempFileName;								//var const string TempFileName;
	UPROPERTY()		FString LogFileName;								//var const string LogFileName;
	//UPROPERTY()		FPointer LogAr;									//var transient pointer LogAr;


	void OpenLog(FString FName, FString FExt, bool bOverwrite);
	void CloseLog();
	void Logf(FString LogString);
	void FlushLog();
	void SetFileExtension(FString new_ext);
	void SetFilePath(FString new_path);
	FString GetFileExtension();
	FString GetFilePath();
};
