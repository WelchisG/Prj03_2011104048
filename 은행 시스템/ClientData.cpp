#include "ClientData.h"
#include <fstream>
using namespace std;
ClientData::ClientData()
{
	num = 0;
	Apart = "����";
}
/*====================================================================================
// Function	: Ű���忡�� ��ȣ�� �Է¹޾Ƽ� ClientNumber�� ����
// Pre		: none
// Post		: ClientNumber�� ����ȣ ����, �д� �� ������ �߻��ϸ� 0 ������ �̸� 1�� ����
=====================================================================================*/
int ClientData::GetNumberFromKB()
{
	char temp;
	cout << "\tInput Client's Number :  ";
	for(int i=0; i<13; i++)
	{
		cin >> temp;	// �Էµ� �ֹι�ȣ�� �ϳ��� ���� �Է�
		number[i] = temp-'0';	// ĳ�������� ��Ʈ������ �ٲ�
	}
	return 1;
}

/*====================================================================================
// Function	: Ű���忡�� �̸��� �Է¹޾Ƽ� ClientName�� ����
// Pre		: none
// Post		: name�� �̸� ����, �д� �� ������ �߻��ϸ� 0 ������ �̸� 1�� ����
=====================================================================================*/
int ClientData::GetNameFromKB()
{
	cout << "\tInput Client's Name :  ";
	cin >> name;
	return 1;
}

/*====================================================================================
// Function	: Ű���忡�� �ּ��� �Է¹޾Ƽ� Clientaddress�� ����
// Pre		: none
// Post		: Clientaddress�� �ּ� ����, �д� �� ������ �߻��ϸ� 0 ������ �̸� 1�� ����
=====================================================================================*/
int ClientData::GetAddressFromKB()
{
	string temp;
	cout << "\tInput Client's address :  ";
	cin >> address;
	getline(cin, temp);
	address += temp;
	return 1;
}

/*====================================================================================
// Function	: Ű���忡�� �뵵�� �Է¹޾Ƽ� ClientPhone�� ����
// Pre		: none
// Post		: ClientPhone�� �뵵 ����, �д� �� ������ �߻��ϸ� 0 ������ �̸� 1�� ����
=====================================================================================*/
int ClientData::GetPhoneFromKB()
{
	cout << "\tInput Client's Phone :  ";
	cin >> phone;
	return 1;
}

/*====================================================================================
// Function	: Ű���忡�� ��� �Է¹޾Ƽ� ClientHouse�� ����
// Pre		: none
// Post		: ClientHouse�� ��� ����, �д� �� ������ �߻��ϸ� 0 ������ �̸� 1�� ����
=====================================================================================*/
int ClientData::GetHouseFromKB()
{
	cout << "\tInput Client's House(O,X) :  ";
	cin >> house;
	return 1;
}
/*====================================================================================
// Function	: Ű���忡�� ��� �Է¹޾Ƽ� ClientHouse�� ����
// Pre		: none
// Post		: ClientHouse�� ��� ����, �д� �� ������ �߻��ϸ� 0 ������ �̸� 1�� ����
=====================================================================================*/
int ClientData::GetCreditFromKB()
{
	cout << "\tInput Client's House(A~D) :  ";
	cin >> credit;
	return 1;
}
/*====================================================================================
// Function	: Ű���忡����������  ����
// Pre		: none
// Post		: �������� ����
=====================================================================================*/
void ClientData::GetClientData()
{
	GetNumberFromKB();		//�� ��ȣ �Է� �Լ�
	GetNameFromKB();		//�� �̸� �Է� �Լ�
	GetAddressFromKB();	//�� �ּ� �Է� �Լ�
	GetPhoneFromKB();			//�� �޴��� ��ȣ �Է� �Լ�
	GetHouseFromKB();		//�� �� ���� ���� �Է� �Լ�
	GetCreditFromKB();	// �� �ſ뵵 �Է�
}


/*====================================================================================
// Function	: Ű���忡����������  ���
// Pre		: none
// Post		: �������� ���
=====================================================================================*/
void ClientData::PutClientData()
{
	 cout << setw(15) << "Number" << setw(20) << "Name" << setw(15) << "Phone" << setw(10) << "House"<< setw(10) << "Apart" << endl;
	 PutNumberScreen();		//�� ��ȣ ��� �Լ�
	 PutNameScreen();		//�� �̸� ��� �Լ�
	 PutPhoneScreen();		//�� �޴��� ��ȣ ��� �Լ�
	 PutHouseScreen();		//�� �� ���� ���� ��� �Լ�
	 PutApartScreen();	// ���� û��� ���� ���� ��� �Լ�
	 cout << "\tAddress" << endl;	// �ּ� ����� ���� ������ ����
	 PutAddressScreen();	//�� �ּ� ��� �Լ�

	 if(Account.LengthIs() == 0)	// ��ϵ� ���°� ������
	 {
		 cout << endl;	// ���� ��� �� 
		 return;	// ����
	 }
	 account temp;	// �ӽ� ���� �����
	 Account.ResetList();
	 Account.GetCurrentItem(temp);	// ���� ���� �������� �ޱ�
	 cout << endl;
	 for(int i=0; i<Account.LengthIs()-1; i++)	// ���� ������ŭ ����
	 {
		Account.GetCurrentItem(temp);	// ���� ���� ���� ������ �޾�
		temp.Putaccount();	// ȭ�鿡 ���
	 }

	 cout << endl;
}

