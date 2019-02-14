// ************************************************************************** //
//
//  Prototype of mini MVVM framework for bornagainproject.org
//
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher
//
// ************************************************************************** //

#ifndef VIEWMODELINTERFACES_H
#define VIEWMODELINTERFACES_H

#include "global.h"
#include <QList>

class QStandardItem;

namespace ModelView {

class SessionItem;

//! Base class to construct row of QStandardItems from given SessionItem.

class CORE_EXPORT RowConstructorInterface
{
public:
    virtual ~RowConstructorInterface() = default;

    virtual QList<QStandardItem*> constructRow(SessionItem* item) = 0;
};

}  // namespace ModelView

#endif // VIEWMODELINTERFACES_H