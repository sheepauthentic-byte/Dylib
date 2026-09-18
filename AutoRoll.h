#ifndef AUTOROLL_H
#define AUTOROLL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    const char *champion_name;
    int copies_needed;
    int minimum_gold;
    int roll_cost;
    int enabled;
} ARConfig;

void ar_configure(const ARConfig *config);
void ar_set_enabled(int enabled);
int ar_should_roll(void);
void ar_update(int current_gold, int copies_found);
const char *ar_target_name(void);

#ifdef __cplusplus
}
#endif

#endif