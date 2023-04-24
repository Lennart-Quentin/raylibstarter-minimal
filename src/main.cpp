#include <cstdlib>

#include "raylib.h"

#include "config.h"

struct tile {
    float x, y;
    float height = 1.0;
    float width = 1.0;
    int pixels = 32;

    Rectangle GetRect() {
        return Rectangle{(x - 1) * pixels, (y - 1) * pixels, width * pixels, height * pixels};
    };

    void Draw() {
        DrawRectangle((int) (x - 1) * pixels, (int) (y - 1) * pixels, (int) width * pixels, (int) height * pixels,
                      MAGENTA);
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
    player.x = 1;
    player.y = 1;
    player.height = 1;
    player.width = 1;

    tile wall;
    wall.x = 5;
    wall.y = 2;
    wall.height = 2;
    wall.width = 25;


    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        if (IsKeyPressed(KEY_W)) {
                player.y -= 1;
            if (CheckCollisionRecs(player.GetRect(), wall.GetRect())) {
                player.y += 1;
            }
        }
        if (IsKeyPressed(KEY_A)) {
            player.x -= 1;
            if (CheckCollisionRecs(player.GetRect(), wall.GetRect())) {
                player.x += 1;
            }
        }
        if (IsKeyPressed(KEY_S)) {
            player.y += 1;
            if (CheckCollisionRecs(player.GetRect(), wall.GetRect())) {
                player.y -= 1;
            }
        }
        if (IsKeyPressed(KEY_D)) {
            player.x += 1;
            if (CheckCollisionRecs(player.GetRect(), wall.GetRect())) {
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
        wall.Draw();
        player.Draw();
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
