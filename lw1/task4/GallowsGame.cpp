#include "GallowsGame.h"
#include <stdexcept>

GallowsGame::GallowsGame(std::vector<Task> tasks)
{
	m_tasks = tasks;

	UpdateGameParams();
}

void GallowsGame::Restart()
{
	UpdateGameParams();

	emit DoOnGameRestart();
}

Letter GallowsGame::CheckLetter(char letter)
{
	auto answer = m_tasks.at(m_currentTaskNumber).answer;
	auto pos = answer.find(letter);

	Letter usedLetter;
	usedLetter.letter = letter;
	if (pos != std::string::npos)
	{	 
		usedLetter.position = { pos };
	}
	else
	{
		usedLetter.position = std::nullopt;
		AddErrorNumber();
	}

	AddUsedLetter(usedLetter);

	return usedLetter;
}

void GallowsGame::UpdateGameParams()
{
	m_currentTaskNumber = rand() % m_tasks.size() + 1;
	m_usedLetters.clear();
	m_errorsNumbers = 0;
}

void GallowsGame::AddUsedLetter(Letter letter)
{
	m_usedLetters.push_back(letter);
}

void GallowsGame::AddErrorNumber()
{
	m_errorsNumbers++;
}

std::string GallowsGame::GetCurrentAnswer() const
{
	return m_tasks.at(m_currentTaskNumber).answer;
}

std::string GallowsGame::GetCurrentQuestion() const
{
	return m_tasks.at(m_currentTaskNumber).question;
}

size_t GallowsGame::GetMaxErrorNumber() const
{
	return MAX_ERRORS_NUMBER;
}

size_t GallowsGame::GetErrorsNumber() const
{
	return m_errorsNumbers;
}

std::vector<Letter> GallowsGame::GetUsedLetters() const
{
	return m_usedLetters;
}