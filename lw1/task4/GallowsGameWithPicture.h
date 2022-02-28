#pragma once
#include <QLabel>
#include <QBoxLayout>
#include <QGraphicsView>
#include <QButtonGroup>
#include <memory>
#include "IGallowsGame.h"
#include "LetterButton.h"
#include "Letter.h"

class GallowsGameWithPicture : public QObject
{
	Q_OBJECT
public:
	GallowsGameWithPicture(std::shared_ptr<IGallowsGame> game, 
		QLabel* m_questionLabel, 
		QBoxLayout* m_lettersBox,
		QGraphicsView* m_graphicsView);
	~GallowsGameWithPicture();

private slots:
	void CheckLetter(int id);
	void ReactToCheckedLetter(Letter letter);
	void GameOver(bool isWin);
	void Restart();

private:
	void Init();
	void MarkLetter(LetterButton* button, Letter letter);
	void AddError();
	void AddGuessedLetter();
	void UpdateView();

	std::shared_ptr<IGallowsGame> m_game;
	QButtonGroup* m_buttons;

	QLabel* m_questionLabel;
	QBoxLayout* m_lettersBox;
	QGraphicsView* m_graphicsView;

	std::vector<QGraphicsItem*> m_errorPicture;
	size_t m_currentErrorNumber;
};

