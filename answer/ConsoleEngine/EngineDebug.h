#pragma once

// windows���� �����ϴ� ����
#include <Windows.h> // MessageBoxA -> ���â ����ֱ�
#include <assert.h> // assert -> ���α׷� �ı�

// ��ũ�� -> �ڵ� ġȯ
#define LeakCheck _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
// ���� : �� üũ

#define MsgBoxAssert(TEXT) MessageBoxA(nullptr, TEXT, "ġ���� ����", MB_OK); assert(false);
// ��Ȱ : ���â �޼��� ����
