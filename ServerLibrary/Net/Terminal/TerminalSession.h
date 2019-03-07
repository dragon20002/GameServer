/**
TerminalManager
�� Terminal
	�� TerminalSession : Session
*/
/**
���� ����
- ����/�α��� ����, ä�ü��� : Ŭ���̾�Ʈ ��ü ���� ����
- �߰�(relay) ����		 : Ŭ���̾�Ʈ�� ���忡 ������ �л��Ŵ
- �� / ���� ������		 : Ŭ���̾�Ʈ ���� ����. ���� ���尡 �߰� ������ �����
- DB �߰� / ĳ�� ����	 : DB ���� ���
- Billing ����			 : �ַ� ���ֳ� �ܺ� �� ����� ���
- �α� / ���� ����		 : ���� ���� ���α׷�. CPU, �޸�, CCU ���� ����͸��ϰų� ���ǽð��� ���� ����� ���
*/
#pragma once
#include "stdafx.h"

class TerminalSession :public Session
{
public:
	bool	connectTo(char *ip, int port);
	void	onSend(size_t transferSize);
	void	sendPacket(Packet* packet);
	Package* onRecv(size_t transferSize);
};