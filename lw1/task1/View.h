#pragma once
#include <QtWidgets/QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class View; }
QT_END_NAMESPACE

class View : public QWidget
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

private slots:
    void Move();

private:
    QGraphicsItem* GetLetterC();
    QGraphicsItem* GetLetterA();

    Ui::View* ui;
    QGraphicsScene* m_scene;
    std::vector<std::pair<QGraphicsItem*, float>> m_items;
};
