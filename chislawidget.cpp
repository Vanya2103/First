#include "chislawidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <cmath>
#include <QTextStream>

ChislaWidget::ChislaWidget(QWidget *parent)
    : QWidget(parent),
    taskDescription(new QLabel(this)),
    inputLine(new QLineEdit(this)),
    outputArea(new QTextEdit(this)),
    calculateButton(new QPushButton("Найти числа ", this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *inputLayout = new QHBoxLayout;

    inputLayout->addWidget(new QLabel("Введите число:", this));
    inputLayout->addWidget(inputLine);

    mainLayout->addLayout(inputLayout);
    mainLayout->addWidget(outputArea);
    mainLayout->addWidget(calculateButton);

    connect(calculateButton, &QPushButton::clicked, this, &ChislaWidget::onCalculateClicked);

    setLayout(mainLayout);
    setWindowTitle("Chisla Finder");
}

void ChislaWidget::onCalculateClicked()
{
    bool ok;
    int k = inputLine->text().toInt(&ok);

    if (!ok || k <= 0) {
        outputArea->setText("Введите корректное число.");
        return;
    }

    outputArea->clear();

    for (int i = 1; i <= k; ++i) {
        for (int m = 2; m < 100; ++m) {
            int poweredValue = static_cast<int>(pow(i, m));
            if (sum(poweredValue) == i) {
                outputArea->append(QString("%1 ^ %2 = %3").arg(i).arg(m).arg(poweredValue));
                break;
            }
        }
    }
}

int ChislaWidget::sum(int number)
{
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
