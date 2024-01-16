#pragma once
#include "Part.h"

class Head : public Part
{

protected:
	void Update() override;

	int2 dir = { 0,0 };
	int2 nextdir = { 0,0 };
};

