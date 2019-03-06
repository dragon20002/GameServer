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
	virtual void tick() = 0; //�� �ֱ⸶�� ó���� ��
	virtual void wakeup() {}; //��� �� ó���� ��
	virtual void suspend() {}; //��� ����
	virtual void stop() {}; //�ƿ� ����
	virtual void start() {}; //�ٽ� ����
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