#pragma once
#include "bits/stdc++.h"
#include "clsString.h"
#pragma warning (disable : 4996) 

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class clsDate;

struct Periode
{

    clsDate* Start_Periode;
    clsDate* End_Periode;

};

class clsDate
{

private:

    struct stTime
    {

        short Year = 0;
        short Days = 0;
        int Hours = 0;
        int Minutes = 0;
        int Seconds = 0;

    };

    short _Year = 0;
    short _Month = 0;
    short _Day = 0;

    enum enMonth { Jan = 1, Feb, March, April, May, Jun, July, Aug, Sep, Oct, Nov, Dec };

    enum enDay { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

    enum enDate_Compare { Before = -1, Equal, After };

public:

    clsDate()
    {
        Set_Local_Time();
    }

    clsDate(string Date)
    {
        String_To_Date(Date);
    }

    clsDate(int Day, int Month, int Year)
    {

        this->_Day = Day;
        this->_Month = Month;
        this->_Year = Year;

    }

    clsDate(int Days, int Year)
    {
        *this = Date_From_Number_Of_Days_From_TheBeginingOfTheYear(Days, Year);
    }

    static bool IsLeap_Year(short Year)
    {
        return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
    }

    bool IsLeap_Year()
    {
        return IsLeap_Year(_Year);
    }

    static stTime Year_To_Time(short Year)
    {

        stTime Time;


        Time.Days = IsLeap_Year(Year) ? 366 : 365;

        Time.Hours = Time.Days * 24;

        Time.Minutes = Time.Hours * 60;

        Time.Seconds = Time.Minutes * 60;


        return Time;

    }

    stTime Year_To_Time()
    {
        return Year_To_Time(_Year);
    }

    static short Number_Of_Days_In_Year(short Year)
    {
        return IsLeap_Year(Year) ? 366 : 365;
    }

    short Number_Of_Days_In_Year()
    {
        return Number_Of_Days_In_Year(_Year);
    }

    static int Number_Of_Hours_In_Year(short Year)
    {
        return Number_Of_Days_In_Year(Year) * 24;
    }

    int Number_Of_Hours_In_Year()
    {
        return Number_Of_Hours_In_Year(_Year);
    }

    static int Number_Of_Minutes_In_Year(short Year)
    {
        return Number_Of_Hours_In_Year(Year) * 60;
    }

    int Number_Of_Minutes_In_Year()
    {
        return Number_Of_Minutes_In_Year(_Year);
    }

    static int Number_Of_Seconds_In_Year(short Year)
    {
        return Number_Of_Minutes_In_Year(Year) * 60;
    }

    int Number_Of_Seconds_In_Year()
    {
        return Number_Of_Seconds_In_Year(_Year);
    }

    static short Number_Of_Days_In_Month(short Month, short Year)
    {

        if (Month < 1 || Month > 12)
            return 0;

        short Number_Of_Days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        return (Month == 2) ? (IsLeap_Year(Year) ? 29 : 28) : Number_Of_Days[Month - 1];

    }

    short Number_Of_Days_In_Month()
    {
        return Number_Of_Days_In_Month(_Month, _Year);
    }

    static short Number_Of_Hours_In_Month(short Month, short Year)
    {
        return Number_Of_Days_In_Month(Month, Year) * 24;
    }

    short Number_Of_Hours_In_Month()
    {
        return Number_Of_Hours_In_Month(_Month, _Year);
    }

    static int Number_Of_Minutes_In_Month(short Month, short Year)
    {
        return Number_Of_Hours_In_Month(Month, Year) * 60;
    }

    int Number_Of_Minutes_In_Month()
    {
        return Number_Of_Minutes_In_Month(_Month, _Year);
    }

    static int Number_Of_Seconds_In_Month(short Month, short Year)
    {
        return Number_Of_Minutes_In_Month(Month, Year) * 60;
    }

    int Number_Of_Seconds_In_Month()
    {
        return Number_Of_Seconds_In_Month(_Month, _Year);
    }

