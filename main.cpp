#include "todo.h"
#include <QApplication>

/*
 * can add priority based dispaly of task.
 * can add check widget for task.
 * and many more.
 */

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    toDo app;
    app.show();

    return a.exec();
}