/*====================================================================================
// Function : �ϳ��� ���ڵ带 file�κ��� �о� ���δ�.
// Pre		: file�� open�ǰ� file pointer�� �о���� ���ڵ��� ��ġ�� 
// Post		: Client ���� ����. file pointer�� �ǵڷ� �Ű���  
=====================================================================================*/
int  ClientData::GetRecordFromFile(ifstream& fin)
{
	for(int i=0; i<13; i++)	// �ֹε�Ϲ�ȣ ������ŭ ����
	{
		fin>>number[i];		// �ֹε�Ϲ�ȣ i��°�� �Է¹޾�
		number[i] -= 'a';	// Ű��ŭ ��
	}
	fin>>name;	// �̸� �ޱ�
	fin>>phone;	// ��ȭ��ȣ �ޱ�
	fin>>house;	// �� �������� �ޱ�
	fin >> credit;	// �ſ뵵 �ޱ�
	fin.ignore(10,'\n');
	getline(fin,address,'\n');	// �ּ� �ޱ�
	int n;	// ���� ���� 
	fin >> n;	// ���� ���� �ޱ�
	for(int i=0; i<n; i++)	// ���� ���� ������ŭ ����
		OpenAccount(fin);		// ���� ����
	return 1;
}

/*====================================================================================
// Function : �ϳ��� ���ڵ带 file�� ����
// Pre		: file�� open�ǰ� file pointer�� ���ڵ尡 �� ��ġ��
//			  id�� name���� ��µ� �ڷᰡ ����
// Post		: ���Ͽ� ����ǰ� file pointer�� �� �ڷ� �Ű��� 
=====================================================================================*/
int ClientData:: PutRecordToFile(ofstream& fout)
{
	for(int i=0; i<13; i++)	// �ֹι�ȣ 13�ڸ���ŭ ����
	{
		number[i] += 'a';	// ��ȣȭ Ű���� ���Ѵ�
		fout<< number[i] << " ";	// ���� ���
	}
	fout<<name << " "; 		// �̸� ���
	fout<<phone << " ";		// ��ȭ��ȣ ���
	fout<<house << " ";	// ���� �������� ���
	fout << credit ;	// �ſ뵵 ���
	fout<< endl << address << endl;	// �ּ� ���
	if(Account.LengthIs()<=0)	// ���°� ������ ����
	{
		fout << 0 << endl;
		return 1;
	}
	fout << Account.LengthIs()-1;	// ���� ���� ���
	
	account temp;	// �ӽ� ���� ����� ����
	Account.ResetList();	// ���� ��ũ�帮��Ʈ ����
	Account.GetCurrentItem(temp);	// temp�� �������� ����
	for(int i=0; i<Account.LengthIs()-1; i++)	// ���� ������ŭ ����
	{
		fout << endl;	// ���°� ������ endl ���
		Account.GetCurrentItem(temp);
		temp.PutRecordToFile(fout);		// �������� ���
	}
	fout << endl;
	return 1;
}

/*====================================================================================
// Function	: Client�� ������ �� object(�Ǵ� this)�� ����
// Pre		: Client�� �ڷ� ����
// Post		: this�� �ڷ� ���� 
=====================================================================================*/
void ClientData::Copy(ClientData Client)
{
	for(int i=0; i<13; i++)
		number[i] = Client.number[i];			//�� ��ȣ ����
	name = Client.name;				//�� �̸� ����
	address = Client.address;		//�� �ּ� ����
	phone = Client.phone;					//�� �޴��� ��ȣ ����
	house = Client.house;				//�� �� ���� ���� ����
	credit = Client.credit;
	Account = Client.Account;

}

/*====================================================================================
// Function	: this�� Client�� �� 
// Pre		: none
// Pose		: this.ClientNumber < Client.ClientNumber, then return LESS
//			  this.ClientNumber > Client.ClientNumber, then return GREATER
//			  else				 return EQUAL
=====================================================================================*/
RelationType ClientData::CompareByNumber(ClientData Client)
{
	if(number > Client.number)
		return LESS;
	else if(number < Client.number)
		return GREATER;
	else
		return EQUAL;
}

