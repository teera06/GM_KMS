#include "ConsoleObject.h"

ConsoleObject::ConsoleObject()
{

}

ConsoleObject::ConsoleObject(const int2& _StartPos, char _RenderChar)
{

}

ConsoleObject::~ConsoleObject()
{

}

//-------------------------------------------------

int2 ConsoleObject::GetPos() const
{
	return Pos;
}

char ConsoleObject::GetRendeerchar() const
{
	return RenderChar;
}

//-------------------------------------------------


