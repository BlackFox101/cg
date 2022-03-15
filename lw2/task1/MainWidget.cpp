#include "MainWidget.h"
#include <QPainter>

MainWidget::MainWidget(QWidget* parent)
	: QWidget(parent)
{
}

void MainWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    DrawBackground(painter);
    DrawImage(painter);
}

void MainWidget::OpenNewImage(QString pathToFile)
{
    m_image = QImage(pathToFile);
    repaint();
}

void MainWidget::DrawImage(QPainter& painter)
{
    auto size = m_image.size();
    if (size.width() != 0 && size.height() != 0)
    {
        int newWidth = width();
        int proportions = size.width() / newWidth;
        int newHeight = size.height() / proportions;

        if (newHeight > height())
        {
            proportions = size.height() / height();
            newWidth = size.height() / proportions;
            newHeight = height();
        }

        int centerX = (width() - newWidth) / 2;
        int centerY = (height() - newHeight) / 2;

        painter.drawImage(QRect(centerX, centerY, newWidth, newHeight), m_image);
    }
}

void MainWidget::DrawBackground(QPainter& painter)
{
    int size = 50;
    for (size_t x = 0; x < width(); x += size)
    {
        for (size_t y = 0; y < height(); y += size)
        {
            painter.drawRect(x, y, size, size);
        }
    }
}