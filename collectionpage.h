#ifndef COLLECTIONPAGE_H
#define COLLECTIONPAGE_H

#include "collection.h"
#include "collectionset.h"
#include <QWidget>

const QString COLLECTION_PATH = "/Users/yuanxiangtao/QTtest/ArknightsCalc/collection.json";

namespace Ui {
class CollectionPage;
}

class CollectionPage : public QWidget
{
    Q_OBJECT

public:
    explicit CollectionPage(std::shared_ptr<CollectionSet> collection_set);
    ~CollectionPage();

signals:
    void collection_set_changed();

private:
    Ui::CollectionPage *ui;
    void collection_init();
    std::vector<Collection> collections;
    std::shared_ptr<CollectionSet> collection_set;
};

#endif // COLLECTIONPAGE_H
