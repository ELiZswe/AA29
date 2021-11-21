// All the original content belonged to the US Army


#include "AGP_HUD.h"
#include "AA29/MyStructs.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Volume/CommVolume/AA2_CommVolume.h"
#include "AA29/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/AA29.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/WorldSettings.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/AA2_GameState.h"
#include "AA29/AA2_PlayerState.h"
#include "GameFramework/PlayerController.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Canvas.h"

AAGP_HUD::AAGP_HUD(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{
	// Set the crosshair texture
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_01.hud_crosshair_01'"));			//Dot
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_02.hud_crosshair_02'"));			//Cross
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_03.hud_crosshair_03'"));			//Circle
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_04.hud_crosshair_04'"));			//Circle with Cross
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_05.hud_crosshair_05'"));			//4 Lines
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_06.hud_crosshair_06'"));			//3 lines
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_07.hud_crosshair_07'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_08a.hud_crosshair_08a'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_09a.hud_crosshair_09a'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_10a.hud_crosshair_10a'"));
	//static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_crosshair_11a.hud_crosshair_11a'"));
	CrosshairTex = CrosshairTexObj.Object;


	tFill = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_goal_fill.hud_goal_fill'"), NULL, LOAD_None, NULL),
	//FontInfoClass = "Gameplay.FontInfo"
	bShowHUD = true;
	bFirstTime = true;
	bMainMenuFirstTime = true;
	bShowSpectatorInfo = true;
	CustomHUDColor = FColor(0, 255, 0, 150);
	CustomHUDAlpha = 255;
	ServerBrowser = "AA Browser";
	MessagePromptColor = FColor(0, 255, 255, 255);
	tArmyBox = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/ui_hud_border_nofill.ui_hud_border_nofill'"), NULL, LOAD_None, NULL);
	RadarMaskIndex = 1;
	bRotateRadarAroundPlayer = true;
	HUDColor = FColor(0, 255, 0, 150);
	DefaultFontScale = 1.0f;
	//DetermineVersionLabel(false, false, false, false, false, false, false, false, false, false, false);
}

void AAGP_HUD::DrawHUD()
{
	FString myLocation;
	uint8 myPriority;
	FString myMapName;
	FString myHealth;
	float textWidth = 0;
	float textHeight = 0;
	int32 padding = 30;
	int32 myRow = 0;
	TArray<AActor*> TheActors;
	Super::DrawHUD();
	
	// Draw very simple crosshair
	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	// offset by half the texture's dimensions so that the center of the texture aligns with the center of the Canvas
	const FVector2D CrosshairDrawPosition((Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5)),	(Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));
	// draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::Yellow);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
	AAGP_Pawn* myPawn = Cast<AAGP_Pawn>(GetOwningPawn());

	//Draw Server Typr
	myRow = 0;
	DetermineVersionLabel(false, true, false, false, false, false, false, false, false, false, false);
	GetTextSize(_sVersionInfo, textWidth, textHeight, UE4Font);
	DrawText(
		_sVersionInfo,
		FLinearColor(1, 1, 1, 1),
		(Canvas->ClipX - (textWidth * 2) - padding),					//Width   (X)
		(myRow* textHeight * 2) + padding,								//Height  (Y)
		UE4Font,
		DefaultFontScale * 2,
		false		//scale position of message with HUD scale
	);
	
	HUDSetup(Canvas);

	//Draw Map Name
	myRow += 1;
	myMapName = Cast<AAA2_WorldSettings>(GetWorld()->GetWorldSettings())->Title;
	if (myMapName != "")
	{
		GetTextSize(myMapName, textWidth, textHeight, UE4Font);
		DrawText(
			myMapName,
			FLinearColor(0, 1, 0, 1),
			(Canvas->ClipX - (textWidth *2) - padding),					//Width   (X)
			(myRow* textHeight * 2) + padding,							//Height  (Y)
			UE4Font,
			DefaultFontScale * 2,
			false		//scale position of message with HUD scale
		);
	}

	//Draw Location
	myRow += 1;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAA2_CommVolume::StaticClass(), TheActors);
	myLocation = "Unknown";
	myPriority = 0;
	APlayerController* myController = GetOwningPlayerController();
	

	for (auto& currentActor : TheActors)
	{
		if (currentActor->IsA(AAA2_CommVolume::StaticClass()))
		{
			TArray<AActor*> HumansInZone;
			Cast<AAA2_CommVolume>(currentActor)->GetOverlappingActors(HumansInZone, TSubclassOf<AAGP_Pawn>());
			for (int32 i = 0; i < HumansInZone.Num(); i++)
			{
				if (HumansInZone[i] == myPawn)
				{
					if (Cast<AAA2_CommVolume>(currentActor)->Priority >= myPriority)
					{
						myLocation = Cast<AAA2_CommVolume>(currentActor)->Location;
						myPriority = Cast<AAA2_CommVolume>(currentActor)->Priority;
					}
				}
			}
		}
	}

	GetTextSize(myLocation, textWidth, textHeight, UE4Font);
	DrawText(
		myLocation,
		FLinearColor(0, 1, 0, 1),
		(Canvas->ClipX - (textWidth * 2) - padding),									//Width   (X)
		(myRow* textHeight *2)+padding,													//Height  (Y)
		UE4Font,
		DefaultFontScale * 2,
		false		//scale position of message with HUD scale
	);
	myRow += 1;

	if (GetWorld())
	{
		if (myPawn)
		{	
			myHealth = "Health: "  + myPawn->GetHealthString();
			GetTextSize(myHealth, textWidth, textHeight, UE4Font);
			DrawText(
				myHealth,
				FLinearColor(0, 1, 0, 1),
				(Canvas->ClipX - (textWidth * 2) - padding),							//Width   (X)
				(myRow* textHeight * 2) + padding,										//Height  (Y)
				UE4Font,
				DefaultFontScale * 2,
				false		//scale position of message with HUD scale
			);
			myRow += 1;

			APlayerState* PS = myPawn->GetPlayerState();
			if (PS)
			{
				int32 NumberFrags = 0;
				int32 NumberSmokes = 0;
				int32 NumberFlashes = 0;
				FString MyFrags = "";
				FString MySmokes = "";
				FString MyFlashes = "";
				TArray<TSubclassOf<AInventory>> Local_Inventory = Cast<AAA2_PlayerState>(PS)->My_Pawn_Inventory;

				for (TSubclassOf<AInventory> ThisInv : Local_Inventory)
				{
					if (ThisInv->IsChildOf(AThrow_M67_Frag::StaticClass()))
					{
						NumberFrags += 1;
					}
					if (ThisInv->IsChildOf(AThrow_M83_Smoke::StaticClass()))
					{
						NumberSmokes += 1;
					}
					if (ThisInv->IsChildOf(AThrow_M84_Stun::StaticClass()))
					{
						NumberFlashes += 1;
					}
				}

				MyFrags = "Frags: " + FString::FromInt(NumberFrags);
				MySmokes = "Smokes: " + FString::FromInt(NumberSmokes);
				MyFlashes = "Flashes: " + FString::FromInt(NumberFlashes);

				GetTextSize(MyFrags, textWidth, textHeight, UE4Font);
				DrawText(
					MyFrags,
					FLinearColor(0, 1, 0, 1),
					(Canvas->ClipX - (textWidth * 2) - padding),							//Width   (X)
					(myRow* textHeight * 2) + padding,										//Height  (Y)
					UE4Font,
					DefaultFontScale * 2,
					false		//scale position of message with HUD scale
				);
				myRow += 1;

				GetTextSize(MySmokes, textWidth, textHeight, UE4Font);
				DrawText(
					MySmokes,
					FLinearColor(0, 1, 0, 1),
					(Canvas->ClipX - (textWidth * 2) - padding),							//Width   (X)
					(myRow* textHeight * 2) + padding,										//Height  (Y)
					UE4Font,
					DefaultFontScale * 2,
					false		//scale position of message with HUD scale
				);
				myRow += 1;

				GetTextSize(MyFlashes, textWidth, textHeight, UE4Font);
				DrawText(
					MyFlashes,
					FLinearColor(0, 1, 0, 1),
					(Canvas->ClipX - (textWidth * 2) - padding),							//Width   (X)
					(myRow* textHeight * 2) + padding,										//Height  (Y)
					UE4Font,
					DefaultFontScale * 2,
					false		//scale position of message with HUD scale
				);
				myRow += 1;
			}
			AAA2_GameState* GS = Cast<AAA2_GameState>(GetWorld()->GetGameState());
			/*
			if (GS != nullptr)
			{
				TArray<APlayerState *> player_array = GS->PlayerArray;
				for (int32 b = 0; b < player_array.Num(); b++)
				{
					AAA2_PlayerState* ThePlayerState = Cast<AAA2_PlayerState>(player_array[b]);
					FColor drawColor = FLinearColor(1.0f, 1.0f, 1.0f, 1.0f).ToFColor(true);
					FVector OutSpawnPosition = FVector(0, 0, 100);
					
					FString theText = "Name: ";
					if (ThePlayerState->GetPawn() != nullptr)
					{
						theText = theText.Append(ThePlayerState->GetPawn()->GetName());
					}
					else
					{
						theText = theText.Append("None");
					}
					theText = theText.Append("\n Ping: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->GetPing()));
					theText = theText.Append("\n State: ");
					theText = theText.Append(ThePlayerState->MyState);
					theText = theText.Append("\n TeamID: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->TeamID));
					theText = theText.Append("\n SpawnClass: ");
					theText = theText.Append(ThePlayerState->SpawnClass->GetName());
					theText = theText.Append("\n WeaponClass: ");
					if (ThePlayerState->CurrentWeapon != nullptr)
					{
						theText = theText.Append(ThePlayerState->CurrentWeapon->GetName());
					}
					else
					{
						theText = theText.Append("None");
					}
					
					if (ThePlayerState->GetPawn() != nullptr)
					{
						theText = theText.Append("\n Pawnb:bIsProne: ");
						theText = theText.Append(Cast<AAGP_Pawn>(ThePlayerState->GetPawn())->bIsProne ? "True" : "False");
						theText = theText.Append("\n Pawnb:bIsCrouched: ");
						theText = theText.Append(Cast<AAGP_Pawn>(ThePlayerState->GetPawn())->bIsCrouched2 ? "True" : "False");
					}
					theText = theText.Append("\n bVIPPS: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->bVIPPS));
					theText = theText.Append("\n bSpecialForcesPS: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->bSpecialForcesPS));
					theText = theText.Append("\n bGuerrillaPS: ");
					theText = theText.Append(FString::FromInt(ThePlayerState->bGuerrillaPS));
					
					if (ThePlayerState->GetPawn() != nullptr)
					{
						DrawDebugString(GetWorld(), OutSpawnPosition, theText, (ThePlayerState->GetPawn()), drawColor, 0.0f, true);
					}
				}
			}
			*/
		}
	}
}


