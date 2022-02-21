#pragma once
#include <QtWidgets/QMainWindow>

namespace Ui { class View; }

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget* parent = nullptr);
    ~View();

private:
    Ui::View* ui;
};
