/***************************************************************************
                          kiptables.cpp  -  description
                             -------------------
    begin                : Mit Nov 21 12:15:35 UTC 2001
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

#include "kiptables.h"

Kiptables::Kiptables(const char *name,KIptablesConfig *config) : KTMainWindow(name)
{
	setConfig(config);
	initView();
	initActions();
	createGUI();
}

Kiptables::~Kiptables()
{
	delete iptablesConfig;
}
/** Initialize Main View
 */
void Kiptables::initView(){
	KIptablesHost *host;
	KIptablesNetwork *network;
	KIptablesTCP *tcp;
	KIptablesUDP *udp;
	mainView=new KIptablesMain(this,"MainView");
	connect(mainView,SIGNAL(clickedFWObject(QListViewItem *)),this,SLOT(itemClicked(QListViewItem *)));
	connect(mainView,SIGNAL(FWObjectsSelChanged(QListViewItem *)),this,SLOT(FWObjectsSelChanged(QListViewItem *)));
	connect(mainView,SIGNAL(rightMouseClicked(QListViewItem *,const QPoint &,int)),this,SLOT(slotRightMouseButtonClicked(QListViewItem *,const QPoint &,int)));
	// Add Hosts
	if (iptablesConfig->getHostList()->count()>0) {
		for (host=iptablesConfig->getHostList()->first();host!=0;host=iptablesConfig->getHostList()->next()) {
			mainView->addHostObject(host->getHostName());
		}
	}
	// Add Network
	if (iptablesConfig->getNetworkList()->count()>0) {
		for (network=iptablesConfig->getNetworkList()->first();network!=0;network=iptablesConfig->getNetworkList()->next()) {
			mainView->addNetworkObject(network->getNetworkName());
		}
	}
	// Add TCP
	if (iptablesConfig->getTCPList()->count()>0) {
		for (tcp=iptablesConfig->getTCPList()->first();tcp!=0;tcp=iptablesConfig->getTCPList()->next()) {
			mainView->addTCP(tcp->getPortName());
		}
	}
	// Add UDP
	if (iptablesConfig->getUDPList()->count()>0) {
		for(udp=iptablesConfig->getUDPList()->first();udp!=0;udp=iptablesConfig->getUDPList()->next()) {
			mainView->addUDP(udp->getPortName());
		}
	}		
	
	setView(mainView);
	statusBar()->insertItem("",1,0);
}
/** Initialize Actions */
void Kiptables::initActions(){
	KStdAction::quit(this,SLOT(quitApplication()),actionCollection());
	settings=new KAction(i18n("&Settings"),CTRL+Key_S,this,SLOT(slotSettings()),actionCollection(),"conf_settings");
	actionHost=new KAction(i18n("Add &Host"),0L,this,SLOT(slotFWAddHost()),actionCollection(),"fw_add_host");
	actionHost->setEnabled(false);
	actionHostModify=new KAction(i18n("Modify H&ost"),0L,this,SLOT(slotFWModifyHost()),actionCollection(),"fw_modify_host");
	actionHostModify->setEnabled(false);
	actionHostDelete=new KAction(i18n("Delete Ho&st"),0L,this,SLOT(slotFWDeleteHost()),actionCollection(),"fw_delete_host");
	actionHostDelete->setEnabled(false);
	actionNetwork=new KAction(i18n("Add &Network"),0L,this,SLOT(slotFWAddNetwork()),actionCollection(),"fw_add_network");
	actionNetwork->setEnabled(false);
	actionNetworkModify=new KAction(i18n("Modify N&etwork"),0L,this,SLOT(slotFWModifyNetwork()),actionCollection(),"fw_modify_network");
	actionNetworkDelete=new KAction(i18n("Delete Ne&twork"),0L,this,SLOT(slotFWDeleteNetwork()),actionCollection(),"fw_delete_network");
	actionNetworkModify->setEnabled(false);
	actionNetworkDelete->setEnabled(false);
	actionTCP=new KAction(i18n("Add &TCP-Port"),0L,this,SLOT(slotFWAddTCPPort()),actionCollection(),"fw_add_tcp_port");
	actionTCP->setEnabled(false);
	actionUDP=new KAction(i18n("Add &UDP-Port"),0L,this,SLOT(slotFWAddUDPPort()),actionCollection(),"fw_add_udp_port");
	actionUDP->setEnabled(false);	
}
/** No descriptions */
void Kiptables::slotSettings(){
	KIptablesSettings *settingsDlg=new KIptablesSettings(this,"Settings");
	settingsDlg->setBinary(iptablesConfig->getIptablesBinary());
	if (settingsDlg->exec()) {
		iptablesConfig->setIptablesBinary(settingsDlg->getBinaryName());
	}
	delete settingsDlg;
}
/** Closes and Quits the Application */
void Kiptables::quitApplication(){
	close();
}

