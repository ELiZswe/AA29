// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Net/UnrealNetwork.h"
//#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"

#include "GameFramework/PlayerState.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"

#include "AA29/AA2_WorldSettings.h"

#include "AA2_PlayerState.generated.h"

class AInventory;


UCLASS()
class AA29_API AAA2_PlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	AAA2_PlayerState();

	//myOwn
	UPROPERTY(Replicated)				TArray<TSubclassOf<AInventory>>		My_Pawn_Inventory;
	UPROPERTY(Replicated)				FString								MyState;
	UPROPERTY(Replicated)				int32								TeamID;											//var int TeamID;
	UPROPERTY(Replicated)				TSubclassOf <class ASoldierClass>	SpawnClass;
	UPROPERTY(Replicated)				TSubclassOf <class AAGP_Weapon>		CurrentWeapon;

	UFUNCTION(BlueprintCallable)		void Set_My_Pawn_Inventory(TArray<TSubclassOf<AInventory>> this_inventory);
	UFUNCTION(BlueprintCallable)		TArray<TSubclassOf<AInventory>> Get_My_Pawn_Inventory();
//	UFUNCTION()							void Set_Weapon(TSubclassOf<AAGP_Weapon> Weapon);
	UFUNCTION(BlueprintCallable)		FString GetHumanReadableName() const;


	void PostAuthComplete();
	void BlinkCharacterOnRadar(float BlinkDuration);
	TWeakObjectPtr < class AActor > GetPlayerStart();
	virtual void PostBeginPlay();
	virtual void PostNetBeginPlay();
	virtual bool NeedNetNotify();
	virtual void PostNetReceive();
	virtual void Destroyed();
	void SetCharacterVoice(FString S);
	void SetCharacterName(FString S);
	void Reset();
	void Tick(float DeltaTime);
	virtual void GetPortrait();
	void UpdateCharacter();
	virtual void UpdatePlayerLocation();
	//virtual void DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos)
	void ClientNameChange();
	void SetPlayerName(const FString& S);
	void SetWaitingPlayer(bool B);
	void SetChatPassword(FString InPassword);
	void SetVoiceMemberMask(int32 NewMask);
	virtual FString GetCallSign();
	virtual FString GetNameCallSign();
	//virtual void ContainedInBox(ABox* BBox);
	virtual void UpdateCommVolume();
	virtual AVolume* GetCommVolume();
	virtual AAGP_Objective* GetNearbyObjective(AVolume* C, bool bDefender);
	virtual void GetLocationName(AVolume* C);
	virtual FString GetSquadName();
	virtual bool EquivalentName(FString Name);
	void NotifyPromotion(bool bFTL, uint8 yFT);
	void NotifyNoScore(FName Reason);
	void NotifyClientMessage(FString Message);
	void CalculateWeight(float maxScore);
	float GetWeight();
	virtual int32 GetHonor();
	virtual bool HasGroupIcon();
	virtual int32 GetGroup();
	virtual void SetGroup(uint8 newgroup);
	void SUToggle();
	virtual bool SuperUser(bool bCheckEnabled);
	bool Administrator();
	virtual bool IsPlayerAdmin();
	int32 GetExperience();
	int32 GetCumRounds();
	float GetPlayTime();
	void GetController();
	void ResetPerRound();
	int32 GetRoundScore_Total();
	int32 GetRoundScore_Leadership();
	int32 GetRoundScore_Wins();
	int32 GetRoundScore_Objectives();
	int32 GetRoundScore_Deaths();
	int32 GetRoundScore_Kills();
	int32 GetRoundScore_ROE();
	virtual void ClientNotifyLostMedic();
	virtual int32 GetGoalScore();
	void UpdateScore();
	void PScoreKill();
	void PScoreAIVehicleKill();
	void PScoreDeath();
	void PScoreFF(int32 newscore);
	float CheckROE();
	void ScoreDecoMesh(int32 DestroyPoints);
	void PScoreObjective(int32 newscore);
	void ScoreRound(bool bWon);
	float GetMultiplier();
	int32 GetSLBonus();
	int32 GetFTLBonus();
	void CalculateLeaderScore();
	void CalculateLeaderPenalty();
	void IncrementCumulativeScores();
	int32 CalculateExperience();
	void TotalExperience(bool bShowUserDetail);
	void ResetScores();
	virtual bool hasSoldiersCharacter();
	virtual bool IsFriend(AAA2_PlayerState* Other, ATeamInfo* otherTeam);
	virtual bool IsEnemy(AAA2_PlayerState* Other, ATeamInfo* otherTeam);
	virtual void Timer();
	//void ServerUpdateVolumeZone(AVolume* volNewPlayerVolume, AZoneInfo* volNewPlayerZone, AVolume* volNewCommVol);
	void TeamReset();
	virtual void GetPawnLocation();
	virtual void GetPawnYaw();
	void UpdatePawnYaw();
	void ServerSetMyPawn(APawn* new_pawn);
	virtual void WaitingForPawn(AAA2_PlayerState* PRI);
	virtual void FoundWaitingForPawn(APawn* p);
	virtual APawn* GetMyPawn();
	virtual bool isDead();
	virtual bool isSpectator();
	virtual bool IsSquadLeader();
	virtual bool isTeamLeader();
	virtual AAA2_PlayerState* GetSquadLeader();
	virtual AAA2_PlayerState* GetFTLeader();
	void SubmitPlayerRequest(int32 UnitID, int32 Index);
	void RemovePlayerRequest(AAA2_PlayerState* PRI);
	void CanScore();





	float fLastConnectionResponseTimeLimit;					//var const float fLastConnectionResponseTimeLimit;
	float fLastConnectionResponseTime;						//var const float fLastConnectionResponseTime;
	bool bPlayerAdmin;										//var bool bPlayerAdmin;
	FString sCurrentWeaponClass;							//var string sCurrentWeaponClass;
	FString LastLocationString;								//var string LastLocationString;
	AVolume* LastCommVol;									//var Volume LastCommVol;
	AVolume* CommVol;										//var Volume CommVol;
	bool bTournamentRestartTournamentRequest;				//var bool bTournamentRestartTournamentRequest;
	bool bTournamentMatchPauseRequest;						//var bool bTournamentMatchPauseRequest;
	bool bTournamentTeamSwapRequest;						//var bool bTournamentTeamSwapRequest;
	bool bTournamentRestartRequest;							//var bool bTournamentRestartRequest;
	bool bTournamentWarmupRequest;							//var bool bTournamentWarmupRequest;
	bool bTournamentStartRequest;							//var bool bTournamentStartRequest;
	bool bTournamentTeamCaptain;							//var bool bTournamentTeamCaptain;
	bool bTournamentTeamRosterLocked;						//var bool bTournamentTeamRosterLocked;
	bool bTournamentTeamReady;								//var bool bTournamentTeamReady;
	bool bTournamentSquadLeader;							//var bool bTournamentSquadLeader;
	uint8 bIsQualified;										//var const byte bIsQualified;
	AActor* requiredClass;									//var class<Actor> requiredClass;
	bool bMuted;											//var bool bMuted;
	bool bSUEnabled;										//var bool bSUEnabled;
	uint8 _Group;											//var byte _Group;
	int32 _ExperienceDelta;									//var int _ExperienceDelta;
	int32 _Experience;										//var int _Experience;
	int32 _prevROE;											//var int _prevROE;
	int32 _prevKills;										//var int _prevKills;
	int32 _prevDeaths;										//var int _prevDeaths;
	int32 _prevObjectives;									//var int _prevObjectives;
	int32 _prevWins;										//var int _prevWins;
	int32 _prevLeadership;									//var int _prevLeadership;
	int32 _prevTotal;										//var int _prevTotal;
	int32 _cumROE;											//var int _cumROE;
	int32 _cumKills;										//var int _cumKills;
	int32 _cumDeaths;										//var int _cumDeaths;
	int32 _cumObjectives;									//var int _cumObjectives;
	int32 _cumWins;											//var int _cumWins;
	int32 _cumLeadership;									//var int _cumLeadership;
	int32 _cumTotal;										//var int _cumTotal;
	int32 _LastTimeUpdate;									//var int _LastTimeUpdate;
	int32 _cumRounds;										//var int _cumRounds;
	float _fWeight;											//var float _fWeight;
	int32 _iTrust;											//var int _iTrust;
	bool _bSoldiersCharacter;								//var bool _bSoldiersCharacter;
	FString SquadName;										//var string SquadName;
	FString votekick;										//var string votekick;
	float tNextVoteAllowed;									//var float tNextVoteAllowed;
	bool bIsUAVPilot;										//var bool bIsUAVPilot;
	bool bIsUAVNavigator;									//var bool bIsUAVNavigator;
	bool bIsMortarSpotter;									//var bool bIsMortarSpotter;
	bool bQualifiedUAVPilot;								//var bool bQualifiedUAVPilot;
	bool bQualifiedUAVNavigator;							//var bool bQualifiedUAVNavigator;
	bool bQualifiedMortarSpotter;							//var bool bQualifiedMortarSpotter;
	bool bQualifiedES2;										//var bool bQualifiedES2;
	bool bQualifiedUseCROWS;								//var bool bQualifiedUseCROWS;
	bool bQualifiedDriveHMMWV;								//var bool bQualifiedDriveHMMWV;
	bool bQualifiedJavelin;									//var bool bQualifiedJavelin;
	bool bQualifiedSF;										//var bool bQualifiedSF;
	bool bQualifiedMedic;									//var bool bQualifiedMedic;
	bool bQualifiedRanger;									//var bool bQualifiedRanger;
	bool bQualifiedAirborne;								//var bool bQualifiedAirborne;
	bool bQualifiedSniper;									//var bool bQualifiedSniper;
	bool bQualifiedBCT;										//var bool bQualifiedBCT;
	bool bQualifiedViaInstantAction;						//var bool bQualifiedViaInstantAction;
	bool bCallForMedic;										//var bool bCallForMedic;
	bool bIsMedic;											//var bool bIsMedic;
	bool bLostMedic;										//var bool bLostMedic;
	bool bWillBeMedic;										//var bool bWillBeMedic;
	bool bWantsMedic;										//var bool bWantsMedic;
	bool bAvoidLeaderRole		;							//var bool bAvoidLeaderRole;
	bool bWantsSquadLeader;									//var bool bWantsSquadLeader;
	bool bWantsFTLeader;									//var bool bWantsFTLeader;
	bool LinkedToSquadLeader;								//var bool LinkedToSquadLeader;
	bool LinkedToFTLeader;									//var bool LinkedToFTLeader;
	int32 LinkedTo;											//var int LinkedTo;
	int32 LinkedToMe;										//var int LinkedToMe;
	int32 TempLinked;										//var int TempLinked;
	int32 PawnYaw;											//var int PawnYaw;
	uint8 FT;												//var byte FT;
	//AVehicleReplicationInfo* VehicleReplicationInfo;		//var VehicleReplicationInfo VehicleReplicationInfo;
	int32 SwapRequest;										//var int SwapRequest;
	AAA2_PlayerState* PRI_WaitingForPawn;					//var PlayerReplicationInfo PRI_WaitingForPawn;
	float fpTimeSinceLastPingCalculation;					//var float fpTimeSinceLastPingCalculation;
	int32 LocationZ;										//var int LocationZ;
	int32 LocationY;										//var int LocationY;
	int32 LocationX;										//var int LocationX;
	APawn* myPawn;											//var Pawn myPawn;
	bool bDead;												//var bool bDead;
	bool bVIPPS;											//var bool bVIPPS;
	bool bSpecialForcesPS;									//var bool bSpecialForcesPS;
	bool bGuerrillaPS;										//var bool bGuerrillaPS;
	int32 _Credited_Leadership;								//var int _Credited_Leadership;
	int32 _Credited_Wins;									//var int _Credited_Wins;
	int32 Score_ROE;										//var int Score_ROE;
	int32 Score_Kills;										//var int Score_Kills;
	int32 Score_Deaths;										//var int Score_Deaths;
	int32 Score_Objectives;									//var int Score_Objectives;
	int32 Score_Wins;										//var int Score_Wins;
	int32 Score_Leadership;									//var int Score_Leadership;
	int32 Score_Total;										//var int Score_Total;
	uint8 DesiredTeam;										//var byte DesiredTeam;
	float RadarBlinkEndTime;								//var float RadarBlinkEndTime;
	float RadarBlinkStartTime;								//var float RadarBlinkStartTime;
	float BlinkLatency;										//var float BlinkLatency;
	float LastRadarBlinkEndTime;							//var float LastRadarBlinkEndTime;
	float LastRadarBlinkStartTime;							//var float LastRadarBlinkStartTime;
	int32 RadarDrawOpacity;									//var int RadarDrawOpacity;
	bool bVisibleLastTick;									//var bool bVisibleLastTick;
	uint8 VoiceID;											//var byte VoiceID;
	int32 VoiceMemberMask;									//var int VoiceMemberMask;
	int32 ActiveChannel;									//var int ActiveChannel;
	//AVoiceChatRoom* PrivateChatRoom;						//var VoiceChatRoom PrivateChatRoom;
	bool bRegisteredChatRoom;								//var bool bRegisteredChatRoom;
	//AVoiceChatReplicationInfo* VoiceInfo;					//var VoiceChatReplicationInfo VoiceInfo;
	//ALinkedReplicationInfo* CustomReplicationInfo;		//var LinkedReplicationInfo CustomReplicationInfo;
	//AVehicle* CurrentVehicle;								//var Vehicle CurrentVehicle;
	int32 Kills;											//var int Kills;
	int32 GoalsScored;										//var int GoalsScored;
	FString StringUnknown;									//var localized string StringUnknown;
	FString StringSpectating;								//var localized string StringSpectating;
	FString StringDead;										//var localized string StringDead;
	int32 StartTime;										//var int StartTime;
	uint8 PacketLoss;										//var byte PacketLoss;
	bool bTeamNotified;										//var bool bTeamNotified;
	bool bNoTeam;											//var bool bNoTeam;
	bool bReceivedPing;										//var bool bReceivedPing;
	bool bWelcomed;											//var bool bWelcomed;
	bool bBot;												//var bool bBot;
	bool bOutOfLives;										//var bool bOutOfLives;
	bool bReadyToPlay;										//var bool bReadyToPlay;
	bool bWaitingPlayer;									//var bool bWaitingPlayer;
	bool bOnlySpectator;									//var bool bOnlySpectator;
	bool bIsSpectator;										//var bool bIsSpectator;
	bool bIsFemale;											//var bool bIsFemale;
	bool bAdmin;											//var bool bAdmin;
	FString VoiceTypeName;									//var string VoiceTypeName;
	//AVoicePack* VoiceType;								//var class<VoicePack> VoiceType;
	
	ATeamInfo* Team;										//var TeamInfo Team;
	int32 PlayerID;											//var int PlayerID;
	FString PlayerMAC;										//var string PlayerMAC;
	FString PreviousName;									//var string PreviousName;
	FString OldName;										//var string OldName;
	FString OldCharacterName;								//var string OldCharacterName;
	FString CharacterName;									//var string CharacterName;
	FString AuthUserName;									//var string AuthUserName;
	FString PlayerName;										//var string PlayerName;
	int32 NumLives;											//var int NumLives;
	int32 LastPlayerZone;									//var ZoneInfo LastPlayerZone;
	//AZoneInfo* PlayerZone;								//var ZoneInfo PlayerZone;
	AVolume* LastPlayerVolume;								//var Volume LastPlayerVolume;
	AVolume* PlayerVolume;									//var Volume PlayerVolume;
	uint8 Ping;												//var byte Ping;
	//ADecoration* HasFlag;									//var Decoration HasFlag;




};
