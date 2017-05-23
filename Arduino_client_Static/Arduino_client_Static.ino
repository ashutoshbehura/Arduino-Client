#include <SPI.h>
#include <Ethernet.h>


String message="";
byte mac[] = {  0x12, 0x8A, 0xAB, 0xAC, 0x2E, 0xA2 }; //giving the macID to the device

//the IP address is dependent on your network
// for manual configuration:
IPAddress ip(192, 168, 1, 9);//ip address of the arduino
//byte ip[] = { 192, 168, 1, 9 };  //giving IP to the bord//not required when DHCP is avalable

// the subnet:
//IPAddress subnet(255, 255, 255, 0);

// the router's gateway address:
//IPAddress gateway(192, 168, 1, 1);
byte getway[] = {192, 168, 1, 100};////ip address of the port through which ardrino has connected



// fill in your Domain Name Server address here:
IPAddress myDns(8, 8, 8, 8);


byte server[] = { 192, 168, 1, 100};  //specifying address of server
//IPAddress server(192, 168, 1, 1);

#define port 5001       //random port number to publish

EthernetClient client; //making an object named client, of the class EthernetClient

int connStatus(){
    Ethernet.begin(mac, ip, myDns, getway); //If connection is not established then print the message
        
    //If connection is established then
    Serial.println(Ethernet.localIP());
    return 1;
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  while(!connStatus())
  connStatus();
}
  
void loop() {

if( client.connect(server,port))
 {
  Serial.println("Connecting ......");
  //if connection is established then do the following opoeration
  
    message += "IOT Client";
    Serial.println(message);
    client.print(message);
    client.flush();//clearing the buffer
    client.stop();//closing the connection
    delay(1000);//giving some delay before throwing the next value
    message="";
 }
 else
 {
  //If connection is not established then this part will be executed
  Serial.println("the socket connection is failed to connect to the specified port");
 }
}
