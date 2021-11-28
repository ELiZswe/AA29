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
void AVotingHandler::GetConfigArrayData(FString ConfigArrayName, int32 RowIndex, int32 ColumnIndex)
{
}
void AVotingHandler::GetConfigArrayColumnTitle(FString ConfigArrayName, int32 ColumnIndex)
{
}
void AVotingHandler::DeleteConfigArrayItem(FString ConfigArrayName, int32 RowIndex)
{
}
void AVotingHandler::AddConfigArrayItem(FString ConfigArrayName)
{
}
void AVotingHandler::UpdateConfigArrayItem(FString ConfigArrayName, int32 RowIndex, int32 ColumnIndex, FString NewValue)
{
}
void AVotingHandler::GetConfigArrayItemCount(FString ConfigArrayName)
{
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