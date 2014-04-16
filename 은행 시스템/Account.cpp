#include "account.h"
int account::Anumber = 0;
/*====================================================================================
// Function	: ���� ��ȣ�� �ڵ����� �Է�
// Pre		: none
// Post		: ������ ������ �߻��ϸ� 0, �����̸� 1 ����
=====================================================================================*/
int account::SetNumber()
{
	number = ++Anumber;
	return 1;
}
/*====================================================================================
// Function	: Ű���忡�� ��ȣ�� �Է¹޾Ƽ� accountNumber�� ����
// Pre		: none
// Post		: accountNumber�� ���¹�ȣ ����, �д� �� ������ �߻��ϸ� 0 �����̸� 1�� ����
=====================================================================================*/
void account::GetNumberFromKB()
{
	cout << "\tInput account's Number : "; 
	cin >> number;
}
/*====================================================================================
// Function	: Ű���忡�� �̸��� �Է¹޾Ƽ� accountrate�� ����
// Pre		: none
// Post		: rate�� �̸� ����, �д� �� ������ �߻��ϸ� 0 �����̸� 1�� ����
=====================================================================================*/
int account::GetrateFromKB()
{
	cout << "\tInput account's rate :  ";
	cin >> rate;
	return 1;
}

/*====================================================================================
// Function	: Ű���忡�� �԰��� �Է¹޾Ƽ� accountStandard�� ����
// Pre		: none
// Post		: accountStandard�� �԰� ����, �д� �� ������ �߻��ϸ� 0 �����̸� 1�� ����
=====================================================================================*/
int account::GetStandardFromKB()
{
	cout << "\tInput account's Standard :  ";
	cin >> standard;
	return 1;
}

/*====================================================================================
// Function	: Ű���忡�� ���� ��й�ȣ�� �Է¹޾Ƽ� password�� ����
// Pre		: none
// Post		: accountStandard�� �԰� ����, �д� �� ������ �߻��ϸ� 0 ������ �̸� 1�� ����
=====================================================================================*/
int account::GetPasswordFromKB()
{
	cout << "\tInput account's password :  ";
	cin >> password;
	return 1;
}

/*====================================================================================
// Function	: ���� �ſ뵵�� �������� ���Ѽ� ����
// Pre		: none
// Post		: ���Ѽ� ������ ����
=====================================================================================*/
int account::SetUpper(char credit)
{
	if(credit == 'A')
		upper = 5000000;
	else if(credit == 'B')
		upper = 3000000;
	else if(credit == 'C')
		upper = 1000000;
	else if(credit == 'D')
		upper = 500000;
	return 1;
}
/*====================================================================================
// Function	: Ű���忡�� ����������  ����
// Pre		: none
// Post		: ���������� ����
=====================================================================================*/
void account::Getaccount(char credit)
{
	SetNumber();		//���� ��ȣ �Է� �Լ�
	GetrateFromKB();		//���� �̸� �Է� �Լ�
	GetStandardFromKB();	//���� �԰� �Է� �Լ�
	GetPasswordFromKB();			//���� ���뵵 �Է� �Լ�
	SetUpper(credit);		// ���� ���Ѽ� ���� �Լ�
	money = 0;
}


/*====================================================================================
// Function	: Ű���忡������������  ���
// Pre		: none
// Post		: ���������� ���
=====================================================================================*/
void account::Putaccount()
{
	cout << setw(15) << "Number" << setw(15) << "Standard" << setw(10) << "rate" << setw(15) << "Upper" << setw(10) << "Money" << endl;
	PutNumberScreen();		//���� ��ȣ ��� �Լ�
	PutStandardScreen();	//���� ���� ��� �Լ�
	PutrateScreen();		//���� ������ ��� �Լ�
	PutUpperScreen();		//���� ���Ѽ� ��� �Լ�
	PutMoneyScreen();		//���� �ܾ� ��� �Լ�
}

/*====================================================================================
// Function : �ϳ��� ���ڵ带 file�κ��� �о� ���δ�.
// Pre		: file�� open�ǰ� file pointer�� �о���� ���ڵ��� ��ġ�� 
// Post		: account ���� ����. file pointer�� �ǵڷ� �Ű���  
=====================================================================================*/
int  account::GetRecordFromFile(ifstream& fin, char credit)
{
		fin>>number;
		if(!fin.good()) return 0;
		fin>>password;
		if(!fin.good()) return 0;
		fin>>standard;
		if(!fin.good()) return 0;
		fin>>rate;
		if(!fin.good()) return 0;
		fin>> money;
		SetUpper(credit);
		return 1;
}

/*====================================================================================
// Function : �������� ���� ���
// Pre		: file�� open
// Post		: ���Ͽ� ����ǰ� file pointer�� �� �ڷ� �Ű��� 
=====================================================================================*/
int account:: PutRecordToFile(ofstream& fout)
{
	fout<<number << " ";	// ���� ��ȣ ���
	fout<<password << " "; 		// ���� ��й�ȣ ���
	fout<<standard << " ";		// ���� ���� ���
	fout<<rate << " ";	// ���� ���� ���� ���
	fout<<money;	// ���� �ܰ� ���
	return 1;
}

