#include <cstdlib>

#include "raylib.h"

#include "config.h"

#include "tiles.h"

int bigmap[600] = {37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396,
                   396, 396, 396, 396, 396, 396, 396, 396, 396, 37,
                   37, 37, 37, 37, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396, 396,
                   396, 396, 396, 396, 396, 396, 396, 396, 396, 37,
                   37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 396, 396, 396, 396, 396,
                   396, 396, 396, 396, 37, 37, 37,
                   37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 546, 546, 37, 37,
                   37, 546, 546, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 546, 546, 546, 37,
                   37, 546, 546, 546, 546, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 37, 546, 546, 546, 37,
                   37, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546,
                   546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 37,
                   37, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546,
                   546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 37,
                   37, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546,
                   546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 37,
                   37, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546,
                   546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 37,
                   520, 520, 520, 520, 520, 520, 520, 520, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 546,
                   546, 546, 546, 546, 546, 546, 546, 546, 546, 546, 37,
                   520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520,
                   520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520,
                   37, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520,
                   520, 520, 520, 520, 520, 520, 520, 520, 520, 520, 520,
                   37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
                   37, 37, 37, 37, 37, 37};


void DrawPlayer(tiles t) {
    DrawRectangle((int) (t.x - 1) * t.pixels, (int) (t.y - 1) * t.pixels, (int) t.width * t.pixels,
                  (int) t.height * t.pixels,
                  MAGENTA);
}

void DrawMap(tiles t) {
    int currentMin = 0;
    int currentMax = 30;
    for (int z = 0; z < 20; z++) {
        for (int i = currentMin; i < currentMax; i++) {
            if (bigmap[i] == 396) {
                DrawRectangle((i - currentMin) * t.pixels, z * t.pixels, t.width * t.pixels,
                              t.height * t.pixels, BLUE);
            }
        }
        currentMin += 30;
        currentMax += 30;
    }
}

bool Coll(tiles c) {
    bool collision;
    if (bigmap[c.pos] == 396) {
        collision = true;
    } else if (bigmap[c.pos] == 520) {
        collision = true;
    } else {
        collision = false;
    }
    return collision;
}


void playermove(tiles &player, tiles &tile) {
    if (IsKeyPressed(KEY_W)) {
        player.y -= 1;
        player.pos -= 30;
        if (Coll(player)) {
            player.y += 1;
            player.pos += 30;
        }
    }
    if (IsKeyPressed(KEY_A)) {
        player.x -= 1;
        player.pos -= 1;
        if (Coll(player)) {
            player.x += 1;
            player.pos += 1;
        }
    }
    if (IsKeyPressed(KEY_S)) {
        player.y += 1;
        player.pos += 30;
        if (Coll(player)) {
            player.y -= 1;
            player.pos -= 30;
        }
    }
    if (IsKeyPressed(KEY_D)) {
        player.x += 1;
        player.pos += 1;
        if (Coll(player)) {
            player.x -= 1;
            player.pos -= 1;
        }
    }
    if (player.x > 30) {
        player.x -= 1;
        player.pos -= 1;

    }
    if (player.x < 1) {
        player.x += 1;
        player.pos += 1;
    }
    if (player.y > 20) {
        player.y -= 1;
        player.pos -= 30;
    }
    if (player.y < 1) {
        player.y += 1;
        player.pos += 30;
    }
}


int main() {

    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    Texture2D map = LoadTexture("assets/graphics/test5.png");


    tiles tile;
    tile.x = 1;
    tile.y = 1;
    tile.height = 1;
    tile.width = 1;
    tile.pixels = 32;

    tiles player;
    player.x = 1;
    player.y = 1;
    player.height = 1;
    player.width = 1;
    player.pixels = 32;
    player.pos = 0;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        playermove(player, tile);

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // ...
        // ...
        ClearBackground(WHITE);
        DrawTexture(map, 0, 0, WHITE);
        DrawMap(tile);
        DrawPlayer(player);

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...
    UnloadTexture(map);

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
