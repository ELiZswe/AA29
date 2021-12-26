// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAMoviePlayerButtonStop/STY_AAMoviePlayerButtonStop.h"

USTY_AAMoviePlayerButtonStop::USTY_AAMoviePlayerButtonStop()
{
	KeyName = "MoviePlayerButtonStop";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_stop_button_up_Mat.t_ui_movieplayer_stop_button_up_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_stop_button_highlight_Mat.t_ui_movieplayer_stop_button_highlight_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_stop_button_up_Mat.t_ui_movieplayer_stop_button_up_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_stop_button_down_Mat.t_ui_movieplayer_stop_button_down_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_stop_button_down_Mat.t_ui_movieplayer_stop_button_down_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled
	};
}
