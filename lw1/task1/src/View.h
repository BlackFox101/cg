#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include "ui_View.h"

class View : public QMainWindow
{
	Q_OBJECT

public:
	explicit View(QWidget *parent = Q_NULLPTR);
	~View();

protected:
	void paintEvent(QPaintEvent* event) override;

private:
	void Move();
	QGraphicsItemGroup* GetLetterC();
	QGraphicsItemGroup* GetLetterA();

	Ui::View* ui;
	QGraphicsScene* m_scene;
};
