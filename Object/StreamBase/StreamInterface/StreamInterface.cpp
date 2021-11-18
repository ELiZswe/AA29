// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/StreamInterface/StreamInterface.h"

UStreamInterface::UStreamInterface()
{

}

//native final Function GetBaseDirectory();
void UStreamInterface::GetBaseDirectory()
{
}

//native final Function GetDriveLetters(out array<String> Letters);
void UStreamInterface::GetDriveLetters(TArray<FString> &Letters)
{
}

//native final Function GetDirectoryContents(out array<String> Contents, optional string DirectoryName, optional StreamBase.EFileType FileType);
void UStreamInterface::GetDirectoryContents(TArray<FString> &Contents, FString DirectoryName, EFileType FileType)
{
}

//native final Function CreateDirectory(string DirectoryName);
void UStreamInterface::CreateDirectory(FString DirectoryName)
{
}

//native final Function RemoveDirectory(string DirectoryName);
void UStreamInterface::RemoveDirectory(FString DirectoryName)
{
}

//native final Function ValidDirectory(optional string DirectoryPath);
void UStreamInterface::ValidDirectory(FString DirectoryPath)
{
}

//native final Function CreateStream(string Filename, optional bool bStrict);
void UStreamInterface::CreateStream(FString Filename, bool bStrict)
{
}

//native final Function ValidFile(string Filename);
void UStreamInterface::ValidFile(FString Filename)
{
}

//native final Function LoadPlaylist(string Filename, out array<String> Lines, optional bool bStrict);
void UStreamInterface::LoadPlaylist(FString Filename, TArray<FString> &Lines, bool bStrict)
{
}

void UStreamInterface::GetCurrentDirectory()
{
	/*
	if (CurrentDirectory == "" || !ValidDirectory(CurrentDirectory))
	{
		ChangeDirectory(GetBaseDirectory());
	}
	Return CurrentDirectory;
	*/
}
void UStreamInterface::ChangeDirectory(FString DirectoryName)
{
	/*
	local bool bSave;
	bSave = DirectoryName != CurrentDirectory;
	CurrentDirectory = DirectoryName;
	if (bSave)
	{
		SaveConfig();
	}
	*/
}
void UStreamInterface::HandleDebugExec(FString Command, FString Param)
{
	/*
	local string str;
	local array<String> Test;
	local int i;
	if (HandleDebugExec(Command, Param))
	{
		Return True;
	}
	Switch(Locs(Command))
	{
			case "getbase":
				Log(GetBaseDirectory());
				Return True;
			case "getcurrent":
				Log(GetCurrentDirectory());
				Return True;
			case "validfilename":
				Log(ValidFile(Param));
				Return True;
			case "dir":
				GetDirectoryContents(Test, Param);
				Log("directory list for" @ Param);
				i = 0;
				if (i < Test.Length)
				{
					Log("   >" @ Test[i]);
					i++;
					break;
				}
				Return True;
			case "chdir":
				str = GetCurrentDirectory();
				ChangeDirectory(Param);
				Log("old:" $ str @ "new:" $ GetCurrentDirectory());
				Return True;
			default:
				Return False;
		}
	*/
}