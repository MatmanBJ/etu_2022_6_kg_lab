// settingPanel.cpp
// This file is responsible for constructing panel with parameters and start button

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QDialog>
#include <cmath>
#include <string>

#include "../include_shapes/allshapes.h"
#include "../include_graphic/settingPanel.h"
#include "../include_graphic/mainWindow.h"
#include "../include_graphic/drawField.h"

using namespace std;

// ---------- settingPanel ----------

// constructor
SettingPanel::SettingPanel(QWidget *parent) : QWidget(parent)
{
    _par = parent;

    grid = new QGridLayout();
    grid->setHorizontalSpacing(1); // vertical interval
    grid->setVerticalSpacing(1); // horizontal interval

    // "Circle" and "Point" fields placing

    QLabel *titleCircle1 = new QLabel("Circle", this);
    grid->addWidget(titleCircle1, 0, 0, 1, 4);
    QLabel *titleCircle2 = new QLabel("Point", this);
    grid->addWidget(titleCircle2, 5, 0, 1, 4);

    // "X-coordianate (X) " and "Y-coordianate (Y) " fields placing for each dot and circle

    QLabel *Xlabel1 = new QLabel("X-coordianate (X) ", this);
    grid->addWidget(Xlabel1, 1, 0, 1, 1);
    QLabel *Xlabel2 = new QLabel("X-coordianate (X) ", this);
    grid->addWidget(Xlabel2, 6, 0, 1, 1);
    QLabel *Ylabel1 = new QLabel("Y-coordinate (Y) ", this);
    grid->addWidget(Ylabel1, 2, 0, 1, 1);
    QLabel *Ylabel2 = new QLabel("Y-coordinate (Y) ", this);
    grid->addWidget(Ylabel2, 7, 0, 1, 1);

    // "Semidiameter (R) " field placing

    QLabel *Rlabel1 = new QLabel("Semidiameter (R) ", this);
    grid->addWidget(Rlabel1, 3, 0, 1, 1);

    // fields for input values

    bX1 = new QLineEdit(this);
    grid->addWidget(bX1, 1, 1, 1, 1);
    bY1 = new QLineEdit(this);
    grid->addWidget(bY1, 2, 1, 1, 1);
    bR1 = new QLineEdit(this);
    grid->addWidget(bR1, 3, 1, 1, 1);
    bX2 = new QLineEdit(this);
    grid->addWidget(bX2, 6, 1, 1, 1);
    bY2 = new QLineEdit(this);
    grid->addWidget(bY2, 7, 1, 1, 1);

    // fields for start drawing values

    bStart = new QPushButton("DRAW", this);
    grid->addWidget(bStart, 13, 0, 4, 2);

    setLayout(grid);

    connect(bStart, &QPushButton::released, this, &SettingPanel::check_and_start);
}

// ---------- isFailed ----------

// algorithm if the checking is failed (message about reason of failing)
void SettingPanel::ifFailed(string msg)
{
    QDialog *error = new QDialog();
    error->setModal(true);
    QLabel *label = new QLabel(msg.c_str());
    QGridLayout *gr = new QGridLayout();
    gr->addWidget(label, 0, 0);
    error->setLayout(gr);
    error->show();
}

// ---------- check_and_start ----------

