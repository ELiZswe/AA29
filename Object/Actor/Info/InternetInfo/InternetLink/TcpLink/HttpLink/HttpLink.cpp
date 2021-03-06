// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/HttpLink/HttpLink.h"
#include "AA29/Object/HttpLinkItem/HttpLinkItem.h"

AHttpLink::AHttpLink()
{
	TargetPort = 80;
	TargetVersionFolder = "/2.8.5";
	CacheFileName = "DynamicContent\\NML\\Cache.ini";
	MAX_RETRIES = 3;
}

//native Function CheckBinaryMD5(array<byte> File);
FString AHttpLink::CheckBinaryMD5(TArray<uint8> File)
{
	return "FAKE";    //FAKE   /EliZ
}

//native Function CheckTextMD5(FString File);
FString AHttpLink::CheckTextMD5(FString File)
{
	return "FAKE";    //FAKE   /EliZ
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
	int32 boundport;
	boundport = BindPort(, true);
	if (bVerboseLogging)
	{
		Log("HTTP Bound Port:  " + boundport);
	}
	Resolve(TargetHost);
	*/
}
void AHttpLink::Disconnect()
{
	/*
	if (QueuedFiles.Num() > 0)
	{
		Log("HTTPLink Warning:  Closing connection with " + QueuedFiles.Num() + " pending requests!");
	}
	*/
}

UHttpLinkItem* AHttpLink::RequestText(FString FilePath)
{
	int32 i = 0;
	FString CacheFilePath = "";
	FString ETag = "";
	/*
	i = QueuedFiles.Num();
	QueuedFiles.insert(i, 1);
	QueuedFiles[i] = new () UHttpLinkItem::StaticClass();
	QueuedFiles[i].Filename = FilePath;
	QueuedFiles[i].bIsBinary = false;
	QueuedFiles[i].GetRequest = "GET " + TargetVersionFolder + FilePath + " HTTP/1.1" + Chr(13) + Chr(10);
	QueuedFiles[i].GetRequest += "Host: " + TargetHost + Chr(13) + Chr(10);
	QueuedFiles[i].GetRequest += "Connection: Close" + Chr(13) + Chr(10);
	CacheFilePath = GetBaseDir() + CacheFileName;
	if (DoesFileExist(CacheFileName))
	{
		if (DoesFileExist(FixFilePath(FilePath)))
		{
			ETag = GetPrivateProfileString(CacheFilePath, "Cached Content", FilePath);
			QueuedFiles[i].GetRequest += "If-None-Match: " + """" + ETag + """" + Chr(13) + Chr(10);
		}
	}
	QueuedFiles[i].GetRequest += Chr(13) + Chr(10) + Chr(13) + Chr(10);
	if (QueuedFiles.Num() == 1)
	{
		GetNextFile();
	}
	*/
	return QueuedFiles[i];
}

UHttpLinkItem* AHttpLink::RequestBinary(FString FilePath)
{
	int32 i = 0;
	FString CacheFilePath = "";
	FString ETag = "";
	/*
	i = QueuedFiles.Num();
	QueuedFiles.insert(i, 1);
	QueuedFiles[i] = new () UHttpLinkItem::StaticClass();
	QueuedFiles[i].Filename = FilePath;
	QueuedFiles[i].bIsBinary = true;
	QueuedFiles[i].GetRequest = "GET " + TargetVersionFolder + FilePath + " HTTP/1.1" + Chr(13) + Chr(10);
	QueuedFiles[i].GetRequest += "Host: " + TargetHost + Chr(13) + Chr(10);
	QueuedFiles[i].GetRequest += "Connection: Close" + Chr(13) + Chr(10);
	CacheFilePath = GetBaseDir() + CacheFileName;
	if (DoesFileExist(CacheFilePath))
	{
		if (DoesFileExist(FixFilePath(FilePath)))
		{
			ETag = GetPrivateProfileString(CacheFilePath, "Cached Content", FilePath);
			QueuedFiles[i].GetRequest += "If-None-Match: " + """" + ETag + """" + Chr(13) + Chr(10);
		}
	}
	QueuedFiles[i].GetRequest += Chr(13) + Chr(10);
	if (QueuedFiles.Num() == 1)
	{
		GetNextFile();
	}
	*/
	return QueuedFiles[i];
}