    static string Day_Name(short Day_Of_Week_Order)
    {

        if (Day_Of_Week_Order > 6 || Day_Of_Week_Order < 0)
            return "";

        string Day[8] = { "", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

        return Day[Day_Of_Week_Order];

    }

    string Day_Name()
    {
        return Day_Name(Day_Of_WeekOrder());
    }

    string Day_Short_Name(short Day_Of_Week_Order)
    {

        if (Day_Of_Week_Order > 6 || Day_Of_Week_Order < 0)
            return "";

        string Short_Days[8] = { "", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        return Short_Days[Day_Of_Week_Order];

    }

    static short Day_Of_WeekOrder(short Day, short Month, short Year)
    {

        if (Day < 1 || Day > 31 || Month < 1 || Month > 12)
            return -1;

        short a = (14 - Month) / 12;
        Year -= a;
        Month += 12 * a - 2;

        return (Day + Year + (Year / 4) - (Year / 100) + (Year / 400) + (31 * Month / 12)) % 7 + 1;

    }

    static short Day_Of_WeekOrder(clsDate Date)
    {
        return Day_Of_WeekOrder(Date._Day, Date._Month, Date._Year);
    }

    short Day_Of_WeekOrder()
    {
        return Day_Of_WeekOrder(_Day, _Month, _Year);
    }

    static int Day_To_Day_Of_WeekOrder(string Day)
    {

        string Days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        string Short_Days[8] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

        for (int i = 0; i < 6; ++i)
        {

            if (Days[i] == Day || Short_Days[i] == Day)
                return i + 1;

        }

        return -1;

    }

    static string Date_To_String(short Day, short Month, short Year, bool Global = 1)
    {

        if (!Is_Validate_Date(Day, Month, Year))
            return "";

        if (Global)
            return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
        else
            return to_string(Month) + "/" + to_string(Day) + "/" + to_string(Year);

    }

    static string Date_To_String(clsDate Date, bool Global = 1)
    {
        return Date_To_String(Date._Day, Date._Month, Date._Year, Global);
    }

    string Date_To_String(bool Global = 1)
    {
        return Date_To_String(_Day, _Month, _Year, Global);
    }

    static string Time_To_String()
    {

        std::time_t now = std::time(0);

        std::tm* local_time = std::localtime(&now);

        return to_string(local_time->tm_hour ) + ":" +
            to_string(local_time->tm_min) + ":" +
            to_string(local_time->tm_sec);

    }

    static clsDate String_To_Date(string str, bool RETURN)
    {

        clsDate Date;

        vector <string> v = clsString::Split(str, "/");


        if (v.size() == 3)
        {

            Date._Year = stoi(v.back()); v.pop_back();
            Date._Month = stoi(v.back()); v.pop_back();
            Date._Day = stoi(v.back()); v.pop_back();

        }

        if (Is_Validate_Date(Date))
            return Date;
        else
            return { 0, 0, 0 };

    }

    void String_To_Date(string str)
    {
        *this = String_To_Date(str, 1);
    }

    static string Month_Short_Name(short Month)
    {

        if (Month < 1 || Month > 12)
            return "";

        string Month_Na[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

        return Month_Na[Month - 1];

    }

    string Month_Short_Name()
    {
        return Month_Short_Name(_Month);
    }

    static void Month_Calender(short Month, short Year)
    {

        co " ";  clsString::Print_UnderScore(15); co Month_Short_Name(Month); clsString::Print_UnderScore(16); co endl o endl;


        co " Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";

        short Days = Number_Of_Days_In_Month(Month, Year);

        short Day_WeekkOrder = Day_Of_WeekOrder(1, Month, Year) - 1;

        co " "; clsString::Print_Spaces(Day_WeekkOrder * 5); co "01   ";

        ++Day_WeekkOrder;


        for (int Day = 2; Day <= Days; ++Day)
        {

            if (Day_WeekkOrder % 7 == 0)
                co endl o " ";

            printf("%0*d   ", 2, Day);

            ++Day_WeekkOrder;

        }

        co endl;

        co " "; clsString::Print_UnderScore(34); co endl;

    }

    void Month_Calender()
    {
        Month_Calender(_Month, _Year);
    }

    static void Year_Calender(short Year)
    {

        co "\n ";  clsString::Print_UnderScore(34); co endl;
        co " "; clsString::Print_Spaces(10); co "Calender - " o Year o endl;
        co " ";  clsString::Print_UnderScore(34); co endl o endl;

        for (int Month = 1; Month <= 12; ++Month)
        {

            Month_Calender(Month, Year);
            co endl;

        }

    }

    void Year_Calender()
    {
        Year_Calender(_Year);
    }

    static short Number_Of_Days_From_TheBeginingOfTheYear(short Day, short Month, short Year)
    {

        short Total_Days = 0;

        for (int i = 1; i < Month; ++i)
        {
            Total_Days += Number_Of_Days_In_Month(i, Year);
        }

        Total_Days += Day;

        return Total_Days;

    }

    static short Number_Of_Days_From_TheBeginingOfTheYear(clsDate Date)
    {

        short Day = Date._Day, Month = Date._Month, Year = Date._Year;

        short Total_Days = 0;

        for (int i = 1; i < Month; ++i)
        {
            Total_Days += Number_Of_Days_In_Month(i, Year);
        }

        Total_Days += Day;

        return Total_Days;

    }

    int Number_Of_Days_From_TheBeginingOfTheYear()
    {
        return Number_Of_Days_From_TheBeginingOfTheYear(_Day, _Month, _Year);
    }

    static clsDate Date_From_Number_Of_Days_From_TheBeginingOfTheYear(short Days, short Year)
    {

        clsDate Date;

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

        Date._Day = Days;
        Date._Month = Month;
        Date._Year = Year;

        return Date;

    }

    static clsDate Add_Days_To_Date(short Day, short Month, short Year, int DaysToAdd)
    {

        clsDate Date = { Year, Month, Day };

        short Day_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year);

        DaysToAdd += Number_Of_Days_From_TheBeginingOfTheYear(Date._Day, Date._Month, Date._Year);

        Date._Month = 1;

        while (DaysToAdd > (Day_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year)))
        {

            DaysToAdd -= Day_In_Month;

            ++Date._Month;

            if (Date._Month == 13)
            {

                Date._Month = 1;
                ++Date._Year;

            }

        }

        Date._Day = DaysToAdd;

        return Date;

    }

    static clsDate Add_Days_To_Date(clsDate& Date, int DaysToAdd)
    {

        short Day_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year);

        DaysToAdd += Number_Of_Days_From_TheBeginingOfTheYear(Date._Day, Date._Month, Date._Year);

        Date._Month = 1;

        while (DaysToAdd > (Day_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year)))
        {

            DaysToAdd -= Day_In_Month;

            ++Date._Month;

            if (Date._Month == 13)
            {

                Date._Month = 1;
                ++Date._Year;

            }

        }

