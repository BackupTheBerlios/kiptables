/***************************************************************************
                          kiptablesudpport.h  -  description
                             -------------------
    begin                : Thu Nov 22 2001
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

#ifndef KIPTABLESUDPPORT_H
#define KIPTABLESUDPPORT_H

#include <qwidget.h>
#include "kiptablesudpportui.h"
#include <knuminput.h>
#include <qlineedit.h>

/**UDP Port Dialog Class

  *@author Stephan Hermann
  */

class KIptablesUDPPort : public KIptablesUDPPortUI  {
   Q_OBJECT
public: 
	KIptablesUDPPort(QWidget *parent=0, const char *name=0);
	~KIptablesUDPPort();
  /** No descriptions */
  const int getPortNo();
  /** No descriptions */
  const QString & getPortName();
  /** No descriptions */
  void setPortNo(const int nummer);
  /** No descriptions */
  void setPortName(const QString &name);
private: // Private attributes
  /**  */
  QString temp;
  /**  */
  int temp1;
};

#endif
