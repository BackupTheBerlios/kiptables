/***************************************************************************
                          kiptablesaddnetwork.h  -  description
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

#ifndef KIPTABLESADDNETWORK_H
#define KIPTABLESADDNETWORK_H

#include <qwidget.h>
#include <qlineedit.h>
#include "kiptablesaddnetworkui.h"

/**
  *@author Stephan Hermann
  */

class KIptablesAddNetwork : public KIptablesAddNetworkUI  {
   Q_OBJECT
public: 
	KIptablesAddNetwork(QWidget *parent=0, const char *name=0);
	~KIptablesAddNetwork();
  /** No descriptions */
  const QString & getNetworkAddress();
  /** No descriptions */
  const QString & getNetworkName();
  /** No descriptions */
  void setNetworkAddress(const QString &address);
  /** No descriptions */
  void setNetworkName(const QString &name);

private: // Private attributes
  /**  */
  QString temp;
  /**  */
  QString temp1;
};

#endif