void AAGP_HUD::DetermineVersionLabel(bool bCheat, bool bDev, bool bBeta, bool bLeased, bool bOfficial, bool bNATO, bool bTournament, bool bUltimateArena, bool bIsAuthorized, bool bExploreTheArmyServer, bool bAllowForceclassing)
{
	FString cheat;
	FString tournament;
	FString Debug;
	FString sSubTinyVersion;
	
	if (bCheat)
	{
		cheat = "(Cheats) ";
	}
	if (bTournament)
	{
		if(GetWorld())
		{
			if (GetWorld()->GetGameState() != NULL)
			{
				tournament = "(Tournament - " + Cast<AAA2_GameState>(GetWorld()->GetGameState())->sTournamentState + ")";
			}
		}
	}
	if (bExploreTheArmyServer)
	{
		if (bOfficial)
		{
			sServerMode = "(Official Explorer Server - No HONOR Gained) ";
		}
		else
		{
			sServerMode = "(Unauthorized Explorer Server) ";
		}
	}
	else
	{
		if (bDev)
		{
			sServerMode = "(Dev Server) ";
		}
		else
		{
			if (bBeta)
			{
				sServerMode = "(Beta Server) ";
			}
			else
			{
				if (bNATO)
				{
					sServerMode = "(Europe Server) ";
				}
				else
				{
					if (bLeased)
					{
						if (bOfficial)
						{
							sServerMode = "(Leased-Official Server) ";
						}
						else
						{
							sServerMode = "(Leased Server) ";
						}
					}
					else
					{
						if (bOfficial)
						{
							sServerMode = "(Official Server) ";
						}
						else
						{
							if (bIsAuthorized)
							{
								sServerMode = "(Authorized Server) ";
							}
							else
							{
								sServerMode = "(Unauthorized Server) ";
							}
						}
					}
				}
			}
		}
	}
	//if (IsDebugBuild())
	//{
	//	Debug = "(DEBUG) ";
	//}
	if (bAllowForceclassing)
	{
		sServerMode = FString("(FC Allowed) ") + sServerMode;
	}

	
	sSubTinyVersion = FString::FromInt(GetVersionAGPTiny());
	if (GetVersionAGPSubTiny() > 0)
	{
		sSubTinyVersion = sSubTinyVersion + FString(".");
		if (GetVersionAGPSubTiny() < 10)
		{
			sSubTinyVersion = sSubTinyVersion + FString("0");
		}
		sSubTinyVersion = sSubTinyVersion + FString::FromInt(GetVersionAGPSubTiny());
	}
	_sVersionInfo = FString::FromInt(GetVersionAGPMajor()) + "." + FString::FromInt(GetVersionAGPMinor()) + FString(".") + sSubTinyVersion;
	
	//if (PlayerOwner.GetNetMode() != ENetMode::NM_Standalone)
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		if(Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			_sVersionInfo = cheat + tournament + sServerMode + " (Coop) " + Debug + _sVersionInfo;
		}
		else
		{
			_sVersionInfo = cheat + tournament + sServerMode + Debug + _sVersionInfo;
		}
	}
	else
	{
		_sVersionInfo = "Offline " + Debug + _sVersionInfo;
	}
	
	switch (GetNetMode())
	{
		case ENetMode::NM_Standalone:
		{
			_sVersionInfo += " NM_Standalone";
			break;
		}
		case ENetMode::NM_DedicatedServer:
		{
			_sVersionInfo += " NM_DedicatedServer";
			break;
		}
		case ENetMode::NM_ListenServer:
		{
			_sVersionInfo += " NM_ListenServer";
			break;
		}
		case ENetMode::NM_Client:
		{
			_sVersionInfo += " NM_Client";
			break;
		}
	}
	

}

