#include "GallowsGameWithPicture.h"
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <QHBoxLayout>

GallowsGameWithPicture::GallowsGameWithPicture(std::shared_ptr<IGallowsGame> game, QLabel* m_questionLabel, QBoxLayout* m_lettersBox, QGraphicsView* m_graphicsView, QGroupBox* answerBox)
	: m_game(game)
	, m_questionLabel(m_questionLabel)
	, m_lettersBox(m_lettersBox)
	, m_graphicsView(m_graphicsView)
	, m_buttons(new QButtonGroup())
	, m_answerBox(answerBox)
{
	m_questionLabel->setText(QString::fromStdString(m_game->GetCurrentQuestion()));

	auto letters = m_game->GetAllLetters();
	for (auto letter : letters)
	{
		LetterButton* button = new LetterButton(letter);
		button->setMaximumWidth(20);
		m_lettersBox->addWidget(button);
		m_buttons->addButton(button);
	}

	connect(m_buttons, SIGNAL(idClicked(int)), this, SLOT(CheckLetter(int)));

	connect(dynamic_cast<QObject*>(m_game.get()), SIGNAL(DoOnResponseToCheckLetter(Letter)), this, SLOT(ReactToCheckedLetter(Letter)));
	connect(dynamic_cast<QObject*>(m_game.get()), SIGNAL(DoOnGameRestart()), this, SLOT(Restart()));
	connect(dynamic_cast<QObject*>(m_game.get()), SIGNAL(DoOnGameOver(bool)), this, SLOT(GameOver(bool)));

	m_currentErrorNumber = 0;
	InitPicture();
	UpdateView();
}

GallowsGameWithPicture::~GallowsGameWithPicture()
{
	delete m_buttons;
}

void GallowsGameWithPicture::InitPicture()
{
	m_graphicsView->setAlignment(Qt::AlignCenter);
	m_graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_graphicsView->setRenderHint(QPainter::Antialiasing);
	m_graphicsView->setCacheMode(QGraphicsView::CacheBackground);
	m_graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	m_graphicsView->setContentsMargins(0, 0, 0, 0);

	auto scene = new QGraphicsScene(m_graphicsView);
	auto width = m_graphicsView->width();
	auto height = m_graphicsView->height() ;

	m_graphicsView->setScene(scene);

	scene->setSceneRect(0, 0, width, height);

	auto middle = width / 2;

	scene->addRect(0, 0, 10, height, QColor(0, 0, 0), QColor(0, 0, 0));
	scene->addRect(0, 0, width / 2, 10, QColor(0, 0, 0), QColor(0, 0, 0));

	auto rope = new QGraphicsRectItem(middle, 0, 2, 50);
	rope->setPen(QColor(0, 0, 255));
	rope->setBrush(QColor(0, 0, 255));

	auto head = new QGraphicsEllipseItem(middle - 25, 50, 50, 50);
	head->setPen(QColor(0, 0, 255));
	head->setBrush(QColor(0, 0, 255));

	auto body = new QGraphicsRectItem(middle - 2.5, 100, 5, 100);
	body->setPen(QColor(0, 0, 255));
	body->setBrush(QColor(0, 0, 255));

	QPolygonF d;
	d << QPointF(middle - 2.5, 200) << QPointF(middle + 2.5, 200) << QPointF(middle - 50, 270) << QPointF(middle - 55, 270);
	auto leg1 = new QGraphicsPolygonItem(d);
	leg1->setPen(QColor(0, 0, 255));
	leg1->setBrush(QColor(0, 0, 255));

	d.clear();
	d << QPointF(middle - 2.5, 200) << QPointF(middle + 2.5, 200) << QPointF(middle + 55, 270) << QPointF(middle + 50, 270);
	auto leg2 = new QGraphicsPolygonItem(d);
	leg2->setPen(QColor(0, 0, 255));
	leg2->setBrush(QColor(0, 0, 255));

	d.clear();
	d << QPointF(middle, 130) << QPointF(middle, 135)
		<< QPointF(middle + 50, 165) << QPointF(middle + 50, 160);
	auto arm1 = new QGraphicsPolygonItem(d);
	arm1->setPen(QColor(0, 0, 255));
	arm1->setBrush(QColor(0, 0, 255));

	d.clear();
	d << QPointF(middle, 130) << QPointF(middle, 135)
		<< QPointF(middle - 50, 165) << QPointF(middle - 50, 160);
	auto arm2 = new QGraphicsPolygonItem(d);
	arm2->setPen(QColor(0, 0, 255));
	arm2->setBrush(QColor(0, 0, 255));

	m_errorPicture.push_back(rope);
	m_errorPicture.push_back(head);
	m_errorPicture.push_back(body);
	m_errorPicture.push_back(leg1);
	m_errorPicture.push_back(leg2);
	m_errorPicture.push_back(arm1);
	m_errorPicture.push_back(arm2);

	for (auto item : m_errorPicture)
	{
		scene->addItem(item);
		item->hide();
	}


}

