#pragma once
#include "Part.h"
#include "Body.h"
#include <list>
class Head : public Part
{
public:
	void Setscreenxy(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

protected:
	void Update() override;

	int2 dir = { 0,0 }; // 이동을 위한 dir
	int2 nextdir = { 0,0 }; // dir이 left인 경우 right를 저장 
	int2 headsave = { 0,0 }; // 헤드의 이전 위치 저장
	int2 bodysave = { 0,0 }; // 바디의 이전 위치 저장
	int x = 0;
	int y = 0;
	int count = 0;
	std::list<Body*> bodylist; // curbody 값 받기
};

