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
	// 노드의 다음 포인터 Node's next address
	// 노드의 이전 포인터 Node's previous address
	NodeType<ItemType>* pre;
	NodeType<ItemType>* next;
};


template <class ItemType>
class Doubly
{

private:
	NodeType<ItemType>* header;
	NodeType<ItemType>* trailer;
	NodeType<ItemType>* m_pCurrentPos;  // 현재 객체 노드
	int length;		// 링크의 길이

public:
	/*====================================================================================
	// Function :  생성자, 멤버 변수들을 초기화한다.
	// Pre		: None
	// Post		: 멤버 변수들이 초기화
	=====================================================================================*/
	Doubly();  
		
	/*====================================================================================
	// Function : 함수가 차있는지 확인하는 함수
	// Pre : None
	// Post : 다 차있으면 1 리턴, 차있지 않으면 0 리턴
	=====================================================================================*/
	bool IsFull() const;

	/*====================================================================================
	// Function : 링크의 길이를 반환하는 함수
	// Pre : None
	// Post : 링크의 길이 반환
	=====================================================================================*/
	int  LengthIs() const;
	
	//?? Question : Attach a comment.
	/*====================================================================================
	// Function : 리스트를 모두 비운다.
	// Pre		: None
	// Post		: 리스트 가 모두 해제되어 있어야 한다.
	=====================================================================================*/
	void MakeEmpty();
	
	//?? Question : Attach a comment.
	// The node, in ascending order of 'ID', is inserted.
	// ID에 의해서 오름차순 정렬을 사용할 것
	// How? - By operator overloading.
	/*====================================================================================
	// Function : Adds item to list in the order of the key defined in ItemType.
	// Pre		: List is not full. item is not in list. 
	// Post		: item is in list. if success return 1, else return 0;
	=====================================================================================*/
	int InsertItem(ItemType& item); 
	
	//?? Question : Attach a comment.
	/*====================================================================================
	// Function : 특정한 입력값을 받아 일치하는 노드가 있으면 그 노드를 하나 제거한다.
	// Pre		: none
	// Post		: 성공하면 1, 실패하면 0리턴
	=====================================================================================*/
	int DeleteItem(ItemType item);

	//?? Question : Attach a comment.
	/*====================================================================================
	// Function : m_pCurrentPos의 위치를 header로 옮긴다.
	// Pre		: none
	// Post		: none
	=====================================================================================*/
	void ResetList();

	//?? Question : Attach a comment.
	/*====================================================================================
	// Function : 현재 노드의 데이터를 가져온다.
	// Pre		: none
	// Post		: 성공하면 1, 실패하면 0리턴
	=====================================================================================*/
	int GetCurrentItem(ItemType& item);
		
	/*====================================================================================
	// Fuction : 레코드를 복사한다.
	// Pre : ItemType의 데이터
	// Post : 레코드를 복사한다.
	=====================================================================================*/
	int GetData(ItemType& item);
	
	/*====================================================================================
	// Function : element를 입력한 것으로 Update 한다.
	// Pre:  입력할 element가 존재하여야 한다. 
	// Post: element 가 입력한 입력한 것으로 변한다. 
	=====================================================================================*/
	void Update(ItemType& item);
};


//?? Question : Attach a comment.
/*====================================================================================
// Function : 생성자, 멤버 변수들을 초기화한다.
// Pre		: None
// Post		: 멤버 변수들이 초기화
=====================================================================================*/
template <class ItemType>
Doubly<ItemType>::Doubly()  // Class constructor
{
	length = 0;
	m_pCurrentPos = header = trailer = NULL;
}



/*====================================================================================
// Function : 함수가 차있는지 확인하는 함수
// Pre : None
// Post : 다 차있으면 1 리턴, 차있지 않으면 0 리턴
=====================================================================================*/
template<class ItemType>
bool Doubly<ItemType>::IsFull() const
{
	NodeType<ItemType> *location;
	try
	{
		location = new NodeType<ItemType>;  // 메모리 할당 시도
		delete location;
		return false;   // 성공할 시 false 출력
	}
	catch(bad_alloc exception)  // 실패할 시 true 출력
	{
		return true;
	}
}


/*====================================================================================
// Function : 링크의 길이를 반환하는 함수
// Pre : None
// Post : 링크의 길이 반환
=====================================================================================*/
template <class ItemType>
int Doubly<ItemType>::LengthIs() const
{
	return length;  // 길이 반환
}


//?? Question : Attach a comment.
/*====================================================================================
// Function : 리스트를 모두 비운다.
// Pre		: None
// Post		: 리스트 가 모두 해제되어 있어야 한다.
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
// Function : 특정한 입력값을 받아 일치하는 노드가 있으면 그 노드를 하나 제거한다.
// Pre		: 리스트가 비어있으면 안된다.
// Post		: 성공하면 1, 실패하면 0리턴
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
// Function : m_pCurrentPos의 위치를 header로 옮긴다.
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
	if (m_pCurrentPos == NULL)	// 끝이면 0리턴
		return 0;

	item = m_pCurrentPos->info;		// currentPos의 정보를 item에 저장
	m_pCurrentPos = m_pCurrentPos->next;	// 다음 노드로

	return 1;
}
/*====================================================================================
// Fuction : 레코드를 복사한다.
// Pre : ItemType 의 데이터
// Post : 레코드를 복사한다.
=====================================================================================*/
template <class ItemType>
int Doubly<ItemType>::GetData(ItemType& item)

{
	ResetList();
	NodeType<ItemType>* temp;

	temp=new NodeType<ItemType>;
	temp->info=item;		// 정보를 임시객체에 저장


	for(int i=0 ; i<length ; i++)
	{
		if( (m_pCurrentPos->info) == (temp->info) )		// 현재 정보와 객체의 정보가 같을 시 반복문에서 빠져나감
			break;
		m_pCurrentPos=m_pCurrentPos->next;
	}
	
	if(length == 0)
		return false;

	item=m_pCurrentPos->info;		// 정보 item에 저장

	return 0;
}
/*====================================================================================
// Function : element를 입력한 것으로 Update 한다.
// Pre:  입력할 element가 존재하여야 한다. 
// Post: element 가 입력한 입력한 것으로 변한다. 
=====================================================================================*/
template <class ItemType>
void Doubly<ItemType>::Update(ItemType& item)
{
	ResetList();

	for(int i=0;i<length;i++)
	{
		m_pCurrentPos=m_pCurrentPos->next;
		if( (m_pCurrentPos->info) == item )		// 현재 정보와 객체의 정보가 같을 시 반복문에서 빠져나감
			break;
	}
	m_pCurrentPos->info=item;		// 객체에 입력한 정보를 Update한다.
}
#endif