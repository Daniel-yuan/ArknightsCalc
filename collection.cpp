#include "collection.h"

Collection::Collection(const QJsonObject &obj) {
    name = obj.value("name").toString();

    self_attack_buff_inner = obj.value("self_attack_buff_inner").toDouble(0.0);
    self_attack_buff_outer = obj.value("self_attack_buff_outer").toDouble(0.0);
    self_attack_speed_buff = obj.value("self_attack_speed_buff").toDouble(0.0);
    self_physical_damage_boost_grouped = obj.value("self_physical_damage_boost_grouped").toDouble(0.0);
    self_physical_damage_boost_individual = obj.value("self_physical_damage_boost_individual").toDouble(0.0);
    self_spell_damage_boost_grouped = obj.value("self_spell_damage_boost_grouped").toDouble(0.0);
    self_spell_damage_boost_individual = obj.value("self_spell_damage_boost_individual").toDouble(0.0);

    opponent_attack_buff = obj.value("opponent_attack_buff").toDouble(0.0);
    opponent_physical_defense_buff = obj.value("opponent_physical_defense_buff").toDouble(0.0);
    opponent_spell_defense_buff = obj.value("opponent_spell_defense_buff").toDouble(0.0);
}

Collection Collection::operator + (const Collection &rhs) const {
    Collection result = *this;
    result.name = "SumPacket";
    result.self_attack_buff_inner += rhs.self_attack_buff_inner;
    result.self_attack_buff_outer += rhs.self_attack_buff_outer;
    result.self_attack_speed_buff += rhs.self_attack_speed_buff;
    result.self_physical_damage_boost_grouped += rhs.self_physical_damage_boost_grouped;
    result.self_physical_damage_boost_individual += rhs.self_physical_damage_boost_individual
        + result.self_physical_damage_boost_individual * rhs.self_physical_damage_boost_individual;
    result.self_spell_damage_boost_grouped += rhs.self_spell_damage_boost_grouped;
    result.self_spell_damage_boost_individual += rhs.self_spell_damage_boost_individual
        + result.self_spell_damage_boost_individual * rhs.self_spell_damage_boost_individual;
    result.self_true_damage_boost_individual += rhs.self_true_damage_boost_individual
        + result.self_true_damage_boost_individual * rhs.self_true_damage_boost_individual;

    result.opponent_health_buff += rhs.opponent_health_buff
        + result.opponent_health_buff * rhs.opponent_health_buff;
    result.opponent_attack_buff += rhs.opponent_attack_buff
        + result.opponent_attack_buff * rhs.opponent_attack_buff;
    result.opponent_physical_defense_buff += rhs.opponent_physical_defense_buff
        + result.opponent_physical_defense_buff * rhs.opponent_physical_defense_buff;
    result.opponent_spell_defense_buff += rhs.opponent_spell_defense_buff
        + result.opponent_spell_defense_buff * rhs.opponent_spell_defense_buff;
    return result;
}
