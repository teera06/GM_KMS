// StringContains.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

enum class StringReturn
{
    Equal,
    NotEqual
};

StringReturn StringEqual(const char* const _Left, const char* const _Right)
{

    if (strcmp(_Left, _Right) == 0)
    {
        return StringReturn::Equal;
    }
    else
    {
        return StringReturn::NotEqual;
    }
}

void StringAdd(char* _Dest, const char* const _Left, const char* const _Right)
{
    for (int i = 0; i < strlen(_Left); i++) {
        _Dest[i] = _Left[i];
    }

    for (int i = 0; i < strlen(_Right); i++) {
        _Dest[strlen(_Left) + i] = _Right[i];
    }
}

// ------------------------------------------------------
int StringContains(const char* const _Dest, const char* const _Find)
{
    int count = 0;
    bool check = true; // _Find 문자 하나씩 비교를 하기 위한 bool (같으면 true, 다르면 false)
    int len = strlen(_Find) - 1; // _FInd 문자의 길이-1 -> 인덱스 비교
    for (int i = 0; i < strlen(_Dest); i++) { // _Dest 길이값 만큼 for문

        while (true) { // while 무한반복

            if (_Dest[i + len] == _Find[len]) { // _Fine 길이를 기준으로 뒤에서부터 문자 하나씩 비교 
                --len; // _Find 길이가 저장되어 있는 len의 길이를 하나씩 줄여가며 인덱스 비교
                check = true; // 문자가 같으므로 true
            }
            else { // 문자가 다른 경우
                check = false; // false 후 
                break; // 반복 문 탈출
            }

            if (len < 0) { // len의 길이가 0보다 작아졌다는 말은 같은 문자를 찾았다는 뜻
                len = strlen(_Find) - 1; // len에 다시 _FInd 문자의 길이-1값 넣어줌
                break; // 반복문 탈출
            }
        }

        if (check == true) { // check가 true로 유지될 경우 카우트 개수 증가
            ++count;
        }
    }

    return count;
}

int main()
{
    {
        // 오른쪽과 왼쪽이 같아?
        StringEqual("AAAAA", "AAAAA");
    }

    {
        char Arr[100] = {};
        StringAdd(Arr, "gfadsgf", "fasdfsda");
        // "cccccddddd"
        int a = 0;
    }

    {
        // int Result = StringContains("ababcccccabab", "ab");

        int Result = StringContains("ababcccccabab", "ab");
        printf_s("%d", Result);

        int a = 0;
    }
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.