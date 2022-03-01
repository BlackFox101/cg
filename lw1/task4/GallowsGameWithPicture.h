#pragma once
#include <QLabel>
#include <QBoxLayout>
#include <QGraphicsView>
#include <QButtonGroup>
#include <memory>
#include <QGroupBox>
#include "IGallowsGame.h"
#include "LetterButton.h"
#include "Letter.h"
#include "AnswerLetter.h"

class GallowsGameWithPicture : public QObject
{
	Q_OBJECT
public:
	GallowsGameWithPicture(std::shared_ptr<IGallowsGame> game, 
		QLabel* m_questionLabel, 
		QBoxLayout* m_lettersBox,
		QGraphicsView* m_graphicsView,
		QGroupBox* answerBox);
	~GallowsGameWithPicture();

private slots:
	void CheckLetter(int id);
	void ReactToCheckedLetter(Letter letter);
	void GameOver(bool isWin);
	void Restart();

private:
	void InitPicture();
	void MarkLetter(LetterButton* button, Letter letter);
	void AddError();
	void AddGuessedLetter(Letter letter);
	void UpdateView();

	void UpdateWord();
	void HidePicture();
	void UpdateButtons();

	std::shared_ptr<IGallowsGame> m_game;
	QButtonGroup* m_buttons;

	QLabel* m_questionLabel;
	QBoxLayout* m_lettersBox;
	QGraphicsView* m_graphicsView;
	QGroupBox* m_answerBox;

	std::vector<AnswerLetter*> m_answerLetters;
	std::vector<QGraphicsItem*> m_errorPicture;
	size_t m_currentErrorNumber;
};

