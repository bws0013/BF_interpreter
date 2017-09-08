// Ben Smith (bws0013)

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

#include "bf.h"

using namespace std;

// Notes

/*
	I am aware that I could use a switch statement and it would technically be more efficient,
	but I rarely use c++ so any efficiency my program gains is lost by the time I am spending
	making sure it is correct and error free... therefore if statements.
 */




//string op = "";

vector<int> interprete(const string &input, const vector<int> &ca) {
    //interprete::interprete(string input, string ca[]) {
    int pointer = 0;
    int arrPlace = 0;
    int ecx = 0;
    //int opPlace = 0;
    
    vector<int> fin;
    
    //string op = "";
    char op[30000];
    int arr[30000];
    
    for(int i = 0; i < 30000; i++) {
        arr[i] = 0;
        op[i] = '\0';
    }
    
    
    for(int i = 0; i < input.length(); i++) {
        char c = input.at(i);
        
        
        if(c == '>') {
            pointer++;
            if(pointer >= 30000) {
                cout << "Array Index out of bounds, pointer is greater than 30000, program exiting";
                exit(0);
            }
        } else if(c == '<') {
            pointer--;
            if(pointer < 0) {
                cout << "Array Index out of bounds, pointer is less than 0, program exiting";
                exit(0);
            }
        } else if(c == '+') {
            arr[pointer]++;
        } else if(c == '-') {
            arr[pointer]--;
        } else if(c == '.') {
            int temp = arr[pointer];
            fin.push_back(temp);
        } else if(c == ',') {
            int temp = ca[arrPlace];
            arrPlace++;
            arr[pointer] = temp;
        } else if(c == '[') {
            if(arr[pointer] == 0) {
                char c2 = input.at(i);
                while(ecx > 0 || c2 != ']') {
                    if(input.at(i) == '[') {
                        ecx++;
                    } else if (c2 == ']') {
                        ecx--;
                    }
                    i++;
                }
                
            }
        } else if(c == ']') {
            
            if(arr[pointer] != 0) {
                i--;
                char c2 = input.at(i);
                while(ecx > 0 || c2 != '[') {
                    
                    if (c2== '[') {
                        ecx--;
                    } else if(c2 == ']') {
                        ecx++;
                    }
                    i--;
                }
                i--;
            }
        }
        
    }
    
    return fin;
    
}

//string interprete(const string &input) {
vector<int> interprete(const string &input) {
    int pointer = 0;
    int arrPlace = 0;
    int ecx = 0;
    
    int arr[30000];
    //int opPlace = 0;
    
    vector<int> fin;
    //string op = "";
    char op[30000];
    
    for(int i = 0; i < 30000; i++) {
        arr[i] = 0;
        op[i] = '\0';
    }
    
    
    for(int i = 0; i < input.length(); i++) {
        char c = input.at(i);
        
        
        if(c == '>') {
            pointer++;
            if(pointer >= 30000) {
                cout << "Array Index out of bounds, pointer is greater than 30000, program exiting";
                exit(0);
            }
        } else if(c == '<') {
            pointer--;
            if(pointer < 0) {
                cout << "Array Index out of bounds, pointer is less than 0, program exiting";
                exit(0);
            }
        } else if(c == '+') {
            arr[pointer]++;
        } else if(c == '-') {
            arr[pointer]--;
        } else if(c == '.') {
            int temp = arr[pointer];
            fin.push_back(temp);
            //cout << op;
        } else if(c == ',') {
            arrPlace++;
        } else if(c == '[') {
            if(arr[pointer] == 0) {
                i++;
                while(ecx > 0 || input.at(i) != ']') {
                    if(input.at(i) == '[') {
                        ecx++;
                    } else if (input.at(i) == ']') {
                        ecx--;
                    }
                    i++;
                }
                
            }
        } else if(c == ']') {
            //ecx = 0;
            if(arr[pointer] != 0) {
                i--;
                //char c2 = arr[i];
                while(ecx > 0 || input.at(i) != '[') {
                    
                    if (input.at(i) == '[') {
                        ecx--;
                    } else if(input.at(i) == ']') {
                        ecx++;
                    }
                    i--;
                } 
                i--;
            }
        }
        
    }
    // string toRet = new string (op);
    //cout << op << "hi ";
    return fin;
}

/*
int main() {
    return 0;
}*/