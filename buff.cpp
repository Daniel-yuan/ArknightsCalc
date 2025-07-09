#include "buff.h"

const Buff Buff::DEFAULT_BUFF(0.0, 0.0, 0.0);
Buff::Buff(float attack_buff_inner, float attack_buff_outer, float attack_speed_buff)
    : attack_buff_inner(attack_buff_inner), attack_buff_outer(attack_buff_outer), attack_speed_buff(attack_speed_buff) {}
Buff Buff::operator + (const Buff &rhs) {
    return Buff(
        this->attack_buff_inner + rhs.attack_buff_inner,
        this->attack_buff_outer + rhs.attack_buff_outer,
        this->attack_speed_buff + rhs.attack_speed_buff
    );
}

float Buff::get_attack_buff_inner() {
    return this->attack_buff_inner;
}
float Buff::get_attack_buff_outer() {
    return this->attack_buff_outer;
}
float Buff::get_attack_speed_buff() {
    return this->attack_speed_buff;
}
