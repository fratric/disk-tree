#include "gtest/gtest.h"

#include "../cmd_Handler.h"

#include <sstream>

TEST(Help, Command)
{
	auto command = cmd::GetHandler("help");
	EXPECT_NE(command, nullptr);

	std::stringstream str;

	EXPECT_TRUE(command(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "Dostupne prikazy: quit, list, size, tree, dump, rm, mkdir, link, touch \nNapiste 'help prikaz' pre viac detailov\n");

	str.str(std::string());
	auto command_quit = cmd::GetHandler("help quit");
	EXPECT_NE(command_quit, nullptr);
	EXPECT_TRUE(command_quit(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "quit\nukoncenie prace s aplikaciou\n");

	str.str(std::string());
	auto command_list = cmd::GetHandler("help list");
	EXPECT_NE(command_list, nullptr);
	EXPECT_TRUE(command_list(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "list [-follow] [-recursive] [path]\nvypis definovaneho adresara (path) alebo hlavneho adresara (default), s moznostou 'sledovat' linky (follow) alebo sa rekurzivne vnarat do adresarov (recursive)\n");

	str.str(std::string());
	auto command_size = cmd::GetHandler("help size");
	EXPECT_NE(command_size, nullptr);
	EXPECT_TRUE(command_size(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "size [-follow] [-recursive] [path]\nvypis velkosti suboru/adresara, je mozne zahrnut odkazovane subory/adresare (follow) alebo rekurzivne pridat vnorene adresare (recursive)\n");

	str.str(std::string());
	auto command_tree = cmd::GetHandler("help tree");
	EXPECT_NE(command_tree, nullptr);
	EXPECT_TRUE(command_tree(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "tree [path]\nzobrazenie stromovej struktury pre danu cestu (path) alebo pre hlavny adresar (default); zobrazenie podobne ako prikaz tree pre MS Windows\n");

	str.str(std::string());
	auto command_dump = cmd::GetHandler("help dump");
	EXPECT_NE(command_dump, nullptr);
	EXPECT_TRUE(command_dump(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "dump [path]\nvypis hierarchie danej cesty (default - hlavny adresar) v json formate\n");

	str.str(std::string());
	auto command_rm = cmd::GetHandler("help rm");
	EXPECT_NE(command_rm, nullptr);
	EXPECT_TRUE(command_rm(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "rm <path>\nzmazanie suboru/adresara/odkazu\n");

	str.str(std::string());
	auto command_mkdir = cmd::GetHandler("help mkdir");
	EXPECT_NE(command_mkdir, nullptr);
	EXPECT_TRUE(command_mkdir(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "mkdir <path>\nvytvorenie adresara\n");

	str.str(std::string());
	auto command_link = cmd::GetHandler("help link");
	EXPECT_NE(command_link, nullptr);
	EXPECT_TRUE(command_link(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "link <name> <path>\nvytvorenie odkazu\n");

	str.str(std::string());
	auto command_touch = cmd::GetHandler("help touch");
	EXPECT_NE(command_touch, nullptr);
	EXPECT_TRUE(command_touch(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(),"touch <path> [size]\nvytvorenie suboru (default velkost je 0B)\n");

	str.str(std::string());
	auto command_bad = cmd::GetHandler("help adsvasdvc");
	EXPECT_NE(command_bad, nullptr);
	EXPECT_TRUE(command_bad(nullptr, str));
	EXPECT_FALSE(str.str().empty());
	EXPECT_STREQ(str.str().c_str(), "adsvasdvc\nPrikaz nenajdeny\n");

}
