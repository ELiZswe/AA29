// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyEnums.h"
#include "StreamBase.generated.h"

UCLASS()
class UStreamBase : public UObject
{
	GENERATED_BODY()
public:
	UStreamBase();

	void GetPathSeparator();
	bool IsCaseSensitive();
	FString GetPathRoot(FString& InPath);
	bool HasExtension(FString Test);
	bool ParsePath(FString InPath, FFilePath &ParsedPath);
	FString ParseExtension(FString &FileNameWithExtension);
	TArray<FString>  ParseDirectories(FString &InPath);
	int32 RevInStr(FString Src, FString Match);
	FString FormatTimeDisplay(float Seconds);
	FString ConvertToFileExtension(EFileType aType);
	EFileType ConvertToFileType(FString Extension);
	bool CompareNames(FString NameA, FString NameB);
	bool HandleDebugExec(FString Command, FString Param);
};