int32 AAGP_HUD::GetVersionAGPMajor()
{
	return 2;
}

int32 AAGP_HUD::GetVersionAGPMinor()
{
	return 9;
}

int32 AAGP_HUD::GetVersionAGPTiny()
{
	return 0;
};


int32 AAGP_HUD::GetVersionAGPSubTiny()
{
	return 0;
}

bool AAGP_HUD::AllowFade()
{
	if (bShowMainMenu)
	{
		return false;	//Don't allow a fade if I'm looking at the menu
	}
	return true;
}
/*
void AAGP_HUD::HideHUD()
{
	bHideHUD = true;
}
*/
			

/*
void AAGP_HUD::ShowHud()
{
	bHideHUD = false;
}
*/


void AAGP_HUD::GetMouseX()
{

}
void AAGP_HUD::GetMouseY()
{

}
void AAGP_HUD::UpdatePrecacheMaterials()
{

}
void AAGP_HUD::PrecacheFonts(UCanvas* C)
{
}
void AAGP_HUD::UseSmallFont(UCanvas* C)
{
}
void AAGP_HUD::TournamentNotifyNewTeamCaptain()
{
}
void AAGP_HUD::TournamentNotifyOtherTeamReady()
{

}
void AAGP_HUD::TournamentNotifyNewTeamName()
{

}
void AAGP_HUD::TournamentNotifyNewWeaponClassLockState()
{

}
void AAGP_HUD::TournamentNotifyMyTeamReady()
{

}
void AAGP_HUD::SetHUDActor()
{

}
void AAGP_HUD::FreeHUDActor()
{

}
void AAGP_HUD::GetHUDControl(int32 Id)
{

}
void AAGP_HUD::CreateUIObject(FString ObjectName)
{

}
void AAGP_HUD::Destroyed()
{
}
//Exists in HUD
void AAGP_HUD::PostRender_Stage1(UCanvas* C)
{
}
void AAGP_HUD::PostRender_Stage2(UCanvas* C)
{
}
void AAGP_HUD::DrawConsole(UCanvas* C)
{
}
void AAGP_HUD::PostRender_Stage2_DrawConsole(UCanvas* C)
{
}

