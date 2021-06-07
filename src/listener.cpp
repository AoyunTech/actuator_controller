#include <ros/ros.h>
#include <string.h>
//#include <actuator_controller/gps.h>
//#include <std_msgs/Float32.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <trajectory_msgs/JointTrajectoryPoint.h>
#include <sensor_msgs/JointState.h>

#if 0
void gpsCallback(const actuator_controller::gps::ConstPtr &msg)
{
    std_msgs::Float32 distance;
    distance.data = sqrt(pow(msg->x, 2) + pow(msg->y, 2));
    ROS_INFO("Listener: Distance to orgin = %f, state = %s", distance.data, msg->state.c_str());
}
#endif

void jointTraCallback(const trajectory_msgs::JointTrajectory::ConstPtr &msg)
{
    std::vector<std::string> joint_names_;
    trajectory_msgs::JointTrajectoryPoint points_;

    joint_names_ = msg->joint_names;
    points_ = msg->points;

#if 0
    for(size_t i = 0; i < 12; i++)
    {
        ROS_INFO("Listener: joint_name = %s, at postion = %f", &joint_names_[i], points_.positions[i]);
    }
#endif

}

int main(int argc, char** argv) {
    std::string joint_control_topic = "joint_group_position_controller/command";
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
//    ros::Subscriber sub = n.subscribe("gps_info", 1, gpsCallback);
    ros::Subscriber sub = n.subscribe(joint_control_topic, 1, jointTraCallback);
    ros::spin();

    return 0;
}
