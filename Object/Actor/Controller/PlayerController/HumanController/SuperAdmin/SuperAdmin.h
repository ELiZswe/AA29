// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "SuperAdmin.generated.h"

class AExtender;

UCLASS()
class ASuperAdmin : public AHumanController
{
	GENERATED_BODY()
public:
	ASuperAdmin();

	UPROPERTY()			EExtendLength	ExtendLength;		//var Enum EExtendLength ExtendLength;
	UPROPERTY()			uint8			bZoomIn;			//var input uint8 bZoomIn;
	UPROPERTY()			uint8			bZoomOut;			//var input uint8 bZoomOut;
	UPROPERTY()			bool			bWasIn;				//var bool bWasIn;
	UPROPERTY()			float			fZoomTime;			//var float fZoomTime;
	UPROPERTY()			AExtender*		EList;				//var Extender EList;
	UPROPERTY()			bool			bExtendersOn;		//var bool bExtendersOn;
	UPROPERTY()			bool			bWireFrame;			//var bool bWireFrame;

	void PostNetBeginPlay();
	void NotifyPawnSpawned(APawn* p);
	void NotifyPawnDestroyed(APawn* p);
	void togwireframe();
	void togextend();
	void lenextend();
	float getExtendLength();
	void EnableExtenders();
	void DisableExtenders();
	void AddExtender(APawn* p);
	AExtender* GetExtender(APawn* p);
	void CleanupExtender(APawn* p);
	void UpdateExtenders();
	void PlayerTick(float DeltaTime);
	float GetLockFOV();
	void PostRender(UCanvas* Canvas);
	bool CanBehindView();
	bool IsSpectatePlayersOnly();
	bool IsSpectateFirstPersonOnly();
	void AdminChangePassword(FString sOldPassword, FString sNewPassword, FString sVerifyPassword);
	void Help();
	void PBBanHelp();
	void PBBadNameHelp();
	void PBCvarHelp();
	void PBWebsiteHelp();
	void PBHelp();
	void ShowMapList(FString sTourIndex);
	void ShowAdminCommandPost();
	void AdminResetView();
};
