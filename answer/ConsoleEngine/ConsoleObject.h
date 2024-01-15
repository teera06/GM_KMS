#pragma once
#include "ConsoleMath.h"

// 역할 : 몬스터, 플레이어, 총알 같은 오브젝트 관리
class ConsoleObject
{
	friend class EngineCore; // friend : EngineCore의 private를 사용하겠다.

public:
	ConsoleObject(); // 기본 생성자 (1)

	ConsoleObject(const int2& _StartPos, char _RenderChar); // 초기화를 이용한 생성자 (2) -> 위치값과 랜더링 대입
	// 소멸자 virtual 
	virtual ~ConsoleObject(); // 가상 소멸자 *(3)

	int2 GetPos() const; // 오브젝트의 위치 값 반환 (4) -> this 값 즉 본인의 값이 변하는걸 방지하기 위한 뒤의 const
	char GetRenderChar() const; // 오브젝트의 랜더링 값 반환 (5)

	inline void SetRenderChar(char _Ch) // 오브젝트 랜더링 설정 (6)
	{
		RenderChar = _Ch;
	}

	inline void SetPos(const int2& _Pos) //  오브젝트 위치값 설정 (7)
	{
		Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir) // 오브젝트의 이동 -> 위치값 변함 (8)
	{
		Pos += _Dir;
	}

	virtual void Update() // 가상함수 ConsoleObject(부모) -> 자식 클래스를 위한 오버라이드
	{

	}

	void Destroy() // 미정
	{
		DeathValue = true;
	}

	bool IsPendingKill() // 미정
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

	// 나랑 충돌한 오브젝트
	ConsoleObject* Collision(int _UpdateOrder);
	// std::list<ConsoleObject*> CollisionList(int _UpdateOrder);

protected:

private:
	bool DeathValue = false;

	int2 Pos = { 0, 0 }; // 위치값
	char RenderChar = '@'; // 랜더링 값
	class EngineCore* Core = nullptr;

	void SetCore(EngineCore* _Core)
	{
		Core = _Core;
	}
};


