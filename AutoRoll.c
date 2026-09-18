#include "AutoRoll.h"

static ARConfig cfg = {0};
static int shouldRoll = 0;

void ar_configure(const ARConfig *config) {
    if (config) cfg = *config;
}

void ar_set_enabled(int enabled) {
    cfg.enabled = enabled ? 1 : 0;
}

void ar_update(int current_gold, int copies_found) {
    int complete =
        cfg.copies_needed > 0 &&
        copies_found >= cfg.copies_needed;

    shouldRoll =
        cfg.enabled &&
        !complete &&
        current_gold - cfg.roll_cost >= cfg.minimum_gold;
}

int ar_should_roll(void) {
    return shouldRoll;
}

const char *ar_target_name(void) {
    return cfg.champion_name ? cfg.champion_name : "";
}