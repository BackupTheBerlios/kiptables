/***************************************************************************
                          kiptables.h  -  description
                             -------------------
    begin                : Mit Nov 21 12:15:35 UTC 2001
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

#ifndef KIPTABLES_H
#define KIPTABLES_H

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <kapp.h>
#include <qlist.h>
#include <ktmainwindow.h>
#include <kaction.h>
#include <kstdaction.h>
#include <klocale.h>
#include "GUI/kiptablesmain.h"
#include "GUI/kiptablessettings.h"
#include "GUI/kiptablesaddhost.h"
#include "GUI/kiptablesaddnetwork.h"
#include "GUI/kiptablestcpport.h"
#include "GUI/kiptablesudpport.h"
#include "Logic/kiptablesconfig.h"
#include "Logic/kiptableshost.h"
#include "Logic/kiptablestcp.h"
#include "Logic/kiptablesudp.h"

/** Kiptables is the base class of the project */
class Kiptables : public KTMainWindow
{
  Q_OBJECT 
  public:
    /** construtor */
    Kiptables(const char *name=0,KIptablesConfig *config=0);
    /** destructor */
    ~Kiptables();
  /** No descriptions */
  KIptablesMain * getMainView();
  /** No descriptions */
  void setConfig(KIptablesConfig *config);
private: // Private methods
  /** Initialize Main View
 */
  void initView();
  /** Initialize Actions */
  void initActions();
  /** No descriptions */
KIptablesHost *updateHostEntry(const char *name=0);
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotSettings();
protected slots: // Protected slots
  /** Closes and Quits the Application */
  virtual void quitApplication();
private: // Private attributes
  /** global iptables configuration object
 */
  KIptablesConfig * iptablesConfig;
  /**  */
  KAction * settings;
  /**  */
  KIptablesMain * mainView;
  /**  */
  KAction * actionHost;
  /**  */
  KAction * actionNetwork;
  /**  */
  KAction * actionTCP;
  /**  */
  KAction * actionUDP;
  /**  */
  KAction * actionHostModify;
  /**  */
  KAction * actionHostDelete;
  /**  */
  KAction * actionNetworkModify;
  /**  */
  KAction * actionNetworkDelete;
protected slots: // Protected slots
  /** Update StatusBar */
//Del von KDevelop:
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotFWAddHost();
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotFWAddNetwork();
protected slots: // Protected slots
  /** No descriptions */
  virtual void itemClicked(QListViewItem *);
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotFWAddTCPPort();
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotFWAddUDPPort();
protected slots: // Protected slots
  /** No descriptions */

protected slots: // Protected slots
  /** No descriptions */
  virtual void FWObjectsSelChanged(QListViewItem *);
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotRightMouseButtonClicked(QListViewItem *,const QPoint &,int);
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotFWModifyHost();
protected slots: // Protected slots
  /** No descriptions */

};

#endif
