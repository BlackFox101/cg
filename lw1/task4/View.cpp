#include "View.h"
#include "ui_View.h"

View::View(std::shared_ptr<IGallowsGame> game, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);

    m_viewWithPicture = std::make_unique<GallowsGameWithPicture>(game, ui->questionLabel, ui->lettersLayout, ui->graphicsView, ui->answerBox);
    m_viewWithoutPicture = std::make_unique<GallowsGameWithoutPicture>(game, ui->questionLabel2, ui->usedLattersBox, ui->attemptsNumber, ui->lettersLayout2, ui->answerBox2);
}

View::~View()
{
    delete ui;
}