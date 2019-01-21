#include "cosmopt.h"
#include "cxmlfile.h"
#include "cosm.h"
#include <qdir.h>
#include "cmapsrc.h"
#include <qstring.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qstandardpaths.h>
#include <QFileDialog>
#include <urldownload.h>
#include <QDate>

QString COsmOpt::m_par;
QString COsmOpt::m_prgPath;
QString COsmOpt::m_persPath;
QString COsmOpt::m_srcPath=m_persPath;

QString COsmOpt::m_tmpDir;


COsmOpt::COsmOpt()
{
    if(!m_persPath.isEmpty())	//dann waren wir schon hier
        return;
//Parameter und Programmpfad
    m_prgPath = qApp->applicationDirPath()+"/";
    QStringList pars=QApplication::instance()->arguments();
    if(pars.size()<2)
        m_par="";
    else
        m_par=pars[1];

//tmp-Pfad
    QStringList paths = QStandardPaths::standardLocations(QStandardPaths::TempLocation);
    if(paths.size())
        m_tmpDir=QString("%1/").arg(paths[0]);
    else
    {
        m_tmpDir=QString("%1tmp/").arg(m_prgPath);
        QDir dirH;
        dirH.mkpath(m_tmpDir);
    }

//Persönlicher -Pfad
    paths = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation);
    if(paths.size())
        m_persPath=QString("%1/DYJ/OSM/").arg(paths[0]);
    else
        m_persPath=m_prgPath;

// Tile-Sourcen laden
    loadTahoSrc(false);

}

/*** ------------------------------------------------------------------------ ***/
/*	bool COsmOpt::loadTahoSrc(bool defPathIsPrg)					*/
/*								*/
/*	Parameter:	defPathIsPrg Wenn true sind die Taho-Files im Prg-Ordner, sonst im     */
/*      Dokumente Ordner, ggf werden sie dort hin verschoben                   	*/
/*	Ergebnis:	Erfolgreich?													*/
/*	06.11 von Dimitri Junker	DYJ 4.07d									*/
/*** ------------------------------------------------------------------------ ***/

bool COsmOpt::loadTahoSrc(bool defPathIsPrg)
{
    if(defPathIsPrg)
        m_srcPath=m_prgPath;
    else
        m_srcPath=m_persPath;
    return loadTahoSrc();
}
/*** ------------------------------------------------------------------------ ***/
/*	bool COsmOpt::loadTahoSrc()					*/
/*								*/
/*	Parameter:	keiner     */
/*	Ergebnis:	Erfolgreich?													*/
/*	06.11 von Dimitri Junker	DYJ 4.07d									*/
/*** ------------------------------------------------------------------------ ***/

bool COsmOpt::loadTahoSrc()
{
    static int versuch=0;
    versuch++;
    bool ret=false;
    if((ret=loadTahoSrc(m_srcPath+T_SRC))==false && versuch<2)
        OnUpdSrc();      //Wahrscheinlich der erste Lauf nach der Installation
    versuch=0;
    CMapSrc::m_mySrc=m_persPath+T_MY_SRC;
    loadTahoSrc(CMapSrc::m_mySrc);
    return ret;
}

/*** ------------------------------------------------------------------------ ***/
/*	bool COsmOpt::loadTahoSrc(QString pfad,QString *psTaho,QString errOld)		*/
/*								*/
/*	Parameter:	pfad : Pfad von defsrcP oder mydefsrc							*/
//              psTaho:
//              errOld:
/*	Ergebnis:	erfolgreich?															*/
/*	von Dimitri Junker									*/
/*** ------------------------------------------------------------------------ ***/

bool COsmOpt::loadTahoSrc(QString pfad,QString *psTaho,QString errOld)
{
    QString local,source;
    if(!psTaho)
        psTaho=&local;
    bool ret=false;
    *psTaho="";
    CXmlFile xTaho;
    if(!xTaho.read2Buf(pfad))
        return ret;

    if(!xTaho.readValB(*psTaho,"taho") && !errOld.isEmpty())
    {
        QMessageBox::StandardButton oldOpt;
        oldOpt = QMessageBox::question(NULL, "", errOld,
                                      QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

        if(oldOpt!=QMessageBox::Cancel)
            *psTaho=xTaho.m_sBuf;
    }
//Sources
    if(!psTaho->isEmpty())
        ret=CMapSrc::readTaho(&xTaho);
    return ret;
}


bool COsmOpt::OnUpdSrc()
{
    bool ret=false;
    QString urlOsmTaho="https://wiki.openstreetmap.org/wiki/DE:Taho",urlTaho="";
    QString osmTahoPath=m_tmpDir+"osm_taho.html";
    urlDownload::downloadFile(urlOsmTaho,  osmTahoPath);

    CXmlFile xTaho;
    if(xTaho.read2Buf(osmTahoPath))
    {
        QString sA,fName=T_SRC;
        int pos=0;
        while(!(sA=xTaho.readAttr("a",&pos)).isEmpty())
        {
            QString link=xTaho.readAttrValS(sA,"href");
            if(!link.right(fName.size()).compare(fName,Qt::CaseInsensitive))
            {
                urlTaho=link;
                break;
            }
        }
        if(urlTaho.isEmpty())
        {
            urlTaho="http://www.dimitri-junker.de/";
            urlTaho+=T_SRC;
        }
        urlDownload::downloadFile(urlTaho, m_srcPath+T_SRC);
        ret=loadTahoSrc();
    }
    return ret;
}
