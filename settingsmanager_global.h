#ifndef SETTINGSMANAGER_GLOBAL_H
#define SETTINGSMANAGER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SETTINGSMANAGER_LIBRARY)
#  define SETTINGSMANAGERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define SETTINGSMANAGERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // SETTINGSMANAGER_GLOBAL_H
