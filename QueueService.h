#pragma once
#include "bits/stdc++.h"
#include "clsDate.h"

using namespace std;
// << Mostafa_Shraief >> (:
#define ll int64_t
#define FORn(a,n)  for(int i=0;i<n; ++i) cin >> a[i];
#define co cout <<
#define ci cin >>
#define o <<
#define endl '\n'
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class clsQueueService
{

private:

	struct _stServiceInfo
	{
		string Prefix;
		int ServiceLongInMinutes;
	};

	_stServiceInfo _ServiceInfo;

	struct _stWorkProcceses
	{
		int Total = 0;
		int Waiting = 0;
		int Served = 0;
	};

	_stWorkProcceses _WorkProcceses;

	struct _stClientsQueue
	{
		string TicketRecord;
		string Time = clsDate::GetSystemDateTimeString();
		int ClientQueue;
		int EstimatedTime;
	};

	queue <_stClientsQueue> _ClientsQueue;

	_stClientsQueue _CurrentServe;

	_stClientsQueue PrepearClientQueue()
	{
		
		_stClientsQueue Client;

		Client.TicketRecord = _ServiceInfo.Prefix;
		Client.TicketRecord += to_string(_ClientsQueue.size() + 1);

		Client.ClientQueue = _ClientsQueue.size();

		Client.EstimatedTime = _ClientsQueue.size() * _ServiceInfo.ServiceLongInMinutes;

		return Client;

	}

	void _PrintTicket(_stClientsQueue& Client)
	{

		clsString::Print_UnderScore(30, 1);
		co "\t  " o Client.TicketRecord o endl o endl;
		co "  " o Client.Time o endl;
		co "Are Waiting Clients : " o Client.ClientQueue o endl;
		co "Serve Time In Minutes : " o Client.EstimatedTime o endl;
		clsString::Print_UnderScore(30, 1);

	}

	void _UpdateClientTicket(int QueueIndex, _stClientsQueue& Client)
	{

		Client.ClientQueue = QueueIndex;

		Client.EstimatedTime = _ServiceInfo.ServiceLongInMinutes * QueueIndex;

	}

public:

	clsQueueService(string Prefix, int ServiceLongInMinutes)
	{
		_ServiceInfo.Prefix = Prefix;
		_ServiceInfo.ServiceLongInMinutes = ServiceLongInMinutes;
	}

	void IssueTicket()
	{

		_stClientsQueue ClientQueue = PrepearClientQueue();

		if (_ClientsQueue.empty())
			_CurrentServe = ClientQueue;

		_ClientsQueue.push(ClientQueue);

		++_WorkProcceses.Total;

		++_WorkProcceses.Waiting;

	}

	void ServeNextClient()
	{

		if (!_ClientsQueue.empty())
		{

			_ClientsQueue.pop();

			if (!_ClientsQueue.empty())
			{
				_CurrentServe = _ClientsQueue.front();
				_UpdateClientTicket(0, _CurrentServe);
			}

			--_WorkProcceses.Waiting;

			++_WorkProcceses.Served;

		}

	}

	void PrintInfo()
	{

		clsString::Print_UnderScore(30, 1);
		co "\tQueue Info\n";
		clsString::Print_UnderScore(30, 1);

		co "\tPrefix          : " o _ServiceInfo.Prefix o endl;
		co "\tTotal Clients   : " o _WorkProcceses.Total o endl;
		co "\tServed Clients  : " o _WorkProcceses.Served o endl;
		co "\tWaiting Clients : " o _WorkProcceses.Waiting o endl;

		clsString::Print_UnderScore(30, 1);

	}

	void PrintTicketsRTL()
	{

		queue <_stClientsQueue> _ClientsQueueTemp;

		_ClientsQueueTemp = _ClientsQueue;

		while (!_ClientsQueueTemp.empty())
		{

			co _ClientsQueueTemp.front().TicketRecord ;

			_ClientsQueueTemp.pop();

			if (!_ClientsQueueTemp.empty())
				co " <-- ";

		}

		co endl;

	}

	void PrintTicketsLTR()
	{

		queue <_stClientsQueue> _ClientsQueueTemp;

		_ClientsQueueTemp = _ClientsQueue;

		stack <string> ClientsTickets;

		while (!_ClientsQueueTemp.empty())
		{

			ClientsTickets.push(_ClientsQueueTemp.front().TicketRecord);

			_ClientsQueueTemp.pop();

		}

		while (!ClientsTickets.empty())
		{

			co ClientsTickets.top();

			ClientsTickets.pop();

			if (!ClientsTickets.empty())
				co " --> ";

		}

		co endl;

	}

	void CurrentServe()
	{
		_PrintTicket(_CurrentServe);
	}

	void PrintAllTickets()
	{

		queue <_stClientsQueue> _ClientsQueueTemp;

		_ClientsQueueTemp = _ClientsQueue;

		int ClientsQueueSize = _ClientsQueue.size();

		while (!_ClientsQueueTemp.empty())
		{

			_stClientsQueue Client = _ClientsQueueTemp.front();

			int IndexQueue = ClientsQueueSize - _ClientsQueueTemp.size();

			_UpdateClientTicket(IndexQueue, Client);

			_PrintTicket(Client);

			_ClientsQueueTemp.pop();

		}

	}

};