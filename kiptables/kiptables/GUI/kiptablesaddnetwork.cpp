/***************************************************************************
                          kiptablesaddnetwork.cpp  -  description
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

#include "kiptablesaddnetwork.h"

KIptablesAddNetwork::KIptablesAddNetwork(QWidget *parent, const char *name ) : KIptablesAddNetworkUI(parent,name,true) {
}
KIptablesAddNetwork::~KIptablesAddNetwork(){
}
/** No descriptions */
void KIptablesAddNetwork::setNetworkName(const QString &name){
	entryNetworkName->setText(name);
}
/** No descriptions */
void KIptablesAddNetwork::setNetworkAddress(const QString &address){
	entryNetworkAddress->setText(address);
}
/** No descriptions */
const QString & KIptablesAddNetwork::getNetworkName(){
	temp=entryNetworkName->text();
	return temp;
}
/** No descriptions */
const QString & KIptablesAddNetwork::getNetworkAddress(){
	temp1=entryNetworkAddress->text();
	return temp1;
}
