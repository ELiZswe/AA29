// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAMoviePlayerButtonClose/STY_AAMoviePlayerButtonClose.h"

USTY_AAMoviePlayerButtonClose::USTY_AAMoviePlayerButtonClose()
{
	KeyName = "MoviePlayerButtonClose";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_Mat.t_ui_movieplayer_close_button_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_highlight_Mat.t_ui_movieplayer_close_button_highlight_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_Mat.t_ui_movieplayer_close_button_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_Mat.t_ui_movieplayer_close_button_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_Mat.t_ui_movieplayer_close_button_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled
	};
}
