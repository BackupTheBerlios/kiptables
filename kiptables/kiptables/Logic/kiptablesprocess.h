/***************************************************************************
                          kiptablesprocess.h  -  description
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

#ifndef KIPTABLESPROCESS_H
#define KIPTABLESPROCESS_H

#include <qobject.h>
#include <kprocess.h>
#include <kregexp.h>

/**Process IPTables Output
  *@author Stephan Hermann
  */

class KIptablesProcess : public QObject  {
public: 
	KIptablesProcess();
	~KIptablesProcess();
private: // Private attributes
  /**  */
  KProcess * iptablesProc;
};

#endif
