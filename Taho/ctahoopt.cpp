// TahoOpt.cpp: Implementierungsdatei
//


//CHG: TAHO 2.10g DYJ
//Die *.taho benutzten das falsche charset
/*
* 1.12.13 Dimitri Junker (DYJ) gekennzeichnet mit 'DYJ Taho 3.08b'
Nötige Änderungen zur Anpassung an Visual Studio 2013
 * 30.12.18 Dimitri Junker (DYJ) gekennzeichnet mit 'DYJ Taho 4.07j'
 * Seit Taho mit einem Installer installiert wird machen die Optionen
 * zu den Pfaden keinen Sinn mehr, also habe ich sie gelöscht

*/
#include "ctahoopt.h"
#include "ui_ctahoopt.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QThread>

CTahoOpt::CTahoOpt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CTahoOpt)
{
    ui->setupUi(this);
//DYJ Taho 4.07j     m_pDefPrg=ui->rb_pfadPrg;
//DYJ Taho 4.07j     m_pDefED=ui->rb_pfadED;
    m_tasks = QThread::idealThreadCount();

}

CTahoOpt::~CTahoOpt()
{
    delete ui;
}


/////////////////////////////////////////////////////////////////////////////
// Dialogfeld CTahoOpt
/*

CTahoOpt::CTahoOpt(CWnd* pParent)
    : CMultiLanguageDialog(CTahoOpt::IDD, pParent)
{
    ui->setupUi(this);
    m_cache = 0;
    m_nLang = -1;
    m_zipPath = _T("");
    m_zipPar = _T("");
    m_relPath = -1;
    m_unGzPar = _T("");
    m_uaID = -1;
    m_langCB = IDC_LANG;
}


*/
/////////////////////////////////////////////////////////////////////////////
// Behandlungsroutinen für Nachrichten CTahoOpt
/*DYJ Taho 4.07d Start*/
/*DYJ  Ende; alt:

void CTahoOpt::OnExpSrc()
{
    expSrc();
}
*/

/*DYJ Taho 3.08b Start*/
void CTahoOpt::OnUpdSrc()
{
    COsmOpt::OnUpdSrc();
}
/*DYJ  Ende; */


void CTahoOpt::change_lang(QString lang)
{
    if(lang=="Deutsch")
        qApp->removeTranslator(m_pLanguage);
    else if(lang=="English")
    {
        m_pLanguage->load("taho_en");
        qApp->installTranslator(m_pLanguage);
    }
    else if(lang=="Français")
    {
        m_pLanguage->load("taho_fr");
        qApp->installTranslator(m_pLanguage);
    }
}
/* 2do
bool CTahoOpt::OnInitDialog()
{
    CMultiLanguageDialog::OnInitDialog();

    adjustLanguage(getLang());
    UpdateData(FALSE);
    CSpinButtonCtrl *pSpin=(CSpinButtonCtrl *)GetDlgItem(IDC_TASKS);
    pSpin->SetRange(1,100);
    pSpin->SetPos(m_tasks);
    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX-Eigenschaftenseiten sollten FALSE zurückgeben
}
*/
void CTahoOpt::OnZip()
{
    QFileInfo fi(getZipPath());
    QString path_neu= QFileDialog::getOpenFileName(this,tr("Packer"),getZipPath(),tr("Programm(*.exe);;Alle(*.*)")); //2dowindows
    if(path_neu.isEmpty())
        return;
    setZipPath(path_neu);


    QFileInfo fiZip(getZipPath());
    QString prgName=fiZip.baseName().toLower();

    if(prgName.contains("7z"))
    {
        setZipPar("a -tzip $Z @$L");
        setUnGzPar("x $Q -o$Z");
    }
    else if(prgName.contains("winrar"))
    {
        setZipPar("a -afzip $Z @$L");
        setUnGzPar("x $Q $Z");
    }
    else if(prgName.contains("winzip"))
    {
        setZipPar("-min -a $Z @$L");
        setUnGzPar("-min -e $Q $Z");
    }


}
/*DYJ Taho 4.07j Start*/
/*DYJ  Ende; alt:

void CTahoOpt::OnNormal()
{
    setDefPathIsPrg(false);
    setRelPath(false);
}

void CTahoOpt::OnUsb()
{
    setDefPathIsPrg(true);
    setRelPath(true);

}
*/

void	CTahoOpt::setCache(unsigned int tage)
{
    ui->sbCache->setValue(tage);
}

unsigned int	CTahoOpt::getCache()
{
    return ui->sbCache->value();
}
/*DYJ Taho 4.07j Start*/
/*DYJ  Ende; alt:

void CTahoOpt::setRelPath(bool isRel)	//Absolute Pfade
{
    ui->rb_pfadA->setChecked(!isRel);
    ui->rb_pfadR->setChecked(isRel);
}

bool CTahoOpt::getRelPath()
{
    return ui->rb_pfadR->isChecked();
}
*/
QString	CTahoOpt::getZipPath()
{
    return ui->la_zip->text();
}

void CTahoOpt::setZipPath(QString path)
{
    ui->la_zip->setText(path);
}
QString	CTahoOpt::getZipPar()
{
    return ui->le_parKMZ->text();
}

void CTahoOpt::setZipPar(QString par)
{
    ui->le_parKMZ->setText(par);
}

QString	CTahoOpt::getUnGzPar()
{
    return ui->le_parGZ->text();
}

void CTahoOpt::setUnGzPar(QString par)
{
    ui->le_parGZ->setText(par);
}
void CTahoOpt::changeEvent(QEvent *e)
{
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
