#include "stdafx.h"
#include "DBAgentProcess.h"

DBAgentProcess::DBAgentProcess()
{
	this->registSubPacketFunc();
}

void DBAgentProcess::registSubPacketFunc()
{
	runFuncTable_.insert(make_pair(E_I_DB_REQ_ID_PW, &DBAgentProcess::IPacket_ID_PW));
}

class Query_ID_PW : public Query
{
public:
	oid_t clientId_;

	WCHAR *procedure()
	{
		return L"p_AccountData_Select";
	}

	Query_ID_PW()
	{
		statement_->setQuery(this->procedure(), QUERY_CALL_BACK);
	}

	~Query_ID_PW()
	{
		PK_I_DB_ANS_ID_PW iPacket;
		iPacket.clientId_ = (UInt64)clientId_;
		iPacket.result_ = FALSE;
		if (!record_.isEof()) {
			record_.moveFirst();
		}

		while (!record_.isEof()) {
			array<WCHAR, DB_PARAM_SIZE> buffer;

			if (record_.get("id", buffer.data())) {
				SLog(L"id : %s", buffer.data());
				iPacket.result_ = TRUE;
			}
			else {
				SLog(L"* this query [%s] have error", this->procedure());
				break;
			}
			record_.moveNext();
		}

		Terminal* terminal = TerminalManager::getInstance().terminal(L"LoginServer");
		terminal->sendPacket(&iPacket);
	}
};

void DBAgentProcess::IPacket_ID_PW(Session * session, Packet * rowPacket)
{
	PK_I_DB_REQ_ID_PW *packet = (PK_I_DB_REQ_ID_PW*)rowPacket;

	Query_ID_PW* query = new Query_ID_PW();
	query->clientId_ = packet->clientId_;

	QueryStatement *statement = query->statement();
	statement->addParam((char*)packet->id_.c_str());
	statement->addParam((char*)packet->password_.c_str());

	DBManager::getInstance().pushQuery(query);
}
