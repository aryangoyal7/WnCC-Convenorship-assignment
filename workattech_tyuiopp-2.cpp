#include<bits/stdc++.h>
using namespace std;

int gw(auto it , map <int , int> m, int hour =0, int events = 0 ){ 
  if(it == m.end()){
	  return events;
  }
	else{
		it++;
	    int a1 = gw(it,m,hour,events);
		int a2=  -1;
		if(hour <=  it->first){
			hour = it->first + it->second;
			events++;
        	a2 = gw(it,m,hour,events);
		}
		return max(a1,a2);
	}
}










int main(){
	fstream myfile;
	myfile.open("Schedule.txt" , ios::in);
	map<int,int> m;
	if(myfile.is_open()){
		string s;
		
		int a,b;
		//doubt -- what to put in getline to read it as a string , a int , second int in every line
		while(getline(myfile,s)){
			string ss = "";
			string sss="";
			ss+= s[5];
			ss+= s[6];
			sss+= s[8];
			a = stoi(ss);
			b = stoi(sss);
			
			if(m.find(a) == m.end()){
				m[a] = b;
			}
			else{
				int old = m[a];
				int corr= min(m[a],b);
				m.insert(pair<int,int>(a,corr));
			}
			//if(m[a] != 0){ 
			//  
			//}
			//else{  
			// if(m[a] > b){ 
			//	 (*m.find(a)).second = b;
			//  //insert b as value of key 1
			// }
			//	else{  
			//		continue;
			//		
			//	  //keep value of key a as original only
			//	  
			//	}
			// 
			//}
		}
	}
	 for (auto itr = m.begin(); itr != m.end(); itr++) {
        
        cout << itr->first << '\t' << itr->second << '\n';
    }
	int events =0, hours =0;
	auto itt = m.begin();
	cout<<gw(itt,m,events,hours)<<endl;
	
}