#include "account.h"
int account::Anumber = 0;
/*====================================================================================
// Function	: 계좌 번호를 자동으로 입력
// Pre		: none
// Post		: 저장중 에러가 발생하면 0, 정상이면 1 리턴
=====================================================================================*/
int account::SetNumber()
{
	number = ++Anumber;
	return 1;
}
/*====================================================================================
// Function	: 키보드에서 번호를 입력받아서 accountNumber에 저장
// Pre		: none
// Post		: accountNumber에 계좌번호 저장, 읽는 중 에러가 발생하면 0 정상이면 1을 리턴
=====================================================================================*/
void account::GetNumberFromKB()
{
	cout << "\tInput account's Number : "; 
	cin >> number;
}
/*====================================================================================
// Function	: 키보드에서 이름을 입력받아서 accountrate에 저장
// Pre		: none
// Post		: rate에 이름 저장, 읽는 중 에러가 발생하면 0 정상이면 1을 리턴
=====================================================================================*/
int account::GetrateFromKB()
{
	cout << "\tInput account's rate :  ";
	cin >> rate;
	return 1;
}

/*====================================================================================
// Function	: 키보드에서 규격을 입력받아서 accountStandard에 저장
// Pre		: none
// Post		: accountStandard에 규격 저장, 읽는 중 에러가 발생하면 0 정상이면 1을 리턴
=====================================================================================*/
int account::GetStandardFromKB()
{
	cout << "\tInput account's Standard :  ";
	cin >> standard;
	return 1;
}

/*====================================================================================
// Function	: 키보드에서 계좌 비밀번호를 입력받아서 password에 저장
// Pre		: none
// Post		: accountStandard에 규격 저장, 읽는 중 에러가 발생하면 0 정상이 이면 1을 리턴
=====================================================================================*/
int account::GetPasswordFromKB()
{
	cout << "\tInput account's password :  ";
	cin >> password;
	return 1;
}

/*====================================================================================
// Function	: 고객의 신용도를 기준으로 상한선 설정
// Pre		: none
// Post		: 상한선 정보를 저장
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
// Function	: 키보드에서 계좌정보를  저장
// Pre		: none
// Post		: 계좌정보를 저장
=====================================================================================*/
void account::Getaccount(char credit)
{
	SetNumber();		//계좌 번호 입력 함수
	GetrateFromKB();		//계좌 이름 입력 함수
	GetStandardFromKB();	//계좌 규격 입력 함수
	GetPasswordFromKB();			//계좌 사용용도 입력 함수
	SetUpper(credit);		// 계좌 상한선 설정 함수
	money = 0;
}


/*====================================================================================
// Function	: 키보드에서계좌정보를  출력
// Pre		: none
// Post		: 계좌정보를 출력
=====================================================================================*/
void account::Putaccount()
{
	cout << setw(15) << "Number" << setw(15) << "Standard" << setw(10) << "rate" << setw(15) << "Upper" << setw(10) << "Money" << endl;
	PutNumberScreen();		//계좌 번호 출력 함수
	PutStandardScreen();	//계좌 종류 출력 함수
	PutrateScreen();		//계좌 이자율 출력 함수
	PutUpperScreen();		//계좌 상한선 출력 함수
	PutMoneyScreen();		//계좌 잔액 출력 함수
}

/*====================================================================================
// Function : 하나의 레코드를 file로부터 읽어 들인다.
// Pre		: file이 open되고 file pointer는 읽어들일 레코드의 위치에 
// Post		: account 정보 저장. file pointer는 맨뒤로 옮겨짐  
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
// Function : 계좌정보 파일 출력
// Pre		: file이 open
// Post		: 파일에 저장되고 file pointer는 맨 뒤로 옮겨짐 
=====================================================================================*/
int account:: PutRecordToFile(ofstream& fout)
{
	fout<<number << " ";	// 계좌 번호 출력
	fout<<password << " "; 		// 계좌 비밀번호 출력
	fout<<standard << " ";		// 계좌 종류 출력
	fout<<rate << " ";	// 계좌 이자 비율 출력
	fout<<money;	// 계좌 잔고 출력
	return 1;
}

/*====================================================================================
// Function	: account의 내용을 현 object(또는 this)에 복사
// Pre		: account에 자료 저장
// Post		: this에 자료 저장 
=====================================================================================*/
void account::Copy(account account)
{
	number = account.number;			//계좌 번호 복사
	rate = account.rate;				//계좌 이름 복사
	standard = account.standard;		//계좌 규격 복사
	rate = account.rate;					//계좌 이자율 복사
	money = account.money;				//계좌 잔고 복사
}


