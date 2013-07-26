#include "contexmmenu.h"

ContextMenu::ContextMenu(QWidget *parent = 0) : QMenu(parent)
{
}

//void ContextMenu::ShowContextMenuFileList(const QPoint& pos) // this is a slot
//{
    // for most widgets
    /*QPoint globalPos = FileListView->mapToGlobal(pos);
    // for QAbstractScrollArea and derived classes you would use:
    // QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);

    // ...
  //  connect(&myMenu, SIGNAL(hovered(QAction*)),
  //      this, SLOT(ContextMenuFileListTriggered(QAction *action)));

    QAction* selectedItem = exec(globalPos);
    if (selectedItem)
    {
        // something was chosen, do stuff
    }
    else
    {
        // nothing was chosen
    }*/
//}
