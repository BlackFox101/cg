#pragma once
#include <QPushButton>

class LetterButton : public QPushButton
{
	Q_OBJECT
public:
	LetterButton(char letter, QWidget* parent = nullptr);
	char GetLetter();
	void Reset();

public slots:
	void SetExist();
	void SetNotExist();

private:
	char m_letter;
};

