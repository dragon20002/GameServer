#pragma once
#include "stdafx.h"
#include <sstream>

#define RAND(type, maxVal)		(type) RandomMT::getInstance().rand(maxVal)

class RandomMT : public Singleton<RandomMT>
{
public:
	uint64_t rand(int maxVal)
	{
		// MT19937 ���� ���� (�޸��� Ʈ������)
		std::stringstream ss;
		ss << std::this_thread::get_id();
		uint32_t id = std::stoi(ss.str());
		std::mt19937 engine((uint32_t)time(nullptr) + id);
		//-- ���� �ð�, ������ �ؽ÷� ���� �ʱ�ȭ

		std::uniform_int_distribution<uint64_t> distribution(0, UINT64_MAX);
		// rand ���� �Լ������� bind
		auto generator = bind(distribution, engine);

		return (uint64_t)(generator() % maxVal);
	}
};

// TODO : MT19937�� ������ RandomWell �ۼ��غ��� (����: http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html)