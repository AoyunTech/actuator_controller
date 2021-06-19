#include <ros/ros.h>
#if 0
#include <actuator_controller/gps.h>
#include <std_msgs/Float32.h>
#endif
#include <std_msgs/String.h>
#include <sensor_msgs/JointState.h>

#if 0
void gpsCallback(const actuator_controller::gps::ConstPtr &msg)
{
    std_msgs::Float32 distance;
    distance.data = sqrt(pow(msg->x, 2) + pow(msg->y, 2));
    ROS_INFO("Listener: Distance to orgin = %f, state = %s", distance.data, msg->state.c_str());
}
#endif

void jointstateCallback(const sensor_msgs::JointStateConstPtr& msg)
{
    float pos[3];
    pos[0] = msg->position[0];
    pos[1] = msg->position[1];
    pos[2] = msg->position[2];
    ROS_INFO("I heard: [%f], [%f], [%f]", pos[0], pos[1], pos[2]);

#if 0
    float vel[3];
    vel[0] = msg->velocity[0];
    vel[1] = msg->velocity[1];
    vel[2] = msg->velocity[2];
    ROS_INFO("I heard: [%f], [%f], [%f]", vel[0], vel[1], vel[2]);
#endif
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/joint_states", 1000, jointstateCallback);
    ros::spin();

    return 0;
}
