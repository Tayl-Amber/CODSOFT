#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include<QListView>
#include<QStringListModel>
#include<QToolBar>


QT_BEGIN_NAMESPACE
namespace Ui {
class Todolist;
}
QT_END_NAMESPACE

class CTodolist : public QMainWindow
{
    Q_OBJECT

public:
    CTodolist();
protected slots:
    void onAdd();
    void onRemove();

private:
    QListView* m_pwPending = nullptr;
    QListView* m_pwCompleted = nullptr;

    QAction* m_pActAdd = nullptr;
    QAction* m_pActRemove = nullptr;
};
#endif // TODOLIST_H
