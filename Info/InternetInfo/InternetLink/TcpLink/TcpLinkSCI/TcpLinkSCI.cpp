// All the original content belonged to the US Army


#include "AA29/Info/InternetInfo/InternetLink/TcpLink/TcpLinkSCI/TcpLinkSCI.h"

ATcpLinkSCI::ATcpLinkSCI()
{
	masterHostname = "master0.supercomputerinc.com";
	masterPort = 14200;
	expectedBytes = -1;
}



void ATcpLinkSCI::dlog(FString str)
{
	/*
	if (debugging)
	{
		if (Len(str) >= 900)
		{
			str = Left(str, 900);
			str = str $ " [...text clipped...]";
		}
		Log("debug " $ str);
	}
	*/
}
void ATcpLinkSCI::convFromMetaChars(FString &S)
{
	/*
	local int pos;
	if (True)
	{
		pos = InStr(S, "&quot;");
		if (pos != -1)
		{
			S = Left(S, pos) $ """" $ Mid(S, pos + 6);
		}
		else
		{
			pos = InStr(S, "&amp;");
			if (pos != -1)
			{
				S = Left(S, pos) $ "&" $ Mid(S, pos + 5);
			}
			else
			{
				pos = InStr(S, "&gt;");
				if (pos != -1)
				{
					S = Left(S, pos) $ ">" $ Mid(S, pos + 4);
				}
				else
				{
					pos = InStr(S, "&lt;");
					if (pos != -1)
					{
						S = Left(S, pos) $ "<" $ Mid(S, pos + 4);
					}
					else
					{
					}
				}
			}
		}
	else
	{
	}
	}
	*/
}
void ATcpLinkSCI::convToMetaChars(FString &S)
{
	/*
	local int pos;
	local string tmp;
	tmp = "";
	if (True)
	{
		pos = InStr(S, "&");
		if (pos == -1)
		{
			tmp = tmp $ S;
		}
		else
		{
			tmp = tmp $ Left(S, pos) $ "&amp;";
			S = Mid(S, pos + 1);
		}
	}
	S = tmp;
	if (True)
	{
		pos = InStr(S, """");
		if (pos != -1)
		{
			S = Left(S, pos) $ "&quot;" $ Mid(S, pos + 1);
		}
		else
		{
			pos = InStr(S, "<");
			if (pos != -1)
			{
				S = Left(S, pos) $ "&lt;" $ Mid(S, pos + 1);
			}
			else
			{
				pos = InStr(S, ">");
				if (pos != -1)
				{
					S = Left(S, pos) $ "&gt;" $ Mid(S, pos + 1);
				}
				else
				{
				}
			}
		}
	else
	{
	}
	}
	*/
}
bool ATcpLinkSCI::StillProcessing()
{
	return bWorking;
}
bool ATcpLinkSCI::HadError()
{
	return bError;
}
void ATcpLinkSCI::Connect()
{
	/*
	LinkMode = 2;
	ReceiveMode = 1;
	bShouldBeConnected = true;
	bError = False;
	if (IsConnected())
	{
		bWorking = False;
		Return;
	}
	bWorking = true;
	if (BindPort() == 0)
	{
		Log("TcpLinkSCI: BindPort failed.");
		bWorking = False;
		bError = true;
		Return;
	}
	if (IP.Addr == 0)
	{
		Resolve(masterHostname);
	}
	else
	{
		if (!Open(IP))
		{
			Log("TcpLinkSCI: Open() failed!");
			bWorking = False;
			bError = true;
		}
	}
	*/
}
void ATcpLinkSCI::RequestRawXML(FString xml)
{
	/*
	SendRequestRawXML(xml);
	*/
}
void ATcpLinkSCI::RequestServerCount(FString aGameType, FString extraxml)
{
	/*
	SendRequest(GameType, "GETSERVERCOUNT", extraxml);
	*/
}
void ATcpLinkSCI::RequestServerInfo(FString aGameType, FString Guid)
{
	/*
	SendRequestRawXML("<?xml version=""1.0""?><GSMS><MESSAGES><MESSAGE><ACTION>GETSERVERINFO</ACTION><GUID>" $ Guid $ "</GUID></MESSAGE></MESSAGES></GSMS>");
	*/
}
void ATcpLinkSCI::RequestServerList(FString aGameType, int32 page, int32 pagesize, FString extraxml)
{
	/*
	extraxml = "<PAGE>" $ page $ "</PAGE><PAGESIZE>" $ pagesize $ "</PAGESIZE>" $ extraxml;
	SendRequest(GameType, "GETSERVERLIST", extraxml);
	*/
}
void ATcpLinkSCI::RequestRegistration(FString aGameType, FString version, FString hostname, FString Addr, int32 aPort, int32 QueryPort, FString Map, int32 bPrivate, int32 NumPlayers, int32 MaxPlayers, FString modname, FString extraxml)
{
	/*
	SendRequestRawXML("<?xml version=""1.0""?><GSMS><MESSAGES><MESSAGE><ACTION>REGISTERSERVER</ACTION><SERVERTYPE>" $ GameType $ "</SERVERTYPE><MBS_HOSTNAME>" $ hostname $ "</MBS_HOSTNAME><MBS_IPADDRESS>" $ Addr $ "</MBS_IPADDRESS><MBS_QUERYPORT>" $ QueryPort $ "</MBS_QUERYPORT><MBS_HOSTPORT>" $ Port $ "</MBS_HOSTPORT><MBS_MAP>" $ Map $ "</MBS_MAP><MBS_PRIVATE>" $ bPrivate $ "</MBS_PRIVATE><MBS_PLAYERS>" $ NumPlayers $ "</MBS_PLAYERS><MBS_MAXPLAYERS>" $ MaxPlayers $ "</MBS_MAXPLAYERS><MBS_VERSION>" $ version $ "</MBS_VERSION><MBS_MOD>" $ modname $ "</MBS_MOD>" $ extraxml $ "</MESSAGE></MESSAGES></GSMS>");
	*/
}
void ATcpLinkSCI::RequestHeartbeat(FString Guid)
{
	/*
	SendRequestRawXML("<?xml version=""1.0""?><GSMS><MESSAGES><MESSAGE><ACTION>HEARTBEAT</ACTION><GUID>" $ Guid $ "</GUID></MESSAGE></MESSAGES></GSMS>");
	*/
}
void ATcpLinkSCI::GetCurrentResponseSize()
{
	/*
	if (expectedBytes < 0)
	{
		Return 0;
	}
	Return expectedBytes - incomingBytesLeft;
	*/
}
void ATcpLinkSCI::GetResponseString()
{
	/*
	Return responseString;
	*/
}
void ATcpLinkSCI::Disconnect()
{
	/*
	bShouldBeConnected = False;
	bWorking = IsConnected();
	bError = False;
	if (bWorking)
	{
		Close();
	}
	*/
}
void ATcpLinkSCI::PreBeginPlay()
{
	/*
	dlog("TcpLinkSCI: Spawning...");
	dlog("TcpLinkSCI: !!! FIXME debug output is enabled!");
	IP.Addr = 0;
	IP.Port = masterPort;
	Super::PreBeginPlay();
	*/
}
void ATcpLinkSCI::Resolved(FIpAddr Addr)
{
	/*
	IP.Addr = Addr.Addr;
	if (!Open(IP))
	{
		Log("TcpLinkSCI: Open() failed!");
		bWorking = False;
		bError = true;
	}
	*/
}
void ATcpLinkSCI::ResolveFailed()
{
	/*
	Log("TcpLinkSCI: Resolution of " $ masterHostname $ " failed!");
	bError = true;
	bWorking = False;
	*/
}
void ATcpLinkSCI::Opened()
{
	bWorking = false;
	bError   = false;
}
void ATcpLinkSCI::SendRequestRawXML(FString xml)
{
	/*
	local byte Header;
	local int reqlen;
	LinkMode = 2;
	reqlen = Len(xml);
	Header[0] = Asc("G");
	Header[1] = Asc("S");
	Header[2] = Asc("M");
	Header[3] = Asc("S");
	Header[4] = Asc("0");
	Header[5] = Asc("1");
	Header[6] = Asc("0");
	Header[7] = Asc("0");
	Header[8] = 0;
	Header[9] = 0;
	Header[10] = 0;
	Header[11] = 0;
	Header[12] = reqlen;
	Header[13] = reqlen >> 8;
	Header[14] = reqlen >> 16;
	Header[15] = reqlen >> 24;
	Header[16] = Header[12];
	Header[17] = Header[13];
	Header[18] = Header[14];
	Header[19] = Header[15];
	bWorking = true;
	bError = False;
	responseString = "";
	incomingBytesLeft = -20;
	expectedBytes = -1;
	dlog("TcpLinkSCI: sending raw xml: [" $ xml $ "]");
	SendBinary(20, Header);
	SendText(xml);
	reqlen += 20;
	*/
}
void ATcpLinkSCI::SendRequest(FString aGameType, FString Action, FString extraxml)
{
	/*
	local string xml;
	xml = "<?xml version=""1.0""?><GSMS><MESSAGES><MESSAGE><ACTION>" $ Action $ "</ACTION><SERVERTYPE>" $ GameType $ "</SERVERTYPE>" $ extraxml $ "</MESSAGE></MESSAGES></GSMS>";
	SendRequestRawXML(xml);
	*/
}
void ATcpLinkSCI::ReceivedBinary(int32 Count, uint8 B)
{
	/*
	local int i;
	local int Max;
	local int i0;
	local int i1;
	local int i2;
	local int i3;
	local string tmpstr;
	if (incomingBytesLeft < 0)
	{
		Max = -incomingBytesLeft;
		if (Count < Max)
		{
			Max = Count;
		}
		for (i = 0; i < Max; i++)
		{
			responseHeader[incomingBytesLeft + 20] = B[i];
			incomingBytesLeft++;
		}
		if (incomingBytesLeft >= 0)
		{
			tmpstr = Chr(responseHeader[0]) $ Chr(responseHeader[1]) $ Chr(responseHeader[2]) $ Chr(responseHeader[3]);
			if (tmpstr != "GSMS")
			{
				Log("TcpLinkSCI: Got invalid signature (" $ tmpstr $ ") in response header.");
				Close();
				Return;
			}
			if (responseHeader[8] != 0)
			{
				Log("TcpLinkSCI: Got unexpected response in header[8] (" $ responseHeader[8] $ ").");
				Close();
				Return;
			}
			i0 = responseHeader[12];
			i1 = responseHeader[13];
			i2 = responseHeader[14];
			i3 = responseHeader[15];
			expectedBytes = i0 | i1 << 8 | i2 << 16 | i3 << 24;
			incomingBytesLeft = expectedBytes;
			tmpstr = "";
			for (i = Max; i < Count; i++)
			{
				tmpstr = tmpstr $ Chr(B[i]);
			}
			LinkMode = 0;
			ReceivedText(tmpstr);
		}
	}
	else
	{
		Log("TcpLinkSCI: Received unexpected binary data.");
	}
	*/
}
void ATcpLinkSCI::ReceivedText(FString Text)
{
	/*
	responseString = responseString $ Text;
	incomingBytesLeft -= Len(Text);
	if (incomingBytesLeft <= 0)
	{
		dlog("TcpLinkSCI: Got entire response from server.");
		dlog("TcpLinkSCI: response string: [" $ responseString $ "]");
		bWorking = False;
		bError = False;
	}
	*/
}
void ATcpLinkSCI::Closed()
{
	/*
	if (bShouldBeConnected)
	{
		Log("TcpLinkSCI: Link closed unexpectedly.");
	}
	bError = bShouldBeConnected;
	bShouldBeConnected = False;
	bWorking = False;
	*/
}
