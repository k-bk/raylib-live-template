#include "raylib.h"
#include "logic_loader.h"

int main() {
    if (load_logic()) return 1;

    InitWindow(800, 600, "Raylib test");

    GameState state;
    logic_init(&state);

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_R)) {
            load_logic();
        }

        logic_update(&state);
        logic_draw(&state);
    }

    CloseWindow();

    if (unload_logic()) return 1;
}