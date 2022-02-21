#pragma once
#include <QtWidgets/QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <vector>

namespace Ui { class View; }

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
