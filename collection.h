#ifndef COLLECTION_H
#define COLLECTION_H

#include <QJsonObject>
#include "buff.h"

class Collection
{
private:
    QString name;
    float self_attack_buff_inner = 0;
    float self_attack_buff_outer = 0;
    float self_attack_speed_buff = 0;
    float self_physical_damage_boost_grouped = 0;
    float self_physical_damage_boost_individual = 0;
    float self_spell_damage_boost_grouped = 0;
    float self_spell_damage_boost_individual = 0;
    float self_true_damage_boost_individual = 0;

    float opponent_health_buff = 0;
    float opponent_attack_buff = 0;
    float opponent_physical_defense_buff = 0;
    float opponent_spell_defense_buff = 0;
public:
    Collection() = default;
    Collection(const QJsonObject& obj);
    Collection operator + (const Collection &rhs) const;
    QString get_name() const;
    Buff get_buff() const;
};

#endif // COLLECTION_H
