// ************************************************************************** //
//
//  Model-view-view-model framework for large GUI applications
//
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @authors   see AUTHORS
//
// ************************************************************************** //

#include "refldockwindow.h"
#include "dockscontroller.h"
#include <QLabel>

ReflDockWindow::ReflDockWindow(QWidget* parent)
    : QMainWindow(parent), docks_controller(new DocksController(this))

{
    setCentralWidget(new QLabel("Reflectometry docks"));
}
