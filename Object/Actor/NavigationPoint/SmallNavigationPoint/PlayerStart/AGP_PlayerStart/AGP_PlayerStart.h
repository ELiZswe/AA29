// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerStart.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/SoldierClass.h"
#include "AGP_PlayerStart.generated.h"

class ASoldierClass;
class USkeletalMesh;
class UMaterialInstance;
class APSProxy;
class AInventory;
class APSSet;

UCLASS()
class AAGP_PlayerStart : public APlayerStart
{
	GENERATED_BODY()
protected:
	
	virtual void BeginPlay() override;

public:

	// constructor sets default values for this actor's properties
	AAGP_PlayerStart(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()																	uint8								_NumSpawned;			//var byte _NumSpawned;									// number of times this start has been used this round
	UPROPERTY(EditAnywhere)									uint8								MaxSpawns;				//var() byte MaxSpawns;									// number of times this start can be used in a round
	UPROPERTY(EditAnywhere)									bool								bGiveParachute;			//var() bool bGiveParachute;							// Player spawns in this point with a parachute
	UPROPERTY(EditAnywhere)														TSubclassOf<ASoldierClass>			SpawnClass;				//var() class<SoldierClass> SpawnClass;					// team class to spawn for players starting here.
																																																	// if none, use game default
	UPROPERTY()																	bool bExtraSpecialForces;									//var bool bExtraSpecialForces;
	UPROPERTY()																	FString ExtraSpecialForcesLetter;							//var string ExtraSpecialForcesLetter;
	UPROPERTY(EditAnywhere)									bool bOnlySpawnAtProxies;									//var() bool bOnlySpawnAtProxies;
	UPROPERTY(EditAnywhere)									bool bNoPLFDamage;											//var() bool bNoPLFDamage;
	UPROPERTY(EditAnywhere)									bool bNoParaFallDamage;										//var() bool bNoParaFallDamage;
	UPROPERTY(EditAnywhere)									EInitialParaState InitialParaState;							//var() EInitialParaState InitialParaState;
	UPROPERTY(EditAnywhere)									bool bUserSetMesh;											//var() bool bUserSetMesh;
	UPROPERTY(EditAnywhere)									USkeletalMesh* SetMesh;										//var() Mesh SetMesh;

//User set Skin
	UPROPERTY(EditAnywhere)									UMaterialInstance*					setPants;				//var() Material setPants;
	UPROPERTY(EditAnywhere)									UMaterialInstance*					setShirt;				//var() Material setShirt;
	UPROPERTY(EditAnywhere)									UMaterialInstance*					setHands;				//var() Material setHands;
	UPROPERTY(EditAnywhere)									UMaterialInstance*					setFace;				//var() Material setFace;
	UPROPERTY(EditAnywhere)									bool								bUserSetSkin;			//var() bool bUserSetSkin;
	UPROPERTY()																	TSubclassOf<AAGP_PlayerStart>		nextPS;					//var AGP_PlayerStart nextPS;							//agp [cmb] Used by Team for assigning to PSs to Players at start of match [6/19/2002]
	UPROPERTY()																	int32 StartIndex;											//var int StartIndex;
	UPROPERTY()																	bool bIFVIP;												//var bool bIFVIP;
	UPROPERTY()																	bool bSpecialForces;										//var bool bSpecialForces;
	UPROPERTY()																	bool bGuerrilla;											//var bool bGuerrilla;
	UPROPERTY()																	int32 RemoveNum;											//var int RemoveNum;
	UPROPERTY()																	TArray<uint8> Removed;										//var byte Removed[16];
	UPROPERTY(EditAnywhere)									TArray<TSubclassOf<AInventory>> RemoveClassInventory;		//var() class<Inventory> RemoveClassInventory;
	UPROPERTY(EditAnywhere)									FName MyLeader;												//var() name MyLeader;									// tag of a playerstart for spawned player's leader
	UPROPERTY(EditAnywhere)									TArray<TSubclassOf<AInventory>> AddedInventory;				//var() class<Inventory> AddedInventory;				// inventory items added after items
																																																	// normally received by this class, or by this team
	//From PlayerStart(AA2)
	UPROPERTY()																	TArray<APSProxy*> ProxyList;								//var const array<PSProxy> ProxyList;
	UPROPERTY(EditAnywhere, Category = "Proxy")				FName SetTag;												//var(Proxy) const name SetTag;
	UPROPERTY(EditAnywhere, Category = "Proxy")				FName ProxyTag;												//var(Proxy) const name ProxyTag;
	UPROPERTY()																	FName PrevProxyTag;											//var const transient name PrevProxyTag;
	UPROPERTY(EditAnywhere, Category="AGP_PlayerStart")		EFireTeam FireTeam;											//var(AGP_PlayerStart) EFireTeam FireTeam;
	UPROPERTY(EditAnywhere, Category = "AGP_PlayerStart")	uint8 nInitialHealth;										//var(AGP_PlayerStart) int nInitialHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AGP_PlayerStart")	bool bFTLeader;												//var(AGP_PlayerStart) bool bFTLeader;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AGP_PlayerStart")	bool bSquadLeader;											//var(AGP_PlayerStart) bool bSquadLeader;
	UPROPERTY(EditAnywhere)									uint8 fBaseScore;											//var() float fBaseScore;
	UPROPERTY(EditAnywhere)									bool bPrimaryStart;											//var() bool bPrimaryStart;
	UPROPERTY(EditAnywhere)									bool bEnabled;												//var() bool bEnabled;
	UPROPERTY(EditAnywhere)									bool bCoopStart;											//var() bool bCoopStart;
	UPROPERTY(EditAnywhere)									bool bSinglePlayerStart;									//var() bool bSinglePlayerStart;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)									uint8 TeamNumber;											//var() byte TeamNumber;

	bool bUsed;

	class UBillboardComponent* SpriteComponent;
	//from Actor:
	UPROPERTY(EditAnywhere)		float DrawScale;

	// Icon sprite
	UPROPERTY(EditAnywhere)		UTexture2D* Texture;

	virtual	void PostBeginPlay();
	virtual int32 GetInitialParaState();							//GetInitialParaState
	
	void ResetSkipInventory();
	void Reset();
	virtual bool SkipInventory(FString AddName);					//SkipInventory
	virtual bool ShouldSetInitialParaState();						//ShouldSetInitialParaState

	TSubclassOf<ASoldierClass> GetSpawnClass();						//simulated function Class<SoldierClass> GetSpawnClass()
	virtual int32 GetInitialHealth();								//simulated function int GetInitialHealth()
	virtual float GetScore();										//function float GetScore()
	virtual bool CanSpawn();										//function bool CanSpawn()
	virtual int32 NumSpawnsRemaining();								//function int NumSpawnsRemaining()
	virtual int32 NumSpawnsUsed();									//function int NumSpawnsUsed()
	virtual uint8 GetTeamID();										//function byte GetTeamID()
	virtual bool IsEnabled();										//function bool IsEnabled()
	virtual void UsePlayerStart();									//Function UsePlayerStart ()
	virtual uint8 getFT();											//function byte GetFT()
	virtual FString toString();										//function string toString(){
	virtual void FindNewStartIndex(APSSet* UseSet);					//Function FindNewStartIndex (optional PSSet UseSet)
	virtual FVector GetStartLocation();								//function vector GetStartLocation()
	virtual FRotator GetStartRotation();							//function rotator GetStartRotation()

	virtual void LoadEditorIcon();
	virtual void SetClass();
};
