// All the original content belonged to the US Army

#include "AA29/Object/Commandlet/StreamCommandlet/StreamCommandlet.h"

UStreamCommandlet::UStreamCommandlet()
{

}
/*
int32 UStreamCommandlet::Main(FString Parms)
{
	FString Src = "";
	FString Match = "";
	if (!Divide(Parms, ";", Src, Match))
	{
		return 0;
	}
	Log("Source '" + Src + "'   Match '" + Match + "'");
	Log("Result of reverse search is" @ FString::FromInt(RevInStr(Src, Match)));
	Log("");
	chart(Src);
	return 0;
}
*/
void UStreamCommandlet::chart(FString Src)
{
	int32 i = 0;
	int32 j = 0;
	int32 k = 0;
	FString S = "";
	FString t = "";
	/*
	for (i = 0; i < Len(Src); i++)
	{
		j = int((float(i) % float(10)));
		if (j == 0)
		{
			k = (i / 10);
			t += FString::FromInt(k);
		}
		else
		{
			t += " ";
		}
		S += FString::FromInt(j);
	}
	Log(Src);
	Log(S);
	Log(t);
	*/
}

int32 UStreamCommandlet::RevInStr(FString Src, FString Match)
{
	int32 pos = 0;
	int32 i = 0;
	FString S = "";
	/*
	if ((Src == "") || (Match == ""))
	{
		return -1;
	}
	S = Src;
	i = InStr(S, Match);
	do
	{
		(pos += i);
		S = Mid(Src, (pos + 1));
		i = (InStr(S, Match) + 1);
	}
	until((i == 0));
	*/
	return pos;
}

