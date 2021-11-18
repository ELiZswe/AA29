// All the original content belonged to the US Army


#include "AA29/Object/StreamBase/Stream/Stream.h"

UStream::UStream()
{
	Handle = -1;
	DefaultExtension = "mp3";
}


//native final Function SaveID3Tag();
void UStream::SaveID3Tag()
{
}

//native final Function LoadID3Tag();
void UStream::LoadID3Tag()
{
}


bool UStream::IsReadOnly()
{
	return bReadOnly;
}
int32 UStream::GetHandle()
{
	return Handle;
}
void UStream::GetTag()
{
	//return IDTag;
}
void UStream::GetType()
{
	//return Type;
}
void UStream::GetDirectory()
{
	//return PathName.Directory;
}
void UStream::GetFileName()
{
	//return PathName.Filename;
}
void UStream::GetExtension()
{
	//return PathName.Extension;
}
void UStream::GetPath()
{
	//return PathName.FullPath;
}
void UStream::GetFullName()
{
	//return GetFileName() $ "." $ GetExtension();
}
void UStream::GetSongTitle()
{
	/*
	if (IDTag == None || IDTag.Title.FieldValue == "")
	{
		Return GetFileName();
	}
	Return IDTag.Title.FieldValue;
	*/
}
bool UStream::SetHandle(int32 NewHandle)
{
	Handle = NewHandle;
	return true;
}
void UStream::DumpScriptTag()
{
	//IDTag.DumpScriptTag();
}
void UStream::DumpTags()
{
	//IDTag.DumpTag();
}