void AAGP_HUD::WorldSpaceOverlays()
{

}
//void AAGP_HUD::SetMissionResultTarget(ScriptObject so)
//{
//}
void AAGP_HUD::CreateFrame()
{
}
void AAGP_HUD::FillListBox()
{
}
void AAGP_HUD::FrameOverride()
{
}
void AAGP_HUD::DisablePlayer()
{
	if (PlayerOwner != nullptr)
	{
		/*
		PlayerOwner->bFire = 0;
		if (PlayerOwner->Player != nullptr)
		{
			PlayerOwner->Player->bDetachMouse = true;
			PlayerOwner->Player->bShowWindowsMouse = true;
		}
		*/
	}
}
void AAGP_HUD::EnablePlayer()
{
	
	if (PlayerOwner != nullptr)
	{
		if (PlayerOwner->Player != nullptr)
		{
			/*
			PlayerOwner.Player.bDetachMouse = False;
			PlayerOwner.Player.bShowWindowsMouse = False;
			*/
		}
		/*
		if (PlayerOwner->PlayerReplicationInfo != nullptr)
		{
			if (!PlayerOwner.PlayerReplicationInfo.bReadyToPlay)
			{
				HumanController(PlayerOwner).ServerEnablePlayer();
			}
		}
		*/
	}
}
void AAGP_HUD::SetConsoleWidth(FString sNewWidthPercent)
{

}
void AAGP_HUD::OLD_ShowScores()
{
	if (!bShowMainMenu)
	{
		//Super::OLD_ShowScores();
	}
}
void AAGP_HUD::ShowScores()
{

}
void AAGP_HUD::OpenGameMenu()
{

}
void AAGP_HUD::CloseGameMenu()
{

}
void AAGP_HUD::ToggleAGPGameMenu()
{

}
void AAGP_HUD::ToggleAGPMainMenu()
{

}
void AAGP_HUD::CloseAllMenus()
{
	CloseGameMenu();
	CloseMainMenu();
	CloseMissionResults();
	bShowScores = false;
}
void AAGP_HUD::OpenMainMenu()
{
	return;
}
void AAGP_HUD::CloseMainMenu()
{
	/*
	if (bShowMainMenu == true)
	{
		if (iDesiredXRes < 800 || iDesiredYRes < 600)
		{
			PlayerConsole.ConsoleCommand("setres " $ iDesiredXRes $ "x" $ iDesiredYRes);
		}
		mmFrame.Hide();
		PlayerConsole.MenuClosed();
		bShowMainMenu = False;
		if (ClientBeacon != None)
		{
			ClientBeacon.StopBeacon();
		}
		Region.Zone.ZoneEffect = SavedZoneEffect;
		if (PlayerOwner != None)
		{
			if (!Level.sLevelName ~= "entry")
			{
				PlayerOwner.SetPause(False);
			}
			PlayerOwner.MenuLock(False);
		}
	}
	*/
}
void AAGP_HUD::OpenMissionResults()
{
	/*
	if (mrFrame != None)
	{
		if (FrameOverride())
		{
			return;
		}
		bShowMissionResults = true;
		DisablePlayer();
		if (PlayerOwner != nullptr)
		{
			PlayerOwner.MenuLock(true);
		}
	}
	*/
}
void AAGP_HUD::CloseMissionResults()
{
	/*
	if (bShowMissionResults == true)
	{
		mrFrame.Hide();
		bShowMissionResults = false;
		EnablePlayer();
		if (_MissionResultTarget != NULL)
		{
			_MissionResultTarget.Notify();
		}
		if (PlayerOwner != None)
		{
			PlayerOwner.MenuLock(false);
		}
	}
	*/
}
void AAGP_HUD::OpenMap(FString sMap)
{
	/*
	if (sMap != "")
	{
		CloseGameMenu();
		PawnOwner.ConsoleCommand("start " $ sMap);
	}
	*/
}
void AAGP_HUD::SpawnItem(FString Item)
{
	/*
	if (Item != "")
	{
		PlayerOwner.ConsoleCommand("summon " $ Item);
	}
	*/
}
bool AAGP_HUD::KeyType(int32 Key)
{
	/*
	if (PlayerOwner.Player.Console != None)
	{
		if (PlayerOwner.Player.Console.IsInState('Typing'))
		{
			return false;
		}
	}
	if (bShowMainMenu)
	{
		return mmFrame.KeyType(Key);
	}
	if (bShowGameMenu)
	{
		return gmFrame.KeyType(Key);
	}
	*/
	return false;
}
void AAGP_HUD::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{

}
void AAGP_HUD::ConsoleOpened()
{
	/*
	if (PlayerConsole.bTyping && !_bUIConsole)
	{
		CloseGameMenu();
		CloseMainMenu();
	}
	*/
}
void AAGP_HUD::DrawMenu(UCanvas* C)
{

}
void AAGP_HUD::DrawAngleEditor(UCanvas* C)
{

}
void AAGP_HUD::PostBeginPlay()
{

}
void AAGP_HUD::HUDSetup(UCanvas* C)
{
	oldclipx = Canvas->ClipX;
	PawnOwner = Cast<AAGP_Pawn>(GetOwningPawn());
}
void AAGP_HUD::PlayStartupMessage(uint8 Stage)
{
}
void AAGP_HUD::GetConsoleMessageOffsetX(UCanvas* C)
{
}
void AAGP_HUD::DisplayMOTD()
{
//	LastMOTDDisplaySeconds = PlayerOwner.GameReplicationInfo.MOTDDisplaySeconds;
//	PlayerOwner.SetProgressTime(LastMOTDDisplaySeconds);
}
void AAGP_HUD::DrawHUD(UCanvas* C)
{
}
int32 AAGP_HUD::GetMessagePromptPosition()
{
	if (bPortalDebugView)
	{
		if (bShowDebugInfo)
		{
			return 305;
		}
		else
		{
			return 260;
		}
	}
	else
	{
		return 1;
	}
}
int32 AAGP_HUD::GetMessagePosition()
{
	if (bPortalDebugView)
	{
		if (bShowDebugInfo)
		{
			return 320;
		}
		else
		{
			return 275;
		}
	}
	else
	{
		return 18;
	}
}
//void AAGP_HUD::LocalizedMessage(class<LocalMessage>  Message, int32 Switch, optional PlayerReplicationInfo RelatedPRI_1, optional PlayerReplicationInfo RelatedPRI_2, optional Object OptionalObject, optional string CriticalString)
//{
//}
void AAGP_HUD::DrawTypingPrompt(UCanvas* C, FString Text, int32 pos)
{
	/*
	UFont oldfont;
	oldfont = Canvas.Font;
	UseSmallFont(Canvas);
	Canvas->DrawColor = MessagePromptColor;
	Canvas->DrawColor.A = 255;  // always need to see this for safety's sake, so force alpha 255
	Canvas.SetPos(4, GetMessagePromptPosition() * Canvas->SizeX / 600);

	// agp [edc] MERGE3236: Changed this to reflect changes in HUD.uc and draw the cursor position correctly
	Canvas.DrawTextClipped("(>"@Left(Text, Pos) + chr(4) + Eval(Pos < Len(Text), Mid(Text, Pos), "_"), true);
	Canvas.Font = oldfont;
	*/
}
float AAGP_HUD::GetTextHeight(UCanvas* C)
{
	/*
	float XL;
	float YL;
	Canvas->StrLen("TEST0", XL, YL);
	return YL;
	*/
	return 0.0f;
}
float AAGP_HUD::GetTextWidth(UCanvas* C)
{
	/*
	float XL;
	float YL;

	Canvas->StrLen("XXXX", XL, YL);
	return XL / 4.0f;
	*/
	return 0.0f;
}
void AAGP_HUD::ReWrapMessages(UConsole* MyConsole, UCanvas* MyCanvas)
{
	/*
	int32 i;
	if (LastSizeX == Canvas->SizeX)
	{
		return;
	}
	for (i = 0; i < 64; i++)
	{
	//	MyConsole.MsgText[i] = MyConsole.WrapMessage(MyConsole.MsgText[i]);
	}
	LastSizeX = Canvas->SizeX;
	*/
}
void AAGP_HUD::DisplayMessages(UCanvas* C)
{
}
void AAGP_HUD::SetCrosshair(int32 C)
{
	/*
	SetHUDActor();
	//HUDCrosshair(GetHUDControl(10)).SetCrosshair(C);
	FreeHUDActor();
	*/
}
void AAGP_HUD::NextCrosshair()
{
	/*
	SetHUDActor();
	//HUDCrosshair(GetHUDControl(10)).NextCrosshair();
	FreeHUDActor();
	*/
}
void AAGP_HUD::SetHue(uint8 H)
{
	float Brightness;
	FVector HueV;
	FVector oneV;
	FVector RGBV;
	if (H < 0)
	{
		H = 0;
	}
	if (H > 255)
	{
		H = 255;
	}
	iPrevHUDColor = H;
	oneV.X = 1;
	oneV.Y = 1;
	oneV.Z = 1;
	Brightness = 1.4 / 255;
	Brightness *= 0.7 / 0.01 + FMath::Sqrt(Brightness);
	Brightness = FMath::Clamp(Brightness, 0.0f, 1.0f);
	if (H < 86)
	{
		HueV.X = 85 - H / 85;
		HueV.Y = H - 0 / 85;
		HueV.Z = 0;
	}
	else
	{
		if (H < 171)
		{
			HueV.X = 0;
			HueV.Y = 170 - H / 85;
			HueV.Z = H - 85 / 85;
		}
		else
		{
			HueV.X = H - 170 / 85;
			HueV.Y = 0;
			HueV.Z = 255 - H / 84;
		}
	}
	RGBV = HueV + 1 / 255 * oneV - HueV * Brightness;
	RGBV *= 255;
	HUDColor.R = RGBV.X;
	HUDColor.G = RGBV.Y;
	HUDColor.B = RGBV.Z;
}
void AAGP_HUD::SetAlpha(uint8 A)
{
	if (A <= 0)
	{
		A = 1;
	}
	else
	{
		if (A > 255)
		{
			A = 255;
		}
	}
	iPrevHUDAlpha = A;
	HUDColor.A = A;
}

/* =================================================================================== *
* AGP function DrawPMessage()
*	Prints an annoying message permanently on the screen. For cheaters.
*
* input: Canvas
* last modified by: cmb
* =================================================================================== */
void AAGP_HUD::DrawPMessage(UCanvas* C)
{
	/*
	int32 i;
	int32 Lines;
	FString Line;
	float XL;
	float YL;
	float YCenter;
	float XCenter;
	float midline;
	float Xsize;
	float Ysize;
	switch(PMessage)
	{
			case 0:
				return false;
			default:
				Line[Lines] = "WARNING: Your game installation is corrupted or altered. Do not ";
				Lines++;
				Line[Lines] = "continue to play on Official servers with these files.";
				Lines++;
				Line[Lines] = "Run cleaner.exe from the System directory of your game installation.";
				Lines++;
				Line[Lines] = "If you continue to receive this warning, uninstall the game";
				Lines++;
				Line[Lines] = "and reinstall from the original installer.";
				Lines++;
				Line[Lines] = "Continued use of corrupted or altered files may result in your ";
				Lines++;
				Line[Lines] = "account being disabled.";
				Lines++;
				switch(PMessage)
				{
			case 2:
				Line[Lines] = "This is your second warning.";
				Lines++;
				break;
			case 3:
				Line[Lines] = "You have been warned multiple times.";
				Lines++;
				break;
			default:
				}
				Canvas.Font = _cHUDFrame.Fonts[3];
				for (i = 0; i < Lines; i++)
				{
					Canvas.TextSize(Line[i], XL, YL);
					Xsize = FMax(Xsize, XL);
				}
				Ysize = Lines * YL;
				Canvas.TextSize("XXX", XL, YL);
				Xsize += XL;
				Ysize += YL;
				YCenter = Canvas.SizeY / 2;
				XCenter = Canvas.SizeX / 2;
				Canvas.SetPos(XCenter - Xsize / 2, YCenter - Ysize / 2);
				Canvas.SetDrawColor(255, 255, 255, 100);
				Canvas.DrawTile(tFill, Xsize, Ysize, 0, 0, tFill.USize, tFill.VSize);
				Canvas.SetDrawColor(225, 225, 225, 0);
				midline = Lines / 2;
				for (i = 0; i < Lines; i++)
				{
					Canvas.TextSize(Line[i], XL, YL);
					Canvas.SetPos(XCenter - XL / 2, YCenter + i - midline * YL);
					Canvas.DrawText(Line[i]);
				}
				return true;
				*/
}

