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

	int2 dir = { 0,0 }; // �̵��� ���� dir
	int2 nextdir = { 0,0 }; // dir�� left�� ��� right�� ���� 
	int2 headsave = { 0,0 }; // ����� ���� ��ġ ����
	int2 bodysave = { 0,0 }; // �ٵ��� ���� ��ġ ����
	int x = 0;
	int y = 0;
	std::list<Body*> bodylist; // curbody �� �ޱ�
};

