#include "ros/ros.h"
#include "std_msgs/String.h"
using namespace std;
char chat[20];
ros::Publisher my_pub;
ros::Subscriber my_sub;

void CallBack(const std_msgs::String::ConstPtr&msg)
{
    cout<<msg->data.c_str();
    cout<<"Message:";
    cin>>chat;
    std_msgs::String mg;
    mg.data =chat;
    my_pub.publish(mg);
    //ROS_INFO("%s",mg.data.c_str());

}
int main(int argc , char **argv)
{
    ros::init(argc,argv,"microphone");
    ros::NodeHandle nh;

    ros::AsyncSpinner spinner(2);
    spinner.start();
  
    
    my_sub = nh.subscribe("tomic",10,CallBack);
    my_pub = nh.advertise<std_msgs::String>("tospeaker",10);

    ros::waitForShutdown();

    return 0;

}
