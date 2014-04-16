#include "ClientData.h"
#include <fstream>
using namespace std;
ClientData::ClientData()
{
	num = 0;
	Apart = "없음";
}
/*====================================================================================
// Function	: 키보드에서 번호를 입력받아서 ClientNumber에 저장
// Pre		: none
// Post		: ClientNumber에 고객번호 저장, 읽는 중 에러가 발생하면 0 정상이 이면 1을 리턴
=====================================================================================*/
int ClientData::GetNumberFromKB()
{
	char temp;
	cout << "\tInput Client's Number :  ";
	for(int i=0; i<13; i++)
	{
		cin >> temp;	// 입력된 주민번호를 하나씩 끊어 입력
		number[i] = temp-'0';	// 캐릭터형을 인트값으로 바꿈
	}
	return 1;
}

/*====================================================================================
// Function	: 키보드에서 이름을 입력받아서 ClientName에 저장
// Pre		: none
// Post		: name에 이름 저장, 읽는 중 에러가 발생하면 0 정상이 이면 1을 리턴
=====================================================================================*/
int ClientData::GetNameFromKB()
{
	cout << "\tInput Client's Name :  ";
	cin >> name;
	return 1;
}

/*====================================================================================
// Function	: 키보드에서 주소을 입력받아서 Clientaddress에 저장
// Pre		: none
// Post		: Clientaddress에 주소 저장, 읽는 중 에러가 발생하면 0 정상이 이면 1을 리턴
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
// Function	: 키보드에서 용도를 입력받아서 ClientPhone에 저장
// Pre		: none
// Post		: ClientPhone에 용도 저장, 읽는 중 에러가 발생하면 0 정상이 이면 1을 리턴
=====================================================================================*/
int ClientData::GetPhoneFromKB()
{
	cout << "\tInput Client's Phone :  ";
	cin >> phone;
	return 1;
}

/*====================================================================================
// Function	: 키보드에서 재고를 입력받아서 ClientHouse에 저장
// Pre		: none
// Post		: ClientHouse에 재고를 저장, 읽는 중 에러가 발생하면 0 정상이 이면 1을 리턴
=====================================================================================*/
int ClientData::GetHouseFromKB()
{
	cout << "\tInput Client's House(O,X) :  ";
	cin >> house;
	return 1;
}
/*====================================================================================
// Function	: 키보드에서 재고를 입력받아서 ClientHouse에 저장
// Pre		: none
// Post		: ClientHouse에 재고를 저장, 읽는 중 에러가 발생하면 0 정상이 이면 1을 리턴
=====================================================================================*/
int ClientData::GetCreditFromKB()
{
	cout << "\tInput Client's House(A~D) :  ";
	cin >> credit;
	return 1;
}
/*====================================================================================
// Function	: 키보드에서고객정보를  저장
// Pre		: none
// Post		: 고객정보를 저장
=====================================================================================*/
void ClientData::GetClientData()
{
	GetNumberFromKB();		//고객 번호 입력 함수
	GetNameFromKB();		//고객 이름 입력 함수
	GetAddressFromKB();	//고객 주소 입력 함수
	GetPhoneFromKB();			//고객 휴대폰 번호 입력 함수
	GetHouseFromKB();		//고객 집 소유 여부 입력 함수
	GetCreditFromKB();	// 고객 신용도 입력
}


/*====================================================================================
// Function	: 키보드에서고객정보를  출력
// Pre		: none
// Post		: 고객정보를 출력
=====================================================================================*/
void ClientData::PutClientData()
{
	 cout << setw(15) << "Number" << setw(20) << "Name" << setw(15) << "Phone" << setw(10) << "House"<< setw(10) << "Apart" << endl;
	 PutNumberScreen();		//고객 번호 출력 함수
	 PutNameScreen();		//고객 이름 출력 함수
	 PutPhoneScreen();		//고객 휴대폰 번호 출력 함수
	 PutHouseScreen();		//고객 집 소유 여부 출력 함수
	 PutApartScreen();	// 주택 청약권 소유 여부 출력 함수
	 cout << "\tAddress" << endl;	// 주소 출력을 위해 한줄을 내림
	 PutAddressScreen();	//고객 주소 출력 함수

	 if(Account.LengthIs() == 0)	// 등록된 계좌가 없으면
	 {
		 cout << endl;	// 한줄 출력 후 
		 return;	// 리턴
	 }
	 account temp;	// 임시 계좌 저장소
	 Account.ResetList();
	 Account.GetCurrentItem(temp);	// 현재 고객의 계좌정보 받기
	 cout << endl;
	 for(int i=0; i<Account.LengthIs()-1; i++)	// 계좌 갯수만큼 루프
	 {
		Account.GetCurrentItem(temp);	// 현재 고객의 계좌 정보를 받아
		temp.Putaccount();	// 화면에 출력
	 }

	 cout << endl;
}

/*====================================================================================
// Function : 하나의 레코드를 file로부터 읽어 들인다.
// Pre		: file이 open되고 file pointer는 읽어들일 레코드의 위치에 
// Post		: Client 정보 저장. file pointer는 맨뒤로 옮겨짐  
=====================================================================================*/
int  ClientData::GetRecordFromFile(ifstream& fin)
{
	for(int i=0; i<13; i++)	// 주민등록번호 갯수만큼 루프
	{
		fin>>number[i];		// 주민등록번호 i번째에 입력받아
		number[i] -= 'a';	// 키만큼 뺌
	}
	fin>>name;	// 이름 받기
	fin>>phone;	// 전화번호 받기
	fin>>house;	// 집 소유여부 받기
	fin >> credit;	// 신용도 받기
	fin.ignore(10,'\n');
	getline(fin,address,'\n');	// 주소 받기
	int n;	// 계좌 갯수 
	fin >> n;	// 계좌 갯수 받기
	for(int i=0; i<n; i++)	// 받은 계좌 갯수만큼 루프
		OpenAccount(fin);		// 계좌 열기
	return 1;
}