        Date._Day = DaysToAdd;

        return Date;

    }

    void Add_Days_To_Date(int DaysToAdd)
    {
        *this = Add_Days_To_Date(_Day, _Month, _Year, DaysToAdd);
    }

    static short Check_Is_Date1_Aft_Eq_Bef_Date2(clsDate Date1, clsDate Date2)
    {

        if (Date1._Year > Date2._Year)
        {
            return 1;
        }

        if (Date1._Year < Date2._Year)
        {
            return -1;
        }

        if (Date1._Month > Date2._Month)
        {
            return 1;
        }

        if (Date1._Month < Date2._Month)
        {
            return -1;
        }

        if (Date1._Day > Date2._Day)
        {
            return 1;
        }

        if (Date1._Day < Date2._Day)
        {
            return -1;
        }

        return 0;

    }

    short Check_Is_Date1_Aft_Eq_Bef_Date2(clsDate Date2)
    {
        return Check_Is_Date1_Aft_Eq_Bef_Date2(*this, Date2);
    }

    static bool Is_Last_Day(clsDate Date)
    {
        return (Date._Day == Number_Of_Days_In_Month(Date._Month, Date._Year));
    }

    bool Is_Last_Day()
    {
        return Is_Last_Day(*this);
    }

    static bool Is_Last_Month(clsDate Date)
    {
        return (Date._Month == 12);
    }

