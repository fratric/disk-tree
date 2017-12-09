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
		std::string str;
		std::string prk;
		if (command == "/") {
			str = "Dostupne prikazy: quit, list, size, tree, dump, rm, mkdir, link, touch \nNapiste 'help prikaz' pre viac detailov";
		}
		else if (command == "quit") {
			prk = "quit";
			str = "ukoncenie prace s aplikaciou";
		}
		else if (command == "list") {
			prk = "list [-follow] [-recursive] [path]";
			str = "vypis definovaneho adresara (path) alebo hlavneho adresara (default), s moznostou 'sledovat' linky (follow) alebo sa rekurzivne vnarat do adresarov (recursive)";
		}
		else if (command == "size") {
			prk = "size [-follow] [-recursive] [path]";
			str = "vypis velkosti suboru/adresara, je mozne zahrnut odkazovane subory/adresare (follow) alebo rekurzivne pridat vnorene adresare (recursive)";
		}
		else if (command == "tree") {
			prk = "tree [path]";
			str = "zobrazenie stromovej struktury pre danu cestu (path) alebo pre hlavny adresar (default); zobrazenie podobne ako prikaz tree pre MS Windows";
		}
		else if (command == "dump") {
			prk = "dump [path]";
			str = "vypis hierarchie danej cesty (default - hlavny adresar) v json formate";
		}
		else if (command == "rm") {
			prk = "rm <path>";
			str = "zmazanie suboru/adresara/odkazu";
		}
		else if (command == "mkdir") {
			prk = "mkdir <path>";
			str = "vytvorenie adresara";
		}
		else if (command == "link") {
			prk = "link <name> <path>";
			str = "vytvorenie odkazu";
		}
		else if (command == "touch") {
			prk = "touch <path> [size]";
			str = "vytvorenie suboru (default velkost je 0B)";
		}
		else {
			prk = command;
			str = "Prikaz nenajdeny";
		}
		if (command != "/") {
			out << prk << std::endl;
		}
		
		out << str << std::endl;
		return true;
	};
}

