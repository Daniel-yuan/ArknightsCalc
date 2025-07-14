#ifndef DAMAGEPAGE_H
#define DAMAGEPAGE_H

#include <QWidget>
#include "collectionset.h"

namespace Ui {
class DamagePage;
}

class DamagePage : public QWidget
{
    Q_OBJECT

public:
    explicit DamagePage(std::shared_ptr<CollectionSet> collection_set);
    ~DamagePage();

public slots:
    void refresh_text_browser();

private:
    std::shared_ptr<CollectionSet> collection_set;
    Ui::DamagePage *ui;
};

#endif // DAMAGEPAGE_H
