#include "cmapsrc.h"
#include <qmap.h>
#include <QTextStream>
#include <cosm.h>
#include <QDate>
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <cosmopt.h>
// mapSrc.cpp: Implementierung der Klasse mapSrc.
//
    /*neu für DYJ 1.03b */
//////////////////////////////////////////////////////////////////////



/* 20.4.13 Dimitri Junker (DYJ) gekennzeichnet mit 'DYJ 1.05i'
    Obsolete Quellen werden ignoriert, derzeit sind dies:
    {"Osmarender","Cycle1","Cycle2"}

 * 13.07.15 Dimitri Junker (DYJ) gekennzeichnet mit 'DYJ Taho 4.01d'
Die lonvia Tiles sind umgezogen, um so etwas besser zu behandeln habe ich den Adressen Tilestamps gegeben, damit Taho entscheiden kann welche Adresse aktuell ist (exe oder defsrc)

 * 1.08.16 Dimitri Junker (DYJ) gekennzeichnet mit 'DYJ Taho 4.04b'
    Die Verwaltung der obsoleten Quellen überarbeitet, sie stehen jetzt auch im *.taho File

 * 26.12.18 Dimitri Junker (DYJ) gekennzeichnet mit 'DYJ Taho 4.07c'
 * Platzhalter in Quell URLs erweitert, statt $x funktioniert jetzt auch {x} und ${x},
 * Groß/Kleinschreibung ist auch egal. Außerdem gibt es einen neuen Platzhalter für IDs
 * die man bei Quellen bekommt bei denen man sich anmelden muss, wie thunderforest und maptiler.

 * 27.12.18 Dimitri Junker (DYJ) gekennzeichnet mit 'DYJ Taho 4.07d'
 * Die QuellURLs werden jetzt nur noch in den Files defsrcP.taho und mydefsrc.taho gespeichert,
 * nicht mehr im Programm. Dabei merkt sich Taho welche Quellen aus welcher Datei gelesen wurde,
 *  so kann defsrcP.taho bei einem Update einfach überschrieben werden ohne mydefsrc.taho zu
 *  ändern. Damit ist auch "Export Src" Obsolet

 * 28.12.18 Dimitri Junker (DYJ) gekennzeichnet mit 'DYJ Taho 4.07e'
 * Wegen 4.07d muß jetzt auch im Taho File markiert werden welche Quelle als Standard
 * verwende werden soll. Dazu dient Typ=100

*/
//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////
QListWidget	*CMapSrc::m_ovrCtrlP;
QListWidget	*CMapSrc::m_ovrCtrlV;
QComboBox * CMapSrc::m_srcBox;
QString CMapSrc::m_mySrc; //DYJ Taho 4.07c;

QMap<QString,CMapSrc*> CMapSrc::m_mapSrc;

QString CMapSrc::m_src="";
QMap<QString,QString> COsm::m_osmIDs;/*DYJ Taho 4.07c */

CMapSrc::~CMapSrc()
{

}


CMapSrc::CMapSrc()
{
    m_name="";
    m_url="";
    m_ext="";
    m_pref="";
    m_maxZoom=0;
    m_type=MAP_UNDEF;
    m_offset=0;
    m_useOvrs[0]=m_useOvrs[1]=false;
    m_kSize=0;
    m_mapsPF=0;
}
/*DYJ Taho 4.07d & 4.07i Start*/
CMapSrc *CMapSrc::initV(QString name, QString url,bool isPrivate,unsigned char maxThreads, QString pref, int offset,double kSize,int mapsPF)
{
    CMapSrc *ret=NULL;
    if(offset==-1)	//API -> *.osm
        ret=initP(name,url,isPrivate,"",maxThreads,pref,253);
    else
        ret=initP(name,url,isPrivate,"",maxThreads,pref,254);

     if(ret)	/*DYJ 1.05i */
    {
        ret->m_offset=offset;
        ret->m_kSize=kSize;
        ret->m_mapsPF=mapsPF;
    }
    return ret;
}
/*DYJ  Ende; alt:
CMapSrc *CMapSrc::initV(QString name, QString url,QString timestamp,unsigned char maxThreads, QString pref, int offset,double kSize,int mapsPF)
{
    CMapSrc *ret=NULL;
    if(offset==-1)	//API -> *.osm
        ret=initP(name,url,timestamp,"",maxThreads,pref,253);
    else
        ret=initP(name,url,timestamp,"",maxThreads,pref,254);

     if(ret)
    {
        ret->m_offset=offset;
        ret->m_kSize=kSize;
        ret->m_mapsPF=mapsPF;
    }
    return ret;
}
*/
Q_DECLARE_METATYPE(CMapSrc*)