/** No descriptions */
void Kiptables::slotFWAddHost(){
	KIptablesAddHost *addHostDlg=new KIptablesAddHost(this,"AddHost");
	if (addHostDlg->exec()) {
		iptablesConfig->addHost(addHostDlg->getHostname(),addHostDlg->getHostIp());
		mainView->addHostObject(addHostDlg->getHostname());
	}
	delete addHostDlg;	
}
/** No descriptions */
void Kiptables::setConfig(KIptablesConfig *config){
	iptablesConfig=config;
}
/** No descriptions */
KIptablesMain * Kiptables::getMainView(){
	return mainView;
}
/** No descriptions */
void Kiptables::slotFWAddNetwork(){
	KIptablesAddNetwork *addNetworkDlg=new KIptablesAddNetwork(this,"AddNetwork");
	if (addNetworkDlg->exec()) {
		iptablesConfig->addNetwork(addNetworkDlg->getNetworkName(),addNetworkDlg->getNetworkAddress());
		mainView->addNetworkObject(addNetworkDlg->getNetworkName());
	}
	delete addNetworkDlg;
}
/** No descriptions */
void Kiptables::itemClicked(QListViewItem *item){
	KIptablesAddNetwork *updateNetwork;
	KIptablesNetwork *network;
	if (item->parent()!=0) {
		if (item->parent()->text(0)=="Host") {
			qWarning("Host "+item->text(0));
			item->setText(0,updateHostEntry(item->text(0))->getHostName());
		}
		if (item->parent()->text(0)=="Network") {
			qWarning("Network "+item->text(0));
			network=iptablesConfig->findNetwork(item->text(0));
			if (network!=0) {
				updateNetwork=new KIptablesAddNetwork(this,"UpdateNetwork");
				updateNetwork->setNetworkName(network->getNetworkName());
				updateNetwork->setNetworkAddress(network->getNetworkAddress());
				if(updateNetwork->exec()) {
					network->setNetworkName(updateNetwork->getNetworkName());
					network->setNetworkAddress(updateNetwork->getNetworkAddress());
					item->setText(0,updateNetwork->getNetworkName());
				}
				delete updateNetwork;
			}
		}
		if (item->parent()->text(0)=="TCP-Services") {
			qWarning("TCP-Service "+item->text(0));
		}
		if (item->parent()->text(0)=="UDP-Services") {
			qWarning("UDP-Service "+item->text(0));
		}
	}
}
/** No descriptions */
void Kiptables::slotFWAddTCPPort(){
	KIPtablesTCPPort *addTCPDlg=new KIPtablesTCPPort(this,"AddTCPPort");
	if (addTCPDlg->exec()) {
		iptablesConfig->addTCP(addTCPDlg->getPortName(),addTCPDlg->getPortNo());
		mainView->addTCP(addTCPDlg->getPortName());
	}
	delete addTCPDlg;	
}
/** No descriptions */
void Kiptables::slotFWAddUDPPort(){
	KIptablesUDPPort *addUDPDlg=new KIptablesUDPPort(this,"AddUDPPort");
	if (addUDPDlg->exec()) {
		iptablesConfig->addUDP(addUDPDlg->getPortName(),addUDPDlg->getPortNo());
		mainView->addUDP(addUDPDlg->getPortName());
	}
	delete addUDPDlg;
}

