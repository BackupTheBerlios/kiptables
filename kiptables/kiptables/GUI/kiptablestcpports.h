/****************************************************************************
** Form interface generated from reading ui file './kiptablestcpports.ui'
**
** Created: Thu Nov 22 13:23:01 2001
**      by:  The User Interface Compiler (uic)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/
#ifndef KIPTABLESTCPPORTSUI_H
#define KIPTABLESTCPPORTSUI_H

#include <qvariant.h>
#include <qdialog.h>
class QVBoxLayout; 
class QHBoxLayout; 
class QGridLayout; 
class KIntNumInput;
class QLabel;
class QLineEdit;
class QPushButton;

class KIptablesTCPPortsUI : public QDialog
{ 
    Q_OBJECT

public:
    KIptablesTCPPortsUI( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~KIptablesTCPPortsUI();

    QLineEdit* entryTCPPortName;
    KIntNumInput* entryTCPPortNo;
    QLabel* TextLabel2;
    QPushButton* btnOk;
    QPushButton* btnHelp;
    QPushButton* btnCancel;
    QLabel* TextLabel1;

protected:
    QGridLayout* KIptablesTCPPortsUILayout;
    QHBoxLayout* Layout1;
};

#endif // KIPTABLESTCPPORTSUI_H
