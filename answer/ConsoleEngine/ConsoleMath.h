#pragma once
// 수학적 클래스는 보통 public으로 맴버 변수를 두는 편
class int2
{
public:
	int X = 0;
	int Y = 0;

	// 디폴트 대입 연산자
	// 간단한 기능 구현은 헤더에서 선언과 동시에 구현
	void operator=(const int2& _Other) // 본인의 자료형으로 가져올 수 있다.
	{//=
		X = _Other.X;
		Y = _Other.Y;
	}

	// const int2& _Other -> const : 상수 인자값이 변하지 않는다.
	int2 operator+(const int2& _Other) //+
	{
		return { X + _Other.X, Y + _Other.Y };
	}

	void operator+=(const int2& _Other) // +=
	{
		X += _Other.X;
		Y += _Other.Y;
	}
};

// extern -> ? 찾아보기 -> 추후 테스트 해보기 - 참고
const int2 Left = { -1,0 };
const int2 Right = { 1,0 };
const int2 Up = { 0,-1 };
const int2 Down = { 0,1 };

