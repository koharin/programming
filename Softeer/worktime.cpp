#include<iostream>
#include <string>


using namespace std;

int main(int argc, char** argv)
{
	string delim=":";
	unsigned int result=0;
	for(int i=0; i<5; i++){
		string start, end;

		cin >> start >> end;

		int pos1=start.find_first_of(':');
		int pos2=end.find_first_of(':');
		int start1 = stoi(start.substr(0, pos1));
		int start2 = stoi(start.substr(pos1+1));
		int end1 = stoi(end.substr(0, pos2));
		int end2= stoi(end.substr(pos2+1));
		//printf("start1: %d start2: %d end1: %d end2: %d\n", start1, start2, end1, end2);
		
		if(start2 < end2) result += (end1-start1-1)*60+(60+end2-start2);
		else result += (end1-start1)*60 + (end2-start2);
	}
	printf("%d", result);
	return 0;
}
