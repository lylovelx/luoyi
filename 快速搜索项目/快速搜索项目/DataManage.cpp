#include"DataManage.h"
#define _CRT_SECURE_NO_WARNINGS
void SqliteManager::Open(const string& path) {

	int ret=sqlite3_open(path.c_str(), &_db);
	if (ret!=SQLITE_OK) {
		assert(false);
	}
}
void SqliteManager::Close() {
	sqlite3_close(_db);
}
void SqliteManager::ExecuteSql(const string& sql) {
	sqlite3_exec(_db, sql.c_str(), nullptr, nullptr, &errmsg);
}
void SqliteManager::GetTable(const string& sql, int& row, int& col, char**& ppRet) {
	int ret = sqlite3_get_table(_db,sql.c_str(),&ppRet,&row,&col,&errmsg);
	if (ret!=SQLITE_OK) {
		assert(false);
	}
}

void DataManager::GetDoc(const string& path, set<string>& doc) {
	char query_sql[256];
	sprintf(query_sql, "select doc_name from %s where doc_path = '%s'","tb_doc",path.c_str());
	int row, col;
	char** ppRet;
	AutoGetTable get(&_dbmgr,query_sql,row,col,ppRet);
	for (int i = 1; i < row;++i) {
		doc.insert(ppRet[i]);
	}
}

void DataManager::InsertDoc(const string& path, const string& doc) {

	char sql[256];
	sprintf(sql,"insert into %s values('%s','%s')","tb_doc",path.c_str(),doc.c_str());
	_dbmgr.ExecuteSql(sql);
}
void DataManager::DeleteDoc(const string& path,const string& doc) {
	char sql[256];
	sprintf(sql,"delete from %s where doc_path = '%s' and doc_name = '%s'","tb_doc",path.c_str(),doc.c_str());
	_dbmgr.ExecuteSql(sql);

	string path_ = path;
	path_ += '\\';
	path_ += doc;
	sprintf(sql,"delete from %s where doc_path like '%s%'","tb_doc",path.c_str());
	_dbmgr.ExecuteSql(sql);
	
}
