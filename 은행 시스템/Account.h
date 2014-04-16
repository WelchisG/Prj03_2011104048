#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <conio.h>
using namespace std;
class account
{
private:
	int number;	// ���� ��ȣ
	int password;	// ��й�ȣ
	string standard;	// ���� ����
	double rate;	// ������
	int upper;	// ���Ѽ�
	int money;	// ���� �ܰ�
	int timeC;

	string check;	// ��/���, ����, ��ȯ üũ

public:
	static int Anumber;
	int SetNumber();		//���� ��ȣ �Է� �Լ�
	int GetPasswordFromKB();		//���� �̸� �Է� �Լ�
	int GetStandardFromKB();	//���� �԰� �Է� �Լ�
	int GetrateFromKB();			//���� ���뵵 �Է� �Լ�
	void GetNumberFromKB();			// ���� ��ȣ �Է� �Լ�
	int SetUpper(char credit);		//���� ���Ѽ� ���� �Լ�

	int GetPasswordlist();		//���� �̸� ���� �Լ�
	int GetNumberlist();		//���� ��ȣ ���� �Լ�
	string GetStandardlist();	//���� �԰� ���� �Լ�
	int GetMoney();			//���� �ܰ� ���� �Լ�
	double Getratelist();		// ������ ���� �Լ�

	void Getaccount(char credit);			//���� ���� �Է� �Լ�
	void Putaccount();			//���� ���� ��� �Լ�
	

	struct tm A;	// �ð� ���ϴ� ����
	time_t t;
	int month;	// �� ����
	int day;	// �� ����

	/*====================================================================================
	// Function: �ϳ��� ���ڵ带 file�κ��� �о� ���δ�.
	// Pre		: file�� open�ǰ� file pointer�� �о���� ���ڵ��� ��ġ�� 
	// Post		: id�� Password�� ��� ����, file pointer�� �ǵڷ� �Ű��� 
	=====================================================================================*/ 
	int GetRecordFromFile(ifstream& fin, char credit);

	/*====================================================================================
	// Function : �ϳ��� ���ڵ带 file�� ����
	// Pre		: file�� open�ǰ� file pointer�� ���ڵ尡 �� ��ġ��
	//			  id�� Password���� ��µ� �ڷᰡ ����
	// Post		: ���Ͽ� ����ǰ� file pointer�� �� �ڷ� �Ű��� 
	=====================================================================================*/
	int PutRecordToFile(ofstream& fout);

	/*====================================================================================
	// Function	: ������ ������ �� object(�Ǵ� this)�� ����
	// Pre		: ���¿� �ڷ� ����
	// Post		: this�� �ڷ� ���� 
	=====================================================================================*/
	void Copy(account part);

	/*====================================================================================	
	//���� ��ȣ ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutNumberScreen()	
	{
		cout << setw(15) << number;
	}
	
	/*====================================================================================
	//���� ���� ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutStandardScreen()	
	{
		cout << setw(15) << standard;
	}

	/*====================================================================================
	//���� ���Ѽ� ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutUpperScreen()		
	{
		cout << setw(15) << upper;
	}
	/*====================================================================================
	//���� ������ ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutrateScreen()
	{
		cout << setw(10) << rate;
	}

	void PutMoneyScreen()	{cout << setw(10) << money << endl;}	// ���� �ܾ� ��� �Լ�

	void InputMoney(); // �Ա��Լ�
	void OutputMoney();	// ����Լ�
	void Borrow();	// �����Լ�

	/*====================================================================================
	//��ȣ �Է� �Լ�
	// Pre : ��ȣ�� ������ �����Ǿ��־�� �Ѵ�.
	// Post: Ű����� �Է¹��� �Լ��� ������ ��ȣ�� ������ true, Ʋ���� false ����
	=====================================================================================*/
	bool EnterPassword();
	
	bool operator == (account &part1);
};