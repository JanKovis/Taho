#ifndef CGEOPOINT_H
#define CGEOPOINT_H

class CGeoPoint
{
public:
    void invalidate();
    void init(double lat, double lon, double maxLat=90);
    CGeoPoint(double lat, double lon, double maxLat=90);
    double m_lon;
    double m_lat;
    CGeoPoint();
    virtual ~CGeoPoint();};

#endif // CGEOPOINT_H
