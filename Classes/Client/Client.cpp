//#include "Client.h"
//using namespace std;
//
//Client* Client::client_ = new Client();
//
//void Client::initialization() {
//	//��ʼ���׽��ֿ�
//	WORD w_req = MAKEWORD(2, 2);//�汾��
//	WSADATA wsadata;
//	int err;
//	err = WSAStartup(w_req, &wsadata);
//	if (err != 0) {
//		//cout << "��ʼ���׽��ֿ�ʧ�ܣ�" << endl;
//	}
//	else {
//		//cout << "��ʼ���׽��ֿ�ɹ���" << endl;
//	}
//	//���汾��
//	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
//		//cout << "�׽��ֿ�汾�Ų�����" << endl;
//		WSACleanup();
//	}
//	else {
//		//cout << "�׽��ֿ�汾��ȷ��" << endl;
//	}
//	//������˵�ַ��Ϣ
//
//	//���������Ϣ
//	server_addr.sin_family = AF_INET;
//	server_addr.sin_addr.S_un.S_addr = inet_addr("192.168.43.69");
//	server_addr.sin_port = htons(1234);
//	//�����׽���
//	s_server = socket(AF_INET, SOCK_STREAM, 0);
//	if (connect(s_server, (SOCKADDR*)&server_addr, sizeof(SOCKADDR)) == SOCKET_ERROR) {
//		//cout << "����������ʧ�ܣ�" << endl;
//		WSACleanup();
//	}
//	else {
//		//cout << "���������ӳɹ���" << endl;
//	}
//}
//
//void Client::SendAndRecv(const std::string& msg)
//{
//	//����,��������
//
//	cout << "Please send message:";
//	//cin >> send_buf;
//	send_buf[0] = 'h';
//	send_buf[1] = '\0';
//	send_len = send(s_server, msg.c_str(), 100, 0);
//	if (send_len < 0) {
//		cout << "Sending failed!" << endl;
//		//break;
//	}
//
//	
//	return;
//}
//
//void Client::closeNet()
//{
//	//�ر��׽���
//	closesocket(s_server);
//	//�ͷ�DLL��Դ
//	WSACleanup();
//	return;
//}