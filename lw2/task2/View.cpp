#include "View.h"
#include <QFileDialog>
#include <QGraphicsPixmapItem>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , m_scene(new QGraphicsScene(this))
{
    ui.setupUi(this);

    //ui.graphicsView->hide();

    connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(OpenFile()));
    connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(NewFile()));
    ui.graphicsView->setScene(m_scene);
}


void View::OpenFile()
{
    auto pathToImage = QFileDialog::getOpenFileName(this, "Select file", "C:/", "Images (*.png *.jpeg *.jpg)");
    QImage image(pathToImage);
    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    ui.centralWidget->resize(image.size());
    ui.graphicsView->resize(image.size());
    m_scene->addItem(item);

    //ui.graphicsView->show();

    //QBrush redBrush(Qt::red);
    //QPen blackPen(Qt::black);
    //blackPen.setWidth(6);
    //m_scene->addEllipse(10, 10, 100, 100, blackPen, redBrush);
}

void View::NewFile()
{
    ui.graphicsView->show();
    //ui.centralWidget->OpenNewImage(pathToImage);
}