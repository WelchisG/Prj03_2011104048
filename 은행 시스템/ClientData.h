#include "Account.h"
#include "Double.h"

enum RelationType {LESS, GREATER, EQUAL};

class ClientData
{
private:
	string name;	// 고객 이름
	int number[13];	// 고객 번호
	string address;	// 주소
	string phone;	// 전화번호
	char house;	// 주택 소유여부
	char credit;	// 신용도
	string Apart;	// 주택 청약권
	int num;

public:
	ClientData();
	int GetNumberFromKB();		//고객 번호 입력 함수
	int GetNameFromKB();		//고객 이름 입력 함수
	int GetAddressFromKB();	//고객 주소 입력 함수
	int GetPhoneFromKB();			//고객 사용용도 입력 함수
	int GetHouseFromKB();	// 고객 주택 소유 여부 입력 함수
	int GetCreditFromKB();	// 고객 신용도 입력 함수

	string GetNamelist();		//고객 이름 접근 함수
	string GetPhonelist();		//고객 핸드폰 번호 접근 함수
	string GetAddresslist();	//고객 주소 접근 함수
	int* GetNumberlist()	{return number;};	// 고객 주민등록번호 접근 함수
	char GetCredit() {return credit;};	// 고객 신용도 접근 함수

	void GetClientData();			//고객 정보 입력 함수
	void PutClientData();			//고객 정보 출력 함수

	bool SearchAccount(account& data);			// 계좌 찾기

	/*====================================================================================
	// Function: 하나의 레코드를 file로부터 읽어 들인다.
	// Pre		: file이 open되고 file pointer는 읽어들일 레코드의 위치에 
	// Post		: id와 name에 결과 저장, file pointer는 맨뒤로 옮겨짐 
	=====================================================================================*/ 
	int GetRecordFromFile(ifstream& fin);

	/*====================================================================================
	// Function : 하나의 레코드를 file에 저장
	// Pre		: file이 open되고 file pointer는 레코드가 들어갈 위치에
	//			  id와 name에는 출력될 자료가 저장
	// Post		: 파일에 저장되고 file pointer는 맨 뒤로 옮겨짐 
	=====================================================================================*/
	int PutRecordToFile(ofstream& fout);

	/*====================================================================================
	// Function	: part의 내용을 현 object(또는 this)에 복사
	// Pre		: part에 자료 저장
	// Post		: this에 자료 저장 
	=====================================================================================*/
	void Copy(ClientData part);

	RelationType CompareByNumber(ClientData part); //고객 번호 비교 함수

	/*====================================================================================	
	//고객 번호 출력 함수
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
	//고객 이름 출력 함수
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutNameScreen()		{		cout << setw(13)<< name;	}

	/*====================================================================================
	//고객 주소 출력 함수
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutAddressScreen()		{		cout << "\t" << address;	}

	/*====================================================================================
	//고객 핸드폰 번호 출력 함수
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutPhoneScreen()		{		cout << setw(15) << phone ;	}

	/*====================================================================================
	//고객 집 소유 여부 출력 함수
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutHouseScreen()		{		cout << setw(10)<< house;	}
	void PutCreditScreen()	{		cout << setw(10)<< credit ;	}	// 신용도 출력 함수
	void PutApartScreen() {cout << setw(10) << Apart << endl;}	// 주택 청약권 출력 함수

	void OpenAccount(ifstream &file);	//	계좌 열기
	void CloseAllAccount();	// 모든 계좌 닫기
	void CloseAccount();	// 계좌 닫기
	void ApartApplication();	// 주택 청약

	// 1) '==' operator overloading
	// 2) '=' operator overloading
	bool operator == (ClientData &part1);
	ClientData operator = (ClientData & part2);

	Doubly<account> Account;
};