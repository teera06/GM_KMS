#include <iostream>
#include <list>
#include <ConsoleEngine/EngineDebug.h>

typedef int DataType;

class MyList
{
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
		friend MyList;

	public:
		iterator()
		{
		}

		iterator(ListNode* _CurNode)
			: CurNode(_CurNode)
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

	//--
	class reverse_iterator
	{

		friend MyList;

	public:
		reverse_iterator()
		{
		}

		reverse_iterator(ListNode* _CurNode)
			: CurNode(_CurNode)
		{
		}

		bool operator!=(const reverse_iterator& _Other)
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
			CurNode = CurNode->Prev;
		}
	private:
		ListNode* CurNode = nullptr;
	};

	//----
	MyList()
	{
		Start->Next = End;
		End->Prev = Start;
	}

	~MyList()
	{
		ListNode* CurNode = Start;
		while (CurNode)
		{
			ListNode* Next = CurNode->Next;
			if (nullptr != CurNode)
			{
				delete CurNode;
				CurNode = Next;
			}
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

	reverse_iterator rbegin()
	{
		return reverse_iterator(End->Prev);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(Start->Next);
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
			ReturnIter = iterator(_Iter.CurNode->Next);

			ListNode* PrevNode = _Iter.CurNode->Prev;
			ListNode* NextNode = _Iter.CurNode->Next;

			PrevNode->Next = NextNode;
			NextNode->Prev = PrevNode;

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
	LeckCheck;

	{
		std::cout << "std ����Ʈ" << std::endl;
		std::list<int> NewList = std::list<int>();
		// 0, 1, 2, 3, 4
		for (int i = 0; i < 5; i++)
		{
			NewList.push_back(i);
			// NewList.push_front();
		}

		std::list<int>::reverse_iterator rStartIter = NewList.rbegin();
		std::list<int>::reverse_iterator rEndIter = NewList.rend();

		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; rStartIter != rEndIter
			; ++rStartIter)
		{
			std::cout << *rStartIter << std::endl;
		}
	}

	{
		std::cout << "�� ����Ʈ" << std::endl;
		MyList NewList = MyList();
		for (int i = 0; i < 5; i++)
		{
			NewList.push_front(i);
			// NewList.push_front();
		}

		MyList::reverse_iterator rStartIter = NewList.rbegin();
		MyList::reverse_iterator rEndIter = NewList.rend();

		for (/*std::list<int>::iterator StartIter = NewList.begin()*/
			; rStartIter != rEndIter
			; ++rStartIter)
		{
			std::cout << *rStartIter << std::endl;
		}
	}
}
