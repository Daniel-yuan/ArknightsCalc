#include "operator.h"

Operator::Operator(int base_attack, float base_attack_time)
    : base_attack(base_attack), base_attack_time(base_attack_time) {}
DamagePacket Operator::skill1(const Buff &buff) {
    qWarning() << "Skill1: Not implemented\n";
    return DamagePacket::DEFAULT_DAMAGE_PACKET;
}
DamagePacket Operator::skill2(const Buff &buff) {
    qWarning() << "Skill2: Not implemented\n";
    return DamagePacket::DEFAULT_DAMAGE_PACKET;
}
DamagePacket Operator::skill3(const Buff &buff) {
    qWarning() << "Skill3: Not implemented\n";
    return DamagePacket::DEFAULT_DAMAGE_PACKET;
}

Typhon::Typhon() : Operator(Typhon::BASE_ATTACK, Typhon::BASE_ATTACK_TIME) {}
DamagePacket Typhon::skill2(const Buff &buff) {

}
