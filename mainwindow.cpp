#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "operator.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QJsonArray>

void MainWindow::collection_init() {
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

    QJsonArray jsonArray = doc.array();
    for (const QJsonValue &value : jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            int nameValue = obj.value("name").toInt();
            qDebug() << "name:" << nameValue;
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    collection_init();
    auto test = ui->gridLayout;
    test->setAlignment(Qt::AlignTop);
    auto list = {"a"};
    int i = 0, j = 0;
    for (auto s : list) {
        test->addWidget(new QCheckBox(s), i, j);
        j += 1;
        if (j == 3) i += 1, j = 0;
    }
    DamagePacket t = Typhon().skill2(Buff::DEFAULT_BUFF);
    test->addWidget(new QCheckBox(QString::number(t.get_dps())), i, j);
}

MainWindow::~MainWindow()
{
    delete ui;
}
