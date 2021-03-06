// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/BufferedTCPLink.h"

ABufferedTCPLink::ABufferedTCPLink()
{
	ReceiveMode = EReceiveMode::RMODE_Event;
}

void ABufferedTCPLink::ResetBuffer()
{
	InputBuffer = "";
	OutputBuffer = "";
	bWaiting = false;
	CR = "";
	LF = "";
	CR.AppendChar(TCHAR(13));
	LF.AppendChar(TCHAR(10));
	CRLF = CR + LF;
}
void ABufferedTCPLink::WaitFor(FString What, float TimeOut, int32 MatchData)
{
	bWaiting = true;
	WaitingFor = What;
	WaitForCountChars = 0;
	WaitTimeoutTime = GetWorld()->GetTimeSeconds() + TimeOut;
	WaitMatchData = MatchData;
	WaitResult = "";
}
void ABufferedTCPLink::WaitForCount(int32 Count, float TimeOut, int32 MatchData)
{
	bWaiting = true;
	WaitingFor = "";
	WaitForCountChars = Count;
	WaitTimeoutTime = GetWorld()->GetTimeSeconds() + TimeOut;
	WaitMatchData = MatchData;
	WaitResult = "";
}

void ABufferedTCPLink::GotMatch(int32 MatchData)
{
}

void ABufferedTCPLink::GotMatchTimeout(int32 MatchData)
{
}

FString ABufferedTCPLink::ParseDelimited(FString Text, FString Delimiter, int32 Count, bool bToEndOfLine)
{
	FString Result = "";
	int32 Found = 0;
	int32 i = 0;
	FString S = "";
	Result = "";
	Found = 1;
	/*
	for (i = 0; i < Len(Text); i++)
	{
		S = Mid(Text, i, 1);
		if (InStr(Delimiter, S) != -1)
		{
			if (Found == Count)
			{
				if (bToEndOfLine)
				{
					return Result + Mid(Text, i);
				}
				else
				{
					return Result;
				}
			}
			Found++;
		}
		else
		{
			if (Found >= Count)
			{
				Result = Result + S;
			}
		}
	}
	*/
	return Result;
}

int32 ABufferedTCPLink::ReadChar()
{
	int32 C = 0;
	/*
	if (InputBuffer == "")
	{
		return 0;
	}
	C = Asc(Left(InputBuffer, 1));
	InputBuffer = Mid(InputBuffer, 1);
	*/
	return C;
}

int32 ABufferedTCPLink::PeekChar()
{
	/*
	if (InputBuffer == "")
	{
		return 0;
	}
	return Asc(Left(InputBuffer, 1));
	*/
	return 0;   //FAKE   /EliZ
}

bool ABufferedTCPLink::ReadBufferedLine(FString &Text)
{
	/*
	if (InputBuffer == "")
	{
		return false;
	}
	if (Divide(InputBuffer, CRLF, Text, InputBuffer))
	{
		return true;
	}
	if (Divide(InputBuffer, CR, Text, InputBuffer))
	{
		return true;
	}
	if (Divide(InputBuffer, LF, Text, InputBuffer))
	{
		return true;
	}
	*/
	return false;
}

void ABufferedTCPLink::SendBufferedData(FString Text)
{
	OutputBuffer += Text;
}
void ABufferedTCPLink::ReceivedText(FString Text)
{
	InputBuffer += Text;
}
void ABufferedTCPLink::DoBufferQueueIO()
{
	/*
	int32 i = 0;
	if (bWaiting)
	{
		if (GetWorld()->GetTimeSeconds() > WaitTimeoutTime)
		{
			bWaiting = false;
			GotMatchTimeout(WaitMatchData);
		}
		if (WaitForCountChars > 0)
		{
			if (Len(InputBuffer) < WaitForCountChars)
			{
			}
			WaitResult = Left(InputBuffer, WaitForCountChars);
			InputBuffer = Mid(InputBuffer, WaitForCountChars);
			bWaiting = false;
			GotMatch(WaitMatchData);
		}
		else
		{
		else
		{
			i = InStr(InputBuffer, WaitingFor);
			if (i == -1 && WaitingFor == CR)
			{
				i = InStr(InputBuffer, LF);
			}
			if (i != -1)
			{
				WaitResult = Left(InputBuffer, i + Len(WaitingFor));
				InputBuffer = Mid(InputBuffer, i + Len(WaitingFor));
				bWaiting = false;
				GotMatch(WaitMatchData);
			}
			else
			{
			}
		}
	else
	{
	}
		}
	}
	if (IsConnected())
	{
		if (OutputBuffer != "")
		{
			i = SendText(OutputBuffer);
			OutputBuffer = Mid(OutputBuffer, i);
		}
	}
	*/
}
