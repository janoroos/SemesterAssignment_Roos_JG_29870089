#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <vector>
#include "simplexinfo.h"
#include "dialogwindow.h"
#include "matrix.h"
#include "dialogcon.h"
#include <QDebug>
#include "dialoganswers.h"
#include <iostream>
#include <map>
#include <limits>
#include <string>
#include <bits/stdc++.h>


using namespace std;
vector <double> c;
double Zmax = 0;
double Zmin = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Variables->setText(QString::number(1));
    ui->Constraints->setText(QString::number(1));

    //DialogWindow A;

    /*SimplexInfo one;*/

    /*Matrix <double> C_N(1,one.columns);

    for (int i =0; i < 1;i++)
    {
        for (int j =0;j < one.columns; j++)
        {
            int m = A.Weight();
            C_N.put(i,j,m);
        }
    }*/

}

MainWindow::~MainWindow()
{    
    delete ui;
}


int MainWindow::Waardes()
{
    QString displayVal2 = ui-> Variables -> text();
    int n = displayVal2.toInt();
    return n;
}
int MainWindow::WaardesC()
{
    QString displayVal2 = ui-> Constraints -> text();
    int n = displayVal2.toInt();
    return n;
}

void MainWindow::on_Enter_clicked()
{   
    ui->Constraints->setText(ui->SB_C->cleanText());
    ui->Variables->setText(ui->SB_V->cleanText());

    QString displayVal = ui -> Constraints ->text();
    QString displayVal2 = ui-> Variables -> text();

    SimplexInfo object;
    object.rows = displayVal.toInt();
    object.columns = displayVal2.toInt();

    ui->Enter_C->setEnabled(true);
    ui->Enter_OF->setEnabled(true);
    ui->DisplayButton->setEnabled(true);
    ui ->pushButton->setEnabled(true);
    ui->Max->setEnabled(true);
    ui->Min->setEnabled(true);


    //ui -> Display -> setText()
}

/*vector <double> MainWindow::SimplexRoep()
{
    return c;
}*/

void MainWindow::openNew_window()
{
    dialogwindow = new DialogWindow();
    dialogwindow -> show();

}
void MainWindow::openNew_window2()
{
    dialogCon = new DialogCon();
    dialogCon -> show();
}
void MainWindow::openNew_window3()
{
    dialogAnswers = new DialogAnswers();
    dialogAnswers -> show();
}


void MainWindow::on_Enter_OF_clicked()
{
    DialogWindow object_one;

    openNew_window();
}

void MainWindow::on_Enter_C_clicked()
{
    DialogCon object_one;

    openNew_window2();

}

void MainWindow::on_DisplayButton_clicked()
{
    DialogCon object;

    vector <double> List;

    List = object.afvoer();
    int n = WaardesC()*Waardes();
    QString Afvoer = "";

    for (int i =0;i < n; i++)
    {
        Afvoer += " " + QString::number(List[i]);  
    }

    QString Max = "The maximum solution is: "+ QString::number(Zmax);
    QString Min = "The minimum solution is: "+ QString::number(Zmin);
    ui->Display->setText(Max);
    ui->Display2->setText(Min);
    //ui->Display->setText(QString::number(Zmax));
    qDebug() << List;
}

void MainWindow::on_pushButton_clicked()
{

    DialogAnswers object_one;

    openNew_window3();
}
/*void MainWindow:: Calculations()
{
    vector <double> NV;
    int rows,columns;

    DialogCon object_one;

    NV = object_one.afvoer();
    rows = WaardesC();
    columns = Waardes();

    Matrix <double> N(rows,columns);


    int counter = 0;

    for (int i =0;i < rows;i++)
    {
        for (int j =0;j<columns;j++) {
            N.put(i,j,NV[counter]);
            counter++;
        }
    }
    counter =0;


}*/

