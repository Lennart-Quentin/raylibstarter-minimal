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

int currentMin = 0;
int currentMax = 30;

Rectangle GetRect(tiles t) {
    return Rectangle{(t.x - 1) * t.pixels, (t.y - 1) * t.pixels, t.width * t.pixels, t.height * t.pixels};
}

void Draw(tiles t) {
    DrawRectangle((int) (t.x - 1) * t.pixels, (int) (t.y - 1) * t.pixels, (int) t.width * t.pixels,
                  (int) t.height * t.pixels,
                  MAGENTA);
}

void DrawMap(tiles t) {
    for(int z = 0; z < 20; z++)
    {
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
    currentMin = 0;
    currentMax = 30;


    tiles player;
    player.x = 1;
    player.y = 1;
    player.height = 1;
    player.width = 1;
    player.pixels = 32;

    tiles wall;
    wall.x = 5;
    wall.y = 2;
    wall.height = 1;
    wall.width = 1;
    wall.pixels = 32;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...

        currentMin = 0;
        currentMax = 30;

        if (IsKeyPressed(KEY_W)) {
            player.y -= 1;
            if (CheckCollisionRecs(GetRect(player), GetRect(wall))) {
                player.y += 1;
            }
        }
        if (IsKeyPressed(KEY_A)) {
            player.x -= 1;
            if (CheckCollisionRecs(GetRect(player), GetRect(wall))) {
                player.x += 1;
            }
        }
        if (IsKeyPressed(KEY_S)) {
            player.y += 1;
            if (CheckCollisionRecs(GetRect(player), GetRect(wall))) {
                player.y -= 1;
            }
        }
        if (IsKeyPressed(KEY_D)) {
            player.x += 1;
            if (CheckCollisionRecs(GetRect(player), GetRect(wall))) {
                player.x -= 1;
            }
        }
        if (player.x > 30) {
            player.x -= 1;
        }
        if (player.x < 1) {
            player.x += 1;
        }
        if (player.y > 20) {
            player.y -= 1;
        }
        if (player.y < 1) {
            player.y += 1;
        }

        BeginDrawing();
        // You can draw on the screen between BeginDrawing() and EndDrawing()
        // ...
        // ...
        ClearBackground(WHITE);
        DrawTexture(map, 0, 0, WHITE);
        //wall.Draw();
        DrawMap(wall);
        Draw(player);
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
