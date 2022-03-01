#include "AnswerLetter.h"

AnswerLetter::AnswerLetter(QWidget* parent)
	: QPushButton(parent)
{
	QFont f = font();
	f.setPointSize(20);
	setFont(f);

	setStyleSheet("border-width: 2; border-style: solid; border-color: white white black white;");
}

void AnswerLetter::SetLetter(char letter)
{
	setText(QString::fromStdString(std::string(1, letter)));
}