void GallowsGameWithPicture::CheckLetter(int id)
{
	auto button = dynamic_cast<LetterButton*>(m_buttons->button(id));
	m_game->CheckLetter(button->GetLetter());
}

void GallowsGameWithPicture::ReactToCheckedLetter(Letter letter)
{
	for (auto& button : m_buttons->buttons())
	{
		auto currentButton = dynamic_cast<LetterButton*>(button);

		if (currentButton->GetLetter() == letter.letter)
		{
			MarkLetter(currentButton, letter);
			return;
		}
	}
}

void GallowsGameWithPicture::MarkLetter(LetterButton* button, Letter letter)
{
	if (letter.position == std::nullopt)
	{
		button->SetNotExist();
		AddError();
	}
	else
	{
		button->SetExist();
		AddGuessedLetter(letter);
	}
}

void GallowsGameWithPicture::AddError()
{
	if (m_currentErrorNumber < m_errorPicture.size())
	{
		m_errorPicture[m_currentErrorNumber]->show();
		m_currentErrorNumber++;
	}
}

void GallowsGameWithPicture::AddGuessedLetter(Letter letter)
{
	auto positions = *(letter.position);
	for (auto pos : positions)
	{
		m_answerLetters.at(pos)->SetLetter(letter.letter);
	}
}

void GallowsGameWithPicture::GameOver(bool isWin)
{
	QMessageBox msgBox;
	if (isWin)
	{
		msgBox.setText("You won!");
	}
	else
	{
		msgBox.setText("You've lost!");
	}
	msgBox.setStandardButtons(QMessageBox::Reset | QMessageBox::Close);
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int res = msgBox.exec();
	if (res == QMessageBox::Reset)
	{
		m_game->Restart();
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}

void GallowsGameWithPicture::Restart()
{
	UpdateView();
}

void GallowsGameWithPicture::UpdateView()
{
	m_questionLabel->setText(QString::fromStdString(m_game->GetCurrentQuestion()));
	m_currentErrorNumber = 0;
	HidePicture();
	UpdateButtons();
	UpdateWord();
}

void GallowsGameWithPicture::UpdateButtons()
{
	for (auto& button : m_buttons->buttons())
	{
		auto currentButton = dynamic_cast<LetterButton*>(button);
		currentButton->Reset();
	}
}

void GallowsGameWithPicture::HidePicture()
{
	for (auto item : m_errorPicture)
	{
		item->hide();
	}
}

void GallowsGameWithPicture::UpdateWord()
{
	if (m_answerBox->layout()) 
	{
		QLayoutItem* child;
		while ((child = m_answerBox->layout()->takeAt(0)) != 0) {
			delete child->widget();
			delete child;
		}
		delete m_answerBox->layout();
	}
	m_answerLetters.clear();

	QHBoxLayout* layout = new QHBoxLayout;
	m_answerBox->setLayout(layout);

	auto temp = m_game->GetCurrentAnswer();
	for (size_t i = 0; i < temp.size(); i++)
	{
		AnswerLetter* button = new AnswerLetter();
		m_answerLetters.push_back(button);
		layout->addWidget(button);
	}
}