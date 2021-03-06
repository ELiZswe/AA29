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
	int32 i = 0;
	//i = InStr(InPath, GetPathSeparator() + GetPathSeparator());
	if (i == -1)
	{
		//i = InStr(InPath, ":" + GetPathSeparator());
	}
	if (i != -1)
	{
		root = InPath.Left(i + 1);
		InPath = InPath.Mid(i + 2);
	}
	return root;
}

bool UStreamBase::HasExtension(FString Test)
{
	return ParseExtension(Test) != "";
}

bool UStreamBase::ParsePath(FString InPath, FFilePath &ParsedPath)
{
	int32 i = 0;
	if (InPath == "")
	{
		return false;
	}
	/*
	ParsedPath->FullPath = InPath;
	i = RevInStr(InPath, GetPathSeparator());
	if (i != -1)
	{
		ParsedPath->Directory = InPath.Left(i + 1);
	}
	ParsedPath->DirectoryParts = ParseDirectories(InPath);
	ParsedPath->Extension = ParseExtension(InPath);
	ParsedPath->Filename = InPath;
	return ParsedPath->DirectoryParts.Num() > 0 || ParsedPath->Extension != "" && ParsedPath->Filename != "";
	*/

	return true;    //FAKE   /ELiZ
}

FString UStreamBase::ParseExtension(FString &FileNameWithExtension)
{
	int32 i = 0;
	FString Ext = "";
	if (FileNameWithExtension == "")
	{
		return "";
	}
	i = RevInStr(FileNameWithExtension, ".");
	if (i >= 0)
	{
		Ext = FileNameWithExtension.Mid(i + 1);
	}
	if (ConvertToFileType(Ext) !=EFileType::FILE_None)
	{
		FileNameWithExtension = FileNameWithExtension.Left(i);
		//return Locs(Ext);
	}
	return "";
}

TArray<FString>  UStreamBase::ParseDirectories(FString &InPath)
{
	TArray<FString> Directories;
	Directories.Reset();
	FString root = "";
	/*
	root = GetPathRoot(InPath);
	Split(InPath, GetPathSeparator(), Directories);
	InPath = "";
	if (root != "")
	{
		Directories.insert(0, 1);
		Directories[0] = root;
	}
	if (HasExtension(Directories[Directories.Num() - 1]))
	{
		InPath = Directories[Directories.Num() - 1];
		Directories.Num() = Directories.Num() - 1;
	}
	*/
	return Directories;
}

int32 UStreamBase::RevInStr(FString Src, FString Match)
{
	int32 pos = 0;
	int32 i = 0;
	FString S = "";
	if (Src == "" || Match == "")
	{
		return - 1;
	}
	S = Src;
	//i = InStr(S, Match);
	pos += i;
	S = Src.Mid(pos + 1);
	//i = InStr(S, Match) + 1;
	if (i == 0)
	{
		return pos;
	}
	return 0;    //FAKE    /EliZ
}

FString UStreamBase::FormatTimeDisplay(float Seconds)
{
	int32 i = 0;
	FString TimeString = "";
	i = Seconds / 3600;
	if (i > 0)
	{
		TimeString = i + ":";
	}
	i = Seconds / 60;
	if (TimeString != "" && i < 10)
	{
		TimeString += "0";
	}
	TimeString += i + ":";
	//i = Seconds % 60;
	if (i < 10)
	{
		TimeString += "0";
	}
	TimeString += FString::FromInt(i);
	return TimeString;
}

FString UStreamBase::ConvertToFileExtension(EFileType aType)
{
	switch(aType)
	{
		case	EFileType::FILE_Log:
			return ".log";
		case EFileType::FILE_Ini:
			return ".ini";
		case EFileType::FILE_Playlist:
			return ".m3u;.pls;.b4s";
		case EFileType::FILE_Music:
			return ".umx";
		case EFileType::FILE_Map:
			return ".ut2";
		case EFileType::FILE_Texture:
			return ".utx";
		case EFileType::FILE_Animation:
			return ".ukx";
		case EFileType::FILE_Static:
			return ".usx";
		case EFileType::FILE_XML:
			return ".xml";
		case EFileType::FILE_HTML:
			return ".html;.htm";
		case EFileType::FILE_Sound:
			return ".uax";
		case EFileType::FILE_Demo:
			return ".DEMO4";
		case EFileType::FILE_DivX:
			return ".avi";
		case EFileType::FILE_Stream:
			return ".mp3;.ogg";
		default:
			return "";
			break;
	}
	return "";     //FAKE   /ELiZ
}

EFileType UStreamBase::ConvertToFileType(FString Extension)
{
	FString Ext = "";
	if (Extension == "")
	{
		return EFileType::FILE_None;
	}
	Ext = ParseExtension(Extension);
	if (Ext == "")
	{
		Ext = Extension;
	}
	//Ext = Locs(Ext);
	if (Ext == "mp3") { return EFileType::FILE_Stream; }
	if (Ext == "ogg") { return EFileType::FILE_Stream; }
	if (Ext == "wav") { return EFileType::FILE_Music; }
	if (Ext == "umx") { return EFileType::FILE_Music; }
	if (Ext == "ut2") { return EFileType::FILE_Map; }
	if (Ext == "ukx") { return EFileType::FILE_Animation; }
	if (Ext == "uax") { return EFileType::FILE_Sound; }
	if (Ext == "utx") { return EFileType::FILE_Texture; }
	if (Ext == "dem") { return EFileType::FILE_Demo; }
	if (Ext == "usx") { return EFileType::FILE_Static; }
	if (Ext == "ini") { return EFileType::FILE_Ini; }
	if (Ext == "log") { return EFileType::FILE_Log; }
	if (Ext == "avi") { return EFileType::FILE_DivX; }
	if (Ext == "xml") { return EFileType::FILE_XML; }
	if (Ext == "html") { return EFileType::FILE_HTML; }
	if (Ext == "htm")  { return EFileType::FILE_HTML; }
	if (Ext == "m3u") { return EFileType::FILE_Playlist; }
	if (Ext == "b4s") { return EFileType::FILE_Playlist; }
	if (Ext == "pls") { return EFileType::FILE_Playlist; }
	return EFileType::FILE_None;
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
