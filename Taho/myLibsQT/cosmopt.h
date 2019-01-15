#ifndef COSMOPT_H
#define COSMOPT_H
#include <qstring.h>
#include <QRadioButton>

/*DYJ Taho 4.07d Start*/
#define T_SRC "defsrcP.taho"
/*DYJ  Ende; alt:
#define T_SRC "defsrc.taho"
*/
#define T_MY_SRC "mydefsrc.taho"

class COsmOpt
{
public:
//2doua    QString m_useragent[3];
    int m_uaID;
    void initSrc();
    QString defPath();
    QString defPath(bool defPathIsPrg);
//DYJ Taho 4.07d 	    bool m_reloadSrc;
    bool OnUpdSrc();
    bool loadTahoSrc(QString path,QString *sTaho=NULL,QString errOld="");
    bool loadTahoSrc(bool defPathisPrg);
    bool loadTahoSrc();  //DYJ Taho 4.07d
//DYJ Taho 4.07d     void expSrc();
    static QString m_par;
    static QString m_prgPath;
    static QString m_persPath;
    static QString m_srcPath; //DYJ Taho 4.07d
    static QString m_tmpDir;
    COsmOpt();
//DYJ DYJTrack 2.07j 	    void setDefPathIsPrg(bool isPrg);
//DYJ DYJTrack 2.07j 	    bool getDefPathIsPrg();
//DYJ Taho 4.07j     QRadioButton *m_pDefPrg;
//DYJ Taho 4.07j     QRadioButton *m_pDefED;
//    virtual ~COsmOpt();

};

#endif // COSMOPT_H
