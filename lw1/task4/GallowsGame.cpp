#include "GallowsGame.h"
#include <stdexcept>

GallowsGame::GallowsGame()
{
	m_tasks.push_back({ "Marsupial Bear", "KOALA" });
	m_tasks.push_back({ "Which continent Russia sold to USA", "ALYASKA" });
	m_tasks.push_back({ "Who is the richest person on the planet?", "ELON" });

	UpdateGameParams();
}

void GallowsGame::Restart()
{
	UpdateGameParams();

	emit DoOnGameRestart();
}

size_t GallowsGame::GetAttempsNumber() const
{
	return MAX_ERRORS_NUMBER - m_errorsNumbers;
}

void GallowsGame::CheckLetter(char letter)
{
	if (m_letters.find(letter) == m_letters.end())
	{
		throw std::invalid_argument("Invalid character");
	}

	Letter usedLetter;
	usedLetter.letter = letter;
	usedLetter.position = GetCheckedLetterPosition(letter);

	if (usedLetter.position == std::nullopt)
	{
		m_errorsNumbers++;
	}
	else
	{
		m_unsolvedLettersNumber -= usedLetter.position->size();
	}

	AddUsedLetter(usedLetter);

	emit DoOnResponseToCheckLetter(usedLetter);

	if (m_errorsNumbers >= MAX_ERRORS_NUMBER)
	{
		emit DoOnGameOver(false);
		Restart();
	}

	if (m_unsolvedLettersNumber <= 0)
	{
		emit DoOnGameOver(true);
		Restart();
	}
}

std::optional<std::vector<size_t>> GallowsGame::GetCheckedLetterPosition(char letter)
{
	auto answer = m_tasks.at(m_currentTaskNumber).answer;
	auto pos = answer.find(letter);

	if (pos == std::string::npos)
	{
		return std::nullopt;
	}

	std::vector<size_t> positions;
	do
	{
		positions.push_back(pos);
		answer[pos] = GUESSED_LETTER;
		pos = answer.find(letter);
	} while (pos != std::string::npos);

	return positions;
}

void GallowsGame::UpdateGameParams()
{
	srand(time(0));
	m_currentTaskNumber = rand() % m_tasks.size();
	m_usedLetters.clear();
	m_errorsNumbers = 0;
	m_unsolvedLettersNumber = m_tasks[m_currentTaskNumber].answer.size();
}

void GallowsGame::AddUsedLetter(Letter letter)
{
	m_usedLetters.push_back(letter);
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

std::set<char> GallowsGame::GetAllLetters() const
{
	return m_letters;
}