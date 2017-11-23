#include "headers.h"
#include "tree_Link.h"

#ifdef _DEBUG
#define new DBG_NEW
#endif

using namespace tree;

tree::Size Link::Size(bool bFollow, bool bRecursive) const
{
	return bFollow && _link.lock() ? _link.lock()->Size(bFollow, bRecursive) : .0;
}

void Link::List(bool bFollow, bool bRecursive, const std::string & offset, std::ostream & out) const
{
	out << Name() << " -" << (_link.lock() ? "-" : "X") << "-> " << _path;
	if (_link.lock() && bFollow)
	{
		out << " // ";
		_link.lock()->List(bFollow, bRecursive, offset, out);
	}
	else
	{
		out << std::endl;
	}
}

#include <memory>

std::shared_ptr<Link> Link::Parse(rapidjson::Value & json)
{
	if (!json.HasMember("name") || !json.HasMember("link"))
		return nullptr;

	std::shared_ptr<Link> ptr{new Link(json["name"].GetString(), json["link"].GetString())};
	return ptr;
}
