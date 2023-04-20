#include <cstdlib>

#include "raylib.h"

#include "config.h"

struct tile {
    int x, y;
    int height;
    int width;

    void Draw(){
        DrawRectangle(x,y,32,32,WHITE);
    }
};


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

    tile player;
    player.x = 0;
    player.y = 0;
    player.height = 32;
    player.width = 32;



    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        if(IsKeyPressed(KEY_W)){
            player.y -= 32;
        }
        if(IsKeyPressed(KEY_A)){
            player.x -= 32;
        }
        if(IsKeyPressed(KEY_S)){
            player.y += 32;
        }
        if(IsKeyPressed(KEY_D)){
            player.x += 32;
        }
        if(player.x > 29*32){
            player.x -= 32;
        }
        if(player.x < 0){
            player.x += 32;
        }
        if(player.y > 19*32){
            player.y -= 32;
        }
        if(player.y < 0){
            player.y += 32;
        }


        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            ClearBackground(WHITE);
            DrawTexture(map, 0, 0, WHITE);
            DrawRectangle(player.x, player.y, 32, 32, WHITE);
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
