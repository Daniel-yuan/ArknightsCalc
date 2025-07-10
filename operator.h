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

class Mlynar : public Operator {
private:
    static constexpr int BASE_ATTACK = 445;
    static constexpr float BASE_ATTACK_TIME = 1.2;
    static constexpr int SKILL3_TIME = 28;
    static constexpr float SKILL3_ATTACK_BUFF_INNER = 4.0;
    static constexpr float SKILL3_ATTACK_INDEPENDENT_BUFF = 1.8;
    static constexpr float LIB_X_ATTACK_SPEED_BUFF = 0.07;
    static constexpr float TALENT_ATTACK_BUFF = 1.23;
    static constexpr float TALENT_ATTACK_BUFF_3_ENEMY = 1.28;
public:
    Mlynar();
    DamagePacket skill3(Buff) override;
};

#endif // OPERATOR_H
