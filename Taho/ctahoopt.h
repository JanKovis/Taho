#ifndef CTAHOOPT_H
#define CTAHOOPT_H
#include <cosmopt.h>
#include <QTranslator>
#include <QDialog>
#include <qfile.h>
#include <qtextstream.h>

namespace Ui {
class CTahoOpt;
}

class CTahoOpt : public QDialog, public COsmOpt
{
    Q_OBJECT

public:
    explicit CTahoOpt(QWidget *parent = nullptr);
    ~CTahoOpt();
    void	setCache(unsigned int tage);
    unsigned int getCache();
    QString	getZipPath();
    void setZipPath(QString path);
    QString	getZipPar();
    void setZipPar(QString par);
    void setUnGzPar(QString par);
    QString	getOffDirPath();
    void setOffDirPath(QString path);
    QString	getUnGzPar();
    void saveOptions();

    int	m_tasks;
    QTranslator *m_pLanguage;
    QString m_osmUrl;
    QString m_tahoPfad;
    QString m_version;

protected:
    void changeEvent(QEvent *e);

private:
    Ui::CTahoOpt *ui;
public slots:
    void OnUpdSrc();
    void change_lang(QString lang);
    void OnZip();
    void on_pb_offDir_clicked();
private slots:
    void on_pushButton_clicked();
};

#endif // CTAHOOPT_H
