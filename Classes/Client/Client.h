/**
* @file Client.h
*/

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")

class Client
{
private:
	//���峤�ȱ���
	int send_len = 0;
	int recv_len = 0;
	//���巢�ͻ������ͽ��ܻ�����
	char send_buf[128];
	char recv_buf[128];
	//���������׽��֣����������׽���
	SOCKET s_server;
	//����˵�ַ�ͻ��˵�ַ
	SOCKADDR_IN server_addr;
	static Client* client_;

public:
	void initialization();
	void Send(const char*);
	void closeNet();
	bool Receive();
	static Client* getInstance(){ return client_;}
};



#endif // !__CLIENT_H__