#ifndef CTAHOOPT_H
#define CTAHOOPT_H
#include <cosmopt.h>
#include <QTranslator>
#include <QDialog>

namespace Ui {
class CTahoOpt;
}

class CTahoOpt : public QDialog, public COsmOpt
{
    Q_OBJECT

public:
    explicit CTahoOpt(QWidget *parent = 0);
    ~CTahoOpt();
    void	setCache(unsigned int tage);
    unsigned int	getCache();
//DYJ Taho 4.07j     void setRelPath(bool isRel);	//Absolute Pfade
//DYJ Taho 4.07j     bool getRelPath();
    QString	getZipPath();
    void setZipPath(QString path);
    QString	getZipPar();
    void setZipPar(QString par);
    void setUnGzPar(QString par);
    QString	getUnGzPar();
    unsigned int	m_tasks;
    int		m_uaID;
    QTranslator *m_pLanguage;
protected:
    void changeEvent(QEvent *e);

private:
    Ui::CTahoOpt *ui;
public slots:
    //DYJ Taho 4.07d     void OnExpSrc();
    void OnUpdSrc();
//DYJ Taho 4.07j 	    void OnNormal();
//DYJ Taho 4.07j 	    void OnUsb();
    void change_lang(QString lang);
    void OnZip();
    };

#endif // CTAHOOPT_H
