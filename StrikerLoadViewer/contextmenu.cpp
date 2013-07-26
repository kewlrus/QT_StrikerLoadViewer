#include "contextmenu.h"

ContextMenu::ContextMenu(QListView *ListView,  VirtualListModel* VListModel, bool UsedProxy)
{
    this->ListView = ListView;
    this->VListModel = VListModel;
    this->UsedProxy = UsedProxy;
}


void ContextMenu::SetVirtualListModel(VirtualListModel* VListModel)
{
    this->VListModel = VListModel;
}

void ContextMenu::ShowContextMenu(const QPoint& pos)
{
    QPoint globalPos = ListView->mapToGlobal(pos);
    QItemSelectionModel* mdl = ListView->selectionModel();

    if (VListModel != NULL)
    {
        int RowIndex = mdl->currentIndex().row();

        SelectedString = mdl->currentIndex().data().toString();
        SelectedIndex  = RowIndex;

        if (SelectedIndex < 0)
        {
            this->actions().at(1)->setDisabled(true);
            this->actions().at(2)->setDisabled(true);
        }

        exec(globalPos);
    }
}

void ContextMenu::mousePressEvent(QMouseEvent *event)
{
     QPoint p = event->pos();
     if (!actionAt(p))
     {
         this->close();
         event->accept();
     }

     if (event->button() == Qt::LeftButton && VListModel != NULL)
     {
         bool CanDoAction = (actionAt(p) && actionAt(p)->isEnabled());

         if (CanDoAction)
         {
            if (actionAt(p)->text() == "New File")
            {
                emit NewFileActionClicked();
            }
            else
            {
                if (actionAt(p)->text() == "Delete File")
                {
                    emit DeleteFileActionClicked(SelectedString);
                }
                else
                {
                    if (actionAt(p)->text() == "New Function")
                    {
                        emit AddFunctionActionClicked();
                    }
                    else
                    {
                        if (actionAt(p)->text() == "Delete Function")
                        {
                            emit DeleteFunctionActionClicked(SelectedIndex);
                        }
                        else
                        {
                            if (actionAt(p)->text() == "New Appearence")
                            {
                                emit AddAppearenceActionClicked();
                            }
                            else
                            {
                                if (actionAt(p)->text() == "Delete Appearence")
                                {
                                    emit DeleteAppearenceActionClicked(SelectedIndex);
                                }
                                else
                                {
                                    if (actionAt(p)->text() == "New Property")
                                    {
                                        emit AddAppPropActionClicked();
                                    }
                                    else
                                    {
                                        if (actionAt(p)->text() == "Delete Property")
                                        {
                                            emit DeleteAppPropActionClicked(SelectedIndex);
                                        }
                                        else
                                        {
                                            if (actionAt(p)->text() == "Edit Property")
                                            {
                                                emit EditAppPropActionClicked(SelectedString, SelectedIndex, VListModel);
                                            }
                                            else
                                            {
                                                if (actionAt(p)->text() == "Edit Appearence")
                                                {
                                                    emit EditAppearenceActionClicked(SelectedString, SelectedIndex, VListModel);
                                                }
                                                else
                                                {
                                                    if (actionAt(p)->text() == "Edit Function")
                                                    {
                                                        emit EditFunctionActionClicked(SelectedString, SelectedIndex, VListModel);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            this->close();
            event->accept();
         }
     //   }
     }
 }
