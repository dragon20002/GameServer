#pragma once
#include "stdafx.h"
#include <Ole2.h>
#include <comdef.h>
#include <comutil.h>
#include <conio.h>

#import "\Program Files\Common Files\system\ado\msado15.dll" rename("EOF", "EndOfFile")

#include "Database.h"

typedef ADODB::_ConnectionPtr		dbConnectionPtr;
typedef ADODB::_CommandPtr			commandPtr;
typedef ADODB::_RecordsetPtr		recordPtr;

class ADODatabase : public Database
{
	dbConnectionPtr			dbConnection_;
	wstr_t					connectionStr_;
	wstr_t					dbName_;

	Thread					*thread_;

public:
	ADODatabase();
	virtual ~ADODatabase();

	HRESULT setConnectTimeout(long second);
	void comError(const WCHAR *actionName, _com_error &e);

	bool connect(const WCHAR *provider, const WCHAR *serverName, const WCHAR *dbName, const WCHAR *id, const WCHAR *password);
	bool connect(const WCHAR *serverName, const WCHAR *dbName, const WCHAR *id, const WCHAR *password);
	bool connect();
	bool connected();
	bool disconnect();

private:
	void execute();
	void process();
	void run();
};