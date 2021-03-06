#pragma once

#ifndef __DBConnector
#define __DBConnector

#include  <iostream>
#include  <sstream>
#include  <memory>
#include  <mysql_connection.h>
#include  <mysql_driver.h>
#include  <mysql_error.h>
#include  <cppconn/Statement.h>
#include  <cppconn/ResultSet.h>
#include "Constants.h"

class DBConnector
{
protected:
	sql::Connection *con;

public:

	DBConnector();
	~DBConnector();
	void Connect(std::string DBName);
	void disConnect();
};


#endif // !__DBConnector