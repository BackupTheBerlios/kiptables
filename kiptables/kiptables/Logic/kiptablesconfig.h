/***************************************************************************
                          kiptablesconfig.h  -  description
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

#ifndef KIPTABLESCONFIG_H
#define KIPTABLESCONFIG_H

#include <qobject.h>
#include <qlist.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qregexp.h>
#include <kregexp.h>
#include <ksimpleconfig.h>
#include "kiptableshost.h"
#include "kiptablesnetwork.h"
#include "kiptablestcp.h"
#include "kiptablesudp.h"
#include "../GUI/kiptablesmain.h"

/**Configuration Class
  *@author Stephan Hermann
  */

class KIptablesConfig : public QObject  {
public: 
	KIptablesConfig();
	~KIptablesConfig();
  /** Read Configuration and set variables */
  void readConfig();
  /** Write Configuration */
  void writeConfig();
  /** No descriptions */
  const QString & getIptablesBinary();
  /** No descriptions */
  void setIptablesBinary(const QString &bin);
  /** No descriptions */
  void addHost(const QString &name,const QString &ip);
  /** No descriptions */
  QList<KIptablesHost> * getHostList();
  /** No descriptions */
  void setMainView(KIptablesMain *main);
  /** No descriptions */
  void addNetwork(const QString &name,const QString &address);
  /** No descriptions */
  QList<KIptablesNetwork> * getNetworkList();
  /** Find Host in Hostlist
 */
  KIptablesHost * findHost(const char *name);
  /** No descriptions */
  KIptablesNetwork * findNetwork(const char *name);
  /** No descriptions */
  void addUDP(const QString &name,const int no);
  /** No descriptions */
  void addTCP(const QString &name,const int no);
  /** No descriptions */
  QList<KIptablesUDP> * getUDPList();
  /** No descriptions */
  QList<KIptablesTCP> * getTCPList();
private: // Private attributes
  /**  */
  KSimpleConfig * simpleConfig;
  /**  */
  QString iptablesBinary;
  /**  */
  KIptablesMain * mainView;
  /**  */
  QList<KIptablesNetwork> * networkList;
  /**  */
  QList<KIptablesTCP> * tcpList;
  /**  */
  QList<KIptablesUDP> * udpList;
public: // Public attributes
  /**  */
  QList<KIptablesHost> * hostList;
private: // Private methods
  /** No descriptions */
  void readHostlist();
  /** No descriptions */
  void writeHostlist();
};

#endif
