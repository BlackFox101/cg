#pragma once
#include <QObject>
#include "IGallowsGame.h"
#include "Task.h"

class GallowsGame : public QObject, public IGallowsGame
{
	Q_OBJECT
public:
	const size_t MAX_ERRORS_NUMBER = 7;
	const char GUESSED_LETTER = '_';

	GallowsGame();

	void Restart() override;
	void CheckLetter(char letter) override;

	std::string GetCurrentAnswer() const override;
	std::string GetCurrentQuestion() const override;
	size_t GetMaxErrorNumber() const override;
	size_t GetErrorsNumber() const override;
	std::vector<Letter> GetUsedLetters() const override;
	std::set<char> GetAllLetters() const override;

signals:
	void DoOnGameRestart();
	void DoOnGameOver(bool isWin);
	void DoOnResponseToCheckLetter(Letter letter);

private:
	void UpdateGameParams();
	void AddUsedLetter(Letter letter);
	std::optional<std::vector<size_t>> GetCheckedLetterPosition(char letter);

	std::vector<Task> m_tasks;
	size_t m_currentTaskNumber;

	std::vector<Letter> m_usedLetters;
	size_t m_errorsNumbers;
	size_t m_unsolvedLettersNumber;
	const std::set<char> m_letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
									  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
};

