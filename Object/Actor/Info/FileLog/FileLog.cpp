// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/FileLog/FileLog.h"

AFileLog::AFileLog()
{
	FileExtension = ".txt";
	FilePath = ".";
}


void AFileLog::OpenLog(FString FName, FString FExt, bool bOverwrite)
{

}
void AFileLog::CloseLog()
{

}
void AFileLog::Logf(FString LogString)
{

}
void AFileLog::FlushLog()
{

}

void AFileLog::SetFileExtension(FString new_ext)
{
	FileExtension = new_ext;
}
void AFileLog::SetFilePath(FString new_path)
{
	FilePath = new_path;
}
FString AFileLog::GetFileExtension()
{
	return FileExtension;
}
FString AFileLog::GetFilePath()
{
	return FilePath;
}