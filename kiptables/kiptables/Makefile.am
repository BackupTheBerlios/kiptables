####### kdevelop will overwrite this part!!! (begin)##########
bin_PROGRAMS = kiptables
kiptables_SOURCES = kiptables.cpp main.cpp 
kiptables_LDADD   = ./GUI/libGUI.a ./Logic/libLogic.a  $(LIB_KFILE) $(LIB_KDEUI) $(LIB_KDECORE) $(LIB_QT) $(LIBSOCKET)

SUBDIRS = GUI Logic 

EXTRA_DIST = main.cpp kiptables.cpp kiptables.h kiptables.desktop lo32-app-kiptables.png lo16-app-kiptables.png kiptablesui.rc 

install-data-local:
	$(mkinstalldirs) $(kde_appsdir)/Applications/
	$(INSTALL_DATA) $(srcdir)/kiptables.desktop $(kde_appsdir)/Applications/kiptables.desktop
	$(mkinstalldirs) $(kde_icondir)/locolor/32x32/apps/
	$(INSTALL_DATA) $(srcdir)/lo32-app-kiptables.png $(kde_icondir)/locolor/32x32/apps/kiptables.png
	$(mkinstalldirs) $(kde_icondir)/locolor/16x16/apps/
	$(INSTALL_DATA) $(srcdir)/lo16-app-kiptables.png $(kde_icondir)/locolor/16x16/apps/kiptables.png

uninstall-local:
	-rm -f $(kde_appsdir)/Applications/kiptables.desktop
	-rm -f $(kde_icondir)/locolor/32x32/apps/kiptables.png
	-rm -f $(kde_icondir)/locolor/16x16/apps/kiptables.png

####### kdevelop will overwrite this part!!! (end)############
# this 10 paths are KDE specific. Use them:
# kde_htmldir       Where your docs should go to. (contains lang subdirs)
# kde_appsdir       Where your application file (.kdelnk) should go to. 
# kde_icondir       Where your icon should go to.
# kde_minidir       Where your mini icon should go to.
# kde_datadir       Where you install application data. (Use a subdir)
# kde_locale        Where translation files should go to.(contains lang subdirs)
# kde_cgidir        Where cgi-bin executables should go to.
# kde_confdir       Where config files should go to.
# kde_mimedir       Where mimetypes should go to.
# kde_toolbardir    Where general toolbar icons should go to.
# kde_wallpaperdir  Where general wallpapers should go to.

# set the include path for X, qt and KDE
INCLUDES= $(all_includes)

METASOURCES = AUTO

# the library search path. 
kiptables_LDFLAGS = $(all_libraries) $(KDE_RPATH)

# Uncomment the following two lines if you add a ui.rc file for your application to make use of
# KDE�s XML GUI builing
#rcdir = $(kde_datadir)/kiptables
#rc_DATA = kiptablesui.rc

#WARNING: if you use a ui.rc file above, use:

# messages: rc.cpp

# instead of 

# messages:

messages: 
	LIST=`find . -name \*.h -o -name \*.hh -o -name \*.H -o -name \*.hxx -o -name \*.hpp -o -name \*.cpp -o -name \*.cc -o -name \*.cxx -o -name \*.ecpp -o -name \*.C`; \
	if test -n "$$LIST"; then \
	 $(XGETTEXT) $$LIST -o $(podir)/kiptables.pot; \
	fi

