#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleValidator>
#include "table.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioButtonPaper_toggled(bool checked);

    void on_radioButtonPlate_toggled(bool checked);

    void on_pushButtonAdd_clicked();

    void on_pushButtonClear_clicked();

private:
    void log(const QString& text_);
    Ui::MainWindow* ui;
    QDoubleValidator m_doubleValidatorCoordinates;
    QDoubleValidator m_doubleValidator;
    Table m_table;
};
#endif // MAINWINDOW_H
