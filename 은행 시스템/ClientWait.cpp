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
		cout << "\t 대기중인 고객이 100명 이상이어서 더이상 등록하실 수 없습니다." << endl
			<< "\t 잠시 후에 와주시기 바랍니다. " << endl;
		return;
	}
	cout << "\t 대기하실 고객의 고객 번호를 입력해주세요 : ";
	cin >> CW[m_rear];
	cout << "\t " << CW[m_rear++] << "번호 고객님이 대기열에 등록되셨습니다. " << endl;
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
	cout << "\t 현재 대기자 수 : " << m_rear << "\t 현재 대기자 번호 : " << CW[m_front] << endl;
}