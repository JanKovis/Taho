#ifndef CXMLFILE_H
#define CXMLFILE_H
#include <qstring.h>
enum{TRIM_LEFT=1,TRIM_RIGHT,TRIM,ELIM_TAGS};	//TRIM=TRIM_LEFT|TRIM_RIGHT

class CXmlFile
{
public:
    CXmlFile();
    int readOdsZeile(QStringList *zellen,int *start=NULL,int mode=0);
    bool read2BufFromZip(QString zipFile, QString filename);
    QString readAttrValS(QString quell, QString name);
    static void elimAllTags(QString &str);
    double readVal_dblDef(QString &quell, QString tag, double def);
    QString readAttr(QString &quell,QString tag, int *pPos=NULL);
    QString readAttr(QString tag,int *start=NULL);
    static double readAttrValD(QString quell,QString name);
    static int readVal_intDef(QString &quell, QString tag,int def=0,int *start=NULL);
    QString m_sBuf;
    unsigned long m_fileLen;
    bool read2Buf(QString pfad);
    static void trimLeft(QString &quell,QString wspaces);
    static void trimRight(QString &quell,QString wspaces);
    virtual ~CXmlFile();

    bool readValB(QString &val,QString tag,int *start=NULL,QString *attr=NULL,int opt=0);
    static bool readValB(QString &val,QString &quell,QString tag,int *start=NULL,QString *attr=NULL,int opt=0);
};

#endif // CXMLFILE_H
