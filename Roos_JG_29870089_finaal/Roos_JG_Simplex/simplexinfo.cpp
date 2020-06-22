#include "simplexinfo.h"
#include "matrix.h"
#include <iostream>
#include "mainwindow.h"
#include <vector>
#include "dialoganswers.h"
#include "dialogcon.h"
#include "dialogwindow.h"

using namespace std;

SimplexInfo::SimplexInfo()
{
    int rows;
    int columns;

    DialogCon one;
    DialogWindow two;
    DialogAnswers three;

    Matrix <double> B(rows,rows);
    Matrix <double> C_B(1,rows);
    Matrix <double> C_N(1,columns);

    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < rows;j++)
        {
            if (i ==0 && j ==0)
            {
                B.put(i,j,1);
            }
            else if (i ==j)
            {
                B.put(i,j,1);
            }
            else
            {
                B.put(i,j,0);
            }
        }
    }
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < rows;j++)
        {
            C_B.put(i,j,0);
        }
    }

    MainWindow object;
    //vector <double> m = object.SimplexRoep();*/

}
/*SimplexInfo::Simplex()
{

};*/

