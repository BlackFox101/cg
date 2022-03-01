#include "LetterButton.h"

LetterButton::LetterButton(char letter, QWidget* parent)
	: m_letter(letter)
	, QPushButton(parent)
{
	setText(QString::fromStdString(std::string(1, letter)));
}

char LetterButton::GetLetter()
{
	return m_letter;
}

void LetterButton::Reset()
{
	setDisabled(false);
	setStyleSheet("");
}

void LetterButton::SetExist()
{
	setDisabled(true);
	setStyleSheet("color: green; border-style: outset;");
}

void LetterButton::SetNotExist()
{
	setDisabled(true);
	setStyleSheet("color: red; border-style: outset;");
}
