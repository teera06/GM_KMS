#pragma once
#include "ConsoleMath.h" // �������� ���� ���� ���� -> ���� ���� ���

class ConsoleObject
{
public:
	ConsoleObject(); // ������1
	ConsoleObject(const int2& _StartPos, char _RenderChar); // ������2
	~ConsoleObject();
	// -> �����ε� -> ���� �̸�ó�� �������� ���� ���ڰ��� �ٸ��Ƿ� �ٸ� �̸����� ��� 
	
	int2 GetPos() const; // �Լ� ���ȭ
	char GetRendeerchar() const;  // �Լ� ���ȭ


	// ������ ����϶� ���� �ӷ� ���̱� ���� -> ������ �� �˾ƺ��� - ����
	inline void SetRender(char _ch) // char _ch �տ��� this �� ���� �����Ǿ� �ִ�. - ����
	{
		this->RenderChar = _ch; // this �����Ǿ� �ִ°� ����
	}

	inline void SetPos(const int2& _Pos)
	{
		Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir)
	{
		Pos += _Dir;
	}


protected:

private:
	int2 Pos = { 0,0 }; // �ʱ�ȭ
	char RenderChar = '@'; // �ʱ�ȭ
};

