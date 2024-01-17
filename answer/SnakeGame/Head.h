#pragma once
#include "Part.h"
#include "Body.h"
#include <list>
class Head : public Part
{
public:
	std::list<Body*> bodylist;
protected:
	void Update() override;

	int2 dir = { 0,0 };
	int2 nextdir = { 0,0 };
	int2 headsave = { 0,0 };
	int2 bodysave = { 0,0 };

};

