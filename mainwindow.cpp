#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "operator.h"
#include "collectionpage.h"
#include "damagepage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->collection_set = std::make_shared<CollectionSet>();

    auto test = ui->gridLayout;
    test->setAlignment(Qt::AlignTop);
    auto list = {"a"};
    int i = 0, j = 0;
    for (auto s : list) {
        test->addWidget(new QCheckBox(s), i, j);
        j += 1;
        if (j == 3) i += 1, j = 0;
    }
    DamagePacket t_typhon = Typhon().skill2(Buff::DEFAULT_BUFF);
    DamagePacket t_mlynar = Mlynar().skill3(Buff::DEFAULT_BUFF);
    test->addWidget(new QCheckBox(QString::number(t_mlynar.get_dps())), i, j);

    auto collection_page = new CollectionPage(this->collection_set);
    auto damage_page = new DamagePage(this->collection_set);

    ui->tabWidget->addTab(collection_page, "col");
    ui->tabWidget->addTab(damage_page, "damage");

    connect(collection_page, &CollectionPage::collection_set_changed, damage_page, &DamagePage::refresh_text_browser);
}

MainWindow::~MainWindow()
{
    delete ui;
}
