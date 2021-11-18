// All the original content belonged to the US Army


#include "AA29/Info/InternetInfo/InternetLink/TcpLink/HttpGet/HttpGet.h"

AHttpGet::AHttpGet()
{
	_bDebug = true;
}


void AHttpGet::PostBeginPlay()
{
	/*
	Log("HttpGet::PostBeginPlay(): LinkState is " $ GetEnum(Enum'ELinkState', LinkState));
	*/
}
void AHttpGet::RequestText(FString FileHost, FString FilePath, int32 HostPort)
{
	/*
	if (HostPort == 0)
	{
		HostPort = 80;
	}
	_HostPort = HostPort;
	LinkMode = 0;
	BindPort(HostPort);
	RequestedText.Length = 0;
	_bMadeRequest = true;
	_Request = "GET ";
	_File = FilePath;
	_Protocol = " HTTP/1.1" $ Chr(13) $ Chr(10);
	_Agent = "User-Agent: Unreal" $ Chr(13) $ Chr(10);
	_Host = "Host: " $ FileHost $ Chr(13) $ Chr(10);
	_Connection = "Connection: Close" $ Chr(13) $ Chr(10) $ Chr(13) $ Chr(10);
	Resolve(FileHost);
	*/
}
void AHttpGet::RequestBinary(FString FileHost, FString FilePath, int32 HostPort)
{
	/*
	Return;
	if (HostPort == 0)
	{
		HostPort = 80;
	}
	_HostPort = HostPort;
	RequestedBinary.Length = 0;
	_ByteCount = 0;
	_PacketCount = 0;
	_bMadeRequest = true;
	LinkMode = 2;
	BindPort(HostPort);
	_Request = "GET ";
	_File = FilePath;
	_Protocol = " HTTP/1.1" $ Chr(13) $ Chr(10);
	_Host = "Host: " $ FileHost;
	_Agent = "User-Agent: Unreal" $ Chr(13) $ Chr(10);
	_Connection = "Connection: close" $ Chr(13) $ Chr(10) $ Chr(13) $ Chr(10);
	Resolve(FileHost);
	*/
}
void AHttpGet::ReceivedText(FString Text)
{
	/*
	if (_bMadeRequest)
	{
		RequestedText[RequestedText.Length] = Text;
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self, 16, None, "RecievedText");
		}
	}
	else
	{
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self, 16, None, "RecievedText_NotRequested");
		}
	}
	Log("HttpGet::ReceivedText()");
	*/
}
void AHttpGet::ReceivedLine(FString Line)
{
	/*
	Log("HttpGet::ReceivedLine()");
	*/
}
void AHttpGet::ReceivedBinary(int32 Count, uint8 B)
{
}
void AHttpGet::ReceivedLongBinary(int32 Count, int32 B)
{
	/*
	Log("HttpGet::ReceivedLongBinary()");
	*/
}
void AHttpGet::Resolved(FIpAddr Addr)
{
	/*
	if (_bMadeRequest)
	{
		Addr.Port = _HostPort;
		Open(Addr);
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self, 16, None, "Resolved");
		}
	}
	else
	{
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self, 16, None, "Resolved_NotRequested");
		}
	}
	Log("HttpGet::Resolved(): IP is: " $ IpAddrToString(Addr));
	*/
}
void AHttpGet::Opened()
{
	/*
	Log("HttpGet::Opened()");
	if (_bMadeRequest)
	{
		SendText(_Request $ _File $ _Protocol $ _Host $ _Agent $ _Connection);
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self, 16, None, "Opened");
		}
	}
	else
	{
		if (EventLab != None)
		{
			EventLab.ActorNotify(Self, 16, None, "Opened_NotRequested");
		}
	}
	*/
}
void AHttpGet::Closed()
{
	/*
	Log("HttpGet::Closed()");
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 16, None, "Closed");
	}
	_bMadeRequest = False;
	if (LinkMode == 2)
	{
		Log("HttpGet::Closed(): Byte Count Is: " $ _ByteCount);
		Log("HttpGet::Closed(): Packet Count Is: " $ _PacketCount);
	}
	*/
}
void AHttpGet::ResolveFailed()
{
	/*
	Log("HttpGet::ResolveFailed()");
	if (EventLab != None)
	{
		EventLab.ActorNotify(Self, 16, None, "ResoveFailed");
	}
	_bMadeRequest = False;
	*/
}
void AHttpGet::Timer()
{
}
void AHttpGet::LogConnectionStatus()
{
	/*
	Log("---------------------");
	Log("IsConnected: " $ IsConnected());
	Log("LinkState is: " $ GetEnum(Enum'ELinkState', LinkState));
	Log("LinkMode: " $ GetEnum(Enum'ELinkMode', LinkMode));
	Log("ReceiveMode: " $ GetEnum(Enum'EReceiveMode', ReceiveMode));
	*/
}