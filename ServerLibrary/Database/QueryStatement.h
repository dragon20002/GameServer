#pragma once
#include "stdafx.h"
#include "ADODatabase.h"

typedef enum
{
	QUERY_NOT_RETURN,
	QUERY_WAIT_RETURN,
	QUERY_CALL_BACK
}QUERY_TYPE;

class QueryStatement
{
	ADODB::_CommandPtr		command_;
	QUERY_TYPE				type_;

	wstr_t					query_;
	int						paramCount_;

public:
	QueryStatement();
	~QueryStatement();

	void setQuery(WCHAR *query, QUERY_TYPE type = QUERY_NOT_RETURN);

	const WCHAR *query();
	QUERY_TYPE type();

	template<typename T>
	void addArg(WCHAR * fmt, T value);
	
	void addParam(CHAR *value);
	void addParam(WCHAR *value);
	void addParam(INT32 *value);
	void addParam(UINT32 *value);
	void addParam(INT64 *value);
	void addParam(UINT64 *value);
	void addParam(FLOAT *value);
	void addParam(DOUBLE *value);
};
