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
#include "String.h"

using namespace std;
using namespace String;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i]
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

namespace String
{

    struct stTime
    {

        short Year = 0;
        short Days = 0;
        int Hours = 0;
        int Minutes = 0;
        int Seconds = 0;

    };

    struct stDate
    {

        short Year = 0;
        short Month = 0;
        short Day = 0;

    };

    struct Periode
    {

        stDate Start_Periode;
        stDate End_Periode;

    };

    enum enMonth { Jan = 1, Feb, March, April, May, Jun, July, Aug, Sep, Oct, Nov, Dec };

    enum enDay { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

    enum enDate_Compare { Before = -1, Equal, After };

    bool Is_Validate_Date(short Day, short Month, short Year);

    bool Is_Validate_Date(stDate);

    string Op_Number_To_Text(ll Number)
    {

        if (Number < 0)
            return "Negative " + Op_Number_To_Text(-1 * Number);

        if (Number == 0)
            return "";

        if (Number <= 9)
        {

            string Digit_1[10] = { "", "One", "Two", "Three", "Four", "Five",
                                   "Six", "Seven", "Eight", "Nine" };

            return Digit_1[Number];

        }

        if (Number <= 19)
        {

            string Digit_2[10] = { "Ten", "Eleven", "Twelve", "Therteen", "Fourteen", "Fifteen",
                                   "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

            return Digit_2[Number % 10];

        }

        if (Number <= 99)
        {

            string Digit_2[10] = { "", "", "Twenty", "Therty", "Fourty", "Fifty",
                                   "Sixty", "Seventy", "Eighty", "Ninety" };

            return Digit_2[Number / 10] + " " + Op_Number_To_Text(Number % 10);

        }

        if (Number <= 999)
        {

            return Op_Number_To_Text(Number / 100) + " Hundred " + Op_Number_To_Text(Number % 100);

        }

        if (Number <= 999999)
        {

            return Op_Number_To_Text(Number / 1000) + " Thousand " + Op_Number_To_Text(Number % 1000);

        }

        if (Number <= 999999999)
        {

            return Op_Number_To_Text(Number / 1000000) + " Milion " + Op_Number_To_Text(Number % 1000000);

        }

        if (Number <= 999999999)
        {

            return Op_Number_To_Text(Number / 1000000) + " Milion " + Op_Number_To_Text(Number % 1000000);

        }

        if (Number <= 999999999999)
        {

            return Op_Number_To_Text(Number / 1000000000) + " Bilion " + Op_Number_To_Text(Number % 1000000000);

        }

        if (Number <= 999999999999999)
        {

            return Op_Number_To_Text(Number / 1000000000000) + " Trilion " + Op_Number_To_Text(Number % 1000000000000);

        }

    }

    string Number_To_Text(ll Number)
    {

        if (Number == 0)
            return "Zero";
        else
            return Op_Number_To_Text(Number);

    }

    bool IsLeap_Year(short Year)
    {

        return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);

    }

    stTime Year_To_Time(short Year)
    {

        stTime Time;


        Time.Days = IsLeap_Year(Year) ? 366 : 365;

        Time.Hours = Time.Days * 24;

        Time.Minutes = Time.Hours * 60;

        Time.Seconds = Time.Minutes * 60;


        return Time;

    }

    short Number_Of_Days_In_Year(short Year)
    {

        return IsLeap_Year(Year) ? 366 : 365;

    }

    int Number_Of_Hours_In_Year(short Year)
    {

        return Number_Of_Days_In_Year(Year) * 24;

    }

    int Number_Of_Minutes_In_Year(short Year)
    {

        return Number_Of_Hours_In_Year(Year) * 60;

    }

    int Number_Of_Seconds_In_Year(short Year)
    {

        return Number_Of_Minutes_In_Year(Year) * 60;

    }

    short Number_Of_Days_In_Month(short Month, short Year)
    {

        if (Month < 1 || Month > 12)
            return 0;

        short Number_Of_Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        return (Month == 2) ? (IsLeap_Year(Year) ? 29 : 28) : Number_Of_Days[Month - 1];

    }

