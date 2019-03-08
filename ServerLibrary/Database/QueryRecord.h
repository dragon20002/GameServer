#pragma once
#include "stdafx.h"
#include "ADODatabase.h"

class QueryRecord
{
	recordPtr		record_;
	int				resultVal_;
public:
	QueryRecord();
	~QueryRecord();

	void errorReport(_com_error &e);

	void operator=(QueryRecord &lvalue);
	void operator=(recordPtr &lvalue);

	bool		opened();
	void		close();
	bool		isEof();

	recordPtr	&resultRecord();
	void		setRecord(recordPtr record);
	int			resultVal();
	void		setResultVal(int result);

	HRESULT		moveNext();
	HRESULT		movePrev();
	HRESULT		moveFirst();
	HRESULT		moveLast();

	bool		get(char* fieldName, char* fieldValue);
	bool		get(char* fieldName, wchar_t* fieldValue);
	bool		get(char* fieldName, int& fieldValue);
	bool		get(char* fieldName, float& fieldValue);
	bool		get(char* fieldName, double& fieldValue);
	bool		get(char* fieldName, long& fieldValue);
};