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
    ~CTahoOpt() override;
    void setCache(int tage);
    int	getCache();
    QString	getZipPath();
    void setZipPath(QString path);
    QString	getZipPar();
    void setZipPar(QString par);
    void setUnGzPar(QString par);
    QString	getUnGzPar();

    int	m_tasks = -1;
    QTranslator *m_pLanguage = nullptr;

protected:
    void changeEvent(QEvent *e) override;

private slots:
    void OnUpdSrc();
    void change_lang(QString lang);
    void OnZip();

private:
    Ui::CTahoOpt *ui;
};

#endif // CTAHOOPT_H
