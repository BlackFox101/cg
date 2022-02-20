#include "View.h"
#include "ui_View.h"
#include <QGraphicsView>

View::View(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::View)
    , m_scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    auto graphicsView = new QGraphicsView(this);
    graphicsView->setAlignment(Qt::AlignCenter);                                    // Делаем привязку содержимого к центру
    graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    graphicsView->setMinimumHeight(400);
    graphicsView->setMinimumWidth(600);

    ui->gridLayout->addWidget(graphicsView);
    graphicsView->setScene(m_scene);

    auto width = graphicsView->width() - 11;
    auto height = graphicsView->height() - 11;
    m_scene->setSceneRect(0, 0, width, height);
}
