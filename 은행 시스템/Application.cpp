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
	OpenInputFile();		//�ҷ����̰��� �ϴ� ���� �Է�
	GetClientListFromFile();	// ���Ϸκ��� �� �Է�

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
		Menu();		// �޴��� �ҷ���
		Menu_select();
		cout << "\t �ƹ�Ű�� �����ּ���!";
		key = getch();
		system("cls");
	}
}
/*====================================================================================
// Function	: �� ������ ���� ������ ������ ���� ����
// Pre		: none
// Post		: ���õ� ��� ����
=====================================================================================*/
void Application::Menu()
{
	y = 4;
	CW.ShowCW();	// ���� ��� �� ���
	cout << "\t����������������������������������������" << endl;
	cout << "\t��             ��    ��               ��" << endl;
	cout << "\t��  1. �� ��   �� ��                  ��" << endl;
	cout << "\t��  2. �� �� ��   �� ��               ��" << endl;
	cout << "\t��  3. �� �� �� ��  �� ��             ��" << endl;
	cout << "\t����������������������������������������" << endl;
	cout << "\t  �Է� : Ű���� ����Ű(��, �Ʒ�) & ����" << endl;
	/*	cout << "\t----- Command ----- " << endl;
	cout << "\t   1 : �� ����" << endl;
	cout << "\t   2 : ������ ����" << endl;
	cout << "\t   3 : ���α׷� ���� " << endl;
	cout << endl << "\t Choose a Command--> ";
	*/
	gotoxy(42,y);
	cout << "��";
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
		cout <<"��";
		Sleep(100);
	}
	system("cls");
	/*	try		// Ŀ�ǵ� �Է� �õ�
	{
	cin >> m_nCurCommand;	// Ŀ�ǵ� �Է�
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
	cout << "\t		�������� ��ȣ�� �Է����ּ��� !!" << endl;
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
// Function	: �� ������ ���� ������ ������ ���� ����
// Pre		: none
// Post		: ���õ� ��� ����
=====================================================================================*/
void Application::RunClient()
{
	y = 4;
	CW.ShowCW();
	cout << "\t����������������������������������������" << endl;
	cout << "\t��             ��    ��               ��" << endl;
	cout << "\t��  1. �� �� ǥ   �� ��               ��" << endl;
	cout << "\t��  2. �� ��                          ��" << endl;
	cout << "\t��  3. �� ��                          ��" << endl;
	cout << "\t��  4. �� ��                          ��" << endl;
	cout << "\t��  5. �� ȯ                          ��" << endl;
	cout << "\t��  6. �� �� û ��                    ��" << endl;
	cout << "\t��  7. �� �� �� ��                    ��" << endl;
	cout << "\t����������������������������������������" << endl;
	cout << "\t  �Է� : Ű���� ����Ű(��, �Ʒ�) & ����" << endl;
	gotoxy(42,y);
	cout << "��";
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
		cout <<"��";
		Sleep(100);
	}
	system("cls");
	/*	cout << "\t----- Command ----- " << endl;
	cout << "\t   1 : ���ǥ �߱�" << endl;
	cout << "\t   2 : �Ա�" << endl;
	cout << "\t   3 : ���" << endl;
	cout << "\t   4 : ����" << endl;
	cout << "\t   5 : ��ȯ" << endl;
	cout << "\t   6 : ���� û��" << endl;
	cout << "\t   7 : ���ư���" << endl;
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
	cout << "\t		�������� ��ȣ�� �Է����ּ��� !!" << endl;
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
// Function	: �� ������ ���� ������ ������ ���� ����
// Pre		: none
// Post		: ���õ� ��� ����
=====================================================================================*/
void Application::RunAdmin()
{
	CW.ShowCW();
	y = 4;
	cout << "\t����������������������������������������" << endl;
	cout << "\t��             ��    ��               ��" << endl;
	cout << "\t��  1. �� ��   �� ��                  ��" << endl;
	cout << "\t��  2. �� ��   �� ��                  ��" << endl;
	cout << "\t��  3. �� ��   Ȯ ��                  ��" << endl;
	cout << "\t��  4. �� ��   �� ��                  ��" << endl;
	cout << "\t��  5. �� ��   �� ��                  ��" << endl;
	cout << "\t��  6. �� �� �� ��                    ��" << endl;
	cout << "\t����������������������������������������" << endl;
	cout << "\t  �Է� : Ű���� ����Ű(��, �Ʒ�) & ����" << endl;
	gotoxy(42,y);
	cout << "��";
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
		cout <<"��";
		Sleep(100);
	}
	system("cls");
	/*	cout << "\t----- Command ----- " << endl;
	cout << "\t   1 : �� ���" << endl;
	cout << "\t   2 : �� ����" << endl;
	cout << "\t   3 : �� Ȯ��" << endl;
	cout << "\t   4 : ���� ����" << endl;
	cout << "\t   5 : ���� �ݱ�" << endl;
	cout << "\t   6 : ���ư��� " << endl;
	cout << endl << "\t Choose a Command--> ";
	try
	{
	cin >> m_nCurCommand;	// Ŀ�ǵ� �Է�
	int key = atoi(m_nCurCommand);	// Ŀ�ǵ带 int������ ����
	if(key<1 || key >6)		// �޴��߿� ������
	throw m_nCurCommand[1];	// ���� catch������ throw
	throw key;	// �޴��� ������ �޴� catch�� throw
	}
	catch(int key)
	{
	switch(key)
	{
	case 1:
	data.GetClientData();		// �� ���� �Է�
	m_ClientList.InsertItem(data); // �� �߰� �Լ�
	data.PutClientData();	// �� ���� ȭ�� ���
	break;
	case 2:
	DeleteClient();	// �� ����Ʈ ���� �Լ�
	break;
	case 3:
	if(!SearchList(data))	// �� �˻�
	break;
	data.PutClientData();	// ������ ȭ�鿡 ����
	break;
	case 4:
	OpenAccount();	// ���� ����
	break;
	case 5:
	if(!SearchList(data))	// �� �˻�
	break;
	data.CloseAccount();
	break;
	case 6:
	return;
	}
	}
	catch(char)
	{
	cout << "\t		�������� ��ȣ�� �Է����ּ��� !!" << endl;
	}
	*/
}
void Application::Admin_select()
{
	y -= 3;
	ClientData data;	// �� ���� �ӽ� �������
	account temp;	// ���� �ӽ� �����
	switch(y)
	{
	case 1:
		data.GetClientData();		// �� ���� �Է�
		m_ClientList.InsertItem(data); // �� �߰� �Լ�
		data.PutClientData();	// �� ���� ȭ�� ���
		break;
	case 2:
		DeleteClient();	// �� ����Ʈ ���� �Լ�
		break;
	case 3:
		if(!SearchList(data))	// �� �˻�
			break;
		data.PutClientData();	// ������ ȭ�鿡 ����
		break;
	case 4:
		OpenAccount();	// ���� ����
		break;
	case 5:
		if(!SearchList(data))	// �� �˻�
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
	cout << endl << "\t �� ������ ���������� �����Ǿ����ϴ�!" << endl;
}



/*====================================================================================
// Function : search the Clients information in list.
// Pre		: list has to have one Clients at least.
// Post		: display the Clients information if found.
=====================================================================================*/
int Application::SearchList(ClientData &Clients)
{
	ClientData Client;	// �˻��ϰ����ϴ� ��ǰ ����
	ClientData temp;	// ����Ʈ ���� Client��
	int index = 0;		// �ε��� �ʱ�ȭ
	bool found= false;	// �˻� ����ġ����
	y = 4;
	CW.ShowCW();
	cout << "\t����������������������������������������" << endl;
	cout << "\t��             ��    ��               ��" << endl;
	cout << "\t��  1. �ֹε�Ϲ�ȣ    �� ��          ��" << endl;
	cout << "\t��  2. �� ��   �� ��                  ��" << endl;
	cout << "\t��  3. �� ȭ �� ȣ   �� ��            ��" << endl;
	cout << "\t��  4. �� ��   �� ��                  ��" << endl;
	cout << "\t����������������������������������������" << endl;
	cout << "\t  �Է� : Ű���� ����Ű(��, �Ʒ�) & ����" << endl;
	gotoxy(42,y);
	cout << "��";
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
		cout <<"��";
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

	case 1:							//��ǰ ��ȣ �˻���
		Client.GetNumberFromKB();		//��ǰ ��ȣ �Է�
		for(int i =0;i<m_ClientList.LengthIs();i++)
		{
			m_ClientList.GetCurrentItem(temp);//����Ʈ ���� ������ ������ ���ʴ�� �ҷ���
			if(*temp.GetNumberlist()==*Client.GetNumberlist())//����Ʈ��ȣ�� �˻��Ǵ� ��ǰ ��ȣ Ȯ�� 
			{
				Clients = temp;						//������ ��� ��ǰ ���� ����
				found = true;							// �˻�����ġ Ʈ��
				index = i;
				break;
			}
		}
		if(found == false)								//�˻��� �������� ���
		{
			cout << "\t !! ���� ã�� �� �����ϴ� !!" << endl;
			return false;
		}
		break;
	case 2:
		Client.GetNameFromKB();								//��ǰ �̸� �˻���
		for(int i =0;i<m_ClientList.LengthIs();i++)
		{
			m_ClientList.GetCurrentItem(temp);
			if(temp.GetNamelist()==Client.GetNamelist())		//����Ʈ�̸��� �˻��Ǵ� ��ǰ �̸� Ȯ�� 
			{
				Clients = temp;				//������ ��� ��ǰ ���� ����
				found = true;								// �˻�����ġ Ʈ��
				index = i;
				break;
			}

		}
		if(found == false)									//�˻��� �������� ���
		{
			cout << "\t !! ���� ã�� �� �����ϴ� !!" << endl;
			return false;
		}
		break;
	case 3:	
		Client.GetPhoneFromKB();							//��ǰ �԰�  �˻���
		for(int i =0;i<m_ClientList.LengthIs();i++)
		{
			m_ClientList.GetCurrentItem(temp);
			if(temp.GetPhonelist().compare(Client.GetPhonelist()))//����Ʈ�̸��� �˻��Ǵ� ��ǰ �̸� Ȯ��
			{
				Clients = temp;								//������ ��� ��ǰ ���� ����
				found = true;									// �˻�����ġ Ʈ��
				index = i;
				break;
			}
		}
		if(found == false)										//�˻��� �������� ���
		{
			cout << "\t !! ���� ã�� �� �����ϴ� !!" << endl;
			return false;
		}
		break;
	case 4:
		Client.GetAddressFromKB();						//��ǰ �԰�  �˻���
		for(int i =0;i<m_ClientList.LengthIs();i++)
		{
			m_ClientList.GetCurrentItem(temp);
			if(temp.GetAddresslist()==Client.GetAddresslist())//����Ʈ�̸�, �԰� ��ȣ�� �˻��Ǵ� ��ǰ �̸�, �԰� ��ȣ Ȯ��
			{
				Clients = temp;
				found = true;
				index = i;
				break;
			}
		}
		if(found == false)						//�˻��� �������� ���
		{
			cout << "\t !! ���� ã�� �� �����ϴ� !!" << endl;
			return false;
		}
		break;

	default:									//�߸��� ��ɾ�ó��
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
		cout<<"\t�ش� ������ �����ϴ�."<<endl;
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
	cin >> m_cFileName;						//�����ϰ��� �ϴ� ����
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
		cout << "\t�ش� ������ ���� �� �����ϴ�." << endl;
		return;
	}

	while(!m_ListInFile.eof())
	{
		ClientData* temp = new ClientData;				//����ְ����ϴ� ��ǰ Ÿ��
		if(!temp->GetRecordFromFile(m_ListInFile))
			break;
		m_ClientList.InsertItem(*temp);
		delete temp;
	}
	cout << "\t���������� ���Ͽ��� �о����ϴ�." << endl;
	m_ListInFile.close();
}

/*====================================================================================
// Function : write all Clients information to file.
// Pre		: file is opened.
// Post		: create or update a file that has all Clients information in file.
=====================================================================================*/
void Application::PutClientListToFile()
{
	ClientData temp;					//����ϰ��ϴ� ��ǰ Ÿ��
	m_ClientList.ResetList();			//��ǰ ����Ʈ �ʱ�ȭ
	m_ClientList.GetCurrentItem(temp);
	for(int i=1; i<m_ClientList.LengthIs()-1;i++)		
	{
		m_ClientList.GetCurrentItem(temp);		//���� ������ currentPos �̵�
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
Doubly<ClientData> Client_temp;	// m_CLientLIst�� �����ϴ� �ӽ� �����
Doubly<ClientData> Client_temp2;
ClientData *data = new ClientData;
ClientData data2;
account temp2;

m_ClientList.ResetList();
m_ClientList.GetCurrentItem(data2);
for(int i=0; i<m_ClientList.LengthIs()-1; i++)
{
m_ClientList.GetCurrentItem(data2);
Client_temp.InsertItem(data2);		// Client_temp �ʱ�ȭ
Client_temp2.InsertItem(data2);
}

m_ClientList.MakeEmpty();
m_ClientList.ResetList();	// m_ClientList �����

Client_temp.ResetList();
Client_temp.GetCurrentItem(data2);	// Client_temp ��� �غ�
Client_temp2.ResetList();
Client_temp2.GetCurrentItem(*data);	// Client_temp2 ��� �غ�

data2.Account.ResetList();	
data2.Account.GetCurrentItem(temp2);	// data2.Account ��� �غ�

for(int i=0; i<Client_temp.LengthIs()-1; i++)
{
Client_temp.GetCurrentItem(data2);	// Client node �ϳ� �޾ƿ�
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