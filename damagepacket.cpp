#include "damagepacket.h"

DamagePacket::DamagePacket(int hits, float value_per_hit, float probability_per_hit, int total_time, DamageType damage_type)
    : hits(hits), value_per_hit(value_per_hit), probability_per_hit(probability_per_hit), total_time(total_time), damage_type(damage_type) {}
const DamagePacket DamagePacket::DEFAULT_DAMAGE_PACKET(0, 0, 0, 0, DamageType::kPhysicalDamage);
float DamagePacket::get_dps() {
    return this->hits * this->value_per_hit / this->total_time;
}

float DamagePacket::get_dph() {
    return this->value_per_hit;
}

int DamagePacket::get_hits() {
    return this->hits;
}
