#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto test = ui->gridLayout;
    auto list = {"a", "b", "c", "d", "e", "f", "g"};
    int i = 0, j = 0;
    for (auto s : list) {
        test->addWidget(new QCheckBox(s), i, j);
        j += 1;
        if (j == 3) i += 1, j = 0;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
