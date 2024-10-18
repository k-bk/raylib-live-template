#ifndef LOGIC_H
#define LOGIC_H

typedef struct {
    int points;
} GameState;

typedef void (*logic_init_t)(GameState *);
typedef void (*logic_update_t)(GameState *);
typedef void (*logic_draw_t)(GameState *);

#endif // LOGIC_H