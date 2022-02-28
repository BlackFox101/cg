#include "View.h"
#include "ui_View.h"

View::View(std::shared_ptr<IGallowsGame> game, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);

    m_viewWithPicture = std::make_unique<GallowsGameWithPicture>(game, ui->questionLabel, ui->lettersLayout, ui->graphicsView);
    m_viewWithoutPicture = std::make_unique<GallowsGameWithoutPicture>();
}

View::~View()
{
    delete ui;
}