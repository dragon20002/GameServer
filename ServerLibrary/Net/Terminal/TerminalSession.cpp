#include "stdafx.h"
#include "TerminalSession.h"
#include "../Packet/PacketAnalyzer.h"

bool TerminalSession::connectTo(char *ip, int port)
{
	socketData_.socket_ = ::socket(AF_INET, SOCK_STREAM, 0);
	if (socketData_.socket_ == INVALID_SOCKET) {
		SLog(L"! terminal socket fail");
		return false;
	}
	ZeroMemory(&socketData_.addrInfo_, sizeof(socketData_.addrInfo_));
	socketData_.addrInfo_.sin_family = AF_INET;
	socketData_.addrInfo_.sin_port = htons(port);
	inet_pton(AF_INET, ip, &(socketData_.addrInfo_.sin_addr));

	this->setSocketOpt();

	int ret = ::connect(socketData_.socket_, (sockaddr*)&socketData_.addrInfo_, sizeof(socketData_.addrInfo_));
	if (ret == SOCKET_ERROR) {
		SLog(L"! terminal socket connect fail");
		return false;
	}
	return true;
}

void TerminalSession::onSend(size_t transferSize)
{
	// Empty
}

void TerminalSession::sendPacket(Packet* packet)
{
	Stream stream;
	packet->encode(stream);

	packet_size_t offset = 0;
	array<char, SOCKET_BUF_SIZE> buffer;
	packet_size_t packetLen[1] = { sizeof(packet_size_t) + (packet_size_t)stream.size(), };

	memcpy_s(buffer.data() + offset, buffer.max_size(), (void*)packetLen, sizeof(packetLen));
	offset += sizeof(packetLen);
	memcpy_s(buffer.data() + offset, buffer.max_size(), stream.data(), packetLen[0]);
	offset += (packet_size_t)stream.size();

	// ��Ŷ ������
	::send(socketData_.socket_, buffer.data(), offset, 0);
}

Package* TerminalSession::onRecv(size_t transferSize)
{
	// ��Ŷ �ޱ�
	array<char, SOCKET_BUF_SIZE> rowData;
	int ret = ::recv(socketData_.socket_, rowData.data(), (int)rowData.size(), 0);
	if (ret <= 0) {
		return nullptr;
	}
	// ��Ŷ ���� ��������
	packet_size_t offset = 0;
	packet_size_t packetLen[1] = { 0, };

	memcpy_s((void*)packetLen, sizeof(packetLen), (void*)rowData.data(), sizeof(packetLen));
	offset += sizeof(packetLen);

	// ���� �� ��Ŷ ó��
	Packet* packet = PacketAnalyzer::getInstance().analyzer(rowData.data() + offset, packetLen[0]);
	if (packet == nullptr) {
		return nullptr;
	}

	Package* package = new Package(this, packet);
	return package;
}
