#pragma once
#include "bits/stdc++.h"
#include "clsString.h"
#include "clsPerson.h"
#include "Global.h"

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

class clsBankClient : public clsPerson
{

private:

	string _AccountNumber, _PinCode;

	ld _AccountBalance;

	bool _MarkedForDelete = false;

	enum enMode { EmptyMode = 1, UpdateMode, AddNewMode };

	enMode _Mode;

	static clsBankClient _ConvertLineToObject(string Line, string Seperator = "#//#")
	{

		vector <string> vClient = clsString::Split(Line, Seperator, 1, 0);

		//clsString::DecryptText(vClient[5]);

		return clsBankClient(UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4],
			vClient[5], stod(vClient[6]));

	}

	static string _ConverObjectToLine(clsBankClient Object, string Seperator = "#//#")
	{

		string Line;

		Line += Object.FirstName + Seperator;
		Line += Object.LastName + Seperator;
		Line += Object.Email + Seperator;
		Line += Object.Phone + Seperator;
		Line += Object.AccountNumber + Seperator;
		//Line += clsString::EncryptText(Object._PinCode) + Seperator;
		Line += Object.PinCode + Seperator;
		Line += to_string(Object.AccountBalance);

		return Line;

	}

	static vector <clsBankClient> _ExtractBankClientsFromFile()
	{

		fstream File;

		File.open("BankClients.txt", ios::in);

		string Line;

		vector <clsBankClient> vClients;

		if (File.is_open())
		{

			while (getline(File, Line))
				vClients.push_back(_ConvertLineToObject(Line));

			File.close();

		}

		return vClients;

	}

	static void _SaveClientsToFile(vector <clsBankClient>& Clients)
	{

		fstream File;

		File.open("BankClients.txt", ios::out);

		bool Ok = 0;

		if (File.is_open())
		{

			Ok = 1;

			for (auto& C : Clients)
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

		File.open("BankClients.txt", ios::out | ios::app);

		if (File.is_open())
		{

			File o Line o endl;

			File.close();

		}

	}

	void _Update()
	{

		vector <clsBankClient> vClients = _ExtractBankClientsFromFile();

		bool Ok = 0;

		for (auto& C : vClients)
		{

			if (C.AccountNumber == AccountNumber)
			{
				C = *this;
				Ok = 1;
				break;
			}

		}

		_SaveClientsToFile(vClients);

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(EmptyMode, "", "", "", "", "", "", 0);
	}

	void _AddNew(clsBankClient& Client)
	{
		_AddDataLineToFile(_ConverObjectToLine(Client));
	}

	static bool _IsEmpty(clsBankClient Client)
	{
		return (Client._Mode == EmptyMode);
	}

	string _PreaperTransferRecord(ld Amount, clsBankClient& DestinationAccount, string UserName, string Seperator = "#//#")
	{

		string Record;

		Record = clsDate::GetSystemDateTimeString() + Seperator;
		Record += this->AccountNumber + Seperator;
		Record += DestinationAccount.AccountNumber + Seperator;
		Record += to_string(Amount) + Seperator;
		Record += to_string(this->AccountBalance) + Seperator;
		Record += to_string(DestinationAccount.AccountBalance) + Seperator;
		Record += CurrentUser.UserName;

		return Record;

	}

	void _RegisterTransferLog(ld Amount, clsBankClient& DestinationAccount, string UserName, string LogFileName = "TransactionLogs", string Seperator = "#//#")
	{

		string Record = _PreaperTransferRecord(Amount, DestinationAccount, UserName, Seperator);

		clsUtility::WriteLineInFile(Record, LogFileName);

	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber, string AccountNumber, string PinCode, long double Balance)
		: clsPerson(FirstName, LastName, Email, PhoneNumber)
	{

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = Balance;

	}

	bool IsEmpty()
	{
		return _IsEmpty(*this);
	}

	bool IsMarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetAccountNumber(string Account_Number)
	{
		_AccountNumber = Account_Number;
	}

	__declspec(property(get = GetAccountNumber, put = SetAccountNumber)) string AccountNumber;

	string GetPinCode()
	{
		return _PinCode;
	}

	void SetPinCode(string PINCode)
	{
		_PinCode = PINCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	ld GetAccountBalance()
	{
		return _AccountBalance;
	}

	void SetAccountBalance(ld Balance)
	{
		_AccountBalance = Balance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) ld AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{


		fstream File;

		File.open("BankClients.txt", ios::in);

		string Line;

		clsBankClient Client = _GetEmptyClientObject();

		if (File.is_open())
		{

			while (getline(File, Line))
			{
				
				Client = _ConvertLineToObject(Line);

				if (Client.AccountNumber == AccountNumber)
				{
					File.close();
					return Client;
				}

			}

			File.close();

		}


		return _GetEmptyClientObject();


	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{

		clsBankClient Client = Find(AccountNumber);

		if (Client.PinCode == PinCode)
		{
			return Client;
		}
		else
		{
			return _GetEmptyClientObject();
		}

	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client = Find(AccountNumber);

		return (!_IsEmpty(Client));

	}

	static enum enSaveResult { FailedToSave = 0, SavedSucceed = 1, FailedToSaveAlreeadyAccNumExist };

	enSaveResult Save()
	{

		switch (_Mode)
		{

		case clsBankClient::EmptyMode:
			return FailedToSave;
		case clsBankClient::UpdateMode:
		{

			if (IsClientExist(this->AccountNumber))
			{
				_Update();
				return SavedSucceed;
			}
			else
			{
				return FailedToSaveAlreeadyAccNumExist;
			}

		}
		case clsBankClient::AddNewMode:
		{
			
			if (IsClientExist(this->AccountNumber))
			{
				return FailedToSaveAlreeadyAccNumExist;
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

	static clsBankClient AddNewClientObject(string AccountNumber)
	{
		return clsBankClient(AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool DeleteClient()
	{

		if (IsEmpty() == true)
			return false;

		vector <clsBankClient> vClients = _ExtractBankClientsFromFile();

		bool Status = false;

		for (auto& C : vClients)
		{

			if (C.AccountNumber == AccountNumber)
			{
				C._MarkedForDelete = true;
				Status = true;
				break;
			}

		}

		_SaveClientsToFile(vClients);

		*this = _GetEmptyClientObject();

		return Status;

	}

	static vector <clsBankClient> GetClientsList()
	{
		return _ExtractBankClientsFromFile();
	}

	static ld GetTotalBalances()
	{

		vector <clsBankClient> vClients = _ExtractBankClientsFromFile();

		ld Balances = 0;

		for (auto& Client : vClients)
			Balances += Client.AccountBalance;

		return Balances;

	}

	void Deposit(ld Amount)
	{
		AccountBalance += Amount;
		Save();
	}

	bool WithDraw(ld Amount)
	{

		if (Amount > AccountBalance)
			return false;

		AccountBalance -= Amount;

		Save();

		return true;

	}

	enum enTransfer
	{
		eSucceed,
		eFailedNoMoneyEnough,
		eFailedSameAccount,
		eNotExist,
		eFaildNullAmount
	};

	enTransfer Transfer(ld Amount, clsBankClient& DestinationAccount, string UserName, string LogFileName = "TransactionLogs", string Seperator = "#//#")
	{

		if (Amount > AccountBalance)
			return eFailedNoMoneyEnough; // Check If There Are Money Enough In Source Account.
		else if (this->AccountNumber == DestinationAccount.AccountNumber)
			return eFailedSameAccount; // Check If Transfer Proccess Not To Same Account.
		else if (!IsClientExist(this->AccountNumber) || !IsClientExist(DestinationAccount.AccountNumber))
			return eNotExist; // Check If Source Account & Destination Account Are Exist.
		else if (Amount == 0)
			return eFaildNullAmount; // Amount = 0 (NoThing)

		WithDraw(Amount);

		DestinationAccount.Deposit(Amount);

		_RegisterTransferLog(Amount, DestinationAccount, UserName, LogFileName, Seperator); // Register Transfer Log.

		return eSucceed; // Transfer Completed From Source Account To Desitnation Account.

	}

};