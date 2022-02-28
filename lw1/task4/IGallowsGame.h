#pragma once
#include <string>
#include <vector>
#include <set>
#include "Letter.h"

class IGallowsGame
{
public:
	virtual void Restart() = 0;
	virtual void CheckLetter(char letter) = 0;

	virtual std::string GetCurrentAnswer() const = 0;
	virtual std::string GetCurrentQuestion() const = 0;
	virtual size_t GetMaxErrorNumber() const = 0;
	virtual size_t GetErrorsNumber() const = 0;
	virtual std::vector<Letter> GetUsedLetters() const = 0;
	virtual std::set<char> GetAllLetters() const = 0;

	virtual void DoOnGameRestart() = 0;
	virtual void DoOnGameOver(bool isWin) = 0;
	virtual void DoOnResponseToCheckLetter(Letter letter) = 0;

	virtual ~IGallowsGame() = default;
};