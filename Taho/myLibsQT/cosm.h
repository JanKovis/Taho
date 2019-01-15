#ifndef COSM_H
#define COSM_H

#include <qpoint.h>
#include <qstring.h>
#include <qlist.h>
#include <QDir>
#define PI 3.1415926535897931


/*DYJ Taho 4.07d Start*/
/*DYJ  Ende; alt:
enum {NONE=-1,BAS_DIR,BAS_MAPNIK_DE,BAS_CYCLE,BAS_WIKI_OSM,BAS_HIKEB,BAS_NO_LAB,BAS_WMEDIA,ANZ_SRC};
#define  BAS_STD BAS_WIKI_OSM
enum {OVR_SEAMARK,OVR_SPORT,OVR_TOPO,OVR_LONV_H,OVR_LONV_C,ANZ_OVR};
enum {VEC_GL,VEC_SRTM,VEC_OSM,ANZ_VECT};
extern QString ObsName[];   //DYJ Taho 4.04b
extern QString SrcName[ANZ_SRC];
extern QString SrcPref[ANZ_SRC];
extern QString SrcUrl[ANZ_SRC];
extern QString SrcExt[ANZ_SRC];
extern unsigned char maxZoom[ANZ_SRC];
extern unsigned char SrcMaxThreads[ANZ_SRC];
extern QString OvrName[ANZ_OVR];
extern QString OvrUrl[ANZ_OVR];
extern unsigned char OvrMaxThreads[ANZ_OVR];

extern QString VecName[ANZ_VECT];
extern QString VecUrl[ANZ_VECT];
extern QString VecPref[ANZ_VECT];
extern int VecOffset[ANZ_VECT];
extern double VecKsize[ANZ_VECT];
extern int VecMapPF[ANZ_VECT];
extern unsigned char VecMaxThreads[ANZ_VECT];
*/


struct RGBCELL
{
    unsigned char m_rgb[3]; // A pixel
};

class COsmTag
{
public:
    QString m_value;
    QString m_key;
};
typedef QList<COsmTag>   COsmTagList;

class COsmObj
{
public:
    COsmTagList m_tags;
//DYJ Taho 4.07i     QString m_timestamp;
    bool m_visible;
    int m_uid;
    QString m_user;
    int m_changeset;
    int m_version;
    unsigned int m_id;
};
class COsmNode: public COsmObj
{
public:
    double m_lon;
    double m_lat;
};
class COsmWay: public COsmObj
{
public:
};
class COsm
{
public:
    static void rmdirRec(QString dirname);
    int getsaveVTileWithCache(int nr,QString &file,QString *pErrTxt);
    static QString URLDownloadToStr(QString &url);
    static void convGpxAscShrt(QString zielTxt,QString zielGps,QString quell,bool conv2asc,QString craetor);
    static QPoint getTileNumber(double lat, double lon, int zoom);
    /*DYJ Taho 4.07f Start*/
    int getsaveTileWithCache(int x, int y, QString &file, QString *pErrTxt=NULL, QString addExt="");
    /*DYJ  Ende; alt:
    int getsaveTileWithCache(int x, int y, QString &file, QString *pErrTxt=NULL, bool useStd QString addExt="");
    */
    COsm(int zoom,QString tilesource,QString tileExt,QString tahCache,unsigned int maxCacheDays);
    virtual ~COsm();
    static QMap<QString,QString> m_osmIDs;/*DYJ Taho 4.07c */

private:
    QString m_tahCache;
    QString m_tilesource;
    QString m_tilesourceStd;	//DYJ Taho 4.07e
    QString m_tileExt;
    int m_zoom;
    unsigned int m_maxCacheDays;
};


#endif // COSM_H
