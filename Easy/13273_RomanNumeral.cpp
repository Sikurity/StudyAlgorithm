/**
 *    @link    https://www.acmicpc.net/problem/13273
 *    @date    2017. 10. 30
 *    @author  Sikurity
 *    @method  Simple FSM
 */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

#define MAX_STRLEN 255

using namespace std;

map<char, int> romanNumerals;

int iResult = 0;
string sResult = "";

void truncateWith(int &num, char romanHigh, char romanMid, char romanLow) {
    
    int div = romanNumerals[romanLow];
    
    int quota = num / div;
    
    if(quota == 9) {
        sResult += romanLow;
        sResult += romanHigh;
    }
    else if(quota == 4) {
        sResult += romanLow;
        sResult += romanMid;
    } else {
        if (quota > 4)
            sResult += romanMid;
        
        int repeatNum = quota % 5;
        
        while(repeatNum--)
            sResult += romanLow;
    }
    
    num = num % div;
}

int main()
{
    int
        a = 1,
        b = 2;
    
    printf("%d/%d\n", a, b);
    
    int n;
    scanf("%d", &n);
    
    romanNumerals['I'] = 1;
    romanNumerals['V'] = 5;
    romanNumerals['X'] = 10;
    romanNumerals['L'] = 50;
    romanNumerals['C'] = 100;
    romanNumerals['D'] = 500;
    romanNumerals['M'] = 1000;
    
    char str[MAX_STRLEN + 1];
    for(int i = 0 ; i < n ; i++) {
        
        scanf("%s", str);
        
        int num = atoi(str);
        if( num ) {
            sResult = "";
            
            truncateWith(num, NULL, NULL, 'M');
            truncateWith(num, 'M', 'D', 'C');
            truncateWith(num, 'C', 'L', 'X');
            truncateWith(num, 'X', 'V', 'I');
            
            printf("%s\n", sResult.c_str());
        } else {
            iResult = 0;
            
            int size = static_cast<int>(strlen(str));
            
            for(int i = 0 ; i < size ; i++) {
                
                if(i + 1 < size && romanNumerals[str[i]] < romanNumerals[str[i + 1]])
                    iResult += romanNumerals[str[i + 1]] - romanNumerals[str[i]], i++;
                else
                    iResult += romanNumerals[str[i]];
            }
            
            printf("%d\n", iResult);
        }
    }
    
    return 0;
}
