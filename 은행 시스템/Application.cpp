#include "Application.h"
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#define up 0x48
#define down 0x50
void gotoxy(int x,int y){
	COORD pos={x-1,y-1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
/*====================================================================================
// Function	: default constructor, Initialize member variables.
// Pre		: None
// Post		: Initialize member variables.
=====================================================================================*/
Application::Application()
{
	OpenInputFile();		//불러들이고자 하는 파일 입력
	GetClientListFromFile();	// 파일로부터 고객 입력

	Sleep(1000);
	system("cls");
}

/*====================================================================================
// Function	: Program driver
// Pre		: none
// Post		: none
=====================================================================================*/
void Application::Run()
{
	while(1)
	{
		Menu();		// 메뉴를 불러옴
		Menu_select();
		cout << "\t 아무키나 눌러주세요!";
		key = getch();
		system("cls");
	}
}
/*====================================================================================
// Function	: 고객 업무를 할지 관리자 업무를 할지 선택
// Pre		: none
// Post		: 선택된 기능 실행
=====================================================================================*/
void Application::Menu()
{
	y = 4;
	CW.ShowCW();	// 현재 대기 고객 출력
	cout << "\t┌──────────────────┐" << endl;
	cout << "\t│             메    뉴               │" << endl;
	cout << "\t│  1. 고 객   업 무                  │" << endl;
	cout << "\t│  2. 관 리 자   업 무               │" << endl;
	cout << "\t│  3. 프 로 그 램  종 료             │" << endl;
	cout << "\t└──────────────────┘" << endl;
	cout << "\t  입력 : 키보드 방향키(위, 아래) & 엔터" << endl;
	/*	cout << "\t----- Command ----- " << endl;
	cout << "\t   1 : 고객 업무" << endl;
	cout << "\t   2 : 관리자 업무" << endl;
	cout << "\t   3 : 프로그램 종료 " << endl;
	cout << endl << "\t Choose a Command--> ";
	*/
	gotoxy(42,y);
	cout << "◀";
	for(;;){
		key=0;
		do if(kbhit()) key=getch();
		while(key==224);
		gotoxy(42,y);
		cout <<" ";
		if(key==up && y>=5)y--;
		if(key==down && y<=5)y++;
		if(key==13)break;
		gotoxy(42,y);
		cout <<"◀";
		Sleep(100);
	}
	system("cls");
	/*	try		// 커맨드 입력 시도
	{
	cin >> m_nCurCommand;	// 커맨드 입력
	int key = atoi(m_nCurCommand);	//
	if(key<1 || key >3)
	throw m_nCurCommand[1];
	throw key;

	throw key;
	}
	catch(int key)
	{
	switch(key)
	{
	case 1:
	RunClient();
	break;
	case 2:
	RunAdmin();
	CW.DeleteCW();
	break;
	case 3:
	OpenOutputFile();
	PutClientListToFile();
	exit(100);
	}
	}
	catch(char)
	{
	cout << "\t		선택지의 번호를 입력해주세요 !!" << endl;
	}
	}
	*/
}
void Application::Menu_select()
{
	y -= 3;
	switch(y)
	{
	case 1:
		RunClient();
		Client_select();
		break;
	case 2:
		RunAdmin();
		Admin_select();
		CW.DeleteCW();
		break;
	case 3:
		OpenOutputFile();
		PutClientListToFile();
		exit(100);
	}
}
/*====================================================================================
// Function	: 고객 업무를 할지 관리자 업무를 할지 선택
// Pre		: none
// Post		: 선택된 기능 실행
=====================================================================================*/
void Application::RunClient()
{
	y = 4;
	CW.ShowCW();
	cout << "\t┌──────────────────┐" << endl;
	cout << "\t│             메    뉴               │" << endl;
	cout << "\t│  1. 대 기 표   발 급               │" << endl;
	cout << "\t│  2. 입 금                          │" << endl;
	cout << "\t│  3. 출 금                          │" << endl;
	cout << "\t│  4. 대 출                          │" << endl;
	cout << "\t│  5. 상 환                          │" << endl;
	cout << "\t│  6. 주 택 청 약                    │" << endl;
	cout << "\t│  7. 돌 아 가 기                    │" << endl;
	cout << "\t└──────────────────┘" << endl;
	cout << "\t  입력 : 키보드 방향키(위, 아래) & 엔터" << endl;
	gotoxy(42,y);
	cout << "◀";
	for(;;){
		key=0;
		do if(kbhit()) key=getch();
		while(key==224);
		gotoxy(42,y);
		cout <<" ";
		if(key==up && y>=5)y--;
		if(key==down && y<=9)y++;
		if(key==13)break;
		gotoxy(42,y);
		cout <<"◀";
		Sleep(100);
	}
	system("cls");
	/*	cout << "\t----- Command ----- " << endl;
	cout << "\t   1 : 대기표 발급" << endl;
	cout << "\t   2 : 입금" << endl;
	cout << "\t   3 : 출금" << endl;
	cout << "\t   4 : 대출" << endl;
	cout << "\t   5 : 상환" << endl;
	cout << "\t   6 : 주택 청약" << endl;
	cout << "\t   7 : 돌아가기" << endl;
	cout << endl << "\t Choose a Command--> ";
	try
	{
	cin >> m_nCurCommand;
	int key = atoi(m_nCurCommand);
	if(key<1 || key >7)
	throw m_nCurCommand[1];
	throw key;
	}
	catch(int key)
	{
	switch(key)
	{
	case 1:
	CW.AddCW();
	break;
	case 2:
	InputMoney();
	break;
	case 3:
	OutputMoney();
	break;
	case 4:
	BorrowMoney();
	break;
	case 5:
	InputMoney();
	break;
	case 6:
	SearchList(data);
	data.ApartApplication();
	break;
	case 7:
	return;
	}
	}
	catch(char)
	{
	cout << "\t		선택지의 번호를 입력해주세요 !!" << endl;
	}
	*/
}
void Application::Client_select()
{
	ClientData data;
	y -= 3;
	switch(y)
	{
	case 1:
		CW.AddCW();
		break;
	case 2:
		InputMoney();
		break;
	case 3:
		OutputMoney();
		break;
	case 4:
		BorrowMoney();
		break;
	case 5:
		InputMoney();
		break;
	case 6:
		if(!SearchList(data))
			break;
		data.ApartApplication();
		break;
	case 7:
		return;
	}
}
/*====================================================================================
// Function	: 고객 업무를 할지 관리자 업무를 할지 선택
// Pre		: none
// Post		: 선택된 기능 실행
=====================================================================================*/
void Application::RunAdmin()
{
	CW.ShowCW();
	y = 4;
	cout << "\t┌──────────────────┐" << endl;
	cout << "\t│             메    뉴               │" << endl;
	cout << "\t│  1. 고 객   등 록                  │" << endl;
	cout << "\t│  2. 고 객   삭 제                  │" << endl;
	cout << "\t│  3. 고 객   확 인                  │" << endl;
	cout << "\t│  4. 계 좌   열 기                  │" << endl;
	cout << "\t│  5. 계 좌   닫 기                  │" << endl;
	cout << "\t│  6. 돌 아 가 기                    │" << endl;
	cout << "\t└──────────────────┘" << endl;
	cout << "\t  입력 : 키보드 방향키(위, 아래) & 엔터" << endl;
	gotoxy(42,y);
	cout << "◀";
	for(;;){
		key=0;
		do if(kbhit()) key=getch();
		while(key==224);
		gotoxy(42,y);
		cout <<" ";
		if(key==up && y>=5)y--;
		if(key==down && y<=8)y++;
		if(key==13)break;
		gotoxy(42,y);
		cout <<"◀";
		Sleep(100);
	}
	system("cls");
	/*	cout << "\t----- Command ----- " << endl;
	cout << "\t   1 : 고객 등록" << endl;
	cout << "\t   2 : 고객 삭제" << endl;
	cout << "\t   3 : 고객 확인" << endl;
	cout << "\t   4 : 계좌 열기" << endl;
	cout << "\t   5 : 계좌 닫기" << endl;
	cout << "\t   6 : 돌아가기 " << endl;
	cout << endl << "\t Choose a Command--> ";
	try
	{
	cin >> m_nCurCommand;	// 커맨드 입력
	int key = atoi(m_nCurCommand);	// 커맨드를 int형으로 변경
	if(key<1 || key >6)		// 메뉴중에 없으면
	throw m_nCurCommand[1];	// 에러 catch형으로 throw
	throw key;	// 메뉴에 있으면 메뉴 catch로 throw
	}
	catch(int key)
	{
	switch(key)
	{
	case 1:
	data.GetClientData();		// 고객 정보 입력
	m_ClientList.InsertItem(data); // 고객 추가 함수
	data.PutClientData();	// 고객 정부 화면 출력
	break;
	case 2:
	DeleteClient();	// 고객 리스트 제거 함수
	break;
	case 3:
	if(!SearchList(data))	// 고객 검색
	break;
	data.PutClientData();	// 고객정보 화면에 띄우기
	break;
	case 4:
	OpenAccount();	// 계좌 열기
	break;
	case 5:
	if(!SearchList(data))	// 고객 검색
	break;
	data.CloseAccount();
	break;
	case 6:
	return;
	}
	}
	catch(char)
	{
	cout << "\t		선택지의 번호를 입력해주세요 !!" << endl;
	}
	*/
}
void Application::Admin_select()
{
	y -= 3;
	ClientData data;	// 고객 정보 임시 저장장소
	account temp;	// 계좌 임시 저장소
	switch(y)
	{
	case 1:
		data.GetClientData();		// 고객 정보 입력
		m_ClientList.InsertItem(data); // 고객 추가 함수
		data.PutClientData();	// 고객 정부 화면 출력
		break;
	case 2:
		DeleteClient();	// 고객 리스트 제거 함수
		break;
	case 3:
		if(!SearchList(data))	// 고객 검색
			break;
		data.PutClientData();	// 고객정보 화면에 띄우기
		break;
	case 4:
		OpenAccount();	// 계좌 열기
		break;
	case 5:
		if(!SearchList(data))	// 고객 검색
			break;
		data.CloseAccount();
		break;
	case 6:
		return;
	}
}
/*====================================================================================
// Function	: Delete an Clients in list
// Pre		: none
// Post		: if the Clients is in list then the Clients is deleted from list.
=====================================================================================*/
void Application::DeleteClient()
{
	ClientData temp;
	SearchList(temp);
	m_ClientList.DeleteItem(temp);
	cout << endl << "\t 고객 정보가 성공적으로 삭제되었습니다!" << endl;
}



/*====================================================================================
// Function : search the Clients information in list.
// Pre		: list has to have one Clients at least.
// Post		: display the Clients information if found.
=====================================================================================*/
int Application::SearchList(ClientData &Clients)
{
	ClientData Client;	// 검색하고자하는 부품 생성
	ClientData temp;	// 리스트 내의 Client값
	int index = 0;		// 인덱스 초기화
	bool found= false;	// 검색 스위치정의
	y = 4;
	CW.ShowCW();
	cout << "\t┌──────────────────┐" << endl;
	cout << "\t│             메    뉴               │" << endl;
	cout << "\t│  1. 주민등록번호    검 색          │" << endl;
	cout << "\t│  2. 이 름   검 색                  │" << endl;
	cout << "\t│  3. 전 화 번 호   검 색            │" << endl;
	cout << "\t│  4. 주 소   검 색                  │" << endl;
	cout << "\t└──────────────────┘" << endl;
	cout << "\t  입력 : 키보드 방향키(위, 아래) & 엔터" << endl;
	gotoxy(42,y);
	cout << "◀";
	for(;;){
		key=0;
		do if(kbhit()) key=getch();
		while(key==224);
		gotoxy(42,y);
		cout <<" ";
		if(key==up && y>=5)y--;
		if(key==down && y<=6)y++;
		if(key==13)break;
		gotoxy(42,y);
		cout <<"◀";
		Sleep(100);
	}
	system("cls");
	/*	cout << endl << endl;
	cout << "\t********************************"<<endl;
	cout << "\tInput selecting number"<< endl;
	cout << "\t1 : Selecting by Number "<< endl;
	cout << "\t2 : Selecting by Name "<< endl;
	cout << "\t3 : Selecting by Phone "<< endl;
	cout << "\t4 : Selecting by Address "<< endl;
	cout << "\t********************************"<<endl;
	cout <<"\t select number --->";
	cin>> select;
	*/
	y -= 3;
	m_ClientList.ResetList();
	switch(y)
	{

	case 1:							//부품 번호 검색시
		Client.GetNumberFromKB();		//부품 번호 입력
		for(int i =0;i<m_ClientList.LengthIs();i++)
		{
			m_ClientList.GetCurrentItem(temp);//리스트 내의 데이터 정보를 차례대로 불러옴
			if(*temp.GetNumberlist()==*Client.GetNumberlist())//리스트번호과 검색되는 부품 번호 확인 
			{
				Clients = temp;						//동일할 경우 부품 정보 복사
				found = true;							// 검색스위치 트루
				index = i;
				break;
			}
		}
		if(found == false)								//검색에 실패했을 경우
		{
			cout << "\t !! 고객을 찾을 수 없습니다 !!" << endl;
			return false;
		}
		break;
	case 2:
		Client.GetNameFromKB();								//부품 이름 검색시
		for(int i =0;i<m_ClientList.LengthIs();i++)
		{
			m_ClientList.GetCurrentItem(temp);
			if(temp.GetNamelist()==Client.GetNamelist())		//리스트이름과 검색되는 부품 이름 확인 
			{
				Clients = temp;				//동일할 경우 부품 정보 복사
				found = true;								// 검색스위치 트루
				index = i;
				break;
			}

		}
		if(found == false)									//검색에 실패했을 경우
		{
			cout << "\t !! 고객을 찾을 수 없습니다 !!" << endl;
			return false;
		}
		break;
	case 3:	
		Client.GetPhoneFromKB();							//부품 규격  검색시
		for(int i =0;i<m_ClientList.LengthIs();i++)
		{
			m_ClientList.GetCurrentItem(temp);
			if(temp.GetPhonelist().compare(Client.GetPhonelist()))//리스트이름과 검색되는 부품 이름 확인
			{
				Clients = temp;								//동일할 경우 부품 정보 복사
				found = true;									// 검색스위치 트루
				index = i;
				break;
			}
		}
		if(found == false)										//검색에 실패했을 경우
		{
			cout << "\t !! 고객을 찾을 수 없습니다 !!" << endl;
			return false;
		}
		break;
	case 4:
		Client.GetAddressFromKB();						//부품 규격  검색시
		for(int i =0;i<m_ClientList.LengthIs();i++)
		{
			m_ClientList.GetCurrentItem(temp);
			if(temp.GetAddresslist()==Client.GetAddresslist())//리스트이름, 규격 번호과 검색되는 부품 이름, 규격 번호 확인
			{
				Clients = temp;
				found = true;
				index = i;
				break;
			}
		}
		if(found == false)						//검색에 실패했을 경우
		{
			cout << "\t !! 고객을 찾을 수 없습니다 !!" << endl;
			return false;
		}
		break;

	default:									//잘못된 명령어처리
		cout << "\tWrong choice"<< endl;
		break;
	}

	if(found == true)
	{
		return 1;
	}

	return 0;
}

/*====================================================================================
// Function : file open for read using fileName variable.
// Pre		: none
// Post		: inFile variable get file descriptor
=====================================================================================*/
int Application::OpenInputFile()
{
	cout << "\tinput input file name ";
	cin >> m_cFileName;
	m_ListInFile.open(m_cFileName);

	if(!m_ListInFile.good())
	{
		cout<<"\t해당 파일이 없습니다."<<endl;
	}

	return 1;
}

/*====================================================================================
// Function : file open for write using fileName variable.
// Pre		: none
// Post		: outFile variable get file descriptor
=====================================================================================*/
int Application::OpenOutputFile()
{
	cout << "\tinput Output file name ";
	cin >> m_cFileName;						//오픈하고자 하는 파일
	m_ListOutFile.open(m_cFileName);
	return 1;
}

/*====================================================================================
// Function : read all Clients information from file.
// Pre		: file is opened.
// Post		: update list that has all Clients information from file.
=====================================================================================*/
void Application::GetClientListFromFile()
{
	if(!m_ListInFile.good())
	{
		cout << "\t해당 파일을 읽을 수 없습니다." << endl;
		return;
	}

	while(!m_ListInFile.eof())
	{
		ClientData* temp = new ClientData;				//집어넣고자하는 부품 타입
		if(!temp->GetRecordFromFile(m_ListInFile))
			break;
		m_ClientList.InsertItem(*temp);
		delete temp;
	}
	cout << "\t정상적으로 파일에서 읽었습니다." << endl;
	m_ListInFile.close();
}

/*====================================================================================
// Function : write all Clients information to file.
// Pre		: file is opened.
// Post		: create or update a file that has all Clients information in file.
=====================================================================================*/
void Application::PutClientListToFile()
{
	ClientData temp;					//출력하고하는 부품 타입
	m_ClientList.ResetList();			//부품 리스트 초기화
	m_ClientList.GetCurrentItem(temp);
	for(int i=1; i<m_ClientList.LengthIs()-1;i++)		
	{
		m_ClientList.GetCurrentItem(temp);		//파일 끝까지 currentPos 이동
		temp.PutRecordToFile(m_ListOutFile);
	}
	m_ListOutFile.close();
}

/*====================================================================================
// Function : show all list data.s
// Pre		: none
// Post		: none
=====================================================================================*/
void Application::ShowList()
{
	ClientData temp;
	m_ClientList.ResetList();
	m_ClientList.GetCurrentItem(temp);
	for(int i=0; i<m_ClientList.LengthIs();i++)
	{
		m_ClientList.GetCurrentItem(temp);
		temp.PutClientData();
	}
}
/*====================================================================================
// Function : search the Clients information in list.
// Pre		: list has to have one Clients at least.
// Post		: display the Clients information if found.
=====================================================================================*/
void Application::InputMoney()
{
	ClientData data;
	ClientData data2;
	account temp;
	account temp2;
	if(!SearchList(data))
		return;
	data2.Copy(data);
	if(!data.SearchAccount(temp))
		return;
	temp2.Copy(temp);
	temp.InputMoney();
	data.Account.DeleteItem(temp2);
	data.Account.InsertItem(temp);
	m_ClientList.DeleteItem(data2);
	m_ClientList.InsertItem(data);
}
/*====================================================================================
// Function : search the Clients information in list.
// Pre		: list has to have one Clients at least.
// Post		: display the Clients information if found.
=====================================================================================*/
void Application::OutputMoney()
{
	ClientData data;
	ClientData data2;
	account temp;
	account temp2;
	if(!SearchList(data))
		return;
	data2.Copy(data);
	if(!data.SearchAccount(temp))
		return;
	temp2.Copy(temp);
	temp.OutputMoney();
	data.Account.DeleteItem(temp2);
	data.Account.InsertItem(temp);
	m_ClientList.DeleteItem(data2);
	m_ClientList.InsertItem(data);
}
/*====================================================================================
// Function : search the Clients information in list.
// Pre		: list has to have one Clients at least.
// Post		: display the Clients information if found.
=====================================================================================*/
void Application::BorrowMoney()
{
	ClientData data;
	ClientData data2;
	account temp;
	account temp2;
	if(!SearchList(data))
		return;
	data2.Copy(data);
	if(!data.SearchAccount(temp))
		return;
	temp2.Copy(temp);
	temp.Borrow();
	data.Account.DeleteItem(temp2);
	data.Account.InsertItem(temp);
	m_ClientList.DeleteItem(data2);
	m_ClientList.InsertItem(data);
}
void Application::OpenAccount()
{
	ClientData data;
	ClientData data2;
	account temp;
	account temp2;
	if(!SearchList(data))
		return;
	data2.Copy(data);
	temp.Getaccount(data.GetCredit());
	data.Account.InsertItem(temp);
	m_ClientList.DeleteItem(data2);
	m_ClientList.InsertItem(data);
}
/*====================================================================================
// Function : search the Clients information in list.
// Pre		: list has to have one Clients at least.
// Post		: display the Clients information if found.
=====================================================================================*/
/*void Application::UpdateList(account temp)
{
Doubly<ClientData> Client_temp;	// m_CLientLIst를 저장하는 임시 저장소
Doubly<ClientData> Client_temp2;
ClientData *data = new ClientData;
ClientData data2;
account temp2;

m_ClientList.ResetList();
m_ClientList.GetCurrentItem(data2);
for(int i=0; i<m_ClientList.LengthIs()-1; i++)
{
m_ClientList.GetCurrentItem(data2);
Client_temp.InsertItem(data2);		// Client_temp 초기화
Client_temp2.InsertItem(data2);
}

m_ClientList.MakeEmpty();
m_ClientList.ResetList();	// m_ClientList 비게함

Client_temp.ResetList();
Client_temp.GetCurrentItem(data2);	// Client_temp 사용 준비
Client_temp2.ResetList();
Client_temp2.GetCurrentItem(*data);	// Client_temp2 사용 준비

data2.Account.ResetList();	
data2.Account.GetCurrentItem(temp2);	// data2.Account 사용 준비

for(int i=0; i<Client_temp.LengthIs()-1; i++)
{
Client_temp.GetCurrentItem(data2);	// Client node 하나 받아옴
Client_temp2.GetCurrentItem(*data);
data->Account.ResetList();
data->Account.MakeEmpty();
data2.Account.ResetList();	
data2.Account.GetCurrentItem(temp2);
int a= data2.Account.LengthIs();

for(int j=0; j<a; j++)
{
data2.Account.GetCurrentItem(temp2);
if(temp2.GetNumberlist() == temp.GetNumberlist())
{
data->Account.InsertItem(temp);
}
else
data->Account.InsertItem(temp2);
}
m_ClientList.InsertItem(*data);
}
}*/