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

#define loop 20
/* usr0 is off*/
void RemoveTrigger(){
    fstream fs;
    fs.open(LED_PATH USR0 "/trigger", fstream::out);
    fs<<"none";
    fs.close();
}

void Trigger(string t){
    fstream fs;
    fs.open(LED_PATH USR0 "/trigger", fstream::out);
    fs<<t;
    fs.close();
}

void Usr0status(bool St){
    fstream fs;
    fs.open(LED_PATH USR0 "/brightness", fstream::out);
    if (St != false){
        fs<< "1";
    }
    else {
        fs<< "0";
    }
    
    fs.close();
}
void Usr1status(bool St){
    fstream fs;
    fs.open(LED_PATH USR1 "/brightness", fstream::out);
    if (St != false){
        fs<< "1";
    }
    else {
        fs<< "0";
    }
    
    fs.close();
}

void Usr2status(bool St){
    fstream fs;
    fs.open(LED_PATH USR2 "/brightness", fstream::out);
    if (St != false){
        fs<< "1";
    }
    else {
        fs<< "0";
    }
    
    fs.close();
}

void Usr3status(bool St){
    fstream fs;
    fs.open(LED_PATH USR3 "/brightness", fstream::out);
    if (St != false){
        fs<< "1";
    }
    else {
        fs<< "0";
    }
    
    fs.close();
}

#if 0
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

#endif
int main(int argc, const char * argv[]) {
    
    cout << "remove trigger on Usr0\n";
    RemoveTrigger();
    
    for (int i=0; i<20; i++){
        cout<< "in the loop\n";
        Usr0status(true);
        sleep(1);
        
        Usr1status(true);
        sleep(1);
        
        Usr2status(true);
        sleep(1);
        
        Usr3status(true);
        sleep(1);
        
        Usr3status(false);
        sleep(1);
        
        Usr2status(false);
        sleep(1);
        
        Usr1status(false);
        sleep(1);
        
        Usr0status(false);
        sleep(1);

    }
    
    cout<<"back to normal case\n";
    Trigger("heartbeat");

   // Ledstatus(false);
    
    return 0;
}
