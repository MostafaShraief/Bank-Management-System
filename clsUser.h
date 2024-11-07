#pragma once
#include "bits/stdc++.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsPerson.h"
#include "clsUtility.h"

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define ld long double
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class clsUser : public clsPerson
{

private:

	string _UserName, _Password;

	int _Permissions = 0;

	bool _MarkedForDelete = false;

	enum enMode { EmptyMode = 1, UpdateMode, AddNewMode };

	enMode _Mode;

	static clsUser _ConvertLineToObject(string Line, string Seperator = "#//#")
	{

		vector <string> vUser = clsString::Split(Line, Seperator, 1, 0);

		vUser[5] = clsString::DecryptText(vUser[5]);

		return clsUser(UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4],
			vUser[5], stod(vUser[6]));

	}

	static string _ConverObjectToLine(clsUser Object, string Seperator = "#//#")
	{

		string Line;

		Line += Object.FirstName + Seperator;
		Line += Object.LastName + Seperator;
		Line += Object.Email + Seperator;
		Line += Object.Phone + Seperator;
		Line += Object.UserName + Seperator;
		Line += clsString::EncryptText(Object.Password) + Seperator;
		Line += to_string(Object.Permissions);

		return Line;

	}

	static vector <clsUser> _ExtractUsersFromFile()
	{

		fstream File;

		File.open("Users.txt", ios::in);

		string Line;

		vector <clsUser> vUsers;

		if (File.is_open())
		{

			while (getline(File, Line))
				vUsers.push_back(_ConvertLineToObject(Line));

			File.close();

		}

		return vUsers;

	}

	static void _SaveUsersToFile(vector <clsUser>& Users)
	{

		fstream File;

		File.open("Users.txt", ios::out);

		bool Ok = 0;

		if (File.is_open())
		{

			Ok = 1;

			for (auto& C : Users)
			{
				if (C._MarkedForDelete == false)
					File << _ConverObjectToLine(C) << endl;
			}

			File.close();

		}

	}

	void _AddDataLineToFile(string Line)
	{

		fstream File;

		File.open("Users.txt", ios::out | ios::app);

		if (File.is_open())
		{

			File o Line o endl;

			File.close();

		}

	}

	void _Update()
	{

		vector <clsUser> vUsers = _ExtractUsersFromFile();

		bool Ok = 0;

		for (auto& User : vUsers)
		{

			if (User.UserName == UserName)
			{
				User = *this;
				Ok = 1;
				break;
			}

		}

		_SaveUsersToFile(vUsers);

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(EmptyMode, "", "", "", "", "", "", 0);
	}

	void _AddNew(clsUser& User)
	{
		_AddDataLineToFile(_ConverObjectToLine(User));
	}

	static bool _IsEmpty(clsUser User)
	{
		return (User._Mode == EmptyMode);
	}

	string _PrepearLoginRecord(string LogSeperator = "#//#")
	{

		string Result;

		Result = clsDate::GetSystemDateTimeString() + LogSeperator;

		this->Password = clsString::EncryptText(this->Password);

		Result += this->UserName + LogSeperator;
		Result += this->Password + LogSeperator;
		Result += to_string(this->Permissions);

		return Result;

	}

	struct stLoginRegisterLogs;

	static stLoginRegisterLogs _ConvertLintTostRegisterLog(string Line, string Seperator = "#//#")
	{

		vector <string> vData = clsString::Split(Line, Seperator);

		stLoginRegisterLogs Log;

		Log.DateTime = vData[0];
		Log.UserName = vData[1];
		Log.Password = vData[2];
		Log.Permissions = stoi(vData[3]);

		return Log;

	}

	struct stTransferRegisterLog;

	static stTransferRegisterLog _ConvertLintTostTransferRegisterLog(string Line, string Seperator = "#//#")
	{

		vector <string> vData = clsString::Split(Line, Seperator);

		stTransferRegisterLog Log;

		Log.DateTime = vData[0];
		Log.SourceAccountNumber = vData[1];
		Log.DestinationAccountNumber = vData[2];
		Log.Amount = stoi(vData[3]);
		Log.SourceAccountBalance = stoi(vData[4]);
		Log.DestinationAccountBalance = stoi(vData[5]);
		Log.UserName = vData[6];

		return Log;

	}

