#include<iostream>

#include<string>
using namespace std;
int main()
{
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    string s;
    cin>>s;

    int count =0;
    for(int j=0;j<=7;j++){
      if((s[j%8] == '0' && s[(j+1)%8] == '1') || (s[j%8] == '1' && s[(j+1)%8] == '0') )
        count = count+1;
    }

    if(count<=2){
      cout<<"uniform"<<endl;
    }
    else{

        cout<<"non-uniform"<<endl;

    }
  }
}
