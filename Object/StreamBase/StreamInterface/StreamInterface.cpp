// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/StreamInterface/StreamInterface.h"
#include "AA29/Object/StreamBase/Stream/Stream.h"

UStreamInterface::UStreamInterface()
{

}

//native final Function GetBaseDirectory();
FString UStreamInterface::GetBaseDirectory()
{
	return "FAKE";    //FAKE   /EliZ
}

//native final Function GetDriveLetters(out TArray<FString> Letters);
bool UStreamInterface::GetDriveLetters(TArray<FString> &Letters)
{
	return false;    //FAKE   /EliZ
}

//native final Function GetDirectoryContents(out TArray<FString> Contents, optional string DirectoryName, optional StreamBase.EFileType FileType);
bool UStreamInterface::GetDirectoryContents(TArray<FString> &Contents, FString DirectoryName, EFileType FileType)
{
	return false;    //FAKE   /EliZ
}

//native final Function CreateDirectory(string DirectoryName);
FString UStreamInterface::CreateDirectory(FString DirectoryName)
{
	return "FAKE";    //FAKE   /EliZ
}

//native final Function RemoveDirectory(string DirectoryName);
bool UStreamInterface::RemoveDirectory(FString DirectoryName)
{
	return false;    //FAKE   /EliZ
}

//native final Function ValidDirectory(optional string DirectoryPath);
bool UStreamInterface::ValidDirectory(FString DirectoryPath)
{
	return false;    //FAKE   /EliZ
}

//native final Function CreateStream(string Filename, optional bool bStrict);
UStream* UStreamInterface::CreateStream(FString Filename, bool bStrict)
{
	return nullptr;    //FAKE   /EliZ
}

//native final Function ValidFile(string Filename);
bool UStreamInterface::ValidFile(FString Filename)
{
	return false;    //FAKE   /EliZ
}

//native final Function LoadPlaylist(string Filename, out TArray<FString> Lines, optional bool bStrict);
bool UStreamInterface::LoadPlaylist(FString Filename, TArray<FString> &Lines, bool bStrict)
{
	return false;    //FAKE   /EliZ
}

FString UStreamInterface::GetCurrentDirectory()
{
	/*
	if (CurrentDirectory == "" || !ValidDirectory(CurrentDirectory))
	{
		ChangeDirectory(GetBaseDirectory());
	}
	*/
	return CurrentDirectory;
}

void UStreamInterface::ChangeDirectory(FString DirectoryName)
{
	bool bSave = false;
	bSave = DirectoryName != CurrentDirectory;
	CurrentDirectory = DirectoryName;
	if (bSave)
	{
		SaveConfig();
	}
}

bool UStreamInterface::HandleDebugExec(FString Command, FString Param)
{
	FString str = "";
	TArray<FString> Test ={};
	int32 i = 0;
	/*
	if (HandleDebugExec(Command, Param))
	{
		return true;
	}
	switch(Locs(Command))
	{
			case "getbase":
				Log(GetBaseDirectory());
				return true;
			case "getcurrent":
				Log(GetCurrentDirectory());
				return true;
			case "validfilename":
				Log(ValidFile(Param));
				return true;
			case "dir":
				GetDirectoryContents(Test, Param);
				Log("directory list for" @ Param);
				i = 0;
				if (i < Test.Num())
				{
					Log("   >" @ Test[i]);
					i++;
					break;
				}
				return true;
			case "chdir":
				str = GetCurrentDirectory();
				ChangeDirectory(Param);
				Log("old:" + str @ "new:" + GetCurrentDirectory());
				return true;
			default:
				return false;
		}
	*/
	return false;    //FAKE ELiZ
}
