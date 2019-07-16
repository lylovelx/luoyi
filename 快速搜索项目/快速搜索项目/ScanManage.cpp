#include"ScanManage.h"
#include"DataManage.h"
void ScanManager::DirectoryList(const string& path,vector<string>& subdirs,vector<string>& subfiles) {

	//结构体
	_finddata_t file;
	//查看左孩子 右兄弟 
	string path_ = path + "\\*.*";
	intptr_t handle = _findfirst(path_.c_str(),&file);
	if (handle==-1) {
		cout << "_findfirst : %s" << path_.c_str() << endl;
	}
	//进行子目录查询
	do {
		if (file.attrib & _A_SUBDIR) {
			//为了防止文件系统循环，应该规避掉 . .. 这两个文件
			if (strcmp(file.name,".")!=0&&strcmp(file.name,"..")!=0) {
				subdirs.push_back(file.name);
			}
		}
		else {
			subfiles.push_back(file.name);
		}
	} while (_findnext(handle, &file) == 0);
	_findclose(handle);
}
//对当前目录进行扫描
void ScanManager::Scan(const string& path) {

	//对文件系统和数据库进行比对
	DataManager _datamgr;
	vector<string> localdirs;
	vector<string> localfiles;
	//获取本路径下的目录和文件
	DirectoryList(path,localdirs,localfiles);
	//将目录和文件添加到set当中,实现排序+去重
	std::set<string> localset;
	localset.insert(localdirs.begin(),localdirs.end());
	localset.insert(localfiles.begin(),localfiles.end());
	
	//数据库操作
	set<string> dbset;
	_datamgr.GetDoc(path,dbset);
	//将此路径下的文件以及目录进行比对
	auto localit = localset.begin();
	auto dbit = dbset.begin();
	  

	while (localit!=localset.end()&&dbit!=dbset.end()) {
		if (*localit>*dbit) {
			//删除数据库的数据
			_datamgr.DeleteDoc(path,*dbit);
			dbit++;
		}
		else if (*localit<*dbit) {
			//往数据库添加数据
			_datamgr.InsertDoc(path, *localit);
			localit++;
		}
		else {
			//数据一致，同时向后比较
			localit++;
			dbit++;
		}
	}
	while (localit!=localset.end()) {
		//向数据库中添加文件
		_datamgr.InsertDoc(path, *localit);
		localit++;
	}
	while (dbit!=dbset.end()) {
		_datamgr.DeleteDoc(path, *dbit);
		dbit++;
	}

	//最后递归比对所有子目录
	for (auto& subdirs:localdirs) {
		string subpath = path;
		subpath += '\\';
		subpath += subdirs;
		Scan(subpath);
	}
}