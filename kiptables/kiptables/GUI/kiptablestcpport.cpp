/***************************************************************************
                          kiptablestcpport.cpp  -  description
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

#include "kiptablestcpport.h"

KIPtablesTCPPort::KIPtablesTCPPort(QWidget *parent, const char *name ) : KIptablesTCPPortUI(parent,name,true) {
	entryTCPPortNo->setRange(1,65535,1,true);
}
KIPtablesTCPPort::~KIPtablesTCPPort(){
}
/** No descriptions */
void KIPtablesTCPPort::setPortName(const QString &name){
	entryTCPPortName->setText(name);
}
/** No descriptions */
void KIPtablesTCPPort::setPortNo(const int port){
	entryTCPPortNo->setValue(port);
}
/** No descriptions */
const int KIPtablesTCPPort::getPortNo(){
	temp1=entryTCPPortNo->value();
	return temp1;
	
}
/** No descriptions */
const QString & KIPtablesTCPPort::getPortName(){
	temp=entryTCPPortName->text();
	return temp;
}
