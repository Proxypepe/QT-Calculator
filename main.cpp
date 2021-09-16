#include "mainwindow.h"

#include <memory>
#include <QApplication>
#include <QtGui>
#include <QStyleFactory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setStyle(QStyleFactory::create("Fusion"));
    std::shared_ptr<QPalette> palette = std::make_shared<QPalette>();
    palette->setColor(QPalette::Window, QColor(53, 53, 53));
    palette->setColor(QPalette::WindowText, Qt::white);

    palette->setColor(QPalette::Base, QColor(15, 15, 15));
    palette->setColor(QPalette::AlternateBase, QColor(53, 53, 53));

    palette->setColor(QPalette::ToolTipBase, Qt::white);
    palette->setColor(QPalette::ToolTipText, Qt::white);

    palette->setColor(QPalette::Text, Qt::white);
    palette->setColor(QPalette::Button, QColor(53, 53, 53));

    palette->setColor(QPalette::ButtonText, Qt::black);
    palette->setColor(QPalette::BrightText, Qt::red);

    palette->setColor(QPalette::Highlight, QColor(142, 45, 197).lighter());
    palette->setColor(QPalette::HighlightedText, Qt::white);

    w.setPalette(*palette);
    w.show();
    return a.exec();

}
