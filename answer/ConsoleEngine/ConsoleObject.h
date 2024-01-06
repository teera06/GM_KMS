#pragma once
#include "ConsoleMath.h" // 값형으로 쓰기 위해 선언 -> 만든 파일 헤더

class ConsoleObject
{
public:
	ConsoleObject(); // 생성자1
	ConsoleObject(const int2& _StartPos, char _RenderChar); // 생성자2
	~ConsoleObject();
	// -> 오버로딩 -> 같은 이름처럼 보이지만 안의 인자값이 다르므로 다른 이름으로 취급 
	
	int2 GetPos() const; // 함수 상수화
	char GetRendeerchar() const;  // 함수 상수화


	// 간단한 기능일때 수행 속력 높이기 위해 -> 정학한 뜻 알아보기 - 참고
	inline void SetRender(char _ch) // char _ch 앞에는 this 즉 본인 생략되어 있다. - 참고
	{
		this->RenderChar = _ch; // this 생략되어 있는거 참고
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
	int2 Pos = { 0,0 }; // 초기화
	char RenderChar = '@'; // 초기화
};