void AHttpLink::GetNextFile()
{
	/*
	if (bPaused)
	{
		return;
	}
	if (QueuedFiles.Num() > 0)
	{
		if (bVerboseLogging)
		{
			Log(QueuedFiles.Num() + " files remain.");
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
			return;
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
		Log("Connection established to " + ResolvedAddr.Addr >> 24 + "." + ResolvedAddr.Addr >> 16 + "." + ResolvedAddr.Addr >> 8 + "." + ResolvedAddr.Addr);
		Log("Sending HTTP Get Request:" + Chr(13) + Chr(10) + QueuedFiles[0].GetRequest + Chr(13) + Chr(10) + "IsConnected? " + IsConnected());
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
	//QueuedFiles[0].TextFromServer += Text;
}
void AHttpLink::ReceivedBinary(int32 Count, uint8 B)
{
	int32 i = 0;
	int32 indx = 0;
	int32 BeginBinary = 0;
	/*
	indx = QueuedFiles[0].BinaryFromServer.Num();
	QueuedFiles[0].BinaryFromServer.insert(indx, Count);
	for (i = BeginBinary; i < Count; i++)
	{
		QueuedFiles[0].BinaryFromServer[indx + i] = B[i];
	}
	*/
}
void AHttpLink::Closed()
{
	bool HardClosed = false;
	int32 HTTPErrorCode = 0;
	/*
	HardClosed = HardClose(false);
	if (LinkMode == 0)
	{
		QueuedFiles[0].TextFromServer = StripTextHTTPHeader(QueuedFiles[0].TextFromServer);
		if (bVerboseLogging)
		{
			Log("Connection is closed...(message received, calling delegate.) ");
		}
		HTTPErrorCode = CheckHTTPResponse();
		switch(HTTPErrorCode)
		{
				case 200:
					if (CheckTextMD5(QueuedFiles[0].TextFromServer) != ParseCurrentHTTPHeader("Content-MD5") || bDebugMD5)
					{
						Log("File " + QueuedFiles[0].Filename + " is corrupted. " + RetryAttempts + " attempts.");
						if (RetryAttempts > MAX_RETRIES)
						{
							Log("Maximum number of retries reached for " + QueuedFiles[0].Filename + ".  Aborting...");
							DeleteFileFromCache(QueuedFiles[0].Filename);
							QueuedFiles.RemoveAt(0, 1);
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
			QueuedFiles.RemoveAt(0, 1);
			RetryAttempts = 0;
		}
			case 304:
				QueuedFiles[0].OnReceivedCachedFile(QueuedFiles[0].Filename);
				QueuedFiles.RemoveAt(0, 1);
			default:
				QueuedFiles.RemoveAt(0, 1);
	}
	else
	{
		if (LinkMode == 2)
		{
			StripBinaryHTTPHeader(QueuedFiles[0].BinaryFromServer);
			if (bVerboseLogging)
			{
				Log("Connection is closed...(" + QueuedFiles[0].BinaryFromServer.Num() + " bytes received, calling delegate.)");
			}
			HTTPErrorCode = CheckHTTPResponse();
			switch(HTTPErrorCode)
			{
			case 200:
				if (CheckBinaryMD5(QueuedFiles[0].BinaryFromServer) != ParseCurrentHTTPHeader("Content-MD5") || bDebugMD5)
				{
					Log("File " + QueuedFiles[0].Filename + " is corrupted. " + RetryAttempts + " attempts.");
					if (RetryAttempts > MAX_RETRIES)
					{
						Log("Maximum number of retries reached for " + QueuedFiles[0].Filename + ".  Aborting...");
						QueuedFiles.RemoveAt(0, 1);
						break;
					}
					QueuedFiles[0].BinaryFromServer.RemoveAt(0, QueuedFiles[0].BinaryFromServer.Num());
					RetryAttempts++;
				}
			}
			else
			{
				AddCurrentFileToCache();
				QueuedFiles[0].OnReceivedBinary(QueuedFiles[0].Filename, QueuedFiles[0].BinaryFromServer);
				QueuedFiles.RemoveAt(0, 1);
				RetryAttempts = 0;
			}
			case 304:
				QueuedFiles[0].OnReceivedCachedFile(QueuedFiles[0].Filename);
				QueuedFiles.RemoveAt(0, 1);
			default:
				QueuedFiles.RemoveAt(0, 1);
		}
		else
		{
			if (bVerboseLogging)
			{
				Log("Connection is closed...unknown link mode.");
			}
		}
	}
	bConnectionBusy = false;
	bResolvedHost = false;
	GetNextFile();
	*/
}
FString AHttpLink::StripTextHTTPHeader(FString ResponseToStrip)
{
	/*
	if (LinkMode == 0)
	{
		Divide(ResponseToStrip, Chr(13) + Chr(10) + Chr(13) + Chr(10), QueuedFiles[0].HTTPHeader, ResponseToStrip);
		return ResponseToStrip;
	}
	*/
	return "FAKE";    //FAKE   /EliZ
}

