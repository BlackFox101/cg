#include "View.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , m_scene(new QGraphicsScene(this))
{
    ui.setupUi(this);
    setFixedSize(600, 500);
    m_scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    m_scene->setSceneRect(0, 0, 500, 450);
    ui.graphicsView->resize(600, 500);
    ui.graphicsView->setScene(m_scene);

    DrawPicture(m_scene);
}

void View::DrawPicture(QGraphicsScene* m_scene)
{

}