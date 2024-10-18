#include <dlfcn.h>
#include <stdio.h>

#include "logic_loader.h"

logic_init_t logic_init;
logic_update_t logic_update;
logic_draw_t logic_draw;

static void *logic = NULL;

int load_logic() {
    if (logic != NULL) {
        if (unload_logic()) {
            return 1;
        }
    }

    logic = dlopen(LIBLOGIC_FILENAME, RTLD_NOW);
    if (logic == NULL) {
        fprintf(stderr, "ERROR loading %s: %s\n", LIBLOGIC_FILENAME, dlerror());
        return 1;
    }

    logic_init = (logic_init_t) dlsym(logic, "logic_init");
    if (logic_init == NULL) {
        fprintf(stderr, "ERROR could not load symbol logic_init: %s", dlerror());
    }

    logic_update = (logic_update_t) dlsym(logic, "logic_update");
    if (logic_update == NULL) {
        fprintf(stderr, "ERROR could not load symbol logic_update: %s", dlerror());
    }

    logic_draw = (logic_draw_t) dlsym(logic, "logic_draw");
    if (logic_draw == NULL) {
        fprintf(stderr, "ERROR could not load symbol logic_draw: %s", dlerror());
    }

    return 0;
}

int unload_logic() {
    if (dlclose(logic)) {
        fprintf(stderr, "ERROR unloading %s: %s\n", LIBLOGIC_FILENAME, dlerror());
        return 1;
    }

    return 0;
}