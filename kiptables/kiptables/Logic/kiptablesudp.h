/***************************************************************************
                          kiptablesudp.h  -  description
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

#ifndef KIPTABLESUDP_H
#define KIPTABLESUDP_H

#include <qobject.h>

/**UDP Port Class
  *@author Stephan Hermann
  */

class KIptablesUDP : public QObject  {
public: 
	KIptablesUDP(const char *name=0,const int no=0);
	~KIptablesUDP();
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
  QString portName;
  /**  */
  int portNo;
};

#endif