// draw the centered messages, with a gel and box a la Army of One sytlin's
// capps
void AAGP_HUD::DrawCenteredMessages(UCanvas* C)
{
	/*
	local Font oldfont;
	local float XL;
	local float XL2;
	local float YL;
	local float YL2;
	local float boxw;
	local float boxh;
	local float yposn;
	local int fadelvl;
	local float StartX;
	local float StartY;
	if (bDisableNotificationMessages)
	{
		return;
	}
	oldfont = Canvas.Font;
	Canvas.bCenter = true;
	Canvas.Style = 6;
	Canvas.Font = _cHUDFrame.Fonts[3];
	Canvas.TextSize(_sCMessage[0], XL, YL);
	Canvas.TextSize(_sCMessage[1], XL2, YL2);
	if (FMax(XL, XL2) > Canvas.ClipX * 0.66)
	{
		Canvas.Font = _cHUDFrame.Fonts[1];
		Canvas.TextSize(_sCMessage[0], XL, YL);
		Canvas.TextSize(_sCMessage[1], XL2, YL2);
	}
	if (_fCMessageTimeout > GetWorld()->GetTimeSeconds)
	{
		fadelvl = 255;
	}
	else
	{
		fadelvl = _fCMessageTimeout + 2 - GetWorld()->GetTimeSeconds() * 255 / 2;
		if (fadelvl <= 0)
		{
			fadelvl = 1;
		}
	}
	boxw = FMax(XL, XL2) * 1.1;
	boxh = YL * 2 + YL2;
	yposn = Canvas.SizeY * 0.64;
	Canvas.SetPos(Canvas.SizeX - boxw / 2, yposn - YL / 2);
	if (fadelvl < 200)
	{
		Canvas.SetDrawColor(255, 255, 255, fadelvl / 2 + 1);
	}
	else
	{
		Canvas.SetDrawColor(255, 255, 255, 100);
	}
	Canvas.DrawTile(tFill, boxw, boxh, 0, 0, tFill.USize, tFill.VSize);
	Canvas.DrawColor = HUDColor;
	Canvas.DrawColor.A = fadelvl;
	StartX = Canvas.SizeX - boxw / 2;
	StartY = yposn - YL / 2;
	DrawArmyBox(Canvas, StartX, StartY, boxw, boxh);
	Canvas.SetDrawColor(225, 225, 225, fadelvl);
	Canvas.TextSize("test", XL, YL);
	Canvas.SetPos(0, yposn);
	Canvas.DrawText(_sCMessage[0]);
	Canvas.SetPos(0, yposn + YL);
	Canvas.DrawText(_sCMessage[1]);
	Canvas.bCenter = False;
	Canvas.Font = oldfont;
*/
}
void AAGP_HUD::DrawCenteredLongMessage(UCanvas* C)
{
	/*
	local float XL;
	local float YL;
	local float BiggestStringWidth;
	local float TotalMessageHeight;
	local float boxw;
	local float boxh;
	local float yposn;
	local float StartX;
	local float StartY;
	local float CurY;
	local Font oldfont;
	local array<String> split_msg;
	local int i;
	local int fadelvl;
	local bool fForceMultiLine;
	if (bDisableNotificationMessages)
	{
		return;
	}
	oldfont = Canvas.Font;
	Canvas.bCenter = true;
	Canvas.Style = 6;
	if (LongMessageFont != None)
	{
		Canvas.Font = LongMessageFont;
	}
	else
	{
		Canvas.Font = _cHUDFrame.Fonts[3];
	}
	if (InStr(LongMessage, "|") != -1)
	{
		fForceMultiLine = true;
	}
	else
	{
		fForceMultiLine = False;
		Canvas.TextSize(LongMessage, XL, YL);
	}
	if (fForceMultiLine || XL > Canvas.ClipX * 0.66)
	{
		Canvas.WrapStringToArray(LongMessage, split_msg, Canvas.ClipX * 0.66);
		if (split_msg.Length > 3 && LongMessageFont == None)
		{
			Canvas.Font = _cHUDFrame.Fonts[1];
			Canvas.TextSize(LongMessage, XL, YL);
			if (XL > Canvas.ClipX * 0.66)
			{
				split_msg.Length = 0;
				Canvas.WrapStringToArray(LongMessage, split_msg, Canvas.ClipX * 0.66);
			}
		}
	}
	else
	{
		split_msg.Length = 1;
		split_msg[0] = LongMessage;
	}
	BiggestStringWidth = 0;
	TotalMessageHeight = 0;
	for (i = 0; i < split_msg.Length; i++)
	{
		Canvas.TextSize(split_msg[i], XL, YL);
		if (XL > BiggestStringWidth)
		{
			BiggestStringWidth = XL;
		}
		TotalMessageHeight += YL;
	}
	if (LongMessageTimeout > GetWorld()->GetTimeSeconds)
	{
		fadelvl = 255;
	}
	else
	{
		fadelvl = LongMessageTimeout + 2 - GetWorld()->GetTimeSeconds() * 255 / 2;
		if (fadelvl <= 0)
		{
			fadelvl = 1;
		}
	}
	boxw = BiggestStringWidth * 1.1;
	boxh = TotalMessageHeight + YL;
	yposn = Canvas.SizeY * 0.64;
	StartX = Canvas.SizeX - boxw / 2;
	StartY = yposn - YL / 2;
	Canvas.SetPos(StartX, StartY);
	if (fadelvl < 200)
	{
		Canvas.SetDrawColor(255, 255, 255, fadelvl / 2 + 1);
	}
	else
	{
		Canvas.SetDrawColor(255, 255, 255, 100);
	}
	Canvas.DrawTile(tFill, boxw, boxh, 0, 0, tFill.USize, tFill.VSize);
	Canvas.DrawColor = HUDColor;
	Canvas.DrawColor.A = fadelvl;
	DrawArmyBox(Canvas, StartX, StartY, boxw, boxh);
	Canvas.SetDrawColor(225, 225, 225, fadelvl);
	CurY = yposn;
	for (i = 0; i < split_msg.Length; i++)
	{
		Canvas.SetPos(0, CurY);
		Canvas.DrawText(split_msg[i]);
		Canvas.TextSize(split_msg[i], XL, YL);
		CurY += YL;
	}
	Canvas.bCenter = False;
	Canvas.Font = oldfont;
*/
}
void AAGP_HUD::DisplayCenteredMessage(float Time, FString Message, FString message2)
{
	if (bDisableNotificationMessages)
	{
		return;
	}
	if (PMessage == 0)
	{
		_sCMessage[0] = Message;
		_sCMessage[1] = message2;
		_fCMessageTimeout = (GetWorld()->GetTimeSeconds()) + Time;
	}
}

void AAGP_HUD::DisplayCenteredMessageLong(float Time, FString in_message)
{
	if (bDisableNotificationMessages)
	{
		return;
	}
	if (PMessage == 0)
	{
		LongMessage = in_message;
		LongMessageTimeout = GetWorld()->GetTimeSeconds() + Time;
//		LongMessageFont = F;
	}
}

