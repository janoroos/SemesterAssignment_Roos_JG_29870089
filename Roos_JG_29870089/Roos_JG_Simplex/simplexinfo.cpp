#include "simplexinfo.h"
#include "matrix.h"
#include <iostream>

using namespace std;

SimplexInfo::SimplexInfo()
{
    int rows;
    int columns;

    Matrix <double> B(3,3);
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



}
/*SimplexInfo::Matrix_()
{

}*/
