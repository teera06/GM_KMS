#pragma once
// ������ Ŭ������ ���� public���� �ɹ� ������ �δ� ��
class int2
{
public:
	int X = 0;
	int Y = 0;

	// ����Ʈ ���� ������
	// ������ ��� ������ ������� ����� ���ÿ� ����
	void operator=(const int2& _Other) // ������ �ڷ������� ������ �� �ִ�.
	{//=
		X = _Other.X;
		Y = _Other.Y;
	}

	// const int2& _Other -> const : ��� ���ڰ��� ������ �ʴ´�.
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

// extern -> ? ã�ƺ��� -> ���� �׽�Ʈ �غ��� - ����
const int2 Left = { -1,0 };
const int2 Right = { 1,0 };
const int2 Up = { 0,-1 };
const int2 Down = { 0,1 };

