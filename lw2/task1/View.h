#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_View.h"
#include "MainWidget.h"

class View : public QMainWindow
{
    Q_OBJECT
public:
    View(QWidget *parent = nullptr);

private slots:
    void OpenFile();

private:
    Ui::ViewClass ui;
};
