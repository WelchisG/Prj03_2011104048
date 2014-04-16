#ifndef DOUBLYLINKED_H
#define DOUBLYLINKED_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class ItemType>
struct NodeType
{
    ItemType info;				// Node's real data
    
	//?? Question : Declare pointers
	// One is point at next node's address, the other one is point at previous node's address
	// ����� ���� ������ Node's next address
	// ����� ���� ������ Node's previous address
	NodeType<ItemType>* pre;
	NodeType<ItemType>* next;
};


template <class ItemType>
class Doubly
{

private:
	NodeType<ItemType>* header;
	NodeType<ItemType>* trailer;
	NodeType<ItemType>* m_pCurrentPos;  // ���� ��ü ���
	int length;		// ��ũ�� ����

public:
	/*====================================================================================
	// Function :  ������, ��� �������� �ʱ�ȭ�Ѵ�.
	// Pre		: None
	// Post		: ��� �������� �ʱ�ȭ
	=====================================================================================*/
	Doubly();  
		
	/*====================================================================================
	// Function : �Լ��� ���ִ��� Ȯ���ϴ� �Լ�
	// Pre : None
	// Post : �� �������� 1 ����, ������ ������ 0 ����
	=====================================================================================*/
	bool IsFull() const;

	/*====================================================================================
	// Function : ��ũ�� ���̸� ��ȯ�ϴ� �Լ�
	// Pre : None
	// Post : ��ũ�� ���� ��ȯ
	=====================================================================================*/
	int  LengthIs() const;
	
	//?? Question : Attach a comment.
	/*====================================================================================
	// Function : ����Ʈ�� ��� ����.
	// Pre		: None
	// Post		: ����Ʈ �� ��� �����Ǿ� �־�� �Ѵ�.
	=====================================================================================*/
	void MakeEmpty();
	
	//?? Question : Attach a comment.
	// The node, in ascending order of 'ID', is inserted.
	// ID�� ���ؼ� �������� ������ ����� ��
	// How? - By operator overloading.
	/*====================================================================================
	// Function : Adds item to list in the order of the key defined in ItemType.
	// Pre		: List is not full. item is not in list. 
	// Post		: item is in list. if success return 1, else return 0;
	=====================================================================================*/
	int InsertItem(ItemType& item); 
	
	//?? Question : Attach a comment.
	/*====================================================================================
	// Function : Ư���� �Է°��� �޾� ��ġ�ϴ� ��尡 ������ �� ��带 �ϳ� �����Ѵ�.
	// Pre		: none
	// Post		: �����ϸ� 1, �����ϸ� 0����
	=====================================================================================*/
	int DeleteItem(ItemType item);

	//?? Question : Attach a comment.
	/*====================================================================================
	// Function : m_pCurrentPos�� ��ġ�� header�� �ű��.
	// Pre		: none
	// Post		: none
	=====================================================================================*/
	void ResetList();

	//?? Question : Attach a comment.
	/*====================================================================================
	// Function : ���� ����� �����͸� �����´�.
	// Pre		: none
	// Post		: �����ϸ� 1, �����ϸ� 0����
	=====================================================================================*/
	int GetCurrentItem(ItemType& item);
		
	/*====================================================================================
	// Fuction : ���ڵ带 �����Ѵ�.
	// Pre : ItemType�� ������
	// Post : ���ڵ带 �����Ѵ�.
	=====================================================================================*/
	int GetData(ItemType& item);
	
	/*====================================================================================
	// Function : element�� �Է��� ������ Update �Ѵ�.
	// Pre:  �Է��� element�� �����Ͽ��� �Ѵ�. 
	// Post: element �� �Է��� �Է��� ������ ���Ѵ�. 
	=====================================================================================*/
	void Update(ItemType& item);
};


//?? Question : Attach a comment.
/*====================================================================================
// Function : ������, ��� �������� �ʱ�ȭ�Ѵ�.
// Pre		: None
// Post		: ��� �������� �ʱ�ȭ
=====================================================================================*/
template <class ItemType>
Doubly<ItemType>::Doubly()  // Class constructor
{
	length = 0;
	m_pCurrentPos = header = trailer = NULL;
}



/*====================================================================================
// Function : �Լ��� ���ִ��� Ȯ���ϴ� �Լ�
// Pre : None
// Post : �� �������� 1 ����, ������ ������ 0 ����
=====================================================================================*/
template<class ItemType>
bool Doubly<ItemType>::IsFull() const
{
	NodeType<ItemType> *location;
	try
	{
		location = new NodeType<ItemType>;  // �޸� �Ҵ� �õ�
		delete location;
		return false;   // ������ �� false ���
	}
	catch(bad_alloc exception)  // ������ �� true ���
	{
		return true;
	}
}


/*====================================================================================
// Function : ��ũ�� ���̸� ��ȯ�ϴ� �Լ�
// Pre : None
// Post : ��ũ�� ���� ��ȯ
=====================================================================================*/
template <class ItemType>
int Doubly<ItemType>::LengthIs() const
{
	return length;  // ���� ��ȯ
}


