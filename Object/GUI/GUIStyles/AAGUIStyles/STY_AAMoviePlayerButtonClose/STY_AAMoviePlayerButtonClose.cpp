// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAMoviePlayerButtonClose/STY_AAMoviePlayerButtonClose.h"

USTY_AAMoviePlayerButtonClose::USTY_AAMoviePlayerButtonClose()
{
	KeyName = "MoviePlayerButtonClose";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_Mat.t_ui_movieplayer_close_button_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_highlight_Mat.t_ui_movieplayer_close_button_highlight_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_Mat.t_ui_movieplayer_close_button_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_Mat.t_ui_movieplayer_close_button_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/MoviePlayer/t_ui_movieplayer_close_button_Mat.t_ui_movieplayer_close_button_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_Scaled;
	ImgStyle[1] = EImgStyle::ISTY_Scaled;
	ImgStyle[2] = EImgStyle::ISTY_Scaled;
	ImgStyle[3] = EImgStyle::ISTY_Scaled;
	ImgStyle[4] = EImgStyle::ISTY_Scaled;
}
