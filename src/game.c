#include "../include/game.h"

struct Game game = {0};

void init_game()
{
    game.gameState = GS_TITLE_LOAD;
    game.gameFrame = 0;
    game.tileMap = test_tiles;
    game.tileMapW = test_tile_width;
    game.tileMapH = test_tile_height;
    game.mapX = 0;
    game.mapY = 0;
    game.oldMapX = 255;
    game.oldMapY = 255;
}

void game_loop()
{
    // Loop forever
    while(TRUE)
    {
        // Get new inputs
        old_joy = joy;
        joy = joypad();

        switch(game.gameState)
        {
            case GS_TITLE_LOAD:
                game.gameState = GS_TITLE;

            case GS_TITLE:
                process_title_input();

                break;
            case GS_INGAME:
                process_game_input();
                apply_physics();
                update_game_sprites();

                break;
            case GS_PAUSE:
                process_pause_input();

                break;
            default:
                break;
        }

        game.gameFrame += 1;

        // Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();

        // update camera after vblank
        update_camera();
    }
}