    static bool Is_Last_Month(short Month)
    {
        return (Month == 12);
    }

    bool Is_Last_Month()
    {
        return Is_Last_Month(*this);
    }

    static clsDate NewDay_In_Date(clsDate& Date)
    {

        if (Is_Last_Day(Date))
        {

            if (Is_Last_Month(Date._Month))
            {

                Date._Day = 1;
                Date._Month = 1;
                ++Date._Year;

            }
            else
            {

                Date._Day = 1;
                ++Date._Month;

            }

        }
        else
        {

            ++Date._Day;

        }

        return Date;

    }

    void NewDay_In_Date()
    {
        NewDay_In_Date(*this);
    }

    static void SwapDate(clsDate& Date1, clsDate& Date2)
    {

        clsDate tempdate = Date1;
        Date1 = Date2;
        Date2 = tempdate;

    }

    void SwapDate(clsDate& Date2)
    {
        SwapDate(*this, Date2);
    }

    static int Diffrence_Between_2Dates_By_Days(clsDate Date1, clsDate Date2, bool Include_End_Day = 0)
    {

        short Before = 1;

        // Diffrence From Date1 To Date2

        if (Check_Is_Date1_Aft_Eq_Bef_Date2(Date1, Date2) == 1)
        {

            SwapDate(Date1, Date2);

            Before = -1;

        }

        int Days = 0;

        if (Date1._Year != Date2._Year)
        {
            Days = Number_Of_Days_From_TheBeginingOfTheYear(Date2._Day, Date2._Month, Date2._Year)
                + (Number_Of_Days_In_Year(Date1._Year)
                    - Number_Of_Days_From_TheBeginingOfTheYear(Date1._Day, Date1._Month, Date1._Year));

            ++Date1._Year;

            while (Date1._Year < Date2._Year)
            {

                if (!IsLeap_Year(Date1._Year))
                    ++Date1._Year, Days += 365;
                else
                {
                    ++Date1._Year, Days += 366; break;
                }

            }

            Days += (Date2._Year - Date1._Year) / 4;

            Days += (Date2._Year - Date1._Year) * 365;

        }
        else
        {
            Days = Number_Of_Days_From_TheBeginingOfTheYear(Date2._Day, Date2._Month, Date2._Year)
                - Number_Of_Days_From_TheBeginingOfTheYear(Date1._Day, Date1._Month, Date1._Year);
        }

        return Include_End_Day ? ++Days * Before : Days * Before;

    }

    int Diffrence_Between_2Dates_By_Days(clsDate Date2, bool Include_End_Day = 0)
    {
        return Diffrence_Between_2Dates_By_Days(*this, Date2, Include_End_Day);
    }

    static clsDate Local_Time_To_Date()
    {

        clsDate Date(0, 0, 0);

        std::time_t now = std::time(0);

        std::tm* local_time = std::localtime(&now);

        return { short(local_time->tm_mday), short(local_time->tm_mon + 1), short(local_time->tm_year + 1900) };

    }

    void Set_Local_Time()
    {
        *this = Local_Time_To_Date();
    }

    static int Birthday_To_Age_In_Days(clsDate Birthday, bool Include_End_Day = 0)
    {
        return Diffrence_Between_2Dates_By_Days(Birthday, Local_Time_To_Date(), Include_End_Day);
    }

    int Birthday_To_Age_In_Days(bool Include_End_Day = 0)
    {
        return Birthday_To_Age_In_Days(*this, Include_End_Day);
    }

