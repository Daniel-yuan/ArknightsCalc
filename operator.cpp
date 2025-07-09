#include "operator.h"
#include "utils.h"

Operator::Operator(int base_attack, float base_attack_time)
    : base_attack(base_attack), base_attack_time(base_attack_time) {}
DamagePacket Operator::skill1(Buff buff) {
    qWarning() << "Skill1: Not implemented\n";
    return DamagePacket::DEFAULT_DAMAGE_PACKET;
}
DamagePacket Operator::skill2(Buff buff) {
    qWarning() << "Skill2: Not implemented\n";
    return DamagePacket::DEFAULT_DAMAGE_PACKET;
}
DamagePacket Operator::skill3(Buff buff) {
    qWarning() << "Skill3: Not implemented\n";
    return DamagePacket::DEFAULT_DAMAGE_PACKET;
}

Typhon::Typhon() : Operator(Typhon::BASE_ATTACK, Typhon::BASE_ATTACK_TIME) {}
DamagePacket Typhon::skill2(Buff buff) {
    int hits = get_hits(this->base_attack_time, buff.get_attack_buff_inner(), this->SKILL2_TIME);
    float actual_attack = (1 + buff.get_attack_buff_outer()) * this->base_attack * (1 + buff.get_attack_buff_inner() + this->SKILL2_ATTACK_BUFF_INNER);
    return DamagePacket(hits, actual_attack, 1.0, this->SKILL2_TIME, DamageType::kPhysicalDamage);
}
