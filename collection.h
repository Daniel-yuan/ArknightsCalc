#ifndef COLLECTION_H
#define COLLECTION_H

#include <QJsonObject>

class Collection
{
private:
    QString name;
    float self_attack_buff_inner;
    float self_attack_buff_outer;
    float self_attack_speed_buff;
    float self_physical_damage_boost_grouped;
    float self_physical_damage_boost_individual;
    float self_spell_damage_boost_grouped;
    float self_spell_damage_boost_individual;
    float self_true_damage_boost_individual;

    float opponent_health_buff;
    float opponent_attack_buff;
    float opponent_physical_defense_buff;
    float opponent_spell_defense_buff;
public:
    Collection() = default;
    Collection(const QJsonObject& obj);
    Collection operator + (const Collection &rhs) const;
};

#endif // COLLECTION_H
