/***************************************************************************
                          kiptablesconfig.cpp  -  description
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

#include "kiptablesconfig.h"

KIptablesConfig::KIptablesConfig(){
	simpleConfig=new KSimpleConfig("kiptablesrc");
	hostList=new QList<KIptablesHost>();
	networkList=new QList<KIptablesNetwork>();
	tcpList=new QList<KIptablesTCP>();
	udpList=new QList<KIptablesUDP>();
	readConfig();
	readHostlist();
}

KIptablesConfig::~KIptablesConfig(){
	writeConfig();
	writeHostlist();
	delete tcpList;
	delete udpList;
	delete networkList;
	delete hostList;
	delete simpleConfig;
}
/** No descriptions */
void KIptablesConfig::setIptablesBinary(const QString &bin){
	iptablesBinary=bin;
}

/** No descriptions */
const QString & KIptablesConfig::getIptablesBinary(){
	return iptablesBinary;
}
/** Write Configuration */
void KIptablesConfig::writeConfig(){
	simpleConfig->setGroup("Main Settings");
	simpleConfig->writeEntry("Iptables_Binary",getIptablesBinary());
}
/** Read Configuration and set variables */
void KIptablesConfig::readConfig(){
	simpleConfig->setGroup("Main Settings");
	setIptablesBinary(simpleConfig->readEntry("Iptables_Binary","/sbin/iptables"));
}
/** No descriptions */
void KIptablesConfig::addHost(const QString &name,const QString &ip){
	hostList->append(new KIptablesHost(name,ip));
}
/** No descriptions */
QList<KIptablesHost> * KIptablesConfig::getHostList(){
	return hostList;
}
/** No descriptions */
void KIptablesConfig::writeHostlist(){
	QFile *fp=new QFile("test.txt");
	KIptablesHost *host;
	KIptablesNetwork *network;
	KIptablesTCP *tcp;
	KIptablesUDP *udp;
	if (fp->open(IO_ReadWrite)) {
		QTextStream *stream=new QTextStream(fp);
		for ( host=hostList->first(); host != 0; host=hostList->next() ) {
            *stream << "Host " << host->getHostName() << ";" << host->getHostIp() << "\n";
		}
		for ( network=networkList->first();network!=0;network=networkList->next()) {
			*stream << "Network " << network->getNetworkName() << ";" << network->getNetworkAddress() << "\n";
		}
		for (tcp=tcpList->first();tcp!=0;tcp=tcpList->next()) {
			*stream << "TCPService " << tcp->getPortName() << ";" << tcp->getPortNo() << "\n";
		}
		for (udp=udpList->first();udp!=0;udp=udpList->next()) {
			*stream << "UDPService " << udp->getPortName() << ";" << udp->getPortNo() << "\n";
		}
	}
	fp->close();	
	
}
/** No descriptions */
void KIptablesConfig::setMainView(KIptablesMain *main){
	mainView=main;
}
/** No descriptions */
void KIptablesConfig::readHostlist(){
	QString temp;
	QFile *fp=new QFile("test.txt");	
	KRegExp *reg;
	reg=new KRegExp("(Host|Network|TCPService|UDPService) (.+?);(.+*)","i");
	if (fp->open(IO_ReadWrite)) {
		QTextStream *stream=new QTextStream(fp);
		while (!stream->eof()) {
			temp=stream->readLine();
			if (reg->match(temp)) {
				qWarning("%s => Name: %s  IP: %s",reg->group(1),reg->group(2),reg->group(3));
				if(QString(reg->group(1)).contains("Host")) {
					hostList->append(new KIptablesHost(reg->group(2),reg->group(3)));
				}
				if (QString(reg->group(1)).contains("Network")) {
					networkList->append(new KIptablesNetwork(reg->group(2),reg->group(3)));
				}
				if (QString(reg->group(1)).contains("TCPService")) {
					tcpList->append(new KIptablesTCP(reg->group(2),QString(reg->group(3)).toInt()));
				}
				if (QString(reg->group(1)).contains("UDPService")) {
					udpList->append(new KIptablesUDP(reg->group(2),QString(reg->group(3)).toInt()));
				}
			}
		}
	}
	fp->close();
	delete reg;
}
/** No descriptions */
void KIptablesConfig::addNetwork(const QString &name,const QString &address){
	networkList->append(new KIptablesNetwork(name,address));
}
/** No descriptions */
QList<KIptablesNetwork> * KIptablesConfig::getNetworkList(){
	return networkList;
}
/** Find Host in Hostlist
 */
KIptablesHost * KIptablesConfig::findHost(const char *name){
	KIptablesHost *host;
	for (host=hostList->first();host!=0;host=hostList->next()) {
		if (host->getHostName()==name) {
			return host;
		}
	}
	return 0L;
}
/** No descriptions */
KIptablesNetwork * KIptablesConfig::findNetwork(const char *name){
	KIptablesNetwork *network;
	for(network=networkList->first();network!=0;network=networkList->next()){
		if (network->getNetworkName()==name) {
			return network;
		}
	}
	return 0L;
}
/** No descriptions */
QList<KIptablesTCP> * KIptablesConfig::getTCPList(){
	return tcpList;
}
/** No descriptions */
QList<KIptablesUDP> * KIptablesConfig::getUDPList(){
	return udpList;
}
/** No descriptions */
void KIptablesConfig::addTCP(const QString &name,const int no){
	tcpList->append(new KIptablesTCP(name,no));
}
/** No descriptions */
void KIptablesConfig::addUDP(const QString &name,const int no){
	udpList->append(new KIptablesUDP(name,no));
}
