#ifndef CTAHOCOPY_H
#define CTAHOCOPY_H

#include <QDialog>

namespace Ui {
class CTahoCopy;
}

class CTahoCopy : public QDialog
{
    Q_OBJECT

public:
    explicit CTahoCopy(QString &vers, QWidget *parent = 0);
//    CTahoCopy(QString &vers,QWidget *parent = 0);   // Standardkonstruktor

    ~CTahoCopy();
public slots:
    void OnGpl();
    void OnDyj();
    void OnOsmTaho();
    void OnOSMc();	//DYJ Taho 4.04c
protected:
    void changeEvent(QEvent *e);


private:
    Ui::CTahoCopy *ui;
};

#endif // CTAHOCOPY_H
