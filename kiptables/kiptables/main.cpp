/***************************************************************************
                          main.cpp  -  description
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

#include <kcmdlineargs.h>
#include <kaboutdata.h>
#include <klocale.h>

#include "kiptables.h"
#include "Logic/kiptablesconfig.h"

static const char *description =
	I18N_NOOP("Kiptables");
// INSERT A DESCRIPTION FOR YOUR APPLICATION HERE
	
	
static KCmdLineOptions options[] =
{
  { 0, 0, 0 }
  // INSERT YOUR COMMANDLINE OPTIONS HERE
};

int main(int argc, char *argv[])
{

  KAboutData aboutData( "kiptables", I18N_NOOP("Kiptables"),
    VERSION, description, KAboutData::License_GPL,
    "(c) 2001, Stephan Hermann", 0, 0, "sh@sourcecode.de");
  aboutData.addAuthor("Stephan Hermann",0, "sh@sourcecode.de");
  KCmdLineArgs::init( argc, argv, &aboutData );
  KCmdLineArgs::addCmdLineOptions( options ); // Add our own options.

  KApplication a;
  KIptablesConfig *config=new KIptablesConfig();
  Kiptables *kiptables = new Kiptables(0,config);

  a.setMainWidget(kiptables);
  kiptables->show();

  return a.exec();

}
