#pragma once
#include <QWidget>
#include <QGraphicsScene>
#include "MoveItem.h"

namespace Ui { class View; }

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = Q_NULLPTR);
    ~View();

private:
    MoveItem* GetMoveItem();

    Ui::View* ui;
    QGraphicsScene* m_scene;
};