    void Get_Date()
    {

        clsDate Date(0, 0, 0);

        co endl;
        printf("Inter The Day : "); ci Date._Day;
        co endl;
        printf("Inter The Month : "); ci Date._Month;
        co endl;
        printf("Inter The Year : "); ci Date._Year;

        while (!Is_Validate_Date(Date))
        {

            co endl;
            printf("Ops! Inter Validate Date : \n");
            co endl;
            printf("Inter The Day : "); ci Date._Day;
            co endl;
            printf("Inter The Month : "); ci Date._Month;
            co endl;
            printf("Inter The Year : "); ci Date._Year;

        }

        co endl;

        *this = Date;

    }

    static void Add_OneDay_To_Date(clsDate& Date)
    {
        Add_Days_To_Date(Date, 1);
    }

    void Add_OneDay_To_Date()
    {
        Add_OneDay_To_Date(*this);
    }

    static void Add_XDays_To_Date(clsDate& Date, short DaysToAdd)
    {
        Add_Days_To_Date(Date, DaysToAdd);
    }

    void Add_XDays_To_Date(short DaysToAdd)
    {
        Add_XDays_To_Date(*this, DaysToAdd);
    }

    static void Add_OneWeek_To_Date(clsDate& Date)
    {
        Add_Days_To_Date(Date, 7);
    }

    void Add_OneWeek_To_Date()
    {
        Add_OneWeek_To_Date(*this);
    }

    static void Add_XWeeks_To_Date(clsDate& Date, short WeeksToAdd)
    {
        Add_Days_To_Date(Date, 7 * WeeksToAdd);
    }

    void Add_XWeeks_To_Date(short WeeksToAdd)
    {
        Add_XWeeks_To_Date(*this, WeeksToAdd);
    }

    static void Add_OneMonth_To_Date(clsDate& Date)
    {

        ++Date._Month;

        if (Date._Month == 13)
            Date._Month = 1, ++Date._Year;

        int Days_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year);

