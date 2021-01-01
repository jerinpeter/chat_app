#include "ros/ros.h"
#include "std_msgs/String.h"

char chat[20];

using namespace std;
ros::Publisher my_pub;
ros::Subscriber my_sub;

void CallBack(const std_msgs::String::ConstPtr& mg)
{
      ROS_INFO("I heard: [%s]", mg->data.c_str());
}
int main(int argc, char **argv)
{
  ros::init(argc,argv,"speaker");
  ros::NodeHandle nh;

  ros::AsyncSpinner spinner(2);
  spinner.start();
  
  
   my_pub = nh.advertise<std_msgs::String>("tomic",10);   
  cout<<"new msg";
   my_sub = nh.subscribe("tospeaker",10,CallBack);
   while (ros::ok())
   {
    cout<<"Message:";
    cin>>chat;
    std_msgs:: String msg;
    msg.data = chat;
      //ROS_INFO("%s",msg.data.c_str());
     // cout<<msg.data.c_str();
    my_pub.publish(msg);
    cout<<endl;
    cout<<"hello";
    cout<<msg.data<<endl;
   
   
   //ros::spinOnce();
   }
return 0;
}
