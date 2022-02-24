#pragma once
#include <QObject>
#include "IGallowsGame.h"
#include "Task.h"

class GallowsGame : public QObject, public IGallowsGame
{
	Q_OBJECT
public:
	const size_t MAX_ERRORS_NUMBER = 7;
	
	GallowsGame(std::vector<Task> tasks);

	void Restart() override;
	Letter CheckLetter(char letter) override;

	std::string GetCurrentAnswer() const override;
	std::string GetCurrentQuestion() const override;
	size_t GetMaxErrorNumber() const override;
	size_t GetErrorsNumber() const override;
	std::vector<Letter>  GetUsedLetters() const override;

signals:
	void DoOnGameRestart();
	void DoOnGameOver(bool isWin);

private:
	void UpdateGameParams();
	void AddUsedLetter(Letter letter);
	void AddErrorNumber();

	std::vector<Task> m_tasks;
	size_t m_currentTaskNumber;

	std::vector<Letter> m_usedLetters;
	size_t m_errorsNumbers;
};

