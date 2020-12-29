#include "ros/ros.h"
#include "std_msgs/String.h"
char chat[20];
std_msgs::String mg;

using namespace std;
void CallBack(const std_msgs::String::ConstPtr&msg)
{
cout<<"Reply:";
cout<<msg->data.c_str();
}
int main(int argc, char **argv)
{
  ros::init(argc,argv,"speaker");
  ros::NodeHandle nh;
  ros::Publisher my_pub = nh.advertise<std_msgs::String>("tomic",10);
  ros::Subscriber my_sub = nh.subscribe("tospeaker",1000,CallBack);

  ros::Rate loop_rate(10);

  while(ros::ok())
  {   
    cout<<"MESSAGE:";
    cin>>chat;
      std_msgs:: String msg;
      msg.data = chat;
      ROS_INFO("%s",msg.data.c_str());
      my_pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
      cout<<endl;
  } 
return 0;
}