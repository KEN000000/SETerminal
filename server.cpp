//#include "pch.h"
#include<iostream>
#include<winsock.h>
#include<vector>
#include<map>
#include<string>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
void initialization();
int main() {
	vector<SOCKET>clients;
	string recvMessage[16];
	bool isRecvNewMessage = false;
	map<SOCKET, SOCKADDR_IN>clientsAddr;
	//���峤�ȱ���
	int send_len = 0;
	int recv_len = 0;
	int len = 0;
	const char* text = "nihao";
	//���巢�ͻ������ͽ��ܻ�����
	char send_buf[128];
	char recv_buf[128];
	//���������׽��֣����������׽���
	SOCKET s_server;
	SOCKET s_accept;
	//����˵�ַ�ͻ��˵�ַ
	SOCKADDR_IN server_addr;
	SOCKADDR_IN accept_addr;
	initialization();
	//���������Ϣ
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(1234);
	//�����׽���
	s_server = socket(AF_INET, SOCK_STREAM, 0);
	unsigned long u1 = 1;
	ioctlsocket(s_server, FIONBIO, (unsigned long*)&u1);//����Ϊ������

	if (bind(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		cout << "�׽��ְ�ʧ�ܣ�" << endl;
		WSACleanup();
	}
	else {
		cout << "�׽��ְ󶨳ɹ���" << endl;
	}
	//�����׽���Ϊ����״̬
	if (listen(s_server, SOMAXCONN) < 0) {
		cout << "���ü���״̬ʧ�ܣ�" << endl;
		WSACleanup();
	}
	else {
		cout << "���ü���״̬�ɹ���" << endl;
	}
	cout << "��������ڼ������ӣ����Ժ�...." << endl;
	//������������
	/*len = sizeof(SOCKADDR);
	s_accept = accept(s_server, (SOCKADDR*)&accept_addr, &len);
	if (s_accept == SOCKET_ERROR) {
		cout << "����ʧ�ܣ�" << endl;
		WSACleanup();
		return 0;
	}
	cout << "���ӽ�����׼����������" << endl;*/
	//��������
	while (1) {
		isRecvNewMessage = false;
		//������������
		len = sizeof(SOCKADDR);
		s_accept = accept(s_server, (SOCKADDR*)&accept_addr, &len);
		if (s_accept != SOCKET_ERROR)
		{
			//���ӳɹ���ʱ������±ߵĲ���
			clients.push_back(s_accept);
			
		}
		//recv_len = recv(s_accept, recv_buf, 128, 0);
		//cout << "11111" << recv_buf << endl;

		
		//clientsAddr[s_accept] = accept_addr;
		//�жϵ�i������ǲ��Ƿ�����Ϣ
		for (int i = 0; i < clients.size(); i++)
		{
			recv_len = recv(clients[i], recv_buf, 128, 0);
			if (recv_len < 0) {
				//cout << "222" << endl;
				continue;
			}
			else {
				isRecvNewMessage = true;
				cout << "�ͻ�����Ϣ:" << recv_buf << endl;
				recvMessage[i] = recv_buf;
				for (int j = 0; j < clients.size(); j++)
				{
					char tt[128] = "huifu";
					send(clients[j], tt, 128, 0);
				}

			}	
			
		}


		/*recv_len = recv(s_accept, recv_buf, 128, 0);
		if (recv_len < 0) {
			continue;
			cout << "����ʧ�ܣ�" << endl;
			break;
		}
		else {
			cout << "�ͻ�����Ϣ:" << recv_buf << endl;
		}*/

		/*cout << "������ظ���Ϣ:";
		cin >> send_buf;
		send_len = send(s_accept, send_buf, 100, 0);
		if (send_len < 0) {
			cout << "����ʧ�ܣ�" << endl;
			break;
		}*/
	}
	//�ر��׽���
	closesocket(s_server);
	closesocket(s_accept);
	//�ͷ�DLL��Դ
	WSACleanup();
	return 0;
}
void initialization() {
	//��ʼ���׽��ֿ�
	WORD w_req = MAKEWORD(2, 2);//�汾��
	WSADATA wsadata;
	int err;
	err = WSAStartup(w_req, &wsadata);
	if (err != 0) {
		cout << "��ʼ���׽��ֿ�ʧ�ܣ�" << endl;
	}
	else {
		cout << "��ʼ���׽��ֿ�ɹ���" << endl;
	}
	//���汾��
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
		cout << "�׽��ֿ�汾�Ų�����" << endl;
		WSACleanup();
	}
	else {
		cout << "�׽��ֿ�汾��ȷ��" << endl;
	}
	//������˵�ַ��Ϣ

}