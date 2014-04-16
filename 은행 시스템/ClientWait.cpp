#include <iostream>
#include "ClientWait.h"
using namespace std;

ClientWait::ClientWait()
{
	m_front = 0;
	m_rear = 0;
	CW[m_front] = "";
}
bool ClientWait::IsFull()
{
	if(m_rear+1 == m_front)
		return true;
	return false;
}
bool ClientWait::IsEmpty()
{
	if(m_front == m_rear)
		return true;
	return false;
}
void ClientWait::AddCW()
{
	if(IsEmpty())
		m_rear = 0;
	if(IsFull())
	{
		cout << "\t ������� ���� 100�� �̻��̾ ���̻� ����Ͻ� �� �����ϴ�." << endl
			<< "\t ��� �Ŀ� ���ֽñ� �ٶ��ϴ�. " << endl;
		return;
	}
	cout << "\t ����Ͻ� ���� �� ��ȣ�� �Է����ּ��� : ";
	cin >> CW[m_rear];
	cout << "\t " << CW[m_rear++] << "��ȣ ������ ��⿭�� ��ϵǼ̽��ϴ�. " << endl;
}
void ClientWait::DeleteCW()
{
	if(IsEmpty())
		return;
	if(m_front == MAX)
		m_front = 0;
	CW[m_front++] = "";
}
void ClientWait::ShowCW()
{
	cout << "\t ���� ����� �� : " << m_rear << "\t ���� ����� ��ȣ : " << CW[m_front] << endl;
}