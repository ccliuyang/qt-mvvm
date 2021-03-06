// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef FLATEDITORCORE_DEMOWIDGET_H
#define FLATEDITORCORE_DEMOWIDGET_H

#include <QWidget>
#include <memory>

namespace ModelView
{
class SessionModel;
class AllItemsTreeView;
class PropertyTreeView;
class PropertyFlatView;
} // namespace ModelView

class QBoxLayout;

/*!
@class DemoWidget
@brief Demonstrates usage of PropertyFlatView.
*/

class DemoWidget : public QWidget
{
    Q_OBJECT
public:
    DemoWidget(ModelView::SessionModel* model, QWidget* parent = nullptr);
    ~DemoWidget();

private:
    QBoxLayout* create_left_layout();
    QBoxLayout* create_right_layout();

    void connect_views();

    ModelView::AllItemsTreeView* m_defaultTreeView;
    ModelView::PropertyTreeView* m_propertyTreeView;
    ModelView::PropertyFlatView* m_propertyFlatView;
    ModelView::SessionModel* m_sessionModel;
};

#endif // FLATEDITORCORE_DEMOWIDGET_H