//?? Question : Attach a comment.
/*====================================================================================
// Function : ����Ʈ�� ��� ����.
// Pre		: None
// Post		: ����Ʈ �� ��� �����Ǿ� �־�� �Ѵ�.
=====================================================================================*/
template <class ItemType>
void Doubly<ItemType>::MakeEmpty()
{
	//?? Question : Delete all nodes
	NodeType<ItemType>* location;
	ResetList();
	for(int i=0; i<length; i++)
	{
		location = m_pCurrentPos;
		m_pCurrentPos = m_pCurrentPos->next;
		delete location;
	}
	m_pCurrentPos = header = trailer = NULL;
	length = 0;
}
/*====================================================================================
// Function : Adds item to list in the order of the key defined in ItemType.
// Pre		: List is not full. item is not in list. 
// Post		: item is in list. if success return 1, else return 0;
=====================================================================================*/
template <class ItemType>
int Doubly<ItemType>::InsertItem(ItemType& item)
{
	m_pCurrentPos = trailer;
	if(m_pCurrentPos == NULL){
		m_pCurrentPos = new NodeType<ItemType>;
		header = m_pCurrentPos;
		length++;
	}
	m_pCurrentPos->next = new NodeType<ItemType>;
	m_pCurrentPos->next->pre = m_pCurrentPos;
	m_pCurrentPos = m_pCurrentPos->next;
	m_pCurrentPos->info = item;
	trailer = m_pCurrentPos;
	trailer->next = NULL;
	length++;
	return 1;
}
/*====================================================================================
// Function : Ư���� �Է°��� �޾� ��ġ�ϴ� ��尡 ������ �� ��带 �ϳ� �����Ѵ�.
// Pre		: ����Ʈ�� ��������� �ȵȴ�.
// Post		: �����ϸ� 1, �����ϸ� 0����
=====================================================================================*/
template <class ItemType>
int Doubly<ItemType>::DeleteItem(ItemType item)
{
	bool moreToSearch = true;
	ResetList();
	while(moreToSearch)
	{
		m_pCurrentPos = m_pCurrentPos->next;
		if(item == m_pCurrentPos->info)
		{
			length--;
			if(length == 0)
			{
				delete m_pCurrentPos;
				return 1;
			}
			if(m_pCurrentPos->next == NULL)
			{
				m_pCurrentPos->next = new NodeType<ItemType>;
				trailer = m_pCurrentPos->next;
				trailer->next = NULL;
			}
			else
				m_pCurrentPos->pre->next = m_pCurrentPos->next;
				m_pCurrentPos->next->pre = m_pCurrentPos->pre;
				delete m_pCurrentPos;
				m_pCurrentPos = NULL;
			
			moreToSearch = false;
			return 1;
		}
	}
	return 0;
}
/*====================================================================================
// Function : m_pCurrentPos�� ��ġ�� header�� �ű��.
// Pre		: none
// Post		: none
=====================================================================================*/
template <class ItemType>
void Doubly<ItemType>::ResetList()
{
	m_pCurrentPos = header;
}
template<class ItemType>
int Doubly<ItemType>::GetCurrentItem(ItemType& item)
{
	if (m_pCurrentPos == NULL)	// ���̸� 0����
		return 0;

	item = m_pCurrentPos->info;		// currentPos�� ������ item�� ����
	m_pCurrentPos = m_pCurrentPos->next;	// ���� ����

	return 1;
}
/*====================================================================================
// Fuction : ���ڵ带 �����Ѵ�.
// Pre : ItemType �� ������
// Post : ���ڵ带 �����Ѵ�.
=====================================================================================*/
template <class ItemType>
int Doubly<ItemType>::GetData(ItemType& item)

{
	ResetList();
	NodeType<ItemType>* temp;

	temp=new NodeType<ItemType>;
	temp->info=item;		// ������ �ӽð�ü�� ����


	for(int i=0 ; i<length ; i++)
	{
		if( (m_pCurrentPos->info) == (temp->info) )		// ���� ������ ��ü�� ������ ���� �� �ݺ������� ��������
			break;
		m_pCurrentPos=m_pCurrentPos->next;
	}
	
	if(length == 0)
		return false;

	item=m_pCurrentPos->info;		// ���� item�� ����

	return 0;
}
/*====================================================================================
// Function : element�� �Է��� ������ Update �Ѵ�.
// Pre:  �Է��� element�� �����Ͽ��� �Ѵ�. 
// Post: element �� �Է��� �Է��� ������ ���Ѵ�. 
=====================================================================================*/
template <class ItemType>
void Doubly<ItemType>::Update(ItemType& item)
{
	ResetList();

	for(int i=0;i<length;i++)
	{
		m_pCurrentPos=m_pCurrentPos->next;
		if( (m_pCurrentPos->info) == item )		// ���� ������ ��ü�� ������ ���� �� �ݺ������� ��������
			break;
	}
	m_pCurrentPos->info=item;		// ��ü�� �Է��� ������ Update�Ѵ�.
}
#endif