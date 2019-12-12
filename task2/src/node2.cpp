#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include <iostream>



ros::Publisher ch2;

void recv(const std_msgs::String::ConstPtr& msg)
{
  cout << msg->data;
  std_msgs::Int32 n;
  cin >> n.data ;
  ROS_INFO("sent: %d", n.data);
  ch2.publish(n);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node2");
  ros::NodeHandle N;
  ros::Subscriber ch1 = N.subscribe("channel1", 1000, recv);
  ch2 = N.advertise<std_msgs::Int32>("channel2", 1000);
  ros::Rate loop_rate(10);
  ros::spin();
  return 0;
}
