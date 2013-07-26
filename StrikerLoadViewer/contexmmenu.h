#ifndef CONTEXTMMENU_H
#define CONTEXTMMENU_H

#include <QMenu>
#include <QListView>

class ContextMenu : public QMenu
{
    Q_OBJECT
private:
  QListView *ListView;

public:
    explicit ContextMenu(QWidget *parent = 0);
    
signals:
    
//public slots:
//    void ShowContextMenuFileList(const QPoint& pos);
};

#endif // CONTEXTMMENU_H
