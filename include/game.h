#ifndef _GAME_H
#define _GAME_H

#include <gb/gb.h>
#include <stdio.h>

#include "structs.h"
#include "input.h"
#include "physics.h"
#include "player.h"
#include "utils.h"
#include "gfx.h"
#include "levels.h"
#include "key_obj.h"

// Game state
enum GameState
{
    GS_TITLE_LOAD,
    GS_TITLE,
    GS_INGAME,
    GS_PAUSE
};

enum GameFlags
{
    GF_NONE = 0x00,
    GF_DOOR_OPEN = 0x01,
};

struct Game
{
    uint16_t gameState;
    uint16_t gameFrame;
    uint8_t currentLevel;
    level_t level_data;
    uint16_t mapPixelW;
    uint16_t mapPixelH;
    uint8_t mapX;
    uint8_t mapY;
    uint8_t oldMapX;
    uint8_t oldMapY;
    uint8_t flags;
};

extern struct Game game;

void init_game(void);
void game_loop(void);
void start_level(uint8_t level);

#endif
