#include "ClientData.h"
#define MAX 101

class ClientWait
{
private:
	string CW[100];					// �� ����ȣ �迭
	int m_front, m_rear;			// ť �ε���
public:
	ClientWait();
	bool IsFull();		// ť�� �� ���ִ°�?
	bool IsEmpty();		// ť�� ����ִ°�?
	void AddCW();	// �� ��� �߰�
	void DeleteCW();	// �� ��� ����
	void ShowCW();
};