/***************************************************************************
                          kiptablesmain.h  -  description
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

#ifndef KIPTABLESMAIN_H
#define KIPTABLESMAIN_H

#include <qwidget.h>
#include <klocale.h>
#include <qlistview.h>
#include <qdragobject.h>
#include <klistview.h>
#include "kiptablesmainui.h"

/**MainView

  *@author Stephan Hermann
  */

class KIptablesMain : public KIptablesMainUI  {
   Q_OBJECT
public: 
	KIptablesMain(QWidget *parent=0, const char *name=0);
	~KIptablesMain();
  /** Add Host Object to listView */
  void addHostObject(const QString &name);
  /** No descriptions */
  void addNetworkObject(const QString &name);
  /** No descriptions */
  void addTCP(const QString &name);
  /** No descriptions */
  void addUDP(const QString &name);
private: // Private methods
  /** initialize lviewFWObjects */
  void initFWObjects();
  /** No descriptions */
  void initFWTables();
  /** No descriptions */

private: // Private attributes
  /**  */
  KListViewItem * hostItem;
  /**  */
  KListViewItem * networkItem;
  /**  */
  KListViewItem * tcpServices;
  /**  */
  KListViewItem* udpServices;
  /**  */
  KListViewItem * filter;
  /**  */
  KListViewItem * mangle;
  /**  */
  KListViewItem * filterINPUT;
  /**  */
  KListViewItem * nat;
  /**  */
  KListViewItem * filterOUTPUT;
  /**  */
  KListViewItem * filterFORWARD;
  /**  */
  KListViewItem * natPREROUTING;
  /**  */
  KListViewItem * natPOSTROUTING;
  /**  */
  KListViewItem * natOUTPUT;
  /**  */
  KListViewItem * manglePREROUTING;
signals: // Signals
  /** No descriptions */
  void clickedFWObject(QListViewItem *);
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotlviewFWObjectsClicked(QListViewItem *);
public: // Public attributes
  /**  */
  KListViewItem * mangleOUTPUT;
signals: // Signals
  /** No descriptions */
  /** No descriptions */
  void FWObjectsSelChanged(QListViewItem *);
  /** No descriptions */
  void rightMouseClicked(QListViewItem *,const QPoint &,int);

protected slots: // Protected slots
  /** No descriptions */

protected slots: // Protected slots
  /** No descriptions */
  virtual void slotFWObjectsSelChanged(QListViewItem *);
protected slots: // Protected slots
  /** No descriptions */
  virtual void slotFWObjectsRightMouse(QListViewItem *,const QPoint &,int);
};

#endif
