// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/TcpLinkBigBinary/TcpLinkBigBinary.h"

ATcpLinkBigBinary::ATcpLinkBigBinary()
{
	bUseBigBinaryBuffer = true;
}

//native Function SendBigBinary(int32 Count);
int32 ATcpLinkBigBinary::SendBigBinary(int32 Count)
{
	return 0;    //FAKE   /EliZ
}
void ATcpLinkBigBinary::ReceivedBigBinary(int32 Count)
{
}
