#include "GallowsGame.h"

GallowsGame::GallowsGame()
{
	m_tasks.push_back({"�������� �������", "�����"});
}

void GallowsGame::Restart()
{
	GenerateRandomTask();
	emit DoOnGameRestart();
}

void GallowsGame::GenerateRandomTask()
{

}