/*DYJ Taho 4.07d& 4.07i Start*/
CMapSrc *CMapSrc::initP(QString name, QString url,bool isPrivate, QString ext,int maxThreads, QString pref,unsigned char maxZoom)
/*DYJ  Ende; alt:
CMapSrc *CMapSrc::initP(QString name, QString url,QString timestamp, QString ext,int maxThreads, QString pref,unsigned char maxZoom)
*/
{
    CMapSrc *ret;
    bool isNew=false;
    QMap<QString,CMapSrc *>::iterator it=m_mapSrc.find(name);
    if(it==m_mapSrc.end())
    {
        ret=new CMapSrc;
        m_mapSrc.insert(name,ret);
        isNew=true;
    }
    else
        ret=it.value();
//DYJ Taho 4.07i     if(isNew||ret->m_timestamp.compare(timestamp)<0)
//DYJ Taho 4.07i     {

    ret->m_isPrivate=isPrivate;	//DYJ Taho 4.07d
    ret->m_name=name;
    ret->m_ext=ext;
    ret->m_url=url;
    ret->m_maxThreads=maxThreads;
//DYJ Taho 4.07i     ret->m_timestamp=timestamp;
    if(pref.isEmpty())
        ret->m_pref=name.left(3);
    else
        ret->m_pref=pref;
    switch(maxZoom)
    {
    case 255:	//Pixel Overlay
        ret->m_type=MAP_OVR;
        ret->m_maxZoom=0;
        if(isNew && m_ovrCtrlP)
        {
            QListWidgetItem *newItem =new QListWidgetItem(name);
            newItem->setCheckState(Qt::Unchecked);
            newItem->setData(Qt::UserRole,QVariant::fromValue<CMapSrc*>(ret));
            m_ovrCtrlP->addItem(newItem);
            m_ovrCtrlP->sortItems();
        }
        break;
    case 253:	//*.osm
        ret->m_type=MAP_OSM;
        ret->m_maxZoom=0;
        if(isNew && m_ovrCtrlV)
        {
            name+=" (*.osm)";
            QListWidgetItem *newItem =new QListWidgetItem(name);
            newItem->setCheckState(Qt::Unchecked);
            newItem->setData(Qt::UserRole,QVariant::fromValue<CMapSrc*>(ret));
            m_ovrCtrlV->addItem(newItem);
            m_ovrCtrlV->sortItems();
        }
        break;
    case 254:	//Vector
        ret->m_type=MAP_VECT;
        ret->m_maxZoom=0;
        if(isNew && m_ovrCtrlV)
        {
            name+=" (*.img)";
            QListWidgetItem *newItem =new QListWidgetItem(name);
            newItem->setCheckState(Qt::Unchecked);
            newItem->setData(Qt::UserRole,QVariant::fromValue<CMapSrc*>(ret));
            m_ovrCtrlV->addItem(newItem);
            m_ovrCtrlV->sortItems();
         }
      break;
        /*DYJ Taho 4.07d Start*/
        /*DYJ  Ende; alt:

    case 252:	//Obsolete
        ret->m_type=MAP_OBS;
        break;
        */
    default:	//Pixel Basemap
        ret->m_type=MAP_BAS;
        ret->m_maxZoom=maxZoom;
        if(isNew && m_srcBox)
            m_srcBox->addItem(name);
        break;
    }
    ret->m_useOvrs[0]=ret->m_useOvrs[1]=false;
//DYJ Taho 4.07i     }
    return ret;

}

