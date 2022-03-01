#pragma once
#include <QPushButton>

class AnswerLetter : public QPushButton
{
	Q_OBJECT
public:
	AnswerLetter(QWidget* parent = nullptr);
	void SetLetter(char letter);
};

