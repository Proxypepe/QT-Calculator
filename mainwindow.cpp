#include "mainwindow.h"
#include "ui_mainwindow.h"





void MainWindow::set_expressions(const QString& mode, const QString& digit)
{
    QString expression                      = "";
    QString sub_expression                  = "";
    std::tie(expression, sub_expression)    =  m.update(mode, digit);
    ui->expression->setText(expression);
    ui->sub_expression->setText(sub_expression);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_zero_button_clicked()   { set_expressions("digit", "0"); }
void MainWindow::on_one_button_clicked()    { set_expressions("digit", "1"); }
void MainWindow::on_two_button_clicked()    { set_expressions("digit", "2"); }
void MainWindow::on_tree_button_clicked()   { set_expressions("digit", "3"); }
void MainWindow::on_four_button_clicked()   { set_expressions("digit", "4"); }
void MainWindow::on_five_button_clicked()   { set_expressions("digit", "5"); }
void MainWindow::on_six_button_clicked()    { set_expressions("digit", "6"); }
void MainWindow::on_seven_button_clicked()  { set_expressions("digit", "7"); }
void MainWindow::on_eight_button_clicked()  { set_expressions("digit", "8"); }
void MainWindow::on_nine_button_clicked()   { set_expressions("digit", "9"); }

void MainWindow::on_addition_button_clicked(){ set_expressions("simple_op", "+");  }

void MainWindow::on_subtraction_button_clicked(){ set_expressions("simple_op", "-");  }

void MainWindow::on_multiplication_button_clicked(){ set_expressions("simple_op", "*");  }

void MainWindow::on_division_button_clicked(){ set_expressions("simple_op", "/");  }

void MainWindow::on_equel_button_clicked() { set_expressions("calculate");  }

void MainWindow::on_clear_button_clicked() { set_expressions("clear", "+");  }

void MainWindow::on_clear_all_button_clicked() { set_expressions("clear_all", "+");  }

