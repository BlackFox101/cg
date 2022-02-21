#pragma once
#include <QObject>
#include <string>
#include <vector>

class GallowsGame : public QObject
{
	Q_OBJECT
public:
	struct Letter
	{
		char letter;
		bool isExist;
	};

	GallowsGame();

	void Restart();

	std::string GetCurrentWord();
	std::string GetCurrentQuestion();

	bool CheckLetter(char letter);

	std::vector<Letter> GetUsedLetters();
	std::vector<Letter> GetAllLetters();

	size_t GetAttemptsNumber();
	size_t GetErrorsNumber();
	size_t GetMaxErrorNumber();

signals:
	void DoOnGameRestart();
	void DoOnGameOver(bool isWin);

private:
	void GenerateRandomTask();

	struct Task
	{
		std::string question;
		std::string answer;
	};

	size_t m_taskNumber;
	std::vector<Task> m_tasks;
	std::vector<Letter> m_usedLetters;
	std::vector<char> m_allLetters;

	const char m_letter[33] = {'À', 'Á', 'Â', 'Ã', 'Ä', 'Å', '¨', 'Æ', 'Ç', 'È', 'É',
							   'Ê', 'Ë', 'Ì', 'Í', 'Î', 'Ï', 'Ð', 'Ñ', 'Ò', 'Ó', 'Ô',
							   'Õ', 'Ö', '×', 'Ø', 'Ù', 'Ú', 'Û', 'Ü', 'Ý', 'Þ', 'ß' };
};

