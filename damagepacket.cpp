#include "damagepacket.h"

DamagePacket::DamagePacket(int hits, int value_per_hit, float probability_per_hit, DamageType damage_type)
    : hits(hits), value_per_hit(value_per_hit), probability_per_hit(probability_per_hit), damage_type(damage_type) {}
