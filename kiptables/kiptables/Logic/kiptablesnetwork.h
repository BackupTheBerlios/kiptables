/***************************************************************************
                          kiptablesnetwork.h  -  description
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

#ifndef KIPTABLESNETWORK_H
#define KIPTABLESNETWORK_H

#include <qobject.h>

/**KIptables Network Class
  *@author Stephan Hermann
  */

class KIptablesNetwork : public QObject  {
public: 
	KIptablesNetwork(const char *name=0,const char *address=0);
	~KIptablesNetwork();
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
  QString networkName;
  /**  */
  QString networkAddress;
protected slots: // Protected slots
  /** No descriptions */
//Del von KDevelop:
signals: // Signals
  /** No descriptions */

};

#endif
