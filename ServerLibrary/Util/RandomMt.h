#pragma once
#include "stdafx.h"
#include <sstream>

#define RAND(type, maxVal)		(type) RandomMT::getInstance().rand(maxVal)

class RandomMT : public Singleton<RandomMT>
{
public:
	uint64_t rand(int maxVal)
	{
		// MT19937 난수 엔진 (메르센 트위스터)
		std::stringstream ss;
		ss << std::this_thread::get_id();
		uint32_t id = std::stoi(ss.str());
		std::mt19937 engine((uint32_t)time(nullptr) + id);
		//-- 현재 시간, 스레드 해시로 엔진 초기화

		std::uniform_int_distribution<uint64_t> distribution(0, UINT64_MAX);
		// rand 생성 함수포인터 bind
		auto generator = bind(distribution, engine);

		return (uint64_t)(generator() % maxVal);
	}
};

// TODO : MT19937를 개선한 RandomWell 작성해보기 (참고: http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html)