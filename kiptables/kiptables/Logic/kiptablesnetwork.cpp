/***************************************************************************
                          kiptablesnetwork.cpp  -  description
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

#include "kiptablesnetwork.h"

KIptablesNetwork::KIptablesNetwork(const char *name,const char *address){
	setNetworkName(QString(name));
	setNetworkAddress(QString(address));
}
KIptablesNetwork::~KIptablesNetwork(){
}
/** No descriptions */
void KIptablesNetwork::setNetworkName(const QString &name){
	networkName=name;
}
/** No descriptions */
void KIptablesNetwork::setNetworkAddress(const QString &address){
	networkAddress=address;
}
/** No descriptions */
const QString & KIptablesNetwork::getNetworkName(){
	return networkName;
}
/** No descriptions */
const QString & KIptablesNetwork::getNetworkAddress(){
	return networkAddress;
}
