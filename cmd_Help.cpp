#include "headers.h"
#include "cmd_Handlers.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace cmd;
using namespace tree;

Handler cmd::Help(const Options & options) {
	return [command = options.path](Node * node, std::ostream & out)
	{
		out << "help..." << std::endl;
		return true;
	};
}

