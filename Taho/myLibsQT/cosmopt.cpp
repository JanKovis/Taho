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
QString COsmOpt::m_srcPath=m_persPath; //DYJ Taho 4.07d

QString COsmOpt::m_tmpDir;


COsmOpt::COsmOpt()
{
//DYJ Taho 4.07j 	    m_pDefPrg=NULL;
//DYJ Taho 4.07j 	    m_pDefED=NULL;
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

    m_uaID=0;	/*DYJ Taho 3.06c */
// Tile-Sourcen laden
    /*DYJ Taho 4.07d Start*/
    /*DYJ  Ende; alt:
    Q_ASSERT(!SrcName[ANZ_SRC-1].isEmpty());	//DYJ 1.05h
    Q_ASSERT(!OvrName[ANZ_OVR-1].isEmpty());	//DYJ 1.05h
    Q_ASSERT(!VecName[ANZ_VECT-1].isEmpty());	//DYJ 1.05h
    initSrc();
    CMapSrc::select(SrcName[BAS_STD]);
    */
    loadTahoSrc(false);

}
/*** ------------------------------------------------------------------------ ***/
/*	void COsmOpt::initSrc()														*/
/*	Liest die Quellen ein														*/
/*	Parameter:	keine															*/
/*	Ergebnis:	keines															*/
/*	06.11 von Dimitri Junker	DYJ 1.03b										*/
/*** ------------------------------------------------------------------------ ***/
/*DYJ Taho 4.07d Start*/
/*DYJ  Ende; alt:

void COsmOpt::initSrc()
{
    QString ts = QString("%1%2").arg(QLocale(QLocale::C).toDate(QString(__DATE__).simplified(), QLatin1String("MMM d yyyy")).toString("yyyyMMdd"))
    .arg(QString("%1%2%3%4%5%6").arg(__TIME__[0])
    .arg(__TIME__[1])
    .arg(__TIME__[3])
    .arg(__TIME__[4])
    .arg(__TIME__[6])
    .arg(__TIME__[7]));
    QString sSrc;

    for(int i=0;!ObsName[i].isEmpty();i++)
        CMapSrc::initP(ObsName[i],"",ts,"",0,"",252);
   for(int i=0;i<ANZ_SRC;i++)
        CMapSrc::initP(SrcName[i],SrcUrl[i],ts,SrcExt[i],SrcMaxThreads[i],SrcPref[i],maxZoom[i]);
    CMapSrc::select(SrcName[BAS_STD]);
    for(int i=0;i<ANZ_OVR;i++)
        CMapSrc::initP(OvrName[i],OvrUrl[i],ts,".png",OvrMaxThreads[i]);
    for(int i=0;i<ANZ_VECT;i++)
        CMapSrc::initV(VecName[i],VecUrl[i],ts,VecMaxThreads[i],VecPref[i],VecOffset[i],VecKsize[i],VecMapPF[i]);
}
void COsmOpt::expSrc()
{
    QString path= QFileDialog::getSaveFileName(NULL,QObject::tr("Speicher Quellen"),defPath(),QObject::tr("Taho-Files(*.taho)"));
    if(path.isEmpty())
       return;
    CMapSrc::writeTaho(path);

}
    */

/*DYJ Taho 4.07d Start*/
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
/*DYJ  Ende; alt:

bool COsmOpt::loadTahoSrc(bool defPathIsPrg)
{
    bool ret=false;
    QString path=defPath(defPathIsPrg)+T_SRC;
    if((ret=loadTahoSrc(path))==false)
    {
        if((ret=loadTahoSrc(m_prgPath+T_SRC))==true)
        {
            if(defPathIsPrg)
                CMapSrc::writeTaho(path); 	// soll in Eigene Dateien ist da aber nicht (von altem Taho geschrieben)
        }
    }

//DYJ Taho 4.07c Start
    m_mySrc=defPath(defPathIsPrg)+T_MY_SRC;
    loadTahoSrc(m_mySrc);
//DYJ  Ende; alt:
//    path=defPath(defPathIsPrg)+T_MY_SRC;
//    loadTahoSrc(path);

    return ret;
}*/


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

/*DYJ Taho 4.07dgj Start*/

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
/*DYJ  Ende; alt:
void COsmOpt::OnUpdSrc()
{
    QString urlOsmTaho="http://wiki.openstreetmap.org/wiki/Taho",urlTaho="",ret="";
    QString osmTahoPath=m_tmpDir+"osm_taho.html";
    urlDownload::downloadFile(urlOsmTaho,  osmTahoPath);

    CXmlFile xTaho;
    if(!xTaho.read2Buf(osmTahoPath))
        return;

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
    urlDownload::downloadFile(urlTaho, m_persPath+T_SRC);
    loadTahoSrc(pfad,psTaho,errOld);


}*/


/*DYJ Taho 4.07j Start*/
/*DYJ  Ende; alt:

QString COsmOpt::defPath()
{
    if(getDefPathIsPrg())
        return m_prgPath;
    else
        return m_persPath;
}
QString COsmOpt::defPath(bool defPathIsPrg)
{
    if(defPathIsPrg)
        return m_prgPath;
    else
        return m_persPath;
}
void COsmOpt::setDefPathIsPrg(bool isPrg)
{
    m_pDefED->setChecked(!isPrg);
    m_pDefPrg->setChecked(isPrg);

}
bool COsmOpt::getDefPathIsPrg()
{
    return m_pDefPrg->isChecked();

}
*/
