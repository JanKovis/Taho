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
    void	setCache(int tage);
    int	getCache();
    QString	getZipPath();
    void setZipPath(QString path);
    QString	getZipPar();
    void setZipPar(QString par);
    void setUnGzPar(QString par);
    QString	getOffDirPath();
    void setOffDirPath(QString path);
    QString	getUnGzPar();
    void saveOptions();

    int	m_tasks = -1;
    QTranslator *m_pLanguage = nullptr;
    QString m_osmUrl;
    QString m_tahoPfad;
    QString m_version;

protected:
    void changeEvent(QEvent *e) override;

private slots:

    void OnUpdSrc();
    void change_lang(QString lang);
    void OnZip();
    void on_pb_offDir_clicked();
    void on_pushButton_clicked();

private:

    Ui::CTahoOpt *ui;

    };

#endif // CTAHOOPT_H
