#ifndef OPERATOR_H
#define OPERATOR_H

#include "damagepacket.h"
#include "buff.h"
#include <QDebug>

class Operator
{
private:
    int base_attack;
    float base_attack_time;
public:
    Operator(int, float);
    virtual DamagePacket skill1(const Buff &);
    virtual DamagePacket skill2(const Buff &);
    virtual DamagePacket skill3(const Buff &);
};

class Typhon : public Operator {
    static constexpr int BASE_ATTACK = 1189;
    static constexpr float BASE_ATTACK_TIME = 2.4;
public:
    Typhon();
    DamagePacket skill2(const Buff &) override;
};

#endif // OPERATOR_H
