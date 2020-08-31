#include<iostream>
#include<fstream>
using namespace std;
//
int main(){
	string command="ls /root/Documents/move |grep -i pdf >to_move.txt";
	system(command.c_str());
	//
	ifstream mf("to_move.txt");
	do{
		string filename;
		if(!mf.eof()){
			getline(mf,filename);
			command="cd /root/Documents/move ;mv "+filename+" /root/Books/"+filename+"; ";
			system(command.c_str());
			cout<<command;
		}
	}while(!mf.eof());
	command="rm to_move.txt";
	//system(command.c_str());
	return 0;
}