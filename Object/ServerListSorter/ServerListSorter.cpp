// All the original content belonged to the US Army


#include "AA29/Object/ServerListSorter/ServerListSorter.h"

UServerListSorter::UServerListSorter()
{

}



//native static Function SortServerList(out array<ServerBrowserBase.GameSpyServerItem> List, string Field, bool Ascending);
void UServerListSorter::SortServerList(TArray<FGameSpyServerItem>& List, FString Field, bool Ascending)
{
}

//native static Function testonly_CompareServers(ServerBrowserBase.GameSpyServerItem ServerA, ServerBrowserBase.GameSpyServerItem ServerB, string Field);
void UServerListSorter::testonly_CompareServers(FGameSpyServerItem ServerA, FGameSpyServerItem ServerB, FString Field)
{
}

