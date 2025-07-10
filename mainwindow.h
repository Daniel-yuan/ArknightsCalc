#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCheckBox>

const QString COLLECTION_PATH = "/Users/yuanxiangtao/QTtest/ArknightsCalc/collection.json";

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void collection_init();
};
#endif // MAINWINDOW_H
