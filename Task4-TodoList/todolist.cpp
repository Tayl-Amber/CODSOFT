#include "todolist.h"
#include "ui_todolist.h"

#include<QLabel>
#include<QTabBar>
#include<QBoxLayout>

CTodolist::CTodolist()
{
    QWidget* pWidget = new QWidget(this);
    pWidget->setStyleSheet("background-color: #ECF01");
    setCentralWidget(pWidget);

    QVBoxLayout* pMainLayout = new QVBoxLayout();
    pWidget->setLayout(pMainLayout);

    QLabel* pwTitle = new QLabel("To Do List", this);
    pMainLayout->addWidget(pwTitle);
    pwTitle->setAlignment((Qt::AlignCenter));
    pwTitle->setStyleSheet("font-size:30pt; margin:10%");

    QHBoxLayout* pHLayoutLabels = new QHBoxLayout();
    pMainLayout->addLayout(pHLayoutLabels);

    QLabel* plblPending = new QLabel("Pending", this);
    plblPending->setStyleSheet("font-size :15pt");
    pHLayoutLabels->addWidget(plblPending);

    QLabel* plblCompleted = new QLabel("Completed", this);
    plblCompleted->setStyleSheet("font-size :15pt");
    pHLayoutLabels->addWidget(plblCompleted);

    QHBoxLayout* PHLayout = new QHBoxLayout();
    pMainLayout->addLayout(PHLayout);

    m_pwPending = new QListView(this);
    m_pwPending->setDragEnabled(true);
    m_pwPending->setAcceptDrops(true);
    m_pwPending->setDropIndicatorShown(true);
    m_pwPending->setDefaultDropAction(Qt::MoveAction);
    PHLayout->addWidget(m_pwPending);

    m_pwCompleted = new QListView(this);
  m_pwCompleted->setDragEnabled(true);
   m_pwCompleted->setAcceptDrops(true);
    m_pwCompleted->setDropIndicatorShown(true);
   m_pwCompleted->setDefaultDropAction(Qt::MoveAction);
    PHLayout->addWidget(m_pwCompleted);

   m_pwPending->setModel(new QStringListModel());
    m_pwCompleted->setModel(new QStringListModel());

   m_pwPending->setStyleSheet
   ("QListView {font-size: 20pt; font-weight: bold}"
    "QListView::{background-color: #E74C3C; padding: 10%;"
    "border: 1px solid #C0392B;}"
    "QListView::item::hover{backgroung-color: #C0392B}");

    m_pwCompleted->setStyleSheet
        ("QListView {font-size: 20pt; font-weight: bold}"
         "QListView::{background-color: #2ECC71; padding: 10%;"
         "border: 1px solid #27AE60;}"
       "QListView::item::hover{backgroung-color: #27AE60}");

   QToolBar* pToolBar = new QToolBar(this);
   addToolBar(pToolBar);

   m_pActAdd = new QAction(this);
   m_pActAdd-> setIcon(QIcon(":/resources/add.png"));
   connect(m_pActAdd, &QAction::triggered, this, &CTodolist::onAdd);

   m_pActRemove = new QAction(this);
   m_pActRemove-> setIcon(QIcon(":/resources/remove.png"));
   connect(m_pActRemove, &QAction::triggered, this, &CTodolist::onRemove);

   pToolBar->addAction(m_pActAdd);
   pToolBar->addAction(m_pActRemove);

}

void CTodolist::onAdd()
{
    m_pwPending->model()->insertRow(m_pwPending->model()->rowCount());
    QModelIndex oIndex = m_pwPending->model()->index(m_pwPending->model()->rowCount()-1, 0);
    m_pwPending->edit(oIndex);
}

void CTodolist::onRemove()
{
    QModelIndex oIndex = m_pwPending->currentIndex();
    m_pwPending->model()->removeRow(oIndex.row());
}

