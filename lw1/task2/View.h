#pragma once
#include <QWidget>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = Q_NULLPTR);

private:
    Ui::View* ui;
    QGraphicsScene* m_scene;
};
