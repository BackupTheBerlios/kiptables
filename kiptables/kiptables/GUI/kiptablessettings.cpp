/***************************************************************************
                          kiptablessettings.cpp  -  description
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

#include "kiptablessettings.h"

KIptablesSettings::KIptablesSettings(QWidget *parent, const char *name ) : KIptablesSettingsUI(parent,name,true) {
}
KIptablesSettings::~KIptablesSettings(){
}
/** No descriptions */
void KIptablesSettings::slotToolBtnSearch(){
	iptablesBinary=KFileDialog::getOpenFileName("","*|All Files",this,"Search IPTables Binary");
	entryIptablesBinary->setText(iptablesBinary);
}
/** Sets the binary name to the settings dialog */
void KIptablesSettings::setBinary(const QString &bin){
	iptablesBinary=bin;
	entryIptablesBinary->setText(iptablesBinary);
}
/** Get the binary name */
const QString & KIptablesSettings::getBinaryName(){
	iptablesBinary=entryIptablesBinary->text();
	return iptablesBinary;
}
