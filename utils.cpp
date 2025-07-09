#include "utils.h"

int get_hits(float attack_time, float attack_speed_buff, int total_time) {
    int total_frame = total_time * FRAME_PER_SECOND;
    float actual_attack_time = attack_time / (1 + attack_speed_buff);
    float actual_attack_frame = actual_attack_time * FRAME_PER_SECOND;
    int attack_frame_per_hit
}