void MainWindow::on_Max_clicked()
{
    DialogWindow object1;
    DialogCon object2;
    DialogAnswers object3;

    bool request =true;
    int k = 0;
    vector <double> list_OF;
    vector <double> list_Con;
    vector <double> list_An;

    int row = WaardesC();
    int Col = Waardes();

    list_OF = object1.afvoer1();
    list_Con = object2.afvoer();
    list_An = object3.afvoer3();

    qDebug() << list_OF;
    qDebug() << list_Con;
    qDebug() << list_An;

    Matrix <double> B(row, row);
    Matrix <double> b(row,1);
    Matrix <double> N(row,Col);
    Matrix <double> C_N(1, Col);
    Matrix <double> C_B(1, row);

    double m;

    int counter = 0;
    for(int i = 0; i < row;i++)
    {
        for(int j = 0; j <Col;j++)
        {
            N.put(i,j,list_Con[counter]);
            counter++;
        }
    }
    counter = 0;
    for(int i = 0; i < 1;i++)
    {
        for(int j = 0; j < Col;j++)
        {
            C_N.put(i,j,list_OF[counter]);
            counter++;
        }
    }


    for(int i = 0; i < row;i++)
    {
        for(int j = 0; j < row;j++)
        {
            if(i = j)
            {
                B.put(i,j,1);
            }
            else if(j == 0 && i == 0){
                B.put(i,j,1);
            }
            else
            {
                B.put(i,j,0);
            }
        }
    }
    for (int i = 0;i<row;i++)
    {
        C_B.put(0,i,0);
    }


        /*Answers input*/
    counter = 0;
    for(int i = 0; i < row;i++)
    {
        for(int j = 0; j < 1;j++)
        {
            b.put(i,j,list_An[counter]);
            counter++;
        }
    }
    counter = 0;

    double Zalt = -999;
    Matrix <double> B_inverse (row, row);

        do{
            request = false;
            B_inverse = B.getInverse();

            /*cout << "B = " << B << endl;
            cout << "b = " << b << endl;
            cout << "N = " << N << endl;
            cout << "B_inverse = " << B_inverse <<endl;
            cout << "Cn =" << C_N << endl;*/

            Matrix <double> t1(row,Col);
            Matrix <double> t2(1, Col);
            Matrix <double> t3(1, Col);

            t1 = B_inverse*N;
            t2 = C_B * t1;





            /*cout << t1 <<endl;
            cout <<"\n\n" <<t2 <<endl;*/

            t3 = C_N - t2;

            /*cout << "\n\n" << t3 <<endl;*/

            vector <double> Temp;

            for(int i = 0; i < Col;i++)
            {
                Temp.push_back(t3.get(0,i));
            }


            int maxelement_index = std::max_element(Temp.begin(),Temp.end())-Temp.begin();
            int C = maxelement_index;

            qDebug() << "Max element index = " << maxelement_index <<endl;

            vector <double> ColumN;
            vector <double> ColumnB;

            for(int i =0; i < row ;i++)
            {
                double m = 0;
                m = N.get(i,C);
                ColumN.push_back(m);
            }

            /*cout << "Column in:" << endl;*/
            //qDebug() << ColumN<<endl;

            Matrix <double> X_B;
            Matrix <double> B_1A1;
            Matrix <double> A1(row,1);
            vector <double> Colout;

            for(int i = 0; i <row;i++)
            {
                int m = 0;
                m = ColumN[i];
                A1.put(i,0,m);
            }
/*----------for (int i = 0;i<row;i++) {
                qDebug() << "A1: "<< A1.get(i,0) <<endl;
------------}*/



            X_B = B_inverse*b;
            B_1A1 = B_inverse*A1;
            Matrix <double> Z = C_B*X_B;
            qDebug() << Z.get(0,0)<<endl;
            double z = Z.get(0,0);


            if(z > Zalt)
            {
                Zalt = z;
            }

            qDebug() <<"Zalt =" <<Zalt;

            for(int i = 0; i < row; i++)
            {
                double m = 0;
                m = X_B.get(i,0)/B_1A1.get(i,0);
                Colout.push_back(m);
            }
            //cout << "Column out is: " <<endl;
            //qDebug() << Colout <<endl;


            double smallest_number = 99999999;
            double index;

            for(int i =0; i <row;i++)
            {
                if((Colout[i] < smallest_number) &&(Colout[i] > 0))
                {
                    smallest_number = Colout[i];
                    index =  i;
                }
            }


            /*qDebug() << "Smallest number in vector is = "<<smallest_number<<endl;
            qDebug() << "At position = "<<index<<endl;*/
            /*cout << "Xb = "<<X_B<<endl;
            cout << "B_1A1 = "<<B_1A1<<endl;*/


            for(int i = 0; i <row ;i++)
            {
                double M;
                M = B.get(i,index);
                ColumnB.push_back(M);
            }
            //qDebug() << ColumnB << " " <<endl;

            for(int i = 0; i <row ;i++)
            {
                N.put(i,C,ColumnB[i]);
                B.put(i,index,ColumN[i]);
            }

            double cb = C_B.get(0,index);
            double cn = C_N.get(0,C);

            C_N.put(0,C,cb);
            C_B.put(0,index,cn);


            if(k<10)
            {
                request = true;
                cout << "Max value of itteration "<< k+1 <<": "<<Zalt<<endl;

            }
            else{
                qDebug() << "The maximum value is: " << Zalt <<endl;
            }
            k++;

        }while(request);

    Zmax = Zalt;
}



