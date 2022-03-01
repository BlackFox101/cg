#pragma once
#include <QObject>
#include <QLabel>
#include <QGroupBox>
#include <QBoxLayout>
#include <QButtonGroup>
#include "IGallowsGame.h"
#include "LetterButton.h"
#include "AnswerLetter.h"

class GallowsGameWithoutPicture : public QObject
{
	Q_OBJECT
public:
	GallowsGameWithoutPicture(
		std::shared_ptr<IGallowsGame> game,
		QLabel* questionLabel,
		QGroupBox* usedLattersBox,
		QLabel* attemptsNumber,
		QBoxLayout* lettersBox,
		QGroupBox* answerBox);

private slots:
	void CheckLetter(int id);
	void ReactToCheckedLetter(Letter letter);
	void GameOver(bool isWin);
	void Restart();

private:
	void Init();

	void UpdateWord();
	void UpdateButtons();
	void UpdateView();
	void UpdateAttempsNumber();
	void UpdateUsedLetters();

	void MarkLetter(LetterButton* button, Letter letter);
	void AddError();
	void AddGuessedLetter(Letter letter);

	std::vector<AnswerLetter*> m_answerLetters;
	QButtonGroup* m_buttons;

	std::shared_ptr<IGallowsGame> m_game;

	QLabel* m_questionLabel;
	QGroupBox* m_usedLattersBox;
	QLabel* m_attemptsNumber;
	QBoxLayout* m_lettersBox;
	QGroupBox* m_answerBox;
};

