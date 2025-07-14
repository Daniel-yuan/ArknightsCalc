#include "collectionpage.h"
#include "ui_collectionpage.h"
#include <QLineEdit>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>
#include <QCheckBox>

void CollectionPage::collection_init() {
    QFile file(COLLECTION_PATH);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open file!";
        qWarning() << file.errorString();
        return;
    }
    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    const QJsonArray jsonArray = doc.array();
    for (const QJsonValue &value : jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            Collection collection = Collection(obj);
            this->collections.push_back(collection);
        }
    }
}

CollectionPage::CollectionPage(std::shared_ptr<CollectionSet> collection_set)
    : QWidget(nullptr), collection_set(collection_set)
    , ui(new Ui::CollectionPage)
{
    ui->setupUi(this);

    collection_init();

    auto test = ui->gridLayout;
    int i = 0, j = 0;
    for (const Collection &it : this->collections) {
        QCheckBox *checkbox = new QCheckBox(it.get_name());
        checkbox->setMinimumHeight(200);
        connect(checkbox, &QCheckBox::checkStateChanged, this, [this, collection_set, it](int state){
            if (state == 0) {
                collection_set->erase(it);
            } else if (state == 2) {
                collection_set->insert(it);
            } else {
                qWarning() << "??";
            }
            emit this->collection_set_changed();
        });
        test->addWidget(checkbox, i, j);
        j += 1;
        if (j == 3) i += 1, j = 0;
    }
}

CollectionPage::~CollectionPage()
{
    delete ui;
}