/*====================================================================================
// Function : 하나의 레코드를 file에 저장
// Pre		: file이 open되고 file pointer는 레코드가 들어갈 위치에
//			  id와 name에는 출력될 자료가 저장
// Post		: 파일에 저장되고 file pointer는 맨 뒤로 옮겨짐 
=====================================================================================*/
int ClientData:: PutRecordToFile(ofstream& fout)
{
	for(int i=0; i<13; i++)	// 주민번호 13자리만큼 루프
	{
		number[i] += 'a';	// 암호화 키값을 더한다
		fout<< number[i] << " ";	// 띄어쓰기 출력
	}
	fout<<name << " "; 		// 이름 출력
	fout<<phone << " ";		// 전화번호 출력
	fout<<house << " ";	// 주택 소유여부 출력
	fout << credit ;	// 신용도 출력
	fout<< endl << address << endl;	// 주소 출력
	if(Account.LengthIs()<=0)	// 계좌가 없으면 리턴
	{
		fout << 0 << endl;
		return 1;
	}
	fout << Account.LengthIs()-1;	// 계좌 갯수 출력
	
	account temp;	// 임시 계좌 저장소 생성
	Account.ResetList();	// 계좌 링크드리스트 리셋
	Account.GetCurrentItem(temp);	// temp에 계좌정보 저장
	for(int i=0; i<Account.LengthIs()-1; i++)	// 계좌 갯수만큼 루프
	{
		fout << endl;	// 계좌가 있으면 endl 출력
		Account.GetCurrentItem(temp);
		temp.PutRecordToFile(fout);		// 계좌정보 출력
	}
	fout << endl;
	return 1;
}

/*====================================================================================
// Function	: Client의 내용을 현 object(또는 this)에 복사
// Pre		: Client에 자료 저장
// Post		: this에 자료 저장 
=====================================================================================*/
void ClientData::Copy(ClientData Client)
{
	for(int i=0; i<13; i++)
		number[i] = Client.number[i];			//고객 번호 복사
	name = Client.name;				//고객 이름 복사
	address = Client.address;		//고객 주소 복사
	phone = Client.phone;					//고객 휴대폰 번호 복사
	house = Client.house;				//고객 집 소유 여부 복사
	credit = Client.credit;
	Account = Client.Account;

}

/*====================================================================================
// Function	: this와 Client를 비교 
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
// Function	: Client의 ClientName 접근
// Pre		: Client에 자료 접근
// Post		: this에 자료 접근 
=====================================================================================*/
string ClientData::GetNamelist()
{
	return name;
}

/*====================================================================================
// Function	: Client의 ClientName 접근
// Pre		: Client에 자료 접근
// Post		: this에 자료 접근 
=====================================================================================*/
string ClientData::GetPhonelist()
{
	return phone;
}

/*====================================================================================
// Function	: Client의 Clientaddress 접근
// Pre		: Client에 자료 접근
// Post		: this에 자료 접근
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
// Function	: 계좌 열기
// Pre		: Client에 자료 접근
// Post		: this에 자료 접근
=====================================================================================*/
void ClientData::OpenAccount(ifstream &fin)
{
	account data;
	data.GetRecordFromFile(fin, credit);
	Account.InsertItem(data);
	num++;
}
/*====================================================================================
// Function	: 계좌 열기
// Pre		: Client에 자료 접근
// Post		: this에 자료 접근
=====================================================================================*/
void ClientData::CloseAccount()
{
	account data;
	if(!SearchAccount(data))
		return;
	Account.DeleteItem(data);
}
/*====================================================================================
// Function	: 계좌 찾기
// Pre		: Client에 자료 접근
// Post		: 찾은 계좌를 data에 입력, 찾으면 true, 못찾으면 false 리턴
=====================================================================================*/
bool ClientData::SearchAccount(account &data)
{
	account dat;	// 검색하고자하는 부품 생성
	account temp;	// 리스트 내의 Client값
	int index = 0;		// 인덱스 초기화
	bool found= false;	// 검색 스위치정의

	Account.ResetList();
	dat.GetNumberFromKB();
	for(int i=0;i<Account.LengthIs();i++)
	{
		Account.GetCurrentItem(temp);//리스트 내의 데이터 정보를 차례대로 불러옴
		if(temp.GetNumberlist()==dat.GetNumberlist())//리스트번호과 검색되는 부품 번호 확인 
		{
			data = temp;				//동일할 경우 부품 정보 복사
			found = true;							// 검색스위치 트루
			index = i;
			break;
		}
	}
	if(found == false)								//검색에 실패했을 경우
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
// Function	: 주택 청약
// Pre		: Client에 자료 접근
// Post		: 고객 상태에 따라서 주택 청약권 입력
=====================================================================================*/
void ClientData::ApartApplication()
{
	if(number[0]<5)
	{
		cout << "\t만 19세가 넘어야 주택 청약권을 획득할 수 있습니다.";
		return;
	}

	int count = 0;
	account atemp;
	string temp;

	if(credit=='A')		// 신용도에 따라 등급 점수 메기기
		count += 4;
	else if(credit == 'B')
		count += 3;
	else if(credit == 'C')
		count += 2;
	else if(credit == 'D')
		count += 1;
	
	if(house == 'X')		// 집이 없으면 우선 순위 올라감
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
		Apart = "1등급";
	else if(count < 11 && count >7)
		Apart =	"2등급"; 
	else if(count < 7 && count > 2)
		Apart = "3등급";

	PutClientData();
}