/** No descriptions */
void Kiptables::FWObjectsSelChanged(QListViewItem *item){
	if (item->text(0)=="Host"||(item->parent()!=NULL&&item->parent()->text(0)=="Host")) {
		// Host
		actionHost->setEnabled(true);		
		actionHostModify->setEnabled(true);
		actionHostDelete->setEnabled(true);
		// Network
		actionNetwork->setEnabled(false);
		actionNetworkModify->setEnabled(false);
		actionNetworkDelete->setEnabled(false);
		
		// TCP
		actionTCP->setEnabled(false);
		// UDP
		actionUDP->setEnabled(false);
	} else if(item->text(0)=="Network"||(item->parent()!=NULL&&item->parent()->text(0)=="Network")) {
		actionHost->setEnabled(false);
		actionHostModify->setEnabled(false);
		actionHostDelete->setEnabled(false);

		actionNetwork->setEnabled(true);
		actionNetworkModify->setEnabled(true);
		actionNetworkDelete->setEnabled(true);
		
		actionTCP->setEnabled(false);
		actionUDP->setEnabled(false);
	} else if (item->text(0)=="TCP-Ports"||(item->parent()!=NULL&&item->parent()->text(0)=="TCP-Ports")) {
		actionHost->setEnabled(false);
		actionHostModify->setEnabled(false);
		actionHostDelete->setEnabled(false);		
		actionNetwork->setEnabled(false);
		actionNetworkModify->setEnabled(false);
		actionNetworkDelete->setEnabled(false);	
		actionTCP->setEnabled(true);
		actionUDP->setEnabled(false);	
	} else if (item->text(0)=="UDP-Ports"||(item->parent()!=NULL&&item->parent()->text(0)=="UDP-Ports")) {
		actionHost->setEnabled(false);
		actionHostModify->setEnabled(false);
		actionHostDelete->setEnabled(false);		
		actionNetwork->setEnabled(false);
		actionNetworkModify->setEnabled(false);
		actionNetworkDelete->setEnabled(false);	
		actionTCP->setEnabled(false);
		actionUDP->setEnabled(true);	
	} else {
		actionHost->setEnabled(false);
		actionHostModify->setEnabled(false);
		actionHostDelete->setEnabled(false);		
		actionNetwork->setEnabled(false);
		actionNetworkModify->setEnabled(false);
		actionNetworkDelete->setEnabled(false);	
		actionTCP->setEnabled(false);
		actionUDP->setEnabled(false);
	}
}
/** No descriptions */
void Kiptables::slotRightMouseButtonClicked(QListViewItem *item,const QPoint &,int){
	
	if (item->text(0)=="Host") {
	}	
}
/** No descriptions */
void Kiptables::slotFWModifyHost(){
	if (mainView->lviewFWObjects->selectedItem()->parent()!=0&&mainView->lviewFWObjects->selectedItem()->parent()->text(0)=="Host") {
		mainView->lviewFWObjects->selectedItem()->setText(0,updateHostEntry(mainView->lviewFWObjects->selectedItem()->text(0))->getHostName());
	}
}
/** No descriptions */
//Del von KDevelop:void Kiptables::slotFWModifyHost(QListViewItem *){
//Del von KDevelop:}
/** No descriptions */
KIptablesHost *Kiptables::updateHostEntry(const char *name){
	KIptablesAddHost *updateHost;
	KIptablesHost *host;
	if (name!=0) {
		host=iptablesConfig->findHost(name);
		if (host!=0) {
			updateHost=new KIptablesAddHost(this,"UpdateHOst");
			updateHost->setHostname(host->getHostName());
			updateHost->setHostIp(host->getHostIp());
			if (updateHost->exec()) {
				host->setHostname(updateHost->getHostname());
				host->setHostIp(updateHost->getHostIp());
			}
			delete updateHost;
			return host;
		}
	}
	return 0;
}
