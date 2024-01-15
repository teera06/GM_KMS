#include <iostream>
#include <list>
#include <ConsoleEngine/EngineDebug.h>

typedef int DataType;

// ��������Դϴ�.
class MyList
{
	// Node�� �����͸� 1�� �ޱ� �����Դϴ�.
// ���̳���� ����� ����� �̴ϴ�.
private:
	class ListNode
	{
	public:
		DataType Data = DataType();
		ListNode* Next = nullptr;
		ListNode* Prev = nullptr;
	};


public:
	class iterator
	{
		// class MyList���� ����� ���ÿ� friend�� �ǰǵ�
		// mylist�� ���� �˱� ������.
		friend MyList;

	public:
		iterator()
		{
		}

		iterator(ListNode* _CurNode)
			: CurNode(_CurNode)
		{
		}

		~iterator()
		{
		}

		bool operator!=(const iterator& _Other)
		{
			return CurNode != _Other.CurNode;
		}

		DataType& operator*()
		{
			return CurNode->Data;
		}

		// ������ ������ �߿� 
		void operator++()
		{
			CurNode = CurNode->Next;
		}


	private:
		ListNode* CurNode = nullptr;
	};


	MyList()
	{
		Start->Next = End;
		End->Prev = Start;
	}

	~MyList()
	{
		if (nullptr != Start->Next)
		{
			delete Start;
			Start = nullptr;
		}

		if (nullptr != End->Prev)
		{
			delete End;
			End = nullptr;
		}
	}

	iterator begin()
	{
		return iterator(Start->Next);
	}

	iterator end()
	{
		return iterator(End);
	}

	// End�� Prev�� ���ο� �����͸� �ְڴ�.
	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Data = _Data;

		NewNode->Next = End;
		NewNode->Prev = End->Prev;

		ListNode* PrevNode = NewNode->Prev;
		ListNode* NextNode = NewNode->Next;

		PrevNode->Next = NewNode;
		NextNode->Prev = NewNode;
	}

	// Start�� Next�� ���ο� �����͸� �ְڴ�.
	void push_front(const DataType& _Data)
	{
		// ���Լ�
		ListNode* NewNode = new ListNode();
		NewNode->Data = _Data;

		NewNode->Prev = Start;
		NewNode->Next = Start->Next;

		ListNode* PrevNode = NewNode->Prev;
		ListNode* NextNode = NewNode->Next;

		PrevNode->Next = NewNode;
		NextNode->Prev = NewNode;



	}

	iterator erase(iterator& _Iter)
	{
		if (_Iter.CurNode == Start)
		{
			MsgBoxAssert("Start�� �����Ϸ��� �߽��ϴ�.");
		}

		if (_Iter.CurNode == End)
		{
			MsgBoxAssert("End�� �����Ϸ��� �߽��ϴ�.");
		}

		iterator ReturnIter;

		if (nullptr != _Iter.CurNode)
		{
			// ���� ��带 ����
			ReturnIter = iterator(_Iter.CurNode->Next);

			ListNode* PrevNode = _Iter.CurNode->Prev;
			ListNode* NextNode = _Iter.CurNode->Next;

			PrevNode->Next = NextNode;
			NextNode->Prev = PrevNode;

			// �����ϱ� ����
			// �����Ѵٴ°��� �����͸� ���δ� ����ڴٴ� �ǵ�.
			// ����� ����Ҽ� ����.
			if (nullptr != _Iter.CurNode)
			{
				delete _Iter.CurNode;
				_Iter.CurNode = nullptr;
			}
		}

		return ReturnIter;
	}


protected:

private:

	ListNode* Start = new ListNode();
	ListNode* End = new ListNode();
};

int main()
{
	LeakCheck;

	{
		std::cout << "std ����Ʈ" << std::endl;
		std::list<int> NewList = std::list<int>();
		for (int i = 0; i < 5; i++)
		{
			NewList.push_back(i);
			// NewList.push_front();
		}

		std::list<int>::iterator StartIter = NewList.begin();
		std::list<int>::iterator EndIter = NewList.end();

		// ������ ����� ���� ��带 �����մϴ�.
		StartIter = NewList.erase(StartIter);

		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; StartIter != EndIter
			; ++StartIter)
		{
			std::cout << *StartIter << std::endl;
			// std::cout << StartIter.operator*() << std::endl;
		}
	}

	{
		std::cout << "�� ����Ʈ" << std::endl;
		MyList NewList = MyList();
		for (int i = 0; i < 10; i++)
		{
			NewList.push_front(i);
			// NewList.push_front();
		}

		MyList::iterator StartIter = NewList.begin();
		MyList::iterator EndIter = NewList.end();

		StartIter = NewList.erase(StartIter);

		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; StartIter != EndIter
			; ++StartIter
			)
		{
			std::cout << *StartIter << std::endl;
			// std::cout << StartIter.operator*() << std::endl;
		}
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
