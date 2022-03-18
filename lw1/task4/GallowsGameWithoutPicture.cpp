#include "GallowsGameWithoutPicture.h"

GallowsGameWithoutPicture::GallowsGameWithoutPicture(
	std::shared_ptr<IGallowsGame> game,
	QLabel* questionLabel,
	QGroupBox* usedLattersBox,
	QLabel* attemptsNumber,
	QBoxLayout* lettersBox,
	QGroupBox* answerBox)
	: m_game(game)
	, m_questionLabel(questionLabel)
	, m_usedLattersBox(usedLattersBox)
	, m_attemptsNumber(attemptsNumber)
	, m_lettersBox(lettersBox)
	, m_answerBox(answerBox)
	, m_buttons(new QButtonGroup())

{
	connect(m_buttons, SIGNAL(idClicked(int)), this, SLOT(CheckLetter(int)));

	connect(dynamic_cast<QObject*>(m_game.get()), SIGNAL(DoOnResponseToCheckLetter(Letter)), this, SLOT(ReactToCheckedLetter(Letter)));
	connect(dynamic_cast<QObject*>(m_game.get()), SIGNAL(DoOnGameRestart()), this, SLOT(Restart()));
	connect(dynamic_cast<QObject*>(m_game.get()), SIGNAL(DoOnGameOver(bool)), this, SLOT(GameOver(bool)));

	Init();
	UpdateView();
}

void GallowsGameWithoutPicture::UpdateView()
{
	m_questionLabel->setText(QString::fromStdString(m_game->GetCurrentQuestion()));
	UpdateWord();
	UpdateButtons();
	UpdateWord();
	UpdateAttempsNumber();
	UpdateUsedLetters();
}

void GallowsGameWithoutPicture::UpdateButtons()
{
	for (auto& button : m_buttons->buttons())
	{
		auto currentButton = dynamic_cast<LetterButton*>(button);
		currentButton->Reset();
	}
}

void GallowsGameWithoutPicture::Init()
{
	auto letters = m_game->GetAllLetters();
	for (auto letter : letters)
	{
		LetterButton* button = new LetterButton(letter);
		button->setMaximumWidth(20);
		m_lettersBox->addWidget(button);
		m_buttons->addButton(button);
	}
}

void GallowsGameWithoutPicture::UpdateUsedLetters()
{
	if (m_usedLattersBox->layout())
	{
		QLayoutItem* child;
		while ((child = m_usedLattersBox->layout()->takeAt(0)) != 0) {
			delete child->widget();
			delete child;
		}
		delete m_usedLattersBox->layout();
	}

	QHBoxLayout* layout = new QHBoxLayout;
	m_usedLattersBox->setLayout(layout);

	auto letters = m_game->GetUsedLetters();
	for (auto letter : letters)
	{
		LetterButton* button = new LetterButton(letter.letter);
		if (letter.position == std::nullopt)
		{
			button->SetNotExist();
		}
		else
		{
			button->SetExist();
		}
		button->setMaximumWidth(20);
		layout->addWidget(button);
	}
	auto horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	layout->addItem(horizontalSpacer);
}

void GallowsGameWithoutPicture::UpdateAttempsNumber()
{
	m_attemptsNumber->setText(QString::number(m_game->GetAttempsNumber()));
}

void GallowsGameWithoutPicture::CheckLetter(int id)
{
	auto button = dynamic_cast<LetterButton*>(m_buttons->button(id));
	m_game->CheckLetter(button->GetLetter());
}

void GallowsGameWithoutPicture::ReactToCheckedLetter(Letter letter)
{
	UpdateUsedLetters();
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

void GallowsGameWithoutPicture::MarkLetter(LetterButton* button, Letter letter)
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

void GallowsGameWithoutPicture::AddError()
{
	UpdateAttempsNumber();
}

void GallowsGameWithoutPicture::AddGuessedLetter(Letter letter)
{
	auto positions = *(letter.position);
	for (auto pos : positions)
	{
		m_answerLetters.at(pos)->SetLetter(letter.letter);
	}
}

void GallowsGameWithoutPicture::GameOver(bool isWin)
{

}

void GallowsGameWithoutPicture::Restart()
{
	UpdateView();
}

void GallowsGameWithoutPicture::UpdateWord()
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