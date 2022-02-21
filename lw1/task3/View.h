#pragma once
#include <QtWidgets/QMainWindow>

namespace Ui { class View; }

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

private:
    void paintEvent(QPaintEvent* event) override;
    void DrawLine(QPainter& painter, int x0, int y0, int x1, int y1);

    Ui::View* ui;
};
