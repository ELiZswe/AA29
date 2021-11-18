// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/UIBase/UIControl/UISoundControl/UINavControl/UINavControl.h"
#include "UIServerListDisplay.generated.h"

class AServerBrowserBase;

UCLASS()
class AA29_API UUIServerListDisplay : public UUINavControl
{
	GENERATED_BODY()
public:
	UUIServerListDisplay();

	//const kMaxPlayersVisible = 7;
	//const kDoubleClickTime = 0.3;
	//const kMaxLan = 4;


	UPROPERTY()										int32 _iNavPlayerList;						//var int _iNavPlayerList;
	UPROPERTY()										int32 _iFirstPlayer;						//var int _iFirstPlayer;
	UPROPERTY()										int32 _iLastSelected;						//var int _iLastSelected;
	UPROPERTY()										float fLastClickTime;						//var float fLastClickTime;
	UPROPERTY()										UMaterialInstance* _tTour;					//var Texture _tTour;
	UPROPERTY()										UMaterialInstance* _tFavorite;				//var Texture _tFavorite;
	UPROPERTY()										UMaterialInstance* _tPassword;				//var Texture _tPassword;
	UPROPERTY()										UMaterialInstance* _tMiles;					//var Texture _tMiles;
	UPROPERTY()										UMaterialInstance* _tApproved;				//var Texture _tApproved;
	UPROPERTY()										UMaterialInstance* _tLeasedOfficial;		//var Texture _tLeasedOfficial;
	UPROPERTY()										UMaterialInstance* _tLeased;				//var Texture _tLeased;
	UPROPERTY()										UMaterialInstance* _tOfficial;				//var Texture _tOfficial;
	UPROPERTY()										UMaterialInstance* _tSelected;				//var Texture _tSelected;
	UPROPERTY()										int32 _iSelected;							//var int _iSelected;
	UPROPERTY()										int32 _iNumServers;							//var int _iNumServers;
	UPROPERTY()										int32 _iFirstServer;						//var int _iFirstServer;
	UPROPERTY()										int32 _iNumOver;							//var int _iNumOver;
	UPROPERTY()										int32 _iNumLan;								//var int _iNumLan;
	UPROPERTY()										bool _bFirstOver;							//var bool _bFirstOver;
	UPROPERTY()										int32 _iState;								//var int _iState;

	void MouseMove(int32 mX, int32 mY);
	bool ProcessKeyEvent(int32 Key, int32 Action, float Delta);
	void Draw(UCanvas* Canvas);
	void DisplaySelectedInfo(UCanvas* Canvas, FGameSpyServerItem Item, FString sAddress);
	void DisplaySelectedPlayers(UCanvas* Canvas, AServerBrowserBase* sbBase, int32 server_index, int32 num_players);
	void CreateTexture();
	int32 GetSelected();
	void SetSelectedServer(int32 selected);
	void NextPlayerList();
	void PrevPlayerList();

};
