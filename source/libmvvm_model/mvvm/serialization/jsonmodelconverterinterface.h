// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#ifndef MVVM_SERIALIZATION_JSONMODELCONVERTERINTERFACE_H
#define MVVM_SERIALIZATION_JSONMODELCONVERTERINTERFACE_H

#include <mvvm/model_export.h>

class QJsonObject;

namespace ModelView
{

class SessionModel;

//! Base class for all converters of SessionModel to/from json object.

class MVVM_MODEL_EXPORT JsonModelConverterInterface
{
public:
    virtual ~JsonModelConverterInterface() = default;

    virtual void model_to_json(const SessionModel&, QJsonObject&) const = 0;

    virtual void json_to_model(const QJsonObject&, SessionModel&) const = 0;
};

} // namespace ModelView

#endif // MVVM_SERIALIZATION_JSONMODELCONVERTERINTERFACE_H