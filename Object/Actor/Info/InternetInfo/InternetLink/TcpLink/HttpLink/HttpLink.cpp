// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/HttpLink/HttpLink.h"

AHttpLink::AHttpLink()
{
	TargetPort = 80;
	TargetVersionFolder = "/2.8.5";
	CacheFileName = "DynamicContent\\NML\\Cache.ini";
	MAX_RETRIES = 3;
}

//native Function CheckBinaryMD5(array<byte> File);
void AHttpLink::CheckBinaryMD5(TArray<uint8> File)
{
}

//native Function CheckTextMD5(FString File);
void AHttpLink::CheckTextMD5(FString File)
{
}

void AHttpLink::PauseDownloads()
{
	bPaused = true;
}
void AHttpLink::ResumeDownloads()
{
	bPaused = false;
	if (!bConnectionBusy)
	{
		GetNextFile();
	}
}
void AHttpLink::SetHost(FString Host, int32 HostPort)
{
	TargetHost = Host;
	if (HostPort != 0)
	{
		TargetPort = HostPort;
	}
}
void AHttpLink::SetLocalFilePath(FString ContentPath)
{
	/*
	LocalFilePath = ContentPath;
	*/
}
void AHttpLink::Connect()
{
	/*
	local int boundport;
	boundport = BindPort(, true);
	if (bVerboseLogging)
	{
		Log("HTTP Bound Port:  " $ boundport);
	}
	Resolve(TargetHost);
	*/
}
void AHttpLink::Disconnect()
{
	/*
	if (QueuedFiles.Length > 0)
	{
		Log("HTTPLink Warning:  Closing connection with " $ QueuedFiles.Length $ " pending requests!");
	}
	*/
}
void AHttpLink::RequestText(FString FilePath)
{
	/*
	local int i;
	local string CacheFilePath;
	local string ETag;
	i = QueuedFiles.Length;
	QueuedFiles.insert(i, 1);
	QueuedFiles[i] = new () class'HttpLinkItem';
	QueuedFiles[i].Filename = FilePath;
	QueuedFiles[i].bIsBinary = False;
	QueuedFiles[i].GetRequest = "GET " $ TargetVersionFolder $ FilePath $ " HTTP/1.1" $ Chr(13) $ Chr(10);
	QueuedFiles[i].GetRequest $ = "Host: " $ TargetHost $ Chr(13) $ Chr(10);
	QueuedFiles[i].GetRequest $ = "Connection: Close" $ Chr(13) $ Chr(10);
	CacheFilePath = GetBaseDir() $ CacheFileName;
	if (DoesFileExist(CacheFileName))
	{
		if (DoesFileExist(FixFilePath(FilePath)))
		{
			ETag = GetPrivateProfileString(CacheFilePath, "Cached Content", FilePath);
			QueuedFiles[i].GetRequest $ = "If-None-Match: " $ """" $ ETag $ """" $ Chr(13) $ Chr(10);
		}
	}
	QueuedFiles[i].GetRequest $ = Chr(13) $ Chr(10) $ Chr(13) $ Chr(10);
	if (QueuedFiles.Length == 1)
	{
		GetNextFile();
	}
	Return QueuedFiles[i];
	*/
}
void AHttpLink::RequestBinary(FString FilePath)
{
	/*
	local int i;
	local string CacheFilePath;
	local string ETag;
	i = QueuedFiles.Length;
	QueuedFiles.insert(i, 1);
	QueuedFiles[i] = new () class'HttpLinkItem';
	QueuedFiles[i].Filename = FilePath;
	QueuedFiles[i].bIsBinary = true;
	QueuedFiles[i].GetRequest = "GET " $ TargetVersionFolder $ FilePath $ " HTTP/1.1" $ Chr(13) $ Chr(10);
	QueuedFiles[i].GetRequest $ = "Host: " $ TargetHost $ Chr(13) $ Chr(10);
	QueuedFiles[i].GetRequest $ = "Connection: Close" $ Chr(13) $ Chr(10);
	CacheFilePath = GetBaseDir() $ CacheFileName;
	if (DoesFileExist(CacheFilePath))
	{
		if (DoesFileExist(FixFilePath(FilePath)))
		{
			ETag = GetPrivateProfileString(CacheFilePath, "Cached Content", FilePath);
			QueuedFiles[i].GetRequest $ = "If-None-Match: " $ """" $ ETag $ """" $ Chr(13) $ Chr(10);
		}
	}
	QueuedFiles[i].GetRequest $ = Chr(13) $ Chr(10);
	if (QueuedFiles.Length == 1)
	{
		GetNextFile();
	}
	Return QueuedFiles[i];
	*/
}
void AHttpLink::GetNextFile()
{
	/*
	if (bPaused)
	{
		Return;
	}
	if (QueuedFiles.Length > 0)
	{
		if (bVerboseLogging)
		{
			Log(QueuedFiles.Length $ " files remain.");
		}
		if (QueuedFiles[0].bIsBinary)
		{
			LinkMode = 2;
		}
		else
		{
			LinkMode = 0;
		}
		if (!bResolvedHost)
		{
			Connect();
			Return;
		}
		if (!Open(ResolvedAddr))
		{
			if (bVerboseLogging)
			{
				Log("Connection could not be opened...");
			}
		}
		else
		{
			if (bVerboseLogging)
			{
				Log("Opening connection...");
			}
		}
	}
	*/
}
void AHttpLink::Opened()
{
	/*
	if (bVerboseLogging)
	{
		Log("Connection established to " $ ResolvedAddr.Addr >> 24 $ "." $ ResolvedAddr.Addr >> 16 $ "." $ ResolvedAddr.Addr >> 8 $ "." $ ResolvedAddr.Addr);
		Log("Sending HTTP Get Request:" $ Chr(13) $ Chr(10) $ QueuedFiles[0].GetRequest $ Chr(13) $ Chr(10) $ "IsConnected? " $ IsConnected());
	}
	SendText(QueuedFiles[0].GetRequest);
	bConnectionBusy = true;
	*/
}
void AHttpLink::Resolved(FIpAddr Addr)
{
	/*
	Addr.Port = 80;
	ResolvedAddr = Addr;
	bResolvedHost = true;
	GetNextFile();
	*/
}
void AHttpLink::ReceivedText(FString Text)
{
	/*
	QueuedFiles[0].TextFromServer $ = Text;
	*/
}
void AHttpLink::ReceivedBinary(int32 Count, uint8 B)
{
	/*
	local int i;
	local int indx;
	local int BeginBinary;
	indx = QueuedFiles[0].BinaryFromServer.Length;
	QueuedFiles[0].BinaryFromServer.insert(indx, Count);
	for (i = BeginBinary; i < Count; i++)
	{
		QueuedFiles[0].BinaryFromServer[indx + i] = B[i];
	}
	*/
}
void AHttpLink::Closed()
{
	/*
	local bool HardClosed;
	local int HTTPErrorCode;
	HardClosed = HardClose(False);
	if (LinkMode == 0)
	{
		QueuedFiles[0].TextFromServer = StripTextHTTPHeader(QueuedFiles[0].TextFromServer);
		if (bVerboseLogging)
		{
			Log("Connection is closed...(message received, calling delegate.) ");
		}
		HTTPErrorCode = CheckHTTPResponse();
		Switch(HTTPErrorCode)
		{
				case 200:
					if (CheckTextMD5(QueuedFiles[0].TextFromServer) != ParseCurrentHTTPHeader("Content-MD5") || bDebugMD5)
					{
						Log("File " $ QueuedFiles[0].Filename $ " is corrupted. " $ RetryAttempts $ " attempts.");
						if (RetryAttempts > MAX_RETRIES)
						{
							Log("Maximum number of retries reached for " $ QueuedFiles[0].Filename $ ".  Aborting...");
							DeleteFileFromCache(QueuedFiles[0].Filename);
							QueuedFiles.remove(0, 1);
							break;
						}
						QueuedFiles[0].TextFromServer = "";
						RetryAttempts++;
					}
		}
		else
		{
			AddCurrentFileToCache();
			QueuedFiles[0].OnReceivedText(QueuedFiles[0].Filename, QueuedFiles[0].TextFromServer);
			QueuedFiles.remove(0, 1);
			RetryAttempts = 0;
		}
			case 304:
				QueuedFiles[0].OnReceivedCachedFile(QueuedFiles[0].Filename);
				QueuedFiles.remove(0, 1);
			default:
				QueuedFiles.remove(0, 1);
	}
	else
	{
		if (LinkMode == 2)
		{
			StripBinaryHTTPHeader(QueuedFiles[0].BinaryFromServer);
			if (bVerboseLogging)
			{
				Log("Connection is closed...(" $ QueuedFiles[0].BinaryFromServer.Length $ " bytes received, calling delegate.)");
			}
			HTTPErrorCode = CheckHTTPResponse();
			Switch(HTTPErrorCode)
			{
			case 200:
				if (CheckBinaryMD5(QueuedFiles[0].BinaryFromServer) != ParseCurrentHTTPHeader("Content-MD5") || bDebugMD5)
				{
					Log("File " $ QueuedFiles[0].Filename $ " is corrupted. " $ RetryAttempts $ " attempts.");
					if (RetryAttempts > MAX_RETRIES)
					{
						Log("Maximum number of retries reached for " $ QueuedFiles[0].Filename $ ".  Aborting...");
						QueuedFiles.remove(0, 1);
						break;
					}
					QueuedFiles[0].BinaryFromServer.remove(0, QueuedFiles[0].BinaryFromServer.Length);
					RetryAttempts++;
				}
			}
			else
			{
				AddCurrentFileToCache();
				QueuedFiles[0].OnReceivedBinary(QueuedFiles[0].Filename, QueuedFiles[0].BinaryFromServer);
				QueuedFiles.remove(0, 1);
				RetryAttempts = 0;
			}
			case 304:
				QueuedFiles[0].OnReceivedCachedFile(QueuedFiles[0].Filename);
				QueuedFiles.remove(0, 1);
			default:
				QueuedFiles.remove(0, 1);
		}
		else
		{
			if (bVerboseLogging)
			{
				Log("Connection is closed...unknown link mode.");
			}
		}
	}
	bConnectionBusy = False;
	bResolvedHost = False;
	GetNextFile();
	*/
}
void AHttpLink::StripTextHTTPHeader(FString ResponseToStrip)
{
	/*
	if (LinkMode == 0)
	{
		Divide(ResponseToStrip, Chr(13) $ Chr(10) $ Chr(13) $ Chr(10), QueuedFiles[0].HTTPHeader, ResponseToStrip);
		Return ResponseToStrip;
	}
	*/
}
void AHttpLink::StripBinaryHTTPHeader(TArray<uint8> B)
{
	/*
	local int i;
	local int j;
	local bool bWasLineBreak;
	if (LinkMode == 2)
	{
		bWasLineBreak = False;
		i = 0;
		if (i < B.Length)
		{
			if (B[i] == 13)
			{
				if (B[i + 1] == 10)
				{
					i += 2;
					if (bWasLineBreak)
					{
					}
					else
					{
						bWasLineBreak = true;
					}
				else
				{
				}
			else
			{
		else
		{
			bWasLineBreak = False;
		}
			}
			bWasLineBreak = False;
			i++;
				}
			}
		}
		j = 0;
		if (j < i - 4)
		{
			QueuedFiles[0].HTTPHeader $ = Chr(QueuedFiles[0].BinaryFromServer[j]);
			j++;
		}
		QueuedFiles[0].BinaryFromServer.remove(0, i);
	}
	*/
}
void AHttpLink::ResolveFailed()
{
	/*
	Log("Failed to resolve domain " $ TargetHost $ "...");
	*/
}
void AHttpLink::CheckHTTPResponse()
{
	/*
	local string BitBucket;
	local string HTTPErr;
	local string ETag;
	local int HTTPCode;
	HTTPErr = ParseCurrentHTTPHeader("Top");
	Divide(HTTPErr, " ", BitBucket, HTTPErr);
	Divide(HTTPErr, " ", HTTPErr, BitBucket);
	HTTPCode = HTTPErr;
	Switch(HTTPCode)
	{
			case 200:
				ETag = ParseCurrentHTTPHeader("ETag");
				if (bVerboseLogging)
				{
					Log("----HTTP: File Request OK----");
					Log("HTTP: FileName: " $ QueuedFiles[0].Filename);
					Log("HTTP: ETag: " $ ETag);
					Log("-------------------------------");
				}
				break;
			case 304:
				if (bVerboseLogging)
				{
					ETag = ParseCurrentHTTPHeader("ETag");
					Log("----HTTP: File Not Modified----");
					Log("HTTP: FileName: " $ QueuedFiles[0].Filename);
					Log("HTTP: ETag: " $ ETag);
					Log("-------------------------------");
				}
				break;
			default:
				if (bVerboseLogging)
				{
					Log("----HTTP: Error: " $ HTTPErr $ "----");
				}
	}
	Return HTTPCode;
	*/
}
void AHttpLink::AddCurrentFileToCache()
{
	/*
	local string CacheFilePath;
	local string ETag;
	CacheFilePath = GetBaseDir() $ CacheFileName;
	ETag = ParseCurrentHTTPHeader("ETag");
	SetPrivateProfileString(ETag, CacheFilePath, "Cached Content", QueuedFiles[0].Filename);
	SavePrivateProfile(CacheFilePath);
	*/
}
void AHttpLink::DeleteFileFromCache(FString CachedFile)
{
	/*
	local string CacheFilePath;
	local string CacheFileLine;
	local string Filename;
	local string ETag;
	local array<String> FileBuffer;
	local int LineCount;
	local int i;
	CacheFilePath = GetBaseDir() $ CacheFileName;
	if (bVerboseLogging)
	{
		Log("----DeleteFileFromCache----");
		Log("Removing " $ CachedFile $ " entry from " $ CacheFilePath);
	}
	if (FOpen(CacheFileName))
	{
		LineCount = 0;
		if (FReadLine(CacheFileLine))
		{
			Divide(CacheFileLine, "=", Filename, ETag);
			if (Filename != CachedFile)
			{
				FileBuffer[LineCount] = CacheFileLine;
				++LineCount;
			}
		}
		FClose();
		if (FOpenWrite(CacheFileName))
		{
			for (i = 0; i < LineCount; i++)
			{
				FWriteLine(FileBuffer[i]);
			}
			FClose();
			if (bVerboseLogging)
			{
				Log("Entries Successfully removed");
				Log("---------------------------");
			}
		}
	}
	*/
}
void AHttpLink::DoesFileExist(FString Filename)
{
	/*
	if (FOpen(Filename))
	{
		FClose();
		Return True;
	}
	Return False;
	*/
}
void AHttpLink::ParseCurrentHTTPHeader(FString FieldName)
{
	/*
	local string FieldData;
	local string BitBucket;
	FieldData = "";
	if (FieldName == "Top")
	{
		Divide(QueuedFiles[0].HTTPHeader, Chr(13) $ Chr(10), FieldData, BitBucket);
	}
	else
	{
		if (InStr(QueuedFiles[0].HTTPHeader, FieldName) != -1)
		{
			Divide(QueuedFiles[0].HTTPHeader, FieldName $ ": ", BitBucket, FieldData);
			Divide(FieldData, Chr(13) $ Chr(10), FieldData, BitBucket);
		}
	}
	Return FieldData;
	*/
}
FString AHttpLink::FixFilePath(FString FilePath)
{
	/*
	FilePath = LocalFilePath $ FilePath;
	if (Left(FilePath, 1) == "/")
	{
		FilePath = Mid(FilePath, 1);
	}
	Return Repl(FilePath, "/", "\");
	*/
	return "";	//FAKE   /ELiZ
}