/*DYJ Taho 4.07d Start*/
void CMapSrc::writeTaho(QString path,bool onlyPriv)
/*DYJ  Ende; alt:
void CMapSrc::writeTaho(QString path)
*/
{
    FILE *fTaho=fopen(path.toLatin1(),"w");
    if(fTaho)
    {
        fprintf(fTaho,"<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>\n");	//CHG: TAHO 2.10g DYJ
        fprintf(fTaho,"<taho version=\"1.0\" creator=\"Taho.exe - http://www.dimitri-junker.de/html/openstreetmap.html\">\n");
        fprintf(fTaho,"\t<mapallsrc>\n");

        QMap<QString,CMapSrc *>::iterator pos=m_mapSrc.begin();
        while (pos != m_mapSrc.end())
        {
            CMapSrc *map=pos.value();
            QString name=pos.key();
            pos++;
            if(!onlyPriv || map->m_isPrivate)	//DYJ Taho 4.07d
            {
                fprintf(fTaho,"\t\t<src>\n");
                fprintf(fTaho,"\t\t\t<name>%s</name>\n",name.toStdString().c_str());
                fprintf(fTaho,"\t\t\t<prefix>%s</prefix>\n",map->m_pref.toStdString().c_str());
                fprintf(fTaho,"\t\t\t<url>%s</url>\n",map->m_url.toStdString().c_str());
//DYJ Taho 4.07i                 fprintf(fTaho,"\t\t\t<timestamp>%s</timestamp>\n",map->m_timestamp.toStdString().c_str());
                fprintf(fTaho,"\t\t\t<ext>%s</ext>\n",map->m_ext.toStdString().c_str());
                fprintf(fTaho,"\t\t\t<type>%d</type>\n",map->m_type);
                switch((int)map->m_type)
                {
                case MAP_BAS:
                    fprintf(fTaho,"\t\t\t<maxzoom>%d</maxzoom>\n",map->m_maxZoom);
                    break;
                case MAP_VECT:
                    fprintf(fTaho,"\t\t\t<offset>%d</offset>\n",map->m_offset);
                    fprintf(fTaho,"\t\t\t<mapspf>%d</mapspf>\n",map->m_mapsPF);
                case MAP_OSM:
                    fprintf(fTaho,"\t\t\t<ksize>%f</ksize>\n",map->m_kSize);
                    break;
                }
                fprintf(fTaho,"\t\t</src>\n");
            }
        }
        fprintf(fTaho,"\t</mapallsrc>\n");
//DYJ Taho 4.07c Start
        fprintf(fTaho,"\t<OsmIds>\n");
        QMapIterator<QString, QString> iter(COsm::m_osmIDs);

        while(iter.hasNext())
        {
            iter.next();
            fprintf(fTaho,"\t\t<ID>\n");
            fprintf(fTaho,"\t\t\t<name>%s</name>\n",iter.key().toStdString().c_str());
            fprintf(fTaho,"\t\t\t<IDV>%s</IDV>\n",iter.value().toStdString().c_str());
            fprintf(fTaho,"\t\t</ID>\n");
        }
        fprintf(fTaho,"\t</OsmIds>\n");
//DYJ  Ende;
        fprintf(fTaho,"</taho>\n");
        fclose(fTaho);
    }
}

