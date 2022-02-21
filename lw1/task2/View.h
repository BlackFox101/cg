#pragma once
#include <QWidget>
#include <QGraphicsScene>
#include "MoveItem.h"

namespace Ui { class View; }

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

private:

    Ui::View* ui;
    QGraphicsScene* m_scene;
};