void AAGP_HUD::DrawArmyBox(UCanvas* C, float StartX, float StartY, float boxw, float boxh)
{
	
	bool bSmooth;
	if (boxw >= 0 && boxh >= 0)
	{
		bSmooth = Canvas->bNoSmooth;
		Canvas->bNoSmooth= true;
	/*
		Canvas->SetPos(StartX, StartY);
		Canvas->DrawTile(tArmyBox, 16, 16, 0, 0, 16, 16);
		Canvas->SetPos(StartX + 16, StartY);
		Canvas->DrawTile(tArmyBox, boxw - 32, 16, 16, 0, 16, 16);
		Canvas->SetPos(StartX + boxw - 16, StartY);
		Canvas->DrawTile(tArmyBox, 16, 16, 32, 0, 16, 16);
		Canvas->SetPos(StartX, StartY + 16);
		Canvas->DrawTile(tArmyBox, 16, boxh - 32, 0, 16, 16, 16);
		Canvas->SetPos(StartX + 16, StartY + 16);
		Canvas->DrawTile(tArmyBox, boxw - 32, boxh - 32, 16, 16, 16, 16);
		Canvas->SetPos(StartX + boxw - 16, StartY + 16);
		Canvas->DrawTile(tArmyBox, 16, boxh - 32, 32, 16, 16, 16);
		Canvas->SetPos(StartX, StartY + boxh - 16);
		Canvas->DrawTile(tArmyBox, 16, 16, 0, 32, 16, 16);
		Canvas->SetPos(StartX + 16, StartY + boxh - 16);
		Canvas->DrawTile(tArmyBox, boxw - 32, 16, 16, 32, 16, 16);
		Canvas->SetPos(StartX + boxw - 16, StartY + boxh - 16);
		Canvas->DrawTile(tArmyBox, 16, 16, 32, 32, 16, 16);
	*/
		Canvas->bNoSmooth = bSmooth;
	}
	
}
void AAGP_HUD::DrawArmyLine(UCanvas* C, float StartX, float StartY, float boxw)
{
	
	bool bSmooth;
	if (boxw >= 0)
	{
		bSmooth = Canvas->bNoSmooth;
		Canvas->bNoSmooth = true;
		//Canvas->SetPos(StartX, StartY);
		//Canvas->DrawTile(tArmyBox, boxw, 16, 16, 0, 16, 16);
		Canvas->bNoSmooth = bSmooth;
	}
	
}
void AAGP_HUD::ToggleClassSelect()
{
	/*
	PlayerOwner.ClientCloseMenu(true);
	if (gmFrame == NULL || bShowMainMenu)
	{
		return;
	}
	if (bShowGameMenu && gmFrame.GetActiveScreen().GetID() == 3)
	{
		CloseGameMenu();
		return;
	}
	gmFrame.RefreshClassSelect();
	gmFrame.SetActiveScreen(3);
	CloseAllMenus();
	OpenGameMenu();
	*/
}
void AAGP_HUD::ToggleTeamSelect()
{
	/*
	PlayerOwner.ClientCloseMenu(true);
	if (gmFrame == None || bShowMainMenu)
	{
		return;
	}
	if (bShowGameMenu && gmFrame.GetActiveScreen().GetID() == 1)
	{
		CloseGameMenu();
		return;
	}
	gmFrame.RefreshClassSelect();
	gmFrame.SetActiveScreen(1);
	CloseAllMenus();
	OpenGameMenu();
	*/
}
void AAGP_HUD::ToggleServerAdmin()
{
	/*
	PlayerOwner.ClientCloseMenu(true);
	if (gmFrame == None || bShowMainMenu)
	{
		return;
	}
	if (bShowGameMenu && gmFrame.GetActiveScreen().GetID() == 7)
	{
		CloseGameMenu();
		return;
	}
	gmFrame.SetActiveScreen(7);
	CloseAllMenus();
	OpenGameMenu();
	_bUIConsole = true;
	*/
}
void AAGP_HUD::OpenTeamSelect()
{
	/*
	PlayerOwner.ClientCloseMenu(True);
	if (gmFrame != None)
	{
		if (bShowMainMenu)
		{
			CloseMainMenu();
		}
		gmFrame.SetActiveScreen(1);
		OpenGameMenu();
	}
	*/
}
void AAGP_HUD::OpenClassSelect()
{
	/*
	PlayerOwner.ClientCloseMenu(True);
	if (gmFrame != None)
	{
		gmFrame.RefreshClassSelect();
		gmFrame.SetActiveScreen(3);
		OpenGameMenu();
	}
	*/
}
void AAGP_HUD::ToggleLogin()
{
	/*
	if (gmFrame != None)
	{
		if (bShowGameMenu)
		{
			CloseGameMenu();
		}
		else
		{
			gmFrame.SetActiveScreen(4);
			CloseAllMenus();
			gmFrame.RefreshLoginScreen();
			OpenGameMenu();
		}
	}
	*/
}
void AAGP_HUD::SetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
	/*
	if (gmFrame != None)
	{
		if (bShowGameMenu)
		{
			gmFrame.SetLoginStatus(iStatus, sStatus, sNavMsg);
		}
	}
	if (mmFrame != None)
	{
		if (bShowMainMenu)
		{
			mmFrame.SetLoginStatus(iStatus, sStatus, sNavMsg);
		}
	}
	OnSetLoginStatus(iStatus, sStatus, sNavMsg);
	*/
}
void AAGP_HUD::OnSetLoginStatus(int32 iStatus, FString sStatus, FString sNavMsg)
{
}
void AAGP_HUD::OpenMissionSuccess(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene, bool bCheater)
{
	/*
	if (gmFrame != NULL)
	{
		gmFrame.SetActiveScreen(5);
		CloseAllMenus();
		gmFrame.SetMissionSuccessScreen(Texture, Text, text2, USize, VSize, RenderStyle, replayscene, bCheater);
		gmFrame.RefreshLoginScreen();
		OpenGameMenu();
	}
	*/
}
void AAGP_HUD::OpenMissionFailure(FString Texture, FString Text, FString text2, int32 USize, int32 VSize, int32 RenderStyle, FName replayscene)
{
	/*
	if (gmFrame != None)
	{
		gmFrame.SetActiveScreen(6);
		CloseAllMenus();
		gmFrame.SetMissionFailureScreen(Texture, Text, text2, USize, VSize, RenderStyle, replayscene);
		gmFrame.RefreshLoginScreen();
		OpenGameMenu();
	}
	*/
}
void AAGP_HUD::OpenLandNavScore(FString text1, FString text2, FString text3, FString text4, FString text5, FString text6, FString text7, FString text8, bool bCheater)
{
	/*
	if (gmFrame != None)
	{
		gmFrame.SetActiveScreen(8);
		CloseAllMenus();
		gmFrame.SetLandNavScoreScreen(text1, text2, text3, text4, text5, text6, text7, text8, bCheater);
		gmFrame.RefreshLoginScreen();
		OpenGameMenu();
	}
	*/
}
void AAGP_HUD::RefreshTourMissionDisplays()
{
	/*
	if (mmFrame != NULL)
	{
		mmFrame.RefreshTourMissionDisplays();
	}
	*/
}
void AAGP_HUD::GameSpyTest()
{
}
int32 AAGP_HUD::GetServerBrowserAsInt()
{
	if (ServerBrowser != "gamespy" || LanServerBrowser)
	{
		return 1;
	}
	else
	{
		if (ServerBrowser != "AA Browser")
		{
			return 3;
		}
		else
		{
			return 3;
		}
	}
}
void AAGP_HUD::GetCurrentServerBrowser(bool IsLAN)
{
		/*
	local int iBrowser;
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1 || IsLAN)
	{
		if (BrowserGSPY == None)
		{
			BrowserGSPY = Spawn(Class'GameSpyServerList');
			BrowserGSPY.SetOwner(Self);
		}
		return BrowserGSPY;
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == None)
			{
				BrowserSCI = Spawn(Class'ServerBrowserSCI');
				BrowserSCI.SetOwner(Self);
			}
			return BrowserSCI;
		}
		else
		{
			if (iBrowser == 3)
			{
				if (BrowserDBMBS == None)
				{
					BrowserDBMBS = Spawn(Class'ServerBrowserDBMBS', Self);
				}
				return BrowserDBMBS;
			}
		}
	}
	return None;
	*/
}
void AAGP_HUD::ServerBrowserUpdateList()
{
	/*
	local int iBrowser;
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == None)
		{
			BrowserGSPY = Spawn(Class'GameSpyServerList');
			BrowserGSPY.SetOwner(Self);
		}
		BrowserGSPY.UpdateServerList();
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == None)
			{
				BrowserSCI = Spawn(Class'ServerBrowserSCI');
				BrowserSCI.SetOwner(Self);
			}
			BrowserSCI.UpdateServerList();
		}
		else
		{
			if (iBrowser == 3)
			{
				if (BrowserDBMBS == None)
				{
					BrowserDBMBS = Spawn(Class'ServerBrowserDBMBS', Self);
				}
				BrowserDBMBS.UpdateServerList();
			}
		}
	}
	*/
}
void AAGP_HUD::ServerBrowserRefreshList()
{
	/*
	local int iBrowser;
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == None)
		{
			BrowserGSPY = Spawn(Class'GameSpyServerList');
			BrowserGSPY.SetOwner(Self);
		}
		BrowserGSPY.RefreshServerList();
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == None)
			{
				BrowserSCI = Spawn(Class'ServerBrowserSCI');
				BrowserSCI.SetOwner(Self);
			}
			BrowserSCI.RefreshServerList();
		}
		else
		{
			if (iBrowser == 3)
			{
				if (BrowserDBMBS == None)
				{
					BrowserDBMBS = Spawn(Class'ServerBrowserDBMBS', Self);
				}
				BrowserDBMBS.RefreshServerList();
			}
		}
	}
	*/
}
void AAGP_HUD::ConnectToGameSpyServer(int32 Index, FString sPassword, bool bSpectatorOnly)
{
	/*
	local FGameSpyServerItem Item;
	local string sAddress;
	local string sVersion;
	local IpDrv.ServerBrowserBase sbBase;
	local int iBrowser;
	local string sURL;
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == None)
		{
			return;
		}
		else
		{
			sbBase = BrowserGSPY;
		}
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == None)
			{
				return;
			}
			else
			{
				sbBase = BrowserSCI;
			}
		}
	}
	if (sbBase == None)
	{
		return;
	}
	sbBase.GetSpecificServer(Index, Item);
	if (Item.bValid == 0)
	{
		return;
	}
	sAddress = sbBase.IpAddrToString(Item.IP, Item.Port);
	sVersion = GetVersionAGPMajor() $ "." $ GetVersionAGPMinor() $ "." $ GetVersionAGPTiny() $ "." $ GetVersionAGPSubTiny();
	if (Item.GameVer != sVersion)
	{
		return;
	}
	if (GetMilesOnly() && Item.bMiles == 0)
	{
		mmFrame.MessageBox("MILES Only", 0, "", "OK");
		return;
	}
	if (Item.bPassword == 1 && sPassword == "")
	{
		mmFrame.MessageBox("Enter Password", 0, "", "OK");
		return;
	}
	sURL = sAddress;
	if (sPassword != "")
	{
		sURL $ = "?password=" $ sPassword;
	}
	if (bSpectatorOnly)
	{
		sURL $ = "?SpectatorOnly=1";
	}
	PlayerOwner.ConsoleCommand("disconnect");
	CloseMainMenu();
	PlayerOwner.ConsoleCommand("start " $ sURL);
	*/
}
void AAGP_HUD::ConnectToServer(int32 Index, FString sPassword, bool bSpectatorOnly)
{
	/*
	local FGameSpyServerItem Item;
	local string sAddress;
	local string sVersion;
	local IpDrv.ServerBrowserBase sbBase;
	local int iBrowser;
	local string sURL;
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == None)
		{
			return;
		}
		else
		{
			sbBase = BrowserGSPY;
		}
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == None)
			{
				return;
			}
			else
			{
				sbBase = BrowserSCI;
			}
		}
	}
	if (sbBase == None)
	{
		return;
	}
	sbBase.GetSpecificServer(Index, Item);
	if (Item.bValid == 0)
	{
		return;
	}
	sAddress = sbBase.IpAddrToString(Item.IP, Item.Port);
	sVersion = GetVersionAGPMajor() $ "." $ GetVersionAGPMinor() $ "." $ GetVersionAGPTiny() $ "." $ GetVersionAGPSubTiny();
	if (Item.GameVer != sVersion)
	{
		return;
	}
	if (GetMilesOnly() && Item.bMiles == 0)
	{
		mmFrame.MessageBox("MILES Only", 0, "", "OK");
		return;
	}
	if (Item.bPassword == 1 && sPassword == "")
	{
		mmFrame.MessageBox("Enter Password", 0, "", "OK");
		return;
	}
	sURL = sAddress;
	if (sPassword != "")
	{
		sURL $ = "?password=" $ sPassword;
	}
	if (bSpectatorOnly)
	{
		sURL $ = "?SpectatorOnly=1";
	}
	PlayerOwner.ConsoleCommand("disconnect");
	CloseMainMenu();
	PlayerOwner.ConsoleCommand("start " $ sURL);
	*/
}
void AAGP_HUD::SortServers(FString sField, bool bAscending, EGameSpyCompareMode eType)
{	
	/*
	local int iBrowser;
	local IpDrv.ServerBrowserBase sbBase;
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == None)
		{
			return;
		}
		else
		{
			sbBase = BrowserGSPY;
		}
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == None)
			{
				return;
			}
			else
			{
				sbBase = BrowserSCI;
			}
		}
	}
	if (sbBase == None)
	{
		return;
	}
	if (sbBase.GetNumServers() == 0)
	{
		return;
	}
	sbBase.SortServers(sField, bAscending, eType);
	*/
}
void AAGP_HUD::RefreshSelectedServer(int32 Index)
{
		/*
	local int iBrowser;
	local IpDrv.ServerBrowserBase sbBase;
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == None)
		{
			return;
		}
		else
		{
			sbBase = BrowserGSPY;
		}
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == None)
			{
				return;
			}
			else
			{
				sbBase = BrowserSCI;
			}
		}
	}
	if (sbBase == None)
	{
		return;
	}
	if (sbBase.GetNumServers() == 0)
	{
		return;
	}
	sbBase.RefreshSpecificServer(Index);
	*/
}
void AAGP_HUD::SetServerBrowserFilter(FString sFilter)
{
	/*
	local int iBrowser;
	iBrowser = GetServerBrowserAsInt();
	if (iBrowser == 1)
	{
		if (BrowserGSPY == None)
		{
			BrowserGSPY = Spawn(Class'GameSpyServerList');
			BrowserGSPY.SetOwner(Self);
		}
		BrowserGSPY.SetFilter(sFilter);
	}
	else
	{
		if (iBrowser == 2)
		{
			if (BrowserSCI == None)
			{
				BrowserSCI = Spawn(Class'ServerBrowserSCI');
				BrowserSCI.SetOwner(Self);
			}
			BrowserSCI.SetFilter(sFilter);
		}
		else
		{
			if (iBrowser == 3)
			{
				if (BrowserDBMBS == None)
				{
					BrowserDBMBS = Spawn(Class'ServerBrowserDBMBS', Self);
				}
				BrowserDBMBS.SetFilter(sFilter);
			}
		}
	}
	*/
}
void AAGP_HUD::QueryServerListReply(int32 Index, FString Section, FString Setting, FString Value, int32 Type)
{
	/*
	if (gmFrame != None)
	{
		gmFrame.QueryServerListReply(Index, Section, Setting, Value, Type);
	}
	*/
}
void AAGP_HUD::SetServerSettingReply(int32 Index, FString Value)
{
	/*
	if (gmFrame != None)
	{
		gmFrame.SetServerSettingReply(Index, Value);
	}
	*/
}
bool AAGP_HUD::GetAutoSort()
{
	bool breturn;
	if (PlayerOwner != nullptr)
	{
		breturn = Cast<AHumanController>(PlayerOwner)->bAutoSortServerList;
	}
	else
	{
		breturn = false;
	}
	return breturn;
}
void AAGP_HUD::SetHUDColor(FColor NewColor)
{
	
	cPrevHUDColor = HUDColor;
	HUDColor.R = NewColor.R;
	HUDColor.G = NewColor.G;
	HUDColor.B = NewColor.B;
}
void AAGP_HUD::ShowCoords()
{
	/*
	Log("Player Group: " $ PlayerOwner.PlayerReplicationInfo._Group $ " Authorized server: " $ Cast<AAA2_WorldSettings>(GetWorldSettings())->IsAuthorizedServer());
	if (PlayerOwner.PlayerReplicationInfo._Group != 1 && PlayerOwner.PlayerReplicationInfo._Group != 20 && PlayerOwner.PlayerReplicationInfo._Group != 4 && HumanController(PlayerOwner).bServerRequiresAuthorization)
	{
		HumanController(PlayerOwner).ClientMessage("Command not supported");
		return;
	}
	bShowCoords = !bShowCoords;
	if (bShowCoords)
	{
		Log("* ShowCoords: Location: " $ PlayerOwner.Pawn.Location $ " Rotation: " $ PlayerOwner.Pawn.Rotation);
	}
	*/
}
void AAGP_HUD::ToggleBRoll()
{
	/*
	bBRoll = !bBRoll;
	AGP_Pawn(HumanController(PlayerOwner).Pawn).GetOpticsDevice().NotifyBRoll(bBRoll);
	*/
}
void AAGP_HUD::DisplayVoiceGain(UCanvas* C)
{
	/*
	local Texture Tex;
	local float VoiceGain;
	local float PosY;
	local float BlockSize;
	local float XL;
	local float YL;
	local int i;
	local string ActiveName;
	BlockSize = 8192 / C.ClipX * HudScale;
	Tex = Texture'WhiteSquareTexture';
	PosY = C.ClipY * 0.375;
	VoiceGain = 1 - 3 * Min(GetWorld()->GetTimeSeconds() - LastVoiceGainTime, 0.3333) * LastVoiceGain;
	for (i = 0; i < 10; i++)
	{
		if (VoiceGain > 0.1 * i)
		{
			C.SetPos(0.5 * BlockSize, PosY);
			C.SetDrawColor(28.299999 * i, 255 - 28.299999 * i, 0, 255);
			C.DrawTile(Tex, BlockSize, BlockSize, 0, 0, Tex.USize, Tex.VSize);
			PosY -= 1.2 * BlockSize;
		}
	}
	if (PlayerOwner != None && PlayerOwner.ActiveRoom != None)
	{
		ActiveName = PlayerOwner.ActiveRoom.GetTitle();
	}
	if (ActiveName != "")
	{
		ActiveName = "(" @ ActiveName @ ")";
		C.Font = GetFontSizeIndex(C, -2);
		C.StrLen(ActiveName, XL, YL);
		if (XL > 0.125 * C.ClipY)
		{
			C.Font = GetFontSizeIndex(C, -4);
			C.StrLen(ActiveName, XL, YL);
		}
		C.SetPos(BlockSize * 2, C.ClipY * 0.375 + BlockSize - YL);
		C.DrawColor = C.MakeColor(160, 160, 160);
		if (PlayerOwner != None && PlayerOwner.PlayerReplicationInfo != None)
		{
			if (PlayerOwner.PlayerReplicationInfo.Team != None)
			{
				if (PlayerOwner.PlayerReplicationInfo.Team.TeamIndex == 0)
				{
					C.DrawColor = RedColor;
				}
				else
				{
					C.DrawColor = TurqColor;
				}
			}
		}
		C.DrawText(ActiveName);
	}
	*/
}
//void AAGP_HUD::ShowDebug()
//{
//}





