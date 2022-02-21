#include "View.h"
#include "ui_View.h"
#include <QPainter>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}

void View::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    // Устанавливаем режим устранения ступенчатости фигур (anti-aliasing mode)
    //painter.setRenderHint(QPainter::Antialiasing);

    // Устанавливаем кисть жёлтого цвета (цвет задан в RGB)
    painter.setBrush(QBrush(QColor(0, 0, 0)));
    painter.setPen(QColor(0, 0, 0));
    DrawLine(painter, 0, 0 , width() - 1, height() - 1);
    //painter.drawLine(0, 0, width() - 1, height() - 1);
    //painter.drawPoint(0, 0);

    // Рисуем эллипс на всё окно с отступом 5 пикселей
    //painter.drawEllipse(QRect(5, 5, width() - 10, height() - 10));
}

void View::DrawLine(QPainter& painter, int x0, int y0, int x1, int y1)
{
    int deltaX = x0 - x1;
    int deltaY = y0 - y1;
    double k = static_cast<double>(deltaY) / static_cast<double>(deltaX);

    bool isPositiveIncrease = deltaX > 0;
    // positiveIncrease ? i <= deltaX : i >= deltaX; positiveIncrease ? i++ : i--
    // 
    // i <= std::abs(deltaX); i++
    for (int i = 0; isPositiveIncrease ? i >= deltaX : i <= deltaX; isPositiveIncrease ? i-- : i++)
    {
        int x = x0 + i;
        int y = static_cast<int>(i * k) + y0;
        painter.drawPoint(x, y);
    }
}
