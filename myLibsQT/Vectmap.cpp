// Vectmap.cpp: Implementierung der Klasse CVectmap.
//
//////////////////////////////////////////////////////////////////////

#include <Vectmap.h>
#include <cosm.h>
#include <cmapsrc.h>
#include <urldownload.h>
#include <QProcess>
#include <QMessageBox>
#include <QDebug>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

CVectmap::CVectmap()
{

}

CVectmap::~CVectmap()
{

}

CVectmap::CVectmap(CGeoRect &rect, SDLM_DATA *data, CMapSrc *map)
{
	m_map=map;
	m_rect=rect;
    m_pfadI=QString("%1map/").arg(data->m_outBas);
	if(map->m_offset==-1)	//*.osm
	{
		m_pfadG="";
        m_filename=QString("%1_N%2_S%3_W%4_E%5").arg(map->m_pref).arg(rect.m_n).arg(rect.m_s).arg(rect.m_w).arg(rect.m_e);
        m_filename.replace('.','_');
		m_tileNr=-1;
		m_vectExt=".osm";
	}
	else
	{
        m_pfadG=QString("%1%2/").arg(data->m_outBas).arg(map->m_name);
		double xloop=rect.m_w+180;
		double yloop=rect.m_s+90;
	//Number = ((int)((lat + 90) / ksize) + (int)((lon + 180) / ksize) * (int)(180 / ksize)) + 63240001
		m_tileNr=int(yloop/map->m_kSize)+int(xloop/map->m_kSize)*int(180/map->m_kSize)+map->m_offset;

		
		if(data->m_nameBy==NB_COORD)
		{
            m_filename=QString("%1_lat%2_lon%3").arg(map->m_pref).arg(rect.m_s).arg(rect.m_w);
            m_filename.replace('.','_');
		}
		else
            m_filename=QString("%1_%2").arg(map->m_pref).arg(m_tileNr);
		
		m_vectExt=data->m_pictType;
	}
	m_maxCacheDays=data->m_maxCacheDays;

}

void CVectmap::LoadTile(SDLM_DATA *data,QString zfName)
{
    QString url;
	if(m_map->m_offset==-1)
	{
        url=m_map->m_url;
        QString txt;
        txt=QString("%1").arg(m_rect.m_w);
        url.replace("$W",txt);
        txt=QString("%1").arg(m_rect.m_e);
        url.replace("$E",txt);
        txt=QString("%1").arg(m_rect.m_s);
        url.replace("$S",txt);
        txt=QString("%1").arg(m_rect.m_n);
        url.replace("$N",txt);
        QString file;
        file=QString("%1%2.osm").arg(m_pfadI).arg(zfName);
        if(urlDownload::downloadFile(url, file)!=0)
		{
            data->m_errTxts.append(zfName+="<br>\r\n");
            data->errs|= ERR_PIXM_TILE;
		}
	}
	else
	{
		if(m_map->m_mapsPF)
            url=QString("%1/%2").arg(m_map->m_url).arg(m_tileNr/m_map->m_mapsPF);
		else
            url=m_map->m_url;
        COsm osm(0,url,m_map->m_ext,m_pfadG,m_maxCacheDays);
        QString tile1Path,errTxt;
		switch(osm.getsaveVTileWithCache(m_tileNr,tile1Path,&errTxt))
		{
		case 1:	//Laden erfolglos
            data->m_errTxts.append(tile1Path.mid(1)+="<br>\r\n");
            data->errs|= ERR_PIXM_TILE;
			break;
		case 2: //Laden erfolglos aber altes File vorhanden
            data->m_errTxts.append(tile1Path.mid(1)+"<br>\r\n");
            data->errs|= ERR_PIXM_TILE_OLD;
		case 0:	//OK
			//entpacken
            if(!data->m_packer.isEmpty() && !data->m_unGz.isEmpty())
			{
                QString param=data->m_unGz;
                for(int i=0;i<param.size();i++)
				{
					if(param[i]=='$')
					{
                        if(param[i+1]=='$')
                            param.remove(i);
                        else if(param[i+1]=='Z')
                        {
                            param.remove(i,2);
                            param.insert(i,"\"\"");
                            param.insert(i+1,m_pfadI);
                        }
                        else if(param[i+1]=='Q')
                        {
                            param.remove(i,2);
                            param.insert(i,"\"\"");
                            param.insert(i+1,tile1Path);
						}
					}
				}
                QString cmd="\""+data->m_packer+"\" "+param;;
                /*QProcess *mp = new QProcess();
                if(!mp->startDetached(cmd))
                {
                    QMessageBox::warning(NULL, QObject::tr("Vector-Tile"), QObject::tr("Fehler in unGz"),
                                                  QMessageBox::Ok);
                    return;
                }*/
            }
			//umbenennen
            QString quell,qfName;
            int pos=tile1Path.lastIndexOf('/');
			if(pos>-1)
			{
                qfName=tile1Path.mid(pos+1);
                pos=qfName.lastIndexOf('.');
				if(pos>-1)
                    qfName=qfName.left(pos);
                quell=m_pfadI+qfName;
                QString ziel2;
                ziel2=m_pfadI+zfName+data->m_pictType;
                QFile fi(quell);
                fi.rename(ziel2);
			}
		}
	}

}
