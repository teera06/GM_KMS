#pragma once
#include "ConsoleMath.h"

// ���� : ����, �÷��̾�, �Ѿ� ���� ������Ʈ ����
class ConsoleObject
{
	friend class EngineCore; // friend : EngineCore�� private�� ����ϰڴ�.

public:
	ConsoleObject(); // �⺻ ������ (1)

	ConsoleObject(const int2& _StartPos, char _RenderChar); // �ʱ�ȭ�� �̿��� ������ (2) -> ��ġ���� ������ ����
	// �Ҹ��� virtual 
	virtual ~ConsoleObject(); // ���� �Ҹ��� *(3)

	int2 GetPos() const; // ������Ʈ�� ��ġ �� ��ȯ (4) -> this �� �� ������ ���� ���ϴ°� �����ϱ� ���� ���� const
	char GetRenderChar() const; // ������Ʈ�� ������ �� ��ȯ (5)

	inline void SetRenderChar(char _Ch) // ������Ʈ ������ ���� (6)
	{
		RenderChar = _Ch;
	}

	inline void SetPos(const int2& _Pos) //  ������Ʈ ��ġ�� ���� (7)
	{
		Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir) // ������Ʈ�� �̵� -> ��ġ�� ���� (8)
	{
		Pos += _Dir;
	}

	virtual void Update() // �����Լ� ConsoleObject(�θ�) -> �ڽ� Ŭ������ ���� �������̵�
	{

	}

	void Destroy() // ����
	{
		DeathValue = true;
	}

	bool IsPendingKill() // ����
	{
		return DeathValue;
	}

	class EngineCore* GetCore() 
	{
		return Core;
	}

	template<typename EnumType>
	ConsoleObject* Collision(EnumType _UpdateOrder)
	{
		return Collision(static_cast<int>(_UpdateOrder));
	}

	// ���� �浹�� ������Ʈ
	ConsoleObject* Collision(int _UpdateOrder);
	// std::list<ConsoleObject*> CollisionList(int _UpdateOrder);

protected:

private:
	bool DeathValue = false;

	int2 Pos = { 0, 0 }; // ��ġ��
	char RenderChar = '@'; // ������ ��
	class EngineCore* Core = nullptr;

	void SetCore(EngineCore* _Core)
	{
		Core = _Core;
	}
};


