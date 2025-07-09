#ifndef OPERATOR_H
#define OPERATOR_H

#include "damagepacket.h"
#include "buff.h"
#include <QDebug>

class Operator
{
protected:
    int base_attack;
    float base_attack_time;
public:
    Operator(int, float);
    virtual DamagePacket skill1(Buff);
    virtual DamagePacket skill2(Buff);
    virtual DamagePacket skill3(Buff);
};

class Typhon : public Operator {
private:
    static constexpr int BASE_ATTACK = 1279;
    static constexpr float BASE_ATTACK_TIME = 2.4;
    static constexpr int SKILL2_TIME = 200000;
    static constexpr float SKILL2_ATTACK_BUFF_INNER = 0.5;
public:
    Typhon();
    DamagePacket skill2(Buff) override;
};

#endif // OPERATOR_H
