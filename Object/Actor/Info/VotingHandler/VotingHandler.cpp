// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/VotingHandler/VotingHandler.h"

AVotingHandler::AVotingHandler()
{

}

void AVotingHandler::PlayerJoin(APlayerController* Player)
{
}

void AVotingHandler::PlayerExit(AController* Exiting)
{
}

bool AVotingHandler::HandleRestartGame()
{
	return true;
}

FString AVotingHandler::GetConfigArrayData(FString ConfigArrayName, int32 RowIndex, int32 ColumnIndex)
{
	return "FAKE";    //FAKE   /EliZ
}

FString AVotingHandler::GetConfigArrayColumnTitle(FString ConfigArrayName, int32 ColumnIndex)
{
	return "FAKE";    //FAKE   /EliZ
}

void AVotingHandler::DeleteConfigArrayItem(FString ConfigArrayName, int32 RowIndex)
{
}

int32 AVotingHandler::AddConfigArrayItem(FString ConfigArrayName)
{
	return 0;    //FAKE   /EliZ
}

void AVotingHandler::UpdateConfigArrayItem(FString ConfigArrayName, int32 RowIndex, int32 ColumnIndex, FString NewValue)
{
}

int32 AVotingHandler::GetConfigArrayItemCount(FString ConfigArrayName)
{
	return 0;    //FAKE   /EliZ
}

void AVotingHandler::FillPlayInfo(APlayInfo* PlayInfo)
{
	//Super::FillPlayInfo(PlayInfo);
}

bool AVotingHandler::IsEnabled()
{
	return false;
}

void AVotingHandler::ReloadAll(bool bParam)
{
}

void AVotingHandler::GetServerDetails(FServerResponseLine &ServerState)
{
}
