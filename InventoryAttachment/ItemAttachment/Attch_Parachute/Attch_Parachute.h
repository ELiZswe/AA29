// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "Attch_Parachute.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttch_Parachute : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAttch_Parachute();

	UPROPERTY()		bool bNoInstigator;						//var bool bNoInstigator;
	UPROPERTY()		uint8 PrevAnimState;					//var byte PrevAnimState;
	UPROPERTY()		AItemAttachment* ParaItems;				//var ItemAttachment ParaItems;
	UPROPERTY()		bool bStartScaleDeploy;					//var bool bStartScaleDeploy;
	UPROPERTY()		FVector fScaleDeploy;					//var FVector fScaleDeploy;
	UPROPERTY()		USoundBase* sParachuteCollapseSound;	//var Sound sParachuteCollapseSound;
	UPROPERTY()		USoundBase* sParachuteFlutterSound;		//var Sound sParachuteFlutterSound;
	UPROPERTY()		USoundBase* sParachuteOpenSound;		//var Sound sParachuteOpenSound;
	UPROPERTY()		float _ParachuteSoundUpdate;			//var float _ParachuteSoundUpdate;

};
