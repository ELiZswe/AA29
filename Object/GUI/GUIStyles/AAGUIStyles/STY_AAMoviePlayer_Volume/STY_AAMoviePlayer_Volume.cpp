// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAMoviePlayer_Volume/STY_AAMoviePlayer_Volume.h"

USTY_AAMoviePlayer_Volume::USTY_AAMoviePlayer_Volume()
{
	KeyName = "MoviePlayer_Volume";
	FontNames[0] = "AAFontSmallHeader";
	FontNames[1] = "AAFontSmallHeader";
	FontNames[2] = "AAFontSmallHeader";
	FontNames[3] = "AAFontSmallHeader";
	FontNames[4] = "AAFontSmallHeader";
	FontColors = {
		FColor(255, 255, 255, 255),
		FColor(255, 255, 255, 255),
		FColor(0, 200, 230, 255),
		FColor(0, 0, 0, 255),
		FColor(255, 255, 255, 255)
	};
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_area_Mat.t_ui_movieplayer_volume_area_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_area_Mat.t_ui_movieplayer_volume_area_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_area_Mat.t_ui_movieplayer_volume_area_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_area_Mat.t_ui_movieplayer_volume_area_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_volume_area_Mat.t_ui_movieplayer_volume_area_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled
	};
}
