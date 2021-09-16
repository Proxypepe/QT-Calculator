#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <tuple>
#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void set_expressions(const QString&, const QString& = "");

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Model m;
    Ui::MainWindow *ui;

public slots:
    void on_zero_button_clicked();
    void on_one_button_clicked();
    void on_two_button_clicked();
    void on_tree_button_clicked();
    void on_four_button_clicked();
    void on_five_button_clicked();
    void on_six_button_clicked();
    void on_seven_button_clicked();
    void on_eight_button_clicked();
    void on_nine_button_clicked();
    void on_addition_button_clicked();
    void on_subtraction_button_clicked();
    void on_multiplication_button_clicked();
    void on_division_button_clicked();

    void on_equel_button_clicked();
private slots:
    void on_clear_button_clicked();
    void on_clear_all_button_clicked();
    void on_deletion_button_clicked();
    void on_comma_button_clicked();
    void on_neg_pos_button_clicked();
    void on_one_div_x_clicked();
    void on_power_button_clicked();
    void on_sqrt_button_clicked();
};
#endif // MAINWINDOW_H
