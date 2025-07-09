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
    int value_per_hit;
    float probability_per_hit;
    DamageType damage_type;
public:
    static const DamagePacket DEFAULT_DAMAGE_PACKET;
    DamagePacket(int, int, float, DamageType);
};

#endif // DAMAGEPACKET_H
