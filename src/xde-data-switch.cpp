#include<iostream>
#include<Eigen/Core>
#include<Eigen/Lgsm>

#include<xdecore/gvm.h>

#include <rtt/os/main.h>
#include <rtt/Logger.hpp>
#include <rtt/TaskContext.hpp>

#include <rtt/Property.hpp>
#include <rtt/Port.hpp>


class DataSwitch : public RTT::TaskContext{

	public:
		DataSwitch(std::string name) : TaskContext(name){
		}

		bool configureHook(){

			return true;
		}

		void updateHook(){
			std::string data;
		}

};

#include <rtt/Component.hpp>
ORO_CREATE_COMPONENT( DataSwitch );
