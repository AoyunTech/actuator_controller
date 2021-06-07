#include <ros/ros.h>
#include <actuator_controller/gps.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    actuator_controller::gps msg;
    msg.x = 1.0;
    msg.y = 1.0;
    msg.state = "working";
    ros::Publisher pub = nh.advertise<actuator_controller::gps>("gps_info", 1);
    ros::Rate loop_rate(1.0);
    while (ros::ok()) {
    	msg.x = 1.03 * msg.x;
	msg.y = 1.01 * msg.y;
	ROS_INFO("Talker: GPS: x = %f, y = %f", msg.x, msg.y);
	pub.publish(msg);
	loop_rate.sleep();
    }

    return 0;
}
