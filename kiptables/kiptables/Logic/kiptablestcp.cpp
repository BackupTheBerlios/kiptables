/***************************************************************************
                          kiptablestcp.cpp  -  description
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

#include "kiptablestcp.h"

KIptablesTCP::KIptablesTCP(const char *name,const int no){
	portName=name;
	portNo=no;
}
KIptablesTCP::~KIptablesTCP(){
}
/** No descriptions */
void KIptablesTCP::setPortName(const QString &name){
	portName=name;
}
/** No descriptions */
void KIptablesTCP::setPortNo(const int nummer){
	portNo=nummer;
}
/** No descriptions */
const QString & KIptablesTCP::getPortName(){
	return portName;
}
/** No descriptions */
const int KIptablesTCP::getPortNo(){
	return portNo;
}