/*====================================================================================
// Function	: account�� ������ �� object(�Ǵ� this)�� ����
// Pre		: account�� �ڷ� ����
// Post		: this�� �ڷ� ���� 
=====================================================================================*/
void account::Copy(account account)
{
	number = account.number;			//���� ��ȣ ����
	rate = account.rate;				//���� �̸� ����
	standard = account.standard;		//���� �԰� ����
	rate = account.rate;					//���� ������ ����
	money = account.money;				//���� �ܰ� ����
}


/*====================================================================================
// Function	: account�� accountrate ����
// Pre		: account�� �ڷ� ����
// Post		: this�� �ڷ� ���� 
=====================================================================================*/
double account::Getratelist()
{
	return rate;
}

/*====================================================================================
// Function	: account�� accountrate ����
// Pre		: account�� �ڷ� ����
// Post		: this�� �ڷ� ���� 
=====================================================================================*/
int account::GetNumberlist()
{
	return number;
}

/*====================================================================================
// Function	: account�� accountStandard ����
// Pre		: account�� �ڷ� ����
// Post		: this�� �ڷ� ����
=====================================================================================*/
string account::GetStandardlist()
{
	return standard;
}

/*====================================================================================
// Function	: account�� accountStock ����
// Pre		: account�� �ڷ� ����
// Post		: this�� �ڷ� ����
=====================================================================================*/
int account::GetMoney()
{
	return money;
}
/*====================================================================================
// Function	: �Ա� / ��ȯ
// Pre		: account�� �ڷ� ����
// Post		: this�� �ڷ� ����
=====================================================================================*/
void account::InputMoney()
{
	int temp;
	cout << "\t �Ա��Ͻ� �ݾ��� �Է����ּ��� : ";
	cin >> temp;
	money += temp;
	
	if(money < 0)
		check = "��ȯ";
	else
		check = "�Ա�";

	ofstream file;
	time(&t);
	localtime_s(&A, &t);
	char num_temp[10];
	itoa(number,num_temp,10);
	strcat(num_temp,".txt");
	file.open(num_temp, ios::app);
	file << A.tm_year << " " << A.tm_mon << " " << A.tm_mday << " " << A.tm_hour << " " << A.tm_min << " " << A.tm_sec << " " << temp << " " << check << " " << money << "\n";
	file.close();
	cout << "\t " << number << "�� ������ �ܰ�� " << money << "�� �Դϴ�. " << endl;
}
/*====================================================================================
// Function	: ���
// Pre		: account�� �ڷ� ����
// Post		: this�� �ڷ� ����
=====================================================================================*/
void account::OutputMoney()
{
	if(!EnterPassword())
		return;
	int temp;
	cout << "\t ����Ͻ� �ݾ��� �Է����ּ��� : ";
	cin >> temp;
	money -= temp;
	if(money < 0)
	{
		cout << "\t �ܾ��� �����մϴ� !!" << endl;
		money += temp;
		return;
	}
	check = "���";

	ofstream file;
	time(&t);
	localtime_s(&A, &t);
	char num_temp[10];
	itoa(number,num_temp,10);
	strcat(num_temp,".txt");
	file.open(num_temp, ios::app);
	file << A.tm_year << " " << A.tm_mon << " " << A.tm_mday << " " << A.tm_hour << " " << A.tm_min << " " << A.tm_sec << " " << temp << " " << check << " " << money << "\n";
	file.close();
	cout << "\t " << number << "�� ������ �ܰ�� " << money << "�� �Դϴ�. " << endl;
}
/*====================================================================================
// Function	: ����
// Pre		: account�� �ڷ� ����
// Post	: ���⿡ �����ϸ� ���� ���, �����ϸ� client code�� ���ư�
=====================================================================================*/
void account::Borrow(){
	if(!EnterPassword())
		return;
	cout << "\t ���� �ܰ� : " << money << endl
		<< "\t ���� ���ѱݾ� : " << upper << endl;
	int temp;			// ������ �ݾ� �ִ� �ӽ� �����
	cout << "\t �����Ͻ� �ݾ��� �Է����ּ��� : ";
	cin >> temp;			// ���� �ݾ� �Է�

	money -= temp;			// 
	if(money < -upper)
	{
		cout << "\t ���� ������ �Ѿ����ϴ�!!" << endl;
		money += temp;
		return ;
	}
	check = "����";

	ofstream file;
	time(&t);
	localtime_s(&A, &t);
	char num_temp[10];
	itoa(number,num_temp,10);
	strcat(num_temp,".txt");
	file.open(num_temp, ios::app);
	file << A.tm_year << " " << A.tm_mon << " " << A.tm_mday << " " << A.tm_hour << " " << A.tm_min << " " << A.tm_sec << " " << temp << " " << check << " " << money << "\n";
	file.close();
	cout << "\t ���� �ܰ� : " << money << endl;
}
/*====================================================================================
// Function	: ��й�ȣ �Է�
// Pre		: account�� �ڷ� ����
// Post		: this�� �ڷ� ����
=====================================================================================*/
bool account::EnterPassword()
{
	int temp;		// ��й�ȣ �ӽ� �����
	cout << "\t ��й�ȣ�� �Է��� �ּ��� : ";
	cin >> temp;		// ����ڷκ��� ��й�ȣ �Է�
	if(temp == password)
		return true;		// ���� �� true ��ȯ
	cout << "\t ��й�ȣ�� �ٸ��ϴ�!!!!" << endl;
	return false;		// Ʋ���� false ��ȯ
}

bool account::operator==(account &part1)
{	
	if(number == part1.GetNumberlist())
		return true;
	return false;
}