void AHttpLink::StripBinaryHTTPHeader(TArray<uint8> B)
{
	int32 i = 0;
	int32 j = 0;
	bool bWasLineBreak = false;
	/*
	if (LinkMode == 2)
	{
		bWasLineBreak = false;
		i = 0;
		if (i < B.Num())
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
			bWasLineBreak = false;
		}
			}
			bWasLineBreak = false;
			i++;
				}
			}
		}
		j = 0;
		if (j < i - 4)
		{
			QueuedFiles[0].HTTPHeader += Chr(QueuedFiles[0].BinaryFromServer[j]);
			j++;
		}
		QueuedFiles[0].BinaryFromServer.RemoveAt(0, i);
	}
	*/
}
void AHttpLink::ResolveFailed()
{
	//Log("Failed to resolve domain " + TargetHost + "...");
}

int32 AHttpLink::CheckHTTPResponse()
{
	FString BitBucket = "";
	FString HTTPErr = "";
	FString ETag = "";
	int32 HTTPCode = 0;
	/*
	HTTPErr = ParseCurrentHTTPHeader("Top");
	Divide(HTTPErr, " ", BitBucket, HTTPErr);
	Divide(HTTPErr, " ", HTTPErr, BitBucket);
	HTTPCode = HTTPErr;
	switch(HTTPCode)
	{
			case 200:
				ETag = ParseCurrentHTTPHeader("ETag");
				if (bVerboseLogging)
				{
					Log("----HTTP: File Request OK----");
					Log("HTTP: FileName: " + QueuedFiles[0].Filename);
					Log("HTTP: ETag: " + ETag);
					Log("-------------------------------");
				}
				break;
			case 304:
				if (bVerboseLogging)
				{
					ETag = ParseCurrentHTTPHeader("ETag");
					Log("----HTTP: File Not Modified----");
					Log("HTTP: FileName: " + QueuedFiles[0].Filename);
					Log("HTTP: ETag: " + ETag);
					Log("-------------------------------");
				}
				break;
			default:
				if (bVerboseLogging)
				{
					Log("----HTTP: Error: " + HTTPErr + "----");
				}
	}
	*/
	return HTTPCode;
}

void AHttpLink::AddCurrentFileToCache()
{
	FString CacheFilePath = "";
	FString ETag = "";
	/*
	CacheFilePath = GetBaseDir() + CacheFileName;
	ETag = ParseCurrentHTTPHeader("ETag");
	SetPrivateProfileString(ETag, CacheFilePath, "Cached Content", QueuedFiles[0].Filename);
	SavePrivateProfile(CacheFilePath);
	*/
}

void AHttpLink::DeleteFileFromCache(FString CachedFile)
{
	FString CacheFilePath = "";
	FString CacheFileLine = "";
	FString Filename = "";
	FString ETag = "";
	TArray<FString> FileBuffer = {};
	int32 LineCount = 0;
	int32 i = 0;
	/*
	CacheFilePath = GetBaseDir() + CacheFileName;
	if (bVerboseLogging)
	{
		Log("----DeleteFileFromCache----");
		Log("Removing " + CachedFile + " entry from " + CacheFilePath);
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
bool AHttpLink::DoesFileExist(FString Filename)
{
	/*
	if (FOpen(Filename))
	{
		FClose();
		return true;
	}
	*/
	return false;
}

FString AHttpLink::ParseCurrentHTTPHeader(FString FieldName)
{
	FString FieldData = "";
	FString BitBucket = "";
	FieldData = "";
	/*
	if (FieldName == "Top")
	{
		Divide(QueuedFiles[0].HTTPHeader, Chr(13) + Chr(10), FieldData, BitBucket);
	}
	else
	{
		if (InStr(QueuedFiles[0].HTTPHeader, FieldName) != -1)
		{
			Divide(QueuedFiles[0].HTTPHeader, FieldName + ": ", BitBucket, FieldData);
			Divide(FieldData, Chr(13) + Chr(10), FieldData, BitBucket);
		}
	}
	*/
	return FieldData;
}
FString AHttpLink::FixFilePath(FString FilePath)
{
	/*
	FilePath = LocalFilePath + FilePath;
	if (Left(FilePath, 1) == "/")
	{
		FilePath = Mid(FilePath, 1);
	}
	return Repl(FilePath, "/", "\");
	*/
	return "";	//FAKE   /ELiZ
}
