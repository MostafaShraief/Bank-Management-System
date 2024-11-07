#pragma once

#include "bits/stdc++.h"

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class clsStudent
{

private:

    static string _FirstName;
    static string _LastName;
    static string _FullName;

    class clsEducation
    {

    protected:

        static string _University;
        static string _College;
        static string _Major;
        static string _Language;

        class clsGet
        {

        public:

            string University()
            {
                return _University;
            }

            string College()
            {
                return _College;
            }

            string Major()
            {
                return _Major;
            }

            string Language()
            {
                return _Language;
            }

        };

        class clsSet
        {

        public:

            void University(string University)
            {
                _University = University;
            }

            void College(string College)
            {
                _College = College;
            }

            void Major(string Major)
            {
                _Major = Major;
            }

            void Language(string Language)
            {
                _Language = Language;
            }

        };

    public:

        clsGet Get;

        clsSet Set;

        clsEducation(string University, string College, string Major, string Language)
        {

            _University = University;
            _College = College;
            _Major = Major;
            _Language = Language;

        }

        void Print()
        {

            co "\n_____________________________________\n";
            co left o setw(20) o "University" o ": " o _University o endl;
            co left o setw(20) o "College" o ": " o _College o endl;
            co left o setw(20) o "Major" o ": " o _Major o endl;
            co left o setw(20) o "Language" o ": " o _Language o endl;
            co "_____________________________________\n\n";

        }

    };

    class clsGet
    {

    public:

        string FirstName()
        {
            return _FirstName;
        }

        string LastName()
        {
            return _LastName;
        }

        string FullName()
        {
            return _FullName;
        }

    };

    class clsSet
    {

    public:

        void FullName(string FirstName, string LastName)
        {
            _FullName = FirstName + " " + LastName;
        }

        void FirstName(string FirstName)
        {

            FullName(FirstName, _LastName);
            _FirstName = FirstName;

        }

        void LastName(string LastName)
        {

            FullName(_FirstName, LastName);
            _LastName = LastName;

        }



    };

public:

    clsEducation Education = clsEducation("", "", "", "");

    clsGet Get;

    clsSet Set;

    clsStudent(string FirstName, string LastName, string University, string College, string Major, string Language)
    {

        Set.FirstName(FirstName);
        Set.LastName(LastName);
        Education.Set.University(University);
        Education.Set.College(College);
        Education.Set.Major(Major);
        Education.Set.Language(Language);

    }


    void Print()
    {

        co "\n_____________________________________\n";
        co left o setw(20) o "FirstName" o ": " o _FirstName o endl;
        co left o setw(20) o "LastName" o ": " o _LastName o endl;
        co left o setw(20) o "FullName" o ": " o _FullName o endl;
        co left o setw(20) o "University" o ": " o Education.Get.University() o endl;
        co left o setw(20) o "College" o ": " o Education.Get.College() o endl;
        co left o setw(20) o "Major" o ": " o Education.Get.Major() o endl;
        co left o setw(20) o "Language" o ": " o Education.Get.Language() o endl;
        co "_____________________________________\n\n";

    }

};

string clsStudent::clsEducation::_University;
string clsStudent::clsEducation::_College;
string clsStudent::clsEducation::_Major;
string clsStudent::clsEducation::_Language;
string clsStudent::_FirstName;
string clsStudent::_LastName;
string clsStudent::_FullName;