bool CMapSrc::readTaho(CXmlFile *xTaho)
{
    bool ret=false;
    //DYJ Taho 4.07c Start
    QString sOsmIDs;
    if(xTaho->readValB(sOsmIDs,"OsmIds"))
    {
        QString sID;
        int pos=0;
        while(xTaho->readValB(sID,sOsmIDs,"ID",&pos))
        {
            QString sName;
            QString sIDVal="";
            xTaho->readValB(sName,sID,"name");
            xTaho->readValB(sIDVal,sID,"IDV");
            COsm::m_osmIDs.insert(sName,sIDVal);
        }
    }
    //DYJ  Ende;
    QString sMapsrc;
    /*DYJ Taho 4.07d Start*/
    if(!xTaho->readValB(sMapsrc,"mapPubSrc"))
    /*DYJ  Ende; alt:
    if(!xTaho->readValB(sMapsrc,"mapallsrc"))
    */
    {
        QString sMapsrcP;
        xTaho->readValB(sMapsrc,"mapsrc");
        xTaho->readValB(sMapsrcP,"mapovr");
        sMapsrc+=sMapsrcP;
    }
    //DYJ Taho 4.07d Start
    bool isMysrc=false;
    if(sMapsrc.isEmpty())   //evtl mydefsrc.taho
    {
        xTaho->readValB(sMapsrc,"mapallsrc");
        isMysrc=true;
    }

    //DYJ  Ende;
    if(!sMapsrc.isEmpty())
    {
        QString sSrc;
        int pos=0;
        while(xTaho->readValB(sSrc,sMapsrc,"src",&pos))
        {
            QString sName;
//DYJ Taho 4.07i             QString sMapsrcTime="";
            xTaho->readValB(sName,sSrc,"name");
            QString sURL,sExt;
            xTaho->readValB(sURL,sSrc,"url");
//DYJ Taho 4.07i             xTaho->readValB(sMapsrcTime,sSrc,"timestamp");
            xTaho->readValB(sExt,sSrc,"ext");
            if(sExt.isEmpty())
                sExt=".png";
            unsigned char maxzoom=255;
            int maxThreads =xTaho->readVal_intDef(sSrc,"maxThreads",1000);
            if(maxThreads==1000)	//altes Taho-File)
            {
                QString slUrl=sURL;
                slUrl.toLower();
                if(slUrl.indexOf("wanderreitkarte.de")==-1)
                    maxThreads=255;
                else
                    maxThreads=1;
            }
            QString tmpstr;
            switch(xTaho->readVal_intDef(sSrc,"type"))
            {
            //DYJ Taho 4.07e Start
                case MAP_DEF:
                    m_src=sName;
            //DYJ  Ende;
                case MAP_BAS:
                    maxzoom=(unsigned char)xTaho->readVal_intDef(sSrc,"maxzoom",255);
                case MAP_OVR:
                    xTaho->readValB(tmpstr,sSrc,"prefix");
                    /*DYJ Taho 4.07d & 4.07i Start*/
                    initP(sName,sURL,isMysrc,sExt,(unsigned char)maxThreads,tmpstr,maxzoom);
                    /*DYJ  Ende; alt:
                    initP(sName,sURL,sMapsrcTime,sExt,(unsigned char)maxThreads,tmpstr,maxzoom);
                    */

                    break;
                case MAP_VECT:
                    xTaho->readValB(tmpstr,sSrc,"prefix");
                    /*DYJ Taho 4.07d & 4.07i Start*/
                    initV(sName,sURL,isMysrc,(unsigned char)maxThreads,tmpstr,xTaho->readVal_intDef(sSrc,"offset"),xTaho->readVal_dblDef(sSrc,"ksize",1),xTaho->readVal_intDef(sSrc,"mapspf",1000));
                    /*DYJ  Ende; alt:
                    initV(sName,sURL,sMapsrcTime,(unsigned char)maxThreads,tmpstr,xTaho->readVal_intDef(sSrc,"offset"),xTaho->readVal_dblDef(sSrc,"ksize",1),xTaho->readVal_intDef(sSrc,"mapspf",1000));
                    */

                    break;
                case MAP_OSM:
                    xTaho->readValB(tmpstr,sSrc,"prefix");
                    /*DYJ Taho 4.07d & 4.07i Start*/
                    initV(sName,sURL,isMysrc,(unsigned char)maxThreads,tmpstr,-1,xTaho->readVal_dblDef(sSrc,"ksize",1),0);
                    /*DYJ  Ende; alt:
                    initV(sName,sURL,sMapsrcTime,(unsigned char)maxThreads,tmpstr,-1,xTaho->readVal_dblDef(sSrc,"ksize",1),0);
                    */
                    /*DYJ Taho 4.07d Start*/
                    /*DYJ  Ende; alt:
                break;
            case MAP_OBS:
                initP(sName,"",sMapsrcTime,"",0,"",252);
                    */
            }
            ret=true;
        }
    }
    return ret;
}

