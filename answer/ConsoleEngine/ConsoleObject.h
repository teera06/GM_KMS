#pragma once
#include "ConsoleMath.h"

// 전방선언 
class ConsoleObject
{
	friend class EngineCore; // friend : EngineCore의 private를 사용하겠다.

public:
	ConsoleObject(); // 기본 생성자
	ConsoleObject(const int2& _StartPos, char _RenderChar); // 초기화를 이용한 생성자
	// 소멸자 virtual 
	virtual ~ConsoleObject(); // 가상 소멸자

	int2 GetPos() const; // this -> const 2개 사용 -> 위치, 값 변경 불가능
	char GetRenderChar() const; // this -> const 2개 사용 -> 위치, 값 변경 불가능

	inline void SetRenderChar(char _Ch) // 몬스터, 플레이어, 총알 랜더링 표시할 것 set -> 받아서 저장
	{
		RenderChar = _Ch;
	}

	inline void SetPos(const int2& _Pos) //  const : 본연의 값 변경X, Set -> 몬스터, 플레이어, 총알 위치 값 받아오기
	{
		Pos = _Pos;
	}

	inline void AddPos(const int2& _Dir) // AddPos 기존의 위치값에 up, down, left, right -> 한칸 씩 이동
	{
		Pos += _Dir;
	}

	virtual void Update() // 가상함수 -> 자식 함수 오버라이드 참고 즉 부모클래스
	{

	}

	void Destroy() // 기능 아직 확인불가
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

	// 나랑 충돌한 오브젝트
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


