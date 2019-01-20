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
    explicit CTahoOpt(QWidget *parent = nullptr);
    ~CTahoOpt();
    void	setCache(int tage);
    int	getCache();
    QString	getZipPath();
    void setZipPath(QString path);
    QString	getZipPar();
    void setZipPar(QString par);
    void setUnGzPar(QString par);
    QString	getUnGzPar();
    int	m_tasks;
    QTranslator *m_pLanguage;
protected:
    void changeEvent(QEvent *e);

private:
    Ui::CTahoOpt *ui;
public slots:
    void OnUpdSrc();
    void change_lang(QString lang);
    void OnZip();
    };

#endif // CTAHOOPT_H
