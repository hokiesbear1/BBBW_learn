//
//  main.cpp
//  BBBW_0
//
//  Created by Hokiesbear on 6/9/21.
//  Copyright © 2021 Jing Luo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define LED_PATH "/sys/class/leds/"
#define USR0 "beaglebone:green:usr0"
// #define USR1 "beaglebone:green:usr1"
// #define USR2 "beaglebone:green:usr2"
// #define USR3 "beaglebone:green:usr3"

void RemoveTrigger(){
    fstream fs;
    fs.open(LED_PATH USR0 "/trigger", fstream::out);
    fs<<"none";
    fs.close();
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "remove trigger on Usr0\n";
    RemoveTrigger();
    return 0;
}
