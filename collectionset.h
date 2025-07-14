#ifndef COLLECTIONSET_H
#define COLLECTIONSET_H

#include "collection.h"
#include <set>

class CollectionSet
{
private:
    std::vector<Collection> vec;
    Collection sum;
    void calc_sum();
public:
    void insert(const Collection &it);
    void erase(const Collection &it);
    Collection get_sum();
    CollectionSet();
};

#endif // COLLECTIONSET_H
