#include "ClientWait.h"

class Application
{
public:

	/*====================================================================================
	// Function	: default constructor, Initialize member variables.
	// Pre		: None
	// Post		: Initialize member variables.
	=====================================================================================*/
	Application();

	/*====================================================================================
	// Function: Program driver
	// Pre: none
	// Post : none
    =====================================================================================*/
	void Run();

	/*====================================================================================
	// Function	: Add new Clients to list, New item information is from keyboard. add using AddRecord() function
	// Pre		: No same Clients information in list.
	// Post		: list is added new item. if list is full,
	=====================================================================================*/
	void AddClient(ClientData &Client);

	/*====================================================================================
	// Function	: Delete an Clients in list
	// Pre		: none
	// Post		: if the Clients is in list then the Clients is deleted from list.
	=====================================================================================*/
	void DeleteClient();
	
	/*====================================================================================
	// Function : search the Clients information in list.
	// Pre		: list has to have one Clients at least.
	// Post		: display the Clients information if found.
	=====================================================================================*/
	int SearchList(ClientData &Client);

	/*====================================================================================
	// Function : file open for read using fileName variable.
	// Pre		: none
	// Post		: inFile variable get file descriptor
	=====================================================================================*/
	int OpenInputFile();

	/*====================================================================================
	// Function : file open for write using fileName variable.
	// Pre		: none
	// Post		: outFile variable get file descriptor
	=====================================================================================*/
	int OpenOutputFile();

	/*====================================================================================
	// Function : read all Clients information from file.
	// Pre		: file is opened.
	// Post		: update list that has all Clients information from file.
	=====================================================================================*/
	void GetClientListFromFile();

	/*====================================================================================
	// Function : write all Clients information to file.
	// Pre		: file is opened.
	// Post		: create or update a file that has all Clients information in file.
	=====================================================================================*/
	void PutClientListToFile();

	/*====================================================================================
	// Function : show all list data.s
	// Pre		: none
	// Post		: none
	=====================================================================================*/
	void ShowList();

	//void UpdateList(account temp);	// ����Ʈ ������Ʈ
	
	void InputMoney();	//	�Ա�
	void OutputMoney();	//  ���
	void BorrowMoney();	//  ����
	void ReturnMoney();	//  ��ȯ
	void OpenAccount();	// ���� ����

	void Menu();	// ������ ���������� ����
	void Menu_select();
	void RunAdmin();	// ������ ���� �޴� ����
	void Admin_select();
	void RunClient();	// �� ���� �޴� ����
	void Client_select();
	
private:
	Doubly<ClientData> m_ClientList;	// double linked list
	char m_nCurCommand[100];					// current command number
	char m_cFileName[80];				// fileName for reading or writing file
	ofstream m_ListOutFile;			// out file descriptor
	ifstream m_ListInFile;			// in file descriptor
	ClientWait CW;		// �� ��� Ŭ����

	int y;
	int key;
};