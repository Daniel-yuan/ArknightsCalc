#ifndef BUFF_H
#define BUFF_H

class Buff
{
private:
    float attack_buff_inner;
    float attack_buff_outer;
    float attack_speed_buff;
public:
    static const Buff DEFAULT_BUFF;
    Buff(float, float, float);
    Buff operator + (const Buff &rhs);
    float get_attack_buff_inner();
    float get_attack_buff_outer();
    float get_attack_speed_buff();
};

#endif // BUFF_H
