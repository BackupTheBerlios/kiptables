/***************************************************************************
                          kiptablesaddhost.h  -  description
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

#ifndef KIPTABLESADDHOST_H
#define KIPTABLESADDHOST_H

#include <qwidget.h>
#include <qlineedit.h>
#include "kiptablesaddhostui.h"

/**Add Host Dialog Class
  *@author Stephan Hermann
  */

class KIptablesAddHost : public KIptablesAddHostUI  {
   Q_OBJECT
public: 
	KIptablesAddHost(QWidget *parent=0, const char *name=0);
	~KIptablesAddHost();
  /** No descriptions */
  const QString & getHostIp();
  /** No descriptions */
  const QString & getHostname();
  /** No descriptions */
  void setHostIp(const QString &ip);
  /** No descriptions */
  void setHostname(const QString &name);
private: // Private attributes
  /**  */
  QString temp;
  /**  */
  QString temp1;
};

#endif
