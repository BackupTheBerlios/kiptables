/***************************************************************************
                          kiptablessettings.h  -  description
                             -------------------
    begin                : Wed Nov 21 2001
    copyright            : (C) 2001 by Stephan Hermann
    email                : sh@sourcecode.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef KIPTABLESSETTINGS_H
#define KIPTABLESSETTINGS_H

#include <qwidget.h>
#include <kfiledialog.h>
#include <qlineedit.h>
#include "kiptablessettgingsui.h"

/**Settings Dialog Class
  *@author Stephan Hermann
  */

class KIptablesSettings : public KIptablesSettingsUI  {
   Q_OBJECT
public: 
	KIptablesSettings(QWidget *parent=0, const char *name=0);
	~KIptablesSettings();
  /** Sets the binary name to the settings dialog */
  void setBinary(const QString &bin);
  /** Get the binary name */
  const QString & getBinaryName();
private: // Private attributes
  /**  */
  QString iptablesBinary;
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotToolBtnSearch();
};

#endif
