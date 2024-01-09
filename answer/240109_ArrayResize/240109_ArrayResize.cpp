
#include <iostream>
#include <ConsoleEngine/EngineDebug.h>

class IntArray
{
    // private: 디폴트 접근제한 지정자
public:
    // 디폴트 생성자
    IntArray(int _Size)
    {
        ReSize(_Size);
    }

    // 디폴트 복사 생성자
    IntArray(const IntArray& _Other)
    {
        Copy(_Other);

        //NumValue = _Other.NumValue;
        //ArrPtr = _Other.ArrPtr;
    }
    // 디폴트 소멸자
    ~IntArray()
    {
        Release();
    }
    // 디폴트 대입연산자
    void operator=(const IntArray& _Other)
    {
        // 쉘로우 카피라고 부릅니다.
        // 이걸 얕은 복사라고 합니다.
        // 깊은 복사가 더 좋은 복사
        // 멍청한 일이 발생하는 경우가 있는데.
        // 얕은 복사 => 나빠 <= 아니다.
        // 참조만 복사하는 복사를 얕은 복사라고 합니다.
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

        // 깊은 복사를 해줘야 합니다.
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
            MsgBoxAssert("배열의 크기가 0일수 없습니다");
        }
        int n = NumValue; // 그전 크기값을 미리 받음
        NumValue = _Size;

        int* ptr = ArrPtr; // Ptr에 기존 Arrptr값을 복사

        ArrPtr = new int[_Size]; // 다시 동적할당으로 Arrptr 생성
        // ptr =    [0][1][2][3][4]
        // ArrPtr = [?][?][?][?][?][?][?][?][?][?][?]

         // ptr =    [0][1][2][3][4]
        // ArrPtr = [?][?][?]

        if (n > NumValue) { // 그전의 길이가 새로 리사이트한 길이보다 큰 경우
            for (int i = 0; i < NumValue; i++) { // 새로 받은 길이를 기준으로 복사
                ArrPtr[i] = ptr[i];
            }
        }
        else if (n <= NumValue) { // 새로받은길이가 그전 길이보다 크거나 같은경우 
            for (int i = 0; i < n; i++) { // 그전 길이를 기준으로 복사
                ArrPtr[i] = ptr[i];
            }
        }

        // ptr은 더이상 의미가 없으므로 릭을 없애기위한 방지
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

    // 1. 아래와 같은 결과가 나온이유를 이해하고
    // 2. 정상적으로 아래와 같이 출력이 되도록 만드시면 됩니다.
    // 3. 기존에 존재하는 값을 보존하면서 확장할수 있게 만들어라.
    // 4. 선생님이 얼마든지 테스트를 변경할수 있다.
    // 5. 테스트 도중 선생님이 생각하기에 정답에 가까운 조언들을 해줄테니 마음껏 물어보세요.

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



    // 리사이즈 값은 얼마든지 변경될 수 있다.
    NewArray.ReSize(3);
    // ?는 무슨값이 들어가 있어도 괜찮다.
    // [0][1][2][3][4][?][?][?][?][?]

    for (size_t i = 0; i < NewArray.Num(); i++)
    {
        std::cout << NewArray[i] << std::endl;
    }

}
