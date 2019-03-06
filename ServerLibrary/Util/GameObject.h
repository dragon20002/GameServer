#pragma once
#include "stdafx.h"

class Object
{
	wstr_t	allocFile_;
	int		allocLine_;
};

class NameObject
{
	wstr_t	name_;
public:
	wstr_t& name()
	{
		return name_;
	}

	void setName(wstr_t name)
	{
		name_ = name;
	}
};

class Work
{
public:
	virtual void tick() = 0; //매 주기마다 처리할 일
	virtual void wakeup() {}; //깨어날 때 처리할 일
	virtual void suspend() {}; //잠시 멈춤
	virtual void stop() {}; //아예 멈춤
	virtual void start() {}; //다시 시작
};

class GameObject : public NameObject, public Work
{
	POINT		position_;
	float		direction_;
public:
	virtual ~GameObject()
	{
		this->free();
	}
	virtual void initialize() {};
	virtual void free() {};
};