//
//  main.cpp
//  BBBW_0
//
//  Created by Hokiesbear on 6/9/21.
//  Copyright © 2021 Jing Luo. All rights reserved.
//
/* Usr0 keeps off
Usr1 Keeps blink - 5s on, 5s off
Usr2 keeps on
usr3 brigtness low -> high
 */
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdio.h>

using namespace std;

#define LED_PATH "/sys/class/leds/"
#define USR0 "beaglebone:green:usr0"
#define USR1 "beaglebone:green:usr1"
#define USR2 "beaglebone:green:usr2"
#define USR3 "beaglebone:green:usr3"

/* usr0 is off*/
void RemoveTrigger(string trigger){
    fstream fs;
    fs.open(LED_PATH USR0 "/trigger", fstream::out);
    fs<<trigger;
    fs.close();
    
}




/*usr1 is blink 5s on 5s off*/

void blink (string i, string j){
    fstream fs;
    fs.open(LED_PATH USR1 "trigger", fstream::out);
    fs<< "timer";
    fs.close();
    fs.open(LED_PATH USR1 "delay_on", fstream::out);
    fs<< i;
    fs.close();
    fs.open(LED_PATH USR1 "delay_off", fstream::out);
    fs<< j;
    fs.close();
}

/*usr2 keeps on*/

void Ledstatus(bool statue ){
    fstream fs;
    fs.open(LED_PATH USR2 "/brightness", fstream::out);
    if (statue != false){
        fs<< "1";
    }
    else {
        fs<< "0";
    }
    
    fs.close();
    
}
int main(int argc, const char * argv[]) {
    
    
    for (int i=0; i<10; i++){
        
        cout << "remove trigger on Usr0\n";
        RemoveTrigger("none");
        sleep(1000);
        RemoveTrigger("1000");
        cout<< "usr1 blink every 5s";
        blink ("5000", "5000");
        Ledstatus(true);
        sleep(5000);
        Ledstatus(false);
    }
    
    RemoveTrigger("heartbeat");
    blink ("100","100");
    Ledstatus(false);
    
    return 0;
}
