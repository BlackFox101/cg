#include "GallowsGame.h"

GallowsGame::GallowsGame()
{
	m_tasks.push_back({"Сумчатый медведь", "коала"});
}

void GallowsGame::Restart()
{
	GenerateRandomTask();
	emit DoOnGameRestart();
}

void GallowsGame::GenerateRandomTask()
{

}