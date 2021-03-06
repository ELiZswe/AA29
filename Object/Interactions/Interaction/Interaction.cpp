// All the original content belonged to the US Army

#include "AA29/Object/Interactions/Interaction/Interaction.h"
#include "AA29/Object/Interactions/InteractionMaster/InteractionMaster.h"
#include "AA29/AA29.h"
#include "Engine/Canvas.h"

UInteraction::UInteraction()
{
	bActive = true;
}

//native Function Initialize();
void UInteraction::Initialize()
{

}

//native Function ConsoleCommand(coerce string S);
bool UInteraction::ConsoleCommand(FString S)
{
	return false;   //FAKE  /ELiZ
}

//native Function WorldToScreen(FVector Location, optional FVector CameraLocation, optional FRotator CameraRotation);
FVector UInteraction::WorldToScreen(FVector Location, FVector CameraLocation, FRotator CameraRotation)
{
	return FVector(0, 0, 0);     //FAKE   /EliZ
}

//native Function ScreenToWorld(FVector Location, optional FVector CameraLocation, optional FRotator CameraRotation);
FVector UInteraction::ScreenToWorld(FVector Location, FVector CameraLocation, FRotator CameraRotation)
{
	return FVector(0, 0, 0);     //FAKE   /EliZ
}

void UInteraction::Initialized()
{
}
void UInteraction::NotifyLevelChange()
{
}
void UInteraction::Message(FString Msg, float MsgLife, FColor Color)
{
}
bool UInteraction::KeyType(EInputKey &Key, FString Unicode)
{
	return false;
}
bool UInteraction::KeyEvent(EInputKey& Key, EInputAction& Action, float Delta)
{
	return false;
}
void UInteraction::PreRender(UCanvas* Canvas)
{
}
void UInteraction::PostRender(UCanvas* Canvas)
{
}
void UInteraction::SetFocus()
{
	//Master.SetFocusTo(this, ViewportOwner);
}
void UInteraction::Tick(float DeltaTime)
{
}
void UInteraction::StreamFinished(int32 Handle, EStreamFinishReason Reason)
{
}
void UInteraction::NotifyMusicChange()
{
}
void UInteraction::NotifyDemoCompleted()
{
}
void UInteraction::InteractionChanged(UInteraction* Changed, bool bOpen)
{
}
