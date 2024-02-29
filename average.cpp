#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc,char *argv[]){
    if(argc ==1){
        cout <<"Please input numbers to find average.";
    }else{
        cout<< "---------------------------------" << endl;
        float sum = 0;
        for(int i = 1; i < argc ; i++){
            sum += atof(argv[i]); 
        }
        cout <<"Average of " << argc - 1 << " numbers = " << sum/(argc-1) << endl;
        cout <<"---------------------------------";
        }
}
