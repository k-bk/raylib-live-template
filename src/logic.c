#include "raylib.h"
#include "logic.h"
#include "player.h"

float blink_timer = 0;
bool blink = false;

void logic_init(GameState* state) {
    state->points = 777;
}

void logic_update(GameState* state) {
    blink_timer -= GetFrameTime();
    if (blink_timer <= 0) {
        blink = !blink;
        blink_timer = 1.0;
    }

    if (IsKeyPressed(KEY_ENTER)) {
        state->points += 100;
    }
}

void logic_draw(GameState* state) {
    BeginDrawing();
    ClearBackground(BLACK);
    if (blink) {
        DrawRectangle(10, 10, 10, 10, WHITE);
    }
    DrawText(TextFormat("Points %d health: %d", state->points, get_health()), 100, 100, 20, WHITE);
    EndDrawing();
}