public:

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber, string UserName, string Password, int Permission)
		: clsPerson(FirstName, LastName, Email, PhoneNumber)
	{

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permission;

	}

	bool IsEmpty()
	{
		return _IsEmpty(*this);
	}

	bool IsMarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string User_Name)
	{
		_UserName = User_Name;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	string GetPassword()
	{
		return _Password;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermissions()
	{
		return _Permissions;
	}

	enum enPermissions
	{
		eFullAccess = -1, eClientsList = 1,
		eAddClient, eDeleteClient,
		eUpdateClient, eFindClient,
		eTransactions, eManageUsers,
		eRegisterLogs, eCurrencyExchange,
		eLogout
	};

	void SetPermissions(enPermissions Permission)
	{

		if (Permission != eFullAccess && _Permissions != -1)
			_Permissions += (1ll << ll(Permission));
		else
			_Permissions = -1;

	}

	void NullPermissions()
	{
		_Permissions = 0;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{


		fstream File;

		File.open("Users.txt", ios::in);

		string Line;

		clsUser User = _GetEmptyUserObject();

		if (File.is_open())
		{

			while (getline(File, Line))
			{

				User = _ConvertLineToObject(Line);

				if (User.UserName == UserName)
				{
					File.close();
					return User;
				}

			}

			File.close();

		}


		return _GetEmptyUserObject();


	}

	static clsUser Find(string UserName, string Password)
	{

		clsUser User = Find(UserName);

		if (User.Password == Password)
		{
			return User;
		}
		else
		{
			return _GetEmptyUserObject();
		}

	}

	static bool IsUserExist(string UserName)
	{

		clsUser User = Find(UserName);

		return (!_IsEmpty(User));

	}

	static enum enSaveResult { FailedToSave = 0, SavedSucceed = 1, FailedToSaveAlreeadyUserNameExist };

	enSaveResult Save()
	{

		switch (_Mode)
		{

		case clsUser::EmptyMode:
			return FailedToSave;
		case clsUser::UpdateMode:
		{

			if (IsUserExist(this->UserName))
			{
				_Update();
				return SavedSucceed;
			}
			else
			{
				return FailedToSaveAlreeadyUserNameExist;
			}

		}
		case clsUser::AddNewMode:
		{

			if (IsUserExist(this->UserName))
			{
				return FailedToSaveAlreeadyUserNameExist;
			}
			else
			{
				_AddNew(*this);
				_Mode = UpdateMode;
				return SavedSucceed;
			}
		}

		}

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool DeleteUser()
	{

		if (IsEmpty() == true)
			return false;

		vector <clsUser> vUsers = _ExtractUsersFromFile();

		bool Status = false;

		for (auto& User : vUsers)
		{

			if (User.UserName == UserName)
			{
				User._MarkedForDelete = true;
				Status = true;
				break;
			}

		}

		_SaveUsersToFile(vUsers);

		*this = _GetEmptyUserObject();

		return Status;

	}

	static vector <clsUser> GetUsersList()
	{
		return _ExtractUsersFromFile();
	}

	static string ReadUserName()
	{

		string UserName = clsInputValidate::ReadString("\n\t\t\t\t\tInter User Name : ");

		while (!clsUser::IsUserExist(UserName))
		{
			UserName = clsInputValidate::ReadString("\n\t\t\t\t\tOps.. Not Exist,\n\t\t\t\t\tInter Valid User Name : ");
		}

		return UserName;

	}

	bool CheckPermission(enPermissions Permission)
	{

		if (this->Permissions & (1ll << Permission) || Permission == eLogout)
			return 1;

		return 0;

	}

	void LoginLog(string LogsSeperator = "#//#")
	{

		fstream File;

		string stDataFile = _PrepearLoginRecord(LogsSeperator);

		File.open("LoginRegister.txt", ios::out | ios::app);

		if (File.is_open())
		{

			File o stDataFile o endl;

			File.close();

		}

	}

	static vector <string> ExtractLoginLogsFromFile()
	{
		return clsUtility::ExtractDataFromFile("LoginRegister");
	}

	struct stLoginRegisterLogs
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	static vector <stLoginRegisterLogs> GetstRegisterLogs(string Seperator = "#//#")
	{

		fstream File;

		File.open("LoginRegister.txt", ios::in | ios::app);

		vector <stLoginRegisterLogs> vLogs;

		string Line;

		if (File.is_open())
		{

			while (getline(File, Line))
				vLogs.push_back(_ConvertLintTostRegisterLog(Line));

			File.close();

		}

		return vLogs;

	}

	struct stTransferRegisterLog
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		ll Amount;
		ll SourceAccountBalance;
		ll DestinationAccountBalance;
		string UserName;
	};

	static vector <stTransferRegisterLog> GetstTransferRegisterLogs(string Seperator = "#//#")
	{

		fstream File;

		File.open("TransactionLogs.txt", ios::in | ios::app);

		vector <stTransferRegisterLog> vLogs;

		string Line;

		if (File.is_open())
		{

			while (getline(File, Line))
				vLogs.push_back(_ConvertLintTostTransferRegisterLog(Line));

			File.close();

		}

		return vLogs;

	}

};