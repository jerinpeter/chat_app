#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std;
char chat[20];          //variable for storing the user input

ros::Publisher my_pub;        //creation of publisher object
ros::Subscriber my_sub;       //creation of subscriber object

void CallBack(const std_msgs::String::ConstPtr&msg)
{
    cout<<msg->data.c_str();        //Prints the msg from the speaker 
    cout<<endl;
    cout<<"Message:";
    cin>>chat;
    cout<<endl;                           
    std_msgs::String mg;
    mg.data =chat;
    my_pub.publish(mg);             //Publishes the message to speaker

}
int main(int argc , char **argv)
{
    ros::init(argc,argv,"microphone");  //initialization and naming the node micrphone
     
    ros::NodeHandle nh;   // creation of nodehandle object
    ros::AsyncSpinner spinner(2);    // (2) implies uses 2 threads
    spinner.start();                 
  
    my_sub = nh.subscribe("tomic",10,CallBack);
    /*
    will subscribe to the topic /tomic with the  master and will call the
    CallBack() whenever a new message is recieved
    */
    my_pub = nh.advertise<std_msgs::String>("tospeaker",10);
    /*
    Tells the rosmaster that this node is going to publish a msg
     of std_msgs/String type and will allow the master tell any nodes listening
     to tospeaker that this node is going to publish a message 
    */

    ros::waitForShutdown();

    return 0;

}