void CMapSrc::destroy()
{
    QMap<QString,CMapSrc *>::iterator pos=m_mapSrc.begin();
    while (pos != m_mapSrc.end())
    {
        CMapSrc *map=pos.value();
        delete map;
        pos++;
     }

}
void CMapSrc::initBoxes(QComboBox * src,QListWidget *ovr,QListWidget *vect,int nr)
{
    m_srcBox=src;
    m_ovrCtrlP=ovr;
    m_ovrCtrlV=vect;

    QMap<QString,CMapSrc *>::iterator it=m_mapSrc.begin();
    while (it != m_mapSrc.end())
    {
        QString name=it.key();
        CMapSrc *map=it.value();
        it++;
        switch((int)map->m_type)
        {
            case MAP_BAS:	//Pixel Basemap
                if(m_srcBox)
                    m_srcBox->addItem(name);
                break;
            case MAP_OVR:	//Pixel Overlay
                if(ovr)
                {
                    QListWidgetItem *newItem =new QListWidgetItem(name);
                    if(map->m_useOvrs[nr])
                        newItem->setCheckState(Qt::Checked);
                    else
                        newItem->setCheckState(Qt::Unchecked);
                    newItem->setData(Qt::UserRole,QVariant::fromValue<CMapSrc*>(map));
                    m_ovrCtrlP->addItem(newItem);
                }
                break;
            case MAP_VECT:	//Vector
                if(vect)
                {
                    name +=" (*.img)";
                    QListWidgetItem *newItem =new QListWidgetItem(name);
                    if(map->m_useOvrs[nr])
                        newItem->setCheckState(Qt::Checked);
                    else
                        newItem->setCheckState(Qt::Unchecked);
                    newItem->setData(Qt::UserRole,QVariant::fromValue<CMapSrc*>(map));
                    m_ovrCtrlV->addItem(newItem);
                }
                break;
            case MAP_OSM:	//*.osm
                if(vect)
                {
                    name +=" (*.osm)";
                    QListWidgetItem *newItem =new QListWidgetItem(name);
                    if(map->m_useOvrs[nr])
                        newItem->setCheckState(Qt::Checked);
                    else
                        newItem->setCheckState(Qt::Unchecked);
                    newItem->setData(Qt::UserRole,QVariant::fromValue<CMapSrc*>(map));
                    m_ovrCtrlV->addItem(newItem);
                }
                break;
        }

    }
    if(m_srcBox && !m_src.isEmpty())
        select(m_src);
    if(m_ovrCtrlP)
        m_ovrCtrlP->sortItems();
    if(m_ovrCtrlV)
        m_ovrCtrlV->sortItems();
}
CMapSrc * CMapSrc::lookup(QString name)
{
    CMapSrc *ret=NULL;
    QMap<QString,CMapSrc *>::iterator it=m_mapSrc.find(name);
    if(it!=m_mapSrc.end())
        ret=it.value();
    return ret;
}

void CMapSrc::resetOvr()
{
    QMap<QString,CMapSrc *>::iterator pos=m_mapSrc.begin();
    while (pos != m_mapSrc.end())
    {
        QString name=pos.key();
        pos++;
        select(name,LCC_DES);
    }

}

