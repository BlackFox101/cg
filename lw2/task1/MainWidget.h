#pragma once
#include <QWidget>
#include <QPainter>

class MainWidget : public QWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget* parent = nullptr);

	void OpenNewImage(QString pathToFile);

protected:
	void paintEvent(QPaintEvent* event) override;

private:
	void DrawImage(QPainter& painter);
	void DrawBackground(QPainter& painter);

	QImage m_image;
};

