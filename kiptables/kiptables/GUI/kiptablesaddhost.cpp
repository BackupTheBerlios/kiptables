/***************************************************************************
                          kiptablesaddhost.cpp  -  description
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

#include "kiptablesaddhost.h"

KIptablesAddHost::KIptablesAddHost(QWidget *parent, const char *name ) : KIptablesAddHostUI(parent,name,true) {
}
KIptablesAddHost::~KIptablesAddHost(){
}
/** No descriptions */
void KIptablesAddHost::setHostname(const QString &name){
	entryHost->setText(name);
}
/** No descriptions */
void KIptablesAddHost::setHostIp(const QString &ip){
	entryIpAddress->setText(ip);
}
/** No descriptions */
const QString & KIptablesAddHost::getHostname(){
	temp=entryHost->text();
	return temp;
}
/** No descriptions */
const QString & KIptablesAddHost::getHostIp(){
	temp1=entryIpAddress->text();
	return temp1;
}
