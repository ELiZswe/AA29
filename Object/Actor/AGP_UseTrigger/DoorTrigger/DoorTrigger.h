// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_UseTrigger/AGP_UseTrigger.h"
#include "AA29/MyEnums.h"
#include "DoorTrigger.generated.h"

UCLASS()
class ADoorTrigger : public AAGP_UseTrigger
{
	GENERATED_BODY()
public:
	ADoorTrigger();

	UPROPERTY()											bool bIsLocked;							//var bool bIsLocked;
	UPROPERTY(EditAnywhere)								FString TextLocked;						//var() string TextLocked;
	UPROPERTY(EditAnywhere)								FString TextUnlocked;					//var() string TextUnlocked;
	UPROPERTY(EditAnywhere)								USoundBase* SoundUnLocking;				//var() Sound SoundUnLocking;
	UPROPERTY(EditAnywhere)								USoundBase* SoundLocking;				//var() Sound SoundLocking;
	UPROPERTY(EditAnywhere)								USoundBase* SoundLocked;				//var() Sound SoundLocked;
	UPROPERTY(EditAnywhere)								bool bOpen;								//var() bool bOpen;
	UPROPERTY(EditAnywhere)								bool bLocked;							//var() bool bLocked;
	UPROPERTY(EditAnywhere)								FName DoorTag;							//var() name DoorTag;
	UPROPERTY(EditAnywhere)								ELockType LockType;						//var() ELockType LockType;
	UPROPERTY(EditAnywhere, Category = "aaHelp")		TArray<FString> DoorTriggerHelp;		//var(aaHelp) const editconst string DoorTriggerHelp;

	bool IsLocked();
	bool IsOpen();
	void SetLocked(bool Locked);
	void BeginPlay();
	void MySetHUDText();
	void MatchStarting();
	bool UsedBy(APawn* User);
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
	bool ToggleOpen();
	void Open();
	void Close();
};