        if (Days_In_Month < Date._Day)
            Date._Day = Days_In_Month;


    }

    void Add_OneMonth_To_Date()
    {
        Add_OneMonth_To_Date(*this);
    }

    static void Add_XMonths_To_Date(clsDate& Date, short MonthsToAdd)
    {

        while (MonthsToAdd--)
            Add_OneMonth_To_Date(Date);

    }

    void Add_XMonths_To_Date(short MonthsToAdd)
    {
        Add_XMonths_To_Date(*this, MonthsToAdd);
    }

    static void Add_OneYear_To_Date(clsDate& Date)
    {

        ++Date._Year;

        int Days_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year);

        if (Days_In_Month < Date._Day)
            Date._Day = Days_In_Month;

    }

    void Add_OneYear_To_Date()
    {
        Add_OneYear_To_Date(*this);
    }

    static void Add_XYears_To_Date(clsDate& Date, short YearsToAdd)
    {

        Date._Year += YearsToAdd;

        int Days_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year);

        if (Days_In_Month < Date._Day)
            Date._Day = Days_In_Month;

    }

    void Add_XYears_To_Date(short YearsToAdd)
    {
        Add_XYears_To_Date(*this, YearsToAdd);
    }

    static void Add_OneDecade_To_Date(clsDate& Date)
    {
        Date._Year += 10;
    }

    void Add_OneDecade_To_Date()
    {
        Add_OneDecade_To_Date(*this);
    }

    static void Add_XDecades_To_Date(clsDate& Date, short DecadesToAdd)
    {
        Date._Year += 10 * DecadesToAdd;
    }

    void Add_XDecades_To_Date(short DecadesToAdd)
    {
        Add_XDecades_To_Date(*this, DecadesToAdd);
    }

    static void Add_OneCentury_To_Date(clsDate& Date)
    {
        Date._Year += 100;
    }

    void Add_OneCentury_To_Date()
    {
        Add_OneCentury_To_Date(*this);
    }

    static void Add_XCenturies_To_Date(clsDate& Date, short CenturiesToAdd)
    {
        Date._Year += 100 * CenturiesToAdd;
    }

    void Add_XCenturies_To_Date(short CenturiesToAdd)
    {
        Add_XCenturies_To_Date(*this, CenturiesToAdd);
    }

    static void Add_OneMillennium_To_Date(clsDate& Date)
    {
        Date._Year += 1000;
    }

    void Add_OneMillennium_To_Date()
    {
        Add_OneMillennium_To_Date(*this);
    }

    static void Decrease_OneDay_To_Date(clsDate& Date)
    {
        Add_Days_To_Date(Date, -1);
    }

    void Decrease_OneDay_To_Date()
    {
        Decrease_OneDay_To_Date(*this);
    }

    static void Decrease_XDays_To_Date(clsDate& Date, short DaysToDecrease)
    {
        Add_Days_To_Date(Date, -DaysToDecrease);
    }

    void Decrease_XDays_To_Date(short DaysToDecrease)
    {
        Decrease_XDays_To_Date(*this, DaysToDecrease);
    }

    static void Decrease_OneWeek_To_Date(clsDate& Date)
    {
        Add_Days_To_Date(Date, -7);
    }

    void Decrease_OneWeek_To_Date()
    {
        Decrease_OneWeek_To_Date(*this);
    }

    static void Decrease_XWeeks_To_Date(clsDate& Date, short WeeksToDecrease)
    {
        Add_Days_To_Date(Date, 7 * -WeeksToDecrease);
    }

    void Decrease_XWeeks_To_Date(short WeeksToDecrease)
    {
        Decrease_XWeeks_To_Date(*this, WeeksToDecrease);
    }

    static void Decrease_OneMonth_To_Date(clsDate& Date)
    {

        --Date._Month;

        if (Date._Month == 0)
            Date._Month = 12, --Date._Year;

        int Days_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year);

        if (Days_In_Month < Date._Day)
            Date._Day = Days_In_Month;


    }

    void Decrease_OneMonth_To_Date()
    {
        Decrease_OneMonth_To_Date(*this);
    }

    static void Decrease_XMonths_To_Date(clsDate& Date, short MonthsToDecrease)
    {

        while (MonthsToDecrease--)
            Decrease_OneMonth_To_Date(Date);

    }

    void Decrease_XMonths_To_Date(short MonthsToDecrease)
    {
        Decrease_XMonths_To_Date(*this, MonthsToDecrease);
    }

    static void Decrease_OneYear_To_Date(clsDate& Date)
    {

        --Date._Year;

        int Days_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year);

        if (Days_In_Month < Date._Day)
            Date._Day = Days_In_Month;

    }

    void Decrease_OneYear_To_Date()
    {
        Decrease_OneYear_To_Date(*this);
    }

    static void Decrease_XYears_To_Date(clsDate& Date, short YearsToDecrease)
    {

        Date._Year -= YearsToDecrease;

        int Days_In_Month = Number_Of_Days_In_Month(Date._Month, Date._Year);

        if (Days_In_Month < Date._Day)
            Date._Day = Days_In_Month;

    }

    void Decrease_XYears_To_Date(short YearsToDecrease)
    {
        Decrease_XYears_To_Date(*this, YearsToDecrease);
    }

    static void Decrease_OneDecade_To_Date(clsDate& Date)
    {
        Date._Year -= 10;
    }

    void Decrease_OneDecade_To_Date()
    {
        Decrease_OneDecade_To_Date(*this);
    }

    static void Decrease_XDecades_To_Date(clsDate& Date, short DecadeasToDecrease)
    {
        Date._Year -= 10 * DecadeasToDecrease;
    }

    void Decrease_XDecades_To_Date(short DecadeasToDecrease)
    {
        Decrease_XDecades_To_Date(*this, DecadeasToDecrease);
    }

    static void Decrease_OneCentury_To_Date(clsDate& Date)
    {
        Date._Year -= 100;
    }

    void Decrease_OneCentury_To_Date()
    {
        Decrease_OneCentury_To_Date(*this);
    }

    static void Decrease_XCenturies_To_Date(clsDate& Date, short CenturiesToDecrease)
    {
        Date._Year -= 100 * CenturiesToDecrease;
    }

    void Decrease_XCenturies_To_Date(short CenturiesToDecrease)
    {
        Decrease_XCenturies_To_Date(*this, CenturiesToDecrease);
    }

    static void Decrease_OneMillennium_To_Date(clsDate& Date)
    {
        Date._Year -= 1000;
    }

    void Decrease_OneMillennium_To_Date()
    {
        Decrease_OneMillennium_To_Date(*this);
    }

    static bool Is_End_Of_Week(clsDate Date)
    {
        return Day_Of_WeekOrder(Date) == 7;
    }

    bool Is_End_Of_Week()
    {
        return Is_End_Of_Week(*this);
    }

    static bool Is_Weekend(clsDate Date)
    {
        return Day_Of_WeekOrder(Date) == 6;
    }

    static bool Is_Weekend(short DayInWeekOrder)
    {
        return DayInWeekOrder == 6;
    }

    bool Is_Weekend()
    {
        return Is_Weekend(*this);
    }

    static bool Is_BusinessDay(clsDate Date)
    {
        return !Is_Weekend(Date);
    }

    static bool Is_BusinessDay(short DayInWeekOrder)
    {
        return !Is_Weekend(DayInWeekOrder);
    }

    bool Is_BusinessDay()
    {
        return Is_BusinessDay(*this);
    }

    static short Days_Until_The_End_Of_Week(clsDate Date)
    {
        return Day_To_Day_Of_WeekOrder("Saturday") - Day_Of_WeekOrder(Date);
    }

    short Days_Until_The_End_Of_Week()
    {
        return Days_Until_The_End_Of_Week(*this);
    }

    static short Days_Until_End_Of_Month(clsDate Date)
    {
        return Number_Of_Days_In_Month(Date._Month, Date._Year) - Date._Day + 1;
    }

    short Days_Until_End_Of_Month()
    {
        return Days_Until_End_Of_Month(*this);
    }

    static short Days_Until_End_Of_Year(clsDate Date)
    {
        return Year_To_Time(Date._Year).Days - Number_Of_Days_From_TheBeginingOfTheYear(Date) + 1;
    }

    short Days_Until_End_Of_Year()
    {
        return Days_Until_End_Of_Year(*this);
    }

    static int Periode_Length_In_Days(Periode Period, bool Include_End_Day = 0)
    {
        return Diffrence_Between_2Dates_By_Days(*Period.Start_Periode, *Period.End_Periode, Include_End_Day);
    }

    static int Actual_Days_Vacation(clsDate Date1, clsDate Date2)
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

    static clsDate Holiday_In_Days_To_Date(clsDate& Date, int Days)
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

    clsDate Holiday_In_Days_To_Date(int Days)
    {
        return Holiday_In_Days_To_Date(*this, Days);
    }

    static bool Is_Overlap(clsDate Date1Periode1, clsDate Date2Periode1, clsDate Date1Periode2, clsDate Date2Periode2)
    {

        short D1P2_D2P1 = Check_Is_Date1_Aft_Eq_Bef_Date2(Date1Periode2, Date2Periode1);
        //short D2P1_D2P2 = Check_Is_Date1_Aft_Eq_Bef_Date2(Date2Periode1, Date2Periode2);

        //short D1P2_D1P1 = Check_Is_Date1_Aft_Eq_Bef_Date2(Date1Periode2, Date1Periode1);
        short D1P1_D2P2 = Check_Is_Date1_Aft_Eq_Bef_Date2(Date1Periode1, Date2Periode2);

        return !((D1P1_D2P2 == 1) || (D1P2_D2P1 == 1));

    }

    static bool Is_Overlap(Periode Periode1, Periode Periode2)
    {
        return Is_Overlap(*Periode1.Start_Periode, *Periode1.End_Periode, *Periode2.Start_Periode, *Periode2.End_Periode);
    }

    static bool Is_Date_In_Period(clsDate Date, Periode Period)
    {
        return (Check_Is_Date1_Aft_Eq_Bef_Date2(Date, *Period.Start_Periode) != -1 && Check_Is_Date1_Aft_Eq_Bef_Date2(Date, *Period.End_Periode) != 1);
    }

    bool Is_Date_In_Period(Periode Period)
    {
        return Is_Date_In_Period(*this, Period);
    }

    static void Swap_Periode(Periode& Periode1, Periode& Periode2)
    {

        Periode Temp = Periode1;
        Periode1 = Periode2;
        Periode2 = Temp;

    }

    static int Diffrence_Between_Two_Periods_Overlapped(Periode Period1, Periode Period2)
    {

        if (!Is_Overlap(Period1, Period2))
            return 0;

        short Check_Start = Check_Is_Date1_Aft_Eq_Bef_Date2(*Period1.Start_Periode, *Period2.Start_Periode);
        short Check_End = Check_Is_Date1_Aft_Eq_Bef_Date2(*Period1.End_Periode, *Period2.End_Periode);

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
            return Diffrence_Between_2Dates_By_Days(*Period2.Start_Periode, *Period1.End_Periode);
        }
        if (Check_Start != Before && Check_End != Before)
        {
            return Diffrence_Between_2Dates_By_Days(*Period1.Start_Periode, *Period2.End_Periode);
        }

    }

    static int Diffrence_Between_Two_Periods_Overlapped_Enhanced(Periode Period1, Periode Period2)
    {

        if (!Is_Overlap(Period1, Period2))
            return 0;

        short Check_Start = Check_Is_Date1_Aft_Eq_Bef_Date2(*Period1.Start_Periode, *Period2.Start_Periode);
        short Check_End = Check_Is_Date1_Aft_Eq_Bef_Date2(*Period1.End_Periode, *Period2.End_Periode);

        if (Check_Start == Before)
            SwapDate(*Period1.Start_Periode, *Period2.Start_Periode);

        if (Check_End == After)
            SwapDate(*Period1.End_Periode, *Period2.End_Periode);

        return Periode_Length_In_Days(Period1);

    }

    static bool Is_Validate_Date(short Day, short Month, short Year)
    {

        if (Month < 1 || Month > 12 || Year < 1)
            return 0;

        if (Day > Number_Of_Days_In_Month(Month, Year) || Day < 1)
            return 0;

        return 1;

    }

    static bool Is_Validate_Date(clsDate Date)
    {

        return Is_Validate_Date(Date._Day, Date._Month, Date._Year);

    }

    bool Is_Validate_Date()
    {
        return Is_Validate_Date(*this);
    }

    static string Date_Format(clsDate Date, string Format = "dd/mm/yyyy")
    {

        string Result = Format;

        Result = clsString::Replace(Result, "dd", to_string(Date._Day));
        Result = clsString::Replace(Result, "mm", to_string(Date._Month));
        Result = clsString::Replace(Result, "yyyy", to_string(Date._Year));
        Result = clsString::Replace(Result, "yy", to_string(Date._Year));

        return Result;

    }

    string Date_Format(string Format = "dd/mm/yyyy")
    {
        return Date_Format(*this, Format);
    }

    string Get_String_Date(string Message = "")
    {

        string strDate;

        co Message;
        getline(cin >> ws, strDate);

        return strDate;

    }

    static void Print(clsDate Date)
    {
        printf("\nDay : %d, Month : %d, Year : %d \n", Date._Day, Date._Month, Date._Year);
    }

    void Print()
    {
        Print(*this);
    }

    static string GetSystemDateTimeString(string Seperator = " - ")
    {
        return Local_Time_To_Date().Date_To_String() + Seperator + Time_To_String();
    }

};