#include "ros/ros.h"
#include "std_msgs/String.h"
using namespace std;
char chat[20];
void CallBack(const std_msgs::String::ConstPtr&msg)
{
    cout<<msg->data.c_str();
    cout<<"Enter a msg:";
    cin>>chat;
   
    //ROS_INFO("Got this from the speaker: [%s]",msg->data.c_str());

}

int main(int argc , char **argv)
{
    ros::init(argc,argv,"microphone");
    ros::NodeHandle nh;
    ros::Subscriber my_sub = nh.subscribe("tomic",1000,CallBack);
    ros::NodeHandle n;
    ros::Publisher my_pub = n.advertise<std_msgs::String>("tospeaker",10);
    std_msgs::String mg;
    mg.data =chat;
    my_pub.publish(mg);
    ros::spin();
    return 0;

}
