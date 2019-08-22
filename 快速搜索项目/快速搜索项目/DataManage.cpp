#include"DataManage.h"
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
		//assert(false);
	}
}
void DataManager::Init() {
	char sql[256];
	sprintf(sql, "create table %s (id integer primary key autoincrement,doc_path text,doc_name text)",TB_DOC);
	_dbmgr.ExecuteSql(sql);

}
void DataManager::GetDoc(const string& path, set<string>& doc) {
	char query_sql[256];
	sprintf(query_sql, "select doc_name from %s where doc_path = '%s'",TB_DOC,path.c_str());
	int row, col;
	char** ppRet;
	AutoGetTable get(&_dbmgr,query_sql,row,col,ppRet);
	for (int i = 1; i <= row;++i) {
		doc.insert(ppRet[i]);
	}
}
//void SqliteManager::Get(sqlite3*& db) {
//	db = _db;
//}
//void DataManager::GetInstance(sqlite3*& db) {
//	_dbmgr.Get(db);
//}
void DataManager::InsertDoc(const string& path, const string& doc) {

	char sql[256];
	sprintf(sql,"insert into %s(doc_path,doc_name) values('%s','%s')",TB_DOC,path.c_str(),doc.c_str());
	_dbmgr.ExecuteSql(sql);
}
void DataManager::DeleteDoc(const string& path,const string& doc) {
	char sql[256];
	sprintf(sql,"delete from %s where doc_path = '%s' and doc_name = '%s'",TB_DOC,path.c_str(),doc.c_str());
	_dbmgr.ExecuteSql(sql);

	//char sql_s[256];
	string path_ = path;
	path_ += '\\';
	path_ += doc;
	sprintf(sql,"delete from %s where doc_path like '%s%%'",TB_DOC,path_.c_str());
	_dbmgr.ExecuteSql(sql);
}
void DataManager::SearchDoc(const string& key, vector<pair<string,string>>& docs) {
	//利用模糊匹配搜索数据并打印
	char sql[256];
	//sqlite中文模糊匹配不支持模糊查询，只支持精确查询
	sprintf(sql, "select doc_path,doc_name from %s where doc_name like '%%%s%%'", TB_DOC,key.c_str());
	int row, col;
	char** ppRet;
	AutoGetTable get(&_dbmgr,sql,row,col,ppRet);
	for (int i = 1; i <= row;++i) {
		docs.push_back(make_pair(ppRet[i*col+0],ppRet[i*col+1]));
	}
}
