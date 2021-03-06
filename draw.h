#ifndef DRAW_H
#define DRAW_H

#include <QWidget>
#include "qpoint3d.h"
#include <QtGui>
#include "edge.h"
#include "triangle.h"
#include "iostream"
#include <QTextOption>


class Draw : public QWidget
{
    Q_OBJECT
private:
    std::vector<QPoint3D> points;
    QPolygonF polygon;
    std::vector<Edge> dt;
    std::vector<Edge> contours, main_contours;
    std::vector<Triangle> triangles;
    std::vector<QPoint3D> label_points;
    std::vector<double> directions;
    double y_max = 0.0, x_min = 999999999.0; //pro transformaci
    double y_min = 999999999.0, x_max = 0.0; //pro meritko
    double z_min = 999999999.0, z_max = 0.0; //pro souradnice
    int dz = 1;
    double max_slope, min_slope;
    int slope_param, expos_param;

public:
    explicit Draw(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void clear();
    void loadData(QString &file_name);
    void loadPolygon(QString &file_name);
    std::vector<QPoint3D> getPoints(){return points;}
    double getZmin(){return z_min;}
    double getZmax(){return z_max;}
    void setDT(std::vector<Edge> &dt_){dt = dt_;}
    void setDZ(int &dz_){dz = dz_;}
    void setMinSlope(double &minsl_){min_slope = minsl_;}
    void setMaxSlope(double &maxsl_){max_slope = maxsl_;}
    void setDirections(std::vector<double> directions_){directions = directions_;}
    std::vector<double> getDirections(){return directions;}
    void setLabelPoints(std::vector<QPoint3D> &label_points_){label_points = label_points_;}
    std::vector<QPoint3D> getLabelPoints(){return label_points;}
    std::vector<Edge> getDT(){return dt;}
    void setContours(std::vector<Edge> &contours_){contours = contours_;}
    void setMainContours(std::vector<Edge> &main_contours_){main_contours = main_contours_;}
    std::vector<Edge> getContours(){return contours;}
    std::vector<Edge> getMainContours(){return main_contours;}
    std::vector<Triangle> getTriangles(){return triangles;}
    void setTriangles(std::vector<Triangle> &triangles_){triangles = triangles_;}
    int round2num(int &numToRound, int &multiple, bool &dir);
    bool sl_exp = false, colorchanged = false;
    bool labels = false;
    bool wContours = false;
    void clearDT();
    void clearPoints();
    void setSlopeParameters(int slope_param_){slope_param = slope_param_;}
    void setExpositionParameters(int expos_param_){expos_param = expos_param_;}

signals:

public slots:
};

#endif // DRAW_H