void AAGP_HUD::BuildMOTD()
{
	/*
	int32 i;
	int32 C;
	int32 p;
	FString S;
	FString t;

	if (bBuiltMOTD || PlayerOwner == NULL || PlayerOwner.GameReplicationInfo == None)
	{
		return;
	}
	bBuiltMOTD = true;
	PlayerOwner.SetProgressTime(6);
	C = 0;
	t[0] = PlayerOwner.GameReplicationInfo.MOTDLine1;
	t[1] = PlayerOwner.GameReplicationInfo.MOTDLine2;
	t[2] = PlayerOwner.GameReplicationInfo.MOTDLine3;
	t[3] = PlayerOwner.GameReplicationInfo.MOTDLine4;
	Log("MOTD1: " $ PlayerOwner.GameReplicationInfo.MOTDLine1);
	Log("MOTD2: " $ PlayerOwner.GameReplicationInfo.MOTDLine2);
	Log("MOTD3: " $ PlayerOwner.GameReplicationInfo.MOTDLine3);
	Log("MOTD4: " $ PlayerOwner.GameReplicationInfo.MOTDLine4);
	for (i = 0; i < 4; i++)
	{
		p = InStr(t[i], "|");
		if (p >= 0)
		{
			S = Left(t[i], p);
			MOTD[C] = S;
			C++;
			if (C == 4)
			{
				return;
			}
			t[i] = Right(t[i], Len(t[i]) - p - 1);
			p = InStr(t[i], "|");
		}
		MOTD[C] = t[i];
		Log("MOTD[" $ C $ "] is: " $ MOTD[C]);
		C++;
		if (C == 4)
		{
			return;
		}
	}
*/

}
