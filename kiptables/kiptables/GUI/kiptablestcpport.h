/***************************************************************************
                          kiptablestcpport.h  -  description
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

#ifndef KIPTABLESTCPPORT_H
#define KIPTABLESTCPPORT_H

#include <qwidget.h>
#include "kiptablestcpportui.h"
#include <knuminput.h>
#include <qlineedit.h>

/**TCP Port Dialog Class
  *@author Stephan Hermann
  */

class KIPtablesTCPPort : public KIptablesTCPPortUI  {
   Q_OBJECT
public: 
	KIPtablesTCPPort(QWidget *parent=0, const char *name=0);
	~KIPtablesTCPPort();
  /** No descriptions */
  void setPortNo(const int port);
  /** No descriptions */
  void setPortName(const QString &name);
private: // Private attributes
public: // Public attributes
  /**  */
//Del von KDevelop:
  /** No descriptions */
  const QString & getPortName();
  /** No descriptions */
  const int getPortNo();
  /**  */
  QString temp;
  /**  */
  int temp1;
};

#endif
