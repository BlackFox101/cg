#include "UsedLetter.h"

UsedLetter::UsedLetter(char letter, QWidget* parent)
	: LetterButton(letter, parent)
{
	setFixedSize(size());
}