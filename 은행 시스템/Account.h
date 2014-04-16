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
	int number;	// 통장 번호
	int password;	// 비밀번호
	string standard;	// 계좌 종류
	double rate;	// 이자율
	int upper;	// 상한선
	int money;	// 통장 잔고
	int timeC;

	string check;	// 입/출금, 대출, 상환 체크

public:
	static int Anumber;
	int SetNumber();		//계좌 번호 입력 함수
	int GetPasswordFromKB();		//계좌 이름 입력 함수
	int GetStandardFromKB();	//계좌 규격 입력 함수
	int GetrateFromKB();			//계좌 사용용도 입력 함수
	void GetNumberFromKB();			// 계좌 번호 입력 함수
	int SetUpper(char credit);		//계좌 상한선 설정 함수

	int GetPasswordlist();		//계좌 이름 접근 함수
	int GetNumberlist();		//계좌 번호 접근 함수
	string GetStandardlist();	//계좌 규격 접근 함수
	int GetMoney();			//계좌 잔고 접근 함수
	double Getratelist();		// 이자율 접근 함수

	void Getaccount(char credit);			//계좌 정보 입력 함수
	void Putaccount();			//계좌 정보 출력 함수
	

	struct tm A;	// 시간 구하는 변수
	time_t t;
	int month;	// 월 저장
	int day;	// 일 저장

	/*====================================================================================
	// Function: 하나의 레코드를 file로부터 읽어 들인다.
	// Pre		: file이 open되고 file pointer는 읽어들일 레코드의 위치에 
	// Post		: id와 Password에 결과 저장, file pointer는 맨뒤로 옮겨짐 
	=====================================================================================*/ 
	int GetRecordFromFile(ifstream& fin, char credit);

	/*====================================================================================
	// Function : 하나의 레코드를 file에 저장
	// Pre		: file이 open되고 file pointer는 레코드가 들어갈 위치에
	//			  id와 Password에는 출력될 자료가 저장
	// Post		: 파일에 저장되고 file pointer는 맨 뒤로 옮겨짐 
	=====================================================================================*/
	int PutRecordToFile(ofstream& fout);

	/*====================================================================================
	// Function	: 계좌의 내용을 현 object(또는 this)에 복사
	// Pre		: 계좌에 자료 저장
	// Post		: this에 자료 저장 
	=====================================================================================*/
	void Copy(account part);

	/*====================================================================================	
	//계좌 번호 출력 함수
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutNumberScreen()	
	{
		cout << setw(15) << number;
	}
	
	/*====================================================================================
	//계좌 유형 출력 함수
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutStandardScreen()	
	{
		cout << setw(15) << standard;
	}

	/*====================================================================================
	//계좌 상한선 출력 함수
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutUpperScreen()		
	{
		cout << setw(15) << upper;
	}
	/*====================================================================================
	//계좌 이자율 출력 함수
	// Pre : none
	// Post: none
	=====================================================================================*/
	void PutrateScreen()
	{
		cout << setw(10) << rate;
	}

	void PutMoneyScreen()	{cout << setw(10) << money << endl;}	// 계좌 잔액 출력 함수

	void InputMoney(); // 입금함수
	void OutputMoney();	// 출금함수
	void Borrow();	// 대출함수

	/*====================================================================================
	//암호 입력 함수
	// Pre : 암호가 사전에 지정되어있어야 한다.
	// Post: 키보드로 입력받은 함수가 계좌의 암호와 맞으면 true, 틀리면 false 리턴
	=====================================================================================*/
	bool EnterPassword();
	
	bool operator == (account &part1);
};