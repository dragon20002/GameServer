#include "stdafx.h"
#include "TerminalManager.h"

TerminalManager::TerminalManager() {}

TerminalManager::~TerminalManager()
{
	for (auto iter : terminalPool_) {
		auto terminal = iter.second;
		SAFE_DELETE(terminal);
	}
}

void TerminalManager::initialize(xml_t *config)
{
	xmlNode_t *root = config->FirstChildElement("App")->FirstChildElement("Terminal");
	xmlHandle_t terminalNode = xmlHandle_t(root);
	if (!root) {
		SLog(L"@ not exist terminal setting");
		return;
	}
}

void TerminalManager::put(wstr_t serverName, Terminal *terminal)
{
	terminalPool_.insert(make_pair(serverName, terminal));
}

Terminal* TerminalManager::terminal(wstr_t name)
{
	return terminalPool_.at(name);
}

bool TerminalManager::isTerminal(const char* ip)
{
	for (auto terminal : terminalPool_) {
		if (!strcmp(terminal.second->ip(), ip)) {
			return true;
		}
	}
	return false;
}

void TerminalManager::run(Server *server)
{
	server_ = server;

	xml_t config;
	if (!loadConfig(&config)) {
		return;
	}
	this->initialize(&config);
}

