#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    string sorce;
    cin >> sorce;
    string operand;
    int one, two;
    int point=0;
    char mozi;
    unordered_map<int, int> hairetu;
    while (point<sorce.size()) {
        if (sorce.at(point)=='a') {
            point += 2;
            operand = "";
            while (sorce.at(point)-'0'<=9&& sorce.at(point) - '0' >= 0) {
                operand += sorce.at(point);
                point++;
                if (point == sorce.size()) {
                    break;
                }
            }
            point++;
            one = stoi(operand);
            operand = "";
            while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0) {
                operand += sorce.at(point);
                point++;
                if (point == sorce.size()) {
                    break;
                }
            }
            two = stoi(operand);
            hairetu[one] += hairetu[two];
        }else if (sorce.at(point) == 'm') {
            point += 2;
            operand = "";
            while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0) {
                operand += sorce.at(point);
                point++;
                if (point == sorce.size()) {
                    break;
                }
            }
            point++;
            one = stoi(operand);
            operand = "";
            while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0) {
                operand += sorce.at(point);
                point++;
                if (point == sorce.size()) {
                    break;
                }
            }
            two = stoi(operand);
            hairetu[one] -= hairetu[two];
        }else if (sorce.at(point) == 'i') {
            point += 2;
            operand = "";
            while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0) {
                operand += sorce.at(point);
                point++;
                if (point == sorce.size()) {
                    break;
                }
            }
            point++;
            one = stoi(operand);
            operand = "";
            while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0 || sorce.at(point) == '-') {
                operand += sorce.at(point);
                point++;
                if (point == sorce.size()) {
                    break;
                }
            }
            two = stoi(operand);
            hairetu[one] = two;
        }else if (sorce.at(point) == 'o') {
            point++;
            if (sorce.at(point) == 'j') {
                point ++;
                operand = "";
                while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0) {
                    operand += sorce.at(point);
                    point++;
                    if (point == sorce.size()) {
                        break;
                    }
                }
                mozi = hairetu[stoi(operand)];
                cout << mozi;
            }
            else {
                point+=2;
                operand = "";
                while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0) {
                    operand += sorce.at(point);
                    point++;
                    if (point == sorce.size()) {
                        break;
                    }
                }
                cout << hairetu[stoi(operand)];
            }
        }else if (sorce.at(point) == 'g') {
            point +=2;
            operand = "";
            while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0) {
                operand += sorce.at(point);
                point++;
                if (point == sorce.size()) {
                    break;
                }
            }
            point++;
            one = stoi(operand);
            operand = "";
            if (sorce.at(point) == 'a') {
                mozi = 'a';
            }if (sorce.at(point) == 'i') {
                mozi = 'i';
            }if (sorce.at(point) == 'm') {
                mozi = 'm';
            }if (sorce.at(point) == 'o') {
                mozi = 'o';
            }
            point+=2;
            while (sorce.at(point) - '0' <= 9 && sorce.at(point) - '0' >= 0) {
                operand += sorce.at(point);
                point++;
                if (point == sorce.size()) {
                    break;
                }
            }
            two = stoi(operand);
            if (mozi == 'a' && hairetu[one] == 0) {
                point = two;
            }else if (mozi == 'i' && hairetu[one] != 0) {
                point = two;
            }else if (mozi == 'm' && hairetu[one] > 0) {
                point = two;
            }else if (mozi == 'o' && hairetu[one] < 0) {
                point = two;
            }
        }
    }
}