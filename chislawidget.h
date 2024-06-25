#ifndef CHISLAWIDGET_H
#define CHISLAWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>

class ChislaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChislaWidget(QWidget *parent = nullptr);

private slots:
    void onCalculateClicked();

private:
    QLabel *taskDescription;
    QLineEdit *inputLine;
    QTextEdit *outputArea;
    QPushButton *calculateButton;

    int sum(int number);
};

#endif // CHISLAWIDGET_H

