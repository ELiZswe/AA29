// All the original content belonged to the US Army


#include "AA29/Info/InternetInfo/InternetLink/TcpLink/BufferedTCPLink/BufferedTCPLink.h"

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
void ABufferedTCPLink::ParseDelimited(FString Text, FString Delimiter, int32 Count, bool bToEndOfLine)
{
	/*
	local string Result;
	local int Found;
	local int i;
	local string S;
	Result = "";
	Found = 1;
	for (i = 0; i < Len(Text); i++)
	{
		S = Mid(Text, i, 1);
		if (InStr(Delimiter, S) != -1)
		{
			if (Found == Count)
			{
				if (bToEndOfLine)
				{
					Return Result $ Mid(Text, i);
				}
				else
				{
					Return Result;
				}
			}
			Found++;
		}
		else
		{
			if (Found >= Count)
			{
				Result = Result $ S;
			}
		}
	}
	Return Result;
	*/
}
void ABufferedTCPLink::ReadChar()
{
	/*
	local int C;
	if (InputBuffer == "")
	{
		Return 0;
	}
	C = Asc(Left(InputBuffer, 1));
	InputBuffer = Mid(InputBuffer, 1);
	Return C;
	*/
}
void ABufferedTCPLink::PeekChar()
{
	/*
	if (InputBuffer == "")
	{
		Return 0;
	}
	Return Asc(Left(InputBuffer, 1));
	*/
}
void ABufferedTCPLink::ReadBufferedLine(FString &Text)
{
	/*
	if (InputBuffer == "")
	{
		Return False;
	}
	if (Divide(InputBuffer, CRLF, Text, InputBuffer))
	{
		Return True;
	}
	if (Divide(InputBuffer, CR, Text, InputBuffer))
	{
		Return True;
	}
	if (Divide(InputBuffer, LF, Text, InputBuffer))
	{
		Return True;
	}
	Return False;
	*/
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
	local int i;
	if (bWaiting)
	{
		if (GetWorld()->GetTimeSeconds() > WaitTimeoutTime)
		{
			bWaiting = False;
			GotMatchTimeout(WaitMatchData);
		}
		if (WaitForCountChars > 0)
		{
			if (Len(InputBuffer) < WaitForCountChars)
			{
			}
			WaitResult = Left(InputBuffer, WaitForCountChars);
			InputBuffer = Mid(InputBuffer, WaitForCountChars);
			bWaiting = False;
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
				bWaiting = False;
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