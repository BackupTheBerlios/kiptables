/***************************************************************************
                          kiptableshost.h  -  description
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

#ifndef KIPTABLESHOST_H
#define KIPTABLESHOST_H

#include <qobject.h>

/**Host Object
  *@author Stephan Hermann
  */

class KIptablesHost : public QObject  {
public: 
	KIptablesHost(const char *name=0,const char *ip=0);
	~KIptablesHost();
  /** No descriptions */
  void setHostname(const QString &name);
  /** No descriptions */
  const QString & getHostIp();
  /** No descriptions */
  const QString & getHostName();
  /** No descriptions */
  void setHostIp(const QString &ip);
private: // Private attributes
  /**  */
  QString hostName;
  /**  */
  QString hostIp;
};

#endif