/*====================================================================================
// Function	: Client�� ClientName ����
// Pre		: Client�� �ڷ� ����
// Post		: this�� �ڷ� ���� 
=====================================================================================*/
string ClientData::GetNamelist()
{
	return name;
}

/*====================================================================================
// Function	: Client�� ClientName ����
// Pre		: Client�� �ڷ� ����
// Post		: this�� �ڷ� ���� 
=====================================================================================*/
string ClientData::GetPhonelist()
{
	return phone;
}

/*====================================================================================
// Function	: Client�� Clientaddress ����
// Pre		: Client�� �ڷ� ����
// Post		: this�� �ڷ� ����
=====================================================================================*/
string ClientData::GetAddresslist()
{
	return address;
}

// '==' operator overloading
bool ClientData::operator==(ClientData &Client1)
{	
	if(name == Client1.GetNamelist())
		return true;
	return false;
}

// '=' operator overloading
ClientData ClientData::operator =(ClientData &Client2)
{
	Copy(Client2);
	return *this;
}

/*====================================================================================
// Function	: ���� ����
// Pre		: Client�� �ڷ� ����
// Post		: this�� �ڷ� ����
=====================================================================================*/
void ClientData::OpenAccount(ifstream &fin)
{
	account data;
	data.GetRecordFromFile(fin, credit);
	Account.InsertItem(data);
	num++;
}
/*====================================================================================
// Function	: ���� ����
// Pre		: Client�� �ڷ� ����
// Post		: this�� �ڷ� ����
=====================================================================================*/
void ClientData::CloseAccount()
{
	account data;
	if(!SearchAccount(data))
		return;
	Account.DeleteItem(data);
}
/*====================================================================================
// Function	: ���� ã��
// Pre		: Client�� �ڷ� ����
// Post		: ã�� ���¸� data�� �Է�, ã���� true, ��ã���� false ����
=====================================================================================*/
bool ClientData::SearchAccount(account &data)
{
	account dat;	// �˻��ϰ����ϴ� ��ǰ ����
	account temp;	// ����Ʈ ���� Client��
	int index = 0;		// �ε��� �ʱ�ȭ
	bool found= false;	// �˻� ����ġ����

	Account.ResetList();
	dat.GetNumberFromKB();
	for(int i=0;i<Account.LengthIs();i++)
	{
		Account.GetCurrentItem(temp);//����Ʈ ���� ������ ������ ���ʴ�� �ҷ���
		if(temp.GetNumberlist()==dat.GetNumberlist())//����Ʈ��ȣ�� �˻��Ǵ� ��ǰ ��ȣ Ȯ�� 
		{
			data = temp;				//������ ��� ��ǰ ���� ����
			found = true;							// �˻�����ġ Ʈ��
			index = i;
			break;
		}
	}
	if(found == false)								//�˻��� �������� ���
	{
		cout << "\tNot Found"<<endl;
	}
	if(found == true)
	{
		return true;
	}
	return false;
}
/*====================================================================================
// Function	: ���� û��
// Pre		: Client�� �ڷ� ����
// Post		: �� ���¿� ���� ���� û��� �Է�
=====================================================================================*/
void ClientData::ApartApplication()
{
	if(number[0]<5)
	{
		cout << "\t�� 19���� �Ѿ�� ���� û����� ȹ���� �� �ֽ��ϴ�.";
		return;
	}

	int count = 0;
	account atemp;
	string temp;

	if(credit=='A')		// �ſ뵵�� ���� ��� ���� �ޱ��
		count += 4;
	else if(credit == 'B')
		count += 3;
	else if(credit == 'C')
		count += 2;
	else if(credit == 'D')
		count += 1;
	
	if(house == 'X')		// ���� ������ �켱 ���� �ö�
		count += 5;

	SearchAccount(atemp);
	if(atemp.GetMoney() >= 20000000)
		count+= 4;
	else if(atemp.GetMoney() <20000000 && atemp.GetMoney() >=10000000)
		count += 3;
	else if(atemp.GetMoney() <10000000 && atemp.GetMoney() >=5000000)
		count += 2;
	else if(atemp.GetMoney() <5000000 && atemp.GetMoney() >=1000000)
		count += 1;
	else if(atemp.GetMoney() < 0)
		count -= 2;

	if(count <= 13 && count >= 11)
		Apart = "1���";
	else if(count < 11 && count >7)
		Apart =	"2���"; 
	else if(count < 7 && count > 2)
		Apart = "3���";

	PutClientData();
}