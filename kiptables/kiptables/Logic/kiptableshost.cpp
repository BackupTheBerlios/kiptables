/***************************************************************************
                          kiptableshost.cpp  -  description
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

#include "kiptableshost.h"

KIptablesHost::KIptablesHost(const char *name,const char *ip){
	setHostname(QString(name));
	setHostIp(QString(ip));
}
KIptablesHost::~KIptablesHost(){
}
/** No descriptions */
void KIptablesHost::setHostname(const QString &name){
	hostName=name;
}
/** No descriptions */
void KIptablesHost::setHostIp(const QString &ip){
	hostIp=ip;
}
/** No descriptions */
const QString & KIptablesHost::getHostName(){
	return hostName;
}
/** No descriptions */
const QString & KIptablesHost::getHostIp(){
	return hostIp;
}
