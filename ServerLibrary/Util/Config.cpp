#include "stdafx.h"
#include "Config.h"

bool loadConfig(xml_t *config)
{
	if (!config->LoadFile("./config.xml")) {
		printf("! not exist config file.");
		return false;
	}
	return true;
}

/**
void Server::initialize(xml_t *config)
{
	xmlNode_t *root = config->FirstChildElement("App")->FirstChildElement("Server");
	xmlNode_t *elem = root->FirstChildElement("IP");
	strcpy_s(ip_, elem->GetText());

	elem = root->FirstChildElement("Port");
	sscanf_s(elem->GetText(), "%d", &port_);

	elem = root->FirstChildElement("ThreadCount");
	sscanf_s(elem->GetText(), "%d", &workerThreadCount_);

	status_ = SERVER_INITIALIZE;
	SLog(L"* IO worker thread count : %d", workerThreadCount_);
}
 */