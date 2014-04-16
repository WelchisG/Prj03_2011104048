#include "ClientData.h"
#define MAX 101

class ClientWait
{
private:
	string CW[100];					// 고객 대기번호 배열
	int m_front, m_rear;			// 큐 인덱스
public:
	ClientWait();
	bool IsFull();		// 큐가 꽉 차있는가?
	bool IsEmpty();		// 큐가 비어있는가?
	void AddCW();	// 고객 대기 추가
	void DeleteCW();	// 고객 대기 빼기
	void ShowCW();
};