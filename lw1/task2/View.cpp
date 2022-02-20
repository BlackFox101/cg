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
    graphicsView->setAlignment(Qt::AlignCenter); 
    graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    graphicsView->setMinimumHeight(400);
    graphicsView->setMinimumWidth(600);

    graphicsView->setRenderHint(QPainter::Antialiasing);
    graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    ui->gridLayout->addWidget(graphicsView);
    graphicsView->setScene(m_scene);

    auto width = graphicsView->width() - 11;
    auto height = graphicsView->height() - 11;
    m_scene->setSceneRect(0, 0, width, height);

    auto item = new MoveItem();
    m_scene->addItem(item);
}

View::~View()
{
    delete ui;
}

MoveItem* GetMoveItem()
{
    return new MoveItem();
}