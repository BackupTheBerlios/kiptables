/***************************************************************************
                          kiptablesmain.cpp  -  description
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

#include "kiptablesmain.h"

KIptablesMain::KIptablesMain(QWidget *parent, const char *name ) : KIptablesMainUI(parent,name) {
	setAcceptDrops(true);
	initFWObjects();
	initFWTables();
}



KIptablesMain::~KIptablesMain(){
}
/** Add Host Object to listView */
void KIptablesMain::addHostObject(const QString &name){
	new QListViewItem(hostItem,name);
	lviewFWObjects->setOpen(hostItem,true);
}

/** No descriptions */
void KIptablesMain::addNetworkObject(const QString &name){	
	new QListViewItem(networkItem,name);
	lviewFWObjects->setOpen(networkItem,true);
}

/** initialize lviewFWObjects */
void KIptablesMain::initFWObjects(){
	lviewFWObjects->setDragEnabled(true);
	lviewFWObjects->setSorting(-1,false);
	udpServices=new KListViewItem(lviewFWObjects,i18n("UDP-Ports"));
	tcpServices=new KListViewItem(lviewFWObjects,i18n("TCP-Ports"));
	networkItem=new KListViewItem(lviewFWObjects,i18n("Network"));
	hostItem=new KListViewItem(lviewFWObjects,i18n("Host"));
}
/** No descriptions */
void KIptablesMain::initFWTables(){
	// lviewFWTables->setDragEnabled(true);
	lviewFWTables->setAcceptDrops(true);
	lviewFWTables->setSorting(-1,false);
	mangle=new KListViewItem(lviewFWTables,i18n("Mangle"));
	manglePREROUTING=new KListViewItem(mangle,i18n("PreRouting"));
	mangleOUTPUT=new KListViewItem(mangle,i18n("Output"));
	nat=new KListViewItem(lviewFWTables,i18n("NAT"));
	natPREROUTING=new KListViewItem(nat,i18n("PreRouting"));
	natPOSTROUTING=new KListViewItem(nat,i18n("PostRouting"));
	natOUTPUT=new KListViewItem(nat,i18n("Output"));
	filter=new KListViewItem(lviewFWTables,i18n("Filter"));
	filterOUTPUT=new KListViewItem(filter,i18n("Input"));
	filterFORWARD=new KListViewItem(filter,i18n("Forward"));
	filterINPUT=new KListViewItem(filter,i18n("Input"));
}

/** No descriptions */
void KIptablesMain::slotlviewFWObjectsClicked(QListViewItem *item){
	emit(clickedFWObject(item));
}

/** No descriptions */
void KIptablesMain::slotFWObjectsSelChanged(QListViewItem *item){
	emit(FWObjectsSelChanged(item));
}
/** No descriptions */
void KIptablesMain::addTCP(const QString &name){
	new QListViewItem(tcpServices,name);
	lviewFWObjects->setOpen(tcpServices,true);
}
/** No descriptions */
void KIptablesMain::addUDP(const QString &name){
	new QListViewItem(udpServices,name);
	lviewFWObjects->setOpen(udpServices,true);
}
/** No descriptions */
void KIptablesMain::slotFWObjectsRightMouse(QListViewItem *item,const QPoint &pt,int row){
	emit(rightMouseClicked(item,pt,row));
}
