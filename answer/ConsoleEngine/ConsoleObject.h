#pragma once
#include "ConsoleMath.h"

// ���漱�� 
class ConsoleObject
{
	friend class EngineCore; // friend : EngineCore�� private�� ����ϰڴ�.

public:
	ConsoleObject(); // �⺻ ������
	ConsoleObject(const int2& _StartPos, char _RenderChar); // �ʱ�ȭ�� �̿��� ������
	// �Ҹ��� virtual 
	virtual ~ConsoleObject(); // ���� �Ҹ���

	int2 GetPos() const; // this -> const 2�� ��� -> ��ġ, �� ���� �Ұ���
	char GetRenderChar() const; // this -> const 2�� ��� -> ��ġ, �� ���� �Ұ���

	inline void SetRenderChar(char _Ch) // ����, �÷��̾�, �Ѿ� ������ ǥ���� �� set -> �޾Ƽ� ����
	{
		RenderChar = _Ch;
	}

	inline void SetPos(const int2& _Pos) //  const : ������ �� ����X, Set -> ����, �÷��̾�, �Ѿ� ��ġ �� �޾ƿ���
	{
		Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir) // AddPos ������ ��ġ���� up, down, left, right -> ��ĭ �� �̵�
	{
		Pos += _Dir;
	}

	virtual void Update() // �����Լ� -> �ڽ� �Լ� �������̵� ���� �� �θ�Ŭ����
	{

	}

	void Destroy() // ��� ���� Ȯ�κҰ�
	{
		DeathValue = true;
	}

	bool IsPendingKill()
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

	int2 Pos = { 0, 0 };
	char RenderChar = '@';
	class EngineCore* Core = nullptr;

	void SetCore(EngineCore* _Core)
	{
		Core = _Core;
	}
};