    short Number_Of_Hours_In_Month(short Month, short Year)
    {

        return Number_Of_Days_In_Month(Month, Year) * 24;

    }

    int Number_Of_Minutes_In_Month(short Month, short Year)
    {

        return Number_Of_Hours_In_Month(Month, Year) * 60;

    }

    int Number_Of_Seconds_In_Month(short Month, short Year)
    {

        return Number_Of_Minutes_In_Month(Month, Year) * 60;

    }

    string Day_Name(short Day_Of_Week_Order)
    {

        if (Day_Of_Week_Order > 6 || Day_Of_Week_Order < 0)
            return "";

        string Day[8] = { "", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return Day[Day_Of_Week_Order];

    }

    string Day_Short_Name(short Day_Of_Week_Order)
    {

        if (Day_Of_Week_Order > 6 || Day_Of_Week_Order < 0)
            return "";

        string Short_Days[8] = { "", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return Short_Days[Day_Of_Week_Order];

    }

    short Day_Of_WeekOrder(short Day, short Month, short Year)
    {

        if (Day < 1 || Day > 31 || Month < 1 || Month > 12)
            return -1;

        short a = (14 - Month) / 12;
        Year -= a;
        Month += 12 * a - 2;

        return (Day + Year + (Year / 4) - (Year / 100) + (Year / 400) + (31 * Month / 12)) % 7 + 1;

    }

    short Day_Of_WeekOrder(stDate Date)
    {

        return Day_Of_WeekOrder(Date.Day, Date.Month, Date.Year);

    }

    int Day_To_Day_Of_WeekOrder(string Day)
    {

        string Days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        string Short_Days[8] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        for (int i = 0; i < 6; ++i)
        {

            if (Days[i] == Day || Short_Days[i] == Day)
                return i + 1;

        }

    }

    string Date_To_String(short Day, short Month, short Year, bool Global = 1)
    {

        if (!Is_Validate_Date(Day, Month, Year))
            return "";

        if (Global)
            return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
        else
            return to_string(Month) + "/" + to_string(Day) + "/" + to_string(Year);

    }

    string Date_To_String(stDate Date, bool Global = 1)
    {

        return Date_To_String(Date.Day, Date.Month, Date.Year, Global);

    }

    stDate String_To_stDate(string str)
    {

        stDate Date;

        vector <string> v = Split(str, "/");


        if (v.size() == 3)
        {

            Date.Year = stoi(v.back()); v.pop_back();
            Date.Month = stoi(v.back()); v.pop_back();
            Date.Day = stoi(v.back()); v.pop_back();

        }

        if (Is_Validate_Date(Date))
            return Date;
        else
            return { 0, 0, 0 };

    }

    string Month_Short_Name(short Month)
    {

        if (Month < 1 || Month > 12)
            return "";

        string Month_Na[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

        return Month_Na[Month - 1];

    }

    void Month_Calender(short Month, short Year)
    {

        co " ";  Print_UnderScore(15); co Month_Short_Name(Month); Print_UnderScore(16); co endl o endl;


        co " Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        short Days = Number_Of_Days_In_Month(Month, Year);

        short Day_WeekkOrder = Day_Of_WeekOrder(1, Month, Year) - 1;

        co " "; Print_Spaces(Day_WeekkOrder * 5); co "01   ";

        ++Day_WeekkOrder;


        for (int Day = 2; Day <= Days; ++Day)
        {

            if (Day_WeekkOrder % 7 == 0)
                co endl o " ";

            printf("%0*d   ", 2, Day);

            ++Day_WeekkOrder;

        }

        co endl;

        co " "; Print_UnderScore(34); co endl;

    }

    void Year_Calender(short Year)
    {

        co " ";  Print_UnderScore(34); co endl;
        co " "; Print_Spaces(10); co "Calender - " o Year o endl;
        co " ";  Print_UnderScore(34); co endl o endl;

        for (int Month = 1; Month <= 12; ++Month)
        {

            Month_Calender(Month, Year);
            co endl;

        }

    }

    short Number_Of_Days_From_TheBeginingOfTheYear(short Day, short Month, short Year)
    {

        short Total_Days = 0;

        for (int i = 1; i < Month; ++i)
        {
            Total_Days += Number_Of_Days_In_Month(i, Year);
        }

        Total_Days += Day;

        return Total_Days;

    }

    short Number_Of_Days_From_TheBeginingOfTheYear(stDate Date)
    {

        short Day = Date.Day, Month = Date.Month, Year = Date.Year;

        short Total_Days = 0;

        for (int i = 1; i < Month; ++i)
        {
            Total_Days += Number_Of_Days_In_Month(i, Year);
        }

        Total_Days += Day;

        return Total_Days;

    }

    stDate Date_From_Number_Of_Days_From_TheBeginingOfTheYear(short Days, short Year)
    {

        stDate Date;

        short Month = 1;

        short Days_In_Month;

        while (true)
        {
            Days_In_Month = Number_Of_Days_In_Month(Month, Year);

            if (Days > Days_In_Month)
                Days -= Number_Of_Days_In_Month(Month, Year), ++Month;
            else
                break;

        }

        Date.Day = Days;
        Date.Month = Month;
        Date.Year = Year;

        return Date;

    }

    stDate Add_Days_To_Date(short Day, short Month, short Year, int DaysToAdd)
    {

        stDate Date = { Year, Month, Day };

        short Day_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year);

        DaysToAdd += Number_Of_Days_From_TheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

        Date.Month = 1;

        while (DaysToAdd > (Day_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year)))
        {

            DaysToAdd -= Day_In_Month;

            ++Date.Month;

            if (Date.Month == 13)
            {

                Date.Month = 1;
                ++Date.Year;

            }

        }

        Date.Day = DaysToAdd;

        return Date;

    }

    stDate Add_Days_To_Date(stDate& Date, int DaysToAdd)
    {

        short Day_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year);

        DaysToAdd += Number_Of_Days_From_TheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);

