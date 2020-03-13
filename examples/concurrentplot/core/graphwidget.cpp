// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include "graphwidget.h"
#include "graphmodel.h"
#include "graphpropertywidget.h"
#include <QAction>
#include <QBoxLayout>
#include <QToolBar>
#include <QToolButton>
#include <mvvm/model/modelutils.h>
#include <mvvm/plotting/graphcanvas.h>
#include <mvvm/standarditems/graphviewportitem.h>

using namespace ModelView;

GraphWidget::GraphWidget(GraphModel* model, QWidget* parent)
    : QWidget(parent), m_toolBar(new QToolBar),  m_graphCanvas(new GraphCanvas),
      m_propertyWidget(new GraphPropertyWidget), m_model(nullptr)
{
    auto mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(10);

    auto centralLayout = new QHBoxLayout;

    centralLayout->addWidget(m_graphCanvas, 3);
    centralLayout->addWidget(m_propertyWidget, 1);

    mainLayout->addWidget(m_toolBar);
    mainLayout->addLayout(centralLayout);

    setLayout(mainLayout);
    setModel(model);

    init_toolbar();
}

void GraphWidget::setModel(GraphModel* model)
{
    if (!model)
        return;

    m_model = model;

    m_propertyWidget->setModel(model);

    m_graphCanvas->setItem(Utils::TopItem<GraphViewportItem>(model));
}

void GraphWidget::init_toolbar()
{
    const int toolbar_icon_size = 24;
    m_toolBar->setIconSize(QSize(toolbar_icon_size, toolbar_icon_size));
}
