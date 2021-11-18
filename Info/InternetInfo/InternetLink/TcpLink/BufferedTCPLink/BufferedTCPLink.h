// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/InternetInfo/InternetLink/TcpLink/TcpLink.h"
#include "BufferedTCPLink.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABufferedTCPLink : public ATcpLink
{
	GENERATED_BODY()
public:
	ABufferedTCPLink();

	UPROPERTY()			int32 WaitMatchData;								//var int WaitMatchData;
	UPROPERTY()			FString WaitResult;									//var string WaitResult;
	UPROPERTY()			int32 WaitForCountChars;							//var int WaitForCountChars;
	UPROPERTY()			FString WaitingFor;									//var string WaitingFor;
	UPROPERTY()			float WaitTimeoutTime;								//var float WaitTimeoutTime;
	UPROPERTY()			bool bWaiting;										//var bool bWaiting;
	UPROPERTY()			FString LF;											//var string LF;
	UPROPERTY()			FString CR;											//var string CR;
	UPROPERTY()			FString CRLF;										//var string CRLF;
	UPROPERTY()			FString OutputBuffer;								//var string OutputBuffer;
	UPROPERTY()			FString InputBuffer;								//var string InputBuffer;

	void ResetBuffer();
	void WaitFor(FString What, float TimeOut, int32 MatchData);
	void WaitForCount(int32 Count, float TimeOut, int32 MatchData);
	void GotMatch(int32 MatchData);
	void GotMatchTimeout(int32 MatchData);
	void ParseDelimited(FString Text, FString Delimiter, int32 Count, bool bToEndOfLine);
	void ReadChar();
	void PeekChar();
	void ReadBufferedLine(FString& Text);
	void SendBufferedData(FString Text);
	void ReceivedText(FString Text);
	void DoBufferQueueIO();

};
