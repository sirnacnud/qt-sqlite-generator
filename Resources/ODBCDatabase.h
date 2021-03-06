#ifndef <%PRODUCTNAME%>DATABASE_H
#define <%PRODUCTNAME%>DATABASE_H

//The MIT License
//
//Copyright (c) 2006-2010 Michael Simpson
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//THE SOFTWARE.

// This File was auto generated on <%date%> by <%applicationName%>.  
// Do not modify!!!!!
// Changes will be overwritten.

#include <QSqlDatabase>

#include "<%productInclude%>"
<%includes%>

#include "ODBCDrivers.h"
<%namespaceStart%>
// singleton class encapsulating Qt database
class <%dllExport%> <%productName%>Database
{
public:
	<%productName%>Database();
	virtual ~<%productName%>Database();

	void CreateConnection(const QString& connectionName);

	// Use this to pass a connection string to QT
	void SetConnectionString(const QString& connectionString)
		{ _connectionString = connectionString; }
	QString ConnectionString(void)
		{ return _connectionString; }

	// Or...use these and a connection string will be created for you
	void SetODBCDriver(ODBCDrivers odbcDriver);
	void SetHost(const QString& host);
	void SetPort(int portNum);
	void SetDatabase(const QString& database);
	void SetUserName(const QString& userName);
	void SetPassword(const QString& password);

	QSqlDatabase Database(void)
		{ return _database; }

	bool Open(void);
	void Close(void);

	bool IsOpen(void);

	bool BeginTransaction(void)
	{
		return _database.transaction();
	}

	bool CommitTransaction(void)
	{
		return _database.commit();
	}

	bool RollbackTransaction(void)
	{
		return _database.rollback();
	}

	// Tables
<%tables%>
	// Views
<%views%>
protected:
<%tablePtrs%>

	QSqlDatabase				_database;

private:
	QString						_connectionName;
	QString						_connectionString;

	QString						_driverString;
	QString						_host;
	QString						_port;
	QString						_databaseName;
	QString						_userName;
	QString						_password;

	void BuildConnectionString(void);
};
<%namespaceEnd%>
#endif
