#include "collectionset.h"
#include <QDebug>

CollectionSet::CollectionSet() {
    vec.clear();
    sum = Collection();
}
Collection CollectionSet::get_sum() {
    return sum;
}
void CollectionSet::calc_sum() {
    this->sum = Collection();
    for (const auto &it : vec) {
        this->sum = this->sum + it;
    }
}
void CollectionSet::insert(const Collection &it) {
    vec.erase(
        std::remove_if(vec.begin(), vec.end(), [&it](const Collection &col){
            return it.get_name() == col.get_name();
        }),
        vec.end()
    );
    vec.push_back(it);
    calc_sum();
}
void CollectionSet::erase(const Collection &it) {
    vec.erase(
        std::remove_if(vec.begin(), vec.end(), [&it](const Collection &col){
            return it.get_name() == col.get_name();
        }),
        vec.end()
    );
    calc_sum();
}
