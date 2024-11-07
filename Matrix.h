#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <forward_list>
#include <map>
#include <iomanip>

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i]
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

namespace Matrix
{

    short RandomToFrom(short From, short To)
    {
        return rand() % (To - From + 1) + From;
    }

    void FillMatrixWithRdmNums(int Arr[3][3], short Rows, short Colms, short From, short To)
    {

        for (int Row = 0; Row < Rows; ++Row)
        {
            for (int Column = 0; Column < Colms; ++Column)
                Arr[Row][Column] = RandomToFrom(From, To);
        }

    }

    void Print_2DMatrix(int Arr[3][3], short Rows, short Colms)
    {
        for (int Row = 0; Row < Rows; ++Row)
        {
            for (int Column = 0; Column < Colms; ++Column)
            {

                printf(" %0*d  ", 2, Arr[Row][Column]);

            }
            co endl;
        }
    }

    void Print_1DMAtrix(int Arr[3], short Rows)
    {
        for (int Row = 0; Row < Rows; ++Row)
            co setw(3) o Arr[Row] o " ";
    }

    int RowSum(int Arr[3][3], short Row, short Colms)
    {
        int sum = 0;

        for (short Column = 0; Column < Colms; ++Column)
            sum += Arr[Row][Column];

        return sum;
    }

    int ColumnSum(int Arr[3][3], short Rows, short Colm)
    {
        int sum = 0;

        for (short Row = 0; Row < Rows; ++Row)
            sum += Arr[Row][Colm];

        return sum;
    }

    void PrintRowSum(int Arr[3][3], short Rows, short Colms)
    {

        for (short Row = 0; Row < 3; ++Row)
        {

            co "The Sum Of Row [" o Row + 1 o "] Is : " o setw(3) o RowSum(Arr, Row, Colms) o endl;

        }

    }

    void PrintColumnSum(int Arr[3][3], short Rows, short Colms)
    {

        for (short Column = 0; Column < Colms; ++Column)
        {

            co "The Sum Of Row [" o Column + 1 o "] Is : " o setw(3) o ColumnSum(Arr, Rows, Column) o endl;

        }

    }

    void _1DMatrixFromEachRowSum_2DM(int _2DArray[3][3], int _1DArray[3], short Rows, short Colms)
    {

        for (short Row = 0; Row < Rows; ++Row)
        {

            _1DArray[Row] = RowSum(_2DArray, Row, Colms);

        }

    }

    void _1DMatrixFromEachColumnSum_2DM(int _2DArray[3][3], int _1DArray[3], short Rows, short Colms)
    {

        for (short Column = 0; Column < Colms; ++Column)
        {

            _1DArray[Column] = ColumnSum(_2DArray, Rows, Column);

        }

    }

    void Fill_Matrix_With_Ordered_Numbers(int Arr[3][3], short Rows, short Columns)
    {

        short Counter = 0;

        for (short Row = 0; Row < Rows; ++Row)
        {
            for (short Column = 0; Column < Columns; ++Column)
            {
                ++Counter;
                Arr[Row][Column] = Counter;
            }
        }

    }

    void Transpose_Matrix(int Arr[3][3], int TranspoesedArr[3][3], short Rows, short Columns)
    {

        for (int Row = 0; Row < Rows; ++Row)
        {

            for (int Column = 0; Column < Columns; ++Column)
            {
                TranspoesedArr[Column][Row] = Arr[Row][Column];
            }

        }

    }

    void Multiply_Two_Matrix(int Arr1[3][3], int Arr2[3][3], short Rows, short Columns)
    {

        for (int Row = 0; Row < Rows; ++Row)
        {

            for (int Column = 0; Column < Columns; ++Column)
            {
                printf(" %0*d", 2, Arr1[Row][Column] * Arr2[Row][Column]);
                co "  ";
            }
            co endl;
        }

    }

    void Multiply_Two_Matrix_New_Array_Version(int Arr1[3][3], int Arr2[3][3], int NewArray[3][3], short Rows, short Columns)
    {

        for (int Row = 0; Row < Rows; ++Row)
        {

            for (int Column = 0; Column < Columns; ++Column)
            {
                NewArray[Row][Column] = Arr1[Row][Column] * Arr2[Row][Column];
            }

        }

    }

    void Print_Middle_Row(int Matrix[3][3], short Rows, short Columns)
    {

        short Middle_Row = Rows / 2;

        for (short Column = 0; Column < Columns; ++Column)
        {

            printf(" %0*d  ", 2, Matrix[Middle_Row][Column]);

        }

        co endl;

    }

