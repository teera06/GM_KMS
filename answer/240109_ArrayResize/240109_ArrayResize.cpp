
#include <iostream>
#include <ConsoleEngine/EngineDebug.h>

class IntArray
{
    // private: ����Ʈ �������� ������
public:
    // ����Ʈ ������
    IntArray(int _Size)
    {
        ReSize(_Size);
    }

    // ����Ʈ ���� ������
    IntArray(const IntArray& _Other)
    {
        Copy(_Other);

        //NumValue = _Other.NumValue;
        //ArrPtr = _Other.ArrPtr;
    }
    // ����Ʈ �Ҹ���
    ~IntArray()
    {
        Release();
    }
    // ����Ʈ ���Կ�����
    void operator=(const IntArray& _Other)
    {
        // ���ο� ī�Ƕ�� �θ��ϴ�.
        // �̰� ���� ������ �մϴ�.
        // ���� ���簡 �� ���� ����
        // ��û�� ���� �߻��ϴ� ��찡 �ִµ�.
        // ���� ���� => ���� <= �ƴϴ�.
        // ������ �����ϴ� ���縦 ���� ������ �մϴ�.
        // ArrPtr = _Other.ArrPtr;
        Copy(_Other);
    }

    int& operator[](int _Count)
    {
        return ArrPtr[_Count];
    }

    int Num()
    {
        return NumValue;
    }

    void Copy(const IntArray& _Other)
    {
        NumValue = _Other.NumValue;

        // ���� ���縦 ����� �մϴ�.
        ReSize(NumValue);
        for (int i = 0; i < NumValue; i++)
        {
            ArrPtr[i] = _Other.ArrPtr[i];
        }
    }

    void ReSize(int _Size)
    {
        if (0 >= _Size)
        {
            MsgBoxAssert("�迭�� ũ�Ⱑ 0�ϼ� �����ϴ�");
        }
        int n = NumValue; // ���� ũ�Ⱚ�� �̸� ����
        NumValue = _Size;

        int* ptr = ArrPtr; // Ptr�� ���� Arrptr���� ����

        ArrPtr = new int[_Size]; // �ٽ� �����Ҵ����� Arrptr ����
        // ptr =    [0][1][2][3][4]
        // ArrPtr = [?][?][?][?][?][?][?][?][?][?][?]

         // ptr =    [0][1][2][3][4]
        // ArrPtr = [?][?][?]

        if (n > NumValue) { // ������ ���̰� ���� ������Ʈ�� ���̺��� ū ���
            for (int i = 0; i < NumValue; i++) { // ���� ���� ���̸� �������� ����
                ArrPtr[i] = ptr[i];
            }
        }
        else if (n <= NumValue) { // ���ι������̰� ���� ���̺��� ũ�ų� ������� 
            for (int i = 0; i < n; i++) { // ���� ���̸� �������� ����
                ArrPtr[i] = ptr[i];
            }
        }

        // ptr�� ���̻� �ǹ̰� �����Ƿ� ���� ���ֱ����� ����
        delete[] ptr; 
        ptr = nullptr;
    }

    void Release()
    {
        if (nullptr != ArrPtr)
        {
            delete[] ArrPtr;
            ArrPtr = nullptr;
        }
    }

private:
    int NumValue = 0;
    int* ArrPtr = nullptr;
};


int main()
{
    IntArray NewArray = IntArray(5);
    // [?][?][?][?][?]

    for (int i = 0; i < NewArray.Num(); i++)
    {
        NewArray[i] = i;
    }
    // [0][1][2][3][4]

    //for (size_t i = 0; i < NewArray.Num(); i++)
    //{
    //    std::cout << NewArray[i] << std::endl;
    //}

    // 

    // 1. �Ʒ��� ���� ����� ���������� �����ϰ�
    // 2. ���������� �Ʒ��� ���� ����� �ǵ��� ����ø� �˴ϴ�.
    // 3. ������ �����ϴ� ���� �����ϸ鼭 Ȯ���Ҽ� �ְ� ������.
    // 4. �������� �󸶵��� �׽�Ʈ�� �����Ҽ� �ִ�.
    // 5. �׽�Ʈ ���� �������� �����ϱ⿡ ���信 ����� ������� �����״� ������ �������.

    // 0
    // 1
    // 2
    // 3
    // 4
    // -134212312
    // -134212312
    // -134212312
    // -134212312
    // -134212312



    // �������� ���� �󸶵��� ����� �� �ִ�.
    NewArray.ReSize(3);
    // ?�� �������� �� �־ ������.
    // [0][1][2][3][4][?][?][?][?][?]

    for (size_t i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }

}
