#include "ros/ros.h"
#include "std_msgs/String.h"

char chat[20];  //variable for storing the user input
using namespace std;   //for using cout statement 

ros::Publisher my_pub;
ros::Subscriber my_sub;

void CallBack(const std_msgs::String::ConstPtr& mg)
{
      cout<<mg->data.c_str();     //prints the msg from microphone
      cout<<endl;
}
int main(int argc, char **argv)
{
  ros::init(argc,argv,"speaker");
  ros::NodeHandle nh;      //creation of nodehandle object
  ros::AsyncSpinner spinner(2);  // creation of AsyncSpinner with 2 threads
  spinner.start();

   my_pub = nh.advertise<std_msgs::String>("tomic",10);
   /*
    Tells the rosmaster that this node is going to publish a msg
     of std_msgs/String type and will allow the master tell any nodes listening
     to tomic that this node is going to publish a message 
    */   
   my_sub = nh.subscribe("tospeaker",10,CallBack);
   /*
    will subscribe to the topic /tospeaker with the  master and will call the
    CallBack() whenever a new message is recieved
    */
    while (ros::ok())
    {
      cout<<"Message:";
      cin>>chat;
      cout<<endl;
      std_msgs:: String msg;
      msg.data = chat; 
      my_pub.publish(msg);       //publsing the msg
      cout<<endl; 
      cout<<msg.data<<endl;
    }

return 0;
}