// treatment of input text and calling function named "non linear system" from "sup.cpp"
void SettingPanel::check_and_start()
{
    if (
        bX1->text().isEmpty() ||
        bY1->text().isEmpty() ||
        bR1->text().isEmpty() ||
        bX2->text().isEmpty() ||
        bY2->text().isEmpty()
    )
    {
        ifFailed(string("Please, input all the values"));
        return;
    }

    int x01, y01, x02, y02, r1;
    bool is_ok, res_ok = false;
    x01 = bX1->text().toInt(&is_ok);
    res_ok += !is_ok;
    y01 = bY1->text().toInt(&is_ok);
    res_ok += !is_ok;
    r1 = bR1->text().toInt(&is_ok);
    res_ok += !is_ok;
    x02 = bX2->text().toInt(&is_ok);
    res_ok += !is_ok;
    y02 = bY2->text().toInt(&is_ok);
    res_ok += !is_ok;

    res_ok = !res_ok;

    // checking error for input values is integer or not

    if (res_ok != true)
    {
        ifFailed(string("Please, input the integer values"));
        return;
    }

    // checking error for semidiameter positivity

    if (r1 <= 0)
    {
        ifFailed(string("Please, input the positive semidiameter number"));
        return;
    }

    // checking error for crossing circle borders

    double d = ((double)x01 - (double)x02)*((double)x01 - (double)x02);
    d = d + ((double)y01 - (double)y02)*((double)y01 - (double)y02);
    d = sqrt(d);
    if (d <= r1 + 0)
    {
        ifFailed(string("Please, input the point coordinates outside from the circle, not inside or on the circle"));
        return;
    }

    sOriginPlane cb(0, 0);

    sPoint xo1 = sPoint(x01, y01, cb);
    sPoint xo2 = sPoint(x02, y02, cb);

    sPoint line11 = sPoint(0, 0, cb);
    sPoint line12 = sPoint(0, 0, cb);
    sPoint line21 = sPoint(0, 0, cb);
    sPoint line22 = sPoint(0, 0, cb);
    sPoint line31 = sPoint(0, 0, cb);
    sPoint line32 = sPoint(0, 0, cb);
    sPoint line41 = sPoint(0, 0, cb);
    sPoint line42 = sPoint(0, 0, cb);

    float r = r1;
    float x_0 = x01; // center of circle
    float y_0 = y01; // center of circle
    float x_1 = x02;
    float y_1 = y02;
    float point_1[] = { 0,0 };
    float point_2[] = { 0,0 };
    float a = (x_1 - x_0) * (x_1 - x_0) + (y_0 - y_1) * (y_0 - y_1);
    float b = -2 * ((x_1 - x_0) * (r * r + x_0 * x_1 - x_0 * x_0) + x_0 * (y_0 - y_1) * (y_0 - y_1));
    float c = (r * r + x_0 * x_1 - x_0 * x_0) * (r * r + x_0 * x_1 - x_0 * x_0) + (y_0 - y_1) * (y_0 - y_1) * (x_0 * x_0 - r * r);
    float D = b * b - 4 * a * c;

    if (D > 0)
    {
        // x0 -- circle
        // x1 -- dot
        float y_h, y_l;
        point_1[0] = (sqrt(D) - b)/(2*a);
        y_h = y_0 + sqrt( r*r - (point_1[0] - x_0)*(point_1[0] - x_0) ); // y high -- "+" square root
        y_l = y_0 - sqrt( r*r - (point_1[0] - x_0)*(point_1[0] - x_0) ); // y low -- "-"" square root

        if(((point_1[0] - x_0)*(x_1 - point_1[0]) + (y_l - y_0)*(y_1 - y_l))==0)
        {
            point_1[1] = y_l;
        }
        else if (((point_1[0] - x_0)*(x_1 - point_1[0]) + (y_h - y_0)*(y_1 - y_h))==0)
        {
            point_1[1] = y_h;
        }
        else // abs (number module) is necessary
        {
            if (abs(((point_1[0] - x_0)*(x_1 - point_1[0]) + (y_l - y_0)*(y_1 - y_l)))
                >= abs(((point_1[0] - x_0)*(x_1 - point_1[0]) + (y_h - y_0)*(y_1 - y_h)))) // abs -- absolute
            {
                point_1[1] = y_h; // if y_l >= y_h => setting y_h (measurement error is less)
            }
            else // final else
            {
                point_1[1] = y_l;
            }
        }

        point_2[0] = (-sqrt(D) - b)/(2*a);
        y_h = y_0 + sqrt( r*r - (point_2[0] - x_0)*(point_2[0] - x_0) );
        y_l = y_0 - sqrt( r*r - (point_2[0] - x_0)*(point_2[0] - x_0) );
        if(((point_2[0] - x_0)*(x_1 - point_2[0]) + (y_l - y_0)*(y_1 - y_l))==0)
        {
            point_2[1] = y_l;
        }
        else if (((point_2[0] - x_0)*(x_1 - point_2[0]) + (y_h - y_0)*(y_1 - y_h))==0)
        {
            point_2[1] = y_h;
        }
        else // abs (number module) is necessary
        {
            if (abs(((point_2[0] - x_0)*(x_1 - point_2[0]) + (y_l - y_0)*(y_1 - y_l)))
                >= abs(((point_2[0] - x_0)*(x_1 - point_2[0]) + (y_h - y_0)*(y_1 - y_h))))
            {
                point_2[1] = y_h; // if y_l >= y_h => setting y_h (measurement error is less)
            }
            else // final else
            {
                point_2[1] = y_l;
            }
        }
    }
    else if (D == 0)
    {
        point_1[0] = -b / (2 * a);
        point_1[1] = y_0 + sqrt(r * r - (point_1[0] - x_0) * (point_1[0] - x_0));
        point_2[0] = point_1[0];
        point_2[1] = y_0 - sqrt(r * r - (point_1[0] - x_0) * (point_1[0] - x_0));
    }

    // setting values for sending to other function

    float res[4] = { point_1[0],point_1[1],point_2[0],point_2[1] };
    line21.setX(point_1[0]);
    line21.setY(point_1[1]);
    line22.setX(x02);
    line22.setY(y02);
    line31.setX(point_2[0]);
    line31.setY(point_2[1]);
    line32.setX(x02);
    line32.setY(y02);

    // main window update
    
    MainWindow *p = (MainWindow*)_par;

    // drawing counted values

    (p->getDrawField())->init(x01, y01, r1,
    x02, y02,
    line21.getX(), line21.getY(), line22.getX(), line22.getY(),
    line31.getX(), line31.getY(), line32.getX(), line32.getY(),
    cb);
    (p->getDrawField())->update();
}