    void Print_Middle_Column(int Matrix[3][3], short Rows, short Columns)
    {

        short Middle_Column = Columns / 2;

        for (short Row = 0; Row < Rows; ++Row)
        {

            printf(" %0*d  ", 2, Matrix[Row][Middle_Column]);

        }

        co endl;

    }

    int Sum_Matrix_Elements(int Matrix[3][3], short Rows, short Columns)
    {

        int sum = 0;

        for (int Row = 0; Row < Rows; ++Row)
        {

            for (int Column = 0; Column < Columns; ++Column)
            {

                sum += Matrix[Row][Column];

            }
        }

        return sum;

    }

    bool Check_Equal_Matrices(int Arr1[3][3], int Arr2[3][3], short Rows, short Columns)
    {

        return (Sum_Matrix_Elements(Arr1, Rows, Columns) == Sum_Matrix_Elements(Arr2, Rows, Columns));

    }

    bool Check_Typical_Matrices(int Arr1[3][3], int Arr2[3][3], short Rows, short Columns)
    {

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                if (Arr1[Row][Column] != Arr2[Row][Column])
                    return false;       // Is Not Typical

            }
        }

        return true;        // Is Typical

    }

    bool Check_Identity_Matrix(int Arr[3][3], short Rows, short Columns)
    {

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                if (Row == Column)
                {

                    if (Arr[Row][Column] != 1)
                        return false;

                }

                else
                {

                    if (Arr[Row][Column] != 0)
                        return false;

                }

            }

        }

        return true;
    }

    void Fill_Identity_Matrix(int Arr[3][3], short Rows, short Columns)
    {

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                if (Row == Column)
                    Arr[Row][Column] = 1;
                else
                    Arr[Row][Column] = 0;

            }

        }

    }

    bool Check_Scalar_Matrix(int Arr[3][3], short Rows, short Columns)
    {

        int First_Element = Arr[0][0];

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                if (Row == Column)
                {

                    if (Arr[Row][Column] != First_Element)
                        return false;

                }

                else
                {

                    if (Arr[Row][Column] != 0)
                        return false;

                }

            }

        }

        return true;
    }

    void Fill_Scalar_Matrix(int Arr[3][3], short Rows, short Columns, int First_Element)
    {

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                if (Row == Column)
                    Arr[Row][Column] = First_Element;
                else
                    Arr[Row][Column] = 0;

            }

        }

    }

    short Count_Number_In_Matrix(int Arr[3][3], short Rows, short Columns, int Wanted_Number)
    {
        short Counter = 0;

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                if (Arr[Row][Column] == Wanted_Number)
                    ++Counter;

            }

        }

        return Counter;

    }

    bool Check_Sparce_Matrix(int Arr[3][3], short Rows, short Columns)
    {

        short Number_0_Counter = Count_Number_In_Matrix(Arr, Rows, Columns, 0);

        if (Number_0_Counter > Rows * Columns / 2)
            return true;

        return false;
    }

    bool Check_Number_Exist_In_Matrix(int Arr[3][3], short Rows, short Columns, int Wanted_Number)
    {

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                if (Arr[Row][Column] == Wanted_Number)
                    return true;    // Exist

            }

        }

        return false;   // Not Exist

    }

    void Print_Intersected_Numbers_2Matrix(int Arr1[3][3], int Arr2[3][3], short Rows, short Columns)
    {

        int Number_To_Check;

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {
                Number_To_Check = Arr1[Row][Column];

                if (Check_Number_Exist_In_Matrix(Arr2, Rows, Columns, Number_To_Check))
                    co setw(3) o Number_To_Check o " ";

            }
        }

    }

    int Max_Number_In_Matrix(int Arr[3][3], short Rows, short Columns)
    {

        int Max_Number = Arr[0][0];

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                Max_Number = max(Max_Number, Arr[Row][Column]);

            }

        }

        return Max_Number;

    }

    int Min_Number_In_Matrix(int Arr[3][3], short Rows, short Columns)
    {

        int Min_Number = Arr[0][0];

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns; ++Column)
            {

                Min_Number = min(Min_Number, Arr[Row][Column]);

            }

        }

        return Min_Number;

    }

    bool Check_Palindrom_Matrix(int Arr[3][3], short Rows, short Columns)
    {

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column < Columns / 2; ++Column)
            {

                if (Arr[Row][Column] != Arr[Row][Columns - Column - 1])
                    return false;

            }

        }

        return true;

    }

    void Create_Palindrom_Matrix(int Arr[3][3], short Rows, short Columns, int From, int To)
    {

        for (short Row = 0; Row < Rows; ++Row)
        {

            for (short Column = 0; Column <= Columns / 2; ++Column)
            {

                Arr[Row][Column] = RandomToFrom(From, To);
                Arr[Row][Columns - Column - 1] = Arr[Row][Column];

            }

        }

    }

}