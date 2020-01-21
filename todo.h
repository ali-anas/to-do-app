#ifndef TODO_H
#define TODO_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>

//namespace Ui {
//class toDo;
//}

class toDo : public QMainWindow
{
    Q_OBJECT

public:
//    explicit toDo(QWidget *parent = nullptr);
//    ~toDo();
    toDo();

protected slots:
    void onAdd();
    void onRemove();


private:
//    Ui::toDo *ui;
    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;

    QAction* m_pActAdd = nullptr;
    QAction* m_pActRemove = nullptr;
};

#endif // TODO_H
