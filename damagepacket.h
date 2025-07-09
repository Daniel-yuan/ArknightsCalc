#ifndef DAMAGEPACKET_H
#define DAMAGEPACKET_H

enum DamageType {
    kPhysicalDamage,
    kSpellDamage,
};

class DamagePacket
{
private:
    int hits;
    float value_per_hit;
    float probability_per_hit;
    int total_time;
    DamageType damage_type;
public:
    static const DamagePacket DEFAULT_DAMAGE_PACKET;
    DamagePacket(int hits, float value_per_hit, float probability_per_hit, int total_time, DamageType);
    float get_dps();
    float get_dph();
};

#endif // DAMAGEPACKET_H
