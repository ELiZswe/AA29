// All the original content belonged to the US Army

#include "AA29/Object/StreamBase/Stream/Stream.h"
#include "AA29/Object/StreamBase/StreamTag/StreamTag.h"

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

UStreamTag* UStream::GetTag()
{
	return IDTag;
}

EFileType UStream::GetType()
{
	return Type;
}

FString UStream::GetDirectory()
{
	return PathName.Directory;
}

FString UStream::GetFileName()
{
	return PathName.Filename;
}

FString UStream::GetExtension()
{
	return PathName.Extension;
}

FString UStream::GetPath()
{
	return PathName.FullPath;
}

FString UStream::GetFullName()
{
	return GetFileName() + "." + GetExtension();
}

FString UStream::GetSongTitle()
{
	if (IDTag == nullptr || IDTag->Title.FieldValue == "")
	{
		return GetFileName();
	}
	return IDTag->Title.FieldValue;
}

bool UStream::SetHandle(int32 NewHandle)
{
	Handle = NewHandle;
	return true;
}

void UStream::DumpScriptTag()
{
	IDTag->DumpScriptTag();
}

void UStream::DumpTags()
{
	IDTag->DumpTag();
}
