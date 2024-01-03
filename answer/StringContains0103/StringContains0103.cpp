// StringContains.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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
    bool check = true; // _Find ���� �ϳ��� �񱳸� �ϱ� ���� bool (������ true, �ٸ��� false)
    int len = strlen(_Find) - 1; // _FInd ������ ����-1 -> �ε��� ��
    for (int i = 0; i < strlen(_Dest); i++) { // _Dest ���̰� ��ŭ for��

        while (true) { // while ���ѹݺ�

            if (_Dest[i + len] == _Find[len]) { // _Fine ���̸� �������� �ڿ������� ���� �ϳ��� �� 
                --len; // _Find ���̰� ����Ǿ� �ִ� len�� ���̸� �ϳ��� �ٿ����� �ε��� ��
                check = true; // ���ڰ� �����Ƿ� true
            }
            else { // ���ڰ� �ٸ� ���
                check = false; // false �� 
                break; // �ݺ� �� Ż��
            }

            if (len < 0) { // len�� ���̰� 0���� �۾����ٴ� ���� ���� ���ڸ� ã�Ҵٴ� ��
                len = strlen(_Find) - 1; // len�� �ٽ� _FInd ������ ����-1�� �־���
                break; // �ݺ��� Ż��
            }
        }

        if (check == true) { // check�� true�� ������ ��� ī��Ʈ ���� ����
            ++count;
        }
    }

    return count;
}

int main()
{
    {
        // �����ʰ� ������ ����?
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

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.