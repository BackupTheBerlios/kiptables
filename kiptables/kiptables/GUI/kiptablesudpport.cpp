/***************************************************************************
                          kiptablesudpport.cpp  -  description
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

#include "kiptablesudpport.h"

KIptablesUDPPort::KIptablesUDPPort(QWidget *parent, const char *name ) : KIptablesUDPPortUI(parent,name,true) {
	entryPortNo->setRange(1,65535,1,true);
}
KIptablesUDPPort::~KIptablesUDPPort(){
}
/** No descriptions */
void KIptablesUDPPort::setPortName(const QString &name){
	entryPortName->setText(name);
}
/** No descriptions */
void KIptablesUDPPort::setPortNo(const int nummer){
	entryPortNo->setValue(nummer);
}
/** No descriptions */
const QString & KIptablesUDPPort::getPortName(){
	temp=entryPortName->text();
	return temp;
}
/** No descriptions */
const int KIptablesUDPPort::getPortNo(){
	temp1=entryPortNo->value();
	return temp1;
}