void CMapSrc::select(QString name,int action,int nr)
{

    QMap<QString,CMapSrc *>::iterator it=m_mapSrc.find(name);
    if(it!=m_mapSrc.end())
    {
        CMapSrc *map=it.value();
        QString name=it.key();
        if(map->m_type==MAP_BAS)
        {
            if(action==LCC_SEL )
            {
                m_src=name;
                if(m_srcBox)
                    m_srcBox->setCurrentText(name);
            }
        }
        else
        {
            switch(action)
            {
            case LCC_TOG:
                map->m_useOvrs[nr]=!map->m_useOvrs[nr];
                break;
            case LCC_DES:
                map->m_useOvrs[nr]=false;
                break;
            case LCC_SEL:
                map->m_useOvrs[nr]=true;
                break;
            }
            if(map->m_type==MAP_OVR)
            {
                if(m_ovrCtrlP)
                {
                    QList<QListWidgetItem *> items=m_ovrCtrlP->findItems(map->m_name,Qt::MatchExactly);
                    if(items.size()==1)
                        items[0]->setCheckState(map->m_useOvrs[nr]?Qt::Checked:Qt::Unchecked);
                }
            }
            else if(m_ovrCtrlV)
            {
                QList<QListWidgetItem *> items=m_ovrCtrlV->findItems(map->m_name,Qt::MatchExactly);
                if(items.size()==1)
                    items[0]->setCheckState(map->m_useOvrs[nr]?Qt::Checked:Qt::Unchecked);
            }
        }
    }

}
void CMapSrc::writeTahoSelected(QTextStream &oFile, MapType type, int nr)
{
    QString name;
    switch((int)type)
    {
        case MAP_BAS:
            name=m_srcBox->currentText();
            if(!name.isEmpty())
                oFile << "\t\t<sourceName>" << name << "</sourceName>\n";
            break;
        case MAP_OVR:
        case MAP_VECT:
        case MAP_OSM:
            QMap<QString,CMapSrc*>::iterator it=CMapSrc::m_mapSrc.begin();
            while (it != CMapSrc::m_mapSrc.end())
            {
                CMapSrc *map=it.value();
                if(map->m_type==type && map->m_useOvrs[nr])
                    oFile << "\t\t<overlayName>" << name << "</overlayName>\n";
                ++it;
            }
            break;
    }
}

QString CMapSrc::getSrc()
{
    return m_srcBox->currentText();
}


/*** ------------------------------------------------------------------------ ***/
/*	bool CMapSrc::hatUnbekannteID()					*/
/*								*/
/*	Parameter:	keine															*/
/*	Ergebnis:	true wenn die Quelle eine ID enthält und diese nicht definiert ist	*/
/*	30.12.18 von Dimitri Junker	DYJ 4.07c									*/
/*** ------------------------------------------------------------------------ ***/
bool CMapSrc::hatUnbekannteID()
{

    bool ret=false;
    if(m_url.contains("{ID_",Qt::CaseInsensitive))
    {
         int indx=m_url.indexOf("{ID_");
         QString idName=m_url.mid(indx+1);
         indx=idName.indexOf("}");
         if(indx>-1)
         {
             idName.truncate(indx);
             QString idValue=COsm::m_osmIDs.value(idName,"");
             if(idValue.isEmpty())
             {
                 bool ok;
                 idValue=QInputDialog::getText(NULL,QObject::tr("Bitte ID eingeben"),idName,QLineEdit::Normal,"",&ok);
                 if(ok)
                 {
                     COsm::m_osmIDs.insert(idName,idValue);
                     writeTaho(CMapSrc::m_mySrc,true);
                 }
                 else
                 {
                     QMessageBox::warning(NULL, "", QObject::tr("Bitte andere Quelle wählen oder sich auf der Homepage anmelden"),
                                                   QMessageBox::Ok);
                    ret=true;
                 }
             }
         }
     }
    return ret;
}
