#ifndef __CONFIG_H__
#define __CONFIG_H__

#define VERSION           "@QTCURVE_VERSION_FULL@"
#define KDE3_ICONS_PREFIX "@KDE3_ICONS_PREFIX@"
#define KDE4_ICONS_PREFIX "@KDE4_ICONS_PREFIX@"
#define KDE3PREFIX        "@KDE3PREFIX@"
#define KDE4PREFIX        "@KDE4PREFIX@"
#define GTK_THEME_DIR     "@GTK_THEME_DIR@/gtk-2.0"

#cmakedefine QTC_ADD_EVENT_FILTER
#cmakedefine QTC_MODIFY_MOZILLA
#cmakedefine QTC_MODIFY_MOZILLA_USER_JS
#cmakedefine QTC_REORDER_GTK_DIALOG_BUTTONS
#cmakedefine QTC_OLD_MOZILLA
#cmakedefine QTC_DEFAULT_TO_KDE3
#cmakedefine QTC_USE_CAIRO_FOR_ARROWS
#cmakedefine QTC_STYLE_SUPPORT
#cmakedefine QTC_CAIRO_1_10_HACK

#endif
