#include "MockWidgets.h"
#include "sessionitem.h"
#include "obsoleteitemmapper.h"
#include "itemmapper.h"
#include "sessionmodel.h"
#include "modelmapper.h"


ObsoleteMockWidget::ObsoleteMockWidget(ModelView::SessionItem* item)
    : m_item(nullptr)
{
    setItem(item);
}

ObsoleteMockWidget::~ObsoleteMockWidget()
{
    if (m_item)
        m_item->obsolete_mapper()->unsubscribe(this);
}

void ObsoleteMockWidget::setItem(ModelView::SessionItem* item)
{
    m_item = item;

    if (m_item == nullptr)
        return;

    m_item->obsolete_mapper()->setOnItemDestroy([this](ModelView::SessionItem* item) {
        m_item = nullptr;
        onItemDestroy(item);
    }, this);

    m_item->obsolete_mapper()->setOnDataChange([this](ModelView::SessionItem* item, int role) {
        onDataChange(item, role);
    }, this);
}

// ----------------------------------------------------------------------------

MockWidgetForItem::MockWidgetForItem(ModelView::SessionItem* item)
    : m_item(nullptr)
{
    setItem(item);
}

MockWidgetForItem::~MockWidgetForItem()
{
    if (m_item)
        m_item->mapper()->unsubscribe(this);
}

void MockWidgetForItem::setItem(ModelView::SessionItem* item)
{
    m_item = item;

    if (m_item == nullptr)
        return;

    m_item->mapper()->setOnDataChange([this](ModelView::SessionItem* item, int role) {
        onDataChange(item, role);
    }, this);
}

// ----------------------------------------------------------------------------

MockWidgetForModel::MockWidgetForModel(ModelView::SessionModel* model)
    : m_model(nullptr)
{
    setModel(model);
}

MockWidgetForModel::~MockWidgetForModel()
{
    if (m_model)
        m_model->mapper()->unsubscribe(this);
}

void MockWidgetForModel::setModel(ModelView::SessionModel* model)
{
    m_model = model;

    if (m_model == nullptr)
        return;

    m_model->mapper()->setOnItemDestroy([this](ModelView::SessionItem* item) {
        onItemDestroy(item);
    }, this);

    m_model->mapper()->setOnDataChange([this](ModelView::SessionItem* item, int role) {
        onDataChange(item, role);
    }, this);

    m_model->mapper()->setOnRowInserted([this](ModelView::SessionItem* item, int row) {
        onRowInserted(item, row);
    }, this);

    m_model->mapper()->setOnRowRemoved([this](ModelView::SessionItem* item, int row) {
        onRowRemoved(item, row);
    }, this);
}

