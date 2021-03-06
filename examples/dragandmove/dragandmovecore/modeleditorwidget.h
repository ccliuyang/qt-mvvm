// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef MODELEDITORWIDGET_H
#define MODELEDITORWIDGET_H

#include <QWidget>
#include <memory>

class SampleModel;
class ContainerEditorWidget;
class QToolBar;
class QAction;

/*!
@class ModelEditorWidget
@brief Shows model content as two table-like trees.

It is expected that model has two containers with demo items, left tree shows first container,
right tree the second. It is possible to drag-and-drop items between two containers.
*/

class ModelEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ModelEditorWidget(SampleModel* model = nullptr, QWidget* parent = nullptr);

    void setModel(SampleModel* model);

private slots:
    void onUndo();
    void onRedo();

private:
    void init_actions();

    QToolBar* m_toolBar;
    ContainerEditorWidget* m_leftWidget;
    ContainerEditorWidget* m_rightWidget;
    QAction* m_undoAction;
    QAction* m_redoAction;
    SampleModel* m_model;
};

#endif // MODELEDITORWIDGET_H
