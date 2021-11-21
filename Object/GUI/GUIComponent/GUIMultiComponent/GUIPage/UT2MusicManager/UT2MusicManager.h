// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "UT2MusicManager.generated.h"

UCLASS(Config = Game)
class AA29_API UUT2MusicManager : public UGUIPage
{
	GENERATED_BODY()
public:
	UUT2MusicManager();

	UPROPERTY(config)						FPlayListStruct Playlist;						//var config PlayListStruct Playlist;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetMusic(FString NewSong);
	FString SetInitialMusic(FString NewSong);
	void MusicChanged();
	bool NotifyLevelChange();
};
