#pragma once
#include <QtWidgets/QMainWindow>
#include <QGraphicsScene>
#include "ui_View.h"

class View : public QMainWindow
{
    Q_OBJECT
public:
    explicit View(QWidget* parent = Q_NULLPTR);

private:
    void DrawPicture(QGraphicsScene* m_scene);

    Ui::View ui;
    QGraphicsScene* m_scene;
};
