#include "todo.h"
//#include "ui_todo.h"

#include <QLabel>
#include <QToolBar>
#include <QBoxLayout>

// constructor
toDo::toDo() {
    QWidget* pWidget = new QWidget(this);
    pWidget -> setStyleSheet("background-color: #ECF0F1");
    setCentralWidget(pWidget);

    QVBoxLayout* pMainLayout = new QVBoxLayout();
    pWidget -> setLayout(pMainLayout);

    QLabel* pwTitle = new QLabel("To Do List", this);
    pMainLayout -> addWidget(pwTitle);
    pwTitle -> setAlignment(Qt::AlignCenter);
    pwTitle -> setStyleSheet("font-size: 30pt; margin: 10%;");

    QHBoxLayout* pHLayoutLabels = new QHBoxLayout();
    pMainLayout -> addLayout(pHLayoutLabels);

    QLabel* plblPending = new QLabel("Pending", this);
    plblPending -> setStyleSheet("font-size: 15pt;");
    pHLayoutLabels -> addWidget(plblPending);

    QLabel* plblCompleted = new QLabel("Completed", this);
    plblCompleted -> setStyleSheet("font-size: 15pt;");
    pHLayoutLabels -> addWidget(plblCompleted);

    QHBoxLayout* pHLayout = new QHBoxLayout();
    pMainLayout -> addLayout(pHLayout);

    m_pwPending = new QListView(this);
    m_pwPending -> setDragEnabled(true);
    m_pwPending -> setAcceptDrops(true);
    m_pwPending -> setDropIndicatorShown(true);
    m_pwPending -> setDefaultDropAction(Qt::MoveAction);
    pHLayout -> addWidget(m_pwPending);

    m_pwCompleted = new QListView(this);
    m_pwCompleted -> setDragEnabled(true);
    m_pwCompleted -> setAcceptDrops(true);
    m_pwCompleted -> setDropIndicatorShown(true);
    m_pwCompleted-> setDefaultDropAction(Qt::MoveAction);
    pHLayout -> addWidget(m_pwCompleted);

    m_pwPending -> setModel(new QStringListModel());
    m_pwCompleted -> setModel(new QStringListModel());

    m_pwPending -> setStyleSheet
            ("QListView { font-size: 20pt; font-weight: bold; }"
             "QListView::item { background-color: #E3280A; padding: 10%;"
             "border: 1px solid #E12103; }"
             "QListView::item::hover { background-color: #E12103 }");

    m_pwCompleted -> setStyleSheet
            ("QListView { font-size: 20pt; font-weight: bold; }"
             "QListView::item { background-color: #2FD100; padding: 10%;"
             "border: 1px solid #2FB807; }"
             "QListView::item::hover { background-color: #2FB807 }");

    QToolBar* pToolBar = new QToolBar(this);
    addToolBar(pToolBar);

    m_pActAdd = new QAction(this);
    m_pActAdd -> setIcon(QIcon(":/add.png"));
    connect(m_pActAdd, &QAction::triggered, this, &toDo::onAdd);

    m_pActRemove = new QAction(this);
    m_pActRemove -> setIcon(QIcon(":/delete.png"));
    connect(m_pActRemove, &QAction::triggered, this, &toDo::onRemove);

    pToolBar -> addAction(m_pActAdd);
    pToolBar -> addAction(m_pActRemove);

}

/*
 * TODO:
 *  removing a task is done only on pending side.
 *  have to make remove functionality work on both sides.
 */

void toDo::onAdd() {
    m_pwPending -> model() -> insertRow(m_pwPending -> model() -> rowCount());
    QModelIndex oIndex = m_pwPending -> model() -> index(
                m_pwPending -> model() -> rowCount()-1, 0);
    m_pwPending -> edit(oIndex);
}

void toDo::onRemove() {
    QModelIndex oIndex = m_pwCompleted -> currentIndex();
    m_pwCompleted -> model() -> removeRow(oIndex.row());
}
