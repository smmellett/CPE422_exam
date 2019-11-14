#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<unistd.h>
using namespace std;

#define FILE_PATH "/home/debian/CPE422exam/Problem3/"

// g++ process-temp.cpp -o process-temp
// to use in cmd line:: ./process-temp temperatures.txt

int main(int argc, char* argv[]){
  if(argc!=2){
  cout << "Usage is to read a file" << endl;
  return 2;
  }

  string cmd(argv[1]);
  cout << endl;
  cout << endl;
  cout << "Starting the read file program" << endl;
  cout << "The current file path is: " << FILE_PATH << endl;
  cout << endl;
  cout << endl;


  std::fstream fs;
	string line;
  string filename = "/"+ cmd;
  fs.open((FILE_PATH + filename).c_str(),std::fstream::in);	
  int val=0;
  int sum=0;
  int count=0;
  int average=0;
  while(getline(fs,line)) 
  {
    cout << line << endl;
    if ( ! (istringstream(line) >> val) ) val = 0;
    sum = sum + val;
    count++;
  }
	fs.close();
  
  average = sum/count;
  cout << "The average temperature is: " << average << endl;

  return 0;

}
