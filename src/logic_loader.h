#ifndef LOGIC_LOADER_H
#define LOGIC_LOADER_H

#include "logic.h"

#define LIBLOGIC_FILENAME "liblogic.so"

extern logic_init_t logic_init;
extern logic_update_t logic_update;
extern logic_draw_t logic_draw;

int load_logic();
int unload_logic();

#endif // LOGIC_LOADER_H