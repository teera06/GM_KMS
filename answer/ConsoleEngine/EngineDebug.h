#pragma once

// windows에서 제공하는 파일
#include <Windows.h> // MessageBoxA -> 경고창 띄어주기
#include <assert.h> // assert -> 프로그램 파괴

// 매크로 -> 코드 치환
#define LeakCheck _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
// 역할 : 릭 체크

#define MsgBoxAssert(TEXT) MessageBoxA(nullptr, TEXT, "치명적 에러", MB_OK); assert(false);
// 역활 : 경고창 메세지 띄우기
