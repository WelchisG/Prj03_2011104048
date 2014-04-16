#include "Account.h"
#include "Double.h"

enum RelationType {LESS, GREATER, EQUAL};

class ClientData
{
private:
	string name;	// �� �̸�
	int number[13];	// �� ��ȣ
	string address;	// �ּ�
	string phone;	// ��ȭ��ȣ
	char house;	// ���� ��������
	char credit;	// �ſ뵵
	string Apart;	// ���� û���
	int num;

public:
	ClientData();
	int GetNumberFromKB();		//�� ��ȣ �Է� �Լ�
	int GetNameFromKB();		//�� �̸� �Է� �Լ�
	int GetAddressFromKB();	//�� �ּ� �Է� �Լ�
	int GetPhoneFromKB();			//�� ���뵵 �Է� �Լ�
	int GetHouseFromKB();	// �� ���� ���� ���� �Է� �Լ�
	int GetCreditFromKB();	// �� �ſ뵵 �Է� �Լ�

	string GetNamelist();		//�� �̸� ���� �Լ�
	string GetPhonelist();		//�� �ڵ��� ��ȣ ���� �Լ�
	string GetAddresslist();	//�� �ּ� ���� �Լ�
	int* GetNumberlist()	{return number;};	// �� �ֹε�Ϲ�ȣ ���� �Լ�
	char GetCredit() {return credit;};	// �� �ſ뵵 ���� �Լ�

	void GetClientData();			//�� ���� �Է� �Լ�
	void PutClientData();			//�� ���� ��� �Լ�

	bool SearchAccount(account& data);			// ���� ã��

	/*====================================================================================
	// Function: �ϳ��� ���ڵ带 file�κ��� �о� ���δ�.
	// Pre		: file�� open�ǰ� file pointer�� �о���� ���ڵ��� ��ġ�� 
	// Post		: id�� name�� ��� ����, file pointer�� �ǵڷ� �Ű��� 
	=====================================================================================*/ 
	int GetRecordFromFile(ifstream& fin);

	/*====================================================================================
	// Function : �ϳ��� ���ڵ带 file�� ����
	// Pre		: file�� open�ǰ� file pointer�� ���ڵ尡 �� ��ġ��
	//			  id�� name���� ��µ� �ڷᰡ ����
	// Post		: ���Ͽ� ����ǰ� file pointer�� �� �ڷ� �Ű��� 
	=====================================================================================*/
	int PutRecordToFile(ofstream& fout);

	/*====================================================================================
	// Function	: part�� ������ �� object(�Ǵ� this)�� ����
	// Pre		: part�� �ڷ� ����
	// Post		: this�� �ڷ� ���� 
	=====================================================================================*/
	void Copy(ClientData part);

	RelationType CompareByNumber(ClientData part); //�� ��ȣ �� �Լ�

	/*====================================================================================	
	//�� ��ȣ ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutNumberScreen()	
	{
		cout << setw(10);
		for(int i=0; i<13; i++)
			cout << number[i];
	}

	/*====================================================================================	
	//�� �̸� ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutNameScreen()		{		cout << setw(13)<< name;	}

	/*====================================================================================
	//�� �ּ� ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutAddressScreen()		{		cout << "\t" << address;	}

	/*====================================================================================
	//�� �ڵ��� ��ȣ ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutPhoneScreen()		{		cout << setw(15) << phone ;	}

	/*====================================================================================
	//�� �� ���� ���� ��� �Լ�
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutHouseScreen()		{		cout << setw(10)<< house;	}
	void PutCreditScreen()	{		cout << setw(10)<< credit ;	}	// �ſ뵵 ��� �Լ�
	void PutApartScreen() {cout << setw(10) << Apart << endl;}	// ���� û��� ��� �Լ�

	void OpenAccount(ifstream &file);	//	���� ����
	void CloseAllAccount();	// ��� ���� �ݱ�
	void CloseAccount();	// ���� �ݱ�
	void ApartApplication();	// ���� û��

	// 1) '==' operator overloading
	// 2) '=' operator overloading
	bool operator == (ClientData &part1);
	ClientData operator = (ClientData & part2);

	Doubly<account> Account;
};