/*====================================================================================
// Function	: account의 accountrate 접근
// Pre		: account에 자료 접근
// Post		: this에 자료 접근 
=====================================================================================*/
double account::Getratelist()
{
	return rate;
}

/*====================================================================================
// Function	: account의 accountrate 접근
// Pre		: account에 자료 접근
// Post		: this에 자료 접근 
=====================================================================================*/
int account::GetNumberlist()
{
	return number;
}

/*====================================================================================
// Function	: account의 accountStandard 접근
// Pre		: account에 자료 접근
// Post		: this에 자료 접근
=====================================================================================*/
string account::GetStandardlist()
{
	return standard;
}

/*====================================================================================
// Function	: account의 accountStock 접근
// Pre		: account에 자료 접근
// Post		: this에 자료 접근
=====================================================================================*/
int account::GetMoney()
{
	return money;
}
/*====================================================================================
// Function	: 입금 / 상환
// Pre		: account에 자료 접근
// Post		: this에 자료 접근
=====================================================================================*/
void account::InputMoney()
{
	int temp;
	cout << "\t 입금하실 금액을 입력해주세요 : ";
	cin >> temp;
	money += temp;
	
	if(money < 0)
		check = "상환";
	else
		check = "입금";

	ofstream file;
	time(&t);
	localtime_s(&A, &t);
	char num_temp[10];
	itoa(number,num_temp,10);
	strcat(num_temp,".txt");
	file.open(num_temp, ios::app);
	file << A.tm_year << " " << A.tm_mon << " " << A.tm_mday << " " << A.tm_hour << " " << A.tm_min << " " << A.tm_sec << " " << temp << " " << check << " " << money << "\n";
	file.close();
	cout << "\t " << number << "번 계좌의 잔고는 " << money << "원 입니다. " << endl;
}
/*====================================================================================
// Function	: 출금
// Pre		: account에 자료 접근
// Post		: this에 자료 접근
=====================================================================================*/
void account::OutputMoney()
{
	if(!EnterPassword())
		return;
	int temp;
	cout << "\t 출금하실 금액을 입력해주세요 : ";
	cin >> temp;
	money -= temp;
	if(money < 0)
	{
		cout << "\t 잔액이 부족합니다 !!" << endl;
		money += temp;
		return;
	}
	check = "출금";

	ofstream file;
	time(&t);
	localtime_s(&A, &t);
	char num_temp[10];
	itoa(number,num_temp,10);
	strcat(num_temp,".txt");
	file.open(num_temp, ios::app);
	file << A.tm_year << " " << A.tm_mon << " " << A.tm_mday << " " << A.tm_hour << " " << A.tm_min << " " << A.tm_sec << " " << temp << " " << check << " " << money << "\n";
	file.close();
	cout << "\t " << number << "번 계좌의 잔고는 " << money << "원 입니다. " << endl;
}
/*====================================================================================
// Function	: 대출
// Pre		: account에 자료 접근
// Post	: 대출에 성공하면 파일 출력, 실패하면 client code로 돌아감
=====================================================================================*/
void account::Borrow(){
	if(!EnterPassword())
		return;
	cout << "\t 계좌 잔고 : " << money << endl
		<< "\t 대출 상한금액 : " << upper << endl;
	int temp;			// 대출할 금액 넣는 임시 저장소
	cout << "\t 대출하실 금액을 입력해주세요 : ";
	cin >> temp;			// 대출 금액 입력

	money -= temp;			// 
	if(money < -upper)
	{
		cout << "\t 대출 상한을 넘었습니다!!" << endl;
		money += temp;
		return ;
	}
	check = "대출";

	ofstream file;
	time(&t);
	localtime_s(&A, &t);
	char num_temp[10];
	itoa(number,num_temp,10);
	strcat(num_temp,".txt");
	file.open(num_temp, ios::app);
	file << A.tm_year << " " << A.tm_mon << " " << A.tm_mday << " " << A.tm_hour << " " << A.tm_min << " " << A.tm_sec << " " << temp << " " << check << " " << money << "\n";
	file.close();
	cout << "\t 계좌 잔고 : " << money << endl;
}
/*====================================================================================
// Function	: 비밀번호 입력
// Pre		: account에 자료 접근
// Post		: this에 자료 접근
=====================================================================================*/
bool account::EnterPassword()
{
	int temp;		// 비밀번호 임시 저장소
	cout << "\t 비밀번호를 입력해 주세요 : ";
	cin >> temp;		// 사용자로부터 비밀번호 입력
	if(temp == password)
		return true;		// 맞을 시 true 반환
	cout << "\t 비밀번호가 다릅니다!!!!" << endl;
	return false;		// 틀릴시 false 반환
}

bool account::operator==(account &part1)
{	
	if(number == part1.GetNumberlist())
		return true;
	return false;
}