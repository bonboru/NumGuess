//this program is a game of guessing a group of random numbers.
//author: Chandler

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//unknown stores the random numbers
	//suspect stores the input numbers
	//a,b stores the number of A,B
	//flag controls the execution of the game
	int unknown[3]={0}, suspect[3]={0}, suspect_cp[3]={0};
	int win_no=0, lose_no=0, a=0, b=0, i=0, j=0;
	char flag;
	
	srand(time(NULL));
	
	flag = 'Y';
	
	while (flag=='Y'||flag=='y') {
		cout<<"需要玩游戏吗（Y/N）？";
		cin>>flag;
		if (flag=='N'||flag=='n') break;
		
		//generate random numbers and ensure they are not same.
		unknown[0] = rand() * 10 / (RAND_MAX + 1);
		do {
			unknown[1] = rand() * 10 / (RAND_MAX + 1);
		} while (unknown[0] == unknown[1]);
		do {
			unknown[2] = rand() * 10 / (RAND_MAX + 1);
		} while ((unknown[0] == unknown[2]) || (unknown[1] == unknown[2]));

		//body of the seven guessing process
		for (i=0; i<7; ++i) {
			a = 0;
			b = 0;
			
			cout<<"请输入你猜测的数字：";
			cin>>suspect[0]>>suspect[1]>>suspect[2];
			
			//calculate B 
			for (j=0; j<3; ++j) {
				suspect_cp[j]=suspect[j];
			}
			//delete the same number
			if (suspect_cp[1]==suspect_cp[0]) suspect_cp[1]=-1;
			if (suspect_cp[2]==suspect_cp[0]) suspect_cp[2]=-1;
			if (suspect_cp[2]==suspect_cp[1]) suspect_cp[2]=-1;
			for (j=0; j<3; ++j){
				if (suspect_cp[0]==unknown[j]||suspect_cp[1]==unknown[j]||suspect_cp[2]==unknown[j]) {
					b += 1;	
				}
			}
							
			for (j=0; j<3; ++j){
				if (suspect[j]==unknown[j]) a+=1;
			}
						
			cout<<a<<'A'<<b<<'B'<<endl;		 
			if (a==3) break;
		}
	
	
		if (a==3) {
			cout<<"恭喜，你猜对了"<<endl;
			win_no += 1;
		}
		else {
			cout<<"很遗憾，你没有在规定次数内猜对。答案是 "<<unknown[0]<<unknown[1]<<unknown[2]; 
			lose_no += 1;
		}
	}
	
	cout<<"您一共玩了"<<(win_no+lose_no)<<"局，赢了"<<win_no<<"局，输了"<<lose_no<<"局。";
	
	return 0;
}
