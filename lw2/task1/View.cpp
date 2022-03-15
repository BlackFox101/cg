#include "View.h"
#include <QFileDialog>
#include <QPainter>
#include "MainWidget.h"

View::View(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(OpenFile()));
}

void View::OpenFile()
{
    auto pathToImage = QFileDialog::getOpenFileName(this, "Select file", "C:/", "Images (*.png *.jpeg)");

    ui.centralWidget->OpenNewImage(pathToImage);
}