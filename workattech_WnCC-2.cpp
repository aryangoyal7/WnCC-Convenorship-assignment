// Online C++ Compiler
// Use this online editor to compile and run C++ code online
#include <bits/stdc++.h>
#include<fstream>
#include<string>

using namespace std;
int gw(auto it , map <int , int> m, int hour =0, int events = 0 ){ 
  if(it == m.end()){
	  return events;
  }
	else{
		it++;
	    gw(it,m,hour,events);
		
		if(hour <=  it->first){
		hour = hour + it->first + it->second;
		events++;
        gw(it,m,hour,events);
		}
		
	}

}


int main() {
	
	
	map <int, int> m;
	fstream myfile;
	myfile.open("schedule.txt" , ios::in);
	if(myfile.is_open()){
		string s;
		string ss;
		string sss;
		
		int a,b;
		//doubt -- what to put in getline to read it as a string , a int , second int in every line
		while(getline(myfile,s)){
			ss = s[5] + s[6];
			sss = s[7] + s[8];
			a = stoi(ss);
			b = stoi(sss);
			
			
			m.insert(a,b);
			if(m[a] != 0){ 
			  
			}
			else{  
			 if(m[a] > b){ 
				 (*m.find(a)).second = b;
			  //insert b as value of key 1
			 }
				else{  
					continue;
					
				  //keep value of key a as original only
				  
				}
			 
			}
			
			
		}
	}
	
	
	
	
	
	/*int s,d;
	
	for(int i =0 ; i <22 ; i++){
		cin>>s>>d;
		if(m[s] != 0){
			if(m[s] > d){
				m[s] = d;
			}
		}
		else{
			m[s] = d;
		}
		
		}
	*/
	//now we have map with start timing and duration minus the slots wiht same start timing but longer durations
	int hour = 0, events = 0;
	auto it = m.begin();
	
	cout<<gw(it,m,hour,events)<<endl;
	
	
	
	return 0;
}