
#include <map>
#include <deque>
#include <ctime>
#include <iostream>

class Client
{
	private:
		std::time_t	_id;
		std::string	_name;
		std::string	_nickname;
};

class Channel
{
	private:
		std::string						_name;
		std::string						_password;
		std::string						_topic;
		std::map<std::time_t, Client>	_users;
		std::deque<std::time_t>			_admins;
		int								_mode[5];
};

class Server
{
	private:
		int								_port;
		std::map<std::string, Channel>	_channels;
};