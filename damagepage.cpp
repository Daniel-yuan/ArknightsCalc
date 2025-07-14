#include "damagepage.h"
#include "ui_damagepage.h"
#include <QDebug>

DamagePage::DamagePage(std::shared_ptr<CollectionSet> collection_set)
    : QWidget(nullptr), collection_set(collection_set)
    , ui(new Ui::DamagePage)
{
    ui->setupUi(this);
    Collection sum = collection_set->get_sum();
    ui->textBrowser->setPlainText(sum.get_name());
    qWarning() << sum.get_name();
}

void DamagePage::refresh_text_browser() {
    auto sum = collection_set->get_sum();
    auto buff = sum.get_buff();
    QString content;
    content += "inner buff: " + QString::number(buff.get_attack_buff_inner()) + "\n";
    content += "outer buff: " + QString::number(buff.get_attack_buff_outer()) + "\n";
    content += "speed buff: " + QString::number(buff.get_attack_speed_buff()) + "\n";
    ui->textBrowser->setPlainText(content);
}

DamagePage::~DamagePage()
{
    delete ui;
}