void MainWindow::on_Min_clicked()
{
    DialogWindow object1;
    DialogCon object2;
    DialogAnswers object3;

    double m;
    bool request =true;
    int k = 0;
    vector <double> list_OF;
    vector <double> list_Con;
    vector <double> list_An;

    int row = Waardes();
    int Col = WaardesC();

    list_OF = object1.afvoer1();
    list_Con = object2.afvoer();
    list_An = object3.afvoer3();

   /* qDebug() << list_OF;
    qDebug() << list_Con;
    qDebug() << list_An;*/



    Matrix <double> N(row,Col);
        Matrix <double> B(row,row);
        Matrix <double> C_B(1,row);
        Matrix <double> C_N(1,Col);
        Matrix <double> b(row,1);


        int counter = 0;
        for(int i = 0; i < Col; i++)
        {
            for(int j = 0; j < row;j++)
            {
                N.put(j,i,list_Con[counter]);
                counter++;
            }
        }

        counter = 0;
        for(int i = 0; i < row  ; i++)
        {
            for(int j = 0; j < 1 ;j++)
            {
                b.put(i,j,list_OF[counter]);
                counter++;
            }
        }

        counter=0;
        for(int i = 0; i < 1  ; i++)
        {
            for(int j = 0; j < Col ;j++)
            {
                C_N.put(i,j,list_An[counter]);
                counter++;
            }
        }

        for(int i = 0; i < row;i++)
        {
            for(int j =0;j<row;j++)
            {
                if((i == 0)&&(j == 0))
                {
                    B.put(i,j,1);
                }
                else if(i==j)
                {
                    B.put(i,j,1);
                }
                else
                {
                    B.put(i,j,0);
                }
            }
        }

        for(int i = 0; i < row;i++)
        {
            C_B.put(0,i,0);
        }

        counter = 0;

        double Zalt = -999;
        Matrix <double> B_inverse (row, row);

        do{
                request = false;
                B_inverse = B.getInverse();

                cout << "B = " << B << endl;
                cout << "b = " << b << endl;
                cout << "N = " << N << endl;
                cout << "B_inverse = " << B_inverse <<endl;
                cout << "Cn =" << C_N << endl;

                Matrix <double> t1(row,Col);
                Matrix <double> t2(1, Col);
                Matrix <double> t3(1, Col);

                t1 = B_inverse*N;
                t2 = C_B * t1;





                /*cout << t1 <<endl;
                cout <<"\n\n" <<t2 <<endl;*/

                t3 = C_N - t2;

                /*cout << "\n\n" << t3 <<endl;*/

                vector <double> Temp;

                for(int i = 0; i < Col;i++)
                {
                    Temp.push_back(t3.get(0,i));
                }


                int maxelement_index = std::max_element(Temp.begin(),Temp.end())-Temp.begin();
                int C = maxelement_index;

                cout << "Max element index = " << maxelement_index <<endl;

                vector <double> ColumN;
                vector <double> ColumnB;

                for(int i =0; i < row ;i++)
                {
                    double m = 0;
                    m = N.get(i,C);
                    ColumN.push_back(m);
                }

                /*cout << "Column in:" << endl;*/
                //qDebug() << ColumN<<endl;

                Matrix <double> X_B;
                Matrix <double> B_1A1;
                Matrix <double> A1(row,1);
                vector <double> Colout;

                for(int i = 0; i <row;i++)
                {
                    int m = 0;
                    m = ColumN[i];
                    A1.put(i,0,m);
                }
    /*----------for (int i = 0;i<row;i++) {
                    qDebug() << "A1: "<< A1.get(i,0) <<endl;
    ------------}*/



                X_B = B_inverse*b;
                B_1A1 = B_inverse*A1;
                Matrix <double> Z = C_B*X_B;
                cout<< Z<<endl;
                double z = Z.get(0,0);


                if(z > Zalt)
                {
                    Zalt = z;
                }

                cout <<"Zalt =" <<Zalt;

                for(int i = 0; i < row; i++)
                {
                    double m = 0;
                    m = X_B.get(i,0)/B_1A1.get(i,0);
                    Colout.push_back(m);
                }
                //cout << "Column out is: " <<endl;
                //qDebug() << Colout <<endl;


                double smallest_number = 99999999;
                double index;

                for(int i =0; i <row;i++)
                {
                    if((Colout[i] < smallest_number) &&(Colout[i] > 0))
                    {
                        smallest_number = Colout[i];
                        index =  i;
                    }
                }


                /*qDebug() << "Smallest number in vector is = "<<smallest_number<<endl;
                qDebug() << "At position = "<<index<<endl;*/
                /*cout << "Xb = "<<X_B<<endl;
                cout << "B_1A1 = "<<B_1A1<<endl;*/


                for(int i = 0; i <row ;i++)
                {
                    double M;
                    M = B.get(i,index);
                    ColumnB.push_back(M);
                }
                //qDebug() << ColumnB << " " <<endl;

                for(int i = 0; i <row ;i++)
                {
                    N.put(i,C,ColumnB[i]);
                    B.put(i,index,ColumN[i]);
                }

                double cb = C_B.get(0,index);
                double cn = C_N.get(0,C);

                C_N.put(0,C,cb);
                C_B.put(0,index,cn);

                /*char reQ;
                cout << "Run another itteration" <<endl;
                cin>> reQ;*/

                if(k <5)
                {
                    request = true;
                    cout << "Max value of itteration "<< k+1 <<": "<<Zalt<<endl;
                }
                else{
                    cout << "The maximum value is: " << Zalt <<endl;
                }
                k++;

            }while(request);

    Zmin = Zalt;

}
