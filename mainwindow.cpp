#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    m_doubleValidator.setBottom(0.0);
    ui->lineEditX->setValidator(&m_doubleValidatorCoordinates);
    ui->lineEditY->setValidator(&m_doubleValidatorCoordinates);
    ui->lineEditThickness->setValidator(&m_doubleValidator);
    ui->lineEditWidth->setValidator(&m_doubleValidator);
    ui->lineEditHeight->setValidator(&m_doubleValidator);
    ui->lineEditRadius->setValidator(&m_doubleValidator);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_radioButtonPaper_toggled(bool checked) {
    ui->lineEditHeight->setEnabled(checked);
    ui->lineEditWidth->setEnabled(checked);
    ui->lineEditRadius->setEnabled(!checked);
}

void MainWindow::on_radioButtonPlate_toggled(bool checked) {
    ui->lineEditHeight->setEnabled(!checked);
    ui->lineEditWidth->setEnabled(!checked);
    ui->lineEditRadius->setEnabled(checked);
}

void MainWindow::on_pushButtonAdd_clicked() {
    if (ui->radioButtonPaper->isChecked()) {
        m_table.addPaper(ui->lineEditX->text().toDouble(),
                         ui->lineEditY->text().toDouble(),
                         ui->lineEditThickness->text().toDouble(),
                         ui->lineEditWidth->text().toDouble(),
                         ui->lineEditHeight->text().toDouble());
        log(QString("Add paper; stack size is %1; it is %2balanced").arg(QString::number(m_table.size()), m_table.isBalanced() ? "" : "un"));
    } else {
        m_table.addPlate(ui->lineEditX->text().toDouble(),
                         ui->lineEditY->text().toDouble(),
                         ui->lineEditThickness->text().toDouble(),
                         ui->lineEditRadius->text().toDouble());
        log(QString("Add plate; stack size is %1; it is %2balanced").arg(QString::number(m_table.size()), m_table.isBalanced() ? "" : "un"));
    }
}

void MainWindow::on_pushButtonClear_clicked() {
    m_table.clear();
    log(QString("Clear table; stack size is expectedly %1; it is obviously %2balanced").arg(QString::number(m_table.size()), m_table.isBalanced() ? "" : "un"));
}

void MainWindow::log(const QString &text_) {
    ui->textEditLog->setText(ui->textEditLog->toPlainText() + text_ + "\n");
}
