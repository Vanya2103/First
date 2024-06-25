//Условие задачи: Найти все натуральные числа, не превосходящие K, сумма цифр каждого из которых в некоторой степени дает это число (например, 9^2=81, 18^3=5832).
#include <QApplication>
#include "chislawidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ChislaWidget widget;
    widget.show();

    return app.exec();
}
