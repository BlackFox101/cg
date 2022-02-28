#pragma once
#include <QtWidgets/QMainWindow>
#include "IGallowsGame.h"
#include "GallowsGameWithPicture.h";
#include "GallowsGameWithoutPicture.h";
#include <memory>

namespace Ui { class View; }

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(std::shared_ptr<IGallowsGame> game, QWidget* parent = nullptr);
    ~View();

private:
    Ui::View* ui;

    std::unique_ptr<GallowsGameWithPicture> m_viewWithPicture;
    std::unique_ptr<GallowsGameWithoutPicture> m_viewWithoutPicture;
};
