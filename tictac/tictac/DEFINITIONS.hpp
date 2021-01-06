#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1136

#define SPLASH_STATE_SHOW_TIME 3
//sciezki do grafik
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Main Menu Background.png"
#define PAUSE_BACKGROUND_FILEPATH "Main Menu Background.png"

#define MAIN_MENU_TITLE_PATH "Game Title.png"
#define MAIN_MENU_PLAY_BUTTON "Play Button.png"
#define MAIN_MENU_PLAY_BUTTON_OUTER "Play Button Outer.png"

#define GAME_BACKGROUND_FILEPATH "Main Menu Background.png"
#define PAUSE_BUTTON "Pause Button.png"
#define RESUME_BUTTON "Resume Button.png"
#define HOME_BUTTON "Home Button.png"
#define RETRY_BUTTON "Retry Button.png"

#define X_PIECE_FILEPATH "X.png"
#define O_PIECE_FILEPATH "O.png"
#define X_WINNING_PIECE_FILEPATH "X Win.png"
#define O_WINNING_PIECE_FILEPATH "O Win.png"

#define GRID_SPRITE_FILEPATH "Grid.png"

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define TIME_BEFORE_SHOWING_GAME_OVER 1