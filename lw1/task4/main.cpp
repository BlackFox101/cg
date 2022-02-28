#include "View.h"
#include <QtWidgets/QApplication>
#include "GallowsGame.h"
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::shared_ptr<IGallowsGame> model = std::make_shared<GallowsGame>();
    View w(model);
    w.show();
    return a.exec();
}