        Date.Month = 1;

        while (DaysToAdd > (Day_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year)))
        {

            DaysToAdd -= Day_In_Month;

            ++Date.Month;

            if (Date.Month == 13)
            {

                Date.Month = 1;
                ++Date.Year;

            }

        }

        Date.Day = DaysToAdd;

        return Date;

    }

    short Check_Is_Date1_Aft_Eq_Bef_Date2(stDate Date1, stDate Date2)
    {

        if (Date1.Year > Date2.Year)
        {
            return 1;
        }

        if (Date1.Year < Date2.Year)
        {
            return -1;
        }

        if (Date1.Month > Date2.Month)
        {
            return 1;
        }

        if (Date1.Month < Date2.Month)
        {
            return -1;
        }

        if (Date1.Day > Date2.Day)
        {
            return 1;
        }

        if (Date1.Day < Date2.Day)
        {
            return -1;
        }

        return 0;

    }

    bool Is_Last_Day(stDate Date)
    {

        return (Date.Day == Number_Of_Days_In_Month(Date.Month, Date.Year));

    }

    bool Is_Last_Month(stDate Date)
    {

        return (Date.Month == 12);

    }

    bool Is_Last_Month(short Month)
    {

        return (Month == 12);

    }

    stDate NewDay_In_Date(stDate Date)
    {

        if (Is_Last_Day(Date))
        {

            if (Is_Last_Month(Date.Month))
            {

                Date.Day = 1;
                Date.Month = 1;
                ++Date.Year;

            }
            else
            {

                Date.Day = 1;
                ++Date.Month;

            }

        }
        else
        {

            ++Date.Day;

        }

        return Date;

    }

    void SwapDate(stDate& Date1, stDate& Date2)
    {

        stDate TempDate = Date1;
        Date1 = Date2;
        Date2 = TempDate;

    }

    int Diffrence_Between_2Dates_By_Days(stDate Date1, stDate Date2, bool Include_End_Day = 0)
    {

        short Before = 1;

        // Diffrence From Date1 To Date2

        if (Check_Is_Date1_Aft_Eq_Bef_Date2(Date1, Date2) == 1)
        {

            SwapDate(Date1, Date2);

            Before = -1;

        }

        int Days = 0;

        if (Date1.Year != Date2.Year)
        {
            Days = Number_Of_Days_From_TheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year)
                + (Number_Of_Days_In_Year(Date1.Year)
                    - Number_Of_Days_From_TheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year));

            ++Date1.Year;

            while (Date1.Year < Date2.Year)
            {

                if (!IsLeap_Year(Date1.Year))
                    ++Date1.Year, Days += 365;
                else
                {
                    ++Date1.Year, Days += 366; break;
                }

            }

            Days += (Date2.Year - Date1.Year) / 4;

            Days += (Date2.Year - Date1.Year) * 365;

        }
        else
        {
            Days = Number_Of_Days_From_TheBeginingOfTheYear(Date2.Day, Date2.Month, Date2.Year)
                - Number_Of_Days_From_TheBeginingOfTheYear(Date1.Day, Date1.Month, Date1.Year);
        }

        return Include_End_Day ? ++Days * Before : Days * Before;

    }

    stDate Local_Time()
    {
        std::time_t now = std::time(0);

        std::tm* local_time = std::localtime(&now);

        return { short(local_time->tm_year + 1900), short(local_time->tm_mon + 1), short(local_time->tm_mday) };

    }

    int Birthday_To_Age_In_Days(stDate Birthday, bool Include_End_Day = 0)
    {

        return Diffrence_Between_2Dates_By_Days(Birthday, Local_Time(), Include_End_Day);

    }

    stDate Get_Date()
    {

        stDate Date;

        printf("Inter The Day : "); ci Date.Day;
        printf("Inter The Month : "); ci Date.Month;
        printf("Inter The Year : "); ci Date.Year;

        while (!Is_Validate_Date(Date))
        {

            printf("Ops! Inter Validate Date : \n");
            printf("Inter The Day : "); ci Date.Day;
            printf("Inter The Month : "); ci Date.Month;
            printf("Inter The Year : "); ci Date.Year;

        }

        co endl;

        return Date;

    }

    void Add_OneDay_To_Date(stDate& Date)
    {

        Add_Days_To_Date(Date, 1);

    }

    void Add_XDays_To_Date(stDate& Date, short x)
    {

        Add_Days_To_Date(Date, x);

    }

    void Add_OneWeek_To_Date(stDate& Date)
    {

        Add_Days_To_Date(Date, 7);

    }

    void Add_XWeeks_To_Date(stDate& Date, short x)
    {

        Add_Days_To_Date(Date, 7 * x);

    }

    void Add_OneMonth_To_Date(stDate& Date)
    {

        ++Date.Month;

        if (Date.Month == 13)
            Date.Month = 1, ++Date.Year;

        int Days_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year);

        if (Days_In_Month < Date.Day)
            Date.Day = Days_In_Month;


    }

    void Add_XMonths_To_Date(stDate& Date, short x)
    {

        while (x--)
            Add_OneMonth_To_Date(Date);

    }

    void Add_OneYear_To_Date(stDate& Date)
    {

        ++Date.Year;

        int Days_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year);

        if (Days_In_Month < Date.Day)
            Date.Day = Days_In_Month;

    }

    void Add_XYears_To_Date(stDate& Date, short x)
    {

        Date.Year += x;

        int Days_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year);

        if (Days_In_Month < Date.Day)
            Date.Day = Days_In_Month;

    }

    void Add_OneDecade_To_Date(stDate& Date)
    {

        Date.Year += 10;

    }

    void Add_XDecades_To_Date(stDate& Date, short x)
    {

        Date.Year += 10 * x;

    }

    void Add_OneCentury_To_Date(stDate& Date)
    {

        Date.Year += 100;

    }

    void Add_XCenturies_To_Date(stDate& Date, short x)
    {

        Date.Year += 100 * x;

    }

    void Add_OneMillennium_To_Date(stDate& Date)
    {

        Date.Year += 1000;

    }

    void Decrease_OneDay_To_Date(stDate& Date)
    {

        Add_Days_To_Date(Date, -1);

    }

    void Decrease_XDays_To_Date(stDate& Date, short x)
    {

        Add_Days_To_Date(Date, -x);

    }

    void Decrease_OneWeek_To_Date(stDate& Date)
    {

        Add_Days_To_Date(Date, -7);

    }

    void Decrease_XWeeks_To_Date(stDate& Date, short x)
    {

        Add_Days_To_Date(Date, 7 * -x);

    }

    void Decrease_OneMonth_To_Date(stDate& Date)
    {

        --Date.Month;

        if (Date.Month == 0)
            Date.Month = 12, --Date.Year;

        int Days_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year);

        if (Days_In_Month < Date.Day)
            Date.Day = Days_In_Month;


    }

    void Decrease_XMonths_To_Date(stDate& Date, short x)
    {

        while (x--)
            Decrease_OneMonth_To_Date(Date);

    }

    void Decrease_OneYear_To_Date(stDate& Date)
    {

        --Date.Year;

        int Days_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year);

        if (Days_In_Month < Date.Day)
            Date.Day = Days_In_Month;

    }

    void Decrease_XYears_To_Date(stDate& Date, short x)
    {

        Date.Year -= x;

        int Days_In_Month = Number_Of_Days_In_Month(Date.Month, Date.Year);

        if (Days_In_Month < Date.Day)
            Date.Day = Days_In_Month;

    }

    void Decrease_OneDecade_To_Date(stDate& Date)
    {

        Date.Year -= 10;

    }

    void Decrease_XDecades_To_Date(stDate& Date, short x)
    {

        Date.Year -= 10 * x;

    }

    void Decrease_OneCentury_To_Date(stDate& Date)
    {

        Date.Year -= 100;

    }

    void Decrease_XCenturies_To_Date(stDate& Date, short x)
    {

        Date.Year -= 100 * x;

    }

    void Decrease_OneMillennium_To_Date(stDate& Date)
    {

        Date.Year -= 1000;

    }

    bool Is_End_Of_Week(stDate Date)
    {

        return Day_Of_WeekOrder(Date) == 7;

    }

    bool Is_Weekend(stDate Date)
    {

        return Day_Of_WeekOrder(Date) == 6;

    }

    bool Is_Weekend(short Day)
    {

        return Day == 6;

    }

    bool Is_BusinessDay(stDate Date)
    {

        return !Is_Weekend(Date);

    }

    bool Is_BusinessDay(short Day)
    {

        return !Is_Weekend(Day);

    }

    short Days_Until_The_End_Of_Week(stDate Date)
    {

        return Day_To_Day_Of_WeekOrder("Saturday") - Day_Of_WeekOrder(Date);

    }

    short Days_Until_End_Of_Month(stDate Date)
    {

        return Number_Of_Days_In_Month(Date.Month, Date.Year) - Date.Day + 1;

    }

    short Days_Until_End_Of_Year(stDate Date)
    {

        return Year_To_Time(Date.Year).Days - Number_Of_Days_From_TheBeginingOfTheYear(Date) + 1;

    }

    int Periode_Length_In_Days(Periode Period, bool Include_End_Day = 0)
    {

        return Diffrence_Between_2Dates_By_Days(Period.Start_Periode, Period.End_Periode, Include_End_Day);

    }

    int Actual_Days_Vacation(stDate Date1, stDate Date2)
    {

        int Actual = 0;
        int Day = Day_Of_WeekOrder(Date1);

        if (Check_Is_Date1_Aft_Eq_Bef_Date2(Date1, Date2) == 1)
            return Actual;

        for (; Check_Is_Date1_Aft_Eq_Bef_Date2(Date1, Date2); ++Day, Add_OneDay_To_Date(Date1))
        {

            if (Is_BusinessDay(Day))
                ++Actual;

            if (Day == 8)
                Day = 1;

        }

        return Actual;

    }

    stDate Holiday_In_Days_To_Date(stDate Date, int Days)
    {

        int Day = Day_Of_WeekOrder(Date);

        for (; Days != 0; ++Day, Add_OneDay_To_Date(Date))
        {

            if (Is_BusinessDay(Day))
                --Days;

            if (Day == 8)
                Day = 1;

        }

        return Date;

    }

    bool Is_Overlap(stDate Date1Periode1, stDate Date2Periode1, stDate Date1Periode2, stDate Date2Periode2)
    {

        short D1P2_D2P1 = Check_Is_Date1_Aft_Eq_Bef_Date2(Date1Periode2, Date2Periode1);
        //short D2P1_D2P2 = Check_Is_Date1_Aft_Eq_Bef_Date2(Date2Periode1, Date2Periode2);

        //short D1P2_D1P1 = Check_Is_Date1_Aft_Eq_Bef_Date2(Date1Periode2, Date1Periode1);
        short D1P1_D2P2 = Check_Is_Date1_Aft_Eq_Bef_Date2(Date1Periode1, Date2Periode2);

        return !((D1P1_D2P2 == 1) || (D1P2_D2P1 == 1));

    }

    bool Is_Overlap(Periode Periode1, Periode Periode2)
    {

        return Is_Overlap(Periode1.Start_Periode, Periode1.End_Periode, Periode2.Start_Periode, Periode2.End_Periode);

    }

    bool Is_Date_In_Period(stDate Date, Periode Period)
    {

        return (Check_Is_Date1_Aft_Eq_Bef_Date2(Date, Period.Start_Periode) != -1 && Check_Is_Date1_Aft_Eq_Bef_Date2(Date, Period.End_Periode) != 1);

    }

    void Swap_Periode(Periode& Periode1, Periode& Periode2)
    {

        Periode Temp = Periode1;
        Periode1 = Periode2;
        Periode2 = Temp;

    }

    int Diffrence_Between_Two_Period(Periode Period1, Periode Period2)
    {

        if (!Is_Overlap(Period1, Period2))
            return 0;

        short Check_Start = Check_Is_Date1_Aft_Eq_Bef_Date2(Period1.Start_Periode, Period2.Start_Periode);
        short Check_End = Check_Is_Date1_Aft_Eq_Bef_Date2(Period1.End_Periode, Period2.End_Periode);

        if (Check_Start != After && Check_End != Before)
        {
            return Periode_Length_In_Days(Period2);
        }
        if (Check_Start != Before && Check_End != After)
        {
            return Periode_Length_In_Days(Period1);
        }
        if (Check_Start != After && Check_End != After)
        {
            return Diffrence_Between_2Dates_By_Days(Period2.Start_Periode, Period1.End_Periode);
        }
        if (Check_Start != Before && Check_End != Before)
        {
            return Diffrence_Between_2Dates_By_Days(Period1.Start_Periode, Period2.End_Periode);
        }

    }

    int Diffrence_Between_Two_Period_Enhanced(Periode Period1, Periode Period2)
    {

        if (!Is_Overlap(Period1, Period2))
            return 0;

        short Check_Start = Check_Is_Date1_Aft_Eq_Bef_Date2(Period1.Start_Periode, Period2.Start_Periode);
        short Check_End = Check_Is_Date1_Aft_Eq_Bef_Date2(Period1.End_Periode, Period2.End_Periode);

        if (Check_Start == Before)
            SwapDate(Period1.Start_Periode, Period2.Start_Periode);

        if (Check_End == After)
            SwapDate(Period1.End_Periode, Period2.End_Periode);

        return Periode_Length_In_Days(Period1);

    }

    bool Is_Validate_Date(short Day, short Month, short Year)
    {

        if (Month < 1 || Month > 12 || Year < 1)
            return 0;

        if (Day > Number_Of_Days_In_Month(Month, Year) || Day < 1)
            return 0;

        return 1;

    }

    bool Is_Validate_Date(stDate Date)
    {

        return Is_Validate_Date(Date.Day, Date.Month, Date.Year);

    }

    string Date_Format(stDate Date, string Format = "dd/mm/yyyy")
    {

        string Result = Format;

        Result = Replace(Result, "dd", to_string(Date.Day));
        Result = Replace(Result, "mm", to_string(Date.Month));
        Result = Replace(Result, "yyyy", to_string(Date.Year));
        Result = Replace(Result, "yy", to_string(Date.Year));

        return Result;

    }

    string Get_String_Date(string Message = "")
    {

        string strDate;

        co Message;
        getline(cin >> ws, strDate);

        return strDate;

    }

    void Date_To_Details(stDate Date)
    {

        printf("Day:%d, Month:%d, Year:%d", Date.Day, Date.Month, Date.Year);

    }

}