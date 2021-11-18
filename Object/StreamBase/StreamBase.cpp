// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/StreamBase.h"

UStreamBase::UStreamBase()
{

}


//native static final operator(40) String* (coerce string A, coerce string B);

//native static final operator(44) String *= (out string A, coerce string B);

//native static final Function GetPathSeparator();
void UStreamBase::GetPathSeparator()
{
}

//native static final Function IsCaseSensitive();
bool UStreamBase::IsCaseSensitive()
{
	return false;   //FAKE   /EliZ
}

FString UStreamBase::GetPathRoot(FString &InPath)
{
	FString root = "";
	/*
	local int i;
	i = InStr(InPath, GetPathSeparator() $ GetPathSeparator());
	if (i == -1)
	{
		i = InStr(InPath, ":" $ GetPathSeparator());
	}
	if (i != -1)
	{
		root = Left(InPath, i + 1);
		InPath = Mid(InPath, i + 2);
	}
	*/
	return root;
}
bool UStreamBase::HasExtension(FString Test)
{
	return ParseExtension(Test) != "";
}
bool UStreamBase::ParsePath(FString InPath, FFilePath &ParsedPath)
{
	/*
	local int i;
	if (InPath == "")
	{
		Return False;
	}
	ParsedPath.FullPath = InPath;
	i = RevInStr(InPath, GetPathSeparator());
	if (i != -1)
	{
		ParsedPath.Directory = Left(InPath, i + 1);
	}
	ParsedPath.DirectoryParts = ParseDirectories(InPath);
	ParsedPath.Extension = ParseExtension(InPath);
	ParsedPath.Filename = InPath;
	Return ParsedPath.DirectoryParts.Length > 0 || ParsedPath.Extension != "" && ParsedPath.Filename != "";
	*/

	return true;    //FAKE   /ELiZ
}
FString UStreamBase::ParseExtension(FString &FileNameWithExtension)
{
	/*
	local int i;
	local string Ext;
	if (FileNameWithExtension == "")
	{
		Return "";
	}
	i = RevInStr(FileNameWithExtension, ".");
	if (i >= 0)
	{
		Ext = Mid(FileNameWithExtension, i + 1);
	}
	if (ConvertToFileType(Ext) != 0)
	{
		FileNameWithExtension = Left(FileNameWithExtension, i);
		Return Locs(Ext);
	}
	*/
	return "";
}
TArray<FString>  UStreamBase::ParseDirectories(FString &InPath)
{

	TArray<FString> Directories;
	Directories.Reset();
	/*
	local string root;
	root = GetPathRoot(InPath);
	Split(InPath, GetPathSeparator(), Directories);
	InPath = "";
	if (root != "")
	{
		Directories.insert(0, 1);
		Directories[0] = root;
	}
	if (HasExtension(Directories[Directories.Length - 1]))
	{
		InPath = Directories[Directories.Length - 1];
		Directories.Length = Directories.Length - 1;
	}
	*/
	return Directories;
}
void UStreamBase::RevInStr(FString Src, FString Match)
{
	/*
	local int pos;
	local int i;
	local string S;
	if (Src == "" || Match == "")
	{
		Return - 1;
	}
	S = Src;
	i = InStr(S, Match);
	pos += i;
	S = Mid(Src, pos + 1);
	i = InStr(S, Match) + 1;
	if (i == 0)
	{
		Return pos;
	}
	*/
}
void UStreamBase::FormatTimeDisplay(float Seconds)
{
	/*
	local int i;
	local string TimeString;
	i = Seconds / 3600;
	if (i > 0)
	{
		TimeString = i $ ":";
	}
	i = Seconds / 60;
	if (TimeString != "" && i < 10)
	{
		TimeString $ = "0";
	}
	TimeString $ = i $ ":";
	i = Seconds % 60;
	if (i < 10)
	{
		TimeString $ = "0";
	}
	TimeString $ = i;
	Return TimeString;
	*/
}

FString UStreamBase::ConvertToFileExtension(EFileType aType)
{
	/*
	switch(aType)
	{
		case 2:
			return ".log";
		case 3:
			return ".ini";
		case 5:
			return ".m3u;.pls;.b4s";
		case 6:
			return ".umx";
		case 7:
			return ".ut2";
		case 8:
			return ".utx";
		case 9:
			return ".ukx";
		case 10:
			return ".usx";
		case 11:
			return ".xml";
		case 12:
			return ".html;.htm";
		case 13:
			return ".uax";
		case 14:
			return ".DEMO4";
		case 15:
			return ".avi";
		case 4:
			return ".mp3;.ogg";
		default:
			return "";
			break;
	}
	*/

	return "";     //FAKE   /ELiZ
}
uint8 UStreamBase::ConvertToFileType(FString Extension)
{
	/*
	local string Ext;
	if (Extension == "")
	{
		Return 0;
	}
	Ext = ParseExtension(Extension);
	if (Ext == "")
	{
		Ext = Extension;
	}
	Ext = Locs(Ext);
	switch (Ext)
	{
	case "mp3":
	case "ogg":
		return 4;
	case "wav":
	case "umx":
		return 6;
	case "ut2":
		return 7;
	case "ukx":
		return 9;
	case "uax":
		return 13;
	case "utx":
		return 8;
	case "dem":
		return 14;
	case "usx":
		return 10;
	case "ini":
		return 3;
	case "log":
		return 2;
	case "avi":
		return 15;
	case "xml":
		return 11;
	case "html":
	case "htm":
		return 12;
	case "m3u":
	case "b4s":
	case "pls":
		return 5;
	default:
		return 0;
	}
	*/
	return 0;    //FAKE   /ELiZ
}

bool UStreamBase::CompareNames(FString NameA, FString NameB)
{
	if (IsCaseSensitive())
	{
		return NameA == NameB;
	}

	//return NameA ~= NameB;
	return false;    //Fake  /ELiZ
}

bool UStreamBase::HandleDebugExec(FString Command, FString Param)
{
	return false;
}
