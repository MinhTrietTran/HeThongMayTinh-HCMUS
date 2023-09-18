//
//  main.cpp
//  HeThongMayTinhHW1
//
//  Created by TMT on 18/09/2023.
//

#include <iostream>
#include <string.h>
using namespace std;

string Reverse(string& str)
{
    unsigned long n = str.length();
    for (int i = 0; i < n / 2; ++i)
    {
        std::swap(str[i], str[n - i - 1]);
    }
    return str;
}

string NotTheBit(string& str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '1')
        {
            str[i] = '0';
        }
        else
        {
            str[i] = '1';
        }
    }
    return str;
}

string AddBit1(string& str)
{
    int remember = 0;
    if (str[6] == '1')
    {
        str[6] = '0';
        remember = 1;
    }
    else
    {
        str[6] = '1';
    }
    for(int i = 5; i >= 0; i--)
    {
        if (str[i] == '0' && remember == 1)
        {
            str[i] = '1';
            remember = 0;
        }
        if (str[i] == '1' && remember == 1)
        {
            str[i] = '0';
            remember = 1;
        }
        
    }
    return str;
}


// a. Sign-Magnitude form

string ConvertToSignMagnitude(int x)
{
    // final value
    string bin;
    if (x <-127 || x > 127)
    {
        bin = "Overflow ! Can not convert.";
        return bin;
    }
    if(x == 0)
    {
        bin = "00000000 or 10000000";
        return bin;
    }
    else if (x < 0)
    {
        bin += '1';
        x = -x;
    }
    else
    {
        bin += '0';
    }
    // reverse this string will get the result
    //cout << "bin: " << bin << endl;
    string rev;
    while(x > 0)
    {
        rev += to_string(x % 2);
        x /= 2;
    }
    //cout << "Rev: " << rev << endl;
    // Fill bit 0 in the empty space
    while(rev.length() < 7)
    {
        rev += '0';
    }
    bin += Reverse(rev);
    return bin;
}


// b. 1’s complement form

string ConvertToOneComplement(int x)
{
    // final value
    string bin;
    if (x <-127 || x > 127)
    {
        bin = "Overflow ! Can not convert.";
        return bin;
    }
    if(x == 0)
    {
        bin = "00000000 or 11111111";
        return bin;
    }
    // reverse this string will get the result
    //cout << "bin: " << bin << endl;
    string rev;
  
  
    if (x > 0)
    {
        bin += '0';
        while(x > 0)
        {
            rev += to_string(x % 2);
            x /= 2;
        }
        while(rev.length() < 7)
        {
            rev += '0';
        }
        rev = Reverse(rev);
        bin += rev;
    }
    if (x < 0)
    {
        bin += '1';
        x = -x;
        while(x > 0)
        {
            rev += to_string(x % 2);
            x /= 2;
        }
        while(rev.length() < 7)
        {
            rev += '0';
        }
        rev = Reverse(rev);
        rev = NotTheBit(rev);
        bin += rev;
    }
    return bin;
}

string ConvertToTwoComplement(int x)
{
    // final value
    string bin;
    if (x <-128 || x > 127)
    {
        bin = "Overflow ! Can not convert.";
        return bin;
    }
    if (x == -128)
    {
        return "10000000";
    }
    // reverse this string will get the result
    //cout << "bin: " << bin << endl;
    string rev;
  
    if (x >= 0)
    {
        bin += '0';
        while(x > 0)
        {
            rev += to_string(x % 2);
            x /= 2;
        }
        while(rev.length() < 7)
        {
            rev += '0';
        }
        rev = Reverse(rev);
        bin += rev;
    }
    else
    {
        bin += '1';
        x = -x;
        while(x > 0)
        {
            rev += to_string(x % 2);
            x /= 2;
        }
        while(rev.length() < 7)
        {
            rev += '0';
        }
        rev = Reverse(rev);
        rev = NotTheBit(rev);
        rev = AddBit1(rev);
        bin += rev;
    }
    return bin;
}

int main()
{
    
    int wili;
    cout << "Nhap so nguyen co dau trong khoang -128 den 127: ";
    cin >> wili;
    cout << "Ket qua bang cach luong dau: " << ConvertToSignMagnitude(wili) << endl;
    //--------

    int wilo;
    cout << "Nhap so nguyen co dau trong khoang -128 den 127: ";
    cin >> wilo;
    cout << "Ket qua bang cach bu 1: " << ConvertToOneComplement(wilo) << endl;
    //---------
     
    int wilai;
    cout << "Nhap so nguyen co dau trong khoang -128 den 127: ";
    cin >> wilai;
    cout << "Ket qua bang cach bu 2: " << ConvertToTwoComplement(wilai) << endl;

    
    
    
    return 0;
}
