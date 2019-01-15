#ifndef CMAPSRC_H
#define CMAPSRC_H

#include <qstring.h>
#include "cxmlfile.h"
#include <qmap.h>
#include <qcombobox.h>
#include <qlistwidget.h>
#include <QFile>

enum {LCC_DES,LCC_SEL,LCC_TOG,LCC_ASK};

/*DYJ Taho 4.07d Start*/
enum MapType {MAP_UNDEF=-1,MAP_BAS,MAP_OVR,MAP_VECT,MAP_OSM,MAP_DEF=100};
/*DYJ  Ende; alt:
enum MapType {MAP_OBS=-2,MAP_UNDEF,MAP_BAS,MAP_OVR,MAP_VECT,MAP_OSM};//DYJ Taho 4.04b MAP_OBS hinzugefügt
*/
class CMapSrc
{
public:
    int m_maxThreads;
    double m_kSize;
    int m_mapsPF;
    static QString m_src;
    static QString getSrc();
    static void writeTahoSelected(QTextStream &oFile, MapType type, int nr=0);
    static void select(QString name,int action=LCC_SEL,int nr=0);
    static void resetOvr();
    static CMapSrc * lookup(QString name);
    static void initBoxes(QComboBox * src,QListWidget *ovr=NULL,QListWidget *vect=NULL,int nr=0);
    static QListWidget	*m_ovrCtrlP;
    static QListWidget	*m_ovrCtrlV;
    static QComboBox * m_srcBox;
    static void destroy();
    static bool readTaho(CXmlFile *xTaho);
    static QMap<QString,CMapSrc *> m_mapSrc;
    static QString m_mySrc; //DYJ Taho 4.07c
    CMapSrc();
    /*DYJ Taho 4.07d & Taho 4.07i Start*/
    static void writeTaho(QString path, bool onlyPriv);
    static CMapSrc *initP(QString name,QString url,bool isPrivate, QString ext, int maxThreads, QString pref="", unsigned char maxZoom=255);
    static CMapSrc *initV(QString name,QString url,bool isPrivate,unsigned char maxThreads,QString pref,int offset,double kSize,int mapsPF);
    /*DYJ  Ende; alt:
    static void writeTaho(QString path);
    static CMapSrc *initP(QString name, QString url,QString timestamp, QString ext, int maxThreads, QString pref="", unsigned char maxZoom=255);
    static CMapSrc *initV(QString name,QString url,QString timestamp,unsigned char maxThreads,QString pref,int offset,double kSize,int mapsPF);
    */
    bool hatUnbekannteID();	//DYJ Taho 4.07c
        //DYJ Taho 4.07i  QString m_timestamp;
    bool m_useOvrs[2];
    int m_offset;
    unsigned char m_maxZoom;
    MapType m_type;
    QString m_pref;
    QString m_name;
    QString m_url;
    QString m_ext;
    bool m_isPrivate; 	//DYJ Taho 4.07d

    virtual ~CMapSrc();

};


#endif // CMAPSRC_H
